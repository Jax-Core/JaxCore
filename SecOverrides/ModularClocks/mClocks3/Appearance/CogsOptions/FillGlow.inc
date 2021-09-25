[Option21]
Meter=String
Text=Text color
MeterStyle=Set.String:S | Set.OptionName:S
[Option22]
Meter=String
Text=Glow color
MeterStyle=Set.String:S | Set.OptionName:S
[Option23]
Meter=String
Text=Glow Sigma
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[1st]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=#1stOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[3rd]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#3rdOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[GlowSigma]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value23]
Meter=String
Text=#GlowSigma#
MeterStyle=Set.String:S | Set.Value:S