-- Chain-type tween

-- Values are passed from Main's DoFileParams()
local SKIN, Shared, tween = ...

-- Standard varaibles that all type tween script's should have
local tweensTable = {}
local redraw = false

--region Private functions

-- Formats the parameters from RM, return false if parameters are insufficient
-- Params: SectionName | optionalName | StartValue ; 0.0 | ... | EndValue ; 1.0 | Duration | Interval | SectionCount
local function FormatParams(unformatParams)
    local params = Shared.SplitUnformat(unformatParams)
    local paramsLen = Shared.TableLength(params)

    if paramsLen < 7 then
        error("Parameters insufficient => " .. unformatParams)
        return false 
    else
        for i=2, paramsLen do
            params[i] = Shared.ParseFormula(params[i])
        end

        local valueTable = Shared.CalcPathValueTable(params, 3, paramsLen - 3, unformatParams)
        
        if valueTable == nil then 
            error("Path value syntax invalid for " .. unformatParams)
            return false
        end

        return params[1], params[2], valueTable, params[paramsLen - 2], params[paramsLen - 1],  params[paramsLen]
    end
end

-- return easing, group, loop
local function FormatOptionals(unformatOptionals)
    local optionals = Shared.SplitUnformat(unformatOptionals)

    local easing, group, loop

    for _,v in pairs(optionals) do
        local param = Shared.SplitOptionalParam(v)
        local paramName = param[1]:lower()

        -- Process param
        if paramName == "easing" then
            easing = param[2]:lower()

        elseif paramName == "group" then
            group = param[2]:lower()

        elseif paramName == "loop" then
            loop = param[2]:lower()
        end
    end
      
    return easing, group, loop
end

-- Whether the chain(parent) needs to trigger the child to play (Used by UpdateTween(v))
local function ChainNeedTrigger(parent, child)
    -- If playing forward, return true if clock passed the startTime but passed is not marked true
    if      parent.state > 0 then return parent.clock >= child.startTime and not child.passed
    -- If playing forward, return true if clock passed the endTime but passed is marked true (Should be not passed)
    elseif  parent.state < 0 then return parent.clock <= child.endTime   and     child.passed
    else return false
    end
end

local function Update(tween, dt)
    -- If state not equal 0, its either playing forwards or backwards
    if tween.state ~= 0 then
        -- Updates the tween value and return whether tweening is done (Cache since tween.state be used below again, will do loop at the end)
        local tweenDone = tween.tween:update(dt * tween.state)

        -- Iterate through all the tweens of the tweenChain
        for _,v in pairs(tween.tweens) do
             -- Check if a trigger is needed to set the tween state (The set will only occur once)
             if ChainNeedTrigger(tween, v) then 
                -- Set the state to the parent state (play forwards or backwards)
                v.state = tween.state
                -- Set passed true if playing forwards, false if playing backwards
                v.passed = (tween.state > 0)
            end

            -- If state not equal 0, its either playing forwards or backwards
            if v.state ~= 0 then
                -- Updates the tween tweenvalue and return whether tweening is done, if so s set state to 0
                if v.indexer:update(dt * v.state) then v.state = 0 end

                local indexerValue = v.indexerValue
        
                for _,vi in ipairs(v.tweens) do
                    -- Check in range
                    if indexerValue >= vi.startPercent and indexerValue <= vi.endPercent then
                        -- Manually set value rather than update for precision
                        vi.tween:set(indexerValue - vi.startPercent)
                        Shared.DoTweenBang(tween.sectionType, v.sectionName, v.optionalName, Shared.TableToValue(vi.value))
                        break
                    end
                end
            end
        end

        if tweenDone then 
            Shared.DoLoop(tween.loop, tween, tween.tween)
        end

        -- Needs redraw
        redraw = true
    end
end

-- Used by public functions to get the tween by index
-- *func* refers to the function to be applied on the tween
local function ProcessTween(index, func)
    return Shared.ProcessTween(tweensTable, index, func)
end

--endregion

--region Public functions

Chain = {}

