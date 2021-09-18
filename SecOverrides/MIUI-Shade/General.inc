[Variables]
Drag=0

[HotkeysTitle]
Meter=String
Text=Hotkeys
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=HotKey
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Disable when fullscreen
MeterStyle=Set.String:S | Set.OptionName:S
;================================================================================================================================================================================

[Time]
Meter=String
Text=Time
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Time format: 24(H) 12(I)
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[Weathers]
Meter=String
Text=Weather
MeterStyle=Set.String:S | Set.OptionCat:S

[Option21]
Meter=String
Text=Show weather notification
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S190322131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Weather location
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Unit (Metric/Imperial)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[DragTitle]
Meter=String
Text=Dragging
MeterStyle=Set.String:S | Set.OptionCat:S

[Option30]
Meter=String
Text=Drag to launch skin
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:238]
Meter=Shape
MeterStyle=Set.Div:S
[Option31]
Meter=String
Text=Dragging area width
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
Text=Dragging area location
MeterStyle=Set.String:S | Set.OptionName:S



;================================================================================================================================================================================

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Hotkey')"]
[Value01]
Meter=String
Text=#KeyInString#
MeterStyle=Set.String:S | Set.Value:S
[HideOnFullScreen]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[2412]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#2412#
MeterStyle=Set.String:S | Set.Value:S

[Weather]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])

[WeatherLocation]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[WeatherUnits]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value23]
Meter=String
Text=#WeatherUnits#
MeterStyle=Set.String:S | Set.Value:S

[ActiveChecker2]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\Activator
IfCondition=ActiveChecker2 = 1
IfTrueAction=[!SetVariable Drag 1][!UpdateMeter Drag][!Redraw]

[Drag]
Meter=Shape
MeterStyle=Set.Bool:S | Drag#Drag#
Y=([Option30:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Drag0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\Activator"][!Refresh]
[Drag1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\Activator"][!Refresh]

[Detect.Size]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option31:Y]-#Set.P#+(-30/2+8)*[Set.S])
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
Y=([Option32:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Detect.Location:0]
Meter=String
Text=Left
FontColor=(#Detect.Location# = 0 ? 0 : 255),(#Detect.Location# = 0 ? 0 : 255),(#Detect.Location# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!Refresh "#Skin.Name#\Activator"]
[Detect.Location:1]
Meter=String
Text=Right
FontColor=(#Detect.Location# = 1 ? 0 : 255),(#Detect.Location# = 1 ? 0 : 255),(#Detect.Location# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_1:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!Refresh "#Skin.Name#\Activator"]

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