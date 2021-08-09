[B]
Meter = Shape
Shape=Rectangle 0,0,(#Set.W#),(#Set.H#) | Extend Common
; Shape2=Path This | StrokeWidth 0 | Fill Color 0,0,0,100
Common=StrokeWidth 2 | Fill Color 0,0,0,100 | Stroke Color 50,50,50
; This=(200*[Set.S]),0 | LineTo #Set.W#,0 | LineTo #Set.W#,#Set.H# | LineTo (200*[Set.S]),#Set.H# | ClosePath 1

[Logo]
Meter=Image
ImageName=#@#Images\Logo.png
X=(#Set.P#)
Y=#Set.P#
W=(64*[Set.S])
H=(64*[Set.S])
Leftmouseupaction=[!ActivateConfig "#CURRENTCONFIG#" "Home.ini"]
[SettingsText]
Meter=String
MeterStyle=Set.String:S
Text=#Skin.Shorthand#
X=R
Y=(64/2*[Set.S])r
StringAlign=LeftCenter
FontSize=(14*[Set.S])
Container=
FontWeight=500
DynamicVariables=1
Group=Shorthand


[ContentContainer]
Meter=Shape
X=#Set.L#
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color #Set.Text_Color#
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-30,-150,0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+30,-150,0))"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!SetOptionGroup DropDown MEterStyle "Set.DropDown:S | Set.DD0"][!HideMeterGroup DD][!ShowMEterGroup DD0][!UpdateMEterGroup DRopdown][!Redraw]
MouseActionCursor=0

[Dumy]
Meter=String
Container=ContentContainer

[Home]
Meter=Shape
Shape=Ellipse (15*[Set.S]),(15*[Set.S]),(5*[Set.S]),(5*[Set.S]) | StrokeWidth 10 | StrokeColor 0,0,0,1 | Extend FillE
FillE=Fill Color #Set.Text_Color#,50
MouseOverAction=[!SetOption Home FillE "Fill Color #Set.Text_Color#"][!UpdateMeter Home][!Redraw]
MouseLeaveAction=[!SetOption Home FillE "Fill Color #Set.Text_Color#,50"][!UpdateMeter Esc][!Redraw]
LeftMouseUpAction=[!ActivateConfig "#JaxCore\Main" "Home.ini"]



[Set.GeneratePages:M]
Measure=Script
ScriptFile=#@#Lua\GenSet.lua
[Set.Refresh:M]
Measure=Script
ScriptFile=#@#Lua\Refresh.lua
Refreshed=0