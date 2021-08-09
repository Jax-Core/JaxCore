
[Options]
Meter=String
Text=Options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option00]
Meter=String
Text=Show media notification
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================


[Music]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option00:Y]-#Set.P#+(-20/2+8)*[Set.S])


