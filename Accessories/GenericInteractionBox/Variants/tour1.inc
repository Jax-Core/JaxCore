[Rainmeter]
OnRefreshAction=#Sec.DefaultStartActions#[!delay 1000][!CommandMEasure ActionTimer "Execute 2"]

[Variables]
Sec.W=(500*#Sec.S#)
Sec.H=(700*#Sec.S#)
Sec.R=(5*#Sec.S#)
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
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[ActionTimer]
Custom0=[!CommandMEasure fUnc "interactionBox('tour2')"][!Refresh]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[ImgFade]
Meter=Image
X=(#Sec.W#/2-[ImgFade:W]/2)
Y=(#Sec.H#/2-[ImgFade:W]/2)
W=(300*#Sec.S#)
H=([ImgFade:W])
DynamicVariables=1
ImageAlpha=50
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png
[Img]
Meter=Image
X=(#Sec.W#/2-[Img:W]/2)
Y=(#Sec.H#/2-[Img:W]/2)
W=(256*#Sec.S#)
H=([Img:W])
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png

[Esc]
Meter=