[LoadActions]
ActionList1=Start0 | Wait 500 | Start1

[Tween:M]
Tween2=Single | Variable | TweenNode3 | 0 | 1 | 100
Tween3=Single | Variable | TweenNode4 | 0 | 1 | 100
Optional2=Easing Linear
Optional3=Easing Linear

[Support:S]
Y=(10*#Sec.S#)R
Container=GlobalContainer
DynamicVariables=1
Group=Tweenable
[SupportImage:S]
X=((300/2-100/2)*#Sec.S#)r
Y=((300/2-100/2)*#Sec.S#)r
W=(100*#Sec.S#)
H=(100*#Sec.S#)
DynamicVariables=1
Container=GlobalContainer
[SupportText:S]
FontSize=(10*#Sec.S#)
Angle=(Rad(-90))
Inlinepattern=#CRLF#.*
InlineSetting=Weight | 650
Inlinepattern2=#CRLF#.*
InlineSetting2=Size | (20*#Sec.S#)
Inlinepattern3=#CRLF#.*
StringAlign=Left
FontColor=#Set.Subtext_Color#
Container=GlobalContainer
DynamicVariables=1
Group=Tweenable

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Modifiers]
@includeModifiers=#ROOTCONFIGPATH#Accessories\Tour\Modifier.inc

[Title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Consider supporting me!
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
Text=It takes a lot of time to make JaxCore and its components, if you've enjoyed my creations, consider supporting me!
X=#Sec.P2#
Y=(40*#Sec.S#)r
FontSize=(12*#Sec.S#)
Container=GlobalContainer

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;


[Support.1]
Meter=Shape
This=0,0 | 4,255,83,(100*#TweenNode3#) ; 0.0 | 0,0,0,0 ; 1.0
That=180 | 04ff58 ; 0.0 | 04cc47 ; 1.0
Shape=Rectangle 0,0,300,300,5 | StrokeWidth ((2+4*#TweenNode3#)*#Sec.S#) | Fill RadialGradient This | SCale #Sec.S#,#Sec.S#,0,0 | Stroke LinearGradient That
MouseOverAction=[!CommandMeasure Tween:M "Restart(2)"]
MouseLeaveAction=[!CommandMeasure Tween:M "Rewind(2)"]
X=(#Sec.W#/2-300*#sec.S#-#Sec.P2#/2)
Y=(170*#Sec.S#)
MeterStyle=Support:S
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals"]
[SupportImage.1]
Meter=Image
ImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\DA.png
MeterStyle=SupportImage:S
[SupportText.1]
MEter=String
Text=Watch me on#CRLF#DeviantArt
X=((20-5*#TweenNode3#)*#Sec.S#)R
Y=((90-5*#TweenNode3#)*#Sec.S#)R
InlineSetting3=GradientColor | 180 | 04ff58 ; 0.0 | 04cc47 ; 1.0
MeterStyle=Set.String:S | SupportText:S

[Support.3]
Meter=Shape
This=0,0 | 255,255,255,(100*#TweenNode4#) ; 0.0 | 0,0,0,0 ; 1.0
That=180 | 29ABE0 ; 0.0 | FF5E5B ; 1.0
Shape=Rectangle 0,0,300,300,5 | StrokeWidth ((2+4*#TweenNode4#)*#Sec.S#) | Fill RadialGradient This | SCale #Sec.S#,#Sec.S#,0,0 | Stroke LinearGradient That
MouseOverAction=[!CommandMeasure Tween:M "Restart(3)"]
MouseLeaveAction=[!CommandMeasure Tween:M "Rewind(3)"]
X=(#Sec.W#/2+#Sec.P2#/2)
Y=(170*#Sec.S#)
MeterStyle=Support:S
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
[SupportImage.3]
Meter=Image
ImageName=#ROOTCONFIGPATH#Accessories\Tour\Images\KF.png
MeterStyle=SupportImage:S
[SupportText.3]
MEter=String
Text=Buy me a coffee on#CRLF#Ko-fi
InlineSetting3=GradientColor | 180 | 29ABE0 ; 0.0 | FF5E5B ; 1.0
X=((20-5*#TweenNode4#)*#Sec.S#)R
Y=((90-5*#TweenNode4#)*#Sec.S#)R
MeterStyle=Set.String:S | SupportText:S

; ---------------------------------------------------------------------------- ;
;                                   next page                                  ;
; ---------------------------------------------------------------------------- ;

[Page.ButtonNext.Shape]
Meter=Shape
X=(#Sec.W#-(20)*#Sec.S#-#Sec.p2#)
Y=(#Sec.H#-(40)*#Sec.S#-#Sec.p2#)
Shape=Ellipse 0,0,(20*#sec.S#) | StrokeWidth 0 | Extend This
This=Fill Color 0,255,0,(100)
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,(200)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,255,0,(100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure LoadActions "Execute 2"]
Container=GlobalContainer
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