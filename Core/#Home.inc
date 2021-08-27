[MIUI-Shade]
Meter=Image
X=r
Y=([RecommendedSkins:H]*([Set.S]-1)+10*[Set.S])R
ImageName=#@#Images\Cards\MIUI-Shade.png
MeterStyle=SkinIcon:S
[MIUI-ShadeDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=MIUI-Shade#CRLF# Control, Hotkey, Animated
[Keylaunch]
Meter=Image
ImageName=#@#Images\Cards\Keylaunch.png
MeterStyle=SkinIcon:S
[KeylaunchDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=Keylaunch#CRLF# Workflow, Efficiency, Animated
[Keystrokes]
Meter=Image
ImageName=#@#Images\Cards\Keystrokes.png
MeterStyle=SkinIcon:S
[KeystrokesDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=Keystrokes#CRLF# Overlay, Gaming, Hotkey
[All]
Meter=String
Text=All Skins
MeterStyle=Set.String:S
X=(#Set.P#)
Y=(35*[Set.S])R
Group=Scroll
FontSize=15
StringAlign=LeftTop
FontFace=Poppins SemiBold
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])
[ModularClocks]
Meter=Image
X=r
Y=([All:H]*([Set.S]-1)+10*[Set.S])R
ImageName=#@#Images\Cards\ModularClocks.png
MeterStyle=SkinIcon:S
[ModularClocksDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=ModularClocks#CRLF# Modern, Time, Animated
[Plainext]
Meter=Image
ImageName=#@#Images\Cards\Plainext.png
MeterStyle=SkinIcon:S
[PlainextDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=Plainext#CRLF# System, Retro
[ModularPlayers]
Meter=Image
ImageName=#@#Images\Cards\ModularPlayers.png
MeterStyle=SkinIcon:S
[ModularPlayersDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=ModularPlayers#CRLF# Modern, Music, Minimal
[Combilaunch]
Meter=Image
X=(#Set.P#)
Y=(10*[Set.S])R
ImageName=#@#Images\Cards\Combilaunch.png
MeterStyle=SkinIcon:S
[CombilaunchDes]
Meter=String
MeterStyle=Set.String:S | SkinText:S
Text=Combilaunch#CRLF# Launcher, Minimal
