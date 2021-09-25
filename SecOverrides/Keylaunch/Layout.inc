[Header]
Text=Animation layout
Y=(20*[Set.S]+#Scroll#)

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Export:M]
Measure=String
String=#AniStyle#
IfMatch=^Center$
Ifmatchaction=[!SetOption Center MeterStyle "Select:S | Selected:S"][!UpdateMeter Center][!Redraw]
IfMatch2=^Bottom$
Ifmatchaction2=[!SetOption Bottom MeterStyle "Select:S | Selected:S"][!UpdateMeter Bottom][!Redraw]
IfMatch3=^Slide$
Ifmatchaction3=[!SetOption Slide MeterStyle "Select:S | Selected:S"][!UpdateMeter Slide][!Redraw]
IfMatch4=^Spin$
Ifmatchaction4=[!SetOption Spin MeterStyle "Select:S | Selected:S"][!UpdateMeter Spin][!Redraw]
IfMatch5=^Expand$
Ifmatchaction5=[!SetOption Expand MeterStyle "Select:S | Selected:S"][!UpdateMeter Expand][!Redraw]
; OnUpdateAction=[!SetOption Center MeterStyle "Select:S | Selected:S"][!SetOption Bottom MeterStyle "Select:S | Selected:S"][!SetOption Slide MeterStyle "Select:S | Selected:S"][!SetOption Spin MeterStyle "Select:S | Selected:S"][!UpdateMEasure WASD][!Redraw]

[Select:S]
X=r
Y=(20*[Set.S])R
W=(650*[Set.S])
H=(150*[Set.S])
ImageName=#@#Images\KeylaunchLayout\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=100
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyValue Variables AniStyle "#CURRENTSECTION#" "#Sec.SaveLocatioN#"][!UpdateMeasure Auto_Refresh:M][!Refresh]
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


[Expand]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Center]
Meter=Image
MeterStyle=Select:S

[Bottom]
Meter=Image
MeterStyle=Select:S

[Slide]
Meter=Image
MeterStyle=Select:S

[Spin]
Meter=Image
MeterStyle=Select:S
