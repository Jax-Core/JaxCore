[Rainmeter]
OnUnfocusAction=[!CommandMeasure mActions "Execute 2"]
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[Variables]
Drop.Animation_Time=400
Sec.P=(25*#sec.S#)

[mTween]
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Drop.Animation_Time#
Tween1=Single | Variable | TweenNode2 | 0 | 1 | #Drop.Animation_Time#
Optional0=Easing InOutSine | Group All
Optional1=Easing InOutCirc | Group All
[mActions]
ActionList1=Wait 100 | NUOLOn | Start0 | Wait #Drop.Animation_Time# | Start1
ActionList2=Deactivate

[Sec.String:S]
InlinePattern=^.*-
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[B]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#),#Sec.R# | StrokeWidth 1 | Fill Color 12,12,12,(255*#TweenNode1#) | Stroke Color 35,35,35
Group=Tweenable
DynamicVariables=1

[BC]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#*#TweenNode2#),#Sec.R# | StrokeWidth 0 | Fill Color 35,35,35,(155+100*#TweenNode2#)
Group=Tweenable
DynamicVariables=1
[Bar]
Meter=Shape
Shape=Line 0,0,(#Sec.W#),0 | StrokeWidth 2 | Stroke LinearGradient This
This=180 | CC1C15 ; 0.0 | FF700F ; 1.0
Container=BC

[Bar2]
Meter=Shape
Y=(#Sec.H#*#TweenNode2#)
Shape=Line 0,0,(#Sec.W#),0 | StrokeWidth 2 | Stroke LinearGradient This
This=180 | CC1C15 ; 0.0 | FF700F ; 1.0
Group=Tweenable
Container=BC
DynamicVariables=1

[Title]
Meter=String
X=(#Sec.P#)
Y=(#Sec.P#+(#Sec.arg1#+6-#Sec.P#)*(1-#TweenNode1#))
FontSize=(#Sec.arg2#+10*#TweenNode1#)
FontFace=Poppins SemiBold
Group=Tweenable
DynamicVariables=1
MeterStyle=Sec.String:S
Container=

[Description]
Meter=String
X=(28*#Sec.S#)
Y=(80*#Sec.S#)
FontSize=(12*#Sec.S#)
MeterStyle=Sec.String:S