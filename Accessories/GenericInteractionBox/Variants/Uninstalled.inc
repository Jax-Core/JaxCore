[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=(90*#Sec.S#)
AniDir=Bottom
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

; [HeaderImage]
; Meter=Image
; ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo.png
; X=(#Sec.W#/2-(30*#Sec.S#)/2)
; Y=(#Sec.P#/2)
; W=(30*#Sec.S#)
; H=(30*#Sec.S#)
; ImageAlpha=25

[HeaderString]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
StringAlign=Center
Text=Task complete.
MeterStyle=Sec.String:S
FontSize=(14*#sec.s#)
FontWeight=650
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 2.0

[Description]
Meter=String
X=r
Y=R
StringAlign=Center
Text=Uninstalled #Sec.Arg1# successfully.
MeterStyle=Sec.String:S
FontSize=(10*#sec.s#)

[Esc]
LeftMouseUpAction=[!CommandMeasure Func "corepage('#Sec.Arg1#', 1)"]