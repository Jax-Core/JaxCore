; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="Support me!"

[Description]
Text="Thanks for using my creations! You can support me by funding my university fees!"

[INfo]
Text=""


[WhatsNew:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
ColorLeave=0,255,0,100
ColorOver=0,255,0,200
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
meterStyle=BottomBox:S | FalseStyleDesk
[WhatsNew:String]
Meter=String
StringAlign=CenterCenter
Text=Donate
MeterStyle=Sec.String:S | BottomText:S