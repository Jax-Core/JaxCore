[Variables]
@includeSecVar=#@#SecVar.inc

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Desktop]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!Zpos -2 "#Skin.Name#\Main"][!CommandMeasure mActions "Execute 1"]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Bottom]
Meter=String
LeftMouseUpAction=[!Zpos -1 "#Skin.Name#\Main"][!CommandMeasure mActions "Execute 1"]
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Standard window]
Meter=String
LeftMouseUpAction=[!Zpos 0 "#Skin.Name#\Main"][!CommandMeasure mActions "Execute 1"]
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Elevated]
Meter=String
LeftMouseUpAction=[!Zpos 1 "#Skin.Name#\Main"][!CommandMeasure mActions "Execute 1"]
MeterStyle=String:S
[Div:4]
Meter=Shape
MeterStyle=Div:S
[Always on top]
Meter=String
LeftMouseUpAction=[!Zpos 2 "#Skin.Name#\Main"][!CommandMeasure mActions "Execute 1"]
MeterStyle=String:S