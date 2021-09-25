

[Div:Seqweqwzcxzxczzasde]
Meter=Shape
MeterStyle=SpecialDiv:S
[DivText:qwsa1231waezq]
Meter=String
Text=Positioning options
MeterStyle=Set.String:S | Set.SpecialCat:S

[Option101]
Meter=String
Text=Date's distance from clock
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[NextLineHeight]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option101:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value101]
Meter=String
Text=#NextLineHeight#
MeterStyle=Set.String:S | Set.Value:S