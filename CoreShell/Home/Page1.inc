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
; ifnotmatchaction=[!WriteKeyValue Variables Sec.Page 1 "#SKINSPATH#\#JaxCore\Accessories\Tour\Main.ini"][!ActivateConfig "#JaxCore\Accessories\Tour"][!ActivateConfig "#JaxCore\Accessories"][!DeactivateConfig]
ifnotmatchaction=[!CommandMeasure Func "interactionBox('tour1')"][!DeactivateConfig]
ifmatchaction=
DynamicVariables=1
UpdateDivider=-1

; -------------------------------- News check -------------------------------- ;

[NewsParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/CoreWebResources.inc
RegExp=NewsID=(.*)$
Group=Updater
FinishAction=[!CommandMeasure LogicalScript "checkNews()"]

[mNewsID]
Measure=WebParser
URL=[NewsParser]
Group=Updater
StringIndex=1

[ParseNews]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/Accessories/Popup/Variants/CoreNews.inc
RegExp=(?siU).*
Debug=2
Debug2File=#ROOTCONFIGPATH#Accessories\Popup\Variants\CoreNews.inc
DynamicVariables=1
Disabled=1
FinishAction=[!commandMeasure Func "startPopup('CoreNews', 'Left')"][!WriteKeyValue Variables Core.NewsID [mNewsID] "#@#NewsID.inc"]

; ------------------------------- Version check ------------------------------ ;

[WebParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/%40Resources/Version.inc
RegExp==(.*)$
Group=Updater
FinishAction=[!CommandMeasure LogicalScript "check()"]

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
Y=(#Set.H#*0.35)
Group=Scroll
FontSize=(20*[Set.S])
FontFace=#Set.Font#
StringAlign=LeftCenter
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 2.0
[Title.Text2]
Meter=String
MeterStyle=Set.String:S
Text=JaxCore
X=(-10*[Set.S])r
Y=(60*[Set.s])r
FontSize=(60*[Set.S])
FontFace=#Set.Font# 
FontWeight=(650)
StringAlign=LeftCenter
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0

[Text.1]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(78*[Set.S])r
Text=JaxCore is a set of modules designed to give you better desktop experience
[Text.2]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(10*[Set.S])R
Text=With this configuration hub, you can easily access settings, updates, and new releases


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
; OverColor=88,101,242
; LeaveColor=88,101,242,200
OverColor=#Set.Text_Color#,50
LeaveColor=0,0,0,1
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=["https://discord.gg/JmgehPSDD6"]
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
; OverColor=84, 235, 131
; LeaveColor=399F59
OverColor=#Set.Text_Color#,50
LeaveColor=0,0,0,1
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=["https://www.deviantart.com/jaxoriginals"]
Container=BC
[DeviantArtIcon]
Meter=Image
MeterStyle=TopButton:S
ImageName=#@#Icons\DA.png

[WebsiteButton]
Meter=Shape
X=(30*[Set.S]+#Set.P#/2)r
Y=r
DynamicVariables=1
; OverColor=255, 179, 51
; LeaveColor=FF9834
OverColor=#Set.Text_Color#,50
LeaveColor=0,0,0,1
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=["https://jax-core.github.io/"]
Container=BC
[WebsiteIcon]
Meter=Image
MeterStyle=TopButton:S
ImageName=#@#Icons\Website.png

[NewsButton]
Meter=Shape
X=(30*[Set.S]+#Set.P#/2)r
Y=r
DynamicVariables=1
; OverColor=255, 92, 22
; LeaveColor=219, 53, 19
OverColor=#Set.Text_Color#,50
LeaveColor=0,0,0,1
Shape=Rectangle 0,0,40,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
MeterStyle=Shape.Over:S
Leftmouseupaction=[!commandMeasure Func "startPopup('CoreNews', 'Left')"]
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
This= GradientColor | 180 | #Set.Accent_Color#,51 ; 0.0 | #Set.Accent_Color_2#,51 ; 2.0
Path1 = 297.18398, 94.90905 | CurveTo 297.18398, 116.12225, 303.04184, 100.76691, 303.04184, 110.26439 | LineTo 227.50313, 185.8031 | LineTo 286.31111, 244.61108 | CurveTo 286.31111, 265.82428, 292.16897, 250.46894, 292.16897, 259.96642 | LineTo 116.12226, 436.01313 | CurveTo 94.90906, 436.01313, 110.2644, 441.87099, 100.76692, 441.87099 | LineTo 10.60661, 351.71068 | CurveTo 10.60661, 330.49748, 4.74875, 345.85282, 4.74875, 336.35534 | LineTo 80.28746, 260.81663 | LineTo 21.47948, 202.00865 | CurveTo 21.47948, 180.79545, 15.62162, 196.15079, 15.62162, 186.65331 | LineTo 191.66833, 10.6066 | CurveTo 212.88153, 10.6066, 197.52619, 4.74874, 207.02367, 4.74874 | ClosePath 1
DynamicVariables=1

[Logo]
Meter=Image
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png
X=(#Set.W#-#Set.P#-((256)*[Set.S]))
Y=(#Set.H#/2-((256)*[Set.S])/2)
W=(256*[Set.S])
Y=(256*[Set.S])
Container=BC
; Hidden=(#QoL#)
LeftMouseUpAction=[!commandMeasure Func "startDrop('Dev', '#CURRENTSECTION#', 'JaxCore')"]
DynamicVariables=1