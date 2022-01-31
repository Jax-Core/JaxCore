--[[
    Shared.lua

    This script extracts common functions used by the tween types (Single, Chain and Multiple)
    to reduce repetitive declaration. It may save a tincy wincy of time when loading skins.
    The script is also akin to a Helper class for other scripts.
]]--

-- Value is passed from Main's DoFileParams()
local SKIN = ...

-- The type of loops supported
local loops = { "none", "restart", "yoyo" }

Shared = {}



--region Split functions

-- Split params by "|"
function Shared.SplitUnformat(str, maxNb)
    return Shared.split(str, "|", maxNb)
end

-- Split optional params
-- From Easing linear
-- To   Easing   linear
function Shared.SplitOptionalParam(str, maxNb)
    return Shared.split(str, " ", maxNb)
end

-- From 0,255,180 ; 0.5
-- To   0,255,180   0.5
function Shared.SplitPathValueParam(str)
    local valueParam = Shared.split(str, ";", 2)

    if #valueParam < 1 then
        error("Parameters insufficient => " .. str)
        return false
    else
        return valueParam[1], valueParam[2]
    end
end

--endregion

--region Substitution and parsing

-- Parse string to RM to be calculated
function Shared.ParseFormula(str)
    return SKIN:ReplaceVariables(str):gsub("%(.+%)", function(f) return SKIN:ParseFormula(f) end)
end

-- Substitute %% to i
function Shared.DoSub(str, i)
    return str:gsub("%%%%", i)
end

-- eg 8,1,0 to { 8, 1, 0 }
-- So that tween.lua can calculate the tween by tables
function Shared.ValueToTable(value)
    local tbl = Shared.split(value, ",")
    for i,v in pairs(tbl) do tbl[i] = tonumber(v) end
    return tbl
end

-- Similar to ValueToTable(value) but doesnt convert the values to numbers
function Shared.GroupToTable(groupParams)
    return Shared.split(groupParams, ",")
end

-- Inverse of ValueToTable(value)
function Shared.TableToValue(tbl)
    return table.concat(tbl, ",")
end

--endregion

--region Rainmeter stuff

-- Whether the section supplied is a meter, measure, variable or group
function Shared.GetSectionType(sectionName)
    if sectionName:lower() == "variable" then
        return "variable"
    elseif SKIN:GetMeter(sectionName) ~= nil then
        return "meter"
    elseif SKIN:GetMeasure(sectionName) ~= nil then
        return "measure"
    else
        return "group"
    end
end

-- Apply the changes in RM (Used by UpdateTween(v))
function Shared.DoTweenBang(type, sectionName, optionName, value)
    if type == "meter" or type == 'measure' then
        SKIN:Bang('!SetOption', sectionName, optionName, value)

    elseif type == "variable" then 
        SKIN:Bang('!SetVariable', optionName, value)
        
    elseif type == "group" then
        SKIN:Bang('!SetOptionGroup', sectionName, optionName, value)

    else 
        Shared.LogInternalError("Tween Bang error: " .. type)
    end
end

-- Check if the loop is valid by comparing the *loops* table
function Shared.CheckLoop(type)
    if Shared.ContainsValue(loops, type) then
        return type
    else 
        return "none"
    end
end

-- Process the input when a public function is called (eg "Start(0)")
-- Requires tweensTable and groupTable, which should be included in all 
-- tween type scripts.
-- *func* refers to the function to be applied on the tween
function Shared.ProcessTween(tweensTable, index, func)
    if type(index) == "number" then
        if tweensTable[index] ~= nil then 
            func(tweensTable[index])
        else
            return false
        end 
    elseif type(index) == "string" then
        index = index:lower()
        local found = 0

        for _,v in pairs(tweensTable) do
            if v.group == index then
                func(v)
                found = found + 1
            end
        end

        if found == 0 then
            return false
        end 
    else
        error("The index given is a " .. type(index) .. ". Numbers and strings are only accepted")
        return false
    end

    return true
end

