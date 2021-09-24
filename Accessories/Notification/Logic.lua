function check()
    mVer = SKIN:GetMeasure('mVer')
    CoreVer = tonumber(SKIN:GetVariable('Core.Ver', '00000'))
    ParsedVer = tonumber(mVer:GetStringValue())
    ParsedVerFull = mVer:GetStringValue()
    if ParsedVer == CoreVer then
        print('Up2date - '..ParsedVer..'=='..CoreVer)
    elseif ParsedVer <= CoreVer then
        print('Beta - '..ParsedVer..'<='..CoreVer)
    else
        print('Update required - '..ParsedVer..'>='..CoreVer)
        SKIN:Bang('!CommandMeasure', 'CheckForDataFolder' ,'Check-Data')
        SKIN:Bang('!WriteKeyValue', 'Variables', 'ParsedVer', ParsedVerFull, SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Notification\\Toast\\Main.ini')
        SKIN:Bang('!ActivateConfig', '#JaxCore\\Accessories\\Notification\\Toast')
    end
end

function runUpdate()
    SavePos = SKIN:GetVariable('SKINSPATH'):gsub('Skins\\', '')..'CoreData\\Updater\\InstallData.ini'
    local File = io.open(SavePos, 'w')
    ParsedVerFull = SKIN:GetVariable('ParsedVer')
    File:write(
        '[Data]\n'
        ,'DownloadLink=https://github.com/EnhancedJax/-JaxCore/releases/download/v'..ParsedVerFull..'/JaxCore_v'..ParsedVerFull..'.rmskin\n'
        ,'SaveLocation='..SKIN:GetVariable('SKINSPATH'):gsub('Skins\\', '')..'CoreData\\Updater'
    )
    File:close()
end