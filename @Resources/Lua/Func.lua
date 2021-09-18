function GroupVar(SectionExtract, Option)
	Option = Option or 'SecVar'
	config = SectionExtract:match("(.+:).*")
	Meter = SKIN:GetMeter(config)
	GetVar = Meter:GetOption(Option, 'Error')
	return GetVar
end

function LocalVar(Section, Option)
	Meter = SKIN:GetMeter(Section)
	GetVar = Meter:GetOption(Option, 'Error')
	return GetVar
end

function returnBool(Variable, Match, ReturnStringT, ReturnStringF)
	Var = SKIN:GetVariable(Variable)
	ReturnStringT = ReturnStringT or '1'
	ReturnStringF = ReturnStringF or '0'
	if string.find(Var, Match) then
		return(ReturnStringT)
	  else
		return(ReturnStringF)
	end
end

function startDrop(variant, handler, skin)
	local skin = skin or SKIN:GetVariable('Skin.Name')
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Dropdown\\Main.ini'
	local MyMeter = SKIN:GetMeter(handler)
	local PosX = SKIN:GetX() + MyMeter:GetX()
	local PosY = SKIN:GetY() + MyMeter:GetY()
	local scale = SKIN:GetMeasure('Set.S'):GetValue()
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.name', skin, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Dropdown')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\Dropdown')
end

function startPopup(variant)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Popup\\Main.ini'
	local scale = SKIN:GetMeasure('Set.S'):GetValue()
	local PosX = SKIN:GetX() + SKIN:GetW() / 2 - 400 * scale / 2
	local PosY = SKIN:GetY() + SKIN:GetH() / 2 - 500 * scale / 2
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Popup')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\Popup')
end

function startSide(variant, num)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Hotkey\\Main.ini'
	local scale = SKIN:GetMeasure('Set.S'):GetValue()
	local PosX = SKIN:GetX() + SKIN:GetW() - 400 * scale
	local PosY = SKIN:GetY()
	local DimH = SKIN:GetH()
	local SkinName = SKIN:GetVariable('Skin.Name')
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.H', DimH, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Skin.Name', SkinName, File)
	if num ~= nil then 
		SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Num', num, File) 
	else
		SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Num', '', File) 
	end
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Hotkey')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\Hotkey')
end