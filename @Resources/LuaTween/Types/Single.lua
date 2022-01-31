-- Single-type tween

-- Values are passed from Main's DoFileParams()
local SKIN, Shared, tween = ...

-- Standard varaibles that all type tween script's should have
local tweensTable = {}
local redraw = false

--region Private functions

-- Formats the parameters from RM, return false if parameters are insufficient
-- Params: SectionName | OptionName | StartValue ; 0.0 | ... | EndValue ; 1.0 | Duration
local function FormatParams(unformatParams)
    local params = Shared.SplitUnformat(unformatParams)
    local paramsLen = Shared.TableLength(params)

    if paramsLen < 5 then
        error("Parameters insufficient => " .. unformatParams)
        return false 
    else
        for i,v in pairs(params) do params[i] = Shared.ParseFormula(v) end

        local valueTable = Shared.CalcPathValueTable(params, 3, paramsLen - 1, unformatParams)
        
        if valueTable == nil then 
            error("Path value syntax invalid for " .. unformatParams)
            return false
        end

        return params[1], params[2], valueTable, params[paramsLen]
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

local function Update(tween, dt)
    -- If state not equal 0, its either playing forwards or backwards
    if tween.state ~= 0 then
        -- Updates the tween tweenvalue and return whether tweening is done, if so do loop
        if tween.indexer:update(dt * tween.state) then 
            Shared.DoLoop(tween.loop, tween, tween.indexer)
        end
        
        local indexerValue = tween.indexerValue
        
        for _,v in ipairs(tween.tweens) do
            -- Check in range
            if indexerValue >= v.startPercent and indexerValue <= v.endPercent then
                -- Manually set value rather than update for precision
                v.tween:set(indexerValue - v.startPercent)
                Shared.DoTweenBang(tween.sectionType, tween.sectionName, tween.optionName, Shared.TableToValue(v.value))
                break
            end
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

Single = {}

function Single.New(index, unformatParams, unformatOptionals)
    local sectionName, optionName, valueTable, duration = FormatParams(unformatParams)
    local easing, group, loop = FormatOptionals(unformatOptionals)

    -- Early out if params are invalid
    if not sectionName then 
        error("Single-type tween creation failed")
        return
    end

    -- String -> number
    duration = tonumber(duration)

    local subject = 
    {
        sectionType = Shared.GetSectionType(sectionName),
        sectionName = sectionName,
        optionName = optionName,
        group = group,
        loop = Shared.CheckLoop(loop),
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

    tweensTable[index] = subject
end

-- Called by Mains's Update cycle
function Single.Update(dt)
    redraw = false
    
    for _,v in pairs(tweensTable) do
        Update(v, dt)
    end

    return redraw
end


-- Plays the tween forwards
function Single.Start(index)
    return ProcessTween(index, function(t) 
        t.state = 1 
    end)
end

-- Plays the tween backwards
function Single.Reverse(index)
    return ProcessTween(index, function(t) 
        t.state = -1 
    end)
end

-- Pauses the tween from playing
function Single.Pause(index)
    return ProcessTween(index, function(t) 
        t.state = 0 
    end)
end

-- Sets the tween clock = duration, value is the EndValue
function Single.Finish(index)
    return ProcessTween(index, function(t) 
        t.indexer:finish() 
        t.state = 1

        -- loop is set to none for a constant outcome of Update
        local cacheLoop = t.loop
        t.loop = "none"
        Update(t, 810)
        t.loop = cacheLoop
    end)
end

-- Sets the tween clock = 0, , value is the StartValue
function Single.Reset(index)
    return ProcessTween(index, function(t) 
        t.indexer:reset() 
        t.state = -1

        -- loop is set to none for a constant outcome of Update
        local cacheLoop = t.loop
        t.loop = "none"
        Update(t, 810)
        t.loop = cacheLoop
    end)
end

-- Set the optional of a tween
function Single.SetOptional(index, optionalName, ...)
    optionalName = optionalName:lower()
    local func

    if optionalName == "easing" then
        func = function(t)
            t.indexer:setEasing(arg[1]:lower())
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
        error("Option Name \"" .. optionalName .. "\" is an invalid optional")
    end

    return ProcessTween(index, func)
end

--endregion