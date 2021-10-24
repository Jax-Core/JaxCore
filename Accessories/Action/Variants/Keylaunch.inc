; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[Variables]
@includeSkinActions=#SKINSPATH##Skin.Name#\@Resources\Act.inc
@includeRMPATH=#SKINSPATH#..\CoreData\Vars.inc

Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Act.inc

[Script]
Measure=Script
ScriptFile="#SKINSPATH##Skin.name#\Core\GenKeylaunchKey.lua"

[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
CopyLink=1
GetIcon=1
IconCache=#SKINSPATH#..\CoreData\Keylaunch\IconCache\
IconSize=3
ReturnValue=WholePath
FileInitialDirectory=
ImageInitialDirectory=#CurrentPath#IconCache\
DynamicVariables=1
Command1=[!SetOption Path:M String "$Path$"][!UpdateMEasure Path:M][!UpdateMEasure #CURRENTSECTION#][!CommandMeasure Script "Edit(1, '$Name$', '[Path:M]' , '$Name$', '$Ext$')"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[KeyLabel]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
FontSize=10
FontColor=#Set.Subtext_Color#
Text=Editing #Sec.Num# #CRLF#Click on anything to edit their values, or click Quick start to generate them. Icons must be name of images from IconCache folder in Keylaunch's @Resources folder. Actions must be in Rainmeter's bang format, that is in square brackets
inlinepattern=#CRLF#.*
inlinesetting=Size | 8
DynamicVariables=1
StringAlign=Center
MeterStyle=Sec.String:S

[Image]
MEter=Image
X=(#Sec.W#/2-#Sec.Size1#/2)
Y=(#Sec.H#/2-(#Sec.Size1#+[Name:H]+[Act:H])/2)
W=(#Sec.Size1#)
H=(#Sec.Size1#)
ImageAlpha=50
DynamicVariables=1
ImageName=#RainmeterPath#\CoreData\Keylaunch\IconCache\[##Sec.Num#Icon].png
[Image2]
MEter=Image
X=(#Sec.W#/2-#Sec.Size2#/2)
Y=((#Sec.Size1#-#Sec.Size2#)/2)r
W=(#Sec.Size2#)
H=(#Sec.Size2#)
ImageAlpha=255
DynamicVariables=1
Leftmouseupaction=[!SetVariable Editing "#sec.Num#Icon"][!CommandMeasure Input:M "ExecuteBatch 1"]
ImageName=#RainmeterPath#\CoreData\Keylaunch\IconCache\[##Sec.Num#Icon].png

[Name]
Meter=String
X=(#Sec.W#/2)
Y=((#Sec.Size1#-#Sec.Size2#)+10)R
FontSize=20
FontFace=Poppins SemiBold
Text=[##Sec.Num#Name]
DynamicVariables=1
Leftmouseupaction=[!SetVariable Editing "#sec.Num#Name"][!CommandMeasure Input:M "ExecuteBatch 1"]
StringAlign=CenterCenter
MeterStyle=Sec.String:S

[Act]
Meter=String
X=(#Sec.W#/2)
Y=(10)R
FontSize=10
Text=[##Sec.Num#Action]
DynamicVariables=1
StringAlign=CenterCenter
Leftmouseupaction=[!SetVariable Editing "#sec.Num#Action"][!CommandMeasure Input:M "ExecuteBatch 1"]
MeterStyle=Sec.String:S

[ShapeQuickStart]
Meter=Shape
X=((#Sec.W#-#Sec.P#*2)/2-(100*2+5*1)/2+#sec.P#)
Y=445
ColorLeave=0,100,0,150
ColorOver=0,100,0,250
LeftMouseUpAction=[!CommandMeasure Choose:M "ChooseFile 1"]
MeterStyle=Sec.Button:S
[TextQuick]
Meter=String
Text=Quick start
MEterStyle=Sec.String:S | Sec.Text:S

[ShapeConfirm]
Meter=Shape
Leftmouseupaction=[!Refresh "#JaxCore\Main"][!Refresh "#Skin.Name#\Main"][!DeactivateConfig]
MeterStyle=Sec.Button:S
[TextConfirm]
Meter=String
Text=Confirm
MEterStyle=Sec.String:S | Sec.Text:S
