; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="Join the CoreCommunity!"

[Description]
Text="Get assistance, suggest features, participate in beta tests and more! Join the 300+ other members today!"

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