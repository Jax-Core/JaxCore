[Variables]
CCW=747
CCH=595
[Position]
Meter=Shape
MeterStyle=CtxBox:S
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Text_Color#"][!SetOption 2 FontColor "#Set.Text_Color#"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Pri_Color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Pri_Color#"][!SetOption 2 FontColor "#Set.Pri_Color#"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!Hide][!CommandMeasure Ctx.Move:M "openSub('#CURRENTSECTION#')"]
DynamicVariables=1
[PositionIcon]
Meter=Image
MeterStyle=CtxIcon:S
[2]
Meter=String
Text=Align...
MeterStyle=Ctx.String:S | CtxText:S
