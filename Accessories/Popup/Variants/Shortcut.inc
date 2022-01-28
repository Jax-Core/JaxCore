; ; ---------------------------------------------------------------------------- ;
; ;                                   Functions                                  ;
; ; ---------------------------------------------------------------------------- ;

; [mActions]
; Custom1=[!CommandMeasure PSRM "Check"]

; [PSRM]
; Measure=Plugin
; Plugin=PowershellRM
; DynamicVariables=1
; ScriptFile=#@#Powershell\AddShortcut.ps1

; ; ---------------------------------------------------------------------------- ;
; ;                                    Content                                   ;
; ; ---------------------------------------------------------------------------- ;

; [Title]
; Text="Add shortcut"

; [Description]
; Text="Adding a JaxCore shortcut would make it easier to access the core control panel."

; [INfo]
; Text="Buttons will turn green when the shortcut exists in the directory."


; [WhatsNew:]
; Meter=Shape
; X=(#Sec.W#/2-(#Sec.P#+#Sec.BottomWidth#*2)/2)
; Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
; meterStyle=BottomBox:S | FalseStyleDesk
; [WhatsNew:String]
; Meter=String
; StringAlign=CenterCenter
; Text=Program List
; MeterStyle=Sec.String:S | BottomText:S
; [Jax:]
; Meter=Shape
; meterStyle=BottomBox:S | FalseStyleProg
; ; LeftMouseUpAction=#@#Actions\Utils
; [Jax:String]
; Meter=String
; StringAlign=CenterCenter
; Text=Desktop folder
; MeterStyle=Sec.String:S | BottomText:S

; [FalseStyleProg]
; LeftMouseUpAction=[!CommandMeasure PSRM "Desktop"][!Delay 100][!Refresh]
; [TrueStyleProg]
; ColorLeave=0,255,0,100
; ColorOver=0,255,0,200
; LeftMouseUpAction=[!CommandMeasure PSRM "RemoveStartFolder"][!Delay 100][!Refresh]
; [FalseStyleDesk]
; LeftMouseUpAction=[!CommandMeasure PSRM "StartFolder"][!Delay 100][!Refresh]
; [TrueStyleDesk]
; ColorLeave=0,255,0,100
; ColorOver=0,255,0,200
; LeftMouseUpAction=[!CommandMeasure PSRM "RemoveDeskop"][!Delay 100][!Refresh]