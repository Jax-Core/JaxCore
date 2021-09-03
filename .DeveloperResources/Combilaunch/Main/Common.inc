[Variables]
EndActions=[!SetOptionGroup C MouseOverAction ""][!SetOption S Text ""][!SetVariable CURRENT ""][!SetVariable CURRENTLINE "-100,-100 | LineTo -100,-100"][!SetOption B MouseLeaveAction ""][!SetVariable CURRENTPOS ""][!HideMeter L2][!DisableMeasure measureMouse][!Updatemeasure measureMouse][!UpdateMeter *][!Redraw]

@includeChecks=#@#Checks.inc

[Start]
Measure=Calc
OnUpdateAction=[!Delay 100][!EnableMeasureGroup NUOL][!DisableMeasure #CURRENTSECTION#]

[S]
Meter=String
FontSize=13
FontColor=255,255,255
FontFace=Segoe UI
AntiAlias=1
X=(#Padding#+10+#Gap#*100)
Y=0
StringAlign=Center
DynamicVariables=1
Text=

[1]
Meter=Shape
X=(#Padding#+10)
Y=(#Padding#+10)
MeterStyle=C
[L]
Meter=Shape
X=r
Y=r
DynamicVariables=1
Shape=Path This | StrokeWidth (5) | Stroke Color #ShadowColor#,#ShadowColorOpacity# | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round | Offset 2,2
Shape2=Path This | StrokeWidth (5) | Stroke Color #LineColor#,#LineOpacity# | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round
This=#CURRENTLINE#

[2]
Meter=Shape
MeterStyle=C

[3]
Meter=Shape
MeterStyle=C

[4]
Meter=Shape
X=(#Padding#+10)
Y=(#Gap#*100)r
MeterStyle=C

[5]
Meter=Shape
MeterStyle=C

[6]
Meter=Shape
MeterStyle=C

[7]
Meter=Shape
X=(#Padding#+10)
Y=(#Gap#*100)r
MeterStyle=C

[8]
Meter=Shape
MeterStyle=C
; [TS]
; Meter=String
; FontSize=10
; FontColor=255,255,255
; AntiAlias=1
; X=r
; Y=r
; StringAlign=CenterCenter
; DynamicVariables=1

[9]
Meter=Shape
MeterStyle=C
[L2]
Meter=Shape
X=0
Y=0
DynamicVariables=1
Shape=Path This | StrokeWidth (5) | Stroke Color #LineColor#,#LineOpacity# | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round

[measureMouse]
Measure=Plugin
Plugin=Mouse
Disabled=1
MouseMoveAction=[!SetOption TS Text "$mouseX$, $mouseY$"][!SetOption L2 This "#*CURRENTPOS*# | LineTo $mouseX$,$mouseY$"][!UpdateMeter *][!Redraw]
DynamicVariables=1
RelativeToSkin=1