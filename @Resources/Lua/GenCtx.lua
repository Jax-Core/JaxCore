
function Update()
	local File = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Ctx\\#ContextC.inc','w')
	local Left = tonumber(SKIN:GetVariable('Sec.Ctx.Left', '0'))
	local Center = tonumber(SKIN:GetVariable('Sec.Ctx.Center', '0'))
	-- local Blur = tonumber(SKIN:GetVariable('Sec.Ctx.Blur', '0'))
	local Settings = tonumber(SKIN:GetVariable('Sec.Ctx.Settings', '1'))
	local Unload = tonumber(SKIN:GetVariable('Sec.Ctx.Unload', '0'))
	local SAW = tonumber(SKIN:GetVariable('SCREENAREAWIDTH'))
	local CCW = tonumber(SKIN:GetVariable('CURRENTCONFIGWIDTH'))
	local SAH = tonumber(SKIN:GetVariable('SCREENAREAHEIGHT'))
	local CCH = tonumber(SKIN:GetVariable('CURRENTCONFIGHEIGHT'))
	-- print(Blur, Settings)
	-- /////////////////////////////////////////////////////////

	if Left == 1 then
		File:write('[TopLeft]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 2 FontColor "234,234,230"][!UpdateMeter *][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 2 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
		,'LeftMouseUpAction=[!Move 20 20 "#Sec.Skin#\\Main"][!DeactivateConfig]\n'
		,'DynamicVariables=1\n'
		,'[TopLeftIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=CtxIcon:S\n'
		,'[2]\n'
		,'Meter=String\n'
		,'Text=Align Top Left\n'
		,'MeterStyle=Ctx.String:S | CtxText:S\n')
		end
	
	if Center == 1 then
		File:write('[Center]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 3 FontColor "234,234,230"][!UpdateMeter *][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 3 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
		,'LeftMouseUpAction=[!Move (' ..SAW.. '/2-(' ..CCW.. ')/2) (' ..SAH.. '/2-(' ..CCH.. ')/2) "#Sec.Skin#\\Main"][!DeactivateConfig]\n'
		,'DynamicVariables=1\n'
		,'[CenterIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=CtxIcon:S\n'
		,'[3]\n'
		,'Meter=String\n'
		,'Text=Align Center\n'
		,'MeterStyle=Ctx.String:S | CtxText:S\n')
		end

	-- if (Blur == 1 or Settings == 1 or Unload == 1) then
	if (Settings == 1 or Unload == 1) then
		File:write('[Divider1]\n'
		,'Meter=Shape\n'
		,'MeterStyle=Ctx.Div:S\n')
	end
		
	-- if Blur == 1 then
	-- 	File:write('[Blur]\n'
	-- 	,'Meter=Shape\n'
	-- 	,'MeterStyle=CtxBox:S\n'
	-- 	,'Fill=Fill Color #Set.Pri_Color#,0\n'
	-- 	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 11 FontColor "234,234,230"][!UpdateMeter *][!Redraw]\n'
	-- 	,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 11 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
	-- 	,'LeftMouseUpAction=[!UpdateMeasure RefreshBlur "#Sec.Skin#\\Main"][!DeactivateConfig]\n'
	-- 	,'DynamicVariables=1\n'
	-- 	,'[BlurIcon]\n'
	-- 	,'Meter=Image\n'
	-- 	,'MeterStyle=CtxIcon:S\n'
	-- 	,'[11]\n'
	-- 	,'Meter=String\n'
	-- 	,'Text=Refresh blur\n'
	-- 	,'MeterStyle=Ctx.String:S | CtxText:S\n')
	-- 	end
		
	if Settings == 1 then
		File:write('[Settings]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 21 FontColor "234,234,230"][!UpdateMeter *][!Redraw]\n'
		,'MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 21 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]\n'
		,'LeftMouseUpAction=[!WriteKeyValue Variables Skin.Name #Sec.Skin# "#@#SecVar.inc"][!WriteKeyValue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#JaxCore\\Main" "Settings.ini"][!DeactivateConfig]\n'
		,'DynamicVariables=1\n'
		,'[SettingsIcon]\n'
		,'Meter=Image\n'
		,'MeterStyle=CtxIcon:S\n'
		,'[21]\n'
		,'Meter=String\n'
		,'Text=Settings\n'
		,'MeterStyle=Ctx.String:S | CtxText:S\n')
		end
	
	if Unload == 1 then
		File:write('[Unload]\n'
		,'Meter=Shape\n'
		,'MeterStyle=CtxBox:S\n'
		,'Fill=Fill Color #Set.Pri_Color#,0\n'
		,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 22 FontColor "234,234,230"][!UpdateMeter *][!Redraw]\n'
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

	end




	
	-- if Left then
	-- 	File:write('[{}]\n'
	-- 	,'Meter=Shape\n'
	-- 	,'MeterStyle=CtxBox:S\n'
	-- 	,'Fill=Fill Color #Set.Pri_Color#,0\n'
	-- 	,'MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption <> FontColor "234,234,230"][!UpdateMeter *][!Redraw]\n'
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