function install(skin)
    print('Installing '..skin)
    SKIN:Bang('!ActivateConfig', '#JaxCore\\CoreInstaller', 'Installer.ini')
end