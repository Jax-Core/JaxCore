[Variables]
BarHandler=12

[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S]+#Scroll#)
DynamicVariables=1
Text=Frequently Asked Questions /Shade
FontSize=(20*[Set.S])
FontWeight=450
Leftmouseupaction=[!Refresh]
InlinePattern=(/.*)
InlineSetting=Size | 10
InlinePattern2=(/.*)
InlineSetting2=Color | 150,150,150
MeterStyle=Set.String:S

[Sec.Q:S]
X=(30*[Set.S])
Y=(30*[Set.S])R
FontSize=(14*[Set.S])
FontWeight=500
Container=ContentContainer
[Sec.A:S]
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Clipstring=2
W=(#Set.W#-#Set.L#-#Set.P#-30*2*[Set.S])
;================================================================================================================================================================================
