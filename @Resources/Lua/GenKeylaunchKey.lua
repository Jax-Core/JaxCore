function Initialize()
    t = tonumber(SKIN:GetVariable('Total'))
    saveLocation = SKIN:GetVariable('Sec.SaveLocation')
    root = SKIN:GetVariable('ROOTCONFIGPATH')
    if t == nil then print("ERROR, CONTACT DEVELOPER FOR MORE INFORMATION")
    elseif t >= 1 then
        for i=1,t do
            _G["Name"..i] = SKIN:GetVariable(i..'Name')
            _G["Action"..i] = SKIN:GetVariable(i..'Action')
            _G["Icon"..i] = SKIN:GetVariable(i..'Icon')
            _G["Key"..i] = SKIN:GetVariable('Key'..i)
            _G["KeyS"..i] = SKIN:GetVariable('Key'..i..'InString')
        end
    elseif t == 0 then
        print('Blank canvas. Writing data right now.')
        Add()
    end

    if tonumber(SKIN:GetVariable('Sec.ForceWriteVariables')) == 1 then
        print('Force-Writing')
        local t1 = t
        local t2 = t + 2
        local t3 = t + 3
    
        Write(t1, t2, t3)
        SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.ForceWriteVariables', '0', root..'SecOverrides\\Keylaunch\\General.inc')
        SKIN:Bang('!UpdateMeasure', 'Auto_Refresh:M')
        SKIN:Bang('!Refresh')
    end

    local tryGetIndex = SKIN:GetVariable('Sec.Num')
    if tryGetIndex then cacheIndex = tryGetIndex end
end

function Edit(round, parm1, parm2, parm3, parm4)
    if round == 0 then
        cacheIndex = parm2:gsub('^EditButton', '')
        if parm1 == 0 then
            -- SKIN:Bang('!CommandMeasure', 'Choose:M', 'ChooseFile 1')
        SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Num', cacheIndex, root..'\\Accessories\\Action\\Main.ini')
        SKIN:Bang('!ActivateConfig', '#JaxCore\\Accessories\\Action')
        SKIN:Bang('!Update', '#JaxCore\\Accessories\\Action')
        SKIN:Bang('!Move', '(#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2)', '(#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2)', '#JaxCore\\Accessories\\Action')
        -- elseif parm1 == 1 then
        --     SKIN:Bang('!CommandMeasure', 'Choose:M', 'ChooseFolder 1')
        else
            print('error')
        end
    else
        -- local parm3 = parm3:gsub('%.', '_')
        SKIN:Bang('!WriteKeyValue', 'Variables', cacheIndex..'Name', parm1, saveLocation)
        SKIN:Bang('!WriteKeyValue', 'Variables', cacheIndex..'Action', '["'..parm2..'"]', saveLocation)
        SKIN:Bang('!WriteKeyValue', 'Variables', cacheIndex..'Icon', parm3..'_'..parm4, saveLocation)
        SKIN:Bang('!Refresh', '#JaxCore\\Accessories\\Action')
        -- SKIN:Bang('!UpdateMeasure', 'Auto_Refresh:M')
        -- SKIN:Bang('!Refresh')
    end
end

function Add()
    local t1 = t + 1
    local t2 = t + 2
    local t3 = t + 3

    Write(t1, t2, t3)
    SKIN:Bang('!Refresh')
end

