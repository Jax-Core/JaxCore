
[Variables]
BarHandler=1

Combilaunch.L=881177085
Plainext.L=881628513
ModularClocks.L=883898019
MIUI-Shade.L=885183361
ModularPlayers.L=886577256
Keystrokes.L=889349339
Keylaunch.L=890749449
ValliStart.L=893506095
QuickNote.L=894951390

[Installer]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1

; [ImageContainer]
; Meter=Shape
; X=(#Set.L#+#Set.P#)
; Y=#Set.P#
; Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill LinearGradient1 This
; This=180 | 0,0,0,0 ; 0.0 | 0,0,0 ; 1.0
; DynamicVariables=1
[Image]
Meter=Image
X=((#Set.W#-#Set.L#-#Set.P#*2)/2-(#Set.H#-#Set.P#*2)/2)
W=(#Set.H#-#Set.P#*2)
H=(#Set.H#-#Set.P#*2)
Container=ContentContainer
DynamicVariables=1
ImageAlpha=10
ImageName=#@#Images\Unified\#Skin.Name#.png
PreserveAspectRatio=1

[Header]
Meter=String
X=([ContentContainer:W]/2)
Y=([ContentContainer:H]/2)
Container=ContentContainer
DynamicVariables=1
StringAlign=CenterCenter
Text=#Skin.Name#
FontSize=(30*[Set.S])
FontFace=Poppins Medium
MeterStyle=Set.String:S
Leftmouseupaction=[https://github.com/EnhancedJax/#Skin.Name#/releases/latest]
[Subheader]
Meter=String
X=r
Y=(-10*[Set.S])R
StringAlign=CenterCenter
Text=Fetching latest version id...
InlinePattern=v#Version#
Inlinesetting=Color | #SEt.Accent_Color#
FontColor=150,150,150
FontSize=(13*[Set.S])
FontFace=Poppins Light
MeterStyle=Set.String:S
Container=ContentContainer

[Obj.6]
Meter=Shape
X=(-200/2*[Set.S])r
Y=(40*[Set.S])r
DynamicVariables=1
Shape=Rectangle 0,0,200,45,(#Set.R#) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend THis
OverColor=#Set.Accent_Color#
LeaveColor=#Set.Accent_Color#
Leftmouseupaction=[!SetVariable DownloadLink "https://github.com/EnhancedJax/#Skin.Name#/releases/download/v[mVer]/#Skin.Name#_v[mVer].rmskin"][!SetVariable DownloadName "#Skin.Name#[mVer]"]["https://www.deviantart.com/jaxoriginals/art/-v1-0-[##SKIN.Name#.L]"][!CommandMeasure Installer "Install"]
MeterStyle=Shape.Over:S
Group=DownloadButton
Hidden=1
Container=ContentContainer
[Obj.6.Child]
Meter=String
X=(200/2*[Set.S])r
y=(45/2*[Set.S])r
FontSize=(15*[Set.S])
FontFace=Poppins 
StringAlign=CenterCenter
Text=Download
Group=DownloadButton
Hidden=1
Container=ContentContainer
MeterStyle=SEt.String:S | ButtonT:S

;===========================================================================================================================

[GitHub]
Meter=Image
Y=R
X=([ContentContainer:W]/2-(48*[Set.S])-5)
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
ImageTint=#Set.SubText_Color#
DynamicVariables=1
Container=ContentContainer
Group=Buttons
ImageName=#@#Icons\#CURRENTSECTION#.png
Leftmouseupaction=["https://github.com/EnhancedJax/#Skin.Name#"]
[DA]
Meter=Image
Y=r
X=(10)R
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
ImageTint=#Set.SubText_Color#
DynamicVariables=1
Group=Buttons
Container=ContentContainer
ImageName=#@#Icons\#CURRENTSECTION#.png
Leftmouseupaction=["https://www.deviantart.com/jaxoriginals/art/[##SKIN.Name#.L]"]

;===========================================================================================================================

[WebParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/#Skin.Name#/main/%40Resources/Version.inc
RegExp==(.*)$
FinishAction=[!EnableMeasure mC4U][!UpdateMeasure mC4U]
[mVer]
Measure=WebParser
URL=[WebParser]
StringIndex=1
; [mVer]
; Measure=Calc
; Formula=3.0
; OnUpdateAction=[!EnableMeasure mC4U][!UpdateMeasure mC4U]

[mC4U]
Measure=Calc
Formula=[mVer]
DynamicVariables=1
Disabled=1
IfconditionMode=1
Ifcondition=mC4U = #Version#
IfTrueAction=[!SetOption Subheader Text "Up to date v#Version#"][!UpdateMeter *][!Redraw]
IfCondition2=mC4U < #Version#
IfTrueAction2=[!SetOption Header Text "One update ahead..."][!SetOption Subheader Text "Currently on a beta build for #Skin.Name#"][!UpdateMeter *][!Redraw]
IfCondition3=mC4U > #Version#
IfTrueAction3=[!SetOption Header Text "Update available"][!SetOption Subheader Text "Click here to be directed to the download page for #Skin.Name#"][!ShowMeterGroup DownloadButton][!HideMeterGroup Buttons][!UpdateMeter *][!Redraw]
IfNotMatchAction=

[mCheckforPresence]
Measure=String
String=#*Version*#
IfMatch=#Version#
IfMatchAction=[!SetOption Header Text "#Skin.Name# isn't installed"][!SetOption Subheader Text "Click here to be directed to the download page for #Skin.Name#"][!ShowMeterGroup DownloadButton][!HideMeterGroup Buttons][!DisableMouseActionGroup * Set.SideButtons][!SetOptionGroup Set.SideIcons ImageAlpha 100][!UpdateMeter *][!Redraw]
IfMatchMode=1