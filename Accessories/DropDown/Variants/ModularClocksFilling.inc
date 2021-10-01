[Variables]
SaveLocation="#SKINSPATH#ModularCLocks\@Resources\Data\#arg1#Data.inc"
SaveKey=Fill
RGBSpeed=1

[RGBMeasure]
Measure=Script
ScriptFile=#@#Lua\RGB.lua
UpdateDivider=1

[String:S]
Text=#CURRENTSECTION# Fill
LeftMouseUpAction=[!WriteKeyValue Variables "#arg1##SaveKey#" "#CURRENTSECTION#" "#SaveLocatioN#"][!Refresh "#JaxCore\Accessories\Box"][!Refresh "#JaxCore\Main"][!Delay 100][!CommandMeasure "Script:M" "generateBlur()" "#JaxCore\Main"][!DeactivateConfig]

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
; [Div:3]
; Meter=Shape
; MeterStyle=Div:S
; [Accent]
; Meter=String
; FontColor=FFE636
; MeterStyle=String:S
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
[RGB]
Meter=String
FontColor=[RGBMeasure]
UpdateDivider=1
DynamicVariables=1
MeterStyle=String:S