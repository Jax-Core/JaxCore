[HotkeysTitle]
Meter=String
Text=General
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Scaling factor
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Corner rounding factor
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913138]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Key font face
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191318]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Key font weight
MeterStyle=Set.String:S | Set.OptionName:S

[Mouse]
Meter=String
Text=RGB chroma
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Use RGB as text color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19138]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=RGB color override pressed key color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191sdsd38]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Chroma speed
MeterStyle=Set.String:S | Set.OptionName:S

[Colors]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionCat:S

[Option21]
Meter=String
Text=Background
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:238]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Key
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1911232133138]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Key label
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913zsdasd18]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Pressed key
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913zsdasd1s8]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text=Pressed key label
MeterStyle=Set.String:S | Set.OptionName:S

[Mouse]
Meter=String
Text=RGB chroma
MeterStyle=Set.String:S |  Set.OptionCat:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S
[Corner]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Corner#
MeterStyle=Set.String:S | Set.Value:S
[Font]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#Font#
MeterStyle=Set.String:S | Set.Value:S
[Weight]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#Weight#
MeterStyle=Set.String:S | Set.Value:S

[RGB]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
[RGBOverride]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])
[RGBSpeed]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#RGBSpeed#
MeterStyle=Set.String:S | Set.Value:S


[BackgroundColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[DefaultColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[DefaultFontCOlor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[PressedColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])
[PressedFontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])


@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini