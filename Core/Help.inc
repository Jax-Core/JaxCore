[Variables]
BarHandler=11


[Header]
Meter=String
X=([ContentContainer:W]/2)
Y=([ContentContainer:H]/2-[GitHub:W]/2-5/2)
DynamicVariables=1
StringAlign=CenterCenter
Text=Need help?
FontFace=Roboto Medium
FontSize=(30*#Set.S#)
MeterStyle=Set.String:S
[Subheader]
Meter=String
X=r
Y=R
StringAlign=CenterCenter
Text=Visit the github for a detailed guide / DM me Jax#7000 on discord:
FontColor=150,150,150
FontSize=(12*#Set.S#)
FontFace=Roboto Light
; InlinePattern=Jax\s-\s(.*)
; InlineSetting=Color | #TC#,150
MeterStyle=Set.String:S
[GitHub]
Meter=Image
Y=(5*#Set.S#)R
X=([ContentContainer:W]/2-[#CURRENTSECTION#:W]*1-5)
W=(64*#Set.S#)
H=[GitHub:W]
DynamicVariables=1
Container=ContentContainer
ImageName=#@#Icons\#CURRENTSECTION#.png
Leftmouseupaction=["https://github.com/EnhancedJax/#Skin.Name#"]
[Discord]
Meter=Image
Y=r
X=(10*#Set.S#)R
W=[GitHub:W]
H=[GitHub:W]
DynamicVariables=1
Container=ContentContainer
ImageName=#@#Icons\#CURRENTSECTION#.png
Leftmouseupaction=[!SetClip "Jax#7000"][!SetOption Header Text "Copied to clipboard"][!UpdateMeter Header][!Redraw][!Delay 1000][!SetOption Header Text "Need help?"][!UpdateMeter Header][!Redraw]