[Export:M]
Measure=String
String=#Style#
IfMatch=Center
IfNotMatchAction=[!HideMeterGroup Center]
IfMatch2=Measure
IfNotMatchAction2=[!HideMeterGroup Measure]
IfMatch3=Graph
IfNotMatchAction3=[!HideMeterGroup Graph]
IfMatch4=Smart
IfNotMatchAction4=[!HideMeterGroup Smart]
IfMatch5=^CircTech$
IfNotMatchAction5=[!HideMeterGroup CircTech]
IfMatch6=^Tech$
IfNotMatchAction6=[!HideMeterGroup Tech]
IfMatch7=Arc
IfNotMatchAction7=[!HideMeterGroup Arc]
IfMatch8=Light
IfNotMatchAction8=[!HideMeterGroup Light]

[Export2:M]
Measure=String
String=#VersionPage#
IfMatch=1
IfMatchAction=[!HideMeterGroup V2]
IfMatch2=2
IfMatchAction2=[!HideMeterGroup V1]


[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S]+#Scroll#)
Text=Appearance /Clocks
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

[Variables]
VersionPage=1

;================================================================================================================================================================================

[Color]
Meter=String
Text=Color
MeterStyle=Set.String:S | Set.OptionCat:S

[Option00]
Meter=String
Text=Colors
MeterStyle=Set.String:S | Set.OptionName:S
[Divider19w2sds0ssdsd]
Meter=Shape
MeterStyle=Set.Div:S
[Option000]
Meter=String
Text=Animated update rate
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[ColorMode:]
Meter=Shape
SecVar=ColorMode
0Act=[!CommandMeasure darkLight.Func "SwitchColor(0)"]
1Act=[!CommandMeasure darkLight.Func "SwitchColor(1)"]
MeterStyle=Set.Pick:S
Y=([Option00:Y]-#Set.P#+(-35/2+8)*[Set.S])
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
Text=Clock style // #Style#
MeterStyle=Set.String:S | Set.OptionCat:S

[Box]
Shape=Rectangle  0,0,(([ContentContainer:W]-120*[Set.S])/5),(([ContentContainer:W]-120*[Set.S])/5),#set.R# | StrokeWidth 0 | Extend Fill
Fill=Fill Color 255,255,255,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Box1]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Box
[Box2]
Meter=Shape
X=(20*[Set.S])R
Y=r
MeterStyle=Box
[Box3]
Meter=Shape
X=(20*[Set.S])R
Y=r
MeterStyle=Box
[Box4]
Meter=Shape
X=(20*[Set.S])R
Y=r
MeterStyle=Box
[Box5]
Meter=Shape
X=(20*[Set.S])R
Y=r
MeterStyle=Box
[BoxAdd]
Meter=Shape
X=642
Y=r
DynamicVariables=1
Fill=Fill Color 255,255,255,50
Mouseoveraction=[]
MouseLeaveAction=[]
MeterStyle=Box


[Center]
Meter=Image
Imagename=#SKINSPATH#ModularClocks\@Resources\Images\Preview\#CURRENTSECTION#.png
X=([Box1:X])
Y=([Box1:Y])
W=(([ContentContainer:W]-120*[Set.S])/5)
H=(([ContentContainer:W]-120*[Set.S])/5)
Solidcolor=0,0,0,1
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]
DynamicVariables=1
Group=V1

[Measure]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Graph]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Smart]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Text]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[CircTech]
Meter=Image
Imagename=#SKINSPATH#ModularClocks\@Resources\Images\Preview\#CURRENTSECTION#.png
X=([Box1:X])
Y=([Box1:Y])
W=(([ContentContainer:W]-120*[Set.S])/5)
H=(([ContentContainer:W]-120*[Set.S])/5)
Solidcolor=0,0,0,1
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]
DynamicVariables=1
Group=V2

