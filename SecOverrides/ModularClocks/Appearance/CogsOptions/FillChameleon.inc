[Option21]
Meter=String
Text=Chameleon refresh rate
MeterStyle=Set.String:S | Set.OptionName:S
[Option22]
Meter=String
Text=Chameleon sampling source
MeterStyle=Set.String:S | Set.OptionName:S
[Option23]
Meter=String
Text=Use chameleon colors as gradient
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[ChameleonSampleRate]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=#ChameleonSampleRate#
MeterStyle=Set.String:S | Set.Value:S

[ChameleonSource:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('ChameleonSource', 'Background')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables ChameleonSource "Foreground" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables ChameleonSource "Background" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[ChameleonSource:0]
Meter=String
Text=Foreground
FontColor=([&Func:returnBool('ChameleonSource', 'Background')] = 0 ? 0 : 255),([&Func:returnBool('ChameleonSource', 'Background')] = 0 ? 0 : 255),([&Func:returnBool('ChameleonSource', 'Background')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[ChameleonSource:1]
Meter=String
Text=Background
FontColor=([&Func:returnBool('ChameleonSource', 'Background')] = 1 ? 0 : 255),([&Func:returnBool('ChameleonSource', 'Background')] = 1 ? 0 : 255),([&Func:returnBool('ChameleonSource', 'Background')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[ChameleonGraident]
Meter=Shape
MeterStyle=Set.bool:S
Y=([Option23:Y]-#Set.P#+(-20/2+8)*[Set.S])