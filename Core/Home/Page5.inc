[variables]
@includeVars=#@#Vars.inc
Skin.Name=JaxCore
Set.Background_Check=0
Sec.SaveLocation=#@#Vars.inc

[BC]
MouseScrollDownAction=
MouseScrollUpAction=

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[MeasureRun]
Measure=Plugin
Plugin=RunCommand
Program=PowerShell
Parameter=$a=($PSVersionTable.PSVersion); \"$($a.Major).$($a.Minor)\"
OutputType=ANSI
OnUpdateAction=[!CommandMeasure MeasureRun "Run"]
FinishAction=[!EnableMeasure CheckPSVersion][!UpdateMeasure CheckPSVersion]
State=Hide

[CheckPSVersion]
Measure=Calc
Formula=[MeasureRun]
IfCondition=CheckPSVersion < 5.1
IfTrueAction=[!SetOption Data MeterStyle "Set.String:S | Data2:S"][!UpdateMeter Data][!Redraw]
IfFalseAction=[!UpdateMeter Data][!Redraw][!EnableMeasure CheckForDataFolder]
DynamicVariables=1
Disabled=1

[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\CheckData.ps1
Disabled=1

; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

[Set.OptionCat:S]
X=#Set.P#
[Set.OptionName:S]
[Set.Div:S]
DynamicVariables=1
; Shape=Line 0,0,(500*[Set.S]),0 | StrokeWidth 1 | Fill Color #Set.Pri_Color#,0 | Stroke Color #Set.Text_Color#,25

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[B]
Meter=Shape
Shape=Rectangle 0,0, #Set.W#, #Set.H#, #Set.R# | StrokeWidth 0 | Fill Color #Set.Pri_Color#
MouseActionCursor=0
DynamicVariables=1

[ContentContainer]
Meter=Shape
Shape=Rectangle 0,0, #Set.W#, #Set.H# | StrokeWidth 0 | FIll Color 255,255,255,#ContentContainerAlpha#
MouseActionCursor=0
DynamicVariables=1
; MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-60,-1000,0))"][!UpdateMeter *][!Redraw]
; MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+60,-1000,0))"][!UpdateMeter *][!Redraw]

[Logo]
Meter=Image
ImageName=#@#Images\Logo256.png
X=(#Set.W#-#Set.P#-((256-20)*[Set.S]))
Y=(110*[Set.S])
W=(256*[Set.S])
Y=(256*[Set.S])
Container=BC
DynamicVariables=1

[Data]
Meter=String
MeterStyle=Set.String:S | Data1:S
MeasureName=MeasureRun
X=r
Y=R
W=(256)
ClipString=2
DynamicVariables=1
FontSize=(12*[Set.S])
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])
Container=BC
[Data1:S]
Text=Core version #Core.Ver##CRLF#Master version 3#CRLF#Powershell %1
Leftmouseupaction=
FontColor=#Set.SubText_Color#
[Data2:S]
Text=Please click here to download Powershell 5.1 in order for PSRM to work.
Leftmouseupaction=["https://www.microsoft.com/en-us/download/details.aspx?id=54616"]
FontColor=#Set.Accent_Color#

[title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Settings
X=(#Set.P#)
Y=((110*[Set.S]))
FontSize=60
FontFace=Poppins SemiBold
StringAlign=LeftTop
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])


; ---------------------------------------------------------------------------- ;
;                                   Settings                                   ;
; ---------------------------------------------------------------------------- ;


[Behavior]
Meter=String
Text=Core
Y=(250*[Set.S])
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Auto refresh skins
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S190322131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Check for updates in the background
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1903238]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Checking rate (minutes)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19032]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Quality of Life features (turning off might help reduce crashes)
MeterStyle=Set.String:S | Set.OptionName:S

[Actions]
Meter=String
Text=Actions
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Change window size to...
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:da1]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Clear cache
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S21]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Regenerate CoreData folder
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S2asdada1]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Restart rainmeter
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S2asdadsdasda1]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Open rainmeter...
MeterStyle=Set.String:S | Set.OptionName:S
; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Set.Auto_Refresh]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-[ContentContainer:Y]-(20/2-12/2)*[Set.S])

[ActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#JaxCore\Accessories\Notification
IfCondition=ActiveChecker = 1
IfTrueAction=[!SetVariable Set.Background_Check 1][!UpdateMeter Set.Background_Check][!Redraw]

[Set.Background_Check]
Meter=Shape
MeterStyle=Set.Bool:S | Set.Background_Check#Set.Background_Check#
Y=([Option02:Y]-[ContentContainer:Y]-(20/2-12/2)*[Set.S])
[Set.Background_Check0]
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\Notification"][!Refresh]
[Set.Background_Check1]
Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\Notification"][!Refresh]

[Set.BackgroundCheckTime]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-[ContentContainer:Y]-(30/2-12/2)*[Set.S])
[Value03]
Meter=String
Text=#Set.BackgroundCheckTime#
MeterStyle=Set.String:S | Set.Value:S

[QoL]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option04:Y]-[ContentContainer:Y]-(20/2-12/2)*[Set.S])
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation#"][!WriteKeyvalue Variables "#CURRENTSECTION#Plugin" "[&Func:returnBool('#CURRENTSECTION#', '0', 'Plugin', '')]" "#Sec.SaveLocation#"][!Refresh]

[Button11]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!commandMeasure Func "startDrop('Window', '#CURRENTSECTION#')"]
Y=([Option11:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=Change...
MeterStyle=Set.String:S | Set.Value:S

[Button14]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!Activateconfig "#JaxCore\Accessories\WebParse" "Delete.ini"]
Y=([Option14:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value14]
Meter=String
Text=Clear
MeterStyle=Set.String:S | Set.Value:S

[Button12]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!CommandMeasure CheckForDataFolder "Check-Data"]
OverColor=25,255,0,200
LeaveColor=25,255,0,100
Y=([Option12:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=Regenerate
MeterStyle=Set.String:S | Set.Value:S

[Button13]
Meter=Shape
MeterStyle=Set.Button:S
Act=["#@#Addons\RestartRainmeter.exe"]
OverColor=255,0,0,200
LeaveColor=255,0,0,100
Y=([Option13:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=Restart
MeterStyle=Set.String:S | Set.Value:S

[Button15]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!commandMeasure Func "startDrop('Rainmeter', '#CURRENTSECTION#')"]
Y=([Option15:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value15]
Meter=String
Text=Select...
MeterStyle=Set.String:S | Set.Value:S
