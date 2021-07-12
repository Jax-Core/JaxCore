[Variables]
BarHandler=3

[Header]
Meter=String
X=(20*#Set.S#)
Y=(20*#Set.S#)
Text=Appearance /#Skin.Shorthand#
FontSize=(20*#Set.S#)
FontWeight=450
MeterStyle=Set.String:S
Container=ContentContainer
Leftmouseupaction=[!Refresh]
InlinePattern=\s(.*)
InlineSetting=Size | 10
InlinePattern2=\s(.*)
InlineSetting2=Color | 150,150,150

;================================================================================================================================================================================

[ColorScheme]
Meter=String
X=r
Y=(10*#Set.S#)R
FontSize=(10*#Set.S#)
FontWeight=400
Text=Color theme
MeterStyle=Set.String:S
Container=ContentContainer
[ColorMode]
Meter=Shape
X=r
Y=(10*#Set.S#)R
Shape=Rectangle 0,0,(#Set.W#-#Set.L#-#Set.P#-20*2),50,(#Set.R#/2),(#Set.R#/2) | StrokeWidth 2 | StrokeColor 255,255,255 | Fill Color 0,0,0,0
Shape2=Rectangle ([##CURRENTSECTION#] = 1 ? ((#Set.W#-#Set.L#-#Set.P#-20*2)/2) : 0),0,((#Set.W#-#Set.L#-#Set.P#-20*2)/2),50,(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 255,255,255
Container=ContentContainer
[ColorMode0]
Meter=String
X=((#Set.W#-#Set.L#-#Set.P#-20*2)/4)r
Y=(50/2)r
Padding=((#Set.W#-#Set.L#-#Set.P#-20*2)/4),25,((#Set.W#-#Set.L#-#Set.P#-20*2)/4),25
Text=Light
FontColor=(#ColorMode# = 0 ? 0 : 255),(#ColorMode# = 0 ? 0 : 255),(#ColorMode# = 0 ? 0 : 255)
StringAlign=CenterCenter
MeterStyle=Set.String:S
Shape=Rectangle 0,0,((#Set.W#-#Set.L#-#Set.P#-20*2)/2),50,(#Set.R#/2),(#Set.R#/2) | Fill Color 0,0,0,1 | StrokeWidth 0
Leftmouseupaction=[!WriteKeyValue Variables ColorMode 0 "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKeyValue Variables MainColor "255,255,255" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKeyValue Variables OppositeColor "12,12,12" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh][!Delay 1000][!Refresh "#SKINSPATH##Skin.Name#\Main"]
[ColorMode1]
Meter=String
X=(20+(#Set.W#-#Set.L#-#Set.P#-20*2)/4*3)
Y=r
Padding=((#Set.W#-#Set.L#-#Set.P#-20*2)/4),25,((#Set.W#-#Set.L#-#Set.P#-20*2)/4),25
Text=Dark
FontColor=(#ColorMode# = 1 ? 0 : 255),(#ColorMode# = 1 ? 0 : 255),(#ColorMode# = 1 ? 0 : 255)
StringAlign=CenterCenter
MeterStyle=Set.String:S
Shape=Rectangle 0,0,((#Set.W#-#Set.L#-#Set.P#-20*2)/2),50,(#Set.R#/2),(#Set.R#/2) | Fill Color 0,0,0,1 | StrokeWidth 0
Leftmouseupaction=[!WriteKeyValue Variables ColorMode 1 "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKeyValue Variables OppositeColor "255,255,255" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKeyValue Variables MainColor "12,12,12" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!Refresh][!Delay 1000][!Refresh "#SKINSPATH##Skin.Name#\Main"]

;================================================================================================================================================================================
