; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="IdleStyle Beta | inactivity"
FontSize=(20*#Sec.S#)
Clipstring=0
inlinePattern=Beta
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Description]
Text="IdleStyle is a skin that allows you to display various things when you go idle. The last beta version will be released on the 13th.#CRLF##CRLF#Due to exams, there will be minimal updates next and the week after."
inlinePattern=IdleStyle|display various things|download the beta|minimal updates
InlineSetting=Color | FF700F

[INfo]
Text="Click here to be redirected to the server invite link."


[WhatsNew:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
ColorLeave=88, 101, 242,150
ColorOver=88, 101, 242
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
meterStyle=BottomBox:S | FalseStyleDesk
[WhatsNew:String]
Meter=String
StringAlign=CenterCenter
Text=Let's go!
MeterStyle=Sec.String:S | BottomText:S