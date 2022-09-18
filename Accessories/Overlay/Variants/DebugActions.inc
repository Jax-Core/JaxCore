[Rainmeter]
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
ActionList1=Null
ActionList2=Deactivate
Deactivate=[!DeactivateConfig]
DynamicVariables=1

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
DynamicVariables=1

[Act.Shape:S]
X=(#Set.W#*0.2+20*[Set.S])
Y=(40*[Set.S])r
Shape=Rectangle 0,0,(#Set.W#*0.6-40*[Set.S]),(60*[Set.S]),(5*[Set.S]) | StrokeWidth 0 | Extend Stroke
Stroke=Fill Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.SubText_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
[Act.String:S]
DynamicVariables=1
X=(10*[Set.S])r
Y=(30*[Set.S])r
W=
H=
FontSize=(18*[Set.S])
StringAlign=LeftCenter
FontFace=Material Icons Round
[Act.Des.String:S]
X=(10*[Set.S])R
Y=r
StringAlign=LeftCenter
DynamicVariables=1

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



; ---------------------------------------------------------------------------- ;
;                                 Debug actions                                ;
; ---------------------------------------------------------------------------- ;
; -------------------------------- Open folder ------------------------------- ;
[Item5.Act1.Shape]
Meter=Shape
Y=(20*[Set.S])
LeftMouseUpAction=["#SKINSPATH##Skin.Name#\"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Act.Shape:S
[Item5.Act1.String]
Meter=String
Text=[\xe2c8]
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act1.Des.String]
Meter=String
Text=To directory
MEterStyle=Sec.String:S | Act.Des.String:S
; -------------------------------- Config file ------------------------------- ;
[Item5.Act2.Shape]
Meter=Shape
LeftMouseUpAction=["#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Act.Shape:S
[Item5.Act2.String]
Meter=String
Text=[\xe8b8]
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act2.Des.String]
Meter=String
Text=To config file
MEterStyle=Sec.String:S | Act.Des.String:S
; --------------------------------- Clear rm --------------------------------- ;
[Item5.Act3.Shape]
Meter=Shape
LeftMouseUpAction=[!DeactivateConfig "#Skin.name#\Main"][!CommandMeasure CoreInstallHandler "Remove-Section #Skin.Name#" "#JaxCore\Main"][!UpdateMeasure m.ConfigActive "#JaxCore\Main"][!UpdateMeter * "#JaxCore\Main"][!Redraw "#JaxCore\Main"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Act.Shape:S
[Item5.Act3.String]
Meter=String
Text=[\xe0b8]
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act3.Des.String]
Meter=String
Text=Clear ini data
MEterStyle=Sec.String:S | Act.Des.String:S
; ------------------------------- Reset wizard ------------------------------- ;
[Item5.Act4.Shape]
Meter=Shape
LeftMouseUpAction=[!WriteKeyValue Variables Core.Welcomecheck 0 "#SKINSPATH##SKin.Name#\@Resources\WelcomeVar.inc"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Act.Shape:S
[Item5.Act4.String]
Meter=String
Text=[\xf0fc]
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act4.Des.String]
Meter=String
Text=Clear setup wizard data
MEterStyle=Sec.String:S | Act.Des.String:S
; --------------------------------- Rollback --------------------------------- ;
[Item5.Act5.Shape]
Meter=Shape
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('Rollback', '#SKIN.NAME#', '#Version#')"][!CommandMeasure mActions "Execute 2"]
Group=HideIsClone
MeterStyle=Act.Shape:S
[Item5.Act5.String]
Meter=String
Text=[\xf001]
Group=HideIsClone
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act5.Des.String]
Meter=String
Text=Downgrade
Group=HideIsClone
MEterStyle=Sec.String:S | Act.Des.String:S
; --------------------------------- Close ahk -------------------------------- ;
[Item5.Act6.Shape]
Meter=Shape
LeftMouseUpAction=["#SKINSPATH##Skin.Name#\@Resources\Actions\AHKv1.exe" "#SKINSPATH##Skin.Name#\@Resources\Actions\Source Code\Close.ahk"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Act.Shape:S
[Item5.Act6.String]
Meter=String
Text=[\xe5cd]
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act6.Des.String]
Meter=String
Text=Close AHK process
MEterStyle=Sec.String:S | Act.Des.String:S

; --------------------------------- Uninstall -------------------------------- ;
[Item5.Act7.Shape]
Meter=Shape
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('Uninstall', '#SKIN.NAME#')"][!DeactivateConfig "#Skin.Name#\Main"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Act.Shape:S
[Item5.Act7.String]
Meter=String
Text=[\xe92b]
MEterStyle=Sec.String:S | Act.String:S
[Item5.Act7.Des.String]
Meter=String
Text=Uninstall
MEterStyle=Sec.String:S | Act.Des.String:S

[Anchor]
Meter=String
Y=(40*[SEt.S])r
DynamicVariables=1
