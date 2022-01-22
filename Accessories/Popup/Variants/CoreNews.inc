; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[Image]
ImageName=Variants\Splash\#Sec.Arg1#.png

[Title]
Meter=String
Text="JaxCore v41005 - MIUISHADE NOTICE"
MeterStyle=Sec.String:S | Style.Title:S

[Description.0]
Meter=String
Text=- IMPORTANT! MIUI-Shade is unable to be automatically updated right now. CLICK THIS MESSAGE to copy the patch code, then right click Core's close button, select "Bang", paste copied contents and press enter. Then you can update from Core.
MeterStyle=Sec.String:S | Style.Description:S
[Link.0]
Meter=String
Text="Click here to copy"
Y=R
LeftMouseUpAction=[!SetClip """"#SKINSPATH#MIUI-Shade\@Resources\Actions\AHKv1.exe" "#SKINSPATH#MIUI-Shade\@Resources\Actions\Source Code\close.ahk""""]
MeterStyle=Sec.String:S | Style.Link:S

[Description.1]
Meter=String
Text="- NEW! CoreData now generates module independently"
MeterStyle=Sec.String:S | Style.Description:S

; [Description.5]
; Meter=String
; Text="- NEW! The @Start panel will now be hidden when you install a widget from Core!"
; MeterStyle=Sec.String:S | Style.Description:S

[Description.2]
Meter=String
Text="- Release and update schedule is now available, read it here:"
MeterStyle=Sec.String:S | Style.Description:S
[Link.1]
Meter=String
Text="https://ibb.co/58S57fD"
LeftMouseUpAction=["https://ibb.co/58S57fD"]
MeterStyle=Sec.String:S | Style.Link:S

; [Description.4]
; Meter=String
; Text="- We'll be needing langauge translators soon. If you can help out, join the discord server to be notified when it's available! Thanks :D"
; MeterStyle=Sec.String:S | Style.Description:S

; [Description.4]
; Meter=String
; Text="- Fixed alignment context menu not displaying"
; MeterStyle=Sec.String:S | Style.Description:S

; [Description.5]
; Meter=String
; Text="- Added Scrollbar and a few bug fixes"
; MeterStyle=Sec.String:S | Style.Description:S

; [Description.6]
; Meter=String
; Y=(#Sec.P#*2)R
; Text="Happy Holidays everyone! This is the biggest update Core has ever received, if you liked it consider leaving a star on the DeviantArt post!"
; MeterStyle=Sec.String:S | Style.Description:S


; [DA:]
; Meter=Shape
; X=(#Sec.W#/2-(#Sec.BottomWidth#*3+#Sec.P#)/2)
; Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
; Colorover=84, 235, 131
; Colorleave=399F59
; LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals/art/903806619"]
; meterStyle=BottomBox:S | FalseStyleDesk
; [DA:String]
; Meter=String
; StringAlign=CenterCenter
; Text=DA post
; MeterStyle=Sec.String:S | BottomText:S
[Core:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*2+#Sec.P#/2)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!DeactivateConfig]
meterStyle=BottomBox:S | FalseStyleDesk
[Core:String]
Meter=String
StringAlign=CenterCenter
Text=Global variables
MeterStyle=Sec.String:S | BottomText:S
[DiscordServer:]
Meter=Shape
ColorLeave=88, 101, 242,150
ColorOver=88, 101, 242
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
meterStyle=BottomBox:S | FalseStyleDesk
[DiscordServer:String]
Meter=String
StringAlign=CenterCenter
Text=Join the Discord
MeterStyle=Sec.String:S | BottomText:S