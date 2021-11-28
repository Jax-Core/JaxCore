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

; [ImageContainer]

[ContentContainer]
Meter=Shape
X=(#Set.L#+#set.P#)
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 255,255,255
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-50,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+50,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseActionCursor=0
Group=Background

[ScrollBar]
Meter=Shape
X=([ContentContainer:XW]+25*[Set.S])
Y=#Set.P#
Shape=Line 0,0,0,([ContentContainer:H]/([ContentContainer:H]-[AnchorChecker])*[ContentContainer:H]) | StrokeWidth 4 | StrokeStartCap Round | StrokeEndCap Round | OffSet 0,(#Scroll#/([AnchorChecker]+1)*([ContentContainer:H]-([ContentContainer:H]/([ContentContainer:H]-[AnchorChecker])*[ContentContainer:H]))) | Extend Fill
Fill=Stroke Color #Set.Ter_Color#
Shape2=Line 0,0,0,[ContentContainer:H] | StrokeWidth 10 | Stroke Color 0,0,0,1
DynamicVariables=1
Group=Background
Hidden=1
MeterStyle=ScrolLBar:Idle
[ScrollBar:Scrolling]
Fill=Stroke Color #Set.Subtext_Color#
[ScrollBar:Idle]
LeftMouseDownAction=[!SetVariable ScrollClickedPos "$MouseY$"][!SetOption ScrollBar MeterStyle ScrollBar:Scrolling][!EnableMeasure MouseScrollBar][!UpdateMeasure MouseScrollBar][!CommandMeasure MouseScrollBar "Start"]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Subtext_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]