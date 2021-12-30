; [Title.Core]
; Meter=String
; MeterStyle=Set.String:S
; Text=JaxCore
; X=(#Sec.W#/2)
; Y=(#Sec.H#-#Sec.Top#)
; FontColor=#Set.Subtext_Color#
; StringAlign=CenterBottom

[BackgroundText]
Meter=String
MeterStyle=Set.String:S
Text="The desktop utilities that you'll need#CRLF#      The desktop utilities that you'll need#CRLF#            The desktop utilities that you'll need#CRLF#           The desktop utilities that you'll need"
FontFace=Runic
X=(#Sec.W#/2)
Y=(#Sec.H#)
FontColor=#Set.Subtext_Color#,10
FontSize=(40*#Sec.S#)
Angle=(Rad(-45))

[GlobalContainer]
Meter=String
X=(-#Sec.P2#*(1-#TweenNode1#))
W=(#Sec.W#)
H=#Sec.H#
SolidColor=255,255,255,(#TweenNode1#*255)
DynamicVariables=1
Group=Tweenable