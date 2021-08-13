
[Div]
meter=Shape
X=(25*[Set.S])
Y=([WMPShape:YH]-[ContentContainer:Y]+#set.P#/2)
DynamicVariables=1
MeterStyle=Set.Div:S

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


