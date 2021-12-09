function Initialize()
    -- --------------------- makes sure this is in the core --------------------- --
    if SKIN:GetVariable('Skin.Name') ~= nil then
        MediaPlayerName = SKIN:GetVariable('NPName')
        SKIN:Bang('!SetOption', MediaPlayerName..'Shape', 'MeterStyle', 'MediaBox:S | MediaBox1:S')
        SKIN:Bang('!UpdateMeter', '*')
        -- SKIN:Bang('!Redraw')
    end
end

function startInfo(playerShape)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\MediaDetails\\Main.ini'
	local MyMeter = SKIN:GetMeter('SpotifyShape')
	local PosX = SKIN:GetX() + MyMeter:GetX()
	local PosY = SKIN:GetY() + MyMeter:GetY()
    local save = SKIN:GetVariable('Sec.SaveLocation')

    local scale = tonumber(SKIN:GetMeasure('Set.S'):GetValue())

    local DimW = MyMeter:GetW() * 2 + 20 * scale
    local DimH = (150 * 4 + 20 * 3) * scale


    local player = playerShape:gsub('Shape', '')
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Player', player, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.W', DimW, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.H', DimH, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.SaveLocation', '"'..save..'"', File)
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\MediaDetails')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\MediaDetails')
end

function changeTo()
    local toPlayer = SKIN:GetVariable('Sec.Player')
    local File = SKIN:GetVariable('Sec.SaveLocation')
    local pluginType = 'NP'
    if toPlayer == 'Spotify' or toPlayer == 'Web' then
        pluginType = 'WNP'
    end
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Player', pluginType, File)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'NPName', toPlayer, File)
    SKIN:Bang('!Refresh', '#JaxCore\\Main')
    SKIN:Bang('!UpdateMeasure', 'Auto_Refresh:M', '#JaxCore\\Main')
    SKIN:Bang('!CommandMeasure', 'mActions', 'Execute 1')
end