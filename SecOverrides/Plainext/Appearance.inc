
[Padding]
Meter=String
Text=Look and feel
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Skin padding
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192038sdsdsdsdss]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Skin scaling
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192038sdsdss]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Skin font
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1920dsdsds38sss]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Font weight
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192038sss]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Font alias
MeterStyle=Set.String:S | Set.OptionName:S
[Divider198sss]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Compact look (hides details)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Colors]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionCat:S

[Option10]
Meter=String
Text=Accent Color
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192038sdsds]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Font Color
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192038]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Progress Bar Color
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[In]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#In#
MeterStyle=Set.String:S | Set.Value:S
[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S
[Font]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#Font#
MeterStyle=Set.String:S | Set.Value:S
[FontWeight]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#FontWeight#
MeterStyle=Set.String:S | Set.Value:S
[FontAlias]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option05:Y]-#Set.P#+(-20/2+8)*[Set.S])
[CompactLook]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option06:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Accent]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[BarColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])

