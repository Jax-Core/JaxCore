[Rainmeter]
DynamicWindowSize=1
AccurateText=1
OnRefreshAction=[!FadeDuration 250][!KeepOnScreen 0][!Delay 100][!EnableMeasureGroup NUOL][!DisableMouseActionGroup * Unreleased]

[Variables]
@includeCoreVars=#@#Vars.inc
; ----------------------------- Default variables ---------------------------- ;
Scroll=0
Sec.Container=ContentContainer
@includeVer=#@#Version.inc

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;


@IncludeWindow=#@#Includes/Window.ini
@IncludeMouse=#@#Includes/ScriptMouseHandler.ini

; [FrostedGlass]
; Measure=Plugin
; Plugin=FrostedGlass
; Type=Blur
; Border=All

[Func]
Measure=Script
ScriptFile=#@#Lua\Name.lua

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
FontColor=#Set.Text_Color#
FontFace=Seqoe UI
FontSize=(10*[Set.S])
StringAlign=LeftCenter
W=((150-10)*[Set.S])
H=((30-10)*[Set.S])
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

; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

[Set.String:S]
FontFace=Poppins Regular
AntiAlias=1
FontSize=(12*[Set.S])
FontColor=#Set.Text_Color#
Container=#Sec.Container#
SolidColor=0,0,0,1
DynamicVariables=1
[Set.OptionCat:S]
X=(30*[Set.S])
Y=(30*[Set.S])R
FontSize=(14*[Set.S])
FontWeight=500
[Set.OptionName:S]
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])

; ---------------------------------- Generic --------------------------------- ;




[Set.Div:S]
X=r
y=(15*[Set.S])R
Container=#Sec.Container#
Shape=Line 0,0,(#Set.W#-#Set.L#-#Set.P#*3),0 | StrokeWidth 1 | Fill Color #Set.Pri_Color#,0 | Stroke Color #Set.Text_Color#,25

[Set.TextBox:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
Container=#Sec.Container#
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Stroke Color #Set.Text_Color#,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 1"]
[Set.Value:S]
X=(5*[Set.S])r
Y=(15*[Set.S])r
StringAlign=LeftCenter
FontSize=(10*[Set.S])
DynamicVariables=1

[Set.Bool:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-50)
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-20/2+8)*[Set.S])
Shape=Rectangle 0,0,50,20,10,10 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Shape2=Ellipse ([##CURRENTSECTION#] = 1 ? (40*[Set.S]) : (10*[Set.S])),(10*[Set.S]),(5*[Set.S]),(5*[Set.S]) | StrokeWidth 0 | Fill Color #Set.Text_Color#
DynamicVariables=1
Fill=Fill Color ([##CURRENTSECTION#] = 1 ? 35 : 181),([##CURRENTSECTION#] = 1 ? 209 : 181),([##CURRENTSECTION#] = 1 ? 96 : 181)
Container=#Sec.Container#
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]




; ---------------------------------- Colors ---------------------------------- ;




[Set.Color:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color [##CURRENTSECTION#] | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Stroke Color #Set.Text_Color#,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,15"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
SomeAction=[!Log Update]
Container=#Sec.Container#

[Set.Grad0:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
DynamicVariables=1
Shape=Rectangle 0,0,75,30,3,3 | StrokeWidth 0 | Fill LinearGradient Grad | Scale [Set.S],[Set.S],0,0
Grad=180 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad0')]] ; 0.0 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad1')]] ; 2
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=[&Func:GroupVar('#CURRENTSECTION#', 'Grad0')]" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=#Sec.Container#
[Set.Grad1:S]
X=r
Y=r
DynamicVariables=1
Shape=Rectangle 75,0,75,30,3,3 | StrokeWidth 0 | Fill LinearGradient Grad | Scale [Set.S],[Set.S],0,0
Grad=180 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad0')]] ; -1 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad1')]] ; 1
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=[&Func:GroupVar('#CURRENTSECTION#', 'Grad1')]" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=#Sec.Container#




; ------------------------------ Action buttons ------------------------------ ;




