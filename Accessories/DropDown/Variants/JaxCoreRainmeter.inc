[Variables]
@includeSecvar=#@#Secvar.inc

[Func]
Measure=Script
ScriptFile=#@#Lua\Func.lua

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Run bang]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('RunBang')"][!DeactivateConfig]
MeterStyle=String:S
[Div:0]
Meter=Shape
MeterStyle=Div:S
[Go to module]
Meter=String
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('GoToPage', '#Skin.Name#')"][!DeactivateConfig]
MeterStyle=String:S
[Div:01]
Meter=Shape
MeterStyle=Div:S
[Go to page]
Meter=String
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('GoToModulePage', '#Skin.Name#')"][!DeactivateConfig]
MeterStyle=String:S
[Div:02]
Meter=Shape
MeterStyle=Div:S
[Value Debug]
Meter=String
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('ValueDebugger')"][!DeactivateConfig]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Manage panel]
Meter=String
LeftMouseUpAction=[!Manage Manage][!DeactivateConfig]
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Logs]
Meter=String
LeftMouseUpAction=[!About Logs][!DeactivateConfig]
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Skin data]
Meter=String
LeftMouseUpAction=[!About Skins][!DeactivateConfig]
MeterStyle=String:S
[Div:4]
Meter=Shape
MeterStyle=Div:S
[Plugin list]
Meter=String
LeftMouseUpAction=[!About Plugins][!DeactivateConfig]
MeterStyle=String:S