; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
[Rainmeter]
OnUnfocusAction=[!UpdateMeasure UnloadHandler2]

[Variables]
@includeVars=#@#Vars.inc
Drop.Animation_Time=300
Sec.In=
Sec.Out=
Sec.Ease=

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
ifmatchaction=[!UpdateMeasure mActions][!CommandMeasure mActions "Execute 2"][!SetOptionGroup Handler String 1]
ifnotmatchaction=
IfMatchMode=1
Group=NUOL | Handler
disabled=1

[UnloadHandler2]
Measure=String
String=0
Ifmatch=0
ifmatchaction=[!UpdateMeasure mActions][!CommandMeasure mActions "Execute 3"][!SetOption Handler String 1]
ifnotmatchaction=
IfMatchMode=1
Group=NUOL | Handler
disabled=1

[EasingValidationCheck]
Measure=String
String=#Sec.In##Sec.Out#
ifMatch=$^
ifmatchaction=[!Setvariable "Sec.In" "In"][!UpdateMeter *][!Redraw]
ifnotmatchaction=[!UpdateMeter *][!Redraw]
IfMatchMode=1
DynamicVariables=1
[EasingValidationCheck2]
Measure=String
String=#Sec.Ease#
ifMatch=^Linear$
ifmatchaction=[!Setvariable "Sec.In" ""][!Setvariable "Sec.Out" ""][!UpdateMeter *][!Redraw]
ifnotmatchaction=[!UpdateMeasure EasingValidationCheck]
IfMatchMode=1
DynamicVariables=1

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 100 | NUOLOn | Start0 | Wait #Drop.Animation_Time#
ActionList2=Custom2 | Rewind0 | Wait #Drop.Animation_Time# | Deactivate
ActionList3=Rewind0 | Wait #Drop.Animation_Time# | Deactivate
NUOLOn=[!EnableMeasureGroup NUOL]
Start0=[!CommandMeasure mTween "Start(0)"]
Rewind0=[!CommandMeasure mTween "Rewind(0)"]
Custom2=[!WriteKeyvalue Variables Easetype#Sec.Num# "#Sec.In##Sec.Out##Sec.Ease#" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M "#JaxCore\Main"][!Refresh "#JaxCore\Main"]
Deactivate=[!DeactivateConfig]
Group=Key
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
Text=Configuring animation's easing type
StringAlign=Center
MeterStyle=Sec.String:S

[KeyLabelOverlap]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#*0.3)
FontSize=(20*#Sec.S#)
Text=#Sec.In##Sec.Out##Sec.Ease#
Prefix="> "
Postfix=" <"
DynamicVariables=1
StringAlign=CenterCenter
MeterStyle=Sec.String:S

[Shape1]
Meter=Shape
X=((#Sec.W#-#Sec.P#*2)/2-(50*2+5*1)*#Sec.S#/2+#sec.P#)
Y=(#Sec.H#*0.2)
Class="In"
MeterStyle=Sec.Button:S
[Text1]
Meter=String
Text=In
MEterStyle=Sec.String:S | Sec.Text:S
[Shape2]
Meter=Shape
Class="Out"
MeterStyle=Sec.Button:S
[Text2]
Meter=String
Text=Out
MEterStyle=Sec.String:S | Sec.Text:S


[Linear]
Meter=Shape
X=(#Sec.W#/2-200*#Sec.S#/2)
Y=(#Sec.H#*0.4)
MeterStyle=Sec.Button2:S
[LinearText]
Meter=String
Text=Linear
MEterStyle=Sec.String:S | Sec.Text2:S
[Sine]
Meter=Shape
MeterStyle=Sec.Button2:S
[SineText]
Meter=String
Text=Sine
MEterStyle=Sec.String:S | Sec.Text2:S
[Quad]
Meter=Shape
MeterStyle=Sec.Button2:S
[QuadText]
Meter=String
Text=Quad
MEterStyle=Sec.String:S | Sec.Text2:S
[Cubic]
Meter=Shape
MeterStyle=Sec.Button2:S
[CubicText]
Meter=String
Text=Cubic
MEterStyle=Sec.String:S | Sec.Text2:S
[Quart]
Meter=Shape
MeterStyle=Sec.Button2:S
[QuartText]
Meter=String
Text=Quart
MEterStyle=Sec.String:S | Sec.Text2:S
[Quint]
Meter=Shape
MeterStyle=Sec.Button2:S
[QuintText]
Meter=String
Text=Quint
MEterStyle=Sec.String:S | Sec.Text2:S
[Expo]
Meter=Shape
MeterStyle=Sec.Button2:S
[ExpoText]
Meter=String
Text=Expo
MEterStyle=Sec.String:S | Sec.Text2:S
[Circ]
Meter=Shape
MeterStyle=Sec.Button2:S
[CircText]
Meter=String
Text=Circ
MEterStyle=Sec.String:S | Sec.Text2:S
[Back]
Meter=Shape
MeterStyle=Sec.Button2:S
[BackText]
Meter=String
Text=Back
MEterStyle=Sec.String:S | Sec.Text2:S
[Elastic]
Meter=Shape
MeterStyle=Sec.Button2:S
[ElasticText]
Meter=String
Text=Elastic
MEterStyle=Sec.String:S | Sec.Text2:S
[Bounce]
Meter=Shape
MeterStyle=Sec.Button2:S
[BounceText]
Meter=String
Text=Bounce
MEterStyle=Sec.String:S | Sec.Text2:S


[ShapeConfirm]
Meter=Shape
X=((#Sec.W#-#Sec.P#*2)/2-(100*2+5*1)*#Sec.S#/2+#sec.P#)
Shape=Rectangle 0,0,100,40,(#Sec.R#/2) | StrokeWidth 0 | Extend This | Scale #Sec.S#,#Sec.S#,0,0
Y=(#Sec.H#-40*#Sec.S#-#Sec.p#)
Leftmouseupaction=[!UpdateMeasure UnloadHandler1]
ColorLeave=0,100,0,100
ColorOver=0,100,0,200
MeterStyle=Sec.Button:S
[TextConfirm]
Meter=String
X=(100/2*#Sec.S#)r
Y=(40/2*#Sec.S#)r
Text=Confirm
MEterStyle=Sec.String:S | Sec.Text:S
[ShapeWhat]
Meter=Shape
X=((100/2)*#Sec.S#+#Sec.P#/2)r
Y=(-40/2*#Sec.S#)r
Shape=Rectangle 0,0,100,40,(#Sec.R#/2) | StrokeWidth 0 | Extend This | Scale #Sec.S#,#Sec.S#,0,0
Leftmouseupaction=["https://easings.net/"]
ColorLeave=#Set.Accent_Color#,100
ColorOver=#Set.Accent_Color#,200
MeterStyle=Sec.Button:S
[TextWhat]
Meter=String
X=(100/2*#Sec.S#)r
Y=(40/2*#Sec.S#)r
Text=Graph / List
MEterStyle=Sec.String:S | Sec.Text:S