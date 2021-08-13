
; ---------------------------------------------------------------------------- ;
;                                    Options                                   ;
; ---------------------------------------------------------------------------- ;
[Visibility]
Meter=String
Text=#CURRENTSECTION#
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Blur background using pre-processing
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Background
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191asdad31238]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Gradient filled background
MeterStyle=Set.String:S | Set.OptionName:S

[Colors]
Meter=String
Text=#CURRENTSECTION#
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1238]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Left gradient
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12s38]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Right gradient
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12d38]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Left circle gradient
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:123qwd8]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Center circle gradient
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:123zcx8]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Right circle gradient
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:123z8]
Meter=Shape
MeterStyle=Set.Div:S
[Option17]
Meter=String
Text=Bottom gradient
MeterStyle=Set.String:S | Set.OptionName:S
; ---------------------------------------------------------------------------- ;
;                                 Interactions                                 ;
; ---------------------------------------------------------------------------- ;


[BlurBackground]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Background]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Gradient]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])


[MainColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[LeftGrad:]
Meter=Shape
Grad0=LeftGrad.0
Grad1=LeftGrad.1
MeterStyle=Set.Grad0:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[LeftGrad:1]
Meter=Shape
MeterStyle=Set.Grad1:S
[RightGrad:]
Meter=Shape
Grad0=RightGrad.0
Grad1=RightGrad.1
MeterStyle=Set.Grad0:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[RightGrad:1]
Meter=Shape
MeterStyle=Set.Grad1:S
[OneGrad:]
Meter=Shape
Grad0=OneGrad.0
Grad1=OneGrad.1
MeterStyle=Set.Grad0:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[OneGrad:1]
Meter=Shape
MeterStyle=Set.Grad1:S
[TwoGrad:]
Meter=Shape
Grad0=TwoGrad.0
Grad1=TwoGrad.1
MeterStyle=Set.Grad0:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
[TwoGrad:1]
Meter=Shape
MeterStyle=Set.Grad1:S
[ThreeGrad:]
Meter=Shape
Grad0=ThreeGrad.0
Grad1=ThreeGrad.1
MeterStyle=Set.Grad0:S
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[ThreeGrad:1]
Meter=Shape
MeterStyle=Set.Grad1:S
[LastGrad:]
Meter=Shape
Grad0=LastGrad.0
Grad1=LastGrad.1
MeterStyle=Set.Grad0:S
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])
[LastGrad:1]
Meter=Shape
MeterStyle=Set.Grad1:S