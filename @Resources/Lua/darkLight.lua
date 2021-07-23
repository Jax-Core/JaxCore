function SwitchColor(mode)
    local mode = mode or 0
    local saveLocation = SKIN:GetVariable('Sec.SaveLocation', 'n/a')
    local currentSkin = SKIN:GetVariable('Skin.Name', 'n/a')
    if string.match(currentSkin, "MIUI%-Shade") then
        if mode == 0 then
            SKIN:Bang('!WriteKeyValue', 'Variables', 'MainColor', '34, 34, 36', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'OppositeColor', '240,240,240', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'OffColor', '51, 51, 53', saveLocation)
        else
            SKIN:Bang('!WriteKeyValue', 'Variables', 'MainColor', '235, 235, 235', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'OppositeColor', '0, 0, 0', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'OffColor', '211, 211, 211', saveLocation)
        SKIN:Bang('!Refresh', currentSkin .. '\\Main')
        end
    elseif string.match(currentSkin, "ModularPlayers") then
        if mode == 0 then
            SKIN:Bang('!WriteKeyValue', 'Variables', 'MainColor', '12,12,12', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'OppositeColor', '255,255,255', saveLocation)
        else
            SKIN:Bang('!WriteKeyValue', 'Variables', 'MainColor', '250,250,250', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'OppositeColor', '0, 0, 0', saveLocation)
        SKIN:Bang('!Refresh', currentSkin .. '\\Main')
        end
    elseif string.match(currentSkin, "n/a") then
        if mode == 0 then
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Pri_Color', '19, 19, 19', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Sec_Color', '23,23,23', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Ter_Color', '30, 30, 30', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Opp_Color', '255,255,255', saveLocation)
        else
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Pri_Color', '232, 232, 232', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Sec_Color', '255,255,255', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Ter_Color', '232, 232, 232', saveLocation)
            SKIN:Bang('!WriteKeyValue', 'Variables', 'Set.Opp_Color', '0,0,0', saveLocation)
        end
    end
end
