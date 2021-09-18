
[LoadActions]
ActionList1=Start0 | Wait 1500 | Start1 | Wait 1500 | Start2 | Wait 750 | NextPage

[Tween2:M]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1500
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 500
Tween2=Single | Variable | TweenNode3 | 0 | 1 | 750
Optional0=Easing InOutExpo
Optional2=Easing InOutExpo
UpdateDivider=1

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Polygon]
Meter=
[ContentContainer]
Meter=
[Title]
Meter=
[Logo]
Meter=

[Polygon2]
Meter=Shape
X=(#SCREENAREAWIDTH#/2)
Y=(#SCREENAREAHEIGHT#/2)
DynamicVariables=1
Group=Tweenable
Shape=Rectangle (-(#Sec.O#+100*#TweenNode3#)/2),(-(#Sec.O#-100*#TweenNode3#)/2),(#Sec.O#+100*#TweenNode3#),(#Sec.O#-100*#TweenNode3#),(#Set.R#*#TweenNode3#) | StrokeWidth (4*#TweenNode2#-4*#TweenNode3#) | Rotate (45*(1-#TweenNode3#)) | Scale (#TweenNode1#),(#TweenNode1#) | Fill Color #set.Pri_Color# | Stroke LinearGradient This
This=180 | 204,28,21 ; 0.0 | 255,112,15 ; 1.0

[Title2]
Meter=String
Text=JaxCore3
X=r
Y=r
FontSize=(80)
FontFace=Poppins SemiBold
StringAlign=CenterCenter
Group=Tweenable
InlineSetting=GradientColor | 180 | 204,28,21,(255*#TweenNode1#-255*#TweenNode3#) ; 0.0 | 255,112,15,(255*#TweenNode1#-255*#TweenNode3#) ; 1.0
MeterStyle=Set.String:S
TransformationMatrix=#TweenNode1#;0;0;#TweenNode1#;((1-#TweenNode1#)*([#CURRENTSECTION#:X]+[#CURRENTSECTION#:W]/2));((1-#TweenNode1#)*([#CURRENTSECTION#:Y]+[#CURRENTSECTION#:H]/2))
