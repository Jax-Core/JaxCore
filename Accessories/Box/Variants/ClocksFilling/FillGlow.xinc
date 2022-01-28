[12]
Meter=String
Text=Fill color
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[13]
Meter=String
Text=Glow color
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[14]
Meter=String
Text=Glow amount
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[1st]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=[12:Y]
[Value21]
Meter=String
Text=#1stOpacity#
MeterStyle=Sec.String:S | Set.Pacity:S
[3rd]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=[13:Y]
[Value22]
Meter=String
Text=#3rdOpacity#
MeterStyle=Sec.String:S | Set.Pacity:S
[GlowSigma]
Meter=Shape
MeterStyle=Set.Textbox:S
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*#Sec.S#)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*#Sec.S#)"][!CommandMeasure Input:M "ExecuteBatch 2"]
Y=[14:Y]
[Value23]
Meter=String
Text=#GlowSigma#
MeterStyle=Sec.String:S | Set.Value:S