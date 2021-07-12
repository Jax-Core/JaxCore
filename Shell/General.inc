[Variables]
BarHandler=2

[Header]
Meter=String
X=(20*#Set.S#)
Y=(20*#Set.S#+#Scroll#)
DynamicVariables=1
Text=General /#Skin.Shorthand#
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

[Time]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Time
MeterStyle=Set.String:S
Container=ContentContainer

[Option01]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Time format: 24(H) 12(I)
MeterStyle=Set.String:S
Container=ContentContainer


;================================================================================================================================================================================

[Weathers]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Weather
MeterStyle=Set.String:S
Container=ContentContainer

[Option11]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Weather location
MeterStyle=Set.String:S
Container=ContentContainer
[Divider19w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Unit (Metric/Imperial)
MeterStyle=Set.String:S
Container=ContentContainer

;================================================================================================================================================================================




;================================================================================================================================================================================


[2412]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option01:Y]-#Set.P#-30/2+8)
[Value01]
Meter=String
Text=#2412#
MeterStyle=Set.String:S | Set.Value:S

[WeatherLocation]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option11:Y]-#Set.P#-30/2+8)
[Value11]
Meter=String
Text=#WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[WeatherUnits]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option12:Y]-#Set.P#-30/2+8)
[Value12]
Meter=String
Text=#WeatherUnits#
MeterStyle=Set.String:S | Set.Value:S

;================================================================================================================================================================================

[Input]
Measure=Plugin
Plugin=InputText
SolidColor=171717
FontColor=255,255,255
FontFace=Seqoe UI
FontSize=(10*#Set.S#)
StringAlign=LeftCenter
W=(150-10)
H=(30-10)
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!SetVariable #Editing# "$UserInput$"][!UpdateMeasure SaveAndLoad:M]

[SaveAndLoad:M]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables #Editing# "[##Editing#]" "#@#Vars.inc"][!UpdateMeter *][!Redraw]
Disabled=1
Group=NUOL