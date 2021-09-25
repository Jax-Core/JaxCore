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
Text=Override the Start Menu (uses Win key as hotkey)
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

[S]
Meter=String
Text=Pinned shortcuts
MeterStyle=Set.String:S | Set.OptionCat:S

[Option21]
Meter=String
Text=Open shortcuts folder
MeterStyle=Set.String:S | Set.OptionName:S
; [Set.Div:S190322131238]
; Meter=Shape
; MeterStyle=Set.Div:S
; [Option22]
; Meter=String
; Text=Weather location
; MeterStyle=Set.String:S | Set.OptionName:S
; [Set.Div:S19w2s0328]
; Meter=Shape
; MeterStyle=Set.Div:S
; [Option23]
; Meter=String
; Text=Unit (Metric/Imperial)
; MeterStyle=Set.String:S | Set.OptionName:S

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

[ReplaceWin]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])


[2412:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('2412', 'H')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables 2412 "I" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables 2412 "H" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[2412:0]
Meter=String
Text=12-Hour
FontColor=([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[2412:1]
Meter=String
Text=24-hour
FontColor=([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[Button21]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!CommandMeasure CheckForDataFolder "Check-Data"]["#SKINSPATH#..\CoreData\ValliStart"]
Y=([Option21:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=Open
MeterStyle=Set.String:S | Set.Value:S
[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\CheckData.ps1


@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini