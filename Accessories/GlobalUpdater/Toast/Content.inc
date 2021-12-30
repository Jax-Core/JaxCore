[MIUI-Shade]
Meter=String
Y=90
MeterStyle=Set.String:S | Skin.Name:S

[MIUI-Shade.VerDiff]
Meter=String
Text=1.9 > 2.01
MeterStyle=Set.String:S | Skin.VerDiff:S

[MIUI-Shade.UpdateButton]
Meter=Shape
LeftMouseUpAction=[!CommandMeasure CoreBridge "install('MIUI-Shade')"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Skin.UpdateButton.Shape:S

[MIUI-Shade.UpdateIcon]
Meter=String
MeterStyle=Set.String:S | Skin.UpdateButton.Icon:S

[Variables]
Sec.H=(100+40*1)
            