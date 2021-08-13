[General:Category]
Meter=String
MeterStyle=Set.String:S | Pagecat:S
Text=GENERAL
Y=(#Set.P#+64*[Set.S])
[Info]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 1 ? 255: 0)
Handle=1

[InfoIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 1 ? 1 : 0)

[1]
Meter=String
Text=Info
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[General]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 2 ? 255: 0)
Handle=2

[GeneralIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 2 ? 1 : 0)

[2]
Meter=String
Text=General
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
[Appearance]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 3 ? 255: 0)
Handle=3

[AppearanceIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 3 ? 1 : 0)

[3]
Meter=String
Text=Appearance
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
[Render]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 6 ? 255: 0)
Handle=6

[RenderIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 6 ? 1 : 0)

[6]
Meter=String
Text=Render
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
