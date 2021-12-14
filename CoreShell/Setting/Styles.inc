[Rainmeter]
DynamicWindowSize=1
AccurateText=1
OnRefreshAction=[!CommandMeasure DefaultStartActions "Execute 1"]
DefaultFadeDuration=100
DefaultKeepOnscreen=1

[Focus]
Measure=Plugin
Plugin=Focus
FocusOnRefresh=1

; [ColorPicker]
; Measure=Script
; ScriptFile=#ROOTCONFIGPATH#ColorPickerUI\ColorPickerUI.lua
; Theme=Core
; Animations=0
; FinishAction=[!Log "Successfully changed $section$'s $option$ to $color$!"][!UpdateMeasure Auto_Refresh:M]
; DismissAction=[!Log "$section$'s $option$ didn't change!"] 

[DefaultStartActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Custom1 | Custom2 | Wait 100 | NUOLOn
NUOLOn=[!EnableMeasureGroup NUOL]
Custom1=
Custom2=
Deactivate=[!DeactivateConfig]
DynamicVariables=1


[Variables]
@includeCoreVars=#@#Vars.inc
@includeVer=#@#Version.inc
; ----------------------------- Default variables ---------------------------- ;
Scroll=0
Sec.Container=

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;


@IncludeWindow=#@#Includes/Window.ini
@IncludeMouse=#@#Includes/ScriptMouseHandler#QoL#.ini

[Func]
Measure=Script
ScriptFile=#@#Lua\Func.lua

[Auto_Refresh:M]
Measure=String
OnUpdateAction=[!Refresh "#Skin.Name#\Main"]
Group=NUOL
Disabled=1

[Set.Toolbar:M]
Measure=#QolPlugin#
Plugin=ShowInToolbar
WindowTitle=Core3 /#Skin.Name#
WindowIcon=#@#Images\Logo.ico

[Input:M]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Pri_Color#
FontColor=#Set.Text_Color#
FontFace=#Set.Font#
FontSize=(10*[Set.S])
StringAlign=Right
W=((200-10)*[Set.S])
H=((30-10)*[Set.S])
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!CommandMeasure Func "processInput('#Editing#', [[$UserInput$]])"]

; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

[Set.String:S]
FontFace=#Set.Font#
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
Container=ContentContainer
[Set.OptionName:S]
X=r
Y=(15*[Set.S])R
FontSize=(10*[Set.S])
Container=ContentContainer

; ---------------------------------- Generic --------------------------------- ;




