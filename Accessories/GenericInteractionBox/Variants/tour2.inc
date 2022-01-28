[Variables]
Sec.W=(500*#Sec.S#)
Sec.H=(700*#Sec.S#)
AniDir=Bottom
BackgroundCheckStatus=0
GlobalCheckStatus=0
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

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

[GlobalUpdaterActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#JaxCore\Accessories\GlobalUpdater
IfCondition=GlobalUpdaterActiveChecker = 1
IfTrueAction=[!SetVariable GlobalCheckStatus 1][!UpdateMeter *][!Redraw]
IfFalseAction=[!SetVariable GlobalCheckStatus 0][!UpdateMeter *][!Redraw]

[PSRM]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\AddShortcut.ps1

[ActionTimer]
Custom2=[!CommandMeasure PSRM "Check"]

; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;

[Sec.Icon:S]
FontFace=Segoe MDL2 Assets
X=(26/2*#Sec.S#)r
Y=(26/2*#Sec.S#)r
StringAlign=LeftCenter
FontSize=(10*#Sec.S#)
Text=[\xEA1F]
DynamicVariables=1

[SectionButton:S]
X=(#Sec.W#-100*#Sec.S#-#Sec.P#*2)
Y=((30/2+5)*#Sec.S#)r
Shape=Rectangle 0,0,(100*#Sec.S#),(30*#Sec.S#),(5*#Sec.S#) | StrokeWidth 0 | Extend This
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
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

[ImageContainer]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#),[Image:H],#Sec.R# | StrokeWidth 0 | Fill LinearGradient This
This=90 | 0,0,0,0 ; 0 | 0,0,0,255 ; 1
DynamicVariables=1

[Image]
Meter=Image
Container=Imagecontainer
ImageName=#@#Images\TourPreview.png
W=#Sec.W#
H=(200*#sec.S#)
PreserveAspectRatio=2
ImageAlpha=175

[Img]
Meter=Image
X=(#Sec.W#/2-[Img:W]/2)
Y=#Sec.P#
W=(100*#Sec.S#)
H=([Img:W])
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png

[Text]
Meter=String
Text=Welcome to JaxCore#CRLF#Let's set up Core here!
X=(#Sec.W#/2)
Y=(15*#Sec.s#)R
FontSize=(20*#Sec.S#)
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

[Section1]
Meter=Shape
X=#Sec.P#
Y=(15*#Sec.S#)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
MeterStyle=Section1:#BackgroundCheckStatus#
[Section1:0]
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\UpdatePrompt"][!UpdateMeasure UpdatePromptActiveChecker]
[Section1:1]
Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\UpdatePrompt"][!UpdateMeasure UpdatePromptActiveChecker]

[Section1.Icon]
Meter=String
Text=[\xecc5]
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
FontSize=(20*#Sec.S#)
MeterStyle=Sec.String:S | Sec.Icon:S | Section1.Icon:#BackgroundCheckStatus#
[Section1.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section1.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section1.Text]
Meter=String
X=(60*#Sec.S#)r
Y=r
FontSize=(10*#Sec.S#)
Text=Check for Core updates in background#CRLF#Updates only downloaded when updating
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

; --------------------------------- Section2 --------------------------------- ;

[Section2]
Meter=Shape
X=#Sec.P#
Y=(15*#Sec.S#)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
MeterStyle=Section2:#GlobalCheckStatus#
[Section2:0]
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\GlobalUpdater"][!UpdateMeasure GlobalUpdaterActiveChecker]
[Section2:1]
Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\GlobalUpdater"][!UpdateMeasure GlobalUpdaterActiveChecker]

[Section2.Icon]
Meter=String
Text=[\xecc5]
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
FontSize=(20*#Sec.S#)
MeterStyle=Sec.String:S | Sec.Icon:S | Section2.Icon:#GlobalCheckStatus#
[Section2.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section2.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section2.Text]
Meter=String
X=(60*#Sec.S#)r
Y=r
FontSize=(10*#Sec.S#)
Text=Check for module updates on startup#CRLF#Core will not check for updates in the background 
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

; --------------------------------- Section4 --------------------------------- ;

[Section4]
Meter=Shape
X=#Sec.P#
Y=(15*#Sec.S#)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
; MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1

[Section4.Icon]
Meter=String
Text=[\xF168]
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
FontSize=(20*#Sec.S#)
MeterStyle=Sec.String:S | Sec.Icon:S

[Section4.Text]
Meter=String
X=(60*#Sec.S#)r
Y=r
FontSize=(10*#Sec.S#)
Text=Add shortcut to desktop#CRLF#For easy access to JaxCore
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

[Section4.Button1.Shape]
Meter=Shape
MeterStyle=SectionButton:S | Section4.ButtonDesk.False
Y=(-(30*2+5)/2*#Sec.S#)r
[Section4.Button1.Text]
Meter=String
MeterStyle=Sec.String:S | SectionIcon:S
Text=Desktop
[Section4.Button2.Shape]
Meter=Shape
MeterStyle=SectionButton:S | Section4.ButtonProg.False
[Section4.Button2.Text]
Meter=String
MeterStyle=Sec.String:S | SectionIcon:S
Text=Program list


[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
Text=Continue
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMEasure fUnc "interactionBox('tour3')"][!Refresh]
MeterStyle=Sec.String:S

[Esc]
Meter=