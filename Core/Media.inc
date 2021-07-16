[Variables]
BarHandler=5
Sec.Padding=(20*#Set.S#)
Sec.BoxSize=(((#Set.W#-#Set.L#-#Set.P#)-30*2)/6-10*5*#Set.S#)

[Header]
Meter=String
X=(20*#Set.S#)
Y=(20*#Set.S#)
Text=Media /#Skin.Shorthand#
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

[Export]
Measure=String
String=#NPName#
IfMatch=Spotify
ifmatchaction=[!SetOption Box1 MeterStyle MediaBoxSelectedStyle][!UpdateMEter *][!Redraw]
IfMatch2=AIMP
ifmatchaction2=[!SetOption Box2 MeterStyle MediaBoxSelectedStyle][!UpdateMEter *][!Redraw]
IfMatch3=CAD
ifmatchaction3=[!SetOption Box3 MeterStyle MediaBoxSelectedStyle][!UpdateMEter *][!Redraw]
IfMatch4=iTunes
ifmatchaction4=[!SetOption Box4 MeterStyle MediaBoxSelectedStyle][!UpdateMEter *][!Redraw]
IfMatch5=WinAMP
ifmatchaction5=[!SetOption Box5 MeterStyle MediaBoxSelectedStyle][!UpdateMEter *][!Redraw]
IfMatch6=WMP
ifmatchaction6=[!SetOption Box6 MeterStyle MediaBoxSelectedStyle][!UpdateMEter *][!Redraw]
ifmatchmode=1

;================================================================================================================================================================================


[HELPICONTHING]
Meter=Image
ImageName=#@#Icons\Settings\HelpIcon.png
X=(#Set.W#-#Set.L#-#Set.P#-16-30)
Y=([Option01:Y]-16)
DynamicVariables=1
Leftmouseupaction=[!ActivateConfig "ModularPlayers\@Settings" "FAQ.ini"]
Container=ContentContainer

[Option01]
Meter=String
X=(25*#Set.S#)
Y=(60*#Set.S#)
FontSize=(10*#Set.S#)
Text=Select your music player.
MeterStyle=Set.String:S
Container=ContentContainer
[Divider192038]
Meter=Shape
MeterStyle=Set.Div:S

[MediaStyle]
Imagename=#@#Icons\Music\#CURRENTSECTION#.png
X=#Sec.Padding#r
Y=#Sec.Padding#r
W=#Sec.BoxSize#
H=#Sec.BoxSize#
PreserveAspectRatio=1
Container=ContentContainer
[MediaBoxStyle]
X=(10*#Set.S#+#Sec.Padding#)R
y=(-#Sec.Padding#)r
Shape=Rectangle 0,0,(#Sec.BoxSize#+#Sec.Padding#*2),(#Sec.BoxSize#+#Sec.Padding#*2),5,5 | StrokeWidth 0 | Extend this
this=Fill Color #Set.Opp_Color#,10
Container=ContentContainer
MouseOverAction=[!SetOption #CURRENTSECTION# this "Fill Color #Set.Opp_Color#,25"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# this "Fill Color #Set.Opp_Color#,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[MediaBoxSelectedStyle]
X=(10*#Set.S#+#Sec.Padding#)R
y=(-#Sec.Padding#)r
Shape=Rectangle 0,0,(#Sec.BoxSize#+#Sec.Padding#*2),(#Sec.BoxSize#+#Sec.Padding#*2),5,5 | StrokeWidth 0 | Extend this
this=Fill Color #Set.Opp_Color#,75
Container=ContentContainer

[Box1]
Meter=Shape
X=r
y=(10*#Set.S#)r
MeterStyle=MediaBoxStyle
Leftmouseupaction=[!WriteKEyValue Variables PLayer "WNP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "Spotify" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh]
[Spotify]
Meter=Image
MeterStyle=MediaStyle
[Box2]
Meter=Shape
MeterStyle=MediaBoxStyle
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "AIMP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh]
[AIMP]
Meter=Image
MeterStyle=MediaStyle
[Box3]
Meter=Shape
MeterStyle=MediaBoxStyle
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "CAD" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh]
[Foobar2000]
Meter=Image
MeterStyle=MediaStyle
[Box4]
Meter=Shape
MeterStyle=MediaBoxStyle
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "iTunes" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh]
[iTunes]
Meter=Image
MeterStyle=MediaStyle
[Box5]
Meter=Shape
MeterStyle=MediaBoxStyle
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "WinAMP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh]
[WinAMP]
Meter=Image
MeterStyle=MediaStyle
[Box6]
Meter=Shape
MeterStyle=MediaBoxStyle
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "WMP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh]
[WMP]
Meter=Image
MeterStyle=MediaStyle
