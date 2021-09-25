[Option21]
Meter=String
Text=Text color
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