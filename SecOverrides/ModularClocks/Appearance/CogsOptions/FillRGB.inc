[Option41]
Meter=String
Text=Animation frame interval
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Button41]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!commandMeasure Func "startDrop('AniFrame', '#CURRENTSECTION#')"]
Y=([Option41:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value41]
Meter=String
Text=Configure
MeterStyle=Set.String:S | Set.Value:S