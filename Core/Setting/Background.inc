[B]
Meter=Shape
Shape=Rectangle 0,0, #Set.W#, #Set.H#, #Set.R# | StrokeWidth 0 | Fill Color #Set.Pri_Color#
; Shape2=Rectangle 0,0, #Set.L#, #Set.H# | StrokeWidth 0 | Fill Color #Set.Ter_Color#
MouseActionCursor=0
DynamicVariables=1

[SettingsText]
Meter=String
MeterStyle=Set.String:S
Text=#Skin.Name#
X=(#Set.P#)
Y=(#Set.P#)
Fontface=Poppins SemiBold
StringAlign=LeftTop
FontSize=(14*[Set.S])
DynamicVariables=1
Group=Shorthand


[ContentContainer]
Meter=Shape
X=(#Set.L#+#set.P#)
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 255,255,255
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-50,Clamp(#Set.H#-#Set.P#*2-[Anchor:Y], -1000, 0),0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+50,Clamp(#Set.H#-#Set.P#*2-[Anchor:Y], -1000, 0),0))"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=[!SetOptionGroup DropDown MEterStyle "Set.DropDown:S | Set.DD0"][!HideMeterGroup DD][!ShowMEterGroup DD0][!UpdateMEterGroup DRopdown][!Redraw]
MouseActionCursor=0