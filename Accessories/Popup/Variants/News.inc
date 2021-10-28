; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="Celebrating 1000 members!"
FontSize=(20*#Sec.S#)
Clipstring=0
inlinePattern=1000
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Description]
Text="To show appreciation to every one of you awesome people,#CRLF#I am hosting 3 giveaways in the coming 3 days,#CRLF#along with IdleStyle's beta release!#CRLF##CRLF#Join the Discord server to participate!"
inlinePattern=3 giveaways|beta release
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