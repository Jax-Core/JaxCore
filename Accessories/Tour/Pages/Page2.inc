
; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[ImageContainer]
Meter=Shape
Shape=Rectangle 0,(#Sec.H#*(1-#TweenNode1#)),(#Sec.W#),#Sec.H#,#Set.R# | StrokeWidth 0 | Fill LinearGradient This
This=270 | 0,0,0,(255*#TweenNode2#) ; 0 | 0,0,0,255 ; 1
DynamicVariables=1
Group=Tweenable

[Image]
Meter=Image
Container=Imagecontainer
ImageName=#@#Images\TourPreview.png
W=#Sec.W#
H=#Sec.H#
ImageAlpha=175

[Title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=JaxCore
X=(#Sec.P#)
Y=(250*#Sec.S#)
FontSize=(55*#Sec.S#)
FontFace=Poppins 
FontWeight=(650)
StringAlign=LeftCenter
InlineSetting=GradientColor | 180 | 204, 28, 21 ; 0.0 | 253, 194, 1 ; 1.0
InlineSetting2=Shadow | 0 | 0 | 5 | 0,0,0,100
Container=ImageContainer
[Title.Text2]
Meter=String
MeterStyle=Set.String:S
Text=The desktop utilities that you'll need.
X=r
Y=(80*#Sec.S#)r
FontSize=(18*#Sec.S#)
FontFace=Poppins
StringAlign=LeftCenter
InlineSetting2=Shadow | 0 | 0 | 5 | 0,0,0,100
Container=ImageContainer

[Button]
Meter=Shape
MeterStyle=Button:S
Container=ImageContainer
[ButtonText]
MEter=String
Text=Continue
; Text=[\xEBE7]
; FontFace=Segoe MDL2 Assets
MeterStyle=Set.String:S | ButtonText:S
Container=ImageContainer

[ConvertedShape]
Meter=Shape
X=(#Sec.W#-#Sec.P#-220*(#Sec.S#))
Y=(#Sec.H#/2-210*#Sec.S#)
Container=ImageContainer
Shape = Path Path1 | stroke color 140, 140, 140 | StrokeWidth 0 | Scale (#Sec.S#-0.2),(#Sec.S#-0.2),0,0 | Fill LinearGradient This
This= 180 | CC1C1520 ; 0.0 | FF700F20 ; 1.0
Path1 = 297.18398, 94.90905 | CurveTo 297.18398, 116.12225, 303.04184, 100.76691, 303.04184, 110.26439 | LineTo 227.50313, 185.8031 | LineTo 286.31111, 244.61108 | CurveTo 286.31111, 265.82428, 292.16897, 250.46894, 292.16897, 259.96642 | LineTo 116.12226, 436.01313 | CurveTo 94.90906, 436.01313, 110.2644, 441.87099, 100.76692, 441.87099 | LineTo 10.60661, 351.71068 | CurveTo 10.60661, 330.49748, 4.74875, 345.85282, 4.74875, 336.35534 | LineTo 80.28746, 260.81663 | LineTo 21.47948, 202.00865 | CurveTo 21.47948, 180.79545, 15.62162, 196.15079, 15.62162, 186.65331 | LineTo 191.66833, 10.6066 | CurveTo 212.88153, 10.6066, 197.52619, 4.74874, 207.02367, 4.74874 | ClosePath 1
DynamicVariables=1

[Logo]
Meter=Image
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png
X=(#Sec.W#-#Sec.P#-(235*#Sec.S#))
Y=(#Sec.H#/2-(220*(#Sec.S#))/2)
W=(220*#Sec.S#)
Y=(220*#Sec.S#))
Container=ImageContainer
; Hidden=(#QoL#)
DynamicVariables=1