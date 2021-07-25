[Variables]
Drag=0

[HotkeysTitle]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Hotkeys
MeterStyle=Set.String:S
Container=ContentContainer

[Option01]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=HotKey
InlinePattern=.*(\[.*\])
InlineSetting=Size | 8
InlinePattern2=.*(\[.*\])
InlineSetting2=Color | 150,150,150
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Disable when fullscreen
MeterStyle=Set.String:S
Container=ContentContainer
;================================================================================================================================================================================

[Time]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
DynamicVariables=1
FontSize=(14*#Set.S#)
FontWeight=500
Text=Time
MeterStyle=Set.String:S
Container=ContentContainer

[Option11]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Time format: 24(H) 12(I)
MeterStyle=Set.String:S
Container=ContentContainer


;================================================================================================================================================================================

[Weathers]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Weather
MeterStyle=Set.String:S
Container=ContentContainer

[Option21]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Show weather notification
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:S190322131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Weather location
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:S19w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Unit (Metric/Imperial)
MeterStyle=Set.String:S
Container=ContentContainer

;================================================================================================================================================================================

[DragTitle]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Dragging
MeterStyle=Set.String:S
Container=ContentContainer

[Option30]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Drag to launch skin
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:238]
Meter=Shape
MeterStyle=Set.Div:S
[Option31]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Dragging area width
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Dragging area location
MeterStyle=Set.String:S
Container=ContentContainer



;================================================================================================================================================================================

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*#Set.S#)
Act=[!ActivateConfig "#JaxCore\Main\Hotkey"]
[Value01]
Meter=String
Text=#Key#
MeterStyle=Set.String:S | Set.Value:S
[HideOnFullScreen]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*#Set.S#)

[2412]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value11]
Meter=String
Text=#2412#
MeterStyle=Set.String:S | Set.Value:S

[Weather]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*#Set.S#)

[WeatherLocation]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value22]
Meter=String
Text=#WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[WeatherUnits]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value23]
Meter=String
Text=#WeatherUnits#
MeterStyle=Set.String:S | Set.Value:S

[ActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\Activator
IfCondition=ActiveChecker = 1
IfTrueAction=[!SetVariable Drag 1][!UpdateMeter Drag][!Redraw]

[Drag]
Meter=Shape
MeterStyle=Set.Bool:S | Drag#Drag#
Y=([Option30:Y]-#Set.P#+(-20/2+8)*#Set.S#)
[Drag0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\Activator"][!Refresh]
[Drag1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\Activator"][!Refresh]

[Detect.Size]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option31:Y]-#Set.P#+(-30/2+8)*#Set.S#)
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 2"]
[Value31]
Meter=String
Text=#Detect.Size#
MeterStyle=Set.String:S | Set.Value:S

[Detect.Location:]
Meter=Shape
SecVar=Detect.Location
0Act=[!CommandMeasure darkLight.Func "SwitchColor(0)"]
1Act=[!CommandMeasure darkLight.Func "SwitchColor(1)"]
MeterStyle=Set.Pick:S
Y=([Option32:Y]-#Set.P#+(-35/2+8)*#Set.S#)
[Detect.Location:0]
Meter=String
Text=Left
FontColor=(#Detect.Location# = 0 ? 0 : 255),(#Detect.Location# = 0 ? 0 : 255),(#Detect.Location# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Jax.Func:secVLocalGroup('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Jax.Func:secVLocalGroup('#CURRENTSECTION#', '0Act')][!Refresh][!Refresh "#Skin.Name#\Activator"]
[Detect.Location:1]
Meter=String
Text=Right
FontColor=(#Detect.Location# = 1 ? 0 : 255),(#Detect.Location# = 1 ? 0 : 255),(#Detect.Location# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_1:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Jax.Func:secVLocalGroup('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Jax.Func:secVLocalGroup('#CURRENTSECTION#', '1Act')][!Refresh][!Refresh "#Skin.Name#\Activator"]

;================================================================================================================================================================================
[Input:M]
Command2=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad2:M]

[SaveAndLoad2:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#Sec.SaveLocation#"][!UpdateMeter *][!Redraw][!Refresh "#Skin.Name#\Activator"]
Disabled=1
Group=NUOL

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini