[B]
Meter = Shape
Shape=Rectangle 0,0,(#Set.W#),(#Set.H#),(#Set.R#),(#Set.R#) | StrokeWidth 0 | Fill Color #Set.Pri_Color#
; Shape3=Rectangle (#Set.L#),(#Set.P#),(#Set.W#-#Set.L#-#Set.P#),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color #Set.Sec_Color#

[SmallShadow]
Meter=Image
ImageName=#@#Images\#CURRENTSECTION#.png
Greyscale=1
ImageTint=#Set.Shadow#
W=(#Set.W#)
H=(#Set.H#)

[B2]
Meter=Shape
Shape=Rectangle (#Set.L#),(#Set.P#),(#Set.W#-#Set.L#-#Set.P#),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color #Set.Sec_Color#

[Logo]
Meter=Image
ImageName=#@#Images\Logo.png
X=(#Set.P#)
Y=#Set.P#
W=(64*#Set.S#)
H=(64*#Set.S#)
Leftmouseupaction=[!ActivateConfig "#CURRENTCONFIG#" "Home.ini"]
[SettingsText]
Meter=String
MeterStyle=Set.String:S
Text=#Skin.Shorthand#
X=R
Y=(64/2*#Set.S#)r
StringAlign=LeftCenter
FontSize=(14*#Set.S#)
Container=
FontWeight=500
DynamicVariables=1
Group=Shorthand


[ContentContainer]
Meter=Shape
X=#Set.L#
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color #Set.Opp_Color#
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-30,-150,0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+30,-150,0))"][!UpdateMeter *][!Redraw]
MouseActionCursor=0

[Dumy]
Meter=String
Container=ContentContainer

[Esc]
Meter=Shape
Shape=Ellipse (#Set.W#-15*#Set.S#),(15*#Set.S#),(5*#Set.S#),(5*#Set.S#) | StrokeWidth 10 | StrokeColor 0,0,0,1 | Extend FillE
FillE=Fill Color #Set.Opp_Color#,50
MouseOverAction=[!SetOption Esc FillE "Fill Color #Set.Opp_Color#"][!UpdateMeter Esc][!Redraw]
MouseLeaveAction=[!SetOption Esc FillE "Fill Color #Set.Opp_Color#,50"][!UpdateMeter Esc][!Redraw]
LeftMouseUpAction=[!DeactivateConfig]



[Set.GeneratePages:M]
Measure=Script
ScriptFile=#@#Lua\GenSet.lua
[Set.Refresh:M]
Measure=Script
ScriptFile=#@#Lua\Refresh.lua
Refreshed=0