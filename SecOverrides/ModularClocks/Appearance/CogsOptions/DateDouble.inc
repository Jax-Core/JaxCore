[Option31]
Meter=String
Text=Clock font size
MeterStyle=Set.String:S | Set.OptionName:S
[Option32]
Meter=String
Text=Date font size
MeterStyle=Set.String:S | Set.OptionName:S
[Option33]
Meter=String
Text=String font size
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
[FontSize3]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option32:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value32]
Meter=String
Text=#FontSize3#
MeterStyle=Set.String:S | Set.Value:S
[FontSize4]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option33:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value33]
Meter=String
Text=#FontSize4#
MeterStyle=Set.String:S | Set.Value:S