function Remove(initSelection, startingIndex)
    if toggleDelete == nil then toggleDelete = 0 end
    if initSelection == 1 and toggleDelete == 0 then
        toggleDelete = 1
        SKIN:Bang('!SetOptionGroup', 'ActionButton', 'Text', '[\\xF78A]')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'MeterStyle', 'Set.Button:S | Sec.Delete:S')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'Fill', 'Fill Color 255,0,0,100')
        SKIN:Bang('!UpdateMeterGroup', 'Actions')
        SKIN:Bang('!Redraw')
    elseif initSelection == 1 and toggleDelete == 1 then
        toggleDelete = 0
        SKIN:Bang('!SetOptionGroup', 'ActionButton', 'Text', '[\\xE70F]')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'MeterStyle', 'Set.Button:S | Sec.Edit:S')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'Fill', 'Fill Color 0,255,50,100')
        SKIN:Bang('!UpdateMeterGroup', 'Actions')
        SKIN:Bang('!Redraw')
    elseif initSelection == 0 then
        startingIndex = startingIndex:gsub('^EditButton', '')
        for i=startingIndex,(t-1) do
            local nextIndex = i + 1
            local HotkeyFile = SKIN:GetVariable('SKINSPATH')..'Keylaunch\\@Resources\\Actions\\Hotkeys.ini'
            SKIN:Bang('!WriteKeyValue', 'Variables', i..'Name', _G["Name"..nextIndex], saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', i..'Action', _G["Action"..nextIndex], saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', i..'Icon', _G["Icon"..nextIndex], saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Key'..i, _G["Key"..nextIndex], HotkeyFile)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Key'..i..'InString', _G["KeyS"..nextIndex], HotkeyFile)
        end
        SKIN:Bang('!WriteKeyValue', 'Variables', 'Total', (t-1), saveLocation)
        SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.ForceWriteVariables', '1', root..'SecOverrides\\Keylaunch\\General.inc')
        SKIN:Bang('!Refresh')
        -- local t1 = t - 1
        -- local t2 = t + 2
        -- local t3 = t + 3
    
        -- Write(t1, t2, t3)
        -- SKIN:Bang('!Refresh')
    end
end

