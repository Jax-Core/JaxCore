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

function returnBool(Variable, Match)
	Var = SKIN:GetVariable(Variable)
	if string.find(Var, Match) then
		return(1)
	  else
		return(0)
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