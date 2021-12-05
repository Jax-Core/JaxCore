; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[Variables]
Spin.Animation_Time=1700

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Spin.Animation_Time#
Optional0=Easing InOutExpo
UpdateDivider=1

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Start0 | Wait #Spin.Animation_Time# | Deactivate
; ActionList2=Rewind0
Start0=[!CommandMeasure mTween "Start(0)"]
Rewind0=[!CommandMeasure mTween "Rewind(0)"]
Deactivate=[!ShowMeter Logo "#JaxCore\Main"][!Redraw "#JaxCore\Main"][!Draggable 1 "#JaxCore\Main"][!DeactivateConfig]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Image]
MEter=Image
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png
X=0
Y=0
W=(#SEc.H#)
H=(#Sec.H#)
DynamicVariables=1
Group=Tweenable
TransformationMatrix=(Cos(Rad(#TweenNode1#*360)));(-Sin(Rad(#TweenNode1#*360)));(Sin(Rad(#TweenNode1#*360)));(Cos(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode1#*360)))
