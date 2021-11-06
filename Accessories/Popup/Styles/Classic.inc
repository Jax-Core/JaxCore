; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[Variables]
Drop.Animation_Time=300

[mTween]
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Drop.Animation_Time#
Optional0=Easing InOutCirc
[mActions]
ActionList1=Wait 100 | NUOLOn | Start0 | Wait #Drop.Animation_Time# | Custom1
ActionList2=Rewind0 | Wait #Drop.Animation_Time# | Deactivate

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[B]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#*#TweenNode1#),#Sec.R# | StrokeWidth 0 | Fill Color 35,35,35
Group=Tweenable
DynamicVariables=1

[BC]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#*#TweenNode1#),#Sec.R# | StrokeWidth 0 | Fill Color 35,35,35
Group=Tweenable
DynamicVariables=1

[Image]
Meter=Image
ImageName=Variants\Splash\#Sec.Arg1#.png
W=(#Sec.W#)
H=(#Sec.H#*0.4)
SolidColor=255,255,255
Container=BC

[Title]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)R
FontSize=(22*#Sec.S#)
FontFace=Poppins SemiBold
StringAlign=Center
MeterStyle=Sec.String:S

[Description]
Meter=String
X=r
Y=(#Sec.P#)R
FontSize=(12*#Sec.S#)
StringAlign=Center
MeterStyle=Sec.String:S

[Info]
Meter=String
X=r
Y=(#Sec.H#-#Sec.P#*2-#SEc.BottomHeight#)
FontSize=(8*#Sec.S#)
FontColor=120,120,120
StringAlign=CenterBottom
MeterStyle=Sec.String:S

