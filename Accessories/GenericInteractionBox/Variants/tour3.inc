[Variables]
Sec.W=(500*#Sec.S#)
Sec.H=(700*#Sec.S#)
Sec.R=(5*#Sec.S#)
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
X=((#width#/2-#imgwidth#/2)*#Sec.S#)r
Y=((#width#/2-#imgwidth#/2)*#Sec.S#)r
W=(#imgwidth#*#Sec.S#)
H=(#imgwidth#*#Sec.S#)
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
H=([Img:W])
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png

[Text]
Meter=String
Text=Consider supporting JaxCore!#CRLF#This application is completely free.
X=(#Sec.W#/2)
Y=(30*#Sec.s#)R
FontSize=(20*#Sec.S#)
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | 10
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
INlinePattern4=#CRLF#.*
InlineSetting4=Weight | 400
StringAlign=CenterCenter
MeterStyle=Sec.String:S
FontWeight=650

[Support.1]
Meter=Shape
X=#Sec.P#
Y=(30*#Sec.S#)R
This=0,0 | 4,255,83,(100*#TweenNode3#) ; 0.0 | 0,0,0,0 ; 1.0
That=180 | 04ff58 ; 0.0 | 04cc47 ; 1.0
Shape=Rectangle 0,0,#width#,#width#,5 | StrokeWidth ((2+4*#TweenNode3#)*#Sec.S#) | Fill RadialGradient This | SCale #Sec.S#,#Sec.S#,0,0 | Stroke LinearGradient That
MeterStyle=Support:S
MouseOverAction=[!SEtVariable tweennode3 1][!Updatemeter *][!Redraw]
MouseLeaveAction=[!SEtVariable tweennode3 0][!Updatemeter *][!Redraw]
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals"]
[SupportImage.1]
Meter=Image
ImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\DA.png
MeterStyle=SupportImage:S
[SupportText.1]
MEter=String
Text=Watch me on#CRLF#DeviantArt
InlineSetting3=GradientColor | 180 | 04ff58 ; 0.0 | 04cc47 ; 1.0
MeterStyle=Sec.String:S | SupportText:S
X=([Support.1:X]+(#width#/2))
Y=([Support.1:Y]+#Width#+#Sec.P#*2)

[Support.3]
Meter=Shape
X=(#Sec.W#/2+#Sec.P#/2)
Y=[Support.1:Y]
This=0,0 | 255,255,255,(100*#TweenNode4#) ; 0.0 | 0,0,0,0 ; 1.0
That=180 | 29ABE0 ; 0.0 | FF5E5B ; 1.0
Shape=Rectangle 0,0,#width#,#width#,5 | StrokeWidth ((2+4*#TweenNode4#)*#Sec.S#) | Fill RadialGradient This | SCale #Sec.S#,#Sec.S#,0,0 | Stroke LinearGradient That
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