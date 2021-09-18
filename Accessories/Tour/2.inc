
[Set.string:S]
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Header]
Meter=String
Text=Welcome to JaxCore3
X=(#Sec.W#/2)
Y=(#Sec.H#/2-([Header:H]+[Des:H])/2-#sec.P#)
FontSize=(20)
DynamicVariables=1
FontFace=Poppins SemiBold
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=JaxCore3
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Des]
Meter=String
Text=The new look of Core. Core provides the functionality to customize my skins with ease, allows you to check for updates, shows you all of the skins published and install any of them with a single click.
X=(#Sec.W#/2)
Y=(#Sec.P#)R
W=(#SEc.W#-#Sec.P#*2)
ClipString=2
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;

[Button]
Meter=Shape
MeterStyle=Button:S
[ButtonText]
MEter=String
MeterStyle=Set.String:S | ButtonText:S