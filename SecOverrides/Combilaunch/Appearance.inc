[Options]
Meter=String
Text=Options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Line tracing
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s0sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Confirmation color flash
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s1sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Action execution flash
MeterStyle=Set.String:S | Set.OptionName:S

[Color]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s12sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Line color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s13sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Dot color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s14sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Dot border color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s15sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Shadow color
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;


[MouseTraceBool]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])
[ConfirmBool]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])
[PulseBool]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])

[BackgroundColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])