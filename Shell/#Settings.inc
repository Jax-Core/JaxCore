
[Variables]
@includeSkin=#@#SecVar.inc
;Retrives the skin name
@includeSkinVars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
@includeSkinVer=#SKINSPATH##Skin.Name#\@Resources\Version.inc
;get current skin data

; Set.S=0.7
Set.S=(#SCREENAREAWIDTH#/1920)
Set.P=(20*#Set.S#)
Set.R=(20*#Set.S#)
Set.W=(1200*#Set.S#)
Set.H=(740*#Set.S#)
Set.L=(200*#Set.S#)
;Size, Pad, Round, Width, Height, ListWidth

Skin.Appearance=Combilaunch | Plainext | ModularClocks | MIUIShade | ModularPlayers
Skin.Layout=Combilaunch | MIUIShade
; Skin.General=Combilaunch | Plainext | ModularClocks | MIUIShade | ModularPlayers
Skin.Media=Plainext | MIUIShade | ModularPlayers
Skin.Render=ModularClocks
Skin.FAQ=Plainext | MIUIShade | ModularClocks | ModularPlayers

Scroll=0

;METERSTYLES===========================================================================================
;METERSTYLES===========================================================================================

[Set.String:S]
FontFace=Roboto
AntiAlias=1
FontSize=(12*#Set.S#)
FontColor=255,255,255
Container=ContentContainer
SolidColor=0,0,0,1

[Set.Div:S]
X=r
y=(15*#Set.S#)R
Container=ContentContainer
Shape=Line 0,0,(#Set.W#-#Set.L#-#Set.P#*3),0 | StrokeWidth 1 | Fill Color 0,0,0,0 | Stroke Color 255,255,255,25

[Set.TextBox:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-150)
Container=ContentContainer
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill
Fill=Stroke Color 255,255,255,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 255,255,255,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 1"]

[Set.Value:S]
X=(5*#Set.S#)r
Y=(15*#Set.S#)r
StringAlign=LeftCenter
FontSize=(10*#Set.S#)
DynamicVariables=1

[Set.Bool:S]
X=(#Set.W#-#Set.L#-#Set.P#*2-50)
Shape=Rectangle 0,0,50,20,10,10 | StrokeWidth 0 | Extend Fill
Shape2=Ellipse ([##CURRENTSECTION#] = 1 ? 40 : 10),10,5,5 | StrokeWidth 0 | Fill Color 255,255,255
DynamicVariables=1
Fill=Fill Color ([##CURRENTSECTION#] = 1 ? 35 : 181),([##CURRENTSECTION#] = 1 ? 209 : 181),([##CURRENTSECTION#] = 1 ? 96 : 181)
Container=ContentContainer
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#@#Vars.inc"][!Refresh]


[PageBox:S]
X=#Set.P#
Y=((24/2*#Set.S#)+#Set.P#/1.5)r
Shape=Rectangle 0,0,(#Set.L#-#Set.P#*2),(#Set.P#+(24-4)*#Set.S#),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Extend Fill
Leftmouseupaction=[!WriteKeyvalue Variables "Skin.Set_Page" "#CURRENTSECTION#" "#@#SecVar.inc"][!Refresh][!DeactivateConfig "#JaxCore\Main\Com"]
DynamicVariables=1
Group=Set.SideButtons
[PageIcon:S]
ImageName=#@#Icons\#CURRENTSECTION#.png
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
; Y=([VarOption:Y]-#Set.P#-20/2+8)

;; TEXT INPUT EXAMPLE
; [TextVarName]
; Meter=Shape
; MeterStyle=Set.TextBox:S
; Y=([VarOption:Y]-#Set.P#-30/2+8)
; [VarOptionNumber]
; Meter=String
; Text=TextVarName
; MeterStyle=Set.String:S | Set.Value:S

;STUFF===========================================================================================
;STUFF===========================================================================================

[Set.Toolbar:M]
Measure=Plugin
Plugin=ShowInToolbar
WindowTitle=Jax.O /#Skin.Name#
WindowIcon=#@#Images\Logo.ico

[Set.GeneratePages:M]
Measure=Script
ScriptFile=#@#Lua\GenSet.lua
[Set.Refresh:M]
Measure=Script
ScriptFile=#@#Lua\Refresh.lua
Refreshed=0

[Input:M]
Measure=Plugin
Plugin=InputText
SolidColor=171717
FontColor=255,255,255
FontFace=Seqoe UI
FontSize=(10*#Set.S#)
StringAlign=LeftCenter
W=(150-10)
H=(30-10)
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad:M]

[SaveAndLoad:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeter *][!Redraw][!Delay 1000][!Refresh "#SKINSPATH##Skin.Name#\Main"]
Disabled=1
Group=NUOL