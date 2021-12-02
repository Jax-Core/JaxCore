; ---------------------------------------------------------------------------- ;
;                                 UpdateChecker                                ;
; ---------------------------------------------------------------------------- ;
[Variables]
@includeNewsID=#@#NewsID.inc

[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
ifMatch=^#UserNameCheckVariable#$
; ifmatchaction=[!EnableMeasure Check4New:M][!UpdateMeasure "Check4New:M"]
ifnotmatchaction=[!WriteKeyValue Variables Sec.Page 1 "#SKINSPATH#\#JaxCore\Accessories\Tour\Main.ini"][!ActivateConfig "#JaxCore\Accessories\Tour"][!ActivateConfig "#JaxCore\Accessories"][!DeactivateConfig]
DynamicVariables=1
UpdateDivider=-1

; -------------------------------- News check -------------------------------- ;

[NewsParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/%40Resources/NewsID.inc
RegExp==(.*)$
Group=Updater
FinishAction=[!CommandMeasure LogicalScript "checkNews()"]

[mNewsID]
Measure=WebParser
URL=[NewsParser]
Group=Updater
StringIndex=1

[ParseNews]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/Accessories/Popup/Variants/News.inc
RegExp=(?siU).*
Debug=2
Debug2File=#ROOTCONFIGPATH#Accessories\Popup\Variants\News.inc
DynamicVariables=1
Disabled=1
FinishAction=[!commandMeasure Func "startPopup('News')"][!WriteKeyValue Variables News.ID [mNewsID] "#@#NewsID.inc"]

; ------------------------------- Version check ------------------------------ ;

[WebParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/%40Resources/Version.inc
RegExp==(.*)$
Group=Updater
FinishAction=[!Delay 100][!CommandMeasure LogicalScript "check()"]

[mVer]
Measure=WebParser
URL=[WebParser]
Group=Updater
StringIndex=1
; [mVer]
; Measure=String
; String=10000
; OnUpdateAction=[!Delay 100][!CommandMeasure LogicalScript "check()"]
; UpdateDivider=-1

[LogicalScript]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Accessories\UpdatePrompt\Logic.lua

[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\CheckData.ps1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[BC]
MouseScrollDownAction=
MouseScrollUpAction=

[Title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Config hub
X=(#Set.P#+10*[Set.S])
Y=(#Set.H#*0.32)
Group=Scroll
FontSize=(20*[Set.S])
FontFace=Poppins
StringAlign=LeftCenter
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 2.0
[Title.Text2]
Meter=String
MeterStyle=Set.String:S
Text=JaxCore
X=(-10*[Set.S])r
Y=(60*[Set.s])r
FontSize=(60*[Set.S])
FontFace=Poppins SemiBold
StringAlign=LeftCenter
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Text.1]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(78*[Set.S])r
Text=JaxCore is an on-going set of Rainmeter widgets that provide 
[Text.2]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(10*[Set.S])R
Text=numerous functionalities to users
[Text.3]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(10*[Set.S])R
Text=This config hub provides easy access to configuration
[Text.4]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(10*[Set.S])R
Text=updates and new releases


; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;

[SkinsButton]
Meter=Shape
X=(#Set.P#)
Y=(100*[Set.S])r
MeterStyle=Shape.Over:S | Button:S
OverColor=#Set.Accent_Color#
LeaveColor=#Set.Accent_Color#
Leftmouseupaction=[!commandMeasure Func "startPopup('Donate')"]
[SkinsText]
Meter=String
Text=Support me
MeterStyle=Set.String:S | ButtonText:S

[DiscordButton]
Meter=Shape
X=(150/2*[Set.S]+#Set.P#/2)r
Y=(-20*[Set.S])r
DynamicVariables=1
OverColor=88,101,242
LeaveColor=88,101,242,200
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=[!commandMeasure Func "startPopup('Discord')"]
Container=BC
[DiscordIcon]
Meter=Image
MeterStyle=TopButton:S
ImageName=#@#Icons\Discord.png

[DeviantArtButton]
Meter=Shape
X=(30*[Set.S]+#Set.P#/2)r
Y=r
DynamicVariables=1
OverColor=84, 235, 131
LeaveColor=399F59
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=[!commandMeasure Func "startPopup('DeviantArt')"]
Container=BC
[DeviantArtIcon]
Meter=Image
MeterStyle=TopButton:S
ImageName=#@#Icons\DA.png

[ShortcutButton]
Meter=Shape
X=(30*[Set.S]+#Set.P#/2)r
Y=r
DynamicVariables=1
OverColor=255, 179, 51
LeaveColor=FF9834
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=[!commandMeasure Func "startPopup('Shortcut')"]
Container=BC
[ShortcutIcon]
Meter=Image
MeterStyle=TopButton:S
ImageName=#@#Icons\Shortcut.png

[NewsButton]
Meter=Shape
X=(30*[Set.S]+#Set.P#/2)r
Y=r
DynamicVariables=1
OverColor=255, 92, 22
LeaveColor=219, 53, 19
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=[!commandMeasure Func "startPopup('News')"]
Container=BC
[NewsIcon]
Meter=Image
MeterStyle=TopButton:S
ImageName=#@#Icons\News.png

; ---------------------------------------------------------------------------- ;
;                                     Right                                    ;
; ---------------------------------------------------------------------------- ;

[ConvertedShape]
Meter=Shape
X=(#Set.W#-#Set.P#-295*[Set.S])
Y=(#Set.H#/2-(434/2*[Set.S]))
Container=BC
Shape = Path Path1 | stroke color 140, 140, 140 | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Fill LinearGradient This
This= 180 | CC1C1520 ; 0.0 | FF700F20 ; 1.0
Path1 = 297.18398, 94.90905 | CurveTo 297.18398, 116.12225, 303.04184, 100.76691, 303.04184, 110.26439 | LineTo 227.50313, 185.8031 | LineTo 286.31111, 244.61108 | CurveTo 286.31111, 265.82428, 292.16897, 250.46894, 292.16897, 259.96642 | LineTo 116.12226, 436.01313 | CurveTo 94.90906, 436.01313, 110.2644, 441.87099, 100.76692, 441.87099 | LineTo 10.60661, 351.71068 | CurveTo 10.60661, 330.49748, 4.74875, 345.85282, 4.74875, 336.35534 | LineTo 80.28746, 260.81663 | LineTo 21.47948, 202.00865 | CurveTo 21.47948, 180.79545, 15.62162, 196.15079, 15.62162, 186.65331 | LineTo 191.66833, 10.6066 | CurveTo 212.88153, 10.6066, 197.52619, 4.74874, 207.02367, 4.74874 | ClosePath 1
DynamicVariables=1

[Logo]
Meter=Image
ImageName=#@#Images\Logo256.png
X=(#Set.W#-#Set.P#-((256)*[Set.S]))
Y=(#Set.H#/2-((256)*[Set.S])/2)
W=(256*[Set.S])
Y=(256*[Set.S])
Container=BC
; Hidden=(#QoL#)
LeftMouseUpAction=[!commandMeasure Func "startDrop('Dev', '#CURRENTSECTION#', 'JaxCore')"]
DynamicVariables=1