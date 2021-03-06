
[DragBar.Shape]
Meter=Shape
X=(#Set.WinB#/2)
Y=(#Set.WinB#/2)
Shape=Rectangle 0,0,#Set.W#,(#Set.TB#),#Set.WinR# | StrokeWidth #Set.WinB# | Fill Color #Set.Ter_Color# | Stroke Color #Set.Ter_Color#
MouseOverAction=[!CommandMeasure WindowHandler ToggleDrag(1)]
MouseLeaveAction=[!CommandMeasure WindowHandler ToggleDrag(0)]
LeftMouseDoubleClickAction=[!CommandMeasure WindowHandler ToggleMaximize()]
MouseActionCursor=0
DynamicVariables=1
[DragBar.Image]
Meter=Image
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo64.png
X=(5*[Set.S])r
Y=(5*[Set.S])r
W=(#Set.Tb#-10*[Set.S])
H=(#Set.Tb#-10*[Set.S])
DynamicVariables=1
[DragBar.String]
Meter=String
Text=#Sec.drag_bar_text#
X=(10*[Set.S])R
y=(#Set.WinB#/2+#Set.Tb#/2)
FontSize=(8*[Set.S])
FontColor=#Set.SubText_Color# 
MeterStyle=Set.String:s | DragBar.String:S1
StringAlign=LeftCenter
Container=

[WindowControl.Maximize]
Meter=String
X=(#Set.W#-#Set.TB#/2*5)
Y=(#Set.TB#/2+1)
W=(#Set.TB#+1)
H=(#Set.TB#+1)
SolidColor=0,0,0,1
MeterStyle=Set.String:S | WindowControl.Maximize:#Set.Maximized#
Fontface=Material Icons Round
FontSize=(14*[Set.S])
FontColor=#Set.Text_Color#,50
StringAlign=CenterCenter
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "#Set.Text_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "#Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure WindowHandler ToggleMaximize()]
InlineSetting=Shadow | 0 | 0 | 5 | #Set.Pri_Color#
Container=
[WindowControl.Maximize:0]
Text=[\xe5d0]
[WindowControl.Maximize:1]
Text=[\xe5d1]

[WindowControl.Home]
Meter=String
X=(#Set.W#-#Set.TB#/2*3)
Y=(#Set.TB#/2+1)
W=(#Set.TB#+1)
H=(#Set.TB#+1)
SolidColor=0,0,0,1
Text=[\xe88a]
MeterStyle=Set.String:S
Fontface=Material Icons Round
FontSize=(14*[Set.S])
FontColor=#Set.Text_Color#,50
StringAlign=CenterCenter
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "#Set.Text_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "#Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Sec.Page "0" "#ROOTCONFIGPATH#Main\Home.ini"][!ActivateConfig "#CURRENTCONFIG#" "Home.ini"]
InlineSetting=Shadow | 0 | 0 | 5 | #Set.Pri_Color#
Container=

[WindowControl.Esc]
Meter=String
X=(#Set.W#-#Set.TB#/2)
Y=(#Set.TB#/2+1)
W=(#Set.TB#+1)
H=(#Set.TB#+1)
SolidColor=0,0,0,1
Text=[\xef4a]
MeterStyle=Set.String:S
Fontface=Material Icons Round
FontSize=(8*[Set.S])
FontColor=#Set.Text_Color#,50
StringAlign=CenterCenter
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "#Set.Text_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "#Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!WriteKeyValue variables Sec.page 0 "#ROOTCONFIGPATH#Main\Home.ini"][!DeactivateConfig]
RightMOuseUpAction=[!commandMeasure Func "startDrop('Rainmeter', '#CURRENTSECTION#', 'JaxCore')"]
InlineSetting=Shadow | 0 | 0 | 5 | #Set.Pri_Color#
Container=