[Variables]
Temp.Layout=QWERTY
Temp.Circ=1
Temp.Mouse=1

; ---------------------------------------------------------------------------- ;
;                                    Functions                                    ;
; ---------------------------------------------------------------------------- ;

[Export:M]
Measure=String
String=#Layout#
IfMatch=^WASD$
Ifmatchaction=[!SetOption WASD MeterStyle "Set.String:S | Select:S | Selected:S"][!UpdateMEter WASD][!Redraw]
ifnotmatchaction=[!SetOption QWERTY MeterStyle "Set.String:S | Select:S | Selected:S"][!UpdateMEter QWERTY][!Redraw]

[Export2:M]
Measure=String
String=#Temp.Layout# | #Layout#
OnUpdateAction=[!WriteKeyValue Variables "Temp.Layout" "#Layout#" "#ROOTCONFIGPATH#Secoverrides\Keystrokes\Layout.inc"]
IFMatch=^WASD \| QWERTY$
IfMatchAction=[!WriteKeyValue Variables "Temp.Circ" "#Circ#" "#ROOTCONFIGPATH#Secoverrides\Keystrokes\Layout.inc"][!WriteKeyValue Variables "Temp.Mouse" "#Mouse#" "#ROOTCONFIGPATH#Secoverrides\Keystrokes\Layout.inc"][!WriteKeyValue Variables "Temp.Circ" "#Circ#" "#ROOTCONFIGPATH#Secoverrides\Keystrokes\Layout.inc"][!WriteKeyValue Variables "Mouse" "0" "#Sec.SaveLocation#"][!WriteKeyValue Variables "Circ" "0" "#Sec.SaveLocation#"]
Ifmatch2=^QWERTY \| WASD$
IfMatchAction2=[!WriteKeyValue Variables "Mouse" "#Temp.Mouse#" "#Sec.SaveLocation#"][!WriteKeyValue Variables "Circ" "#Temp.Circ#" "#Sec.SaveLocation#"][!Refresh]



; ---------------------------------------------------------------------------- ;
;                                     Style                                    ;
; ---------------------------------------------------------------------------- ;

[Select:S]
Y=(10*[set.S])
FontFace=Poppins Light
FontSize=(15*[Set.S])
Container=Container
StringAlign=CenterTop
LeftMouseUpAction=[!WriteKeyValue Variables Layout "#CURRENTSECTION#" "#Sec.SaveLocation#"][!UpdateMeasure AUTo_REfresh:M][!Refresh]
[Selected:S]
FontFace=Poppins SemiBold

[KeyB:S] 
X=((50+#KeyPadding#)*[Set.S])r
Y=r
Shape=Rectangle (-50/2),(-50/2),50,50,(#Corner#*5),(#Corner#*5) | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S]
Fill=Fill Color #DefaultColor#,#DefaultOpacity#
DynamicVariables=1
Container=PreviewContainer
[Key2Style]
Shape=Rectangle (-(75)/2),(-50/2),(75),(50),(#Corner#*5),(#Corner#*5) | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S]
[Key3style]
Shape=Rectangle (-(50*3+#KeyPadding#*2)/2),(-50/4),(50*3+#KeyPadding#*2),(50/2),(#Corner#*5),(#Corner#*5) | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S]

[KeyFullboard:S]
X=((50+#KeyPadding#)*[Set.S])r
Y=r
Shape=Rectangle (-50/2),(-50/2),50,50,(#Corner#*5),(#Corner#*5) | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S]
Fill=Fill Color #DefaultColor#,#DefaultOpacity#
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure Script:M "Toggle('#CURRENTSECTION#')"]
Container=PreviewContainer

[Key:S]
X=r
Y=r
FontFace=#Font#
FontWeight=#Weight#
FontSize=(20*[Set.S])
Antialias=1
FontColor=#DefaultFontColor#
DynamicVariables=1
StringAlign=CenterCenter
Container=PreviewContainer
[KeyNo:S]
X=r
Y=r
FontFace=#Font#
FontWeight=#Weight#
FontSize=(20*[Set.S])
Antialias=1
FontColor=#DefaultFontColor#,150
DynamicVariables=1
StringAlign=CenterCenter
Container=PreviewContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Container]
Meter=Shape
Shape=Rectangle 0,0,([ContentContainer:W]),([ContentContainer:H]-[Header:Y]),#Set.R# | StrokeWidth 0
X=([Header:X])
Y=([Header:Y]+50*[Set.S])
DynamicVariables=1

[Background]
Meter=Shape
Shape=Rectangle 0,0,([ContentContainer:W]),([ContentContainer:H]-[Header:Y]),#Set.R# | StrokeWidth 0 | Fill LIneargradient This
This=45 | A1BCEC ; 0.0 | C8ACD4 ; 1.0
DynamicVariables=1
Container=Container

[WASD]
MEter=String
Text=Movement
X=([ContentContainer:W]*0.4)
MeterStyle=Set.String:S | Select:S

[PreviewContainer]
Meter=String
MeterStyle=#Layout#Container:S
[WASDContainer:S]
W=((310-(1-#Circ#)*100)*[Set.S])
H=(200*[Set.S])
X=([ContentContainer:X]+[ContentContainer:W]/2-((310-(1-#Circ#)*100)*[Set.S])/2+#Set.P#)
Y=([ContentContainer:Y]+[ContentContainer:H]/2-(200*[Set.S])/2+#Set.P#)
DynamicVariables=1
SolidColor=255,255,255
[QWERTYContainer:S]
W=(600*[Set.S])
H=(230*[Set.S])
X=([ContentContainer:X]+[ContentContainer:W]/2-(600*[Set.S])/2+#Set.P#)
Y=([ContentContainer:Y]+[ContentContainer:H]/2-(230*[Set.S])/2+#Set.P#)
DynamicVariables=1
SolidColor=255,255,255

[QWERTY]
MEter=String
Text=Fullboard
X=([ContentContainer:W]*0.6)
MeterStyle=Set.String:S | Select:S

; ---------------------------------------------------------------------------- ;
;                                    Preview                                   ;
; ---------------------------------------------------------------------------- ;

@includePreviews=#SKINSPATH##SKIN.NAME#\@Resources\Previews\#Layout#.inc
