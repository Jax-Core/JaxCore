--[[
    Author: Blu
    Reddit: /u/IamLUG
    Github: https://github.com/bluwy

    ------------------------------------------------------------

    Main.lua
    ~ Main.lua is the powerhouse of the project, link the script measure to this script
    ~ Tween any number in Rainmeter with Lua
    ~ Supports tweening meter options, measure options, variables and groups!
    ~ Easily tween a value with lesser syntax than manual tweening in Rainmeter
    ~ Credits: https://github.com/kikito/tween.lua for the tweening and easing functions
    ~ License: https://github.com/bluwy/LuaTween-for-Rainmeter/blob/master/LICENSE.txt

    -------------------------------------------------------------

    For syntaxes or tutorials:
    Visit https://github.com/bluwy/LuaTween-for-Rainmeter/
]]--



--region Rainmeter

function Initialize()
    -- Section: USER MODIFY
    -- ~ LuaTween provides default Single, Chain and Multiple scripts for usage, if you're excluding 
    --   some of these scripts or including your custom scripts, modify here to avoid errors
    --
    -- How to modify?
    -- ~ In the *tweenTypeFileNames* table, modify it to have the exact names of the files in 
    --   LuaTween/Types
    -- ~ In *tweenTypes* table, modify it to be in this format:
    --     "Your syntax in RM" = "Table Name of the related script"
    --   
    local tweenTypeFileNames = 
    {
        -- FileName
        "Single",
        "Chain",
        "Multiple"
    }

    ImportScripts(tweenTypeFileNames)

    tweenTypes =
    {
        -- Syntax = TableName
        single = Single,
        chain = Chain,
        multiple = Multiple
    }
    -- EndSection: USER MODIFY
    

    -- The group for updates and redraws (Default: "Tweenable")
    tweenGroup = SELF:GetOption("TweenGroup", "Tweenable")

    -- The delta time of the script's Update
    dt = 0
    -- the previous time to calculate delta time (Current time - previous time)
    prevTime = os.clock()

    
    -- Whether redraw is needed, if any tween is playing.
    redraw = false
    -- How many times to redraw after *redraw* = true
    redrawTimes = 2
    -- redraw cache
    redrawsLeft = 0
    
    -- Initializes all the tweens
    InitAllTweens()
end

function Update()
    -- Calculate delta time and set previous time to now
    dt = (os.clock() - prevTime) * 1000
    prevTime = os.clock()
    
    -- Iterate all tween types script and executes their respective Updates
    for _,v in pairs(tweenTypes) do
        redraw = v.Update(dt) or redraw
    end
 
    if redraw then 
        redrawsLeft = redrawTimes
        redraw = false
    end

    if redrawsLeft > 0 then
        redrawsLeft = redrawsLeft - 1
        
        -- Updates and redraws group
        UpdateAndRedraw()
    end
end

--endregion

--region Public functions

-- Plays the tween forwards
function Start(index, ...)
    local inRange = false
    for _,v in pairs(tweenTypes) do
        inRange = v.Start(index, ...) or inRange
    end
    if not inRange then LogIndexError(index) end
end

-- Plays the tween backwards
function Reverse(index, ...)
    local inRange = false
    for _,v in pairs(tweenTypes) do
        inRange = v.Reverse(index, ...) or inRange
    end
    if not inRange then LogIndexError(index) end
end

-- Pauses the tween from playing
function Pause(index, ...)
    local inRange = false
    for _,v in pairs(tweenTypes) do
        inRange = v.Pause(index, ...) or inRange
    end
    if not inRange then LogIndexError(index) end
end

-- Sets the tween clock = duration, value is the EndValue
function Finish(index, ...)
    local inRange = false
    for _,v in pairs(tweenTypes) do
        inRange = v.Finish(index, ...) or inRange
    end
    if not inRange then LogIndexError(index) end
end

-- Sets the tween clock = 0, , value is the StartValue
function Reset(index, ...)
    local inRange = false
    for _,v in pairs(tweenTypes) do
        inRange = v.Reset(index, ...) or inRange
    end
    if not inRange then LogIndexError(index) end
end

-- Calls Reset and Start
function Restart(index, ...)
    Reset(index, ...)
    Start(index, ...)
end

-- Calls Finish and Reverse
function Rewind(index, ...)
    Finish(index, ...)
    Reverse(index, ...)
end

function SetOptional(index, ...)
    local inRange = false
    for _,v in pairs(tweenTypes) do
        inRange = v.SetOptional(index, ...) or inRange
    end
    if not inRange then LogIndexError(index) end
end

-- Reinitializes the tween and gets the new values
function Reinit(index)
    InitTween(index)
end

--endregion

--region Private functions

function InitAllTweens()
    local i = 0
    while true do
        if not InitTween(i, false) then break end
        i = i + 1
    end
end

-- Initializes the tween (Returns true if succeeds)
-- if publicCall, sends error when index is out of range
function InitTween(index, publicCall)
    -- Gets the string form TweenN
    local optTween = SELF:GetOption("Tween" .. index)
    
    if optTween == "" then
        if publicCall then 
            error("No tween with index \"" .. index .. "\" found")
        end
        return false 
    end

    local type = GetTweenType(optTween)

    if tweenTypes[type] == nil then 
        error("No tween type \"" .. index .. "\" found")
        return false 
    end
    
    -- Creates a new tween of *type* 
    tweenTypes[type].New(index, GetTweenUnformatParams(optTween), SELF:GetOption("Optional" .. index))

    return true
end

-- Gets the first param, which is the tween's type
function GetTweenType(str)
    local result = Shared.SplitUnformat(str, 1)

    if #result < 1 then
        error("Parameters insufficent for \"" .. str .. "\"")
    else
        return result[1]:lower()
    end
end

-- Gets the string behind the first "|", which is after the tween type param
function GetTweenUnformatParams(str)
    return str:sub(str:find("|") + 1)
end

-- Updates and Redraws group in RM
function UpdateAndRedraw()
    SKIN:Bang('!UpdateMeasureGroup', tweenGroup)
    SKIN:Bang('!UpdateMeterGroup', tweenGroup)
    SKIN:Bang('!RedrawGroup', tweenGroup)
end

-- Similar to dofile(), but with custom params
function DoFileParams(fileName, ...)
    local f = assert(loadfile(fileName))
    f(...)
end

function ImportScripts(tweenTypeFileNames)
    -- Path to current script's folder
    local folderPath = SELF:GetOption("ScriptFile"):match("(.*[/\\])")

    -- Load the tween.lua file (The file must be in the same folder as this script)
    -- Preserved var: tween
    dofile(folderPath .. "tween.lua")
    -- Preserved var: Shared
    DoFileParams(folderPath .. "Types/_Shared.lua", SKIN)

    for  _,v in pairs(tweenTypeFileNames) do
        DoFileParams(folderPath .. "Types/" .. v .. ".lua", SKIN, Shared, tween)
    end
end

-- Default logger for public functions if tween is not found
function LogIndexError(index)
    if type(index) == "number" then
        error("No tween with index \"" .. index .. "\" found")
    elseif type(index) == "string" then
        error("No tween with group name \"" .. index .. "\" found")
    end
end

--endregion