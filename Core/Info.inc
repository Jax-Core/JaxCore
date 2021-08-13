
[Variables]
BarHandler=1

[ImageContainer]
Meter=Shape
X=(#Set.L#+#Set.P#)
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill LinearGradient1 This
This=180 | 0,0,0,0 ; 0.0 | 0,0,0,25; 0.45 | 0,0,0,25 ; 0.55 | 0,0,0,0 ; 1.0
DynamicVariables=1
[Image]
Meter=Image
X=((#Set.W#-#Set.L#-#Set.P#*2)/2-(#Set.H#-#Set.P#*2)/2)
W=(#Set.H#-#Set.P#*2)
H=(#Set.H#-#Set.P#*2)
Container=ImageContainer
DynamicVariables=1
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
Y=R
StringAlign=CenterCenter
Text=CHECKING FOR UPDATES
FontColor=150,150,150
FontSize=(12*[Set.S])
FontFace=Poppins Light
MeterStyle=Set.String:S
Container=ContentContainer

[DownloadButton]
Meter=String
X=r
Y=(5*[Set.S])R
StringAlign=CenterCenter
Text=< Click here for express installation >
FontColor=0,255,100
FontSize=(12*[Set.S])
FontWeight=400
Hidden=1
DynamicVariables=1
Leftmouseupaction=[!WriteKeyValue Data DownloadLink "https://github.com/EnhancedJax/#Skin.Name#/releases/download/v[mVer]/#Skin.Name#_v[mVer].rmskin" "#@#Actions\InstallData.ini"][!WriteKeyValue Data SaveLocation "#@#Actions" "#@#Actions\InstallData.ini"]["#@#Actions\AHK.exe" "#@#Actions\Installer.ahk"]
MeterStyle=Set.String:S
Container=ContentContainer

;===========================================================================================================================


;===========================================================================================================================

[WebParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/#Skin.Name#/main/%40Resources/Version.inc
RegExp==(.*)$
FinishAction=[!Delay 1000][!EnableMeasure mC4U][!UpdateMeasure mC4U]

[mVer]
Measure=WebParser
URL=[WebParser]
StringIndex=1

[mC4U]
Measure=Calc
Formula=[mVer]
DynamicVariables=1
Disabled=1
IfconditionMode=1
Ifcondition=mC4U = #Version#
IfTrueAction=[!SetOption Subheader Text "Up to date - #Version#"][!UpdateMeter *][!Redraw]
IfCondition2=mC4U < #Version#
IfTrueAction2=[!SetOption Header Text "One update ahead..."][!SetOption Subheader Text "Currently on a beta build for #Skin.Name#"][!UpdateMeter *][!Redraw]
IfCondition3=mC4U > #Version#
IfTrueAction3=[!SetOption Header Text "Update available"][!SetOption Subheader Text "Click here to be directed to the download page for #Skin.Name#"][!ShowMeter DownloadButton][!UpdateMeter *][!Redraw]
IfNotMatchAction=

[mCheckforPresence]
Measure=String
String=#*Version*#
IfMatch=#Version#
IfMatchAction=[!SetOption Header Text "#Skin.Name# - Not installed"][!SetOption Subheader Text "Click here to be directed to the download page for #Skin.Name#"][!ShowMeter DownloadButton][!DisableMouseActionGroup * Set.SideButtons][!SetOptionGroup Set.SideIcons ImageAlpha 100][!UpdateMeter *][!Redraw]
IfMatchMode=1


; ---------------------------------------------------------------------------- ;
;                                 DrawSettings                                 ;
; ---------------------------------------------------------------------------- ;


[Set.GeneratePages:M]
Measure=Script
ScriptFile=#@#Lua\GenSet.lua

[Set.Refresh:M]
Measure=Script
ScriptFile=#@#Lua\Refresh.lua
Refreshed=0