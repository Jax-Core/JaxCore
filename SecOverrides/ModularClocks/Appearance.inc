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
IfMatch5=Text
IfNotMatchAction5=[!HideMeterGroup Text]

[Header]
Meter=String
X=(20*#Set.S#)
Y=(20*#Set.S#+#Scroll#)
Text=Appearance /Clocks
FontSize=(20*#Set.S#)
FontWeight=450
MeterStyle=Set.String:S
Container=ContentContainer
Leftmouseupaction=[!Refresh]
InlinePattern=\s(.*)
InlineSetting=Size | 10
InlinePattern2=\s(.*)
InlineSetting2=Color | 150,150,150

;================================================================================================================================================================================

;================================================================================================================================================================================

[Color]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Color
MeterStyle=Set.String:S
Container=ContentContainer

[Option00]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Colors
MeterStyle=Set.String:S
Container=ContentContainer


;================================================================================================================================================================================

[ColorMode:]
Meter=Shape
SecVar=ColorMode
0Act=[!CommandMeasure darkLight.Func "SwitchColor(0)"]
1Act=[!CommandMeasure darkLight.Func "SwitchColor(1)"]
MeterStyle=Set.Pick:S
Y=([Option00:Y]-#Set.P#+(-35/2+8)*#Set.S#)
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

[CurrentClock]
Meter=String
X=(20*#Set.S#)
Y=(50*#Set.S#)r
FontSize=(10*#Set.S#)
FontWeight=400
Text=Clock layout (#Style#)
MeterStyle=Set.String:S
Container=ContentContainer

[Box]
Shape=Rectangle  0,0,170,170,10,10 | StrokeWidth 0 | Extend Fill | Scale #Set.S#,#set.S#,0,0
Fill=Fill Color 255,255,255,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
[Box1]
Meter=Shape
X=r
Y=(10*#Set.S#)R
MeterStyle=Box
[Box2]
Meter=Shape
X=(20*#Set.S#)R
Y=r
MeterStyle=Box
[Box3]
Meter=Shape
X=(20*#Set.S#)R
Y=r
MeterStyle=Box
[Box4]
Meter=Shape
X=(20*#Set.S#)R
Y=r
MeterStyle=Box
[Box5]
Meter=Shape
X=(20*#Set.S#)R
Y=r
MeterStyle=Box
[BoxAdd]
Meter=Shape
X=189
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
W=(170*#Set.S#)
H=(170*#Set.S#)
Solidcolor=0,0,0,1
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]
DynamicVariables=1

[Measure]
Meter=Image
X=(20*#Set.S#)R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Graph]
Meter=Image
X=(20*#Set.S#)R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Smart]
Meter=Image
X=(20*#Set.S#)R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Text]
Meter=Image
X=(20*#Set.S#)R
Y=r
MeterStyle=Center
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!WriteKeyValue BoxAdd X "([#CURRENTSECTION#:X]-[ContentContainer:X])" "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh][!UpdateMeasure Auto_Refresh:M]

;================================================================================================================================================================================

[SmartOptions]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=#Style# Options
MeterStyle=Set.String:S
Container=ContentContainer

[Option01]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Skin scaling
MeterStyle=Set.String:S
Container=ContentContainer
[Divider1328]
Meter=Shape
MeterStyle=Set.Div:S
Group=Smart
[Option02]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
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
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Line width
MeterStyle=Set.String:S
Group=Graph
Container=ContentContainer

; ;================================================================================================================================================================================

;; BOOL EXMAPLE
; [BoolVarName]
; Meter=Shape
; MeterStyle=Set.Bool:S
; Y=([VarOption:Y]-#Set.P#+(-20/2+8)*#Set.S#)

;; TEXT INPUT EXAMPLE
; [TextVarName]
; Meter=Shape
; MeterStyle=Set.TextBox:S
; Y=([VarOption:Y]-#Set.P#+(-30/2+8)*#Set.S#)
; [VarOptionNumber]
; Meter=String
; Text=TextVarName
; MeterStyle=Set.String:S | Set.Value:S


[Scale]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[Align]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Smart
Y=([Option02:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value02]
Meter=String
Text=#Align#
Group=Smart
MeterStyle=Set.String:S | Set.Value:S

[Weather]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Smart
Y=([Option03:Y]-#Set.P#+(-20/2+8)*#Set.S#)

[Date]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Smart
Y=([Option04:Y]-#Set.P#+(-20/2+8)*#Set.S#)

[DateTimeRatio]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Smart
Y=([Option05:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value05]
Meter=String
Text=#DateTimeRatio#
Group=Smart
MeterStyle=Set.String:S | Set.Value:S

[Rotation]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Measure
Y=([Option06:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value06]
Meter=String
Text=#Rotation#
Group=Measure
MeterStyle=Set.String:S | Set.Value:S

[Stroke]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Measure
Y=([Option07:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value07]
Meter=String
Text=#Stroke#
Group=Measure
MeterStyle=Set.String:S | Set.Value:S

[Circle]
Meter=Shape
MeterStyle=Set.Bool:S
Group=Graph
Y=([Option08:Y]-#Set.P#+(-20/2+8)*#Set.S#)

[LineWidth]
Meter=Shape
MeterStyle=Set.TextBox:S
Group=Graph
Y=([Option09:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value09]
Meter=String
Text=#LineWidth#
Group=Graph
MeterStyle=Set.String:S | Set.Value:S

