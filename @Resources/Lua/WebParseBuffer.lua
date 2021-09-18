function start()
    local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\WebParse\\Main.ini'
	local MyMeter = SKIN:GetMeter('Shape1')
	local PosX = SKIN:GetX() + MyMeter:GetX()
	local PosY = SKIN:GetY() + MyMeter:GetY()

    local scale = tonumber(SKIN:GetMeasure('Set.S'):GetValue())

    local DimW = MyMeter:GetW() * 3 + 20 * 2 * scale
    local DimH = MyMeter:GetW() * 4 + 20 * 3 * scale

	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.W', DimW, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.H', DimH, File)
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\WebParse')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\WebParse')
end

function stop()
	SKIN:Bang('!DeactivateConfig', '#JaxCore\\Accessories\\WebParse')
end