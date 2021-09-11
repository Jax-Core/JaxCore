function Initialize()
    root = SKIN:GetVariable('ROOTCONFIGPATH')
    saveLocation = root..'SecOverrides\\ModularClocks\\Appearance.inc'
    SavedStatus = SKIN:GetVariable('Sec.Active')
    -- ---------------------------- Saving mechanism ---------------------------- --
    if SavedStatus == 'NotSaved' then 
        print('Status not saved, saving...')
        SKIN:Bang('!CommandMeasure', 'PSRM', 'FetchVars')
    else 
        print('This is a refresh, pend loading variables')
    end
end

function SaveStatus(Active, X, Y, Thru, Drag, Snap, Keep, ZPos)

    _G["Active"] = Active
    _G["X"] = X
    _G["Y"] = Y
    _G["Thru"] = Thru
    _G["Drag"] = Drag
    _G["Snap"] = Snap
    _G["Keep"] = Keep
    _G["ZPos"] = ZPos
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Active', Active, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.X', X, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Y', Y, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Thru', Thru, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Drag', Drag, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Snap', Snap, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Keep', Keep, saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.ZPos', ZPos, saveLocation)
    -- ---------------------- Set the clock to preview mode --------------------- --
    Move()
end

function Move()
    if Active == 0 then
        SKIN:Bang('!ActivateConfig', 'ModularClocks\\Main')
    end
    SAW = SKIN:GetVariable('SCREENAREAWIDTH')
    SAH = SKIN:GetVariable('SCREENAREAHEIGHT')
    Scale = SKIN:GetVariable('Scale')
    SetS = SKIN:GetMeasure('Set.S'):GetValue()
    SKIN:Bang('!Move', '('..SAW..'-500*'..Scale..')', '('..SAH..'/2-500*#Scale#/2)', 'ModularClocks\\Main')
    SKIN:Bang('!ZPos', '1', 'ModularClocks\\Main')
    SKIN:Bang('!Draggable', '0', 'ModularClocks\\Main')
end

function Restore()
    if _G["Active"] == nil then
        _G["Active"] = SKIN:GetVariable('Sec.Active')
        _G["X"] = SKIN:GetVariable('Sec.X')
        _G["Y"] = SKIN:GetVariable('Sec.Y')
        _G["Thru"] = SKIN:GetVariable('Sec.Thru')
        _G["Drag"] = SKIN:GetVariable('Sec.Drag')
        _G["Snap"] = SKIN:GetVariable('Sec.Snap')
        _G["Keep"] = SKIN:GetVariable('Sec.Keep')
        _G["ZPos"] = SKIN:GetVariable('Sec.ZPos')
    end
    
    SKIN:Bang('!Draggable', '1')

    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Active', 'NotSaved', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.X', ' ', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Y', ' ', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Thru', ' ', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Drag', ' ', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Snap', ' ', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Keep', ' ', saveLocation)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.ZPos', ' ', saveLocation)

    SKIN:Bang('!Move', _G["X"], _G["Y"], 'ModularClocks\\Main')
    SKIN:Bang('!ClickThrough', _G["Thru"], 'ModularClocks\\Main')
    SKIN:Bang('!Draggable', _G["Drag"], 'ModularClocks\\Main')
    SKIN:Bang('!SnapEdges', _G["Snap"], 'ModularClocks\\Main')
    SKIN:Bang('!KeepOnScreen', _G["Keep"], 'ModularClocks\\Main')
    SKIN:Bang('!Zpos', _G["ZPos"], 'ModularClocks\\Main')
    if Active == 0 then
        SKIN:Bang('!DeactivateConfig', 'ModularClocks\\Main')
    end
end