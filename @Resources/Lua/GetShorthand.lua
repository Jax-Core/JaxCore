function Initialize()
    SkinName = SKIN:GetVariable('Skin.Name', 'n/a')
    -- SKIN:Bang('!UpdateMeterGroup', 'Shorthand')
    -- SKIN:Bang('!Redraw')
    w = {["MIUI-Shade"]='Shade', Plainext='Text', ModularPlayers='Players', ModularClocks='Clocks', Clipify='Clipify'}
    SKIN:Bang('!SetVariable', 'Skin.Shorthand', w[SkinName])
end