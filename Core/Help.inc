[Variables]
BarHandler=11


[Header]
Meter=String
X=([ContentContainer:W]/2)
Y=([ContentContainer:H]/2-[GitHub:W]/2-5/2)
DynamicVariables=1
StringAlign=CenterCenter
Text=Need help?
FontFace=Poppins Medium
FontSize=(30*[Set.S])
MeterStyle=Set.String:S
Container=ContentContainer
[Subheader]
Meter=String
X=r
Y=R
StringAlign=CenterCenter
Text=Visit the github / DM me Jax#7000 on discord:
FontColor=150,150,150
FontSize=(12*[Set.S])
FontFace=Poppins Light
; InlinePattern=Jax\s-\s(.*)
; InlineSetting=Color | #TC#,150
MeterStyle=Set.String:S
Container=ContentContainer
[GitHub]
Meter=Image
Y=(5*[Set.S])R
X=([ContentContainer:W]/2-(64*[Set.S])-5)
W=(64*[Set.S])
H=(64*[Set.S])
DynamicVariables=1
Container=ContentContainer
ImageName=#@#Icons\#CURRENTSECTION#.png
Leftmouseupaction=["https://github.com/EnhancedJax/#Skin.Name#"]
[Discord]
Meter=Image
Y=r
X=(10)R
W=(64*[Set.S])
H=(64*[Set.S])
DynamicVariables=1
Container=ContentContainer
ImageName=#@#Icons\#CURRENTSECTION#.png
Leftmouseupaction=[!SetClip "Jax#7000"][!SetOption Header Text "Copied to clipboard"][!UpdateMeter Header][!Redraw][!Delay 1000][!SetOption Header Text "Need help?"][!UpdateMeter Header][!Redraw]