function Initialize()
    root = SKIN:GetVariable('ROOTCONFIGPATH')
    saveLocation = root..'SecOverrides\\ModularClocks\\Appearance.inc'
    SavedStatus = SKIN:GetVariable('Sec.Active')
    _G["CurrentPage"] = tonumber(SKIN:GetVariable('Sec.Page'))
    -- ---------------------------- Saving mechanism ---------------------------- --
    if _G["CurrentPage"] == 1 then
        if SavedStatus == 'NotSaved' then 
            print('Status not saved, saving...')
            SKIN:Bang('!EnableMeasure', 'PSRMDelayer')
        else 
            print('This is a refresh, pend loading variables')
        end
    else
        print('Currently not on the customization page.')
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
    SKIN:Bang('!Move', '('..SAW..'-510*'..Scale..')', '('..SAH..'/2)', 'ModularClocks\\Main')
    SKIN:Bang('!ZPos', '1', 'ModularClocks\\Main')
    SKIN:Bang('!Draggable', '0', 'ModularClocks\\Main')
end

function Restore()
    SKIN:Bang('!Draggable', '1')
    
    if _G["CurrentPage"] == 1 then
        print("Restoring...")
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
end

function generateBlur()
    local File = io.open(SKIN:GetVariable('SKINSPATH')..'ModularClocks\\@Resources\\Cog\\Fill\\Blur.inc','w')
    if SKIN:GetVariable('Layout') == 'Single' then Main = 1 elseif SKIN:GetVariable('Layout') == 'Double' then Main = 2 end
    if SKIN:GetVariable('Rows') == 'Double' then Rows = 1 elseif SKIN:GetVariable('Rows') == 'Triple' then Rows = 2 else Rows = 0 end
    if Main >= 1 and SKIN:GetVariable('MainFill') == 'Blur' then
        File:write(
            '[img1]\n'
            ,'Meter=Image\n'
            ,'ImageName=#@#Export\\Blur.png\n'
            ,'DynamicVariables=1\n'
            ,'W=(#SCREENAREAWIDTH#)\n'
            ,'H=(#SCREENAREAHEIGHT#)\n'
            ,'X=(-#CURRENTCONFIGX#-[1:X])\n'
            ,'Y=(-#CURRENTCONFIGY#-[1:Y])\n'
            ,'COntainer=1\n'
        )
    end
    if Main == 2 and SKIN:GetVariable('MainFill') == 'Blur' then
        File:write(
            '[img2]\n'
            ,'Meter=Image\n'
            ,'ImageName=#@#Export\\Blur.png\n'
            ,'DynamicVariables=1\n'
            ,'W=(#SCREENAREAWIDTH#)\n'
            ,'H=(#SCREENAREAHEIGHT#)\n'
            ,'X=(-#CURRENTCONFIGX#-[2:X])\n'
            ,'Y=(-#CURRENTCONFIGY#-[2:Y])\n'
            ,'COntainer=2\n'
        )
    end
    if Rows >= 1 and SKIN:GetVariable('2Fill') == 'Blur' then
        File:write(
            '[img3]\n'
            ,'Meter=Image\n'
            ,'ImageName=#@#Export\\Blur.png\n'
            ,'DynamicVariables=1\n'
            ,'W=(#SCREENAREAWIDTH#)\n'
            ,'H=(#SCREENAREAHEIGHT#)\n'
            ,'X=(-#CURRENTCONFIGX#-[d1:X])\n'
            ,'Y=(-#CURRENTCONFIGY#-[d1:Y])\n'
            ,'COntainer=d1\n'
        )
    end
    if Rows == 2 and SKIN:GetVariable('3Fill') == 'Blur' then
        File:write(
            '[img4]\n'
            ,'Meter=Image\n'
            ,'ImageName=#@#Export\\Blur.png\n'
            ,'DynamicVariables=1\n'
            ,'W=(#SCREENAREAWIDTH#)\n'
            ,'H=(#SCREENAREAHEIGHT#)\n'
            ,'X=(-#CURRENTCONFIGX#-[d2:X])\n'
            ,'Y=(-#CURRENTCONFIGY#-[d2:Y])\n'
            ,'COntainer=d2\n'
        )
    end
    File:write(
        '@includeWallpaper=#SKINSPATH##JaxCore\\@Resources\\Includes\\WallpaperCheck.inc\n'
        ,'[MM]\n'
        ,'Image=File #Cache.Wallpaper# | RenderSize (#Img.W#/4),(#Img.H#/4) | Modulate #BlurModulate# | Blur #BlurRadius#,#BlurSigma#\n'
    )
    File:close()
    SKIN:Bang('!Refresh', 'ModularClocks\\Main')
end
