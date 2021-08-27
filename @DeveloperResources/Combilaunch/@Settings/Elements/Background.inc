[Variables]
@includevar=#@#Vars.inc
@includeCV=Variables.inc

[FG]
Measure=Plugin
Plugin=FrostedGlass
Blur=Blur

[Background]
Meter=Shape
;31,31,31 | 247, 241, 242
Shape=Rectangle 0,0,(#PanelW#),#PanelH# | StrokeWidth 0 | Fill Color #SettingColor#
;0,0,0 | 255,255,255