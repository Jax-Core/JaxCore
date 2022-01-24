[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=(140*#Sec.S#)
AniDir=Bottom
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[CoreInstallHandler]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
ExecutionPolicy=Unrestricted

[ActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Sec.Arg1#\Main

[Sec.Button:S]
X=#Sec.P#
Y=(25*#Sec.S#)r
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(30*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Sec.Button.Text:S]
X=((#Sec.W#-#Sec.P#*2)/2)r
Y=(15*#Sec.S#)r
StringAlign=CenterCenter

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

; [HeaderImage]
; Meter=Image
; ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo.png
; X=(#Sec.W#/2-(30*#Sec.S#)/2)
; Y=(#Sec.P#/2)
; W=(30*#Sec.S#)
; H=(30*#Sec.S#)
; ImageAlpha=25

[HeaderString]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
StringAlign=Center
Text=Switching up widgets?
MeterStyle=Sec.String:S
FontSize=(14*#sec.s#)
FontWeight=650
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 2.0

[Description]
Meter=String
X=r
Y=R
StringAlign=Center
Text=Reminder: "Modular" skins have multiple styles and plently of customization options that you can play with to make them unique!
MeterStyle=Sec.String:S
FontSize=(10*#sec.s#)

[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
Text=Proceed uninstallation
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure CoreInstallHandler "Uninstall"]
MeterStyle=Sec.String:S

[Esc]
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('Uninstall', '#Sec.Arg1#')"][!Refresh]