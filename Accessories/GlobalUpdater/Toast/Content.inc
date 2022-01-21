[QuickNote]
Meter=String
Y=90
MeterStyle=Set.String:S | Skin.Name:S

[QuickNote.VerDiff]
Meter=String
Text=1.0 > 1.32
MeterStyle=Set.String:S | Skin.VerDiff:S

[QuickNote.UpdateButton]
Meter=Shape
LeftMouseUpAction=[!CommandMeasure LogicalScript "runUpdate('QuickNote', '1.32')" "#JaxCore\Accessories\GlobalUpdater"][!CommandMeasure mActions "Execute 2"]
MeterStyle=Skin.UpdateButton.Shape:S

[QuickNote.UpdateIcon]
Meter=String
MeterStyle=Set.String:S | Skin.UpdateButton.Icon:S

[Variables]
Sec.H=(100+40*1)
            