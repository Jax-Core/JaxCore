
[LoadAct]
Measure=Calc
OnUpdateAction=[!SetVariable Set.W #SCREENAREAWIDTH#][!SetVariable Set.H #WORKAREAHEIGHT#][!SetOption Set.S Formula (#SCREENAREAWIDTH#/1920)][!UpdateMeasure Set.S][!HideMeter bottomButton][!HideMeter BottomText][!HideMeterGroup WindowDragMargin][!UpdateMeter *][!Redraw][!Move 0 0][!Draggable 0]

[Variables]
Sec.Page=1
Sec.L=(600*[Set.S])

Sec.Active=NotSaved 
Sec.X=                                                                                                                                                                                                                     
Sec.Y=                                                                                                                                                                                                                     
Sec.Thru=                                                                                                                                                                                                                     
Sec.Drag=                                                                                                                                                                                                                     
Sec.Snap=                                                                                                                                                                                                                     
Sec.Keep=                                                                                                                                                                                                                     
Sec.ZPos=                                                                                                                                                                                                                     

[Script:M]
Measure=Script
ScriptFile=#@#Lua\ModularClocks.lua
DynamicVariables=1

[PSRMDelayer]
Measure=Calc
Disabled=1
OnupdateAction=[!Delay 100][!CommandMeasure PSRM "FetchVars"]

[PSRM]
Measure = Plugin
Plugin = PowershellRM
ScriptFile = #@#PowerShell\FetchVars.ps1

[TabSelect1]
FontColor=#Set.Text_Color#
[TabSelect0]
FontColor=#Set.Text_Color#,150

[ActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\Main
IfCondition=
IfTrueAction=
Disabled=1

[Auto_Refresh:M]
Measure=String
OnUpdateAction=[!CommandMeasure Script:M "Move()"][!Refresh "#Skin.Name#\Main"][!UpdateMeasure Script:M]
IfMatchMode=1
Group=NUOL
Disabled=1


; ---------------------------------------------------------------------------- ;
;                                     Stuff                                    ;
; ---------------------------------------------------------------------------- ;

[customize]
Meter=String
Text=Customize
MeterStyle=Set.String:S | Set.OptionCat:S | TabSelect[&Func:returnBool('Sec.Page', '1')]
LeftMouseUpAction=[!WriteKeyvalue Variables Sec.Page 1 "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!Refresh]

[Presets]
Meter=String
X=(20*[Set.S])R
Y=r
Text=Presets
MeterStyle=Set.String:S | Set.OptionCat:S | TabSelect[&Func:returnBool('Sec.Page', '2')]
LeftMouseUpAction=[!WriteKeyvalue Variables Sec.Page 2 "#ROOTCONFIGPATH#SecOverrides\ModularClocks\Appearance.inc"][!CommandMeasure Script:M "Restore()"][!Delay 100][!Refresh]

@includePage=Appearance\Page#Sec.Page#.inc
