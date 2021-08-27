[DisableAutoRefresh:M]
Measure=Calc
OnUpdateAction=[!Delay 200][!DisableMeasure Auto_Refresh:M]

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
Text=Show application after animation
MeterStyle=Set.String:S | Set.OptionName:S

[AniTitle]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Highlight color
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
[ExecuteAt]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[MainC]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#MainCOpacity#
MeterStyle=Set.String:S | Set.Pacity:S