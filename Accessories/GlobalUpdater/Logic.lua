function Update()
    local ReadDump = tonumber(SKIN:GetVariable('ReadDump'))
    if ReadDump == 1 then
        SKIN:Bang('[!Delay 50][!WriteKeyvalue Variables ReadDump 0][!Refresh]')
    else
        SKIN:Bang('[!WriteKeyvalue Variables ReadDump 1]')
        check()
    end
end

function ReadIni()
    local tbl, section = {}
    local sectionReadOrder, keyReadOrder = {}, {}
    local num = 0
    for line in file:lines() do
        num = num + 1
        if not line:match('^%s-;') then
            local key, command = line:match('^([^=]+)=(.+)')
            if line:match('^%s-%[.+') then
                section = line:match('^%s-%[([^%]]+)'):lower()
                if not tbl[section] then
                    tbl[section]={}
                    table.insert(sectionReadOrder, section)
                    if not keyReadOrder[section] then keyReadOrder[section]={} end
                end
            elseif key and command and section then
                tbl[section][key:match('^%s*(%S*)%s*$')] = command:match('^%s*(.-)%s*$')
                table.insert(keyReadOrder[section], key)
            elseif #line > 0 and section and not key or command then
                print(num .. ': Invalid property or value.')
            end
        end
    end
    file:close()

    local finalTable={}
    finalTable.INI=tbl
    finalTable.SectionOrder=sectionReadOrder
    finalTable.KeyOrder=keyReadOrder
    return finalTable
end

function check()
    local function Separate(str)
        local o = {}
        for m in str:gmatch('[^%s%|%s]+') do
            table.insert(o, m)
        end
        return o
    end

    _, numOfSkins = SKIN:GetVariable('SKINLIST'):gsub("|", "|")

    local SkinTable = {}
    -- ------------------------ write variables to memory ----------------------- --
    local RowString = SKIN:GetVariable('SKINLIST')
    local SRT = Separate(RowString)

    local numOfUpdates = 0
    contentFile = io.open(SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\GlobalUpdater\\Toast\\Content.inc', 'w')
    for i=1,numOfSkins + 1 do
        -- ---------------------- get skin name from array srt ---------------------- --
        _G["Skin"..i] = SRT[i]
        -- ------------- store version and installed status to skintable ------------ --
        SkinTable[_G["Skin"..i]] = {}
        SkinTable[_G["Skin"..i]]['Version'] = SKIN:GetVariable(_G["Skin"..i])
        ------- check if the skin's version file exists, if it does read it ------ --
        file = io.open(SKIN:GetVariable('SKINSPATH').._G["Skin"..i]..'\\@Resources\\Version.inc','r')
        if file ~= nil then
            -- --------------- store version matching status to skintable --------------- --
            SkinTable[_G["Skin"..i]]['Exist'] = 1
            ini = ReadIni()
            if SkinTable[_G["Skin"..i]]['Version'] > ini.INI['variables']['Version'] then
                contentFile:write(
[[
[]].._G["Skin"..i]..[[]
Meter=String
Y=]]..(90+40*numOfUpdates)..[[

MeterStyle=Set.String:S | Skin.Name:S

[]].._G["Skin"..i]..[[.VerDiff]
Meter=String
Text=]]..ini.INI['variables']['Version']..[[ > ]]..SkinTable[_G["Skin"..i]]['Version']..[[

MeterStyle=Set.String:S | Skin.VerDiff:S

[]].._G["Skin"..i]..[[.UpdateButton]
Meter=Shape
LeftMouseUpAction=[!CommandMeasure LogicalScript "runUpdate(']].._G["Skin"..i]..[[', ']]..SkinTable[_G["Skin"..i]]['Version']..[[')" "#JaxCore\Accessories\GlobalUpdater"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Skin.UpdateButton.Shape:S

[]].._G["Skin"..i]..[[.UpdateIcon]
Meter=String
MeterStyle=Set.String:S | Skin.UpdateButton.Icon:S
]]
                )
                numOfUpdates = numOfUpdates + 1
            end
            SkinTable[_G["Skin"..i]]['LocalVersion'] = ini.INI['variables']['Version']
        else
            -- ---------------------- returns false and exits file ---------------------- --
            SkinTable[_G["Skin"..i]]['Exist'] = 0
            SkinTable[_G["Skin"..i]]['Version'] = 0.0
            SkinTable[_G["Skin"..i]]['LocalVersion'] = 0.0
        end
        -- ------------------------------ print result ------------------------------ --
        -- print(_G["Skin"..i]..' | v'..SkinTable[_G["Skin"..i]]['Version']..' | Installed['..SkinTable[_G["Skin"..i]]['Exist']..'] | LocalVersion v'..SkinTable[_G["Skin"..i]]['LocalVersion'])
    end
    if numOfUpdates ~= 0 then
        contentFile:write(
            [[

[Variables]
Sec.H=(100+40*]]..numOfUpdates..[[)
            ]]
        )
        contentFile:close()
        SKIN:Bang('[!ActivateConfig "#JaxCOre\\Accessories\\GlobalUpdater\\Toast"]')
    else
        contentFile:close()
    end
end


function runUpdate(name, ver)
    ParsedVerFull = SKIN:GetVariable('ParsedVer')
    SKIN:Bang('!SetVariable', 'DownloadLink', 'https://github.com/Jax-Core/'..name..'/releases/download/v'..ver..'/'..name..'_v'..ver..'.rmskin\n')
    SKIN:Bang('!SetVariable', 'DownloadName', name..ver)
    SKIN:Bang('!SetVariable', 'DownloadConfig', name)
    SKIN:Bang('[!SetOption ActiveChecker ConfigName "'..name..'\\Main"][!UpdateMeasure ActiveChecker]')
    SKIN:Bang('!CommandMeasure', 'CoreInstallHandler', 'Install -saveDirectory "Accessories\\GlobalUpdater\\Main.ini"')
end