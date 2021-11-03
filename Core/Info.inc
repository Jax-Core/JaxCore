
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
; Container=ContentContainer
; ; X=(#Set.L#+#Set.P#)
; ; Y=#Set.P#
; Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill LinearGradient1 This
; This=250 | #Set.Accent_Color#,0 ; 0.8 | #Set.Accent_Color# ; 1.0
; DynamicVariables=1
; [Image]
; Meter=Image
; X=(#Set.W#-#Set.L#-#Set.P#-[Image:W])
; H=(#Set.H#-#Set.P#*2)
; Container=ImageContainer
; DynamicVariables=1
; ImageAlpha=255
; ImageName=#@#Images\Cards\#Skin.name#.png

[Header]
Meter=String
Y=(40*[Set.S])
Container=ContentContainer
DynamicVariables=1
FontFace=Poppins Bold
MeterStyle=Set.String:S | Header:1
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
; InlineSetting2=Shadow | 0 | 0 | 2 | CC1C15
Leftmouseupaction=[https://github.com/EnhancedJax/#Skin.Name#/releases/latest]
[Header:2]
Text=One update ahead...
FontSize=(40*[Set.S])
[Header:1]
Text=#Skin.Name#
FontSize=(60*[Set.S])
[Header:0]
Text=Update available
FontSize=(40*[Set.S])
[Shape]
Meter=Shape
X=0
Y=([Header:H]/2)r
Shape=Path This | StrokeWidth 4 | Stroke Color FF700F | StrokeStartCap Triangle | StrokeEndcap Triangle | OffSet -5,0
This=([Header:W]+30*[Set.S]),0 | LineTo ([ContentContainer:W]-50*[Set.S]),0 | LineTo ([ContentContainer:W]-25*[Set.S]),(-25*[Set.S]) | LineTo ([ContentContainer:W]),0 | LineTo ([ContentContainer:W]-25*[Set.S]),(25*[Set.S]) | LineTo ([ContentContainer:W]-30*[Set.S]),(20*[Set.S])
DynamicVariables=1
Container=ContentContainer

[Subheader]
Meter=String
X=0
Y=([Header:YH]-#Set.P#)
InlinePattern=v#Version#
Inlinesetting=Color | #SEt.Accent_Color#
FontColor=150,150,150
FontFace=Poppins Light
MeterStyle=Set.String:S | Subheader:00
Container=ContentContainer
[Subheader:2]
Text=Currently on a beta build for #Skin.Name#
FontSize=(15*[Set.S])
[Subheader:1]
Text=On latest v#Version#
FontSize=(24*[Set.S])
[Subheader:00]
Text=Fetching latest version id...
FontSize=(24*[Set.S])
[Subheader:0]
Text=Click here to be directed to the download page for #Skin.Name#
FontSize=(15*[Set.S])

[Obj.6]
Meter=Shape
X=r
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

[Button21]
Meter=Shape
Shape=Rectangle 0,0,100,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=0
Y=R
; Y=(#Set.H#-#Set.P#*2-(30*3+5*2)*[Set.S])
OverColor=399F59
LeaveColor=57, 159, 89, 200
Act=["https://www.deviantart.com/jaxoriginals/art/[##SKIN.Name#.L]"]
[Value21]
Meter=String
X=(100/2*[Set.S])r
StringAlign=CenterCenter
Text=DeviantArt
MeterStyle=Set.String:S | Set.Value:S
[Button22]
Meter=Shape
Shape=Rectangle 0,0,100,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=((100/2+10)*[Set.S])r
Y=(-30/2*[Set.S])r
Act=["https://github.com/EnhancedJax/#Skin.Name#"]
[Value22]
Meter=String
X=(100/2*[Set.S])r
StringAlign=CenterCenter
Text=Github
MeterStyle=Set.String:S | Set.Value:S

[Description]
Meter=String
X=0
Y=(#Set.P#)R
W=(#Set.W#*0.4)
ClipString=2
FontSize=(12*[Set.S])
FontColor=150,150,150
FontFace=Poppins Light
MeterStyle=Set.String:S
Container=ContentContainer

[Button01]
Meter=Shape
Shape=Rectangle 0,0,175,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=0
Y=#Set.P#R
; Y=(#Set.H#-#Set.P#*2-(30*3+5*2)*[Set.S])
OverColor=#Set.Accent_Color#
LeaveColor=#Set.Accent_Color#,150
Act=["#SKINSPATH##Skin.Name#\"]
[Value01]
Meter=String
X=(175/2*[Set.S])r
StringAlign=CenterCenter
Text=Open folder
MeterStyle=Set.String:S | Set.Value:S
[Button02]
Meter=Shape
Shape=Rectangle 0,0,175,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=0
Y=(5*[Set.S])R
Act=["#SKINSPATH##Skin.Name#\@Resources\Vars.inc"]
[Value02]
Meter=String
X=(175/2*[Set.S])r
StringAlign=CenterCenter
Text=Config file
MeterStyle=Set.String:S | Set.Value:S
[Button03]
Meter=Shape
Shape=Rectangle 0,0,175,30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=0
Y=(5*[Set.S])R
OverColor=#Set.Subtext_Color#
LeaveColor=#Set.Sec_Color#
Act=[!CommandMeasure VersionScript "activateParse()"]
[Value03]
Meter=String
X=(175/2*[Set.S])r
StringAlign=CenterCenter
Text=Rollback version
MeterStyle=Set.String:S | Set.Value:S

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

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
IfTrueAction=[!SetOption Subheader MeterStyle "Set.String:S | Subheader:1"][!UpdateMeter *][!Redraw]
IfCondition2=mC4U < #Version#
IfTrueAction2=[!SetOption Header MeterStyle "Set.String:S | Header:2"][!SetOption Subheader MeterStyle "Set.String:S | Subheader:2"][!UpdateMeter *][!Redraw]
IfCondition3=mC4U > #Version#
IfTrueAction3=[!SetOption Header MeterStyle "Set.String:S | Header:0"][!SetOption Subheader MeterStyle "Set.String:S | Subheader:0"][!ShowMeterGroup DownloadButton][!HideMeterGroup Buttons][!UpdateMeter *][!Redraw]
IfNotMatchAction=

[mCheckforPresence]
Measure=String
String=#*Version*#
IfMatch=#Version#
IfMatchAction=[!SetOption Header Text "#Skin.Name# isn't installed"][!SetOption Subheader Text "Click here to be directed to the download page for #Skin.Name#"][!ShowMeterGroup DownloadButton][!HideMeterGroup Buttons][!DisableMouseActionGroup * Set.SideButtons][!SetOptionGroup Set.SideIcons ImageAlpha 100][!UpdateMeter *][!Redraw]
IfMatchMode=1

[VersionList]
Measure=WebParser
URL=https://api.github.com/repos/EnhancedJax/#Skin.Name#/releases
RegExp=(?siU).*
Debug=2
Debug2File=#@#Includes\APIDump.txt
DynamicVariables=1
Disabled=1
FinishAction=[!CommandMeasure VersionScript "parse()"]
[VersionScript]
Measure=Script
ScriptFile=#@#Lua\VersionScript.lua

; [SkinConfig]
; Measure=Script
; ScriptFile=#@#Lua\SkinConfig.lua