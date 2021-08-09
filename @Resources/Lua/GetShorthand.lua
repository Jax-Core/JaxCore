function Initialize()
    SkinName = SKIN:GetVariable('Skin.Name', 'n/a')
    -- SKIN:Bang('!UpdateMeterGroup', 'Shorthand')
    -- SKIN:Bang('!Redraw')
    w = {Combilaunch='Launch', ["MIUI-Shade"]='Shade', Plainext='Text', ModularPlayers='Players', ModularClocks='Clocks', Clipify='Clipify', WatchOS='Watch', Keystrokes='Strokes'}
    SKIN:Bang('!SetVariable', 'Skin.Shorthand', w[SkinName])
end