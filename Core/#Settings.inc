
[Variables]

; Set.S=0.9
Set.S=(#SCREENAREAWIDTH#/1920)
Set.P=(20*#Set.S#)
Set.R=(20*#Set.S#)
Set.W=(1200*#Set.S#)
Set.H=(740*#Set.S#)
Set.L=(200*#Set.S#)

Set.Color=0
Set.Pri_Color=19, 19, 19
Set.Sec_Color=23,23,23
Set.Ter_Color=30, 30, 30
Set.Opp_Color=255,255,255
Set.Shadow=125,125,125
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars.inc

Set.Auto_Refresh=1
Set.Background_Check_MS=60000
;Size, Pad, Round, Width, Height, ListWidth

Scroll=0
Sec.Container=ContentContainer
;METERSTYLES===========================================================================================
;METERSTYLES===========================================================================================

[Set.String:S]
FontFace=Roboto
AntiAlias=1
FontSize=(12*#Set.S#)
FontColor=#Set.Opp_Color#
Container=#Sec.Container#
SolidColor=0,0,0,1

[Set.Div:S]
X=r
y=(15*#Set.S#)R
Container=#Sec.Container#
Shape=Line 0,0,(#Set.W#-#Set.L#-#Set.P#*3),0 | StrokeWidth 1 | Fill Color #Set.Pri_Color#,0 | Stroke Color #Set.Opp_Color#,25

[Set.TextBox:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*#Set.S#)
Container=#Sec.Container#
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale #Set.S#,#Set.S#,0,0
Fill=Stroke Color #Set.Opp_Color#,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Opp_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Opp_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 1"]
[Set.Value:S]
X=(5*#Set.S#)r
Y=(15*#Set.S#)r
StringAlign=LeftCenter
FontSize=(10*#Set.S#)
DynamicVariables=1

[Set.Bool:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-50)
Shape=Rectangle 0,0,50,20,10,10 | StrokeWidth 0 | Extend Fill | Scale #Set.S#,#Set.S#,0,0
Shape2=Ellipse ([##CURRENTSECTION#] = 1 ? (40*#Set.S#) : (10*#Set.S#)),(10*#Set.S#),(5*#Set.S#),(5*#Set.S#) | StrokeWidth 0 | Fill Color #Set.Opp_Color#
DynamicVariables=1
Fill=Fill Color ([##CURRENTSECTION#] = 1 ? 35 : 181),([##CURRENTSECTION#] = 1 ? 209 : 181),([##CURRENTSECTION#] = 1 ? 96 : 181)
Container=#Sec.Container#
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]

[Set.Color:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*#Set.S#)
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color [##CURRENTSECTION#] | Extend Fill | Scale #Set.S#,#Set.S#,0,0
Fill=Stroke Color #Set.Opp_Color#,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Opp_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Opp_Color#,15"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
SomeAction=[!Log Update]
Container=#Sec.Container#

[Set.Grad0:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*#Set.S#)
DynamicVariables=1
Shape=Rectangle 0,0,75,30,3,3 | StrokeWidth 0 | Fill LinearGradient Grad | Scale #Set.S#,#Set.S#,0,0
Grad=180 | [#[&Jax.Func:secVLocalGroup('#CURRENTSECTION#', 'Grad0')]] ; 0.0 | [#[&Jax.Func:secVLocalGroup('#CURRENTSECTION#', 'Grad1')]] ; 2
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=[&Jax.Func:secVLocalGroup('#CURRENTSECTION#', 'Grad0')]" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=#Sec.Container#
[Set.Grad1:S]
X=r
Y=r
DynamicVariables=1
Shape=Rectangle 75,0,75,30,3,3 | StrokeWidth 0 | Fill LinearGradient Grad | Scale #Set.S#,#Set.S#,0,0
Grad=180 | [#[&Jax.Func:secVLocalGroup('#CURRENTSECTION#', 'Grad0')]] ; -1 | [#[&Jax.Func:secVLocalGroup('#CURRENTSECTION#', 'Grad1')]] ; 1
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=[&Jax.Func:secVLocalGroup('#CURRENTSECTION#', 'Grad1')]" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=#Sec.Container#


[Set.Button:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*#Set.S#)
OverColor=100,100,100,200
LeaveColor=100,100,100,100
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale #Set.S#,#Set.S#,0,0
Fill=Fill Color [&Jax.Func:secVCurrentSec('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Jax.Func:secVCurrentSec('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Jax.Func:secVCurrentSec('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[&Jax.Func:secVCurrentSec('#CURRENTSECTION#', 'Act')]
Container=#Sec.Container#

[Set.Pick:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-300*#Set.S#)
Shape=Rectangle 0,0,300,35,7 | StrokeWidth 2 | Extend Fill | Scale #Set.S#,#Set.S#,0,0 | Stroke Color #Set.Opp_Color#
Fill=Fill Color #Set.Opp_Color#,25
Shape2=Rectangle ([#[&Jax.Func:secVLocalGroup('#CURRENTSECTION#')]] = 0 ? 0 : (150*#Set.S#)),0,(150*#Set.S#),(35*#Set.S#),(7*#set.S#) | Fill Color 255,255,255 | StrokeWidth 0 |
DynamicVariables=1
Container=#Sec.Container#
[Set.PickOption_0:S]
X=(300/4*#Set.S#)r
Y=(35/2*#Set.S#)r
Padding=(300/6*#Set.S#),(35/4*#Set.S#),(300/6*#Set.S#),(35/4*#Set.S#)
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables [&Jax.Func:secVLocalGroup('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Jax.Func:secVLocalGroup('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
[Set.PickOption_1:S]
X=(300/2*#Set.S#)r
Y=r
Padding=(300/6*#Set.S#),(35/4*#Set.S#),(300/6*#Set.S#),(35/4*#Set.S#)
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables [&Jax.Func:secVLocalGroup('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Jax.Func:secVLocalGroup('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter



[PageBox:S]
X=#Set.P#
Y=((24/2*#Set.S#)+#Set.P#/1.5)r
Shape=Rectangle 0,0,(#Set.L#-#Set.P#*2),(#Set.P#+(24-4)*#Set.S#),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Extend Fill
Leftmouseupaction=[!WriteKeyvalue Variables "Skin.Set_Page" "#CURRENTSECTION#" "#@#SecVar.inc"][!Refresh]
DynamicVariables=1
Group=Set.SideButtons
[PageIcon:S]
ImageName=#@#Icons\Settings\#CURRENTSECTION#.png
X=(#Set.P#*1.5)
Y=(((#Set.P#+(24-4)*#Set.S#)/2-24/2*#Set.S#))r
W=(24*#Set.S#)
H=(24*#Set.S#)
DynamicVariables=1
ImageAlpha=200
Group=Set.SideButtons | Set.SideIcons
[PageText:S]
X=(5*#Set.S#)R
Y=(24/2*#Set.S#)r
Container=
StringAlign=LeftCenter
FontColor=(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 255 : 200)
FontSize=(10*#Set.S#)
Group=Set.SideButtons

;; BOOL EXMAPLE
; [BoolVarName]
; Meter=Shape
; MeterStyle=Set.Bool:S
; Y=([VarOption:Y]-#Set.P#+(-20/2+8)*#Set.S#)

;; TEXT INPUT EXAMPLE
; [TextVarName]
; Meter=Shape
; MeterStyle=Set.TextBox:S
; Y=([VarOption:Y]-#Set.P#+(-30/2+8)*#Set.S#)
; [VarOptionNumber]
; Meter=String
; Text=TextVarName
; MeterStyle=Set.String:S | Set.Value:S

;STUFF===========================================================================================
;STUFF===========================================================================================

[Auto_Refresh:M]
Measure=String
String=#Set.Auto_Refresh#
IFMatch=1
Ifmatchaction=[!Delay 500][!Refresh "#Skin.Name#\Main"]
IfMatchMode=1
Group=NUOL
Disabled=1

[Set.Get_Shorthand:M]
Measure=Script
ScriptFile=#@#Lua\GetShorthand.lua

[Set.Toolbar:M]
Measure=Plugin
Plugin=ShowInToolbar
WindowTitle=Jax.O /#Skin.Name#
WindowIcon=#@#Images\Logo.ico

[Input:M]
Measure=Plugin
Plugin=InputText
SolidColor=171717
FontColor=#Set.Opp_Color#
FontFace=Seqoe UI
FontSize=(10*#Set.S#)
StringAlign=LeftCenter
W=((150-10)*#Set.S#)
H=((30-10)*#Set.S#)
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad:M]

[SaveAndLoad:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#Sec.SaveLocation#"][!UpdateMeter *][!Redraw][!UpdateMeasure Auto_Refresh:M]
; OnUpdateAction=[!Log "Yes"]
Disabled=1
Group=NUOL
