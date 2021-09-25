[Option21]
Meter=String
Text=Primary color
MeterStyle=Set.String:S | Set.OptionName:S
[Option22]
Meter=String
Text=Secondary color
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
[2nd]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#2ndOpacity#
MeterStyle=Set.String:S | Set.Pacity:S