[Option31]
Meter=String
Text=Clock font size
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[FontSize]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option31:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value31]
Meter=String
Text=#FontSize#
MeterStyle=Set.String:S | Set.Value:S