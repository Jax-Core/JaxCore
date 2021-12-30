function install(skin)
    print('Installing '..skin)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Skin.Name', skin, SKIN:GetVariable('SKINSPATH')..'#JaxCore\\CoreInstaller\\Installer.ini')
    SKIN:Bang('!ActivateConfig', '#JaxCore\\CoreInstaller', 'Installer.ini')
end