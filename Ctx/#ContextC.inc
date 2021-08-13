[Center]
Meter=Shape
MeterStyle=CtxBox:S
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,110"][!SetOption #CURRENTSECTION#Icon ImageTint "234,234,230"][!SetOption 3 FontColor "234,234,230"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 3 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!Move (1920/2-(1026)/2) (1080/2-(898)/2) "#Sec.Skin#\Main"][!DeactivateConfig]
DynamicVariables=1
[CenterIcon]
Meter=Image
MeterStyle=CtxIcon:S
[3]
Meter=String
Text=Align Center
MeterStyle=Ctx.String:S | CtxText:S
