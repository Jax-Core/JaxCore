; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
[Rainmeter]
OnUnfocusAction=[!UpdateMeasure UnloadHandler2]

[Variables]
Drop.Animation_Time=300
Sec.Input=
Sec.Input_Char=
Sec.Input_Phrase=

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #Drop.Animation_Time#
Optional0=Easing InOutCirc
UpdateDivider=1

[UnloadHandler1]
Measure=String
String=0
Ifmatch=0
ifmatchaction=[!CommandMeasure mActions "Execute 2"][!SetOptionGroup Handler String 1]
ifnotmatchaction=
IfMatchMode=1
Group=NUOL | Handler
disabled=1

[UnloadHandler2]
Measure=String
String=0
Ifmatch=0
ifmatchaction=[!CommandMeasure mActions "Execute 3"][!SetOption Handler String 1]
ifnotmatchaction=
IfMatchMode=1
Group=NUOL | Handler
disabled=1

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 100 | NUOLOn | Start0 | Wait #Drop.Animation_Time#
ActionList2=Custom2 | Rewind0 | Wait #Drop.Animation_Time# | Deactivate
ActionList3=Rewind0 | Wait #Drop.Animation_Time# | Deactivate
NUOLOn=[!EnableMeasureGroup NUOL]
Start0=[!CommandMeasure mTween "Start(0)"]
Rewind0=[!CommandMeasure mTween "Rewind(0)"]
Custom2=[!WriteKeyvalue Variables Key#Sec.Num# "#Sec.Input##Sec.Input_Char#" "#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini"][!WriteKeyvalue Variables Key#Sec.Num#InString "#Sec.Input_Phrase# #Sec.Input_Char#" "#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini"][!UpdateMeasure Auto_Refresh:M "#JaxCore\Main"][!Refresh "#JaxCore\Main"]
Deactivate=[!DeactivateConfig]
Group=Key
DynamicVariables=1


[Sec.Button:S]
X=((50/2+5)*#Sec.S#)r
Y=(-50/2*#Sec.S#)r
Shape=Rectangle 0,0,50,50,(#Sec.R#/2) | StrokeWidth 0 | Extend This | Scale #Sec.S#,#Sec.S#,0,0
This=fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorLeave')]
DynamicVariables=1
ColorLeave=100,100,100,100
ColorOver=100,100,100,200
Container=BC
MouseOverAction=[!SetOption #CURRENTSECTION# this "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorOver')]"][!SetOption #Sec.#CURRENTSECTION## FontColor "255,255,255"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# this "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'ColorLeave')]"][!SetOption #Sec.#CURRENTSECTION## FontColor "255,255,255,150"][!UpdateMeter *][!Redraw]
Leftmouseupaction=[!Setvariable Sec.Input "#Sec.INput#[&Func:LocalVar('#CURRENTSECTION#', 'Class')]"][!Setvariable Sec.Input_Phrase "#Sec.Input_Phrase# [&Func:LocalVar('#CURRENTSECTION#', 'Class2')]"][!UpdateMeter *][!Redraw]

[Sec.Text:S]
X=(50/2*#Sec.S#)r
Y=(50/2*#Sec.S#)r
DynamicVariables=1
StringAlign=CenterCenter
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;



[BC]
Meter = Shape
Shape=Rectangle (#Sec.W#*(1-#TweenNode1#)),0,(#Sec.W#*#TweenNode1#),(#Sec.H#) | StrokeWidth 0 | Fill Color 34,34,34
Group=Tweenable
DynamicVariables=1

[B]
Meter = Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#),#Sec.R# | StrokeWidth 0 | Fill Color 34,34,34
Container=BC

[KeyLabel]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
FontSize=(10*#Sec.S#)
FontColor=255,255,255,150
Text=Click the modifiers below or click any alphabetical keys on your keyboard...
StringAlign=Center
MeterStyle=Sec.String:S

[KeyLabelOverlap]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#/2)
FontSize=(20*#Sec.S#)
Text=#Sec.Input##Sec.Input_Char#
Prefix="> "
Postfix=" <"
DynamicVariables=1
StringAlign=CenterCenter
MeterStyle=Sec.String:S

[KeyLabelOverlap2]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#/2+30)
FontSize=(10*#Sec.S#)
Text=#Sec.Input_Phrase# #Sec.Input_Char#
DynamicVariables=1
StringAlign=CenterCenter
MeterStyle=Sec.String:S

[Shape1]
Meter=Shape
X=((#Sec.W#-#Sec.P#*2)/2-(50*5+5*4)*#Sec.S#/2+#sec.P#)
Y=(#Sec.H#*0.8)
Class="#"
Class2="LWin"
MeterStyle=Sec.Button:S
[Text1]
Meter=String
Text=LWin
MEterStyle=Sec.String:S | Sec.Text:S
[Shape2]
Meter=Shape
Class="^"
Class2="Ctrl"
MeterStyle=Sec.Button:S
[Text2]
Meter=String
Text=Ctrl
MEterStyle=Sec.String:S | Sec.Text:S
[Shape3]
Meter=Shape
Class="!"
Class2="Alt"
MeterStyle=Sec.Button:S
[Text3]
Meter=String
Text=Alt
MEterStyle=Sec.String:S | Sec.Text:S
[Shape4]
Meter=Shape
Class="+"
Class2="Shift"
MeterStyle=Sec.Button:S
[Text4]
Meter=String
Text=Shift
MEterStyle=Sec.String:S | Sec.Text:S
[Shape5]
Meter=Shape
MeterStyle=Sec.Button:S
Leftmouseupaction=[!Setvariable Sec.Input ""][!Setvariable Sec.Input_Phrase ""][!UpdateMeter *][!Redraw]
[Text5]
Meter=String
Text=Clear
MEterStyle=Sec.String:S | Sec.Text:S
[ShapeConfirm]
Meter=Shape
X=(#Sec.W#/2-100/2*#Sec.S#)
Shape=Rectangle 0,0,100,40,(#Sec.R#/2) | StrokeWidth 0 | Extend This | Scale #Sec.S#,#Sec.S#,0,0
Y=(#Sec.P#)R
Leftmouseupaction=[!UpdateMeasure UnloadHandler1]
ColorLeave=0,100,0,100
ColorOver=0,100,0,200
MeterStyle=Sec.Button:S
[TextConfirm]
Meter=String
X=(100/2*#Sec.S#)r
Y=(40/2*#Sec.S#)r
Text=Confirm
MEterStyle=Sec.String:S | Sec.Text:S








[QkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Q
KeyDownAction=[!Setvariable Sec.Input_Char "Q"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[WkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=W
KeyDownAction=[!Setvariable Sec.Input_Char "W"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[EkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=E
KeyDownAction=[!Setvariable Sec.Input_Char "E"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[RkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=R
KeyDownAction=[!Setvariable Sec.Input_Char "R"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[TkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=T
KeyDownAction=[!Setvariable Sec.Input_Char "T"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[YkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Y
KeyDownAction=[!Setvariable Sec.Input_Char "Y"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[UkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=U
KeyDownAction=[!Setvariable Sec.Input_Char "U"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[IkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=I
KeyDownAction=[!Setvariable Sec.Input_Char "I"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[OkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=O
KeyDownAction=[!Setvariable Sec.Input_Char "O"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[PkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=P
KeyDownAction=[!Setvariable Sec.Input_Char "P"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

;===========================================================================================================================================================

[AkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=A
KeyDownAction=[!Setvariable Sec.Input_Char "A"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[SkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=S
KeyDownAction=[!Setvariable Sec.Input_Char "S"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[DkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=D
KeyDownAction=[!Setvariable Sec.Input_Char "D"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[FkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=F
KeyDownAction=[!Setvariable Sec.Input_Char "F"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[GkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=G
KeyDownAction=[!Setvariable Sec.Input_Char "G"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[HkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=H
KeyDownAction=[!Setvariable Sec.Input_Char "H"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[JkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=J
KeyDownAction=[!Setvariable Sec.Input_Char "J"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[KkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=K
KeyDownAction=[!Setvariable Sec.Input_Char "K"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[LkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=L
KeyDownAction=[!Setvariable Sec.Input_Char "L"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

;===========================================================================================================================================================

[ZkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Z
KeyDownAction=[!Setvariable Sec.Input_Char "Z"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[XkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=X
KeyDownAction=[!Setvariable Sec.Input_Char "X"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[CkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=C
KeyDownAction=[!Setvariable Sec.Input_Char "C"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[VkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=V
KeyDownAction=[!Setvariable Sec.Input_Char "V"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[BkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=B
KeyDownAction=[!Setvariable Sec.Input_Char "B"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[NkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=N
KeyDownAction=[!Setvariable Sec.Input_Char "N"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[MkeyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=M
KeyDownAction=[!Setvariable Sec.Input_Char "M"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key


;===========================================================================================================================================================

[0keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=0
KeyDownAction=[!Setvariable Sec.Input_Char "0"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[1keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=1
KeyDownAction=[!Setvariable Sec.Input_Char "1"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[2keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=2
KeyDownAction=[!Setvariable Sec.Input_Char "2"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[3keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=3
KeyDownAction=[!Setvariable Sec.Input_Char "3"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[4keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=4
KeyDownAction=[!Setvariable Sec.Input_Char "4"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[5keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=5
KeyDownAction=[!Setvariable Sec.Input_Char "5"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[6keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=6
KeyDownAction=[!Setvariable Sec.Input_Char "6"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[7keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=7
KeyDownAction=[!Setvariable Sec.Input_Char "7"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[8keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=8
KeyDownAction=[!Setvariable Sec.Input_Char "8"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[9keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=9
KeyDownAction=[!Setvariable Sec.Input_Char "9"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

;===========================================================================================================================================================

[Num0keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num0
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad0"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num1keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num1
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad1"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num2keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num2
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad2"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num3keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num3
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad3"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num4keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num4
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad4"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num5keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num5
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad5"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num6keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num6
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad6"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num7keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num7
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad7"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num8keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num8
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad8"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key

[Num9keyMeasure]
Measure=Plugin
Plugin=Hotkey
DynamicVariables=1
HotKey=Num9
KeyDownAction=[!Setvariable Sec.Input_Char "Numpad9"][!UpdateMeasureGroup Key][!UpdateMeter *][!Redraw]
Group=Key