[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=(150*#Sec.S#)
AniDir=Bottom
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#WORKAREAHEIGHT#-20)
[anchorX]
Formula=50
[anchorY]
Formula=100

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[Input:M]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Sec_Color#
FontColor=#Set.Text_Color#
FontFace=#Set.Font#
FontSize=(10*#Sec.S#)
StringAlign=Left
X=#Sec.P#
Y=[InputBox:Y]
W=(#Sec.W#-#Sec.P#*2)
H=(30*#sec.S#)
DynamicVariables=1
DefaultValue="#Sec.arg1#-Clone"
Command1=[!CommandMEasure CoreInstallHandler """DuplicateSkin -DuplicateName "$UserInput$""""]
[CoreInstallHandler]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
ExecutionPolicy=Unrestricted

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
Text=Widget clone
MeterStyle=Sec.String:S
FontSize=(14*#sec.s#)
FontWeight=650

[Description]
Meter=String
X=r
Y=R
StringAlign=Center
Text=Clone a widget. You must NOT enter a name with spaces. By entering an existing name of clone, you'll be sent to it's config page.
MeterStyle=Sec.String:S
FontSize=(10*#sec.s#)

[InputBox]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#/2)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(30*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Fill Color #set.Sec_Color#
LeftMouseUpAction=[!CommandMeasure Input:M "ExecuteBatch 1"]

[SubtleText]
Meter=String
X=((#Sec.W#-#Sec.P#*2)/2)r
Y=(15*#Sec.S#)r
FontColor=#Set.Subtext_Color#
StringAlign=CenterCenter
Text=Click here to name the duplicated widget
MeterStyle=Sec.String:S