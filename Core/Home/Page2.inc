[variables]
@includeVars=#@#Vars.inc

[BC]
MouseScrollDownAction=
MouseScrollUpAction=

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[title.Text1]
Meter=String
MeterStyle=Set.String:S
Text=Season 2 is out!
X=(#Set.P#)
Y=((110*[Set.S]))
FontSize=40
FontFace=Poppins SemiBold
StringAlign=LeftTop
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])
