[General:Category]
Meter=String
MeterStyle=Set.String:S
Text=GENERAL
FontFace=Segoe UI
X=#Set.P#
Y=(#Set.P#*2+64)
StringAlign=Left
FontSize=(8*#Set.S#)
Container=
FontColor=150,150,150
[Info]
Meter=Shape
Y=(10*#Set.S#)R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 1 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 1 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 1 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InfoIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 1 ? 1 : 0)
ImageTint=(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255)

[1]
Meter=String
Text=Info
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[General]
Meter=Shape
Y=(10*#Set.S#)R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 2 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 2 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 2 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[GeneralIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 2 ? 1 : 0)
ImageTint=(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255)

[2]
Meter=String
Text=General
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
[Appearance]
Meter=Shape
Y=(10*#Set.S#)R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 3 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 3 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 3 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[AppearanceIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 3 ? 1 : 0)
ImageTint=(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255)

[3]
Meter=String
Text=Appearance
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
[Render]
Meter=Shape
Y=(10*#Set.S#)R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 6 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 6 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 6 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[RenderIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 6 ? 1 : 0)
ImageTint=(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255)

[6]
Meter=String
Text=Render
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
[Help:Category]
Meter=String
MeterStyle=Set.String:S
Text=HELP
FontFace=Segoe UI
X=#Set.P#
Y=(#Set.H#-140*#Set.S#)
StringAlign=Left
FontSize=(8*#Set.S#)
Container=
FontColor=150,150,150
[Help]
Meter=Shape
Y=(10*#Set.S#)R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 11 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 11 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 11 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[HelpIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 11 ? 1 : 0)
ImageTint=(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255)

[11]
Meter=String
Text=Help
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
[FAQ]
Meter=Shape
Y=(10*#Set.S#)R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 12 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 12 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 12 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[FAQIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 12 ? 1 : 0)
ImageTint=(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255)

[12]
Meter=String
Text=FAQ
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
