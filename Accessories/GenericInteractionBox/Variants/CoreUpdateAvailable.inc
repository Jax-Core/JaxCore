[Variables]
Sec.W=(310*#Sec.S#)
Sec.H=(70*#Sec.S#)
Sec.R=(5*#Sec.S#)
AniDir=Left
[moveX]
Formula=20
[moveY]
Formula=20
[anchorX]
Formula=0
[anchorY]
Formula=0

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[ActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#JaxCore\Main

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[B]
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.name "#JaxCore" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page "General" "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!CommandMeasure ActionTimer "Execute 2"]

[Img]
Meter=Image
X=(10*#sec.s#)r
Y=(10*#sec.s#)r
W=(50*#Sec.S#)
H=(50*#Sec.S#)
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo.png

[Text]
Meter=String
Text=Core update available#CRLF#Click here to update to #sec.arg1#
X=(5*#Sec.s#)R
Y=(25*#Sec.s#)r
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | 8
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
StringAlign=LeftCenter
MeterStyle=Sec.String:S
DynamicVariables=1