[12]
Meter=String
Text=Blur modulate
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[13]
Meter=String
Text=Blur radius
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[14]
Meter=String
Text=Blur amount
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S
[15]
Meter=String
Text=Regenerate blurred image
X=r
Y=(#Sec.P#)R
MeterStyle=Sec.String:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;


[BlurModulate]
Meter=Shape
MeterStyle=Set.Textbox:S
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*#Sec.S#)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*#Sec.S#)"][!CommandMeasure Input:M "ExecuteBatch 2"]
Y=[12:Y]
[Value12]
Meter=String
Text=#BlurModulate#
MeterStyle=Sec.String:S | Set.Value:S
[BlurRadius]
Meter=Shape
MeterStyle=Set.Textbox:S
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*#Sec.S#)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*#Sec.S#)"][!CommandMeasure Input:M "ExecuteBatch 2"]
Y=[13:Y]
[Value13]
Meter=String
Text=#BlurRadius#
MeterStyle=Sec.String:S | Set.Value:S
[BlurSigma]
Meter=Shape
MeterStyle=Set.Textbox:S
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5*#Sec.S#)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5*#Sec.S#)"][!CommandMeasure Input:M "ExecuteBatch 2"]
Y=[14:Y]
[Value14]
Meter=String
Text=#BlurSigma#
MeterStyle=Sec.String:S | Set.Value:S
[Reload]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!WriteKeyvalue Variables Cache.Wallpaper "" "#Sec.SaveLocation2#"][!Refresh][!Refresh "ModularClocks\Main"]
Y=[15:Y]
[Value15]
Meter=String
Text=Regen
MeterStyle=Sec.String:S | Set.Value:S