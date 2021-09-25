[variables]
@includeVars=#@#Vars.inc

[BC]
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#+20,0,(#Set.PageH#-#Set.H#)))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#-20,0,(#Set.PageH#-#Set.H#)))"][!UpdateMeter *][!Redraw]

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[BarClip]
Fill=Fill Color #Set.Pri_Color#,(#Scroll# > 0 ? 255 : 0)

[Image]
Meter=Image
W=(#Set.W#)
H=(#Set.H#*0.6)
ImageAlpha=(#Scroll# > 0 ? 0 : 50)
PreserveAspectRatio=2
DynamicVariables=1
ImageName=#@#Images\NewsPreview.png
MaskImageName=#@#Images\FadeMask.png
Container=BC

[title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Season 2 is out!
X=(#Set.W#/2)
Y=((110*[Set.S])-#Scroll#)
FontSize=(40*[Set.S])
FontFace=Poppins SemiBold
StringAlign=Center
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Text.1]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(100*[Set.S])r
W=(#Set.W#*0.8)
H=(#Set.H#*0.5)
Clipstring=1
StringAlign=Center
Text=This marks a new beginning of Core. Thank you everyone who had supported me up till now! I will continue to make the most customizable, functional and aesthetically pleasing skins.#CRLF##CRLF#For now on, new skins will be released in a rate of 1 per 2-4 weeks in order for me to cope with my studies.#CRLF#A new skin, ValliStart will be released next week. Stay tuned!#CRLF##CRLF#If you want to support me, buy me a cup of coffee on ko-fi, or join my discord server and hang out!
InlinePattern=Thank you | new skins will be released in a rate of 1 per 2-4 weeks | ValliStart
InlineSetting=Color | #Set.Accent_Color#
InlinePattern2=ko-fi
InlineSetting2=Color | FFA56D
InlinePattern3=discord server
InlineSetting3=Color | 88,101,242

[Button:S]
Shape=Rectangle 0,0,200,40,(#Set.R#/2) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend THis
[ButtonText:S]
X=(200/2*[Set.S])r

[SkinsButton]
Meter=Shape
X=(#Set.W#/2-(200*2*[Set.S]+#Set.P#/2)/2)
Y=(250*[Set.S])r
MeterStyle=Shape.Over:S | Button:S
OverColor=FFA56D
LeaveColor=FFA56D
Leftmouseupaction=[!commandMeasure Func "startPopup('Donate')"]
[SkinsText]
Meter=String
Text=Ko-fi page
MeterStyle=Set.String:S | ButtonText:S

[DiscordButton]
Meter=Shape
X=(200/2*[Set.S]+#Set.P#/2)r
Y=(-20*[Set.S])r
MeterStyle=Shape.Over:S | Button:S
OverColor=88,101,242
LeaveColor=88,101,242
Leftmouseupaction=[!commandMeasure Func "startPopup('Discord')"]
[DiscordText]
Meter=String
Text=Join the community!
MeterStyle=Set.String:S | ButtonText:S

; ------------------------------------- 2 ------------------------------------ ;



[title.Text2]
Meter=String
MeterStyle=Set.String:S
Text=Change log
X=(#Set.W#/2)
Y=(30*[Set.S])R
FontSize=(20*[Set.S])
FontFace=Poppins SemiBold
StringAlign=Center
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Text.2]
Meter=String
MeterStyle=Set.String:S
X=r
Y=(40*[Set.S])r
W=(#Set.W#*0.8)
H=(#Set.H#*0.5)
Clipstring=1
StringAlign=Center
Text=Redesigned the core completely, again.#CRLF#Fixed shortcuts not working with some devices#CRLF#Added animations to a few accessories#CRLF#Reduced duration of welcome page#CRLF#Fixed keylaunch actions not registering quotes#CRLF#Added skin spotlight#CRLF#Added accessibility options to core to cope with crashes#CRLF#Added font gallery#CRLF#Text now scales properly in text boxes#CRLF#Update toast now allows you to dismiss#CRLF#Core updates now uses powershell instead of autohotkey