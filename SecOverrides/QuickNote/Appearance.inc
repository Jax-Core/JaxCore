[HotkeysTitle]
Meter=String
Text=General
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=Font face
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Time]
Meter=String
Text=Animations
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Animation
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Ss]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Animation duration
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[Anim]
Meter=String
Text=Colors and filling
MeterStyle=Set.String:S | Set.OptionCat:S

[Option20]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1381]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text=Secondary color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1382]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Divider color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1383]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Font color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1384]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Accent color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1385]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text=Check circle colors
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[FontFace]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#FontFace#
MeterStyle=Set.String:S | Set.Value:S

[Animation]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])

[TweenTime1]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#TweenTime1#
MeterStyle=Set.String:S | Set.Value:S


[Maincolor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option20:Y]-#Set.P#+(-30/2+8)*[Set.S])
[SecColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[StrokeColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[AccentColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])
[BoolColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])