[Set.Button:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*[Set.S])
; Y=([&Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=100,100,100,200
LeaveColor=100,100,100,100
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[&Func:LocalVar('#CURRENTSECTION#', 'Act')]
Container=#Sec.Container#




; --------------------------------- 2 picker --------------------------------- ;




[Set.Pick:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-300*[Set.S])
Shape=Rectangle 0,0,300,35,7 | StrokeWidth 2 | Extend Fill | Scale [Set.S],[Set.S],0,0 | Stroke Color #Set.Text_Color#
Fill=Fill Color #Set.Text_Color#,25
Shape2=Rectangle ([#[&Func:GroupVar('#CURRENTSECTION#')]] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(35*[Set.S]),(7*[Set.S]) | Fill Color 255,255,255 | StrokeWidth 0 |
DynamicVariables=1
Container=#Sec.Container#
[Set.PickOption_0:S]
X=(300/4*[Set.S])r
Y=(35/2*[Set.S])r
Padding=(300/6*[Set.S]),(35/4*[Set.S]),(300/6*[Set.S]),(35/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
[Set.PickOption_1:S]
X=(300/2*[Set.S])r
Y=r
Padding=(300/6*[Set.S]),(35/4*[Set.S]),(300/6*[Set.S]),(35/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter




; --------------------------------- Dropdown --------------------------------- ;




[Set.DropDown:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150*[Set.S])
NumOfOption=2
Group=DropDown
Container=#Sec.Container#
DynamicVariables=1
Fill=Stroke Color #Set.Text_Color#,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Set.DD0]
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale [Set.S],[Set.S],0,0
LeftMouseupaction=[!SetOption #CURRENTSECTION# MeterStyle "Set.DropDown:S | Set.DD1"][!ShowMeterGroup "DD[&Func:LocalVar('#CURRENTSECTION#', 'Index')]"][!HideMeterGroup "DDNo[&Func:LocalVar('#CURRENTSECTION#', 'Index')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Set.DD1]
Shape=Rectangle 0,0,150,(30*[&Func:LocalVar('#CURRENTSECTION#', 'NumOfOption')]),3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale [Set.S],[Set.S],0,0
LeftMouseupaction=[!SetOption #CURRENTSECTION# MeterStyle "Set.DropDown:S | Set.DD0"][!HideMeterGroup "DD[&Func:LocalVar('#CURRENTSECTION#', 'Index')]"][!ShowMEterGroup DD0][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Set.DropText:S]
X=r
Y=(15*[Set.S])r
StringAlign=LeftCenter
Hidden=1
FontSize=(10*[Set.S])
DynamicVariables=1




; ------------------------------- Side buttons ------------------------------- ;




[PageBox:S]
X=#Set.P#
Y=((24/2*[Set.S])+#Set.P#/1.5)r
Shape=Rectangle 0,0,(#Set.L#-#Set.P#*2),(#Set.P#+(24-4)*[Set.S]),(#Set.R#/4),(#Set.R#/4) | StrokeWidth 0 | Extend This
Leftmouseupaction=[!WriteKeyvalue Variables "Skin.Set_Page" "#CURRENTSECTION#" "#@#SecVar.inc"][!Refresh]
This=Fill LinearGradient 1232412414
1232412414=180 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],(#BarHandler# = [&Func:LocalVar('#CURRENTSECTION#', 'Handle')] ? 220 : 0) ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')] ; 1.0
Grad.0=255,255,255
Grad.1=255,255,255
OverColor=150
LeaveColor=0
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# 1232412414 "180 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],(#BarHandler# = [&Func:LocalVar('#CURRENTSECTION#', 'Handle')] ? 220 : 0) ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'OverColor')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# 1232412414 "180 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],(#BarHandler# = [&Func:LocalVar('#CURRENTSECTION#', 'Handle')] ? 220 : 0) ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Group=Set.SideButtons
[PageIcon:S]
ImageName=#@#Icons\Settings\#CURRENTSECTION#.png
X=(#Set.P#*1.5)
Y=(((#Set.P#+(24-4)*[Set.S])/2-24/2*[Set.S]))r
W=(24*[Set.S])
H=(24*[Set.S])
DynamicVariables=1
ImageAlpha=200
Group=Set.SideButtons | Set.SideIcons
[PageText:S]
X=(5*[Set.S])R
Y=(24/2*[Set.S])r
Container=
StringAlign=LeftCenter
FontColor=(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 255 : 200)
FontSize=(10*[Set.S])
Group=Set.SideButtons




; ------------------------------- Over actions ------------------------------- ;




[Shape.Over:S]
This=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
OverColor=#Set.Ter_Color#
LeaveColor=#Set.Sec_Color#
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Shape.Over_Grad:S]
This=Fill LinearGradient 1232412414
1232412414=180 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],0 ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')] ; 1.0
Grad.0=255,255,255
Grad.1=255,255,255
OverColor=150
LeaveColor=100
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# 1232412414 "180 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],0 ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'OverColor')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# 1232412414 "180 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],0 ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]




; ---------------------------------------------------------------------------- ;
;                                   Examples                                   ;
; ---------------------------------------------------------------------------- ;

;; BOOL EXMAPLE
; [BoolVarName]
; Meter=Shape
; MeterStyle=Set.Bool:S
; Y=([VarOption:Y]-#Set.P#+(-20/2+8)*[Set.S])

;; TEXT INPUT EXAMPLE
; [TextVarName]
; Meter=Shape
; MeterStyle=Set.TextBox:S
; Y=([VarOption:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [VarOptionNumber]
; Meter=String
; Text=TextVarName
; MeterStyle=Set.String:S | Set.Value:S


; ---------------------------------------------------------------------------- ;
;                                 Close button                                 ;
; ---------------------------------------------------------------------------- ;


; [Esc]
; Meter=Shape
; Shape=Ellipse (#Set.W#-15*[Set.S]),(15*[Set.S]),(5*[Set.S]),(5*[Set.S]) | StrokeWidth 10 | StrokeColor 0,0,0,1 | Extend FillE
; FillE=Fill Color #Set.Text_Color#,50
; MouseOverAction=[!SetOption Esc FillE "Fill Color #Set.Text_Color#"][!UpdateMeter Esc][!Redraw]
; MouseLeaveAction=[!SetOption Esc FillE "Fill Color #Set.Text_Color#,50"][!UpdateMeter Esc][!Redraw]
; LeftMouseUpAction=[!DeactivateConfig]
