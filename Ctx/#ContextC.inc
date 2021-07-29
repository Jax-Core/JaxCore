[TopLeft]
Meter=Shape
MeterStyle=CtxBox:S
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 2 FontColor "234,234,230"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 2 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!Move 20 20 "#Sec.Skin#\Main"][!DeactivateConfig]
DynamicVariables=1
[TopLeftIcon]
Meter=Image
MeterStyle=CtxIcon:S
[2]
Meter=String
Text=Align Top Left
MeterStyle=Ctx.String:S | CtxText:S
[Center]
Meter=Shape
MeterStyle=CtxBox:S
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 3 FontColor "234,234,230"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 3 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!Move (1920/2-(500)/2) (1080/2-(250)/2) "#Sec.Skin#\Main"][!DeactivateConfig]
DynamicVariables=1
[CenterIcon]
Meter=Image
MeterStyle=CtxIcon:S
[3]
Meter=String
Text=Align Center
MeterStyle=Ctx.String:S | CtxText:S
[Divider1]
Meter=Shape
MeterStyle=Ctx.Div:S
[Settings]
Meter=Shape
MeterStyle=CtxBox:S
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 21 FontColor "234,234,230"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 21 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Skin.Name #Sec.Skin# "#@#SecVar.inc"][!WriteKeyValue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!DeactivateConfig]
DynamicVariables=1
[SettingsIcon]
Meter=Image
MeterStyle=CtxIcon:S
[21]
Meter=String
Text=Settings
MeterStyle=Ctx.String:S | CtxText:S
