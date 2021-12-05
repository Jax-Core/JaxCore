; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="IdleStyle released!"
FontSize=(20*#Sec.S#)
Clipstring=0
inlinePattern=.*
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0

[Description]
Text="Screensavers reimagined! Display various things including skins, animations and videos when you are idle! A must have if you want people to see the fancy side of your desktop!"
inlinePattern=Screensavers reimagined!|skins, animations and videos
InlineSetting=Color | FF700F

[INfo]
Text="Click here to be redirected to the DeviantArt post"


[WhatsNew:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
Colorover=84, 235, 131
Colorleave=399F59
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
meterStyle=BottomBox:S | FalseStyleDesk
[WhatsNew:String]
Meter=String
StringAlign=CenterCenter
Text=Let's go!
MeterStyle=Sec.String:S | BottomText:S

[Esc:override]
FillE=Fill Color 0,0,0,200
MouseOverAction=[!SetOption Esc FillE "Fill Color 0,0,0"][!UpdateMeter Esc][!Redraw]
MouseLeaveAction=[!SetOption Esc FillE "Fill Color 0,0,0,200"][!UpdateMeter Esc][!Redraw]