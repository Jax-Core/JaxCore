[HotkeysTitle]
Meter=String
Text=Activation
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
Text=Use this hotkey in addition to dragging top left of window
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1238]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Amount of drag required to start
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Distance of panel from screen edge
MeterStyle=Set.String:S | Set.OptionName:S
;================================================================================================================================================================================

[Time]
Meter=String
Text=Behavior
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Automatically switch to next line upon entering
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:Ss]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Show checklist dots
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

[UseHotkey]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[DragAmount]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#DragAmount#
MeterStyle=Set.String:S | Set.Value:S

[ScreenPadding]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#ScreenPadding#
MeterStyle=Set.String:S | Set.Value:S

[AutoNextLine]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])

[CheckDots]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])

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