
[LoadActions]
ActionList1=Start0 | Wait 500 | Start1 | Wait 1000 | start2 | PSRM

[PSRM]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\AddShortcutTour.ps1

[CardSquareButton:S]
X=(#Sec.S#*(40/2+10))r
Y=(#Sec.S#*-40/2)r
Shape=Rectangle 0,0,40,40,5 | StrokeWidth 0 | Scale #Sec.S#,#Sec.S#,0,0 | Extend This
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[CardSquareIcon:S]
X=(40/2*#Sec.S#)r
Y=(40/2*#Sec.S#)r
FontSize=(12*#Sec.S#)
FontFace=Segoe Fluent Icons
StringAlign=CenterCEnter
[CardButton:S]
X=(#Sec.S#*230/2-150*#Sec.S#/2)
Y=(300*#sec.S#-#Sec.Top#*1.5)
Shape=Rectangle 0,0,150,30,5 | StrokeWidth 0 | Scale #Sec.S#,#Sec.S#,0,0 | Extend This
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[CardIcon:S]
X=(150/2*#Sec.S#)r
Y=(30/2*#Sec.S#)r
FontSize=(10*#Sec.S#)
FontFace=Poppins Light
StringAlign=CenterCEnter
[CardButton1:S]
This=Fill Color 0,255,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]


[Card1.ButtonProg.False]
LeftMouseUpAction=[!CommandMeasure PSRM "StartFolder"][!SetOption Card1.Button2.Shape MeterStyle "CardSquareButton:S | Card1.ButtonProg.True"][!UpdateMeter Card1.Button2.Shape][!Redraw]
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Card1.ButtonProg.True]
This=Fill Color 0,255,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure PSRM "RemoveStartFolder"][!SetOption Card1.Button2.Shape MeterStyle "CardSquareButton:S | Card1.ButtonProg.False"][!UpdateMeter Card1.Button2.Shape][!Redraw]
[Card1.ButtonDesk.False]
LeftMouseUpAction=[!CommandMeasure PSRM "Desktop"][!SetOption Card1.Button1.Shape MeterStyle "CardSquareButton:S | Card1.ButtonDesk.True"][!UpdateMeter Card1.Button1.Shape][!Redraw]
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Card1.ButtonDesk.True]
This=Fill Color 0,255,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure PSRM "RemoveDeskop"][!SetOption Card1.Button1.Shape MeterStyle "CardSquareButton:S | Card1.ButtonDesk.False"][!UpdateMeter Card1.Button1.Shape][!Redraw]

[Card.Container:S]
Shape=Rectangle 0,0,(230*#sec.S#),(340*#sec.S#*#TweenNode2#),#Sec.R# | StrokeWidth 0 | Fill Color #Set.Sec_Color#
[Card.Shape:S]
Shape=Rectangle 1,1,(230*#sec.S#-2),(340*#sec.S#-2),#Sec.R# | StrokeWidth 2 | Stroke LinearGradient This | Fill Color #Set.Sec_Color#
[Card.Title:S]
FontFace=Poppins
X=(230/2*#sec.S#)r
Y=(#Sec.Top#*1.5)R
W=(230*#SEc.S#-#sec.top#*2)
ClipString=2
FontSize=(12*#Sec.S#)
Inlinepattern=.*#CRLF#
InlineSetting=Weight | 650
Inlinepattern2=#CRLF#.*
InlineSetting2=Size | (8*#Sec.S#)
StringAlign=CenterTop
[Card.Info:S]
X=r
Y=(300*#sec.S#-#Sec.Top#*3)
W=(230*#SEc.S#-#sec.top#*2)
ClipString=2
FontSize=(8*#Sec.S#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
[Card.Image:S]
X=r
Y=r
MaskImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\Mask.png
W=(230*#sec.S#)

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Modifiers]
@includeModifiers=#ROOTCONFIGPATH#Accessories\Tour\Modifier.inc

[Title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Welcome to JaxCore
X=(#Sec.P2#)
Y=(#Sec.P2#)
FontSize=(36*#Sec.S#)
FontFace=Poppins 
FontWeight=(650)
Container=GlobalContainer
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
InlineSetting2=Shadow | 0 | 0 | 5 | 0,0,0,100

[Title.Shape]
Meter=Shape
X=#Sec.P2#
Y=(35*#Sec.S#)r
Shape=Path This | StrokeWidth 4 | Stroke Color FF700F | StrokeStartCap Triangle | StrokeEndcap Triangle | OffSet -5,0
This=([Title.Text1:W]+(30+200*(1-#TweenNode1#))*#Sec.S#),0 | LineTo (#Sec.W#-2*#Sec.P2#-50*#Sec.S#),0 | LineTo (#Sec.W#-2*#Sec.P2#-25*#Sec.S#),(-25*#Sec.S#) | LineTo (#Sec.W#-2*#Sec.P2#),0 | LineTo (#Sec.W#-2*#Sec.P2#-25*#Sec.S#),(25*#Sec.S#) | LineTo (#Sec.W#-2*#Sec.P2#-30*#Sec.S#),(20*#Sec.S#)
Container=GlobalContainer
DynamicVariables=1
Group=Tweenable

[Des.Text]
Meter=String
MeterStyle=Set.String:S
Text=Delighted to have you here, let's set Core up!#CRLF#You can also configure these in the settings panel after completing the installation.
X=#Sec.P2#
Y=(40*#Sec.S#)r
FontSize=(14*#Sec.S#)
Container=GlobalContainer
Inlinepattern=#CRLF#.*
InlineSetting=Size | (8*#Sec.S#)
Inlinepattern2=#CRLF#.*
InlineSetting2=Color | #Set.Subtext_Color#

; ---------------------------------------------------------------------------- ;
;                                    Card 1                                    ;
; ---------------------------------------------------------------------------- ;

[Card1.Container]
Meter=Shape
X=#Sec.P2#
y=(170*#sec.S#)
MeterStyle=Card.Container:S
DynamicVariables=1
Group=Tweenable
[Card1.Shape]
Meter=Shape
MeterStyle=Card.Shape:S
This=180 | FE4E18 ; 0.0 | FFCE32 ; 1.0
Container=Card1.Container
[Card1.Image]
Meter=Image
MeterStyle=Card.Image:S
Container=Card1.Container
ImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\Shortcut.png
[Card1.Title]
Meter=String
MeterStyle=Set.String:S | Card.Title:S
Text=Add shortcut#CRLF#So you won't struggle to open the panel again
Container=Card1.Container
[Card1.Info]
Meter=String
MeterStyle=Set.String:S | Card.Info:S
Text=Buttons will turn green when the shortcut exists in the directory.
Container=Card1.Container
[Card1.Button1.Shape]
Meter=Shape
MeterStyle=CardSquareButton:S | Card1.ButtonDesk.False
X=(230*#Sec.S#/2-(40*2+10)*#Sec.S#/2)
Y=(300*#sec.S#-#Sec.Top#*1.5)
Container=Card1.Container
[Card1.Button1.Text]
Meter=String
MeterStyle=Set.String:S | CardSquareIcon:S
Text=[\xe7f4]
Container=Card1.Container
[Card1.Button2.Shape]
Meter=Shape
MeterStyle=CardSquareButton:S | Card1.ButtonProg.False
Container=Card1.Container
[Card1.Button2.Text]
Meter=String
MeterStyle=Set.String:S | CardSquareIcon:S
Text=[\xe8a9]
Container=Card1.Container


; ---------------------------------------------------------------------------- ;
;                                    Card 3                                    ;
; ---------------------------------------------------------------------------- ;

[Card3.Container]
Meter=Shape
X=(#Sec.P2#)R
y=r
MeterStyle=Card.Container:S
DynamicVariables=1
Group=Tweenable
[Card3.Shape]
Meter=Shape
MeterStyle=Card.Shape:S
This=180 | FEB619 ; 0.0 | BB00FF ; 1.0
Container=Card3.Container
[Card3.Image]
Meter=Image
MeterStyle=Card.Image:S
Container=Card3.Container
ImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\Update.png
[Card3.Title]
Meter=String
MeterStyle=Set.String:S | Card.Title:S
Text=Global updater#CRLF#Check for updates for every module that you've installed
Container=Card3.Container
[Card3.Info]
Meter=String
MeterStyle=Set.String:S | Card.Info:S
Container=Card3.Container
[Card3.Button1.Shape]
Meter=Shape
MeterStyle=CardButton:S
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\GlobalUpdater"][!SetOption #CURRENTSECTION# MeterStyle "CardButton:S | CardButton1:S"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=Card3.Container
[Card3.Button1.Text]
Meter=String
MeterStyle=Set.String:S | CardIcon:S
Text=Enable
Container=Card3.Container

; ---------------------------------------------------------------------------- ;
;                                   next page                                  ;
; ---------------------------------------------------------------------------- ;

[Page.ButtonNext.Shape]
Meter=Shape
X=(#Sec.W#-(20)*#Sec.S#-#Sec.p2#)
Y=(#Sec.H#-(40)*#Sec.S#-#Sec.p2#)
Shape=Ellipse 0,0,(20*[ButtonNextTimer]/500*#Sec.S#) | StrokeWidth 0 | Extend This
This=Fill Color 0,255,0,(100*[ButtonNextTimer]/500)
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,(200*[*ButtonNextTimer*]/500)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,(100*[*ButtonNextTimer*]/500)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure LoadActions "Execute 2"]
Container=GlobalContainer
DynamicVariables=1
UpdateDivider=1
[Page.ButtonNext.Icon]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(2*#sec.s#)r
FontSize=(12*#Sec.S#)
Text=[\xf0af]
FontFace=Segoe Fluent Icons
StringAlign=CenterCEnter
Container=GlobalContainer
Hidden=1
[ButtonNextTimer]
Measure=Calc
Formula=ButtonNextTimer + 1
IfCondition=ButtonNextTimer >= 500
IfTrueAction=[!ShowMeter Page.ButtonNext.Icon][!SetOption Pagee.ButtonNext.Shape UpdateDivider -1][!UpdateMeter *][!Redraw][!PauseMeasure #CURRENTSECTION#]
DynamicVariables=1
UpdateDivider=1