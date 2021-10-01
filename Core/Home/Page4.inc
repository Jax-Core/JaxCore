[BC]
MouseScrollDownAction=
MouseScrollUpAction=

[BarClip]
Meter=

[Image]
Meter=Image
W=(#Set.W#)
H=(#Set.H#*0.6)
ImageAlpha=100
PreserveAspectRatio=2
DynamicVariables=1
ImageName=#@#Images\SuitesPreview.png
MaskImageName=#@#Images\FadeMask.png
Container=BC

[Title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=CoreSuites
X=(#Set.W#/2)
Y=(#Set.H#*0.3)
Group=Scroll
FontSize=(40*[Set.S])
FontFace=Poppins SemiBold
StringAlign=Center
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
InlineSetting2=Shadow | 0 | 0 | 5 | FF700F40

[Text.1]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(78*[Set.S])r
StringAlign=Center
Text=Stylize your desktop with a single click.#CRLF##CRLF#Scheduled to be released after CoreEnv.

[Text.2]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(300*[Set.S])r
StringAlign=Center
Text=Join the discord for development updates

[DiscordBotton]
Meter=Shape
X=(#Set.W#/2-150*[set.S]/2)
Y=(30*[Set.S])r
MeterStyle=Shape.Over:S | Button:S
OverColor=#Set.Accent_Color#
LeaveColor=#Set.Accent_Color#
Leftmouseupaction=["https://discord.gg/JmgehPSDD6"]
[DiscordText]
Meter=String
Text=Let's go
MeterStyle=Set.String:S | ButtonText:S