-- Do loop based on loop type on the tween or state
-- This function in slightly hard-coded because in depends on state
-- *subjectWithState* is passed rather then *state* to be passed as reference rather than values
function Shared.DoLoop(loopType, subjectWithState, subjectsTween)
    if loopType == "none" then
        subjectWithState.state = 0 

    elseif loopType == "restart" then
        if subjectWithState.state > 0 then subjectsTween:reset() else subjectsTween:finish() end

    elseif loopType == "yoyo" then
        subjectWithState.state = -subjectWithState.state
    else 
        Shared.LogInternalError("Loop error: " .. loopType)
    end
end

-- Calculates the path valueTable from paramsTable
-- *paramsTable* refers to the formated params in a table
-- then index the table from *fromIndex* to *toIndex*
-- finally returns the valueTable
-- *unformatParams is passed in for debugging purpose*
function Shared.CalcPathValueTable(paramsTable, fromIndex, toIndex, unformatParams)
    local valueTable = {}
    local isPercentDefined = false
    local gapCount, index = toIndex - fromIndex, 0

    for i=fromIndex, toIndex do
        local value, percent = Shared.SplitPathValueParam(paramsTable[i])

        -- Early out if syntax is invalid
        if not value then 
            error("Syntax invalid for param number" .. i .. " in " .. unformatParams)
            return
        end
       
        -- Make sure all values are defined with the same syntax (With percentual or otherwise)
        if i == fromIndex then
            isPercentDefined = percent ~= nil
        elseif isPercentDefined == (percent == nil) then
            error("You've used percentages in the param => " .. unformatParams .. ". The rest should also explicitly use percentages in their params")
            return
        end
        
        if isPercentDefined then
            -- Use hte defined percentual values
            percent = Shared.Clamp(tonumber(percent), 0, 1)
        else 
            -- Equivalently distribute percentages acroos values
            percent = index / gapCount
        end

        table.insert(valueTable, { value = value, percent = percent })

        index = index + 1
    end

    -- If percent is defined explicitly, make sure the percentual values are in order
    if isPercentDefined then
        table.sort(valueTable, function(a,b) return a.percent < b.percent end)
    end

    return valueTable
end

--endregion

--region Utilities

-- Copied from https://www.lua-users.org/wiki/SplitJoin
-- Added trimming 
function Shared.split(str, delim, maxNb)
    -- Eliminate bad cases...
    if string.find(str, delim) == nil then
        return { str }
    end

    if maxNb == nil or maxNb < 1 then 
        maxNb = 0 -- No limit
    end

    local result = {}
    local pat = "(.-)" .. delim .. "()"
    local nb = 0
    local lastPos = 0

    for part, pos in string.gmatch(str, pat) do
        local s = Shared.trim(part)

        if s ~= nil and s ~= "" then
            nb = nb + 1
            result[nb] = s
        end

        lastPos = pos

        if(nb == maxNb) then 
            break 
        end
    end

    if nb ~= maxNb then
        result[nb + 1] = Shared.trim(str:sub(lastPos))
    end

    return result
end

-- Copied from https://lua-users.org/wiki/CommonFunctions
-- remove trailing and leading whitespace from string
-- https://en.wikipedia.org/wiki/Trim_(programming)
function Shared.trim(s)
    -- from PiL2 20.4
    return s:gsub("^%s*(.-)%s*$", "%1")
end

-- Clamps value between min and max
function Shared.Clamp(value, min, max)
    if     value < min then value = min 
    elseif value > max then value = max 
    end

    return value
end

function Shared.ContainsValue(table, value)
    if value == nil then
        return false
    end

    for i,v in pairs(table) do
        if v == value then
            return true, i
        end
    end

    return false
end

-- Gets the length of table
function Shared.TableLength(table)
    local i = 0
    for _ in pairs(table) do i = i + 1 end
    return i
end

-- A log function incase things happen where it shouldnt happen :P
function Shared.LogInternalError(message)
    print("Oops, internal error.. Please contact me :)", "Message: " .. message)
end

--endregion