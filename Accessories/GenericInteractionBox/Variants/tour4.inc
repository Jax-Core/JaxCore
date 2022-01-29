[Variables]
Sec.W=(500*#Sec.S#)
Sec.H=(700*#Sec.S#)
AniDir=Bottom
BackgroundCheckStatus=0
GlobalCheckStatus=0
tweennode3=0
tweennode4=0

width=((#Sec.W#-#Sec.P#*3)/2)
imgwidth=(75*#sec.s#)
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1

[ActionTimer]
Custom0=[!WriteKeyValue Variables UserNameCheckVariable "[MeasureUser]" "#@#Vars.inc"][!WriteKeyValue Variables Sec.Page 1 "#ROOTCONFIGPATH#Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.ini"][!DeactivateConfig]

; ---------------------------------------------------------------------------- ;
;                                  MeterStyleS                                 ;
; ---------------------------------------------------------------------------- ;

[Support:S]
DynamicVariables=1
[SupportImage:S]
X=((#width#/2-#imgwidth#/2))r
Y=((#width#/2-#imgwidth#/2))r
W=(#imgwidth#)
H=(#imgwidth#)
DynamicVariables=1
[SupportText:S]
FontSize=(10*#Sec.S#)
Inlinepattern=#CRLF#.*
InlineSetting=Weight | 650
Inlinepattern2=#CRLF#.*
InlineSetting2=Size | (20*#Sec.S#)
Inlinepattern3=#CRLF#.*
StringAlign=CenterCenter
FontColor=#Set.Subtext_Color#
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[ImageContainer]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#),[Image:H],#Set.R# | StrokeWidth 0 | Fill LinearGradient This
This=90 | 0,0,0,0 ; 0 | 0,0,0,255 ; 1
DynamicVariables=1

[Image]
Meter=Image
Container=Imagecontainer
ImageName=#@#Images\TourPreview.png
W=#Sec.W#
H=(200*#sec.S#)
PreserveAspectRatio=2
ImageAlpha=175

[Img]
Meter=Image
X=(#Sec.W#/2-[Img:W]/2)
Y=#Sec.P#
W=(100*#Sec.S#)
H=(100*#Sec.S#)
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png

[Text]
Meter=String
Text=Support JaxCore's development!
X=(#Sec.W#/2)
Y=(15*#Sec.s#)R
FontSize=(20*#Sec.S#)
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
StringAlign=center
MeterStyle=Sec.String:S
FontWeight=650

[Text2]
Meter=String
X=(#Sec.W#/2)
Y=R
FontColor=#Set.Text_Color#
StringAlign=Center
Fontsize=(12*#sec.s#)
Text=Get exclusive early access to upcoming modules!#CRLF#Receive a special role on the Discord server!
MeterStyle=Sec.String:S

[Support.3]
Meter=Shape
X=(#Sec.w#/2-#width#/2)
Y=(30*#Sec.S#)R
This=0,0 | 255,255,255,(100*#TweenNode4#) ; 0.0 | 0,0,0,0 ; 1.0
That=180 | 29ABE0 ; 0.0 | FF5E5B ; 1.0
Shape=Rectangle 0,0,#width#,#width#,5 | StrokeWidth ((2+4*#TweenNode4#)*#Sec.S#) | Fill RadialGradient This | Stroke LinearGradient That
MouseOverAction=[!SEtVariable tweennode4 1][!Updatemeter *][!Redraw]
MouseLeaveAction=[!SEtVariable tweennode4 0][!Updatemeter *][!Redraw]
MeterStyle=Support:S
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
[SupportImage.3]
Meter=Image
ImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\KF.png
MeterStyle=SupportImage:S
[SupportText.3]
MEter=String
Text=Buy me a cup of coffee on#CRLF#Ko-fi
InlineSetting3=GradientColor | 180 | 29ABE0 ; 0.0 | FF5E5B ; 1.0
MeterStyle=Sec.String:S | SupportText:S
X=([Support.3:X]+(#width#/2))
Y=([Support.3:Y]+#Width#+#Sec.P#*2)
W=(#width#)


[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
Text=Finish installation
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure ActionTimer "Execute 2"]
MeterStyle=Sec.String:S

[Esc]
Meter=