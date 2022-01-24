[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=(300*#Sec.S#)
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
Text=Uninstall #Sec.Arg1#
MeterStyle=Sec.String:S
FontSize=(14*#sec.s#)
FontWeight=650
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 2.0

[Description]
Meter=String
X=r
Y=R
StringAlign=Center
Text=Sad to see you go! What's your reason for uninstalling?
MeterStyle=Sec.String:S
FontSize=(10*#sec.s#)

[Button.1]
Meter=Shape
Y=(#Sec.P#/2)R
MeterStyle=Sec.Button:S
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('UninstallBug', '#Sec.Arg1#')"][!Refresh]
[Button.Text.1]
Meter=String
Text=I've encountered some bugs and issues.
MeterStyle=Sec.String:S | Sec.Button.Text:S

[Button.2]
Meter=Shape
MeterStyle=Sec.Button:S
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('UninstallWork', '#Sec.Arg1#')"][!Refresh]
[Button.Text.2]
Meter=String
Text=The module doesn't show up / work properly
MeterStyle=Sec.String:S | Sec.Button.Text:S

[Button.3]
Meter=Shape
MeterStyle=Sec.Button:S
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('UninstallVariants', '#Sec.Arg1#')"][!Refresh]
[Button.Text.3]
Meter=String
Text=I'd like to switch up the widgets
MeterStyle=Sec.String:S | Sec.Button.Text:S

[Button.4]
Meter=Shape
MeterStyle=Sec.Button:S
LeftMouseUpAction=[!CommandMeasure Func "interactionBox('UninstallFeature', '#Sec.Arg1#')"][!Refresh]
[Button.Text.4]
Meter=String
Text=Missing key feature
MeterStyle=Sec.String:S | Sec.Button.Text:S

[Button.5]
Meter=Shape
MeterStyle=Sec.Button:S
LeftMouseUpAction=[!CommandMeasure CoreInstallHandler "Uninstall"]
[Button.Text.5]
Meter=String
Text=Not in use anymore
MeterStyle=Sec.String:S | Sec.Button.Text:S

[Esc]
LeftMouseUpAction=[!CommandMeasure Func "corepage('#Sec.Arg1#', 1)"]