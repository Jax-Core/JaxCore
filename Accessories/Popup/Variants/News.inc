; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title]
Meter=String
Text="Changes"
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text="- NEW! JaxCore launched it's own website! Check it out!"
MeterStyle=Sec.String:S | Style.Description:S
[Link.1]
Meter=String
Text="https://jax-core.github.io/"
LeftMouseUpAction=["https://jax-core.github.io/"]
MeterStyle=Sec.String:S | Style.Link:S

[Description.2]
Meter=String
Text="- NEW! Automated installer to make install and updates easier"
MeterStyle=Sec.String:S | Style.Description:S

[Description.3]
Meter=String
Text="- NEW! All new core settinsg menu to easily access new features"
MeterStyle=Sec.String:S | Style.Description:S

[Description.4]
Meter=String
Text="- NEW! Color schemes for Core, the one currently applied is FROSTED"
MeterStyle=Sec.String:S | Style.Description:S

[Description.5]
Meter=String
Text="- Added Scrollbar and a few bug fixes"
MeterStyle=Sec.String:S | Style.Description:S

[Description.6]
Meter=String
Y=(#Sec.P#*2)R
Text="Happy Holidays everyone! This is the biggest update Core has ever received, if you liked it consider leaving a star on the DeviantArt post!"
MeterStyle=Sec.String:S | Style.Description:S


[DA:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*3+#Sec.P#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
Colorover=84, 235, 131
Colorleave=399F59
LeftMouseUpAction=[""]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=DA post
MeterStyle=Sec.String:S | BottomText:S
[Core:]
Meter=Shape
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page General "#@#SecVar.inc"][!ActivateConfig "#CURRENTCONFIG#" "Settings.ini"]
meterStyle=BottomBox:S | FalseStyleDesk
[Core:String]
Meter=String
StringAlign=CenterCenter
Text=Core settings
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