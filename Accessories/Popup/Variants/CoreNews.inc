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
Text=IMPORTANT ISSUE
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text=Please manually update JaxCore now.
MeterStyle=Sec.String:S | Style.Description:S

; [Description.0]
; Meter=String
; Text=- NEW! 3 upcoming releases: YourMixer (VolumeMixer), ValliStart 3.0, YourFlyouts (MediaFlyouts)
; MeterStyle=Sec.String:S | Style.Description:S
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

; [Description.2]
; Meter=String
; Text=- NEW! You can now translate most of Core to your language! Note: Module setting pages translation is not supported yet.
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
[KF:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*1+#Sec.P#*0)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
Colorover=#Set.Accent_Color#
Colorleave=#Set.Accent_Color#
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/JaxCore/releases/download/v44000/JaxCore_v44000.rmskin"][!SetVariable DownloadName "JaxCore44000"][!SetVariable DownloadConfig "#JaxCore"][!CommandMeasure CoreInstallHandler "Install"]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=Update
MeterStyle=Sec.String:S | BottomText:S


[CoreInstallHandler]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
ExecutionPolicy=Unrestricted
; [Core:]
; Meter=Shape
; X=(#Sec.W#/2-(#Sec.BottomWidth#*2+#Sec.P#/2)/2)
; Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
; LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!DeactivateConfig]
; LeftMouseUpAction=[!DeactivateConfig]
; meterStyle=BottomBox:S | FalseStyleDesk
; [Core:String]
; Meter=String
; StringAlign=CenterCenter
; Text=Okay!
; MeterStyle=Sec.String:S | BottomText:S
; [DiscordServer:]
; Meter=Shape
; ColorLeave=88, 101, 242,150
; ColorOver=88, 101, 242
; LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
; meterStyle=BottomBox:S | FalseStyleDesk
; [DiscordServer:String]
; Meter=String
; StringAlign=CenterCenter
; Text=Join the Discord
; MeterStyle=Sec.String:S | BottomText:S