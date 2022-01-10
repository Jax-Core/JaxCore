; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Rainmeter]
Update=-1

[Variables]
; Drop.Animation_Time=300
TweenNode1=1
[mActions]
ActionList1=NUOLOn
ActionList2=Deactivate

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[B]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#),#Sec.R# | StrokeWidth 0 | Fill Color #Set.Sec_Color#
; This=0 | #Set.Accent_Color# ; 0 | #Set.Accent_color_2# ; 1
Group=Tweenable
DynamicVariables=1

[BC]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#),#Sec.R# | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Group=Tweenable
DynamicVariables=1

[ImageContainer]
Meter = Shape
x=(#Sec.BottomHeight#/2)
y=(#Sec.BottomHeight#/2)
Shape=Rectangle 0,0,(#Sec.W#-#Sec.BottomHeight#),(#Sec.H#*0.4),(#Sec.R#*0.8) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Group=Tweenable
DynamicVariables=1

[Image]
Meter=Image
W=(#Sec.W#-#Sec.BottomHeight#)
H=(#Sec.H#*0.4)
PreserveAspectRatio=2
Container=ImageContainer

[Style.Title:S]
X=(#Sec.P#)
Y=([ImageContainer:YH]+#Sec.P#)
FontSize=(18*#Sec.S#)
FontFace=#Set.Font# 
FontWeight=(650)
DynamicVariables=1
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0

[Style.Description:S]
X=(#Sec.P#)
Y=(#Sec.P#)R
FontSize=(12*#Sec.S#)
inlinePattern=NEW!
InlineSetting=Color | FFC83D

[Style.NextLineDescription:S]
X=(#Sec.P#)
Y=(#Sec.S#*22)r
FontSize=(12*#Sec.S#)
inlinePattern=NEW!
InlineSetting=Color | FFC83D

[Style.Link:S]
FontColor=059FD8
X=(#Sec.P#)
Y=(#Sec.S#*22)r
FontSize=(12*#Sec.S#)
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Style.Link:S | Link:Over"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Style.Link:S | Link:Leave"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Link:Leave]
InlineSetting=
[Link:Over]
InlineSetting=Underline

[Info]
X=r
Y=(#Sec.H#-#Sec.P#*2-#SEc.BottomHeight#)
FontSize=(8*#Sec.S#)
FontColor=#Set.SubText_Color#
StringAlign=CenterBottom
MeterStyle=Sec.String:S




[Esc:Override]
Container=