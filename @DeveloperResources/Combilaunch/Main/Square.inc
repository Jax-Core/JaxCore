[B]
Meter=Shape
Shape=Rectangle 0,0,((#Padding#+10)*2+100*2*#Gap#),((#Padding#+10)*2+100*2*#Gap#) | StrokeWidth 0 | Fill Color #BackgroundColor#,(Clamp(#BackgroundOpacity#,1,255))
MouseLeaveAction=


[C]
Shape=Ellipse 0,0,(#Size#*10),(#Size#*10) | StrokeWidth 10 | Fill Color #DotColor#,#DotColorOpacity# | StrokeColor #DotBorderColor#,#DotBorderOpacity# | Extend Pulse
Pulse=Scale 1,1
Shape2=Ellipse 0,0,#DotBox#,#DotBox# | StrokeWidth 0 | Fill Color 0,0,0,1
LeftMouseDownAction=[!Log Down][!ShowMeter l2][!SetOption measureMouse Disabled (1-#MouseTraceBool#)][!Updatemeasure measureMouse][!SetVariable CURRENTLINE "([#CURRENTSECTION#:X]-40),([#CURRENTSECTION#:Y]-40)"][!SetVariable CURRENTPOS "([#CURRENTSECTION#:X]),([#CURRENTSECTION#:Y])"][!SetOptionGroup C MouseOverAction """[!Log Over][!SetVariable CURRENT "#*CURRENT*##*CURRENTSECTION*#"][!SetVariable CURRENTLINE "#*CURRENTLINE*# | LineTo ([#*CURRENTSECTION*#:X]-40),([#*CURRENTSECTION*#:Y]-40) | SetRoundJoin 1"][!SetVariable CURRENTPOS "([#*CURRENTSECTION*#:X]),([#*CURRENTSECTION*#:Y])"][!SetOption #*CURRENTSECTION*# MouseOverAction ""][!SetOption S Text ""][!UpdateMeasure Name][!UpdateMeter *][!Redraw]#PulseAction#"""][!SetOption B MouseLeaveAction """#*EndActions*#[!SetVariable DotColor 255,0,0][!UpdateMeter *][!Redraw][!Delay 200][!SetVariable DotColor #DotColorbackup#][!UpdateMeter *][!Redraw]"""][!UpdateMeter *]
DynamicVariables=1
Group=C
X=(#Gap#*100)r
Y=r

@includeCommon=Common.inc