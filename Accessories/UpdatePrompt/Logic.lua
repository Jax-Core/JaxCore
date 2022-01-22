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
        SKIN:Bang('!WriteKeyValue', 'Variables', 'ParsedVer', ParsedVerFull, SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\UpdatePrompt\\Toast\\Main.ini')
        SKIN:Bang('!ActivateConfig', '#JaxCore\\Accessories\\UpdatePrompt\\Toast')
    end
end

function checkNews()
    mNewsID = SKIN:GetMeasure('mNewsID')
    CurrentNewsID = tonumber(SKIN:GetVariable('Core.NewsID', '00000'))
    LatestNewsID = tonumber(mNewsID:GetStringValue())
    if LatestNewsID == CurrentNewsID then
        print('News up to date')
    elseif CurrentNewsID < LatestNewsID then
        print('Fetching new news and showing popup')
        SKIN:Bang('!EnableMeasure', 'ParseNews')
        SKIN:Bang('!UpdateMeasure', 'ParseNews')
        SKIN:Bang('!CommandMeasure', 'ParseNews', '"Update"')
    end
end

function runUpdate()
    ParsedVerFull = SKIN:GetVariable('ParsedVer')
    SKIN:Bang('!WriteKeyValue', 'Variables', 'ParsedVer', '0', SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\UpdatePrompt\\Toast\\Main.ini')
    SKIN:Bang('!SetVariable', 'DownloadLink', 'https://github.com/Jax-Core/JaxCore/releases/download/v'..ParsedVerFull..'/JaxCore_v'..ParsedVerFull..'.rmskin\n')
    SKIN:Bang('!SetVariable', 'DownloadName', 'JaxCore'..ParsedVerFull)
    SKIN:Bang('!SetVariable', 'DownloadConfig', '#JaxCore')
    SKIN:Bang('!CommandMeasure', 'CoreInstallHandler', 'Install')
end