; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Text="DeviantArt"

[Description]
Text=This is the place where I release new skins. Watch me on DA to keep yourself up to date!

[INfo]
Text=Click here to be redirected to the DA page.


[WhatsNew:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
ColorLeave=0,255,0,100
ColorOver=0,255,0,200
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals"]
meterStyle=BottomBox:S | FalseStyleDesk
[WhatsNew:String]
Meter=String
StringAlign=CenterCenter
Text=Donate
MeterStyle=Sec.String:S | BottomText:S