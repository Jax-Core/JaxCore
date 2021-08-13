[Rainmeter]
Update=-1

[Variables]
BarHandler=6
Scroll=0

[LaunchVis]
Measure=Calc
onupdateaction=[!Delay 500][!EnableMeasureGroup NUOL]

[ContentContainer]
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-30,-150,0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+30,-150,0))"][!UpdateMeter *][!Redraw]
MouseActionCursor=0

[Export]
Measure=String
String=#Render#
IfMatch=Chameleon
IfNotMatchAction=[!HideMeterGroup Chameleon]
IfMatch2=Shadow
IfNotMatchAction2=[!HideMeterGroup Shadow]
IfMatch3=Blur
IfNotMatchAction3=[!HideMeterGroup Blur]
IfMatch4=Bar
IfNotMatchAction4=[!HideMeterGroup Bar]

[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S]+#Scroll#)
DynamicVariables=1
Text=General /Clocks
FontSize=(20*[Set.S])
FontWeight=450
MeterStyle=Set.String:S
Container=ContentContainer
Leftmouseupaction=[!Refresh]
InlinePattern=\s(.*)
InlineSetting=Size | 10
InlinePattern2=\s(.*)
InlineSetting2=Color | 150,150,150

;================================================================================================================================================================================

[Look]
Meter=String
Text=Rendering (#Render#)
MeterStyle=Set.String:S | Set.OptionCat:S

[RenderStyle]
X=(15*[Set.S])R
Y=r
W=(([ContentContainer:W]-80*[Set.S])/3)
DynamicVariables=1
Container=ContentContainer
ImageName=#SKINSPATH#ModularCLocks\@Resources\Images\Preview\Render\#CURRENTSECTION#.png
Leftmouseupaction=[!WriteKeyValue Variables Render #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
[Chameleon]
Meter=Image
X=r
Y=(15*[Set.S])R
MeterStyle=RenderStyle
[Shadow]
Meter=Image
MeterStyle=RenderStyle
[Blur]
Meter=Image
MeterStyle=RenderStyle
; [Bar]
; Meter=Image
; MeterStyle=RenderStyle
; ImageAlpha=50
; Leftmouseupaction=[]

;================================================================================================================================================================================

[SmartOptipojs]
Meter=String
Text=#Render# Options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Opacity
MeterStyle=Set.String:S | Set.OptionName:S
Group=Shadow
[Divider1328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Shadow
[Option02]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Sigma
MeterStyle=Set.String:S
Group=Shadow
Container=ContentContainer
[Divider19203s8]
Meter=Shape
MeterStyle=Set.Div:S
Group=Shadow
[Option03]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Offset
MeterStyle=Set.String:S
Group=Shadow
Container=ContentContainer
[Divider193s8]
Meter=Shape
MeterStyle=Set.Div:S
Group=Shadow

[Option11]
Meter=String
X=r
Y=([Option01:Y]-#Set.P#)
FontSize=(10*[Set.S])
Text=Modulate (Brightness, Saturation, Hue)
MeterStyle=Set.String:S
Container=ContentContainer
Group=Blur
DynamicVariables=1
[Divider132sdasd8]
Meter=Shape
MeterStyle=Set.Div:S
Group=Blur
[Option12]
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
[Option13]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Radius
MeterStyle=Set.String:S
Group=Blur
Container=ContentContainer
[Divider193sds8]
Meter=Shape
MeterStyle=Set.Div:S
Group=Blur

[Option21]
Meter=String
X=r
Y=([Option01:Y]-#Set.P#)
FontSize=(10*[Set.S])
Text=Background opacity
MeterStyle=Set.String:S
Container=ContentContainer
Group=Bar
DynamicVariables=1

;================================================================================================================================================================================

;; BOOL EXMAPLE
; [BoolVarName]
; Meter=Shape
; MeterStyle=Set.Bool:S
; Y=([VarOption:Y]-#Set.P#+(-20/2+8)*[Set.S])

;; TEXT INPUT EXAMPLE
; [TextVarName]
; Meter=Shape
; MeterStyle=Set.TextBox:S
; Y=([VarOption:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [VarOptionNumber]
; Meter=String
; Text=TextVarName
; MeterStyle=Set.String:S | Set.Value:S


[ShadowOpacity]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Shadow
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#ShadowOpacity#
Group=Shadow
MeterStyle=Set.String:S | Set.Value:S

[ShadowSigma]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Shadow
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#ShadowSigma#
Group=Shadow
MeterStyle=Set.String:S | Set.Value:S

[ShadowOffset]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Shadow
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#ShadowOffset#
Group=Shadow
MeterStyle=Set.String:S | Set.Value:S

;===========================

[BlurModulate]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Blur
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#BlurModulate#
Group=Blur
MeterStyle=Set.String:S | Set.Value:S

[BlurSigma]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Blur
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#BlurSigma#
Group=Blur
MeterStyle=Set.String:S | Set.Value:S

[BlurRadius]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Blur
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#BlurRadius#
Group=Blur
MeterStyle=Set.String:S | Set.Value:S

;===========================

; [BarBackpacity]
; Meter=Shape
; MeterStyle=Set.TextBox:S
; Group=Bar
; Class=21
; [Value21]
; Meter=String
; Text=#BarBackpacity#
; Group=Bar
; MeterStyle=Set.String:S | Set.Value:S



;================================================================================================================================================================================