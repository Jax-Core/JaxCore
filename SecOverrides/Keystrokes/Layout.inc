; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Export:M]
Measure=String
String=#Layout#
IfMatch=^WASD$
Ifmatchaction=[!SetOption WASD MeterStyle Selected:S][!UpdateMEasure WASD][!Redraw]
ifnotmatchaction=[!SetOption QWERTY MeterStyle Selected:S][!UpdateMEasure QWERTY][!Redraw]

[Select:S]
Fill=Fill Color 0,0,0,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,0,0,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,0,0,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyValue Variables Layout "#CURRENTSECTION#" "#Sec.SaveLocatioN#"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[Selected:S]
Fill=Fill Color 0,0,0,255

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[WASD]
Meter=Shape
Shape=Rectangle 0,0,(650),(378),#Set.R# | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend FIll
MEterStyle=Select:S
X=([Header:X])
Y=([Header:Y]+50*[Set.S])
DynamicVariables=1


[KeystrokesLayout]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=WASD
W=([WASD:W])
DynamicVariables=1

[KeystrokesLayoutOverlay]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=WASD
W=([WASD:W])
DynamicVariables=1

[Option01]
Meter=String
Container=WASD
X=([WASD:W]*0.65)
Y=([WASD:H]*0.15)
Text=Mouse Acceleration Display
StringAlign=centerCEnter
FontFace=Poppins Semibold
FontSize=(15*[Set.S])
MeterStyle=Set.String:S

[Option02]
Meter=String
Container=WASD
X=([WASD:W]*0.4)
Y=([WASD:H]*0.9)
Text=Mouse Buttons
StringAlign=centerCEnter
FontFace=Poppins Semibold
FontSize=(15*[Set.S])
MeterStyle=Set.String:S


[QWERTY]
Meter=Shape
Shape=Rectangle 0,0,(650),(200),#Set.R# | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend FIll
X=([Header:X])
Y=([WASD:YH]+20*[Set.S])
DynamicVariables=1
MEterStyle=Select:S

[KeystrokesLayout2]
Meter=Image
ImageName=#@#Images\#CURRENTSECTIOn#.png
Container=QWERTY
W=([QWERTY:W])
H=(200*[Set.S])
PreserveAspectRatio=2
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;


[Circ]
Meter=Shape
MeterStyle=Set.Bool:S
Container=WASD
X=([WASD:W]*0.65-[Option01:W]/2-60*[Set.S])
Y=([WASD:H]*0.15-10*[Set.S])

[Mouse]
Meter=Shape
MeterStyle=Set.Bool:S
Container=WASD
X=([WASD:W]*0.4-[Option02:W]/2-60*[Set.S])
Y=([WASD:H]*0.9-10*[Set.S])