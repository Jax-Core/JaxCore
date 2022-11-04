[Rainmeter]
Update=-1
OnRefreshAction=[]

[Variables]
@includeVars=#@#Vars.inc
CacheW=1128
CacheH=436

[p.FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=Blur
Corner=#Set.BlurCorner#
DynamicVariables=1
Border=All

[AreaFiller.Shape]
Meter=String
W=#Dimension.W#
H=#Dimension.H#
SolidColor=0,0,0,1
DynamicVariables=1
[LazyWindowPreview.Shape]
Meter=Shape
X=(2)
Y=(2)
Shape=Rectangle 0,0, (#Dimension.W#-4), (#Dimension.H#-4), #Set.WinR# | Extend Style
Style=StrokeWidth 2 | Fill Color #Set.Pri_Color#,170 | Stroke Color #Set.SubText_Color#
MouseActionCursor=0
DynamicVariables=1
