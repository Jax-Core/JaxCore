function check()
    mVer = SKIN:GetMeasure('mVer')
    CoreVer = tonumber(SKIN:GetVariable('Core.Ver', '00000'))
    ParsedVer = tonumber(mVer:GetStringValue())
    ParsedVerFull = mVer:GetStringValue()
    SavePos = SKIN:GetVariable('@')..'Actions\\InstallData.ini'
    SaveLocation = SKIN:GetVariable('@')..'Actions'
    if ParsedVer == CoreVer then
        print('Up2date - '..ParsedVer..'=='..CoreVer)
        SKIN:Bang('!UpdateMeasure', 'JaxCoreYes')
    elseif ParsedVer <= CoreVer then
        print('Beta - '..ParsedVer..'<='..CoreVer)
        SKIN:Bang('!UpdateMeasure', 'JaxCoreYes')
    else
        print('Update required - '..ParsedVer..'>='..CoreVer)
        SKIN:Bang('!WriteKeyValue', 'Data', 'DownloadLink', 'https://github.com/EnhancedJax/-JaxCore/releases/download/v'..ParsedVerFull..'/JaxCore_v'..ParsedVerFull..'.rmskin', SavePos)
        SKIN:Bang('!WriteKeyValue', 'Data', 'SaveLocation', SaveLocation, SavePos)
        SKIN:Bang('!UpdateMeasure', 'JaxCoreNo')
    end
end