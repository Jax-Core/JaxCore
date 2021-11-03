; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="IdleStyle Beta"
FontSize=(20*#Sec.S#)
Clipstring=0
inlinePattern=Beta
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Description]
Text="IdleStyle is an extensive skin that allows you to display various things when you go idle, including videos and animations!#CRLF##CRLF#Join the discord server, download the beta and participate in the discussion!"
inlinePattern=IdleStyle|display various things|download the beta
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