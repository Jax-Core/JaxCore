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
    ParsedVerFull = SKIN:GetVariable('ParsedVer')
    SKIN:Bang('!WriteKeyValue', 'Variables', 'ParsedVer', '0', SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Notification\\Toast\\Main.ini')
    SKIN:Bang('!SetVariable', 'DownloadLink', 'https://github.com/EnhancedJax/-JaxCore/releases/download/v'..ParsedVerFull..'/JaxCore_v'..ParsedVerFull..'.rmskin\n')
    SKIN:Bang('!SetVariable', 'DownloadName', 'JaxCore'..ParsedVerFull)
    SKIN:Bang('!CommandMeasure', 'Installer', 'Install')
end