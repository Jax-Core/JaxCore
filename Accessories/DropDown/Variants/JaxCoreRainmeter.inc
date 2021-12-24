[Variables]
; SaveKey=Fill

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Manage panel]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!Manage][!DeactivateConfig]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Settings panel]
Meter=String
LeftMouseUpAction=[!Manage Settings][!DeactivateConfig]
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Logs]
Meter=String
LeftMouseUpAction=[!About Logs][!DeactivateConfig]
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Skin data]
Meter=String
LeftMouseUpAction=[!About Skins][!DeactivateConfig]
MeterStyle=String:S
[Div:4]
Meter=Shape
MeterStyle=Div:S
[Plugin list]
Meter=String
LeftMouseUpAction=[!About Plugins][!DeactivateConfig]
MeterStyle=String:S