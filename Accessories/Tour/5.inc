
[MeasureUser]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1
; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;


[Header]
Meter=String
Text=You're all set!
X=(#Sec.W#/2)
Y=(#Sec.H#/2-([Header:H]+[Des:H])/2)
FontSize=(20)
DynamicVariables=1
FontFace=Poppins SemiBold
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=all set!
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
[Des]
Meter=String
Text=Enjoy your new desktop experience!
X=(#Sec.W#/2)
Y=(#Sec.P#)R
W=(#SEc.W#-#Sec.P#*2)
ClipString=2
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=Search
InlineSetting=Color | 0,255,50

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;


[Button]
Meter=Shape
LeftMouseUpAction=[!WriteKeyValue Variables UserNameCheckVariable "[MeasureUser]" "#@#Vars.inc"][!WriteKeyValue Variables Sec.Page 1 "#ROOTCONFIGPATH#Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.ini"][!DeactivateConfig]
DynamicVariables=1
MeterStyle=Button:S
[ButtonText]
MEter=String
Text=Finish
MeterStyle=Set.String:S | ButtonText:S