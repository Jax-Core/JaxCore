[Variables]
BarHandler=2

[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S]+#Scroll#)
DynamicVariables=1
Text=General 
FontSize=(25*[Set.S])
FontWeight=600
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
MeterStyle=Set.String:S
Container=ContentContainer

