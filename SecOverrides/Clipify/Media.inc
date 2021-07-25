
[Options]
Meter=String
X=(30*#Set.S#)
Y=(30*#Set.S#)R
FontSize=(14*#Set.S#)
FontWeight=500
Text=Options
MeterStyle=Set.String:S
Container=ContentContainer

[Option00]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Show media notification
MeterStyle=Set.String:S
Container=ContentContainer

;================================================================================================================================================================================


[Music]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option00:Y]-#Set.P#+(-20/2+8)*#Set.S#)


