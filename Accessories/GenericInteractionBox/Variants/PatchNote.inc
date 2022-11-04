
[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=([Anchor:Y])
AniDir=Bottom
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#WORKAREAHEIGHT#-20)
[anchorX]
Formula=50
[anchorY]
Formula=100

; ---------------------------------------------------------------------------- ;
;                                  MeterStyleS                                 ;
; ---------------------------------------------------------------------------- ;
[Style.Title:S]
X=(#Sec.P#)
Y=#Sec.P#
FontSize=(18*#Sec.S#)
FontFace=#Set.Font# 
FontWeight=(650)
DynamicVariables=1
ClipString=2
W=(#Sec.W#-#Sec.P#*2)
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0

[Style.Description:S]
X=(#Sec.P#)
Y=(#Sec.P#)R
FontSize=(12*#Sec.S#)
ClipString=2
W=(#Sec.W#-#Sec.P#*2)
inlinePattern=NEW!
InlineSetting=Color | FFC83D
inlinePattern2=IMPORTANT!
InlineSetting2=Color | 255,0,0

[Style.NextLineDescription:S]
X=(#Sec.P#)
Y=(#Sec.S#*22)r
FontSize=(12*#Sec.S#)
inlinePattern=NEW!
InlineSetting=Color | FFC83D

[Style.Link:S]
FontColor=059FD8
X=(#Sec.P#)
Y=(#Sec.S#*22)r
FontSize=(12*#Sec.S#)
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Style.Link:S | Link:Over"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Style.Link:S | Link:Leave"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Link:Leave]
InlineSetting=
[Link:Over]
InlineSetting=Underline

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Contents]
@includeCacheVarsConfigurator=#@#CacheVars\Configurator.inc
@includeContent=#SKINSPATH##Skin.name#\Core\PatchNote\Main.inc

[Anchor]
Meter=String
X=0
Y=(#Sec.P#)R
