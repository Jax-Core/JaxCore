
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[UpdatePromptActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#JaxCore\Accessories\UpdatePrompt
IfCondition=UpdatePromptActiveChecker = 1
IfTrueAction=[!SetVariable BackgroundCheckStatus 1][!UpdateMeter *][!Redraw]
IfFalseAction=[!SetVariable BackgroundCheckStatus 0][!UpdateMeter *][!Redraw]

[PSRM]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\AddShortcut.ps1

[p.ActionTimer]
CustomAction=[!ActivateConfig "#JaxCore\Accessories\UpdatePrompt"][!UpdateMeasure UpdatePromptActiveChecker][!CommandMeasure PSRM "AutoStartup"][!CommandMeasure PSRM "Desktop"][!CommandMeasure PSRM "StartFolder"]

; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;

[Sec.Icon:S]
FontFace=Material Icons Outlined
X=(26/2*#Sec.S#)r
Y=(26/2*#Sec.S#)r
StringAlign=LeftCenter
FontSize=(32*#Sec.S#)
DynamicVariables=1
Container=a.Container

[SectionButton:S]
X=(#Sec.W#-100*#Sec.S#-#Sec.P#-#Sec.WindowPaddingX#)
Y=((30/2+5)*#Sec.S#)r
Shape=Rectangle 0,0,(100*#Sec.S#),(30*#Sec.S#),(5*#Sec.S#) | StrokeWidth 0 | Extend This
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=a.Container
[SectionIcon:S]
X=(50*#Sec.s#)r
Y=(30/2*#Sec.S#)r
W=(100*#sec.s#)
FontSize=(10*#Sec.S#)
FontFace=#Set.Font#
StringAlign=CenterCEnter
DynamicVariables=1
[Section4.ButtonProg.False]
LeftMouseUpAction=[!CommandMeasure PSRM "StartFolder"][!SetOption Section4.Button2.Shape MeterStyle "SectionButton:S | Section4.ButtonProg.True"][!UpdateMeter Section4.Button2.Shape][!Redraw]
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Section4.ButtonProg.True]
This=Fill Color 0,255,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure PSRM "RemoveStartFolder"][!SetOption Section4.Button2.Shape MeterStyle "SectionButton:S | Section4.ButtonProg.False"][!UpdateMeter Section4.Button2.Shape][!Redraw]
[Section4.ButtonDesk.False]
LeftMouseUpAction=[!CommandMeasure PSRM "Desktop"][!SetOption Section4.Button1.Shape MeterStyle "SectionButton:S | Section4.ButtonDesk.True"][!UpdateMeter Section4.Button1.Shape][!Redraw]
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Section4.ButtonDesk.True]
This=Fill Color 0,255,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure PSRM "RemoveDeskop"][!SetOption Section4.Button1.Shape MeterStyle "SectionButton:S | Section4.ButtonDesk.False"][!UpdateMeter Section4.Button1.Shape][!Redraw]


; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Header.String]
Meter=String
Text=Welcome to JaxCore#CRLF#Let's set up Core here!
X=(#Sec.W#/2)r
Y=(70*#Sec.S#)r
FontSize=(24*#Sec.S#)
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | (10*#Sec.S#)
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
INlinePattern4=#CRLF#.*
InlineSetting4=Weight | 400
StringAlign=Center
MeterStyle=Sec.String:S
FontWeight=650



; --------------------------------- Section1 --------------------------------- ;

; [Section1]
; Meter=Shape
; X=#Sec.WindowPaddingX#
; Y=(15*#Sec.S#)R
; Shape=Rectangle 0,0,(#Sec.W#-#Sec.WindowPaddingX#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
; Fill=Fill Color #Set.Sec_Color#
; MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; DynamicVariables=1
; Container=a.Container
; MeterStyle=Section1:#BackgroundCheckStatus#
; [Section1:0]
; Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\UpdatePrompt"][!UpdateMeasure UpdatePromptActiveChecker]
; [Section1:1]
; Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\UpdatePrompt"][!UpdateMeasure UpdatePromptActiveChecker]

; [Section1.Icon]
; Meter=String
; Text=[\xecc5]
; X=(#Sec.P#)r
; Y=(100/2*#Sec.S#)r
; FontSize=(20*#Sec.S#)
; MeterStyle=Sec.String:S | Sec.Icon:S | Section1.Icon:#BackgroundCheckStatus#
; [Section1.Icon:0]
; FontColor=#Set.Accent_Color#
; InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
; [Section1.Icon:1]
; FontColor=#Set.Positive_Color#
; InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

; [Section1.Text]
; Meter=String
; X=(60*#Sec.S#)r
; Y=r
; W=(#Sec.W#-120*#sec.S#)
; FontSize=(10*#Sec.S#)
; Text=Check for Core updates in background#CRLF#Updates only downloaded when updating
; StringAlign=LeftCenter
; InlinePattern=#CRLF#.*
; InlineSetting=Color | #Set.SubText_Color#
; MeterStyle=Sec.String:S

; ; --------------------------------- Section4 --------------------------------- ;

; [Section4]
; Meter=Shape
; X=#Sec.WindowPaddingX#
; Y=(100/2*#Sec.S#+#Sec.P#)r
; Shape=Rectangle 0,0,(#Sec.W#-#Sec.WindowPaddingX#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
; Fill=Fill Color #Set.Sec_Color#
; Container=a.Container
; DynamicVariables=1

; [Section4.Icon]
; Meter=String
; Text=[\xF168]
; X=(#Sec.P#)r
; Y=(100/2*#Sec.S#)r
; FontSize=(20*#Sec.S#)
; MeterStyle=Sec.String:S | Sec.Icon:S

; [Section4.Text]
; Meter=String
; X=(60*#Sec.S#)r
; Y=r
; W=(#Sec.W#-120*#sec.S#)
; FontSize=(10*#Sec.S#)
; Text=Add shortcut to desktop#CRLF#For easy access to JaxCore
; StringAlign=LeftCenter
; InlinePattern=#CRLF#.*
; InlineSetting=Color | #Set.SubText_Color#
; MeterStyle=Sec.String:S

; [Section4.Button1.Shape]
; Meter=Shape
; MeterStyle=SectionButton:S | Section4.ButtonDesk.False
; Y=(-(30*2+5)/2*#Sec.S#)r
; [Section4.Button1.Text]
; Meter=String
; MeterStyle=Sec.String:S | SectionIcon:S
; Text=Desktop
; [Section4.Button2.Shape]
; Meter=Shape
; MeterStyle=SectionButton:S | Section4.ButtonProg.False
; [Section4.Button2.Text]
; Meter=String
; MeterStyle=Sec.String:S | SectionIcon:S
; Text=Program list

; --------------------------------- Section5 --------------------------------- ;

[Section5]
Meter=Shape
X=#Sec.WindowPaddingX#
Y=(15*#Sec.S#)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.WindowPaddingX#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=a.Container
LeftMouseUpAction=[!CommandMeasure PSRM "ToggleHA"]

[HardwareAcceleration]
Meter=String
Text=[\xe322]
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
MeterStyle=Sec.String:S | Sec.Icon:S | Section5.Icon:#HardwareAcceleration#
[Section5.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section5.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section5.Text]
Meter=String
X=(75*#Sec.S#)r
Y=r
W=(#Sec.W#-#Sec.WindowPaddingX#*2-#Sec.P#*2-#Sec.S#*75)
FontSize=(10*#Sec.S#)
Text=Hardware acceleration (Recommended)#CRLf#Makes Rainmeter and JaxCore run faster, depending on your system.
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

; --------------------------------- Game mode -------------------------------- ;

[ParseGameMode]
Measure=WebParser
URL=file://#SETTINGSPATH#Rainmeter.data
RegExp==([01])
StringIndex=1
OnUpdateAction=[!UpdateMeasure OutputGameMode]

[OutputGameMode]
Measure=Calc
Formula=[ParseGameMode]
IfEqualValue=0
IfEqualAction=[!SetVariable GameModeVal 0][!UpdateMeter Section6][!Redraw]
IfAboveValue=0
IfAboveAction=[!SetVariable GameModeVal 1][!UpdateMeter Section6][!Redraw]
DynamicVariables=1

[Section6]
Meter=Shape
X=#Sec.WindowPaddingX#
Y=(100/2*#Sec.S#+#Sec.P#)r
Shape=Rectangle 0,0,(#Sec.W#-#Sec.WindowPaddingX#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=a.Container
LeftMouseUpAction=[!EnableMeasure SetGameMode][!UpdateMeasure SetGameMode]

[GameMode]
Meter=String
Text=[\xea28]
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
MeterStyle=Sec.String:S | Sec.Icon:S | Section6.Icon:#GameModeVal#
[Section6.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section6.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section6.Text]
Meter=String
X=(75*#Sec.S#)r
Y=r
W=(#Sec.W#-#Sec.WindowPaddingX#*2-#Sec.P#*2-#Sec.S#*75)
FontSize=(10*#Sec.S#)
Text=Game Mode#CRLF#Disable Rainmeter / JaxCore when a full-screen game is active
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

; ----------------------------- Performance mode -----------------------------

[Section7]
Meter=Shape
X=#Sec.WindowPaddingX#
Y=(100/2*#Sec.S#+#Sec.P#)r
Shape=Rectangle 0,0,(#Sec.W#-#Sec.WindowPaddingX#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=a.Container
LeftMouseUpAction=[!EnableMeasure SetPerformanceMode][!UpdateMeasure SetPerformanceMode]

[SetPerformanceMode]
Measure=Calc
Formula=#Set.PerformanceMode#
DynamicVariables=1
IfEqualValue=0
IfEqualAction=[!FadeDuration 0 "#JaxCore\Main"][!WriteKeyValue Variables Set.Blur None "#@#Vars.inc"][!WriteKeyValue Variables Set.PerformanceMode 1 "#@#Vars.inc"][!SetVariable Set.PerformanceMode 1][!DisableMeasure SetPerformanceMode][!UpdateMeter PerformanceMode][!Redraw]
IfAboveValue=0
IfAboveAction=[!FadeDuration 100 "#JaxCore\Main"][!WriteKeyValue Variables Set.Blur Blur "#@#Vars.inc"][!WriteKeyValue Variables Set.PerformanceMode 0 "#@#Vars.inc"][!SetVariable Set.PerformanceMode 0][!DisableMeasure SetPerformanceMode][!UpdateMeter PerformanceMode][!Redraw]
Disabled=1

[PerformanceMode]
Meter=String
Text=[\xe9e4]
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
MeterStyle=Sec.String:S | Sec.Icon:S | Section7.Icon:#Set.PerformanceMode#
[Section7.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section7.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section7.Text]
Meter=String
X=(75*#Sec.S#)r
Y=r
W=(#Sec.W#-#Sec.WindowPaddingX#*2-#Sec.P#*2-#Sec.S#*75)
FontSize=(10*#Sec.S#)
Text=Performance Mode#CRLF#Disable resource-intensive features within JaxCore. Recommended for low-end users.
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S


[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
Text=Continue
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure p.ActionTimer "Execute 2"]
MeterStyle=Sec.String:S