
;================================================================================================================================================================================

[Color]
Meter=String
Text=Color
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[ColorMode:]
Meter=Shape
SecVar=ColorMode
0Act=[!CommandMeasure darkLight.Func "SwitchColor(0)"]
1Act=[!CommandMeasure darkLight.Func "SwitchColor(1)"]
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-35/2+8)*[Set.S])
[ColorMode:0]
Meter=String
Text=Dark
FontColor=(#ColorMode# = 0 ? 0 : 255),(#ColorMode# = 0 ? 0 : 255),(#ColorMode# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
[ColorMode:1]
Meter=String
Text=Light
FontColor=(#ColorMode# = 1 ? 0 : 255),(#ColorMode# = 1 ? 0 : 255),(#ColorMode# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_1:S
; ;================================================================================================================================================================================

[Padding]
Meter=String
X=(30*[Set.S])
Y=(10*[Set.S])R
FontSize=(14*[Set.S])
FontWeight=500
Text=Padding
MeterStyle=Set.String:S
Container=ContentContainer

[Option02]
Meter=String
Text=Screen side padding (in pixels)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[ScaleNsize]
Meter=String
Text=Scale and size
MeterStyle=Set.String:S | Set.OptionCat:S

[Option10]
Meter=String
Text=Global size
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S192038sdsds]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Corner size
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S192038]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Object spacing
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Anim]
Meter=String
Text=Animations
MeterStyle=Set.String:S | Set.OptionCat:S

[Option20]
Meter=String
Text=Animations (Turn off for better performance on low-end devices)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[P]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#P#
MeterStyle=Set.String:S | Set.Value:S

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value10]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[R]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#R#
MeterStyle=Set.String:S | Set.Value:S

[GlobalP]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#GlobalP#
MeterStyle=Set.String:S | Set.Value:S

[Animation]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option20:Y]-#Set.P#+(-20/2+8)*[Set.S])