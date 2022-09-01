[Rainmeter]
OnUnfocusAction=[!UpdateMeasure UnloadHandler]
Update=-1

[Variables]
@includeVars=#@#Vars.inc
@includeSkinVars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
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

[Title]
Meter=String
X=(#Set.W#/2)
Y=(#Set.H#/2)
W=(#Set.W#)
StringAlign=CenterCenter
Text=Installer not working? Click me
Leftmouseupaction=["https://wiki.jaxcore.app/getting-started/faqs/jaxcore-faqs#in-app-installer"]
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
MEterStyle=Sec.String:S
