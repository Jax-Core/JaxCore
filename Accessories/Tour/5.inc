
[Set.string:S]
Container=ContentCOntainer

[Support:S]
X=(#Sec.W#/2-300/2)
Y=10R
Shape=Rectangle 0,0,300,50,5 | StrokeWidth 0 | Extend This
This=Fill Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.SubText_color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentCOntainer
[SupportImage:S]
Y=(50/2-32/2)r
W=32
H=32
DynamicVariables=1
Greyscale=1
Container=ContentCOntainer
[SupportText:S]
X=5R
Y=(32/2)r
FontSize=10
StringAlign=LeftCenter
FontColor=255,255,255
Container=ContentCOntainer

[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Header]
Meter=String
Text=Support me
X=(#Sec.W#/2)
Y=(#Sec.H#*0.2)
FontSize=(20)
DynamicVariables=1
FontFace=Poppins SemiBold
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=me
InlineSetting=GradientColor | 180 | CC1C15 ; -1.0 | FF700F ; 1.0

[Support.1]
Meter=Shape
Y=40R
MeterStyle=Support:S
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals"]
[SupportImage.1]
Meter=Image
X=(#Sec.W#/2-([#CURRENTSECTION#:W]+[SupportText.1:W]+5)/2)
ImageName=#@#Icons\DA.png
ImageTint=05C645
MeterStyle=SupportImage:S
[SupportText.1]
MEter=String
Text=Watch me on DeviantArt
MeterStyle=Set.String:S | SupportText:S

[Support.3]
Meter=Shape
Y=10R
MeterStyle=Support:S
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
[SupportImage.3]
Meter=Image
X=(#Sec.W#/2-([#CURRENTSECTION#:W]+[SupportText.1:W]+5)/2)
ImageName=#@#Icons\Donate.png
ImageTint=009CDE
MeterStyle=SupportImage:S
[SupportText.3]
MEter=String
Text=Fund my University fees!
MeterStyle=Set.String:S | SupportText:S

[Support.2]
Meter=Shape
Y=10R
MeterStyle=Support:S
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
[SupportImage.2]
Meter=Image
X=(#Sec.W#/2-([#CURRENTSECTION#:W]+[SupportText.2:W]+5)/2)
ImageName=#@#Icons\Discord.png
ImageTint=108, 130, 206
MeterStyle=SupportImage:S
[SupportText.2]
MEter=String
Text=Join my discord server!
MeterStyle=Set.String:S | SupportText:S

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;

[Button]
Meter=Shape
Y=(#Sec.H#*0.75)
Shape=Rectangle 0,0,120,30,5 | StrokeWidth 0 | Fill Color #Set.Sec_Color#,(#TweenNode2#*255)
MeterStyle=Button:S
LeftMouseUpAction=[!WriteKeyValue Variables UserNameCheckVariable "[MeasureUser]" "#@#Vars.inc"][!ActivateConfig "#JaxCore\Main" "Home.ini"][!WriteKeyValue Variables Sec.Page 1][!DeactivateConfig]
[ButtonText]
MEter=String
Text=Maybe later
MeterStyle=Set.String:S | ButtonText:S