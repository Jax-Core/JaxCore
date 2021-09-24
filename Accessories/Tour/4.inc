
[Set.string:S]
Container=ContentCOntainer

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;


[Header]
Meter=String
Text=Take a look at how Core works!
X=(#Sec.W#/2)
Y=(#Sec.H#/2-([Header:H])/2)
FontSize=(20)
DynamicVariables=1
FontFace=Poppins SemiBold
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=Core
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

; [Des]
; Meter=String
; Text=Check out what Core provides
; X=(#Sec.W#/2)
; Y=(#Sec.P#)R
; W=(#SEc.W#-#Sec.P#*2)
; ClipString=2
; StringAlign=Center
; FontColor=#Set.TextColor#
; MeterStyle=Set.String:S
; InlinePattern=Search
; InlineSetting=Color | 0,255,50

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;


[Button]
Meter=Shape
MeterStyle=Button:S
[ButtonText]
MEter=String
Text=Let's Go!
MeterStyle=Set.String:S | ButtonText:S