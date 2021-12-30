
function Gen()
	local File = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Ctx\\#ContextC.inc','w')
	local Pos = tonumber(SKIN:GetVariable('Sec.Ctx.Pos', '0'))
	-- local Blur = tonumber(SKIN:GetVariable('Sec.Ctx.Blur', '0'))
	local Settings = tonumber(SKIN:GetVariable('Sec.Ctx.Settings', '1'))
	local Unload = tonumber(SKIN:GetVariable('Sec.Ctx.Unload', '0'))
	local SAW = tonumber(SKIN:GetVariable('SCREENAREAWIDTH'))
	local CCW = tonumber(SKIN:GetVariable('CURRENTCONFIGWIDTH'))
	local SAH = tonumber(SKIN:GetVariable('SCREENAREAHEIGHT'))
	local CCH = tonumber(SKIN:GetVariable('CURRENTCONFIGHEIGHT'))
	-- print(Blur, Settings)
	-- /////////////////////////////////////////////////////////

	if Pos == 1 then
		File:write('[Variables]\n'
		,'CCW='..CCW..'\n'
		,'CCH='..CCH..'\n'
		,'[Position]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Text_Color#"][!SetOption 2 FontColor "#Set.Text_Color#"][!UpdateMeter *][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 2 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
		,'LeftMouseUpAction=[!Hide][!CommandMeasure Ctx.Move:M "openSub(\'#CURRENTSECTION#\')"]\n'
		,'DynamicVariables=1\n'
		,'[PositionIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=CtxIcon:S\n'
		,'[2]\n'
		,'Meter=String\n'
		,'Text=Align...\n'
		,'MeterStyle=Ctx.String:S | CtxText:S\n')
		end

	-- if (Blur == 1 or Settings == 1 or Unload == 1) then
	if (Settings == 1 or Unload == 1) then
		File:write('[Divider1]\n'
		,'Meter=Shape\n'
		,'MeterStyle=Ctx.Div:S\n')
	end
		
	if Settings == 1 then
		File:write('[Core]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Text_Color#"][!SetOption 21 FontColor "#Set.Text_Color#"][!UpdateMeter *][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 21 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
		,'LeftMouseUpAction=[!WriteKeyValue Variables Skin.Name #Sec.Skin# "#@#SecVar.inc"][!WriteKeyValue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#JaxCore\\Main" "Settings.ini"][!DeactivateConfig]\n'
		,'DynamicVariables=1\n'
		,'[CoreIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=CtxIcon:S\n'
		,'[21]\n'
		,'Meter=String\n'
		,'Text=Configure in Core\n'
		,'MeterStyle=Ctx.String:S | CtxText:S\n')
		end
	
	if Unload == 1 then
		File:write('[Unload]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Text_Color#"][!SetOption 22 FontColor "#Set.Text_Color#"][!UpdateMeter *][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 22 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
		,'LeftMouseUpAction=[!UpdateMeasure Unload "#Sec.Skin#\\Main"][!DeactivateConfig]\n'
		,'DynamicVariables=1\n'
		,'[UnloadIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=CtxIcon:S\n'
		,'[22]\n'
		,'Meter=String\n'
		,'Text=Unload\n'
		,'MeterStyle=Ctx.String:S | CtxText:S\n')
		end
	File:close()

	if SKIN:GetMeasure('mToggle') then 
		SKIN:Bang('!PauseMeasure', 'mToggle') 
		SKIN:Bang('!WriteKeyValue', 'Variables', 'Ctx.Parent.Toggle', 1, SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Ctx\\Main.ini')
	else
		SKIN:Bang('!WriteKeyValue', 'Variables', 'Ctx.Parent.Toggle', 0, SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Ctx\\Main.ini')
	end

	SKIN:Bang('!WriteKeyValue', 'Variables', 'Ctx.Parent', SKIN:GetVariable('CURRENTCONFIG'), SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Ctx\\Main.ini')

	end




	
	-- if Left then
	-- 	File:write('[{}]\n'
	-- 	,'Meter=Shape\n'
	-- 	,'MeterStyle=CtxBox:S\n'
	-- 	,'Fill=Fill Color #Set.Pri_Color#,0\n'
	-- 	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Text_Color#"][!SetOption <> FontColor "#Set.Text_Color#"][!UpdateMeter *][!Redraw]\n'
	-- 	,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption <> FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
	-- 	,'LeftMouseUpAction=\n'
	-- 	,'DynamicVariables=1\n'
	-- 	,'[{}Icon]\n'
	-- 	,'Meter=Image\n'
	-- 	,'MeterStyle=CtxIcon:S\n'
	-- 	,'[<>]\n'
	-- 	,'Meter=String\n'
	-- 	,'Text={}\n'
	-- 	,'MeterStyle=Ctx.String:S | CtxText:S\n')
	-- 	end