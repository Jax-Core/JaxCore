;===========================================================================================================================
;===========================================================================================================================

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

;===========================================================================================================================
;===========================================================================================================================

[Info]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 1 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 1 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 1 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Appearance]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 2 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 2 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 2 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Layout]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 3 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 3 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 3 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[General]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 4 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 4 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 4 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Media]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 5 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 5 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 5 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Render]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 6 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 6 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 6 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]


;===========================================================================================================================
;===========================================================================================================================

[InfoIcon]
Meter=Image
X=(#Set.P#*1.5)
Y=(#Set.P#*4+64)
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 1 ? 1 : 0)
ImageTint=(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255)

[AppearanceIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 2 ? 1 : 0)
ImageTint=(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255)

[LayoutIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 3 ? 1 : 0)
ImageTint=(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255)

[GeneralIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 4 ? 1 : 0)
ImageTint=(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255)

[MediaIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 5 ? 1 : 0)
ImageTint=(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255)

[RenderIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 6 ? 1 : 0)
ImageTint=(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255)


;===========================================================================================================================
;===========================================================================================================================

[1]
Meter=String
Text=Info
X=(#Set.P#*1.5+24+5)
Y=([InfoIcon:Y]+24/2)
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[2]
Meter=String
Text=Appearance
MeterStyle=Set.String:S | PageText:S

[3]
Meter=String
Text=Layout
MeterStyle=Set.String:S | PageText:S

[4]
Meter=String
Text=General
MeterStyle=Set.String:S | PageText:S

[5]
Meter=String
Text=Media
MeterStyle=Set.String:S | PageText:S

[6]
Meter=String
Text=Render
MeterStyle=Set.String:S | PageText:S


;===========================================================================================================================
;===========================================================================================================================


[Help:Category]
Meter=String
MeterStyle=Set.String:S
Text=HELP
FontFace=Segoe UI
X=#Set.P#
Y=(#Set.H#-140)
StringAlign=Left
FontSize=(8*#Set.S#)
Container=
FontColor=150,150,150

;===========================================================================================================================
;===========================================================================================================================

[Help]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 11 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 11 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 11 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1

[FAQ]
Meter=Shape
MeterStyle=PageBox:S
Fill=Fill Color #Set.Opp_Color#,(#BarHandler# = 12 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 12 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Opp_Color#,(#BarHandler# = 12 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]


[HelpIcon]
Meter=Image
X=(#Set.P#*1.5)
Y=(#Set.H#-140+#Set.P#*2)
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 11 ? 1 : 0)
ImageTint=(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255)

[FAQIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 12 ? 1 : 0)
ImageTint=(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255)


[11]
Meter=String
Text=Help
X=(#Set.P#*1.5+24+5)
Y=([HelpIcon:Y]+24/2)
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[12]
Meter=String
Text=FAQ
MeterStyle=Set.String:S | PageText:S
