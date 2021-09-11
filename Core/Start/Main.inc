[Rainmeter]
Rightmouseupaction=[]
OnRefreshAction=[!ZPos 1][!Move (#SCREENAREAWIDTH#/2-#Sec.W#/2) (#SCREENAREAHEIGHT#/2-#Sec.H#/2)][!SetOption Dep3 MeterStyle "Dep.Shape:S | Dep.ShapeYes:S"][!UpdateMEter *][!Redraw]

; ---------------------------------------------------------------------------- ;
;                                  Export vars                                 ;
; ---------------------------------------------------------------------------- ;

[ExportVariables]
Measure=Calc
OnUpdateAction=[!WriteKeyValue Variables RMPATH "#PROGRAMPATH#Rainmeter.exe" "#@#Actions\Hotkeys.ini"][!Delay 100][!EnableMeasureGroup NUOL]

[CheckModular]
Measure=String
String=#ROOTCONFIG#
IFmatch=ModularClocks|ModularPlayers
IfNotMatchAction=[!HideMeter Dep2][!HideMeter Deptext2][!Redraw]

[Variables]
@includeVersion=#@#Version.inc
@includeJaxCoreChecker=#SKINSPATH#\#JaxCore\@Resources\Version.inc
Sec.W=800
Sec.H=500
Sec.P=40
Sec.L=350
Sec.R=10

Pri_Color=12,12,12
Sec_Color=28,28,28
Ter_Color=35,35,35
Accent_Color=255, 117, 81
Text_Color=242,240,255
SubText_Color=120,120,120

[String:S]
FontColor=#Text_Color#
Fontface=Roboto Light
AntiAlias=1
X=r
Y=10R
FontSize=10

[Dep.Shape:S]
X=-20r
Y=35r
Shape=Rectangle 0,0,(#SEc.W#-#Sec.L#-#Sec.P#*2),50,2.5 | StrokeWidth 0 | Extend This
Shape2=Rectangle 0,0,5,50,2.5 | StrokeWidth 0 | Fill Color #SubText_Color#
This=fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Dep.ShapeYes:S]
Shape2=Rectangle 0,0,5,50,2.5 | StrokeWidth 0 | Fill Color 0,255,50,100
This=Fill Color 0,255,50,50
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,50,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,50,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Dep.ShapeNo:S]
Shape2=Rectangle 0,0,5,50,2.5 | StrokeWidth 0 | Fill Color 255,0,0,100
This=Fill Color 255,0,0,50
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 255,0,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 255,0,0,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Dep.Text:S]
X=20r
Y=25r
W=(#SEc.W#-#Sec.L#-#Sec.P#*2-50)
clipString=2
StringAlign=LeftCenter
FontColor=#Text_Color#
Fontface=Roboto
AntiAlias=1
FontSize=12
InlinePattern=//.*
InlineSetting=Color | #SubText_Color#
InlinePattern2=//.*
InlineSetting2=Size | 10

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

; ------------------------------------ Gen ----------------------------------- ;

[B]
Meter=Shape
Shape=Rectangle 0,0,#Sec.W#,#Sec.H#,#sec.R# | strokeWidth 0 | Fill Color #Pri_Color#
[BC]
Meter=Shape
X=(#Sec.W#-#SEc.L#)
Shape=Rectangle 0,0,(#Sec.L#),#Sec.H#,#sec.R# | strokeWidth 0 | Fill LinearGradient This
This=0 | 0,0,0,150 ; 0.0 | 0,0,0,0 ; 1.0

[Logo]
Meter=Image
ImageName=Logo.png
X=#Sec.P#
Y=(#Sec.H#-#Sec.P#-40)
W=40
H=40

[Image]
Meter=Image
Container=BC
; X=(#Sec.L#-#Sec.H#*6/4)
; PreserveAspectRatio=0
H=#Sec.H#
W=#Sec.L#
PreserveAspectRatio=2
Leftmouseupaction=[!Refresh]
ImageName=#ROOTCONFIG#.png

[Esc]
Meter=Shape
DynamicVariables=1
Shape=Ellipse (#Sec.W#-15),(15),(5),(5) | StrokeWidth 10 | StrokeColor 0,0,0,1 | Extend FillE
FillE=Fill Color #Text_Color#,50
MouseOverAction=[!SetOption Esc FillE "Fill Color #Text_Color#"][!UpdateMeter Esc][!Redraw]
MouseLeaveAction=[!SetOption Esc FillE "Fill Color #Text_Color#,50"][!UpdateMeter Esc][!Redraw]
LeftMouseUpAction=[!DeactivateConfig]

; --------------------------------- Left --------------------------------- ;

[MainText]
Meter=String
X=(#Sec.P#)
Y=#Sec.P#
Text=#ROOTCONFIG# by Jax | #Version#
StringAlign=LEftTOp
FontFace=Roboto Bold
FontSize=25
InlinePattern=by.*
InlineSetting=Size | 10
InlinePattern2=by.*
InlineSetting2=Color | #SubText_Color#
InlinePattern3=by.*
InlineSetting3=Face | Roboto
MeterStyle=String:S

[Des]
Meter=String
Text=Here you can find the list of dependencies. Click on any one of them to install, make sure you are connected to the internet. Refresh this page by clicking on the right.
W=(#SEc.W#-#Sec.L#-#Sec.P#*2)
clipString=2
MeterStyle=String:S

; ------------------------------------ Dep ----------------------------------- ;

[Dep1]
Meter=Shape
X=r
Y=20R
MEterStyle=Dep.Shape:S
[DepText1]
Meter=String
Text=JaxCore3 // Checking...
MeterStyle=Dep.Text:S

[Dep3]
Meter=Shape
MEterStyle=Dep.Shape:S
[DepText3]
Meter=String
Text=Your appreciation
MeterStyle=Dep.Text:S

[Dep2]
Meter=Shape
MEterStyle=Dep.Shape:S
Leftmouseupaction=["https://github.com/khanhas/MagickMeter#how-to-install"]
[DepText2]
Meter=String
Text=ImageMagick // optional - required for Modular skins
MeterStyle=Dep.Text:S

; ------------------------------------ Bot ----------------------------------- ;

[ContinueButton]
Meter=Shape
X=(#Sec.P#+50)
Y=(#Sec.H#-#Sec.P#-40)
DynamicVariables=1
Shape=Rectangle 0,0,120,40,(#Sec.R#/3) | StrokeWidth 0 | Fill COlor 0,255,50,200
Leftmouseupaction=[!ActivateConfig "#JaxCore\Main" "Home.ini"][!DeactivateConfig]
Hidden=1
Group=Button
[ContinueText]
Meter=String
X=(60)r
y=(20)r
FontSize=(10)
Text=Continue
FontFace=Roboto
FontWeight=700
StringAlign=CenterCenter
MeterStyle=String:S
Hidden=1
Group=Button

; ---------------------------------------------------------------------------- ;
;                              Check for jax core                              ;
; ---------------------------------------------------------------------------- ;

[WebParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/main/%40Resources/Version.inc
RegExp==(.*)$
FinishAction=[!Delay 1000][!CommandMeasure LogicalScript "check()"]
OnConnectionErrorAction=[!SetOption Dep1 MeterStyle "Dep.Shape:S | Dep.ShapeNo:S"][!SetOption DepText1 Text "//Failed to connect to JaxCore github, if this is an issue please report to me"][!UpdateMEter *][!Redraw]
OnRegExpErrorAction=[!Log Developer:RegExpFalse]

[InternetStatus]
Measure=PLUGIN
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
IfCondition=InternetStatus = -1
ifTrueaction=[!SetOption Dep1 MeterStyle "Dep.Shape:S | Dep.ShapeNo:S"][!SetOption DepText1 Text "JaxCore // connection error, please check internet connection"][!UpdateMEter *][!Redraw]

[mVer]
Measure=WebParser
URL=[WebParser]
StringIndex=1

[LogicalScript]
Measure=Script
ScriptFile=Logic.lua

[JaxCoreYes]
Measure=String
Group=NUOL
Disabled=1
OnUpdateAction=[!SetOption Dep1 MeterStyle "Dep.Shape:S | Dep.ShapeYes:S"][!SetOption DepText1 Text "JaxCore3 // v#Core.Ver# installed"][!ShowMeterGroup Button][!UpdateMEter *][!Redraw]

[JaxCoreNo]
Measure=String
Group=NUOL
Disabled=1
OnUpdateAction=[!SetOption Dep1 MeterStyle "Dep.Shape:S | Dep.ShapeNo:S"][!SetOption DepText1 Text "JaxCore3 // click here to install"][!SetOption Dep1 Leftmouseupaction """["#@#Actions\AHKv1.exe" "#@#Actions\Installer.ahk"][!SetOption DepText1 Text "JaxCore3 // download here if it doesn't automatically install"][!SetOption Dep1 Leftmouseupaction """["https://github.com/EnhancedJax/-JaxCore/releases/latest"][!UpdateMEter *][!Redraw]"""][!UpdateMEter *][!Redraw]"""][!UpdateMEter *][!Redraw]
