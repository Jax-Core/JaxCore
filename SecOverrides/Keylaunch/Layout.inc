[Header]
Text=Animation layout

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Export:M]
Measure=String
String=#AniStyle#
IfMatch=^Center$
Ifmatchaction=[!SetOption Center MeterStyle "Select:S | Selected:S"][!UpdateMEasure Center][!Redraw]
IfMatch2=^Bottom$
Ifmatchaction2=[!SetOption Bottom MeterStyle "Select:S | Selected:S"][!UpdateMEasure Bottom][!Redraw]
IfMatch3=^Slide$
Ifmatchaction3=[!SetOption Slide MeterStyle "Select:S | Selected:S"][!UpdateMEasure Slide][!Redraw]
IfMatch4=^Spin$
Ifmatchaction4=[!SetOption Spin MeterStyle "Select:S | Selected:S"][!UpdateMEasure Spin][!Redraw]
; OnUpdateAction=[!SetOption Center MeterStyle "Select:S | Selected:S"][!SetOption Bottom MeterStyle "Select:S | Selected:S"][!SetOption Slide MeterStyle "Select:S | Selected:S"][!SetOption Spin MeterStyle "Select:S | Selected:S"][!UpdateMEasure WASD][!Redraw]

[Select:S]
X=r
Y=10R
Fill=Fill Color 255,255,255,50
Shape=Rectangle 0,0,(650),(150),#Set.R# | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend FIll
X=([Header:X])
Y=([Header:Y]+50*[Set.S])
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyValue Variables AniStyle "#CURRENTSECTION#" "#Sec.SaveLocatioN#"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[Selected:S]
Fill=Fill Color 255,255,255,255
MouseOverAction=
MouseLeaveAction=
LeftMouseUpAction=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Center]
Meter=Shape
X=([Header:X])
Y=([Header:Y]+50*[Set.S])
MEterStyle=Select:S

[Bottom]
Meter=Shape
MEterStyle=Select:S

[Slide]
Meter=Shape
MEterStyle=Select:S

[Spin]
Meter=Shape
MEterStyle=Select:S

[KeylaunchLayout1]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=Center
W=([Center:W])
H=([Center:H])
PreserveAspectRatio=2
DynamicVariables=1

[KeylaunchLayout2]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=Bottom
W=([Bottom:W])
H=([Bottom:H])
PreserveAspectRatio=2
DynamicVariables=1

[KeylaunchLayout3]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=Slide
W=([Slide:W])
H=([Slide:H])
PreserveAspectRatio=2
DynamicVariables=1

[KeylaunchLayout4]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=Spin
W=([Spin:W])
H=([Spin:H])
PreserveAspectRatio=2
DynamicVariables=1
