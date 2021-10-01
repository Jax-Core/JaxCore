[Variables]
Spotlight=ValliStart

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
FontFace=Poppins Semibold
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
ImageAlpha=(#Scroll# > 0 ? 0 : 50)
PreserveAspectRatio=2
DynamicVariables=1
ImageName=#@#Images\Cards\#Spotlight#.png
MaskImageName=#@#Images\FadeMask.png
Container=BC

; --------------------------------- Spotlight -------------------------------- ;

[title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Skin spotlight
X=(#Set.P#)
Y=((110*[Set.S])-#Scroll#)
FontSize=40
FontFace=Poppins SemiBold
Group=Scroll
StringAlign=LeftTop
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])

; [SpotLight]
; Meter=String
; Text=Spotlight
; MeterStyle=Set.String:S
; X=(#Set.P#)
; Y=([title.Text1:H]*([Set.S]-1)+20*[Set.S])R
; Group=Scroll
; FontSize=10
; StringAlign=LeftTop
; FontFace=Poppins Light
; TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])

; --------------------------------- Spotlight -------------------------------- ;

[SpotDes]
Meter=String
X=r
y=([title.Text1:H]*([Set.S]-1)+25*[Set.S])R
W=(#Set.W#-#Set.P#*3-500*[Set.S])
ClipString=2
FontSize=(30*[Set.S])
FontFace=Poppins Semibold
StringAlign=Left
InlinePattern=#CRLF#.*
InlineSetting=Size | (12*[Set.S])
InlinePattern2=#CRLF#.*
InlineSetting2=Face | Poppins Thin
MeterStyle=Set.String:S
Text=#Spotlight##CRLF#Replaces the start menu with a centered design. Originated from a concept art for Windows 10 SunValley update, it acts as an control center and a start menu. You can choose to have it replace the start menu, or a seperate menu which can be summoned with a hotkey.
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
Text=Recommended Skins
MeterStyle=Set.String:S
X=(#Set.P#)
Y=(65*[Set.S])R
Group=Scroll
FontSize=15
StringAlign=LeftTop
FontFace=Poppins SemiBold
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])

; ; --------------------------------- Generated -------------------------------- ;

@includeGenerated=#ROOTCONFIGPATH#Core\Home\Generated.inc