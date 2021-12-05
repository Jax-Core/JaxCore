; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[Variables]

[SectionButton:S]
X=((150/2+10)*[Set.S])r
Y=(-30/2*[Set.S])r
Shape=Rectangle 0,0,150,30,5 | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend This
This=Fill Color #Set.Text_Color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Text_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
DynamicVariables=1
[SectionIcon:S]
X=(150/2*[Set.S])r
Y=(30/2*[Set.S])r
FontSize=(10*[Set.S])
FontFace=#Set.Font#
Container=ContentContainer
StringAlign=CenterCEnter
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Behavior]
Meter=String
Text=These are the addons that are required for certain modules
MeterStyle=Set.String:S | Set.OptionCat:S

; --------------------------------- Section1 --------------------------------- ;

[Section1]
Meter=Shape
X=r
Y=(15*[Set.S])R
Shape=Rectangle 0,0,(([ContentContainer:W]-#Set.P#)/2-5*[Set.S]),(280*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Container=ContentContainer
DynamicVariables=1

[Section1.Icon]
Meter=Image
ImageName=#@#Images\CoreAssets\LogoIcon.png
X=((([ContentContainer:W]-#Set.P#)/2-5*[Set.S])/2-128/2*[Set.S])r
Y=(40*[Set.S])r
W=(128*[Set.S])
H=(128*[Set.S])
Container=ContentContainer
ImageTint=#Set.Text_Color#
DynamicVariables=1

[Section1.Text]
Meter=String
X=(128/2*[Set.S])r
Y=(30*[Set.S])R
Text=Check for Core updates in background#CRLF#Updates only downloaded when updating
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=CenterCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
InlinePattern2=#CRLF#.*
InlineSetting2=Size | (9*[Set.S])
MeterStyle=Set.String:S

[BackgroundCheckStatus]
Meter=Shape
MeterStyle=Set.Bool:S | BackgroundCheckStatus:#BackgroundCheckStatus#
Y=R
X=(-50/2*[Set.S])r
[BackgroundCheckStatus:0]
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\GlobalUpdater"][!UpdateMeasure GlobalUpdaterActiveChecker]
[BackgroundCheckStatus:1]
Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\GlobalUpdater"][!UpdateMeasure GlobalUpdaterActiveChecker]

; --------------------------------- Section2 --------------------------------- ;

[Section2]
Meter=Shape
X=(([ContentContainer:W]-#Set.P#*2)/2+55*[SEt.S])
Y=([Section1:Y]-#Set.P#)
Shape=Rectangle 0,0,(([ContentContainer:W]-#Set.P#)/2-5*[Set.S]),(280*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Container=ContentContainer
DynamicVariables=1

[Section2.Icon]
Meter=Image
ImageName=#@#Images\CoreAssets\CoreModules.png
X=((([ContentContainer:W]-#Set.P#)/2-5*[Set.S])/2-128/2*[Set.S])r
Y=(40*[Set.S])r
W=(128*[Set.S])
H=(128*[Set.S])
Container=ContentContainer
ImageTint=#Set.Text_Color#
DynamicVariables=1

[Section2.Text]
Meter=String
X=(128/2*[Set.S])r
Y=(30*[Set.S])R
Text=Check for module updates on startup#CRLF#Core will not check for updates in the background 
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=CenterCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
InlinePattern2=#CRLF#.*
InlineSetting2=Size | (9*[Set.S])
MeterStyle=Set.String:S

[GlobalCheckStatus]
Meter=Shape
MeterStyle=Set.Bool:S | GlobalCheckStatus:#GlobalCheckStatus#
Y=R
X=(-50/2*[Set.S])r
[GlobalCheckStatus:0]
Leftmouseupaction=[!ActivateConfig "#JaxCore\Accessories\GlobalUpdater"][!UpdateMeasure GlobalUpdaterActiveChecker]
[GlobalCheckStatus:1]
Leftmouseupaction=[!DeactivateConfig "#JaxCore\Accessories\GlobalUpdater"][!UpdateMeasure GlobalUpdaterActiveChecker]
; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                Core overrides                                ;
; ---------------------------------------------------------------------------- ;

[Auto_Refresh:M]
Measure=

[Help:Category]
Y=(#Set.H#-100*[Set.S])

[DivCat:1293s18]
Meter=
[ActiveChecker]
Measure=
[BottomButton]
Meter=
[BottomText]
Meter=