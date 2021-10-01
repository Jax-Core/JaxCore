
[Rainmeter]
OnRefreshAction=[!Delay 100][!EnableMeasureGroup NUOL][!SetOption [##arg1#TimeFormat] MeterStyle "Sec.Button:S | Sec.Button2:S"][!UpdateMeter [##arg1#TimeFormat]][!Redraw]

[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Data\#arg1#Data.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
@includeSkinData=#SKINSPATH##Skin.Name#\@Resources\Data\#arg1#Data.inc
@includeSkinvars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc



[Sec.Button:S]
X=(((#Sec.W#-#Sec.P#*3)/4)+#Sec.P#)r
Y=(-30/2*#sec.S#)r
Shape=Rectangle 0,0,((#Sec.W#-#Sec.P#*3)/2),(30*#Sec.S#),#Sec.R# | StrokeWidth 0 | Extend This
This=fill Color 100,100,100,100
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables #arg1#TimeFormat #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!Refresh "ModularClocks\Main"]
[Sec.Button2:S]
This=fill Color 100,100,100,200

[Sec.Text:S]
X=((#Sec.W#-#Sec.P#*3)/4)r
Y=(30/2*#Sec.S#)r
DynamicVariables=1
StringAlign=CenterCenter

[Input:M]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Ter_Color#
FontColor=#Set.Text_Color#
FontFace=Poppins
FontSize=(10*#Sec.S#)
StringAlign=LeftCenter
W=((150-10)*#Sec.S#)
H=((30-10)*#Sec.S#)
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad:M]
Command2=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad2:M]
[SaveAndLoad:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#Sec.SaveLocation#"][!SetVariable #Editing# "[##Editing#]"][!UpdateMeter *][!Redraw][!Refresh "ModularClocks\Main"]
Disabled=1
Group=NUOL
[SaveAndLoad2:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#Sec.SaveLocation2#"][!SetVariable #Editing# "[##Editing#]"][!UpdateMeter *][!Redraw][!Refresh "ModularClocks\Main"]
Disabled=1
Group=NUOL

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
Leftmouseupaction=[!SetVariable Editing "#arg1##CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*#Sec.S#)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*#Sec.S#)"][!CommandMeasure Input:M "ExecuteBatch 1"]

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

[Set.ColorPacity:S]
X=(#Sec.W#-#Sec.P#-150*#Sec.S#)
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale #sec.S#,#sec.S#,0,0
Shape2=Ellipse (135*#sec.S#),(15*#sec.S#),(10*#sec.S#) | StrokeWidth 0 | Fill Color [##CURRENTSECTION#Color]
Fill=Stroke Color #Set.Text_Color#,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,15"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#Color" "FileName=#Sec.SaveLocation2#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main | #JaxCore\Main"]
RightMOuseUpAction=[!SetVariable Editing "#CURRENTSECTION#Opacity"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 2"]
[Set.Pacity:S]
X=(5*#sec.S#)r
Y=(15*#sec.S#)r
StringAlign=LeftCenter
FontSize=(10*#sec.S#)
Stringeffect=Shadow
Prefix="Opacity// "
DynamicVariables=1

[Set.Bool:S]
X=(#Sec.W#-#Sec.P#-50*#Sec.S#)
Shape=Rectangle 0,0,50,20,10,10 | StrokeWidth 0 | Extend Fill | Scale #Sec.S#,#Sec.S#,0,0
Shape2=Ellipse ([##CURRENTSECTION#] = 1 ? (40*#Sec.S#) : (10*#Sec.S#)),(10*#Sec.S#),(6*#Sec.S#) | StrokeWidth 0 | Fill Color #Set.Text_Color#
DynamicVariables=1
Fill=Fill Color ([##CURRENTSECTION#] = 1 ? 35 : 181),([##CURRENTSECTION#] = 1 ? 209 : 181),([##CURRENTSECTION#] = 1 ? 96 : 181)
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation2#"][!Refresh][!Refresh "ModularClocks\Main"]



[Checker]
Measure=String
String=#Arg1#
Ifmatch=Main
Ifmatchaction=[!HideMeterGroup NotMain]


; ---------------------------------------------------------------------------- ;
;                                    Visual                                    ;
; ---------------------------------------------------------------------------- ;

[KeyLabel]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
FontSize=(10*#Sec.S#)
FontColor=#Set.Subtext_Color#
Text=Customizing: #arg1#
inlinepattern=#CRLF#.*
inlinesetting=Size | (8*#Sec.S#)
DynamicVariables=1
StringAlign=Center
MeterStyle=Sec.String:S

[Stuff1]
Meter=String
X=(#Sec.P#)
Y=(#Sec.P#)R
Text=Value format
FontSize=(15*#sec.S#)
FontWeight=600
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 2.0
MeterStyle=Sec.String:S

[1]
Meter=Shape
X=r
Y=(#Sec.P#/4)R
MeterStyle=Sec.Button:S
[Item1]
Meter=String
Text=Standard clock
MeterStyle=Sec.String:S | Sec.Text:S
[2]
Meter=Shape
MeterStyle=Sec.Button:S
[Item2]
Meter=String
Text=Text clock
MeterStyle=Sec.String:S | Sec.Text:S

[3]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#/4)R
MeterStyle=Sec.Button:S
[Item3]
Meter=String
Text=Day of the week
MeterStyle=Sec.String:S | Sec.Text:S
[4]
Meter=Shape
MeterStyle=Sec.Button:S
[Item4]
Meter=String
Text=Day of the month
MeterStyle=Sec.String:S | Sec.Text:S

[5]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#/4)R
MeterStyle=Sec.Button:S
[Item5]
Meter=String
Text=Month
MeterStyle=Sec.String:S | Sec.Text:S
[6]
Meter=Shape
MeterStyle=Sec.Button:S
[Item6]
Meter=String
Text=Month, Date
MeterStyle=Sec.String:S | Sec.Text:S

[7]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#/4)R
MeterStyle=Sec.Button:S
[Item7]
Meter=String
Text=Greeting
MeterStyle=Sec.String:S | Sec.Text:S
[8]
Meter=Shape
MeterStyle=Sec.Button:S
[Item8]
Meter=String
Text=Custom time format
FontColor=#Set.Text_Color#,150
MeterStyle=Sec.String:S | Sec.Text:S

; [Custom]
; Meter=String
; Text=Custom
; X=#Sec.P#
; Y=(#Sec.P#)R
; MeterStyle=Sec.String:S
; ---------------------------------------------------------------------------- ;
;                                    Stuff2                                    ;
; ---------------------------------------------------------------------------- ;

[Stuff2]
Meter=String
X=(#Sec.P#)
Y=(#Sec.P#)R
Text=Appearance
FontSize=(15*#sec.S#)
FontWeight=600
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 2.0
MeterStyle=Sec.String:S
[01]
Meter=String
Text=Font size
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[02]
Meter=String
Text=Font face
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[04]
Meter=String
Text=Displacement X
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
Group=NotMain
[05]
Meter=String
Text=Displacement Y
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
Group=NotMain

; ---------------------------------------------------------------------------- ;
;                                    Filling                                   ;
; ---------------------------------------------------------------------------- ;

[Stuff3]
Meter=String
X=(#Sec.P#)
Y=(#Sec.P#)R
Text=Filling
FontSize=(15*#sec.S#)
FontWeight=600
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 2.0
MeterStyle=Sec.String:S
[11]
Meter=String
Text=Text filling method
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S

@includeFillSettings=ClocksFilling\Fill[#[#arg1]fill].inc
; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Fontsize]
MEter=Shape
Y=[01:Y]
MeterStyle=Set.TextBox:S
[01value]
Meter=String
Text=[##arg1#FontSize]
MeterStyle=Sec.String:S | Set.Value:S
[Fontface]
MEter=Shape
Y=[02:Y]
MeterStyle=Set.TextBox:S
[02value]
Meter=String
Text=[##arg1#FontFace]
MeterStyle=Sec.String:S | Set.Value:S
[Button11]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!commandMeasure Func "startDrop('Filling', '#CURRENTSECTION#', '#SKin.Name#', '#arg1#')"]
Y=[11:Y]
[Value11]
Meter=String
Text=[##arg1#fill]
MeterStyle=Sec.String:S | Set.Value:S
[DisX]
MEter=Shape
Y=[04:Y]
MeterStyle=Set.TextBox:S
Group=NotMain
[04value]
Meter=String
Text=[##arg1#DisX]
MeterStyle=Sec.String:S | Set.Value:S
Group=NotMain
[DisY]
MEter=Shape
Y=[05:Y]
MeterStyle=Set.TextBox:S
Group=NotMain
[05value]
Meter=String
Text=[##arg1#DisY]
MeterStyle=Sec.String:S | Set.Value:S
Group=NotMain

; [customTime]
; MEter=Shape
; Y=[Custom:Y]
; X=(#Sec.W#-#Sec.P#-300*#Sec.S#)
; Shape=Rectangle 0,0,300,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale #Sec.S#,#Sec.S#,0,0
; MeterStyle=Set.TextBox:S
; [Customvalue]
; Meter=String
; Text=[##arg1#CustomTime]
; MeterStyle=Sec.String:S | Set.Value:S