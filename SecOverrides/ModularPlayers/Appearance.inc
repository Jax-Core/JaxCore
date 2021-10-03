[Export:M]
Measure=String
String=#Style#
IfMatch=MIUI
IfNotMatchAction=[!HideMeterGroup MIUI]
IfMatch2=Card
IfNotMatchAction2=[!HideMeterGroup Card]
IfMatch3=Side
IfNotMatchAction3=[!HideMeterGroup Side]
IfMatch4=Neumorphism
IfNotMatchAction4=[!HideMeterGroup Neumorphism]
IfMatch5=Simple
IfNotMatchAction5=[!HideMeterGroup Simple]
IfMatch6=Fortnite
IfNotMatchAction6=[!HideMeterGroup Fortnite]
IfMatch7=Blur
IfNotMatchAction7=[!HideMeterGroup Blur]
IfMatch8=Android
IfNotMatchAction8=[!HideMeterGroup Android]
IfMatch9=BigCirc
IfNotMatchAction9=[!HideMeterGroup BigCirc]

;================================================================================================================================================================================

;================================================================================================================================================================================

[Color]
Meter=String
Text=Color
MeterStyle=Set.String:S | Set.OptionCat:S

[Option00]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[ColorMode:]
Meter=Shape
SecVar=ColorMode
0Act=[!CommandMeasure darkLight.Func "SwitchColor(0)"]
1Act=[!CommandMeasure darkLight.Func "SwitchColor(1)"]
MeterStyle=Set.Pick:S
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[ColorMode:0]
Meter=String
Text=Dark
FontColor=(#ColorMode# = 0 ? 0 : 255),(#ColorMode# = 0 ? 0 : 255),(#ColorMode# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
[ColorMode:1]
Meter=String
Text=Light
FontColor=(#ColorMode# = 1 ? 0 : 255),(#ColorMode# = 1 ? 0 : 255),(#ColorMode# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_1:S
; ;================================================================================================================================================================================

;================================================================================================================================================================================

[Clock]
Meter=String
Text=Player style // #Style#
MeterStyle=Set.String:S | Set.OptionCat:S


[Box]
X=(20*[Set.S])R
Y=r
Shape=Rectangle  0,0,(([ContentContainer:W]-120*[Set.S])/5),(([ContentContainer:W]-120*[Set.S])/5),#set.R# | StrokeWidth 0 | Extend Fill
Fill=Fill Color 255,255,255,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Box1]
Meter=Shape
X=(20*[Set.S])
Y=(10*[Set.S])R
MeterStyle=Box
[Box2]
Meter=Shape
MeterStyle=Box
[Box3]
Meter=Shape
MeterStyle=Box
[Box4]
Meter=Shape
MeterStyle=Box
[Box5]
Meter=Shape
MeterStyle=Box
[Box6]
Meter=Shape
X=(20*[Set.S])
Y=(10*[Set.S])R
MeterStyle=Box
[Box7]
Meter=Shape
MeterStyle=Box
[Box8]
Meter=Shape
MeterStyle=Box
[Box9]
Meter=Shape
MeterStyle=Box


[MIUI]
Meter=Image
Imagename=#SKINSPATH#ModularPlayers\@Resources\Images\Preview\#CURRENTSECTION#.png
X=([Box1:X])
Y=([Box1:Y])
W=(([ContentContainer:W]-120*[Set.S])/5)
H=(([ContentContainer:W]-120*[Set.S])/5)
Solidcolor=0,0,0,1
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
DynamicVariables=1

[Card]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[MMI1]
Meter=Image
ImageName=#@#Icons\Settings\MagickMeterIcon.png
X=r
y=r
W=(24*[Set.S])
H=(24*[Set.S])
Padding=5,5,5,5
LeftMouseUpAction=[!ActivateConfig "#Skin.Name#\@Start"]

[Side]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[Neumorphism]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[MMI2]
Meter=Image
MeterStyle=MMI1

[Simple]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[Fortnite]
Meter=Image
X=([Box6:X])
Y=([Box6:Y])
MeterStyle=MIUI

[Android]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[Blur]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[MMI8]
Meter=Image
MeterStyle=MMI1

[BigCirc]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=MIUI

[MMI9]
Meter=Image
MeterStyle=MMI1

;================================================================================================================================================================================

[Options]
Meter=String
X=(30*[Set.S])
Y=([Box6:YH])
DynamicVariables=1
FontSize=(14*[Set.S])
FontWeight=500
Text=Options
MeterStyle=Set.String:S
Container=ContentContainer

[Option01]
Meter=String
Text=Skin scale
MeterStyle=Set.String:S | Set.OptionName:S


[BlurOptions]
Meter=String
X=(30*[Set.S])
Y=(30*[Set.S])R
FontSize=(14*[Set.S])
FontWeight=500
Text=Blur options
Group=Blur
MeterStyle=Set.String:S
Container=ContentContainer
[Option11]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Sigma
MeterStyle=Set.String:S
Group=Blur
Container=ContentContainer
[Divider192weewe03s8]
Meter=Shape
MeterStyle=Set.Div:S
Group=Blur
[Option12]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Radius
MeterStyle=Set.String:S
Group=Blur
Container=ContentContainer

[AlbumO]
Meter=String
X=(30*[Set.S])
Y=([BlurOptions:Y]-#set.P#)
FontSize=(14*[Set.S])
FontWeight=500
Text=Side options
Group=Side
DynamicVariables=1
MeterStyle=Set.String:S
Container=ContentContainer
[Option21]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Reduce album art to bar
MeterStyle=Set.String:S
Group=Side
Container=ContentContainer
[Divider1s]
Meter=Shape
MeterStyle=Set.Div:S
Group=Side
[Option22]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Side glow
MeterStyle=Set.String:S
Group=Side
Container=ContentContainer
;================================================================================================================================================================================

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[BlurSigma]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Blur
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#BlurSigma#
Group=Blur
MeterStyle=Set.String:S | Set.Value:S
[BlurRadius]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Blur
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#BlurRadius#
Group=Blur
MeterStyle=Set.String:S | Set.Value:S

[HideAlbum]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])
Group=Side
[SideGlow]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option22:Y]-#Set.P#+(-20/2+8)*[Set.S])
Group=Side
