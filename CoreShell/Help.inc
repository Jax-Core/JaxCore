[Variables]
BarHandler=11

[ContentContainer]
X=(#Set.L#)
Y=0
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#),(#Set.H#),(#Set.R#),(#Set.R#) | StrokeWidth 0 | Fill LinearGradient This
This=180 | 255,255,255,0 ; 0.0 | 255,255,255 ; 0.2
[Image]
Meter=Image
X=0
W=[ContentContainer:W]
H=[ContentContainer:H]
Container=ContentContainer
DynamicVariables=1
ImageName=#@#Images\TourPreview.png
ImageAlpha=50
PreserveAspectRatio=2

[Header]
Meter=String
X=([ContentContainer:W]/2)
Y=([ContentContainer:H]/2-5/2)
DynamicVariables=1
StringAlign=CenterCenter
Text=Need help?
FontFace=#Set.Font# Medium
FontSize=(30*[Set.S])
MeterStyle=Set.String:S
Container=ContentContainer
[Subheader]
Meter=String
X=r
Y=(-10*[Set.S])R
DynamicVariables=1
StringAlign=CenterCenter
Text=Join the Discord server!
FontFace=#Set.Font#
FontSize=(12*[Set.S])
MeterStyle=Set.String:S
Container=ContentContainer

[Obj.6]
Meter=Shape
X=(-200/2*[Set.S])r
Y=(20*[Set.S])R
DynamicVariables=1
Shape=Rectangle 0,0,200,45,(#Set.R#) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend THis
OverColor=106, 119, 252
LeaveColor=88,101,242
Leftmouseupaction=["https://discord.gg/JmgehPSDD6"]
MeterStyle=Shape.Over:S
Container=ContentContainer
[Obj.6.Child]
Meter=String
X=(200/2*[Set.S])r
y=(45/2*[Set.S])r
FontSize=(15*[Set.S])
FontFace=#Set.Font# 
StringAlign=CenterCenter
Text="Let's go!"
Container=ContentContainer
MeterStyle=SEt.String:S | ButtonT:S