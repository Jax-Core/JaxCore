[Variables]
TweenNode2=1

[LoadActions]
ActionList1=Start0 | Wait 1000 | start2 | Wait 2000 | Rewind1 | Rewind0 | Rewind2 | Wait 2000 | Custom1
Custom1=[!WriteKeyValue Variables UserNameCheckVariable "[MeasureUser]" "#@#Vars.inc"][!WriteKeyValue Variables Sec.Page 1 "#ROOTCONFIGPATH#Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.ini"][!DeactivateConfig]
DynamicVariables=1

[Tween:M]
Tween2=Single | Variable | TweenNode3 | 0 | 1 | 1700
Optional2=Easing InOutExpo
UpdateDivider=1

[Support:S]
Y=(10*#Sec.S#)R
Container=GlobalContainer
DynamicVariables=1
Group=Tweenable
[SupportImage:S]
X=((300/2-100/2)*#Sec.S#)r
Y=((300/2-100/2)*#Sec.S#)r
W=(100*#Sec.S#)
H=(100*#Sec.S#)
DynamicVariables=1
Container=GlobalContainer
[SupportText:S]
FontSize=(10*#Sec.S#)
Angle=(Rad(-90))
Inlinepattern=#CRLF#.*
InlineSetting=Weight | 650
Inlinepattern2=#CRLF#.*
InlineSetting2=Size | 20
Inlinepattern3=#CRLF#.*
StringAlign=Left
FontColor=#Set.Subtext_Color#
Container=GlobalContainer
DynamicVariables=1
Group=Tweenable

[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Modifiers]
@includeModifiers=#ROOTCONFIGPATH#Accessories\Tour\Modifier.inc

[Polygon]
Modifier=Scale #TweenNode2#,#TweenNode2#
DynamicVariables=1
Group=Tweenable

[SpinLogo]
MEter=Image
X=(#Sec.W#/2-512*#Sec.S#*#TweenNode3#/2)
Y=(#Sec.H#/2-512*#Sec.S#*#TweenNode3#/2)
W=((512*#TweenNode3#)*#Sec.S#)
H=((512*#TweenNode3#)*#Sec.S#)
DynamicVariables=1
Group=Tweenable
Container=GlobalContainer
ImageAlpha=(50*#TweenNode3#)
TransformationMatrix=(Cos(Rad(#TweenNode3#*360)));(-Sin(Rad(#TweenNode3#*360)));(Sin(Rad(#TweenNode3#*360)));(Cos(Rad(#TweenNode3#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode3#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode3#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode3#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode3#*360)))
ImageName=#@#Images\LogoBig.png

[Title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=You're all set
X=(#Sec.W#/2)
Y=(#Sec.H#/2-([Title.Text1:H]+[Des.Text:H])/2)
FontSize=(36*#Sec.S#)
FontFace=Poppins SemiBold
Container=GlobalContainer
StringAlign=Center
DynamicVariables=1
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
InlineSetting2=Shadow | 0 | 0 | 5 | 0,0,0,100

[Des.Text]
Meter=String
MeterStyle=Set.String:S
Text=Thank you for installing JaxCore!
X=r
StringAlign=Center
Y=(70*#Sec.S#)r
FontSize=(12*#Sec.S#)
Container=GlobalContainer

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;
