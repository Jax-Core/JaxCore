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
WindowPosX=390
WindowPosY=66
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

@IncludeMouse=#@#Includes\WindowDragMargins#Set.PerformanceMode#.inc
