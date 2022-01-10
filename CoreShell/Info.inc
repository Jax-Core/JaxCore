
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
IdleStyle.L=899004964

BetaSkinList=MuzeFlyout

@includepatchNoteChecker=#SKINSPATH##Skin.Name#\@Resources\PatchNoteVar.inc

[CoreBridge]
Measure=Script
ScriptFile=#SKINSPATH##JaxCore\@Resources\Lua\CoreElements\Installer.lua

[Header]
Meter=String
Y=(40*[Set.S])
Container=ContentContainer
DynamicVariables=1
FontFace=#Set.Font# 
FontWeight=(650)
MeterStyle=Set.String:S | Header:1
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
; InlineSetting2=Shadow | 0 | 0 | 2 | CC1C15
Leftmouseupaction=["https://github.com/Jax-Core/#Skin.Name#/releases/latest"]
[Header:2]
Text="One update ahead..."
FontSize=(40*[Set.S])
[Header:1]
Text="#Skin.Name#"
FontSize=(40*[Set.S])
[Header:0]
Text="Update available"
FontSize=(40*[Set.S])
[Shape]
Meter=Shape
X=0
Y=([Header:H]/2)r
Shape=Path This | StrokeWidth 4 | Stroke Color #Set.Accent_Color_2# | StrokeStartCap Triangle | StrokeEndcap Triangle | OffSet -5,0
This=([Header:W]+30*[Set.S]),0 | LineTo ([ContentContainer:W]-50*[Set.S]),0 | LineTo ([ContentContainer:W]-25*[Set.S]),(-25*[Set.S]) | LineTo ([ContentContainer:W]),0 | LineTo ([ContentContainer:W]-25*[Set.S]),(25*[Set.S]) | LineTo ([ContentContainer:W]-30*[Set.S]),(20*[Set.S])
DynamicVariables=1
Container=ContentContainer

