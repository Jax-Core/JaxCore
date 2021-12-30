
[Rainmeter]
OnRefreshAction=[!Delay 100][!EnableMeasureGroup NUOL][!SetOption #IconName# MeterStyle "Image:S | Image2:S"][!UpdateMeter #IconName#][!Redraw]

[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
@includeSkinvars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[Set.Value:S]
X=(5*#Sec.S#)r
Y=(15*#Sec.S#)r
StringAlign=LeftCenter
FontSize=(10*#Sec.S#)
DynamicVariables=1

[Set.TextBox:S]
X=(#Sec.W#-#Sec.P#-150*#Sec.S#)
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale #Sec.S#,#Sec.S#,0,0
Fill=Stroke Color #Set.Text_Color#,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*#Sec.S#)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*#Sec.S#)"][!CommandMeasure Input:M "ExecuteBatch 1"]

[Set.Button:S]
X=(#Sec.W#-#Sec.P#-150*#Sec.S#)
OverColor=100,100,100,200
LeaveColor=100,100,100,100
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 0 | Extend Fill | Scale #Sec.S#,#Sec.S#,0,0
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[&Func:LocalVar('#CURRENTSECTION#', 'Act')]

[Input:M]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Sec_Color#
FontColor=#Set.Text_Color#
FontFace=#Set.Font#
FontSize=(10*#Sec.S#)
StringAlign=LeftCenter
W=((150-10)*#Sec.S#)
H=((30-10)*#Sec.S#)
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad:M]
[SaveAndLoad:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#Sec.SaveLocation#"][!SetVariable #Editing# "[##Editing#]"][!UpdateMeter *][!Redraw][!Refresh "#JaxCore\Main"][!Refresh "ValliStart\Main"]
Disabled=1
Group=NUOL

[Shape:S]
X=(#sec.P#)R
Y=r
Shape=Rectangle 0,0,((#Sec.W#-#sec.P#*6)/5),((#Sec.W#-#sec.P#*6)/5),#Sec.R# | StrokeWidth 0 | Extend This
This=Fill Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #set.SubText_Color#,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Image:S]
X=r
Y=r
W=((#Sec.W#-#sec.P#*6)/5-#Sec.P#*2)
H=((#Sec.W#-#sec.P#*6)/5-#Sec.P#*2)
Padding=(#Sec.P#),(#Sec.P#),(#Sec.P#),(#Sec.P#)
ImageName=#SKINSPATH#valliStart\@Resources\Images\Orbs\#CURRENTSECTION#.png
LeftMouseUpAction=[!WriteKeyValue Variables IconName "#CURRENTSECTION#" "#Sec.SaveLocation#"][!Refresh "#JaxCore\Main"][!Refresh "ValliStart\Main"][!Refresh]
[Image2:S]
Greyscale=1
ImageTint=#Set.Accent_Color#
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[KeyLabel]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
FontSize=(10*#Sec.S#)
FontColor=#Set.Subtext_Color#
Text=Select an orb for ValliStart!
inlinepattern=#CRLF#.*
inlinesetting=Size | (8*#Sec.S#)
DynamicVariables=1
StringAlign=Center
MeterStyle=Sec.String:S

[Stuff1]
Meter=String
X=(#Sec.P#)
Y=(#Sec.P#)R
Text=Included orbs
FontSize=(15*#sec.S#)
FontWeight=600
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 2.0
MeterStyle=Sec.String:S

[Shape1]
Meter=Shape
X=r
Y=R
MeterStyle=Shape:S
[Win]
Meter=Image
MeterStyle=Image:S
[Shape2]
Meter=Shape
MeterStyle=Shape:S
[Core]
Meter=Image
MeterStyle=Image:S
[Shape3]
Meter=Shape
MeterStyle=Shape:S
[Win11]
Meter=Image
MeterStyle=Image:S
[Shape4]
Meter=Shape
MeterStyle=Shape:S
[Ring]
Meter=Image
MeterStyle=Image:S
[Shape5]
Meter=Shape
MeterStyle=Shape:S
[States]
Meter=Image
MeterStyle=Image:S

[Shape6]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#)R
MeterStyle=Shape:S
[Active]
Meter=Image
MeterStyle=Image:S
[Shape7]
Meter=Shape
MeterStyle=Shape:S
[Arrow]
Meter=Image
MeterStyle=Image:S
[Shape8]
Meter=Shape
MeterStyle=Shape:S
[CircledArrow]
Meter=Image
MeterStyle=Image:S
[Shape9]
Meter=Shape
MeterStyle=Shape:S
[Focus]
Meter=Image
MeterStyle=Image:S
[Shape10]
Meter=Shape
MeterStyle=Shape:S
[List]
Meter=Image
MeterStyle=Image:S
[Shape11]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#)R
MeterStyle=Shape:S
[Pie]
Meter=Image
MeterStyle=Image:S
[Shape12]
Meter=Shape
MeterStyle=Shape:S
[Star]
Meter=Image
MeterStyle=Image:S
[Shape13]
Meter=Shape
MeterStyle=Shape:S
[Wave]
Meter=Image
MeterStyle=Image:S
[Shape14]
Meter=Shape
MeterStyle=Shape:S
[Tiles]
Meter=Image
MeterStyle=Image:S
[Shape15]
Meter=Shape
MeterStyle=Shape:S
[Hold]
Meter=Image
MeterStyle=Image:S

[Stuff2]
Meter=String
X=(#Sec.P#)
Y=(#Sec.P#*2)R
Text=Custom orb
FontSize=(15*#sec.S#)
FontWeight=600
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 2.0
MeterStyle=Sec.String:S
[01]
Meter=String
Text=Orb image name
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[02]
Meter=String
Text=Open orbs image directory
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[iconName]
MEter=Shape
Y=[01:Y]
MeterStyle=Set.TextBox:S
[01value]
Meter=String
Text=#IconName#
MeterStyle=Sec.String:S | Set.Value:S

[button02]
MEter=Shape
Y=[02:Y]
Act=["#SKINSPATH#valliStart\@Resources\Images\Orbs\"]
MeterStyle=Set.Button:S
[02value]
Meter=String
Text=Open
MeterStyle=Sec.String:S | Set.Value:S