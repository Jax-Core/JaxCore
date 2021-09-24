
[LoadActions]
ActionList1=Start0 | Wait 2000 | Start1 | Wait 1000 | NextPage

[Tween:M]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1700
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 750
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[Set.string:S]
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[SpinImage]
MEter=Image
X=(#Sec.W#/2-256*#Sec.S#*#TweenNode1#/2+415.5*#Sec.S#*#TweenNode2#)
Y=(#Sec.H#/2-256*#Sec.S#*#TweenNode1#/2-109*#Sec.S#*#TweenNode2#)
W=((256*#TweenNode1#-206*#TweenNode2#)*#Sec.S#)
H=((256*#TweenNode1#-206*#TweenNode2#)*#Sec.S#)
DynamicVariables=1
Group=Tweenable
Container=ContentContainer
TransformationMatrix=(Cos(Rad(#TweenNode1#*360)));(-Sin(Rad(#TweenNode1#*360)));(Sin(Rad(#TweenNode1#*360)));(Cos(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode1#*360)))
ImageName=#@#Images\Logo256.png

[Logo]
Meter=