
[B]
Meter = Shape
Shape=Rectangle 0,0,#Set.W#,#Set.H#,#Set.R#,#Set.R#
Shape2=Rectangle 0,0,(#Set.W#),(#Set.H#),(#Set.R#),(#Set.R#) | StrokeWidth 0 | Fill Color 18,18,18
Shape3=Rectangle (#Set.L#),(#Set.P#),(#Set.W#-#Set.L#-#Set.P#),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 23,23,23

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


[ContentContainer]
Meter=Shape
X=#Set.L#
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 255,255,255
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
FillE=Fill Color 255,255,255,50
MouseOverAction=[!SetOption Esc FillE "Fill Color 255,255,255"][!UpdateMeter Esc][!Redraw]
MouseLeaveAction=[!SetOption Esc FillE "Fill Color 255,255,255,50"][!UpdateMeter Esc][!Redraw]
LeftMouseUpAction=[!DeactivateConfig][!DeactivateConfig "#JaxCore\Main\Com"][!ActivateConfig "#Skin.Name#\Main"]