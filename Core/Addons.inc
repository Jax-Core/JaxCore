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
Shape=Rectangle 0,0,(([ContentContainer:W]-#Set.P#)/2-5*[Set.S]),(([ContentContainer:W]-#Set.P#)/2-5*[Set.S]),(#Set.R#/4) | StrokeWidth 2 | Stroke LinearGradient This | Extend Fill
This=0 | EC8827 ; 0 | DA453C ; 1
Fill=Fill Color #Set.Sec_Color#,150
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://github.com/Jax-Core/ModularPlayers#how-to-install-spicetify-cli"]
Container=ContentContainer
DynamicVariables=1

[Section1.Icon]
Meter=Image
ImageName=#@#Images\Spicetify.png
X=((([ContentContainer:W]-#Set.P#)/2-5*[Set.S])/2-256/2*[Set.S])r
Y=((([ContentContainer:W]-#Set.P#)/2-5*[Set.S])/2-256/2*[Set.S])r
W=(256*[Set.S])
H=(256*[Set.S])
PreserveAspectRatio=1
Container=ContentContainer
ImageTint=#Set.Text_Color#
DynamicVariables=1

[Section1.Text]
Meter=String
X=(256/2*[Set.S])r
Y=([Section1:YH])
Text=Required for retrieving Spotify now playing data
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=CenterBottom
FontColor=#Set.SubText_Color#
MeterStyle=Set.String:S

; --------------------------------- Section2 --------------------------------- ;

[Section2]
Meter=Shape
X=(([ContentContainer:W]-#Set.P#*2)/2+55*[SEt.S])
Y=([Section1:Y]-#Set.P#)
Shape=Rectangle 0,0,(([ContentContainer:W]-#Set.P#)/2-5*[Set.S]),(([ContentContainer:W]-#Set.P#)/2-5*[Set.S]),(#Set.R#/4) | StrokeWidth 2 | Stroke LinearGradient This | Extend Fill
This=0 | 283893 ; 0 | EBE722 ; 1
Fill=Fill Color #Set.Sec_Color#,150
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://github.com/khanhas/MagickMeter#how-to-install"]
Container=ContentContainer
DynamicVariables=1

[Section2.Icon]
Meter=Image
ImageName=#@#Images\ImageMagick.png
X=((([ContentContainer:W]-#Set.P#)/2-5*[Set.S])/2-256/2*[Set.S])r
Y=((([ContentContainer:W]-#Set.P#)/2-5*[Set.S])/2-256/2*[Set.S])r
W=(256*[Set.S])
H=(256*[Set.S])
PreserveAspectRatio=1
Container=ContentContainer
ImageTint=#Set.Text_Color#
DynamicVariables=1

[Section2.Text]
Meter=String
X=(256/2*[Set.S])r
Y=([Section2:YH])
Text=Required for shadows and blurring for widgets
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=CenterBottom
FontColor=#Set.SubText_Color#
MeterStyle=Set.String:S
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