[Variables]
SaveLocation="#@#Vars.inc"
; SaveKey=Fill

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Small]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!WriteKeyValue Variables Set.W 600 #SaveLocation#][!WriteKeyValue Variables Set.H 450 #SaveLocation#][!WriteKeyValue Set.S Formula 0.5 #SaveLocation#][!Refresh "#JaxCore\Main"][!DeactivateConfig]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Medium]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables Set.W 750 #SaveLocation#][!WriteKeyValue Variables Set.H 500 #SaveLocation#][!WriteKeyValue Set.S Formula 0.75 #SaveLocation#][!Refresh "#JaxCore\Main"][!DeactivateConfig]
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Big]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables Set.W 1000 #SaveLocation#][!WriteKeyValue Variables Set.H 800 #SaveLocation#][!WriteKeyValue Set.S Formula 1 #SaveLocation#][!Refresh "#JaxCore\Main"][!DeactivateConfig]
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Fullscreen]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables Set.W (#SCREENAREAWIDTH#) #SaveLocation#][!WriteKeyValue Variables Set.H (#SCREENAREAHEIGHT#) #SaveLocation#][!WriteKeyValue Set.S Formula (#SCREENAREAWIDTH#/1920) #SaveLocation#][!Refresh "#JaxCore\Main"][!Move 0 0 "#JaxCore\Main"][!DeactivateConfig]
MeterStyle=String:S