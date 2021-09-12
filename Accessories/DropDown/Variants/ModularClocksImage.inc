[Variables]
SaveLocation="#SKINSPATH#ModularCLocks\@Resources\Vars.inc"
SaveKey=Fill

[String:S]
Text=#CURRENTSECTION# Fill
LeftMouseUpAction=[!WriteKeyValue Variables "#SaveKey#" "#CURRENTSECTION#" "#SaveLocatioN#"][!Refresh "#JaxCore\Main"][!Refresh "ModularClocks\Main"][!DeactivateConfig]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Solid]
Meter=String
Y=(#Sec.P#)
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Gradient]
Meter=String
InlineSetting=GradientColor | 45 | CC1C15 ; 0.0 | FF700F ; 1.0
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Glow]
Meter=String
InlineSetting=Shadow | 0 | 0 | 2 | 255,255,255,255
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Accent]
Meter=String
InlinePattern=Fill
InlineSetting=Color | CC1C15
InlinePattern2=#CURRENTSECTION#
InlineSetting2=Color | FFE636
MeterStyle=String:S
[Div:4]
Meter=Shape
MeterStyle=Div:S
[Chameleon]
Meter=String
FontColor=255,255,255,150
MeterStyle=String:S
[Div:5]
Meter=Shape
MeterStyle=Div:S
[Blur]
Meter=String
InlineSetting=GradientColor | 45 | 677578 ; 0.0 | 93928D ; 1.0
MeterStyle=String:S
[Div:6]
Meter=Shape
MeterStyle=Div:S
[Bar]
Meter=String
MeterStyle=String:S

[EndAnchor]
Meter=String
MeterStyle=String:S