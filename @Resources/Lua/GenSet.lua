
function Initialize()
	local File = io.open(SKIN:GetVariable('ROOTCONFIGPATH')..'Shell\\#SettingsC.inc','w')
	local RawSkin = tostring(SKIN:GetVariable('Skin.Name'))
	Skin = string.gsub(RawSkin, "-", "")
	local Appearance = tostring(SKIN:GetVariable('Skin.Appearance'))
	local Layout = tostring(SKIN:GetVariable('Skin.Layout'))
	local Media = tostring(SKIN:GetVariable('Skin.Media'))
	local Render = tostring(SKIN:GetVariable('Skin.Render'))
	local FAQ = tostring(SKIN:GetVariable('Skin.FAQ'))
	-- /////////////////////////////////////////////////////////
	-- /////////////////////////////////////////////////////////
	-- category general
	File:write('[General:Category]\n'
	,'Meter=String\n'
	,'MeterStyle=Set.String:S\n'
	,'Text=GENERAL\n'
	,'FontFace=Segoe UI\n'
	,'X=#Set.P#\n'
	,'Y=(#Set.P#*2+64)\n'
	,'StringAlign=Left\n'
	,'FontSize=(8*#Set.S#)\n'
	,'Container=\n'
	,'FontColor=150,150,150\n')

	File:write('[Info]\n'
	,'Meter=Shape\n'
	,'Y=(10*#Set.S#)R\n'
	,'MeterStyle=PageBox:S\n'
	,'Fill=Fill Color 255,255,255,(#BarHandler# = 1 ? 220 : 0)\n'
	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 1 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 1 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	,'\n'
	,'[InfoIcon]\n'
	,'Meter=Image\n'
	,'MeterStyle=PageIcon:S\n'
	,'Greyscale=(#BarHandler# = 1 ? 1 : 0)\n'
	,'ImageTint=(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255)\n'
	,'\n'
	,'[1]\n'
	,'Meter=String\n'
	,'Text=Info\n'
	,'DynamicVariables-1\n'
	,'MeterStyle=Set.String:S | PageText:S\n'
	,'\n'
	,'[General]\n'
	,'Meter=Shape\n'
	,'Y=(10*#Set.S#)R\n'
	,'MeterStyle=PageBox:S\n'
	,'Fill=Fill Color 255,255,255,(#BarHandler# = 2 ? 220 : 0)\n'
	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 2 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 2 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	,'\n'
	,'[GeneralIcon]\n'
	,'Meter=Image\n'
	,'MeterStyle=PageIcon:S\n'
	,'Greyscale=(#BarHandler# = 2 ? 1 : 0)\n'
	,'ImageTint=(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255)\n'
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
		,'Y=(10*#Set.S#)R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color 255,255,255,(#BarHandler# = 3 ? 220 : 0)\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 3 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 3 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'\n'
		,'[AppearanceIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 3 ? 1 : 0)\n'
		,'ImageTint=(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255)\n'
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
		,'Y=(10*#Set.S#)R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color 255,255,255,(#BarHandler# = 4 ? 220 : 0)\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 4 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 4 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'\n'
		,'[LayoutIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 4 ? 1 : 0)\n'
		,'ImageTint=(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255)\n'
		,'\n'
		,'[4]\n'
		,'Meter=String\n'
		,'Text=Layout\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	-- /////////////////////////////
	if string.find(Media, Skin) then
		File:write('[Media]\n'
		,'Meter=Shape\n'
		,'Y=(10*#Set.S#)R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color 255,255,255,(#BarHandler# = 5 ? 220 : 0)\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 5 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 5 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'\n'
		,'[MediaIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 5 ? 1 : 0)\n'
		,'ImageTint=(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255)\n'
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
		,'Y=(10*#Set.S#)R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color 255,255,255,(#BarHandler# = 6 ? 220 : 0)\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 6 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 6 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'\n'
		,'[RenderIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 6 ? 1 : 0)\n'
		,'ImageTint=(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255)\n'
		,'\n'
		,'[6]\n'
		,'Meter=String\n'
		,'Text=Render\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	
	File:write('[Help:Category]\n'
	,'Meter=String\n'
	,'MeterStyle=Set.String:S\n'
	,'Text=HELP\n'
	,'FontFace=Segoe UI\n'
	,'X=#Set.P#\n'
	,'Y=(#Set.H#-140)\n'
	,'StringAlign=Left\n'
	,'FontSize=(8*#Set.S#)\n'
	,'Container=\n'
	,'FontColor=150,150,150\n')

	File:write('[Help]\n'
	,'Meter=Shape\n'
	,'Y=(10*#Set.S#)R\n'
	,'MeterStyle=PageBox:S\n'
	,'Fill=Fill Color 255,255,255,(#BarHandler# = 11 ? 220 : 0)\n'
	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 11 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 11 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	,'\n'
	,'[HelpIcon]\n'
	,'Meter=Image\n'
	,'MeterStyle=PageIcon:S\n'
	,'Greyscale=(#BarHandler# = 11 ? 1 : 0)\n'
	,'ImageTint=(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255)\n'
	,'\n'
	,'[11]\n'
	,'Meter=String\n'
	,'Text=Help\n'
	,'DynamicVariables-1\n'
	,'MeterStyle=Set.String:S | PageText:S\n')
	-- /////////////////////////////
	if string.find(FAQ, Skin) then
		File:write('[FAQ]\n'
		,'Meter=Shape\n'
		,'Y=(10*#Set.S#)R\n'
		,'MeterStyle=PageBox:S\n'
		,'Fill=Fill Color 255,255,255,(#BarHandler# = 12 ? 220 : 0)\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 12 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 12 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
		,'\n'
		,'[FAQIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=PageIcon:S\n'
		,'Greyscale=(#BarHandler# = 12 ? 1 : 0)\n'
		,'ImageTint=(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255)\n'
		,'\n'
		,'[12]\n'
		,'Meter=String\n'
		,'Text=FAQ\n'
		,'DynamicVariables-1\n'
		,'MeterStyle=Set.String:S | PageText:S\n')
		end
	
	File:close()

	end

	-- -- /////////////////////////////
	-- if string.find({}, Skin) then
	-- 	File:write('[{}]\n'
	-- 	,'Meter=Shape\n'
	-- 	,'Y=(10*#Set.S#)R\n'
	-- 	,'MeterStyle=PageBox:S\n'
	-- 	,'Fill=Fill Color 255,255,255,(#BarHandler# = <> ? 220 : 0)\n'
	-- 	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = <> ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
	-- 	,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = <> ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]\n'
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