[Subheader]
Meter=String
X=0
Y=([Header:YH]-#Set.P#)
W=([ContentContainer:W])
ClipString=2
InlinePattern=v\d.*$
Inlinesetting=Color | #SEt.Accent_Color#
FontColor=150,150,150
FontFace=#Set.Font# Light
MeterStyle=Set.String:S | Subheader:00
Container=ContentContainer
DynamicVariables=1
[Subheader:2]
Text="Currently on a beta build for #Skin.Name#"
FontSize=(15*[Set.S])
[Subheader:1]
Text="On latest v#Version#"
FontSize=(24*[Set.S])
[Subheader:00]
Text="Fetching latest version id..."
FontSize=(24*[Set.S])
[Subheader:0]
Text="Click the download button to install #skin.name# v[mVer]"
FontSize=(15*[Set.S])
[Subheader:3]
Text="This skin isn't installed on your device. Click the download button to install #skin.name# v[mVer]"
FontSize=(15*[Set.S])
[Subheader:4]
Text="This skin is currently in beta! Join the discord server to participate in the discussion!"
FontSize=(15*[Set.S])

;===========================================================================================================================

[Button21]
Meter=Shape
Shape=Rectangle 0,0,100,100,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=0
Y=(30*[Set.S])R
; Y=(#Set.H#-#Set.P#*2-(30*3+5*2)*[Set.S])
OverColor=399F59
LeaveColor=57, 159, 89, 200
Act=["https://www.deviantart.com/jaxoriginals/art/[##SKIN.Name#.L]"]
[Value21]
Meter=Image
Y=((100-48)/2*[Set.S])r
X=((100-48)/2*[Set.S])r
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
DynamicVariables=1
Container=ContentContainer
Group=Buttons
ImageTint=#Set.Text_Color#
ImageName=#@#Icons\DA.png
[Button22]
Meter=Shape
Shape=Rectangle 0,0,100,100,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=((85)*[Set.S])r
Y=(-(100-48)/2*[Set.S])r
OverColor=#set.Text_Color#,50
LeaveColor=#Set.Text_Color#,10
Act=["https://github.com/Jax-Core/#Skin.Name#"]
[Value22]
Meter=Image
Y=((100-48)/2*[Set.S])r
X=((100-48)/2*[Set.S])r
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
DynamicVariables=1
Container=ContentContainer
Group=Buttons
ImageTint=#Set.Text_Color#
ImageName=#@#Icons\Github.png
[ButtonPatchNote]
Meter=Shape
Shape=Rectangle 0,0,100,100,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
X=((85)*[Set.S])r
Y=(-(100-48)/2*[Set.S])r
OverColor=#set.Accent_Color#
LeaveColor=#Set.Accent_Color#,150
Act=[!commandMeasure Func "startPopup('PatchNote', 'Left')"]
Group=PatchNote
[ValuepatchNote]
Meter=Image
Y=((100-48)/2*[Set.S])r
X=((100-48)/2*[Set.S])r
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
DynamicVariables=1
Container=ContentContainer
Group=Buttons | PatchNote
ImageTint=#Set.Text_Color#
ImageName=#@#Icons\ChangeLog.png
[Button23]
Meter=Shape
Shape=Rectangle 0,0,100,100,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
OverColor=#Set.Accent_Color#
LeaveColor=#Set.Accent_Color#
X=((85)*[Set.S])r
Y=(-(100-48)/2*[Set.S])r
; Act=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v[mVer]/#Skin.Name#_v[mVer].rmskin"][!SetVariable DownloadName "#Skin.Name#[mVer]"]["https://www.deviantart.com/jaxoriginals/art/-v1-0-[##SKIN.Name#.L]"][!CommandMeasure Installer "Install"]
Act=[!CommandMeasure CoreBridge "install('#Skin.Name#')"]
Group=DownloadButton
Hidden=1
[Value23]
Meter=Image
X=((100-48)/2*[Set.S])r
Y=((100-48)/2*[Set.S])r
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
DynamicVariables=1
Container=ContentContainer
Group=DownloadButton
ImageTint=#Set.Text_Color#
ImageName=#@#Icons\Install.png
Hidden=1
[Button24]
Meter=Shape
Shape=Rectangle 0,0,100,100,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
MeterStyle=Set.Button:S
OverColor=88, 101, 242
LeaveColor=88, 101, 242
X=(-(100-48)/2*[Set.S])r
Y=(-(100-48)/2*[Set.S])r
Act=["https://discord.gg/JmgehPSDD6"]
Group=DiscordButton
Hidden=1
[Value24]
Meter=Image
Y=((100-48)/2*[Set.S])r
X=((100-48)/2*[Set.S])r
W=(48*[Set.S])
H=(48*[Set.S])
Greyscale=1
DynamicVariables=1
Container=ContentContainer
Group=DiscordButton
ImageName=#@#Icons\Discord.png
Hidden=1

[Description]
Meter=String
X=0
Y=((100-48)/2+55*[Set.S])r
W=(#Set.W#*0.4)
ClipString=2
FontSize=(12*[Set.S])
FontColor=150,150,150
FontFace=#Set.Font# Light
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
OverColor=#Set.Ter_Color#
LeaveColor=#Set.Ter_Color#,150
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
OverColor=#Set.Sec_Color#
LeaveColor=#Set.Sec_Color#,150
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
URL=https://raw.githubusercontent.com/Jax-Core/#Skin.Name#/main/%40Resources/Version.inc
RegExp==(.*)$
Disabled=1
FinishAction=[!Delay 100][!EnableMeasure mC4U][!UpdateMeasure mC4U]
Group=checkForBeta
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
IfTrueAction3=[!SetOption Header MeterStyle "Set.String:S | Header:0"][!SetOption Subheader MeterStyle "Set.String:S | Subheader:0"][!ShowMeterGroup DownloadButton][!UpdateMeter *][!Redraw]
IfNotMatchAction=

[mCheckforPresence]
Measure=String
String=#*Version*#
IfMatch=#Version#
IfMatchAction=[!SetOption Header MeterStyle "Set.String:S | Header:1"][!SetOption Subheader MeterStyle "Set.String:S | Subheader:3"][!ShowMeterGroup DownloadButton][!DisableMouseActionGroup * Set.SideButtons][!SetOptionGroup Set.SideIcons ImageAlpha 100][!UpdateMeter *][!Redraw]
IfMatchMode=1
Disabled=1
Group=checkForBeta

[VersionList]
Measure=WebParser
URL=https://api.github.com/repos/Jax-Core/#Skin.Name#/releases
RegExp=(?siU).*
Debug=2
Debug2File=#@#Includes\APIDump.txt
DynamicVariables=1
Disabled=1
FinishAction=[!CommandMeasure VersionScript "parse()"]
[VersionScript]
Measure=Script
ScriptFile=#@#Lua\VersionScript.lua
DynamicVariables=1

[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
ifMatch=^#UserNameCheckVariable#$
; ifmatchaction=[!EnableMeasure Check4New:M][!UpdateMeasure "Check4New:M"]
ifnotmatchaction=[!WriteKeyValue Variables Sec.Page 1 "#SKINSPATH#\#JaxCore\Accessories\Tour\Main.ini"][!ActivateConfig "#JaxCore\Accessories\Tour"][!ActivateConfig "#JaxCore\Accessories"][!DeactivateConfig]
DynamicVariables=1
OnUpdateAction=[!CommandMeasure VersionScript "patchNoteCheck('[MeasureUser]')"]