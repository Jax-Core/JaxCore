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
Text=Hotkey activator type
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:S19032213112312313238]
Meter=Shape
MeterStyle=Set.Div:S
[Option011]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=HotKey - Key [Formatting]
InlinePattern=.*(\[.*\])
InlineSetting=Size | 8
InlinePattern2=.*(\[.*\])
InlineSetting2=Color | 150,150,150
MeterStyle=Set.String:S
Hidden=#KeyHook#
Leftmouseupaction=["https://www.autohotkey.com/docs/Hotkeys.htm"]
Container=ContentContainer
[Option012]
Meter=String
X=r
Y=r
FontSize=(10*#Set.S#)
Text=KeyHook - Key [Formatting]
InlinePattern=.*(\[.*\])
InlineSetting=Size | 8
InlinePattern2=.*(\[.*\])
InlineSetting2=Color | 150,150,150
MeterStyle=Set.String:S
Hidden=(1-#KeyHook#)
Leftmouseupaction=["https://github.com/brianferguson/HotKey.dll#pre-defined-hotkey-keywords"]
Container=ContentContainer
[Set.Div:S19032213238]
Meter=Shape
y=(27*#Set.S#)r
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

[KeyHook:]
Meter=Shape
SecVar=KeyHook
0Act=
1Act=
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-35/2+8)*#Set.S#)
[KeyHook:0]
Meter=String
Text=Hotkey
FontColor=(#KeyHook# = 0 ? 0 : 255),(#KeyHook# = 0 ? 0 : 255),(#KeyHook# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
[KeyHook:1]
Meter=String
Text=Keyhook
FontColor=(#KeyHook# = 1 ? 0 : 255),(#KeyHook# = 1 ? 0 : 255),(#KeyHook# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_1:S

;================================================================================================================================================================================

[Key]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option011:Y]-#Set.P#+(-30/2+8)*#Set.S#)
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 2"]
Hidden=(#KeyHook#)
[Value011]
Meter=String
Text=#Key#
Hidden=(#KeyHook#)
MeterStyle=Set.String:S | Set.Value:S
[HotKey]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option012:Y]-#Set.P#+(-30/2+8)*#Set.S#)
Hidden=(1-#KeyHook#)
[Value012]
Meter=String
Text=#HotKey#
Hidden=(1-#KeyHook#)
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

;================================================================================================================================================================================

[Input:M]
Command2=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad2:M]

[SaveAndLoad2:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#SKINSPATH#MIUI-Shade\@Resources\Actions\HotKeys.ini"][!UpdateMeter *][!Redraw][!UpdateMeasure Auto_Refresh:M]
Disabled=1
Group=NUOL

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini