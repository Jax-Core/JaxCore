[Variables]
BarHandler=11


[Header]
Meter=String
X=([ContentContainer:W]/2)
Y=([ContentContainer:H]/2-5/2)
DynamicVariables=1
StringAlign=CenterCenter
Text=Need help?
FontFace=Poppins Medium
FontSize=(30*[Set.S])
MeterStyle=Set.String:S
Container=ContentContainer

[Obj.6]
Meter=Shape
X=(-200/2*[Set.S])r
Y=R
DynamicVariables=1
Shape=Rectangle 0,0,200,50,(#Set.R#) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend THis
OverColor=88,101,242
LeaveColor=88,101,242,200
Leftmouseupaction=["https://discord.gg/JmgehPSDD6"]
MeterStyle=Shape.Over:S
Container=ContentContainer
[Obj.6.Child]
Meter=String
X=(200/2*[Set.S])r
y=(25*[Set.S])r
FontSize=(11*[Set.S])
FontFace=Poppins 
StringAlign=CenterCenter
Text="Join the discord server!"
Container=ContentContainer
MeterStyle=SEt.String:S | ButtonT:S