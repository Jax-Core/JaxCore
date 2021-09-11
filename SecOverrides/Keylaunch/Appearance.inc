[HotkeysTitle]
Meter=String
Text=General
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Text glow sigma
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Text font
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Sasdasd1913s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Show application after animation
MeterStyle=Set.String:S | Set.OptionName:S

[CoTitle]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Highlight color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Sas]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Font color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Sus]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Glow color
MeterStyle=Set.String:S | Set.OptionName:S

[AniTitle]
Meter=String
Text=Animation configuration
MeterStyle=Set.String:S | Set.OptionCat:S
[Option21]
Meter=String
Text=Start animations
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1913sadsas138]
Meter=Shape
MeterStyle=Set.Div:S
[Option26]
Meter=String
Text=Animation display monitor index
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:dsas138]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Animation frame interval (0 for true 60fps)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191qweq3s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Text size modifier
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191qweq]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Animation start duration
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text=Animation end duration
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Blur]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Blur#
MeterStyle=Set.String:S | Set.Value:S
[GlobalFont]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#GlobalFont#
MeterStyle=Set.String:S | Set.Value:S
[ExecuteAt]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])

[MainC]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#MainCOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Glow]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#GlowOpacity#
MeterStyle=Set.String:S | Set.Pacity:S


[ShowAni]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])
[LaunchAt]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option26:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value26]
Meter=String
Text=#LaunchAt#
MeterStyle=Set.String:S | Set.Value:S
[UpdateRate]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#UpdateRate#
MeterStyle=Set.String:S | Set.Value:S
[FontSizeModifier]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value23]
Meter=String
Text=#FontSizeModifier#
MeterStyle=Set.String:S | Set.Value:S
[LongDelay]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value24]
Meter=String
Text=#LongDelay#
MeterStyle=Set.String:S | Set.Value:S
[ShortDelay]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value25]
Meter=String
Text=#ShortDelay#
MeterStyle=Set.String:S | Set.Value:S