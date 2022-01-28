[Rainmeter]
Update=1000

[Variables]
Sec.W=(400*#Sec.S#)
Sec.H=(400*#Sec.S#)
Sec.R=(5*#Sec.S#)
AniDir=Left

Act1=[!WriteKeyvalue ActionTimer Custom1 #*Act2*# "#ROOTCONFIGPATH#Accessories\GenericInteractionBox\Variants\UpdatePrompt.inc"]
Act2=[!WriteKeyvalue ActionTimer Custom1 #*Act1*# "#ROOTCONFIGPATH#Accessories\GenericInteractionBox\Variants\UpdatePrompt.inc"][!DeactivateConfig]
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[ActionTimer]
Custom1=#Act1#
Custom0=#Act2#
[SkinName]
Measure=String
String=#Sec.Arg1#
RegexpSubstitute=1
Substitute="[.|\d]":""
[SkinVer]
Measure=String
String=#Sec.Arg1#
RegexpSubstitute=1
Substitute="^[A-Za-z]":""
[Timer]
Measure=Loop
StartValue=10
EndValue=0
Increment=-1
IfCondition=Timer <= 0
IfTrueAction=["https://github.com/Jax-Core/[SkinName]/releases/download/v[SkinVer]/[SkinName]_v[SkinVer].rmskin"][!Refresh]
UpdateDivider=1
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Img]
Meter=Image
X=(#Sec.W#/2-[Img:W]/2)
Y=(#Sec.W#/2-[Img:H]/2)
W=(200*#Sec.S#)
H=([Img:W])
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo.png

[Text]
Meter=String
Text=Downloading & installing #sec.arg1##CRLF#Redirecting to manual download in [Timer:]s
X=(#Sec.W#/2)
Y=(30*#Sec.s#)R
FontSize=(12*#Sec.S#)
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | 10
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
StringAlign=CenterCenter
MeterStyle=Sec.String:S
DynamicVariables=1
UpdateDivider=1
