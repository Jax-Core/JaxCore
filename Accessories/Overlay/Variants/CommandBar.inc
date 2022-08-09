[Rainmeter]
OnUnfocusAction=[!CommandMeasure mActions "Execute 2"]

[Variables]
@includeVars=#@#Vars.inc
Drop.Animation_Time=300
Sec.In=
Sec.Out=
Sec.Ease=
Sec.P=20

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Drop.Animation_Time#
Optional0=Easing InOutCirc
UpdateDivider=1

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 100 | NUOLOn | Start0 | Wait #Drop.Animation_Time#
ActionList2=Rewind0 | Wait #Drop.Animation_Time# | Deactivate
NUOLOn=[!EnableMeasureGroup NUOL]
Start0=[!CommandMeasure mTween "Start(0)"]
Rewind0=[!CommandMeasure mTween "Rewind(0)"]
Deactivate=[!DeactivateConfig]
DynamicVariables=1


[Sec.Button:S]
X=((50/2+5)*#Sec.S#)r
Y=(-50/2*#Sec.S#)r
Shape=Rectangle 0,0,50,50,(#Sec.R#/2) | StrokeWidth 0 | Extend This | Scale #Sec.S#,#Sec.S#,0,0
This=fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorLeave')]
DynamicVariables=1
ColorLeave=100,100,100,100
ColorOver=100,100,100,200
Container=BC
MouseOverAction=[!SetOption #CURRENTSECTION# this "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorOver')]"][!SetOption #Sec.#CURRENTSECTION## FontColor "255,255,255"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# this "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorLeave')]"][!SetOption #Sec.#CURRENTSECTION## FontColor "255,255,255,150"][!UpdateMeter *][!Redraw]
Leftmouseupaction=[!Setvariable "Sec.[&Func:LocalVar('#CURRENTSECTION#', 'Class')]" "[&Func:returnBool('Sec.[&Func:LocalVar('#CURRENTSECTION#', 'Class')]', '[&Func:LocalVar('#CURRENTSECTION#', 'Class')]', '', '[&Func:LocalVar('#CURRENTSECTION#', 'Class')]')]"][!UpdateMeasure EasingValidationCheck2]
[Sec.Button2:S]
X=((-200/2)*#Sec.S#)r
Y=(30/2*#Sec.S#+#Sec.P#/2)r
Shape=Rectangle 0,0,200,30,(#Sec.R#/2) | StrokeWidth 0 | Extend This | Scale #Sec.S#,#Sec.S#,0,0
This=fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorLeave')]
DynamicVariables=1
ColorLeave=100,100,100,100
ColorOver=100,100,100,200
Container=BC
MouseOverAction=[!SetOption #CURRENTSECTION# this "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorOver')]"][!SetOption #Sec.#CURRENTSECTION## FontColor "255,255,255"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# this "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorLeave')]"][!SetOption #Sec.#CURRENTSECTION## FontColor "255,255,255,150"][!UpdateMeter *][!Redraw]
Leftmouseupaction=[!Setvariable "Sec.Ease" "#CURRENTSECTION#"][!UpdateMeasure EasingValidationCheck2]

[Sec.Text:S]
X=(50/2*#Sec.S#)r
Y=(50/2*#Sec.S#)r
DynamicVariables=1
StringAlign=CenterCenter
[Sec.Text2:S]
X=(200/2*#Sec.S#)r
Y=(30/2*#Sec.S#)r
DynamicVariables=1
StringAlign=CenterCenter
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;



[B]
Meter=Shape
X=(#Set.W#/2-(#Set.W#*0.4)/2)
y=(#Set.WinB#/2+#Set.Tb#/2-(#Set.TB#-10)/2)
Shape=Rectangle 0,0,(#Set.W#*0.4),((#Set.TB#-10)+(200-(#Set.TB#-10))*#TweenNode1#),(10) | StrokeWidth 1 | Fill Color #Set.Ter_Color# | Stroke Color #Set.Text_Color#,50
Group=Tweenable
DynamicVariables=1

[BC]
Meter=Shape
X=(#Set.W#/2-(#Set.W#*0.4)/2)
y=(#Set.WinB#/2+#Set.Tb#/2-(#Set.TB#-10)/2)
Shape=Rectangle 0,0,(#Set.W#*0.4),(200*#TweenNode1#),(10) | StrokeWidth 1 | Fill Color 255,255,255
Group=Tweenable
DynamicVariables=1

[KeyLabel]
Meter=String
X=(#Set.W#*0.4/2)
Y=((#Set.TB#-10)/2)
W=(#Set.W#*0.4-#Sec.P#*2)
Clipstring=1
FontSize=(8*#Sec.S#)
FontColor=#Set.SubText_Color#
Text=CommandBar for JaxCore coming soon
StringAlign=CenterCenter
MeterStyle=Sec.String:S

