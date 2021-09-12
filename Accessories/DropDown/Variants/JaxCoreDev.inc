[Variables]
SaveLocation="#@#Includes\Window.ini"
Sec.W=(256*#Sec.S#)
; SaveKey=Fill

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Generate Home Screen]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!ActivateConfig "#JaxCore\Accessories\Gen\Home"][!DeactivateConfig]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Show Welcome Screen]
Meter=String
LeftMouseUpAction=[!WriteKeyValue Variables Sec.Page 1 "#SKINSPATH#\#JaxCore\Accessories\Tour\Main.ini"][!ActivateConfig "#JaxCore\Accessories\Tour"]
MeterStyle=String:S