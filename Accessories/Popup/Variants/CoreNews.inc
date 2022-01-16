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
Text="ModularVisualizer - Released."
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text="- NEW! The most customizable visualizer, ModularVisualizer is now out. Star it on DeviantArt!"
MeterStyle=Sec.String:S | Style.Description:S
; [Link.1]
; Meter=String
; Text="https://jax-core.github.io/"
; LeftMouseUpAction=["https://jax-core.github.io/"]
; MeterStyle=Sec.String:S | Style.Link:S

[Description.2]
Meter=String
Text="- NEW! Patch notes will now be shown when module updates. This is slowly being rolled out to every one of them."
MeterStyle=Sec.String:S | Style.Description:S

[Description.3]
Meter=String
Text="- NEW! Added more quick actions to the info page."
MeterStyle=Sec.String:S | Style.Description:S

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


[DA:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*3+#Sec.P#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
Colorover=84, 235, 131
Colorleave=399F59
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals/art/903806619"]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=DA post
MeterStyle=Sec.String:S | BottomText:S
[Core:]
Meter=Shape
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name """ModularVisualizer""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"]
meterStyle=BottomBox:S | FalseStyleDesk
[Core:String]
Meter=String
StringAlign=CenterCenter
Text=mVis settings
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