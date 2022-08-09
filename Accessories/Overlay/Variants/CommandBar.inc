[Rainmeter]
OnUnfocusAction=[!UpdateMeasure UnloadHandler]
Update=-1

[Variables]
@includeVars=#@#Vars.inc
@includeSkinVars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
Drop.Animation_Time=300
Sec.P=20
Sec.ResultSize=30
Process.Result_Count=0

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 200 | StartInput
ActionList2=Deactivate
ActionList3=Deactivate
StartInput=[!CommandMeasure p.InputText "ExecuteBatch 1"]
Start0=[!CommandMeasure mTween "Start(0)"]
Rewind0=[!CommandMeasure mTween "Rewind(0)"]
Deactivate=[!DeactivateConfig]
DynamicVariables=1

[UnloadHandler]
Measure=Calc
Formula=0
IfCondition=UnloadHandler = 1
IfTrueAction=[!CommandMeasure mActions "Execute 2"]
IfConditionMode=1

[p.FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=Blur
Corner=#Set.BlurCorner#
DynamicVariables=1
Border=All

[p.InputText]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Ter_Color#
FontColor=#Set.Text_Color#
FontSize=(10*[Set.S])
StringAlign=LeftBottom
X=(#Set.W#/2-(#Set.W#*0.4)/2+10)
y=(#Set.WinB#/2+#Set.Tb#/2-(#Set.TB#-10)/2+5)
W=((#Set.W#*0.4)-20)
H=((#Set.TB#-10)-7)
OnDismissAction=[!SetOption UnloadHandler Formula 1]
DynamicVariables=1
DefaultValue="Search for setting..."
Command1=[!SetOption UnloadHandler Formula 1][!CommandMeasure p.PowershellRM """SearchForString "$userinput$""""]

[p.PowershellRM]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Searcher.ps1
ExecutionPolicy=Unrestricted

; ---------------------------------------------------------------------------- ;
;                                  mEterStyle                                  ;
; ---------------------------------------------------------------------------- ;

[Sec.String:S]
Container=

[Result.String:S]
X=r
Y=R
W=(#Set.W#*0.4-20)
H=#Sec.ResultSize#
Padding=10,0,10,0
ClipString=2
StringAlign=LeftCenter
SolidColor=0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "#Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
InlineSetting=GradientColor | 45 | #SEt.Accent_Color_2# ; 1 | #Set.Accent_color# ;0
InlineSetting2=Color | #Set.Subtext_Color#
InlineSetting3=Size | (8)
Group=Results
Hidden=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Overlay]
Meter=String
W=(#Set.W#+#Set.WinB#)
H=(#Set.H#+#Set.WinB#)
SolidColor=0,0,0,150
Leftmouseupaction=[!CommandMeasure mActions "Execute 2"]
MouseActionCursor=0

[B]
Meter=Shape
X=(#Set.W#/2-(#Set.W#*0.4)/2)
y=(#Set.WinB#/2+#Set.Tb#/2-(#Set.TB#-10)/2)
Shape=Rectangle 0,0,(#Set.W#*0.4),((#Set.TB#-10)+#Sec.ResultSize#*#Process.Result_Count#+20*(Clamp(#Process.Result_Count#,0,1))),(10) | StrokeWidth 1 | Fill Color #Set.Ter_Color# | Stroke Color #Set.Text_Color#,50
Group=Tweenable
Leftmouseupaction=[""]
DynamicVariables=1
MouseActionCursor=0

[InputLabel]
Meter=String
X=(#Set.W#/2-(#Set.W#*0.4)/2+10)
y=(#Set.WinB#/2+#Set.Tb#/2-(#Set.TB#-10)/2+5)
W=((#Set.W#*0.4)-20)
H=((#Set.TB#-10)-10)
Clipstring=1
FontSize=(8*#Sec.S#)
FontColor=#Set.SubText_Color#
Text=Search for a setting...
Leftmouseupaction=[!SetOption UnloadHandler Formula 0][!CommandMeasure p.InputText "ExecuteBatch 1"][!HideMeterGroup Results][!Redraw]
MeterStyle=Sec.String:S

; ---------------------------------- Results --------------------------------- ;

[Result1]
Meter=String
X=(-10)r
Y=((#Set.TB#-10)-5+#Sec.ResultSize#/2+10)r
MeterStyle=Sec.String:S | Result.String:S
[Result2]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result3]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result4]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result5]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result6]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result7]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result8]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result9]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result10]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result11]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result12]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result13]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result14]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result15]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result16]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result17]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result18]
Meter=String
MeterStyle=Sec.String:S | Result.String:S
[Result19]
Meter=String
MeterStyle=Sec.String:S | Result.String:S

