[Variables]
Spotlight=ModularVisualizer

[BC]
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#+60,0,(#Set.PageH#-#Set.H#)))"][!UpdateMeterGroup Scroll][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#-60,0,(#Set.PageH#-#Set.H#)))"][!UpdateMeterGroup Scroll][!Redraw]
Group=Scroll

[SkinIcon:S]
X=(#Set.P#/2+((#Set.W#-(#Set.P#*3))/3)-(10*[Set.S]))r
Y=(15-(((#Set.W#-(#Set.P#*3))/3)/1.5))r
W=((#Set.W#-(#Set.P#*3))/3)
H=(((#Set.W#-(#Set.P#*3))/3)/1.5)
; PreserveAspectRatio=1
; SolidColor=255,0,0,100
; Container=[#CURRENTSECTION]Shape
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name [#CURRENTSECTION] "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#CURRENTCONFIG#" "Settings.ini"]
DynamicVariables=1
MaskImageName=#@#Images\Mask.png
Container=BC
[SkinText:S]
X=(10*[Set.S])r
y=(-15)R
FontSize=(15*[Set.S])
FontFace=#Set.Font# 
FontWeight=(650)
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Size | (10*[Set.S])
InlinePattern2=#CRLF#.*
InlineSetting2=Color | #Set.SubText_Color#
[TopButton:S]
X=r
y=r
Padding=(5*[Set.S]),(5*[Set.S]),(5*[Set.S]),(5*[Set.S])
W=(30*[Set.S])
H=(30*[Set.S])
DynamicVariables=1
Container=BC
; -------------------------------- Fade effect ------------------------------- ;

[BarClip]
Fill=Fill Color #Set.Pri_Color#,(#Scroll# > 0 ? 255 : 0)
Group=Scroll

[Image]
Meter=Image
W=(#Set.W#)
H=(#Set.H#*0.5)
Group=Scroll
ImageAlpha=(#Scroll# > 0 ? 0 : 25)
PreserveAspectRatio=2
DynamicVariables=1
ImageName=#@#Images\Cards\#Spotlight#.png
MaskImageName=#@#Images\FadeMask.png
Container=BC

; --------------------------------- Spotlight -------------------------------- ;

[title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Desktop components // Accessories to add to your desktop
X=(#Set.P#)
Y=((110*[Set.S])-#Scroll#)
FontSize=40
FontFace=#Set.Font# 
FontWeight=(650)
Group=Scroll
StringAlign=LeftTop
InlinePattern=(.*)//
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
InlinePattern2=\/\/.*
InlineSetting2=Size | (14*[Set.S])
InlinePattern3=\/\/.*
InlineSetting3=Weight | 300
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])

; --------------------------------- Spotlight -------------------------------- ;

[SpotDes]
Meter=String
X=r
y=([title.Text1:H]*([Set.S]-1)+25*[Set.S])R
W=(#Set.W#-#Set.P#*3-500*[Set.S])
ClipString=2
FontSize=(30*[Set.S])
FontFace=#Set.Font# 
FontWeight=(650)
StringAlign=Left
InlinePattern=#CRLF#.*
InlineSetting=Size | (12*[Set.S])
InlinePattern2=#CRLF#.*
InlineSetting2=Weight | 300
MeterStyle=Set.String:S
Text=#Spotlight##CRLF#Exceedingly customizable audio visualizer, with numerous built-in layouts and over 40 options to play with. With an additional packaged 3D overlay module to create layering effects.
[SpotImage]
Meter=Image
X=(#Set.W#-#Set.P#-500*[Set.S])
Y=r
W=(500*[Set.S])
DynamicVariables=1
ImageName=#@#Images\Cards\#Spotlight#.png
Container=BC
MaskImageName=#@#Images\RoundedMask.png
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name #Spotlight# "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#CURRENTCONFIG#" "Settings.ini"]
; ------------------------------- Bottom Start ------------------------------- ;

[RecommendedSkins]
Meter=String
Text=All skins
MeterStyle=Set.String:S
X=(#Set.P#)
Y=(65*[Set.S])R
Group=Scroll
FontSize=15
StringAlign=LeftTop
FontFace=#Set.Font# 
FontWeight=(650)
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])

; ; --------------------------------- Generated -------------------------------- ;

@includeGenerated2=#ROOTCONFIGPATH#CoreShell\Home\Generated2.inc