[HotkeysTitle]
Meter=String
Text=Hotkeys
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Hotkey activator type
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19032213112312313238]
Meter=Shape
MeterStyle=Set.Div:S
[Option011]
Meter=String
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
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
FontSize=(10*[Set.S])
Text=KeyHook - Key [Formatting]
InlinePattern=.*(\[.*\])
InlineSetting=Size | 8
InlinePattern2=.*(\[.*\])
InlineSetting2=Color | 150,150,150
MeterStyle=Set.String:S
Hidden=(1-#KeyHook#)
Leftmouseupaction=["https://github.com/brianferguson/HotKey.dll#pre-defined-hotkey-keywords"]
Container=ContentContainer

[Behavior]
Meter=String
Text=Behavior
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Count of history to save
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1903221311313238]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Cache images
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S190322113238]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Generate
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[KeyHook:]
Meter=Shape
SecVar=KeyHook
0Act=
1Act=
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
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
Y=([Option011:Y]-#Set.P#+(-30/2+8)*[Set.S])
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
Y=([Option012:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#KeyHook#)
[Value012]
Meter=String
Text=#HotKey#
Hidden=(1-#KeyHook#)
MeterStyle=Set.String:S | Set.Value:S

[MaxClips]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#MaxClips#
MeterStyle=Set.String:S | Set.Value:S
[GetImage]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Button13]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,255,10,200
LeaveColor=0,255,10,100
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure ClipGen:M "GenClip(#MaxClips#)"]
[Value13]
Meter=String
Text=Generate
MeterStyle=Set.String:S | Set.Value:S
;================================================================================================================================================================================

[Input:M]
Command2=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad2:M]

[SaveAndLoad2:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#SKINSPATH##SKin.Name#\@Resources\Actions\HotKeys.ini"][!UpdateMeter *][!Redraw][!UpdateMeasure Auto_Refresh:M]
Disabled=1
Group=NUOL


[ClipGen:M]
Measure=Script
ScriptFile=#@#Lua\GenClipifyClip.lua

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini