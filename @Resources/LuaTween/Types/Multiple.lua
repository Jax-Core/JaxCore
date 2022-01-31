-- Multiple-type tween

-- Values are passed from Main's DoFileParams()
local SKIN, Shared, tween = ...

-- Standard varaibles that all type tween script's should have
local tweensTable = {}
local redraw = false

--region Private functions

-- Formats the parameters from RM, return false if parameters are insufficient
-- Params: SectionName | optionalName | StartValue ; 0.0 | ... | EndValue ; 1.0 | Duration | SectionCount
local function FormatParams(unformatParams)
    local params = Shared.SplitUnformat(unformatParams)
    local paramsLen = Shared.TableLength(params)

    if paramsLen < 6 then
        error("Parameters insufficient => " .. unformatParams)
        return false 
    else
        for i=2, paramsLen do
            params[i] = Shared.ParseFormula(params[i])
        end

        local valueTable = Shared.CalcPathValueTable(params, 3, paramsLen - 2, unformatParams)
        
        if valueTable == nil then 
            error("Path value syntax invalid for " .. unformatParams)
            return false
        end

        return params[1], params[2], valueTable, params[paramsLen-1], params[paramsLen]
    end
end

-- return easing, group, loop
local function FormatOptionals(unformatOptionals)
    local optionals = Shared.SplitUnformat(unformatOptionals)

    -- Available optionals
    local easing, group, loop

    for _,v in pairs(optionals) do
        local param = Shared.SplitOptionalParam(v)
        local paramName = param[1]:lower()

        -- Process params
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

local function Update(tween, child, dt)
    -- If state not equal 0, its either playing forwards or backwards
    if child.state ~= 0 then
        -- Updates the tween tweenvalue and return whether tweening is done, if so set state to 0 so no more updates
        if child.indexer:update(dt * child.state) then 
            Shared.DoLoop(tween.loop, child, child.indexer)
        end
        
        local indexerValue = child.indexerValue
        
        for _,v in ipairs(child.tweens) do
                -- Check in range
            if indexerValue >= v.startPercent and indexerValue <= v.endPercent then
                -- Manually set value rather than update for precision
                v.tween:set(indexerValue - v.startPercent)
                Shared.DoTweenBang(tween.sectionType, child.sectionName, child.optionalName, Shared.TableToValue(v.value))
                break
            end
        end

        -- Needs redraw
        redraw = true
    end
end

-- Used by public functions to get the tween by index
-- *func* refers to the function to be applied on the tween
local function ProcessTween(index, subIndex, func)
    return Shared.ProcessTween(tweensTable, index, function(t)
        if subIndex == nil then
            for _,v in pairs(t.children) do
                func(t, v)
            end 
        elseif t.children[subIndex] ~= nil then
            func(t, t.children[subIndex])
        else
            error("Tween" .. index .. " doesn't have a subIndex of " .. subIndex)
        end
    end)
end 

--endregion

--region Public functions

Multiple = {}

function Multiple.New(index, unformatParams, unformatOptionals)
    local sectionName, optionalName, valueTable, duration, sectionCount = FormatParams(unformatParams)
    local easing, group, loop = FormatOptionals(unformatOptionals)

    if not sectionName then 
        error("Multiple-type tween creation failed")
        return
    end

    -- String -> number
    duration, sectionCount = tonumber(duration), tonumber(sectionCount)

    -- The parentSubject abstracts common variables of the child tweens to avoid repetitions
    local parentSubject = 
    {
        sectionType = Shared.GetSectionType(Shared.ParseFormula(Shared.DoSub(sectionName, 0))),
        group = group,
        loop = Shared.CheckLoop(loop),
        children = {}
    }

    -- Creating the children
    for i=0, sectionCount-1 do
        local subject = 
        {
            sectionName = Shared.ParseFormula(Shared.DoSub(sectionName, i)),
            optionalName = Shared.ParseFormula(Shared.DoSub(optionalName, i)),
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

        parentSubject.children[i] = subject
    end

    tweensTable[index] = parentSubject
end

-- Called by Mains's Update cycle
function Multiple.Update(dt)
    redraw = false
    
    for _,v in pairs(tweensTable) do
        for _,vi in pairs(v.children) do
            Update(v, vi, dt)
        end
    end

    return redraw
end


-- Plays the tween forwards
function Multiple.Start(index, subIndex)
    return ProcessTween(index, subIndex, function(t, st)
        st.state = 1
    end)
end

-- Plays the tween backwards
function Multiple.Reverse(index, subIndex)
    return ProcessTween(index, subIndex, function(t, st) 
        st.state = -1 
    end)
end

-- Pauses the tween from playing
function Multiple.Pause(index, subIndex)
    return ProcessTween(index, subIndex, function(t, st) 
        st.state = 0 
    end)
end

-- Sets the tween clock = duration, value is the EndValue
function Multiple.Finish(index, subIndex)
    return ProcessTween(index, subIndex, function(t, st) 
        st.indexer:finish() 
        st.state = 1

        local cacheLoop = t.loop
        t.loop = "none"
        Update(t, st, 810)
        t.loop = cacheLoop
    end)
end

-- Sets the tween clock = 0, , value is the StartValue
function Multiple.Reset(index, subIndex)
    return ProcessTween(index, subIndex, function(t, st) 
        st.indexer:reset() 
        st.state = -1

        local cacheLoop = t.loop
        t.loop = "none"
        Update(t, st, 810)
        t.loop = cacheLoop
    end)
end

-- Set the optional of a tween
function Multiple.SetOptional(index, subIndex, optionalName, ...)
    if type(subIndex) == "string" then
        table.insert(arg, 1, optionalName)
        optionalName = subIndex
        subIndex = nil
    end
    
    optionalName = optionalName:lower()
    local func

    if optionalName == "easing" then
        func = function(t, st)
            st.indexer:setEasing(arg[1]:lower())
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
    
    return ProcessTween(index, subIndex, func)
end

--endregion