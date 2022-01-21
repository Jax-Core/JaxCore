function Update()
    if SKIN:GetVariable('Skin.Name') == SKIN:GetVariable('BetaSkinList') then
        SKIN:Bang('!ShowMeterGroup', 'DiscordButton')
        SKIN:Bang('!SetOption', 'SubHeader', 'MEterStyle', 'Set.String:S | Subheader:4')
        SKIN:Bang('!UpdateMeter', '*')
        SKIN:Bang('!Redraw')
    else
        SKIN:Bang('!EnableMeasureGroup', 'checkForBeta')
        SKIN:Bang('!UpdateMeasureGroup', 'checkForBeta')
    end
end

function activateParse()
    local LastParsed = SKIN:GetVariable('LastRollBackSkin')
    -- local LastParsedSkin = LastParsed:match('^.*|')
    -- local LastParsedVer = LastParsed:match('^.*|(.*)$')
    local Current = SKIN:GetVariable('Skin.Name')..'|'..SKIN:GetVariable('Version')
    if Current == LastParsed then
        SKIN:Bang('!CommandMEasure', 'Func', "startDrop('RollBack', 'Button03', 'JaxCore')")
    else
        SKIN:Bang('!EnableMeasure', 'VersionList')
        SKIN:Bang('!UpdateMeasure', 'VersionList')
        SKIN:Bang('!CommandMeasure', 'VersionList', '"Update"')
        _G["Parsed"] = true
    end
end

function parse()
    local file = io.open(SKIN:GetVariable('@')..'Includes\\APIDump.txt','r')
    local writeFile = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Accessories\\DropDown\\Variants\\JaxCoreRollback.inc','w')
    local saveLocation = SKIN:GetVariable('ROOTCONFIGPATH')..'@Resources\\Vars.inc'
    local Current = SKIN:GetVariable('Skin.Name')..'|'..SKIN:GetVariable('Version')
    local content = file:read()
    writeFile:write(
        '[Variables]\n'
        ,'Skin.Name='..SKIN:GetVariable('Skin.Name')..'\n'
        ,'Sec.W=(175*#Sec.S#)\n'
    )
    for match in content:gmatch('\"tag_name\":\"v([%d.]+)\"') do
        writeFile:write(
            '[v'..match..']\n',
            'Meter=String\n',
            'MeterStyle=String:S\n',
            'LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v'..match..'/#Skin.Name#_v'..match..'.rmskin"][!SetVariable DownloadName "#Skin.Name#'..match..'"][!CommandMeasure Installer "Install"]\n',
            '[Div:'..match..']\n',
            'Meter=Shape\n',
            'MeterStyle=Div:S\n'
        )
    end
    writeFile:write(
        '[Installer]\n'
        ,'Measure=Plugin\n'
        ,'Plugin=PowershellRM\n'
        ,'DynamicVariables=1\n'
        ,'ScriptFile=#@#Powershell\\Installer.ps1\n'
    )
    writeFile:close()
    print('Written dropdown menu, showing...')
    SKIN:Bang('!WriteKeyValue', 'Variables', 'LastRollBackSkin', Current, saveLocation)
    SKIN:Bang('!SetVariable', 'LastRollBackSkin', Current)
    SKIN:Bang('!CommandMEasure', 'Func', "startDrop('RollBack', 'Button03', 'JaxCore')")
end

function patchNoteCheck(MeasureUser)
    local pnCheckerVar = SKIN:GetVariable('Core.patchNoteCheckvariable')
    if pnCheckerVar ~= nil then
        -- local MeasureUser = SKIN:GetMeasure('MeasureUser'):GetValue()
        if MeasureUser ~= pnCheckerVar then
            SKIN:Bang('[!commandMeasure Func "startPopup(\'PatchNote\', \'Left\')"][!WriteKeyvalue Variables Core.patchNoteCheckvariable "'..MeasureUser..'" "'..SKIN:ReplaceVariables('#SKINSPATH##Skin.Name#\\@Resources\\PatchNoteVar.inc')..'"]')
        end
    else
        SKIN:Bang('[!SetOption Button.Update MeterStyle "Set.Button:S | Button.Update:NoPN"][!HideMeterGroup PatchNote]')
    end
end