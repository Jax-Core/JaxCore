
[LoadActions]
ActionList1=Start0 | Wait 100 | Start1 | Wait 1000 | Start2 | Wait 1000 | Start3 | Wait 600 | NextPage
Custom1=[!CommandMeasure CheckForDataFolder "Check-Data"]

[Tween:M]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1700
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 1700
Optional0=Easing InOutExpo
Optional1=Easing InOutExpo
UpdateDivider=1

[Set.string:S]
Container=ContentContainer

[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\CheckData.ps1


; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Polygon]
Modifier=Scale #TweenNode1#,#TweenNode1#
Shape2=Rectangle (#Sec.W#/2-(210+100*#TweenNode4#)/2*#Sec.S#),(#Sec.H#/2-(210+100*#TweenNode4#)/2*#Sec.S#),((210+100*#TweenNode4#)*#Sec.S#),((210+100*#TweenNode4#)*#Sec.S#) | Fill Color 0,0,0,0 | StrokeWidth 4 | Stroke Color #Set.Accent_Color#,(#TweenNode3#*255-255*#TweenNode4#) | Rotate 45
DynamicVariables=1
Group=Tweenable

[SpinLogo]
MEter=Image
X=(#Sec.W#/2-256*#Sec.S#*#TweenNode2#/2)
Y=(#Sec.H#/2-256*#Sec.S#*#TweenNode2#/2)
W=((256*#TweenNode2#)*#Sec.S#)
H=((256*#TweenNode2#)*#Sec.S#)
DynamicVariables=1
Group=Tweenable
ImageAlpha=(255-255*#TweenNode4#)
TransformationMatrix=(Cos(Rad(#TweenNode2#*360)));(-Sin(Rad(#TweenNode2#*360)));(Sin(Rad(#TweenNode2#*360)));(Cos(Rad(#TweenNode2#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode2#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode2#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode2#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode2#*360)))
ImageName=#@#Images\Logo256.png

[CheckForIdle]
Measure=Calc
Formula=CheckForIdle + 1
IfCondition=CheckForIdle >= 20
IfTrueAction=[!CommandMEasure CoreBridge "start('', 'An error had occured', [[Welcoming page failed to display properly.]], '', '5000')"][!WriteKeyValue Variables UserNameCheckVariable "[MeasureUser]" "#@#Vars.inc"][!WriteKeyValue Variables Sec.Page 1 "#ROOTCONFIGPATH#Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.ini"][!DeactivateConfig]
DynamicVariables=1
UpdateDivider=20
[CoreBridge]
Measure=Script
ScriptFile=#SKINSPATH##JaxCore\@Resources\Lua\CoreElements\Toast.lua
[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1