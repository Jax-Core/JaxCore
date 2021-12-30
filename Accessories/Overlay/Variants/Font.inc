; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
[Rainmeter]
OnUnfocusAction=[!UpdateMeasure UnloadHandler2]

[Variables]
@includeVars=#@#Vars.inc
Drop.Animation_Time=300

Sec.Input=

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Drop.Animation_Time#
Optional0=Easing InOutCirc
UpdateDivider=1

[UnloadHandler1]
Measure=String
String=0
Ifmatch=0
ifmatchaction=[!CommandMeasure mActions "Execute 2"][!SetOptionGroup Handler String 1]
ifnotmatchaction=
IfMatchMode=1
Group=NUOL | Handler
disabled=1

[UnloadHandler2]
Measure=String
String=0
Ifmatch=0
ifmatchaction=[!CommandMeasure mActions "Execute 3"][!SetOption Handler String 1]
ifnotmatchaction=
IfMatchMode=1
Group=NUOL | Handler
disabled=1

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 100 | NUOLOn | Start0 | Wait #Drop.Animation_Time#
ActionList2=Custom2 | Rewind0 | Wait #Drop.Animation_Time# | Deactivate
ActionList3=Rewind0 | Wait #Drop.Animation_Time# | Deactivate
NUOLOn=[!EnableMeasureGroup NUOL]
Start0=[!CommandMeasure mTween "Start(0)"]
Rewind0=[!CommandMeasure mTween "Rewind(0)"]
Custom2=[!WriteKeyvalue Variables #Sec.Num# "#Sec.Input#" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M "#JaxCore\Main"][!Refresh "#JaxCore\Main"]
Deactivate=[!DeactivateConfig]
Group=Key
DynamicVariables=1


[Sec.Div]
Shape=Line 0,0,(#Sec.W#-#sec.P#*2),0 | StrokeWidth 2 | Stroke Color 255,255,255,50 | StrokeStartCap Round | StrokeEndCap Round
X=r
Y=(#sec.P#)R
Container=BC
[Sec.Text:S]
X=r
Y=(#Sec.P#)R
FontFace=#CURRENTSECTION#
FontSize=(20*#Sec.S#)
Text=12:34 JaxCore | #CURRENTSECTION#
Inlinepattern=\| #CURRENTSECTION#
InlineSetting=Size | (10*#Sec.S#)
Inlinepattern2=\| #CURRENTSECTION#
InlineSetting2=Face | #Set.Font#
LeftMouseUpAction=[!SetVariable Sec.Input "#CURRENTSECTION#"][!UpdateMeasure UnloadHandler1][!UpdateMeasure mActions]
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;



[BC]
Meter = Shape
Shape=Rectangle (#Sec.W#*(1-#TweenNode1#)),0,(#Sec.W#*#TweenNode1#),(#Sec.H#) | StrokeWidth 0 | Fill Color #Set.Ter_Color#
Group=Tweenable
DynamicVariables=1

[B]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#),#Sec.R# | StrokeWidth 0 | Fill Color #Set.Ter_Color#
Container=BC

[KeyLabel]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
FontSize=(10*#Sec.S#)
FontColor=#Set.Text_Color#,150
Text=Font List
StringAlign=Center
MeterStyle=Sec.String:S

[Takota]
Meter=String
X=#sec.P#
Y=R
MeterStyle=Sec.String:S | Sec.Text:S
[Div:0]
Meter=Shape
MeterStyle=Sec.Div

[Segoe UI]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:1]
Meter=Shape
MeterStyle=Sec.Div

[SF Pro Rounded]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:2]
Meter=Shape
MeterStyle=Sec.Div

[Roboto]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:3]
Meter=Shape
MeterStyle=Sec.Div

[Poppins]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:4]
Meter=Shape
MeterStyle=Sec.Div

; [Poppins Light]
; Meter=String
; MeterStyle=Sec.String:S | Sec.Text:S
; [Div:5]
; Meter=Shape
; MeterStyle=Sec.Div

; [Balsamiq Sans]
; Meter=String
; MeterStyle=Sec.String:S | Sec.Text:S
; [Div:6]
; Meter=Shape
; MeterStyle=Sec.Div

[Atami]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:7]
Meter=Shape
MeterStyle=Sec.Div

[Atami Stencil]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:8]
Meter=Shape
MeterStyle=Sec.Div

[Atami Display]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S
[Div:7]
Meter=Shape
MeterStyle=Sec.Div

[Segoe UI]
Meter=String
MeterStyle=Sec.String:S | Sec.Text:S

[KeyLabel2]
Meter=String
X=(#Sec.W#/2)
Y=(#SEc.h#-#Sec.P#)
FontSize=(10*#Sec.S#)
FontColor=#Set.Text_Color#,150
Text=Tip: right click the text field to specify a font
StringAlign=CenterBottom
MeterStyle=Sec.String:S