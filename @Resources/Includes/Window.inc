[Variables]
; --------------------------- Customizing variables -------------------------- ;
MinWindowW=500
MinWindowH=375
MaxWindowW=1920
MaxWindowH=1080
ScaleWindowW=1000
; ScaleWindowH=740
; ---------------------------------------------------------------------------- ;
;                             CacheWindowVariables                             ;
; ---------------------------------------------------------------------------- ;
WindowPosX=396
WindowPosY=89
; ---------------------------- Important variables --------------------------- ;
WindowMaximized=0
WindowDragMarginSize=6


; ---------------------------------------------------------------------------- ;
;                                   Measures                                   ;
; ---------------------------------------------------------------------------- ;

[WindowHandler]
Measure=Script
ScriptFile=#@#Lua\WindowHandler.lua
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                 Drag margins                                 ;
; ---------------------------------------------------------------------------- ;

[DragMarginStyle]
ShapeStyle = StrokeWidth 0 | Fill Color 0,0,0,1
ShapeStyle2 = StrokeWidth 0 | Fill Color 0,0,0,1
LeftMouseDownAction=[!CommandMeasure WindowHandler ResizeWindow('#CurrentSection#',$MouseX$,$MouseY$)][!EnableMeasure MousePosition][!CommandMeasure MousePosition "Start"]
; LeftMouseUpAction=
; MouseOverAction=
MouseActionCursor=1
DynamicVariables=1
Group = Window | WindowDragMargin

[DragMarginTop]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0, 0, #Set.W#, #WindowDragMarginSize# | Extend ShapeStyle
MeterStyle = DragMarginStyle
MouseActionCursorName=topbottom.cur

[DragMarginLeft]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0, 0, #WindowDragMarginSize#, #Set.H# | Extend ShapeStyle
MeterStyle = DragMarginStyle
MouseActionCursorName=leftright.cur

[DragMarginBottom]
Meter=Shape
X=0
Y=(#Set.H#- #WindowDragMarginSize#)
Shape=Rectangle 0, 0, #Set.W#, #WindowDragMarginSize# | Extend ShapeStyle
MeterStyle = DragMarginStyle
MouseActionCursorName=topbottom.cur

[DragMarginRight]
Meter=Shape
X=(#Set.W# - #WindowDragMarginSize#)
Shape=Rectangle 0, 0, #WindowDragMarginSize#, #Set.H# | Extend ShapeStyle
MeterStyle = DragMarginStyle
MouseActionCursorName=leftright.cur

[DragMarginTopLeft]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0, 0, #WindowDragMarginSize#, #WindowDragMarginSize# | Extend ShapeStyle2
MeterStyle = DragMarginStyle
MouseActionCursorName=topleftbottomright.cur

[DragMarginBottomLeft]
Meter=Shape
X=0
Y=(#Set.H# - #WindowDragMarginSize#)
Shape=Rectangle 0, 0, #WindowDragMarginSize#, #WindowDragMarginSize# | Extend ShapeStyle2
MeterStyle = DragMarginStyle
MouseActionCursorName=toprightbottomleft.cur

[DragMarginTopRight]
Meter=Shape
X=(#Set.W# - #WindowDragMarginSize#)
Y=0
Shape=Rectangle 0, 0, #WindowDragMarginSize#, #WindowDragMarginSize# | Extend ShapeStyle2
MeterStyle = DragMarginStyle
MouseActionCursorName=toprightbottomleft.cur

[DragMarginBottomRight]
Meter=Shape
X=(#Set.W#- #WindowDragMarginSize#)
Y=(#Set.H#- #WindowDragMarginSize#)
Shape=Rectangle 0, 0, #WindowDragMarginSize#, #WindowDragMarginSize# | Extend ShapeStyle2
MeterStyle = DragMarginStyle
MouseActionCursorName=topleftbottomright.cur
