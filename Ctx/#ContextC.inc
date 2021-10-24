[Divider1]
Meter=Shape
MeterStyle=Ctx.Div:S
[Core]
Meter=Shape
MeterStyle=CtxBox:S
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 21 FontColor "234,234,230"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 21 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Skin.Name #Sec.Skin# "#@#SecVar.inc"][!WriteKeyValue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!DeactivateConfig]
DynamicVariables=1
[CoreIcon]
Meter=Image
MeterStyle=CtxIcon:S
[21]
Meter=String
Text=Configure in Core
MeterStyle=Ctx.String:S | CtxText:S