[Tech]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=CircTech
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Arc]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=CircTech
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Light]
Meter=Image
X=(20*[Set.S])R
Y=r
MeterStyle=CircTech
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[VersionBox]
Shape=Rectangle 0,0,(([ContentContainer:W]-60*[Set.S])/2),(30*[Set.S]),(10/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color 255,255,255,10
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
[Ver1]
Meter=Shape
X=(20*[Set.S])
Y=(10*[Set.S])R
MeterStyle=VersionBox
Leftmouseupaction=[!WriteKeyvalue Variables VersionPage 1 "#SKINSPATH##JaxCore\SecOverrides\#Skin.Name#\Appearance.inc"][!Refresh]
[Ver1Text]
Meter=String
X=([Ver1:W]/2)r
Y=(15*[Set.S])r
FontSize=(10*[Set.S])
Text=Version 1 Styles
StringAlign=CenterCenter
Container=ContentContainer
MeterStyle=Set.String:S
[Ver2]
Meter=Shape
X=(([Ver1:W]/2)+20*[Set.S])r
Y=(-15*[Set.S])r
MeterStyle=VersionBox
Leftmouseupaction=[!WriteKeyvalue Variables VersionPage 2 "#SKINSPATH##JaxCore\SecOverrides\#Skin.Name#\Appearance.inc"][!Refresh]
[Ver2Text]
Meter=String
Text=Version 2 Styles
MeterStyle=Set.String:S | Ver1Text


;================================================================================================================================================================================

[SmartOptions]
Meter=String
Text=#Style# Options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Skin scaling
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Smart
[Option02]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Align
MeterStyle=Set.String:S
Group=Smart
Container=ContentContainer
[Divider19203s8]
Meter=Shape
MeterStyle=Set.Div:S
Group=Smart
[Option03]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Weather
MeterStyle=Set.String:S
Group=Smart
Container=ContentContainer
[Divider1920328]
Meter=Shape
Group=Smart
MeterStyle=Set.Div:S
[Option04]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Date
MeterStyle=Set.String:S
Group=Smart
Container=ContentContainer
[Divider19w20328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Smart
[Option05]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Date-Time scaling ratio
MeterStyle=Set.String:S
Group=Smart
Container=ContentContainer



[Divider19w20328sdsd]
Meter=Shape
MeterStyle=Set.Div:S
Y=([Option01:Y]-#Set.P#+15*2)
DynamicVariables=1
Group=Measure
[Option06]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Rotation (Hori / Vert)
MeterStyle=Set.String:S
Group=Measure
Container=ContentContainer
[Divider19w20dsdaw328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Measure
[Option07]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Stroke width
MeterStyle=Set.String:S
Group=Measure
Container=ContentContainer



[Divider19w20ssdsd]
Meter=Shape
MeterStyle=Set.Div:S
Y=([Option01:Y]-#Set.P#+15*2)
DynamicVariables=1
Group=Graph
[Option08]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Show dot
MeterStyle=Set.String:S
Group=Graph
Container=ContentContainer
[Divider19wdaw328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Graph
[Option09]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Line width
MeterStyle=Set.String:S
Group=Graph
Container=ContentContainer

[Divider19w2sdsds0ssdsd]
Meter=Shape
MeterStyle=Set.Div:S
Y=([Option01:Y]-#Set.P#+15*2)
DynamicVariables=1
Group=Tech
[Option11]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Show additional time details
MeterStyle=Set.String:S
Group=Tech
Container=ContentContainer
[Divider19wdwqeqewqeqweaw328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Tech
[Option12]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Text=Use the runic font
MeterStyle=Set.String:S
Group=Tech
Container=ContentContainer

; ;================================================================================================================================================================================

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
[Rm.Update]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option000:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value000]
Meter=String
Text=#Rm.update#
MeterStyle=Set.String:S | Set.Value:S

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[Align]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Smart
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Align#
Group=Smart
MeterStyle=Set.String:S | Set.Value:S

[Weather]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Smart
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Date]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Smart
Y=([Option04:Y]-#Set.P#+(-20/2+8)*[Set.S])

[DateTimeRatio]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Smart
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#DateTimeRatio#
Group=Smart
MeterStyle=Set.String:S | Set.Value:S

[Rotation]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Measure
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#Rotation#
Group=Measure
MeterStyle=Set.String:S | Set.Value:S

[Stroke]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Measure
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#Stroke#
Group=Measure
MeterStyle=Set.String:S | Set.Value:S

[Circle]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Graph
Y=([Option08:Y]-#Set.P#+(-20/2+8)*[Set.S])

[LineWidth]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Graph
Y=([Option09:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value09]
Meter=String
Text=#LineWidth#
Group=Graph
MeterStyle=Set.String:S | Set.Value:S


[ShowDetails]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Tech
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Runic]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Tech
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])