[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=(110*#Sec.S#)
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
DefaultValue="Paste or type a bang to execute..."
Command1=[!CommandMEasure StringToBang """parse([[$UserInput$]])"""]
[StringToBang]
Measure=Script
ScriptFile=#@#Lua\StringToBang.lua

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
Text=Execute
MeterStyle=Sec.String:S
FontSize=(14*#sec.s#)
FontWeight=650

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
Text=Click here to input...
MeterStyle=Sec.String:S