function check()
    mVer = SKIN:GetMeasure('mVer')
    CoreVer = tonumber(SKIN:GetVariable('Core.Ver', '00000'))
    ParsedVer = tonumber(mVer:GetStringValue())
    ParsedVerFull = mVer:GetStringValue()
    SavePos = SKIN:GetVariable('@')..'Actions\\InstallData.ini'
    if ParsedVer == CoreVer then
        print('Up2date - '..ParsedVer..'=='..CoreVer)
    elseif ParsedVer <= CoreVer then
        print('Beta - '..ParsedVer..'<='..CoreVer)
    else
        print('Update required - '..ParsedVer..'>='..CoreVer)
        SKIN:Bang('!WriteKeyValue', 'Data', 'DownloadLink', 'https://github.com/EnhancedJax/-JaxCore/releases/download/v'..ParsedVerFull..'/JaxCore_v'..ParsedVerFull..'.rmskin', SavePos)
        SKIN:Bang('!ShowMeterGroup', 'Notif')
        SKIN:Bang('!UpdateMeterGroup', 'Notif')
        SKIN:Bang('!Redraw')
    end
end