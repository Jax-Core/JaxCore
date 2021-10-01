function Initialize()
	-- local function defaultValues()
	-- 	SKIN:Bang('!Setvariable', 'Scroll', '0')
	-- 	SKIN:Bang('!Setvariable', 'ContentContainerAlpha', '255')
	-- 	SKIN:Bang('!UpdateMeter', '*')
	-- end

	-- if SKIN:GetVariable('Skin.Name') ~= nil and tonumber(SKIN:GetVariable('PageAni')) ~= 0 and SKIN:GetVariable('Skin.Set_Page') ~= 'Info' then
	-- 	if SKIN:GetVariable('SKin.Name') == 'ModularClocks' and SKIN:GetVariable('Skin.Set_Page') ~= 'Appearance' then
	-- 		SKIN:Bang('!CommandMEasure', 'AnimatedSettingsHandler', 'Execute 1')
	-- 	elseif SKIN:GetVariable('SKin.Name') ~= 'ModularClocks' then
	-- 		SKIN:Bang('!CommandMEasure', 'AnimatedSettingsHandler', 'Execute 1')
	-- 	else
	-- 		defaultValues()
	-- 	end
	-- else
	-- 	defaultValues()
	-- end
end

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

function startDrop(variant, handler, skin, arg1)
	local skin = skin or SKIN:GetVariable('Skin.Name')
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Dropdown\\Main.ini'
	local MyMeter = SKIN:GetMeter(handler)
	local PosX = SKIN:GetX() + MyMeter:GetX()
	local PosY = SKIN:GetY() + MyMeter:GetY()
	local scalemeasure = SKIN:GetMeasure('Set.S')
	if scalemeasure ~= nil then scale = scalemeasure:GetValue() else scale = tonumber(SKIN:GetVariable('Sec.S')) end
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.name', skin, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	if arg1 then SKIN:Bang('!WriteKeyvalue', 'Variables', 'arg1', arg1, File) end
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

function startBox(variant, arg1, arg2, arg3, arg4)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Box\\Main.ini'
	local scale = SKIN:GetMeasure('Set.S'):GetValue()
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	if arg1 then SKIN:Bang('!WriteKeyvalue', 'Variables', 'arg1', arg1, File) end
	if arg2 then SKIN:Bang('!WriteKeyvalue', 'Variables', 'arg2', arg2, File) end
	if arg3 then SKIN:Bang('!WriteKeyvalue', 'Variables', 'arg3', arg3, File) end
	if arg4 then SKIN:Bang('!WriteKeyvalue', 'Variables', 'arg4', arg4, File) end
	SKIN:Bang('!DeactivateConfig', '#JaxCore\\Accessories\\Box')
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Box')
	-- SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\Box')
end

function startSide(variant, num)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Overlay\\Main.ini'
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
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Overlay')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\Overlay')
end

-- function startJax()
-- 	if tonumber(SKIN:GetVariable('QoL')) == 1 then 
-- 		SKIN:Bang('!Draggable', '0')
-- 		local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Accessories\\Overlay\\Main.ini'
-- 		local scale = SKIN:GetMeasure('Set.S'):GetValue()
-- 		local PosX = SKIN:GetX() + tonumber(SKIN:GetMeter('Logo'):GetX())
-- 		local PosY = SKIN:GetY() + tonumber(SKIN:GetMeter('Logo'):GetY())
-- 		local DimH = 256 * scale
-- 		SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', 'Logo', File)
-- 		SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
-- 		SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.H', DimH, File)
-- 		SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Overlay')
-- 		SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Accessories\\Overlay')
-- 	end
-- end