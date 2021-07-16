[Variables]
BarHandler=3

[darkLight.Func]
Measure=Script
ScriptFile=#@#Lua\DarkLight.lua


[Header]
Meter=String
X=(20*#Set.S#)
Y=(20*#Set.S#+#Scroll#)
DynamicVariables=1
Text=Appearance /#Skin.Shorthand#
FontSize=(20*#Set.S#)
FontWeight=450
MeterStyle=Set.String:S
Container=ContentContainer
Leftmouseupaction=[!Refresh]
InlinePattern=\s(.*)
InlineSetting=Size | 10
InlinePattern2=\s(.*)
InlineSetting2=Color | 150,150,150
Group=Shorthand
;================================================================================================================================================================================

[Color]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Color
MeterStyle=Set.String:S
Container=ContentContainer

[Option01]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Colors
MeterStyle=Set.String:S
Container=ContentContainer


;================================================================================================================================================================================

[ColorMode:]
Meter=Shape
SecVar=ColorMode
0Act=[!CommandMeasure darkLight.Func "SwitchColor(0)"]
1Act=[!CommandMeasure darkLight.Func "SwitchColor(1)"]
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-35/2+8)*#Set.S#)
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