function Write(t1, t2, t3)
    -- -------------------------------------------------------------------------- --
    --                               Write settings                               --
    -- -------------------------------------------------------------------------- --
    local File = io.open(SKIN:GetVariable('SKINSPATH')..'..\\CoreData\\Keylaunch\\Include.inc','w')
    for i=1,t1 do
        File:write(
            '[Option'..i..']\n'
            ,'Meter=String\n'
            ,'Text=#'..i..'Name#\n'
            ,'MeterStyle=Set.String:S | Set.OptionName:S\n'
            ,'[Set.Div:'..i..']\n'
            ,'Meter=Shape\n'
            ,'MeterStyle=Set.Div:S\n'
        )
    end
    File:write(
        '[Option'..t2..']\n'
        ,'Meter=String\n'
        ,'Text=\n'
        ,'MeterStyle=Set.String:S | Set.OptionName:S\n'
    )
    for i=1,t1 do
        File:write(
        '[EditButton'..i..']\n'
        ,'Meter=Shape\n'
        ,'MeterStyle=Set.Button:S | Sec.Edit:S\n'
        ,'Y=([Option'..i..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        ,'Group=ActionButtonShape | Actions\n'
        
        ,'[EditIcon'..i..']\n'
        ,'Meter=String\n'
        ,'FontFace=Segoe MDL2 Assets\n'
        ,'X=(-15*[Set.S])R\n'
        ,'Y=(-15*[Set.S])R\n'
        ,'StringAlign=CenterCenter\n'
        ,'Text=[\\xE70F]\n'
        ,'Group=ActionButton | Actions\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'

        ,'[ButtonString'..i..']\n'
        ,'Meter=Shape\n'
        ,'MeterStyle=Set.Button:S\n'
        ,'X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])\n'
        ,'Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0\n'
        ,'Y=([Option'..i..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        ,'Act=[!ActivateConfig "#JaxCore\\Accessories\\Hotkey"][!SetVariable Sec.Num '..i..' "#JaxCore\\Accessories\\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\\Accessories\\Hotkey"]\n'

        ,'[Value'..i..']\n'
        ,'Meter=String\n'
        ,'Text=#Key'..i..'InString#\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'
    )
    end
    File:write(
        '[Button'..t2..']\n'
        ,'Meter=Shape\n'
        ,'MeterStyle=Set.Button:S\n'
        ,'OverColor=0,255,50,150\n'
        ,'LeaveColor=0,255,50,100\n'
        ,'Y=([Option'..t2..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        ,'Act=[!CommandMeasure Script:M "Add()"]\n'
        ,'[Value'..t2..']\n'
        ,'Meter=String\n'
        ,'Text=Add an action\n'
        ,'StringAlign=CenterCenter\n'
        ,'X=(150*[Set.S]/2)r\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'
        ,'[Button'..t3..']\n'
        ,'Meter=Shape\n'
        ,'X=(-235*[Set.S])r\n'
        ,'MeterStyle=Set.Button:S\n'
        ,'OverColor=255,0,50,150\n'
        ,'LeaveColor=255,0,50,100\n'
        ,'Y=([Option'..t2..':Y]-#Set.P#+(-30/2+8)*[Set.S])\n'
        ,'Act=[!CommandMeasure Script:M "Remove(1)"]\n'
        ,'[Value'..t3..']\n'
        ,'Meter=String\n'
        ,'Text=Remove...\n'
        ,'StringAlign=CenterCenter\n'
        ,'X=(150*[Set.S]/2)r\n'
        ,'MeterStyle=Set.String:S | Set.Value:S\n'
    )
    File:close()
    -- -------------------------------------------------------------------------- --
    --                              write variables                               --
    -- -------------------------------------------------------------------------- --
    local File = io.open(SKIN:GetVariable('SKINSPATH')..'Keylaunch\\@Resources\\Act.inc','w')
    File:write(
        '[Variables]\n'
        ,'Total='..t1..'\n'
    )
    if t1 > t then l = t else l = t1 end
    for i=1,l do
        File:write(
        ''..i..'Name='.._G["Name"..i]..'\n'
        ,''..i..'Action='.._G["Action"..i]..'\n'
        ,''..i..'Icon='.._G["Icon"..i]..'\n'
    )
    end
    if l == t then
        File:write(
        ''..t1..'Name=Blank\n'
        ,''..t1..'Action=["!Log Action_is_Blank"]\n'
        ,''..t1..'Icon=folder_png\n'
        )
    end
    File:close()
    -- -------------------------------------------------------------------------- --
    --                             write ahk variables                            --
    -- -------------------------------------------------------------------------- --
    local File = io.open(SKIN:GetVariable('SKINSPATH')..'Keylaunch\\@Resources\\Actions\\Hotkeys.ini','w')
    local rmpath = SKIN:GetVariable('RMPATH')
    File:write(
    '[Variables]\n'
    ,'RMPATH='..rmpath..'\n'
    )
    for i=1,t do
        File:write(
            'Key'..i..'='.._G["Key"..i]..'\n'
            ,'Key'..i..'InString='.._G["KeyS"..i]..'\n'
        )
    end
    File:write(
        'Key'..t1..'=\n'
        ,'Key'..t1..'InString=Edit...\n'
    )
    File:close()
    -- -------------------------------------------------------------------------- --
    --                                  write ahk                                 --
    -- -------------------------------------------------------------------------- --
    local File = io.open(SKIN:GetVariable('SKINSPATH')..'..\\CoreData\\Keylaunch\\Keylaunch.ahk','w')
    File:write(
    '#SingleInstance Force\n'
    ,'#NoTrayIcon\n'
    )
    for i=1,t1 do
        File:write(
            'IniRead, Key'..i..', '..SKIN:GetVariable("SKINSPATH")..'Keylaunch\\@Resources\\Actions\\Hotkeys.ini, Variables, Key'..i..'\n'
        )
    end
    for i=1,t1 do
        File:write(
            'Try Hotkey, %Key'..i..'%, Action'..i..'\n'
        )
    end
    File:write(
            'Return\n'
    )
    for i=1,t1 do
        File:write(
            'Action'..i..':\n'
            ,'\tSendToReceiver('..i..')\n'
            ,'\tReturn\n'
        )
    end
    File:write(
        'SendToReceiver(index)\n'
        ,'{\n'
        ,'\tIniRead, RainmeterPath, '..SKIN:GetVariable("SKINSPATH")..'Keylaunch\\@Resources\\Actions\\Hotkeys.ini, Variables, RMPATH\n'
        ,'\tRun "%RainmeterPath% "!CommandMEasure "Receiver:M" "Launch(%index%)" "Keylaunch\\Main" " "\n'
        ,'}\n'
    )
    File:close()
end