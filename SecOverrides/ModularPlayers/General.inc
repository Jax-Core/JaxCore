
;================================================================================================================================================================================

[Behavior]
Meter=String
Text=Behavior
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Auto hide music player when not playing
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[AutoHide]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])
