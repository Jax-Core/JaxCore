
[Set.string:S]
Container=ContentCOntainer

[Support:S]
X=(#Sec.W#/2-300/2*#Sec.S#)
Y=(10*#Sec.S#)R
Shape=Rectangle 0,0,300,50,5 | StrokeWidth 0 | Extend This | SCale #Sec.S#,#Sec.S#,0,0
This=Fill Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.SubText_color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentCOntainer
[SupportImage:S]
Y=((50/2-32/2)*#Sec.S#)r
W=(32*#Sec.S#)
H=(32*#Sec.S#)
DynamicVariables=1
Greyscale=1
Container=ContentCOntainer
[SupportText:S]
X=(5*#Sec.S#)R
Y=(32/2*#Sec.S#)r
FontSize=(10*#Sec.S#)
StringAlign=LeftCenter
FontColor=#Set.Text_Color#
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
FontFace=#Set.Font# 
FontWeight=(650)
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=Support
InlineSetting=GradientColor | 180 | CC1C15 ; -1.0 | FF700F ; 1.0

[Support.1]
Meter=Shape
Y=(40*#Sec.S#)R
MeterStyle=Support:S
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals"]
[SupportImage.1]
Meter=Image
X=(#Sec.W#/2-([#CURRENTSECTION#:W]+[SupportText.1:W]+5*#Sec.S#)/2)
ImageName=#@#Icons\DA.png
ImageTint=05C645
MeterStyle=SupportImage:S
[SupportText.1]
MEter=String
Text=Watch me on DeviantArt
MeterStyle=Set.String:S | SupportText:S

[Support.3]
Meter=Shape
Y=(10*#Sec.S#)R
MeterStyle=Support:S
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
[SupportImage.3]
Meter=Image
X=(#Sec.W#/2-([#CURRENTSECTION#:W]+[SupportText.3:W]+3*#Sec.S#)/2)
ImageName=#@#Icons\Donate.png
ImageTint=#Set.Accent_Color#
MeterStyle=SupportImage:S
[SupportText.3]
MEter=String
Text=Buy me a coffee
MeterStyle=Set.String:S | SupportText:S

[Support.2]
Meter=Shape
Y=(10*#Sec.S#)R
MeterStyle=Support:S
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
[SupportImage.2]
Meter=Image
X=(#Sec.W#/2-([#CURRENTSECTION#:W]+[SupportText.2:W]+5*#Sec.S#)/2)
ImageName=#@#Icons\Discord.png
ImageTint=108, 130, 206
MeterStyle=SupportImage:S
[SupportText.2]
MEter=String
Text=Join the Core Community
MeterStyle=Set.String:S | SupportText:S

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;

[Button]
Meter=Shape
MeterStyle=Button:S
[ButtonText]
MEter=String
Text=Continue
MeterStyle=Set.String:S | ButtonText:S