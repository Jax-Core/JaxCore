
function Initialize()
	local File = io.open(SKIN:GetVariable('ROOTCONFIGPATH')..'Core\\Setting\\Generated.inc','w')
	local RawSkin = tostring(SKIN:GetVariable('Skin.Name'))
	Skin = string.gsub(RawSkin, "-", "")
	local Appearance = tostring(SKIN:GetVariable('Skin.Appearance'))
	local Layout = tostring(SKIN:GetVariable('Skin.Layout'))
	local CS = tostring(SKIN:GetVariable('Skin.CS'))
	local Media = tostring(SKIN:GetVariable('Skin.Media'))
	local Render = tostring(SKIN:GetVariable('Skin.Render'))
	local FAQ = tostring(SKIN:GetVariable('Skin.FAQ'))
	-- /////////////////////////////////////////////////////////
	-- /////////////////////////////////////////////////////////
	-- category general
	File:write('[General:Category]\n'
	,'Meter=String\n'
	,'MeterStyle=Set.String:S | Pagecat:S\n'
	,'Text=GENERAL\n'
	,'Y=(#Set.P#+64*[Set.S])\n')

	File:write('[Info]\n'
	,'Meter=Shape\n'
	,'Y=(10*[Set.S])R\n'
	,'MeterStyle=PageBox:S\n'
	,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 1 ? 255: 0)\n'
	,'Handle=1\n'
	
	,'\n'
	,'[InfoIcon]\n'
	,'Meter=Image\n'
	,'MeterStyle=PageIcon:S\n'
	,'Greyscale=(#BarHandler# = 1 ? 1 : 0)\n'
	-- ,'ImageTint=(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255)\n'
	,'\n'
	,'[1]\n'
	,'Meter=String\n'
	,'Text=Info\n'
	,'DynamicVariables-1\n'
	,'MeterStyle=Set.String:S | PageText:S\n'
	,'\n'
	,'[General]\n'
	,'Meter=Shape\n'
	,'Y=(10*[Set.S])R\n'
	,'MeterStyle=PageBox:S\n'
	,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 2 ? 255: 0)\n'
	,'Handle=2\n'
	
	,'\n'
	,'[GeneralIcon]\n'
	,'Meter=Image\n'
	,'MeterStyle=PageIcon:S\n'
	,'Greyscale=(#BarHandler# = 2 ? 1 : 0)\n'
	-- ,'ImageTint=(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255)\n'
	,'\n'
	,'[2]\n'
	,'Meter=String\n'
	,'Text=General\n'
	,'DynamicVariables-1\n'
	,'MeterStyle=Set.String:S | PageText:S\n')
	-- /////////////////////////////
	if string.find(Appearance, Skin) then
		File:write('[Appearance]\n'
		,'Meter=Shape\n'
		,'Y=(10*[Set.S])R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 3 ? 255: 0)\n'
		,'Handle=3\n'
		
		,'\n'
		,'[AppearanceIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 3 ? 1 : 0)\n'
		-- ,'ImageTint=(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255)\n'
		,'\n'
		,'[3]\n'
		,'Meter=String\n'
		,'Text=Appearance\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	-- /////////////////////////////
	if string.find(Layout, Skin) then
		File:write('[Layout]\n'
		,'Meter=Shape\n'
		,'Y=(10*[Set.S])R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 4 ? 255: 0)\n'
		,'Handle=4\n'
		
		,'\n'
		,'[LayoutIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 4 ? 1 : 0)\n'
		-- ,'ImageTint=(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255)\n'
		,'\n'
		,'[4]\n'
		,'Meter=String\n'
		,'Text=Layout\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	-- /////////////////////////////
	if string.find(CS, Skin) then
		File:write('[ColorScheme]\n'
		,'Meter=Shape\n'
		,'Y=(10*[Set.S])R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 4 ? 255: 0)\n'
		,'Handle=4\n'
		
		,'\n'
		,'[ColorSchemeIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 4 ? 1 : 0)\n'
		-- ,'ImageTint=(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255)\n'
		,'\n'
		,'[4]\n'
		,'Meter=String\n'
		,'Text=Color scheme\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	-- /////////////////////////////
	if string.find(Media, Skin) then
		File:write('[Media]\n'
		,'Meter=Shape\n'
		,'Y=(10*[Set.S])R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 5 ? 255: 0)\n'
		,'Handle=5\n'
		
		,'\n'
		,'[MediaIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 5 ? 1 : 0)\n'
		-- ,'ImageTint=(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255)\n'
		,'\n'
		,'[5]\n'
		,'Meter=String\n'
		,'Text=Media\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	-- /////////////////////////////
	if string.find(Render, Skin) then
		File:write('[Render]\n'
		,'Meter=Shape\n'
		,'Y=(10*[Set.S])R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 6 ? 255: 0)\n'
		,'Handle=6\n'
		
		,'\n'
		,'[RenderIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 6 ? 1 : 0)\n'
		-- ,'ImageTint=(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255)\n'
		,'\n'
		,'[6]\n'
		,'Meter=String\n'
		,'Text=Render\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	
	File:close()

	end

	-- -- /////////////////////////////
	-- if string.find({}, Skin) then
	-- 	File:write('[{}]\n'
	-- 	,'Meter=Shape\n'
	-- 	,'Y=(10*[Set.S])R\n'
	-- 	,'MeterStyle=PageBox:S\n'
	-- 	,'Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = <> ? 255: 0)\n'
	-- 	,'Handle=<\n'
	-- 	
	-- 	,'\n'
	-- 	,'[{}Icon]\n'
	-- 	,'Meter=Image\n'
	-- 	,'MeterStyle=PageIcon:S\n'
	-- 	,'Greyscale=(#BarHandler# = <> ? 1 : 0)\n'
	-- 	,'ImageTint=(#BarHandler# = <> ? 0 : 255),(#BarHandler# = <> ? 0 : 255),(#BarHandler# = <> ? 0 : 255)\n'
	-- 	,'\n'
	-- 	,'[<>]\n'
	-- 	,'Meter=String\n'
	-- 	,'Text={}\n'
	-- 	,'DynamicVariables-1\n'
	-- 	,'MeterStyle=Set.String:S | PageText:S\n')
	-- 	end