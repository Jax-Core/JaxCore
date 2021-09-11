[Variables]
BarHandler=11

; [ImageContainer]
; Meter=Shape
; X=(#Set.L#+#Set.P#)
; Y=#Set.P#
; Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill LinearGradient1 This
; This=180 | 0,0,0,0 ; 0.0 | 0,0,0,25; 0.45 | 0,0,0,25 ; 0.55 | 0,0,0,0 ; 1.0
; DynamicVariables=1
; [Image]
; Meter=Image
; X=((#Set.W#-#Set.L#-#Set.P#*2)/2-(256*[Set.S])/2)
; Y=((#Set.H#-#Set.P#*2)/2-(256/2*[Set.S]))
; W=(256*[Set.S])
; H=(256*[Set.S])
; Container=ImageContainer
; DynamicVariables=1
; ImageName=#@#Icons\Discord.png
; PreserveAspectRatio=1

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