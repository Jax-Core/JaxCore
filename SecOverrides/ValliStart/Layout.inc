[Header]
Text=Color scheme
Y=(20*[Set.S]+#Scroll#)

[Option01]
Meter=String
X=r
Text=Choose a color scheme! These might also change different settings to improve the visuals.
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Script:M]
Measure=Script
ScriptFile=#@#Lua\ValliStart.lua

[Select:S]
X=r
Y=(20*[Set.S])R
W=(650*[Set.S])
H=(150*[Set.S])
ImageName=#@#Images\ValliStartLayout\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=200
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!CommandMeasure Script:M "ChangeTo('#CURRENTSECTION#')"] [!UpdateMeasure Auto_Refresh:M][!Refresh]
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Selected:S]
Fill=Fill Color 255,255,255,255
ImageAlpha=255
MouseOverAction=
MouseLeaveAction=
LeftMouseUpAction=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[Dark]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Blur]
Meter=Image
MeterStyle=Select:S

[CoreUI]
Meter=Image
MeterStyle=Select:S

[Dracula]
Meter=Image
MeterStyle=Select:S

[Amarena]
Meter=Image
MeterStyle=Select:S

[Lovelace]
Meter=Image
MeterStyle=Select:S

[Nord]
Meter=Image
MeterStyle=Select:S

[Light]
Meter=Image
MeterStyle=Select:S