function Chain.New(index, unformatParams, unformatOptionals)
    local sectionName, optionalName, valueTable, duration, interval, sectionCount = FormatParams(unformatParams)
    local easing, group, loop = FormatOptionals(unformatOptionals)

    if not sectionName then 
        error("Chain-type tween creation failed")
        return
    end

    -- String -> number
    duration, interval, sectionCount = tonumber(duration), tonumber(interval), tonumber(sectionCount)

    -- The total time needed to tween all
    local totalTime = (sectionCount - 1) * interval + duration

    local parentSubject = 
    {
        sectionType = Shared.GetSectionType(Shared.ParseFormula(Shared.DoSub(sectionName, 0))),
        group = group,
        loop = Shared.CheckLoop(loop),
        state = 0,
        clock = 0,
        tweens = {},
    }

    -- Tweens across the chain of tweens by tweening the clock
    -- The update cycle will then determine which subtweens(or child tweens) to play
    parentSubject.tween = tween.new(totalTime, parentSubject, { clock = totalTime }, 'linear')

    -- Creating the children
    for j=0, sectionCount-1 do
        local subject = 
        {
            sectionName = Shared.ParseFormula(Shared.DoSub(sectionName, j)),
            optionalName = Shared.ParseFormula(Shared.DoSub(optionalName, j)),
            startTime = interval * j,
            endTime = interval * j + duration,
            valueTable = valueTable,
            passed = false,
            state = 0,
            tweens = {},
            indexerValue = 0
        }

        -- indexer in charges of tweening from 0 to 1, the indexerValue is then used to calculate the current value of the path
        subject.indexer = tween.new(duration, subject, { indexerValue = 1 }, easing or 'linear')

        -- A path consist of one or more linear tweens, create(a,b) creates the tween 
        local create = function(a,b) 
            if a.percent == b.percent then return end 
    
            local subSubject = 
            {
                startPercent = a.percent,
                endPercent = b.percent,
                value = Shared.ValueToTable(a.value)
            }
            subSubject.tween = tween.new(b.percent - a.percent, subSubject, { value = Shared.ValueToTable(b.value) }, 'linear')
    
            table.insert(subject.tweens, subSubject)
        end
    
        -- Iterate through the sorted values, creates the tween for the path
        for k,v in ipairs(valueTable) do
            -- For situations when the first percentual value is more than 0
            if k == 1 and v.percent > 0 then
                create({ value = v.value, percent = 0 }, v)
            end

            -- Normal situations when the next percentual value is available
            if valueTable[k+1] ~= nil then
                create(v, valueTable[k+1])
            -- For situations when the last percentual value is less than 1
            elseif v.percent < 1 then
                create(v, { value = v.value, percent = 1 })
            end
        end

        parentSubject.tweens[j] = subject
    end

    tweensTable[index] = parentSubject
end

-- Called by Mains's Update cycle
function Chain.Update(dt)
    redraw = false

    for _,v in pairs(tweensTable) do
        Update(v, dt)
    end

    return redraw
end


-- Plays the tween forwards
function Chain.Start(index)
    return ProcessTween(index, function(t)
        t.state = 1
    end)
end

-- Plays the tween backwards
function Chain.Reverse(index)
    return ProcessTween(index, function(t)
        t.state = -1
    end)
end

-- Pauses the tween from playing
function Chain.Pause(index)
    return ProcessTween(index, function(t)
        t.state = 0
    end)
end

-- Sets the tween clock = duration, value is the EndValue
function Chain.Finish(index)
    return ProcessTween(index, function(t)
        t.tween:finish()
        t.state = 1

        -- loop is set to none for a constant outcome of Update
        local cacheLoop = t.loop
        t.loop = "none"
        for _,v in pairs(t.tweens) do v.indexer:finish() end
        Update(t, 810)
        t.loop = cacheLoop
    end)
end

-- Sets the tween clock = 0, , value is the StartValue
function Chain.Reset(index)
    return ProcessTween(index, function(t)
        t.tween:reset()
        t.state = -1

        -- loop is set to none for a constant outcome of Update
        local cacheLoop = t.loop
        t.loop = "none"
        for _,v in pairs(t.tweens) do v.indexer:reset() end
        Update(t, 810)
        t.loop = cacheLoop
    end)
end

-- Set the optional of a tween
function Chain.SetOptional(index, optionalName, ...)
    optionalName = optionalName:lower()
    local func

    if optionalName == "easing" then
        func = function(t)
            for _,v in pairs(t.tweens) do 
                v.indexer:setEasing(arg[1]:lower()) 
            end
        end
    elseif optionalName == "group" then
        func = function(t)
            t.group = arg[1]:lower()
        end
    elseif optionalName == "loop" then
        func = function(t)
            t.loop = arg[1]:lower()
        end
    else 
        error("Option Name \"" .. optionalName .. "\" is an invalid option or couldn't be set")
    end
    
    return ProcessTween(index, func)
end

--endregion