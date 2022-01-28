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
Text=Golden Insiders \ Translators recruiting now!
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text=- NEW! To show my appreciation for my supporters, both one-time donors and monthly donors now have early access to upcoming modules! Check it out on my kofi page.
MeterStyle=Sec.String:S | Style.Description:S

[Description.0]
Meter=String
Text=- NEW! 3 upcoming releases: YourMixer (VolumeMixer), ValliStart 3.0, YourFlyouts (MediaFlyouts)
MeterStyle=Sec.String:S | Style.Description:S
; [Link.0]
; Meter=String
; Text=Click here to copy
; Y=R
; LeftMouseUpAction=[!SetClip """"#SKINSPATH#MIUI-Shade\@Resources\Actions\AHKv1.exe" "#SKINSPATH#MIUI-Shade\@Resources\Actions\Source Code\close.ahk""""]
; MeterStyle=Sec.String:S | Style.Link:S

; [Description.5]
; Meter=String
; Text="- NEW! The @Start panel will now be hidden when you install a widget from Core!"
; MeterStyle=Sec.String:S | Style.Description:S

[Description.2]
Meter=String
Text=- I am now finding translation helpers to adjust Core language files! You can apply now on the Discord server.
MeterStyle=Sec.String:S | Style.Description:S

[Description.3]
Meter=String
Text=- Our Discord server had just reached 4000 members! Join us today!
MeterStyle=Sec.String:S | Style.Description:S


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
[KF:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*3+#Sec.P#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
Colorover=FF5E5A
Colorleave=FF5E5A
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=Ko-fi page
MeterStyle=Sec.String:S | BottomText:S
[Core:]
Meter=Shape
; X=(#Sec.W#/2-(#Sec.BottomWidth#*2+#Sec.P#/2)/2)
; Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
; LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!DeactivateConfig]
LeftMouseUpAction=[!DeactivateConfig]
meterStyle=BottomBox:S | FalseStyleDesk
[Core:String]
Meter=String
StringAlign=CenterCenter
Text=Okay!
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