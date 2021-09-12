[Variables]
SaveLocation="#SKINSPATH#ModularCLocks\@Resources\Vars.inc"
SaveKey=AnimationUpdateRate

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[60 fps]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!WriteKeyValue Variables "#SaveKey#" "0" "#SaveLocatioN#"][!Refresh "#JaxCore\Main"][!Refresh "ModularClocks\Main"][!DeactivateConfig]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Standard]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables "#SaveKey#" "20" "#SaveLocatioN#"][!Refresh "#JaxCore\Main"][!Refresh "ModularClocks\Main"][!DeactivateConfig]
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Resource efficient]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables "#SaveKey#" "40" "#SaveLocatioN#"][!Refresh "#JaxCore\Main"][!Refresh "ModularClocks\Main"][!DeactivateConfig]
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Low]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables "#SaveKey#" "100" "#SaveLocatioN#"][!Refresh "#JaxCore\Main"][!Refresh "ModularClocks\Main"][!DeactivateConfig]
MeterStyle=String:S