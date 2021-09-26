
;================================================================================================================================================================================

[Time]
Meter=String
Text=Time
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Time format: 24(H) 12(I)
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[Weathers]
Meter=String
Text=Weather
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Weather location
MeterStyle=Set.String:S | Set.OptionName:S
[Divider19w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Unit (Metric/Imperial)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================




;================================================================================================================================================================================


[2412]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#2412#
MeterStyle=Set.String:S | Set.Value:S

[WeatherLocation]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[WeatherUnits]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#WeatherUnits#
MeterStyle=Set.String:S | Set.Value:S