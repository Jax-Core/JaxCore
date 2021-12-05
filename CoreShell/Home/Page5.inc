[variables]
@includeVars=#@#Vars.inc
Skin.Name=JaxCore
Set.Background_Check=0
Sec.SaveLocation=#@#Vars.inc
Set.L=(-#Set.P#)

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

; [MeasureRun]
; Measure=Plugin
; Plugin=RunCommand
; Program=PowerShell
; Parameter=$a=($PSVersionTable.PSVersion); \"$($a.Major).$($a.Minor)\"
; OutputType=ANSI
; OnUpdateAction=[!CommandMeasure MeasureRun "Run"]
; FinishAction=[!EnableMeasure CheckPSVersion][!UpdateMeasure CheckPSVersion]
; State=Hide

; [CheckPSVersion]
; Measure=Calc
; Formula=[MeasureRun]
; IfCondition=CheckPSVersion < 5.1
; IfTrueAction=[!SetOption Data MeterStyle "Set.String:S | Data2:S"][!UpdateMeter Data][!Redraw]
; IfFalseAction=[!UpdateMeter Data][!Redraw][!EnableMeasure CheckForDataFolder]
; DynamicVariables=1
; Disabled=1

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
Shape=Rectangle 0,0, #Set.W#, #Set.H# | StrokeWidth 0 | FIll Color 255,255,255
MouseActionCursor=0
DynamicVariables=1
; MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-60,-1000,0))"][!UpdateMeter *][!Redraw]
; MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+60,-1000,0))"][!UpdateMeter *][!Redraw]

[Header]
Meter=String
MeterStyle=Set.String:S
Text=Core Configuration
X=(#Set.P#)
Y=((110*[Set.S]))
FontSize=(40*[Set.S])
FontFace=#Set.Font# 
FontWeight=(650)
StringAlign=LeftTop
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0

[Shape]
Meter=Shape
X=0
Y=([Header:H]/2)r
Shape=Path This | StrokeWidth 4 | Stroke Color FF700F | StrokeStartCap Triangle | StrokeEndcap Triangle | OffSet -5,0
This=([Header:XW]+30*[Set.S]),0 | LineTo (#Set.W#-50*[Set.S]),0 | LineTo (#Set.W#-25*[Set.S]),(-25*[Set.S]) | LineTo (#Set.W#),0 | LineTo (#Set.W#-25*[Set.S]),(25*[Set.S]) | LineTo (#Set.W#-30*[Set.S]),(20*[Set.S])
DynamicVariables=1
Container=#Sec.Container#

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
Text=Animated context menu
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

[Ctx.Animated]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-[ContentContainer:Y]-(20/2-12/2)*[Set.S])
LeftMouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation#"][!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#ROOTCONFIGPATH#Ctx\Main.ini"][!Refresh]

[ActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#JaxCore\Accessories\UpdatePrompt
IfCondition=ActiveChecker = 1
IfTrueAction=[!SetVariable Set.Background_Check 1][!UpdateMeter Set.Background_Check][!Redraw]

[Set.Background_Check]
Meter=Shape
MeterStyle=Set.Bool:S | Set.Background_Check#Set.Background_Check#
Y=([Option02:Y]-[ContentContainer:Y]-(20/2-12/2)*[Set.S])
[Set.Background_Check0]
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\UpdatePrompt"][!Refresh]
[Set.Background_Check1]
Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\UpdatePrompt"][!Refresh]

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