[Set.Div:S]
X=r
y=(15*[Set.S])R
DynamicVariables=1
Container=ContentContainer
Shape=Line 0,0,(#Set.W#-#Set.L#-#Set.P#*3),0 | StrokeWidth 1 | Fill Color #Set.Pri_Color#,0 | Stroke LinearGradient This
This=0 | #Set.Text_Color#,25 ; 0.0 | #Set.Text_Color#,0 ; 0.5 | #Set.Text_Color#,25 ; 1.0

[Set.TextBox:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-201*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
Container=ContentContainer
DynamicVariables=1
Shape=Rectangle 0,0,200,30,3,3 | StrokeWidth 2 | Stroke Color 0,0,0,1 | Fill LinearGradient This | Scale [Set.S],[Set.S],0,0
This=180 | 0,0,0,1 ; 0 | 0,0,0,1 ; 0
MouseOverAction=[!SetOption #CURRENTSECTION# This "180 | 0,0,0,1 ; 0.5 | #Set.Text_Color#,50 ; 1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "180 | 0,0,0,1 ; 0 | 0,0,0,1 ; 0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*[Set.S])"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*[Set.S])"][!CommandMeasure Input:M "ExecuteBatch 1"]
[Set.FontBox:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-201*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
Container=ContentContainer
DynamicVariables=1
Shape=Rectangle 0,0,200,30,3,3 | StrokeWidth 2 | Stroke Color 0,0,0,1 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure Func "startSide('Font', '#CURRENTSECTION#')"]
RightMouseUpAction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*[Set.S])"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*[Set.S])"][!CommandMeasure Input:M "ExecuteBatch 1"]
[Set.Value:S]
X=((200-7.5)*[Set.S])r
Y=(15*[Set.S])r
StringAlign=rightCenter
FontSize=(10*[Set.S])
Container=ContentContainer
DynamicVariables=1

[Set.Bool:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-60*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-20/2+8)*[Set.S])
Shape=Rectangle 0,(-5*[Set.S]),(60*[Set.S]),(30*[Set.S]),(3*[Set.S]) | StrokeWidth 0 | Extend Fill
Shape2=Path Stair | StrokeWidth 0 | Fill Color #Set.Text_Color# | Scale ([Set.S]*(1-[##CURRENTSECTION#]*2)),([Set.S]*(1-[##CURRENTSECTION#]*2)),0,0 | OffSet ((5+50*[##CURRENTSECTION#])*[SEt.S]),((20*[##CURRENTSECTION#])*[SEt.S])
Stair=0,0 | LineTo 10,0 | LineTo 25,20 | LineTo 0,20 | ClosePath 1
; Shape2=Ellipse ([##CURRENTSECTION#] = 1 ? (40*[Set.S]) : (10*[Set.S])),(10*[Set.S]),(6*[Set.S]) | StrokeWidth 0 | Fill Color #Set.Text_Color#
DynamicVariables=1
Fill=Fill Color [&Func:returnBool('#CURRENTSECTION#', '1', '#Set.Positive_Color#', '#Set.SubText_Color#')]
Container=ContentContainer
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation#"][!SetVariable "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)"][!UpdateMeasure Auto_Refresh:M][!UpdateMeter *][!Redraw]




; ---------------------------------- Colors ---------------------------------- ;




[Set.Color:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-151*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Fill Color 0,0,0,1 | Scale [Set.S],[Set.S],0,0
Shape2=Ellipse (135*[Set.S]),(15*[Set.S]),(10*[Set.S]) | StrokeWidth 2 | Stroke Color #Set.Ter_Color# | Fill Color [##CURRENTSECTION#]
; LeftMouseUpAction=[!CommandMeasure ColorPicker "SetColor('#CURRENTSECTION#', 'Variables', 'rgb', [[#Sec.SaveLocation#]], '#CURRENTSECTION#')"]
; ColorChangeAction=[!SetVariable #CURRENTSECTION# "$color$"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=ContentContainer

[Set.Grad0:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-151*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
DynamicVariables=1
Shape=Rectangle 0,0,75,30,3 | StrokeWidth 0 | Fill LinearGradient Grad | Scale [Set.S],[Set.S],0,0
Grad=180 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad0')]] ; 0.0 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad1')]] ; 2
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=[&Func:GroupVar('#CURRENTSECTION#', 'Grad0')]" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=ContentContainer
[Set.Grad1:S]
X=r
Y=r
DynamicVariables=1
Shape=Rectangle (75*[Set.S]),0,(75*[Set.S]),(30*[Set.S]),3 | StrokeWidth 0 | Fill LinearGradient Grad
Grad=180 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad0')]] ; -1 | [#[&Func:GroupVar('#CURRENTSECTION#', 'Grad1')]] ; 1
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=[&Func:GroupVar('#CURRENTSECTION#', 'Grad1')]" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Container=ContentContainer

[Set.ColorPacity:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-151*[Set.S])
; Y=([Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale [Set.S],[Set.S],0,0
Shape2=Ellipse (135*[Set.S]),(15*[Set.S]),(10*[Set.S]) | StrokeWidth 2 | Stroke Color #Set.Ter_Color# | Fill Color [##CURRENTSECTION#Color]
Fill=Stroke Color 0,0,0,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 0,0,0,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 0,0,0,15"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#Color" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
RightMOuseUpAction=[!SetVariable Editing "#CURRENTSECTION#Opacity"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 1"]
; LeftMouseUpAction=[!CommandMeasure ColorPicker "SetColor('#CURRENTSECTION#', 'Variables', 'rgba', [[#Sec.SaveLocation#]], '#CURRENTSECTION#')"]
; ColorChangeAction=[!SetVariable #CURRENTSECTION# "$color$"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
Type=Num|0|255
[Set.Pacity:S]
X=(5*[Set.S])r
Y=(15*[Set.S])r
StringAlign=LeftCenter
FontSize=(10*[Set.S])
Container=ContentContainer
Stringeffect=Shadow
Prefix="Opacity// "
DynamicVariables=1

; ------------------------------ Action buttons ------------------------------ ;




[Set.Button:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-201*[Set.S])
; Y=([&Option[&Func:LocalVar('#CURRENTSECTION#', 'Class')]:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Sec_Color#
LeaveColor=0,0,0,1
DynamicVariables=1
Shape=Rectangle 0,0,200,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[&Func:LocalVar('#CURRENTSECTION#', 'Act')]
Container=ContentContainer

[Set.RectButton:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-26*[Set.S])
OverColor=#Set.Accent_Color#,255
LeaveColor=#Set.Accent_Color#,200
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Shape=Rectangle 0,0,26,26,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
LeftMouseUpAction=[!commandMeasure Func "startPopup('#CURRENTSECTION#', 'info')"]
Container=ContentContainer
DynamicVariables=1
[Set.Icon:S]
FontFace=Segoe MDL2 Assets
X=(26/2*[Set.S])r
Y=(26/2*[Set.S])r
StringAlign=CenterCenter
FontSize=(10*[Set.S])
Text=[\xEA1F]
Container=ContentContainer
DynamicVariables=1


; --------------------------------- 2 picker --------------------------------- ;




[Set.Pick:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-302*[Set.S])
Shape=Rectangle 0,0,300,30,7 | StrokeWidth 2 | Extend Fill | Scale [Set.S],[Set.S],0,0 | Stroke Color #Set.Text_Color#,50
Fill=Fill Color #Set.Text_Color#,25
Shape2=Rectangle ([#[&Func:GroupVar('#CURRENTSECTION#')]] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
DynamicVariables=1
Container=ContentContainer
[Set.PickOption_0:S]
X=(300/4*[Set.S])r
Y=(30/2*[Set.S])r
FontSize=(10*[Set.S])
Padding=(300/6*[Set.S]),(30/4*[Set.S]),(300/6*[Set.S]),(30/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
Container=ContentContainer
[Set.PickOption_1:S]
X=(300/2*[Set.S])r
Y=r
FontSize=(10*[Set.S])
Padding=(300/6*[Set.S]),(30/4*[Set.S]),(300/6*[Set.S]),(30/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
Container=ContentContainer








; --------------------------------- 3 picker --------------------------------- ;




[Set.Pick3:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-302*[Set.S])
Shape=Rectangle 0,0,300,30,7 | StrokeWidth 2 | Extend Fill | Scale [Set.S],[Set.S],0,0 | Stroke Color #Set.Text_Color#,25
Fill=Fill Color #Set.Text_Color#,25
DynamicVariables=1
Container=ContentContainer
[Set.PickOption3_0:S]
X=(300/6*[Set.S])r
Y=(30/2*[Set.S])r
FontSize=(10*[Set.S])
Padding=(300/6*[Set.S]),(30/4*[Set.S]),(300/6*[Set.S]),(30/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
Container=ContentContainer
[Set.PickOption3_1:S]
X=(300/3*[Set.S])r
Y=r
FontSize=(10*[Set.S])
Padding=(300/6*[Set.S]),(30/4*[Set.S]),(300/6*[Set.S]),(30/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
Container=ContentContainer
[Set.PickOption3_2:S]
X=(300/3*[Set.S])r
Y=r
FontSize=(10*[Set.S])
Padding=(300/6*[Set.S]),(30/4*[Set.S]),(300/6*[Set.S]),(30/4*[Set.S])
DynamicVariables=1
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '2Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
StringAlign=CenterCenter
Container=ContentContainer


; ------------------------------- Side buttons ------------------------------- ;


[PageDiv:S]
X=(#Set.P#)
y=(15*[Set.S])R
Shape=Line 0,0,(#Set.L#-#Set.P#*2),0 | StrokeWidth 2 | Fill Color #Set.Sec_Color#,0 | Stroke Color #Set.Text_Color#,25
DynamicVariables=1
[PageCat:S]
FontFace=#Set.Font# 
FontWeight=(650)
X=#Set.P#
StringAlign=Left
FontSize=(8*[Set.S])
FontColor=150,150,150
InlineSetting=CharacterSpacing | 1 | 1
[PageBox:S]
X=(#Set.P#-5*[Set.S])
Y=((24/2*[Set.S])+#Set.P#/1.5)r
Shape=Rectangle 0,0,(#Set.L#-#Set.P#*2),(40*[Set.S]),(#Set.R#/2) | StrokeWidth 0 | Extend This
Shape2=Rectangle (5*[Set.S]),(5*[Set.S]),(30*[Set.S]),(30*[Set.S]),(#Set.R#) | StrokeWidth 0 | Extend Fill 
Leftmouseupaction=[!WriteKeyvalue Variables "Skin.Set_Page" "#CURRENTSECTION#" "#@#SecVar.inc"][!UpdateMeasure CheckPreview][!Refresh]
This=Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
OverColor=150
LeaveColor=0
DynamicVariables=1
Group=Set.SideButtons
[PageIcon:S]
ImageName=#@#Icons\Settings\#CURRENTSECTION#.png
X=(#Set.P#)
Y=(5*[Set.S])r
W=(20*[Set.S])
H=(20*[Set.S])
Padding=(5*[Set.S]),(5*[Set.S]),(5*[Set.S]),(5*[Set.S])
DynamicVariables=1
; ImageAlpha=200
ImageTint=#Set.Text_Color#
Group=Set.SideButtons | Set.SideIcons
[PageText:S]
X=(15*[Set.S])R
Y=(15*[Set.S])r
Container=
StringAlign=LeftCenter
FontColor=[&Func:returnBool('BarHandler', '#CURRENTSECTION#', '#Set.Text_Color#', '#Set.SubText_Color#')]
; FontColor=(#BarHandler# = #CURRENTSECTION# ? 255 : 120),(#BarHandler# = #CURRENTSECTION# ? 255 : 120),(#BarHandler# = #CURRENTSECTION# ? 255 : 120)
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
1232412414=45 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')] ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.1')] ; 1.0
Grad.0=255,255,255
Grad.1=255,255,255
Grad.2=255,255,255
Grad.3=255,255,255
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# 1232412414 "45 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.2')] ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.3')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# 1232412414 "45 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')] ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.1')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]






; ---------------------------------------------------------------------------- ;
;                                 Close button                                 ;
; ---------------------------------------------------------------------------- ;


[Esc]
Meter=Shape
X=(#Set.W#-15*[Set.S])
Y=(15*[Set.S])
DynamicVariables=1
Shape=Ellipse 0,0,(5*[Set.S]),(5*[Set.S]) | StrokeWidth 20 | StrokeColor 0,0,0,1 | Extend FillE
FillE=Fill Color #Set.Text_Color#,50
MouseOverAction=[!SetOption Esc FillE "Fill Color #Set.Text_Color#"][!UpdateMeter Esc][!Redraw]
MouseLeaveAction=[!SetOption Esc FillE "Fill Color #Set.Text_Color#,50"][!UpdateMeter Esc][!Redraw]
LeftMouseDownAction=[!UpdateMeasure CheckPreview][!ActivateConfig "#CURRENTCONFIG#" "Home.ini"]
RightMOuseUpAction=[!commandMeasure Func "startDrop('Window', '#CURRENTSECTION#', 'JaxCore')"]

[CheckPreview]
Measure=String
String=#SKIn.Name# #Skin.Set_Page#
Ifmatch=^ModularClocks Appearance$
Ifmatchaction=[!CommandMeasure Script:M "Restore()"]
ifmatchmode=1
disabled=1
group=nuol