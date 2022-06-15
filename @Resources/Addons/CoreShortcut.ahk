#SingleInstance, force
#NoTrayIcon
DetectHiddenWindows, On
SetWinDelay, 0

; 1 = Save location
; 2 = Target
; 3 = Param
; 4 = Icon

FileCreateShortcut, %2%, %1%, , %3%, Launch JaxCore, %4%
ExitApp