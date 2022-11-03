#SingleInstance, force
#NoTrayIcon
DetectHiddenWindows, On
SetWinDelay, 0

Goto, %1%

Setup_GameMode_FullScreenToggleOn:
Sleep, 50
WinWait, Manage Rainmeter
Control, Check, , Button2, Manage Rainmeter
WinClose, Manage Rainmeter
; MsgBox, clicked
; Sleep, 50
ExitApp

Setup_GameMode_FullScreenToggleOff:
Sleep, 50
WinWait, Manage Rainmeter
Control, Uncheck, , Button2, Manage Rainmeter
WinClose, Manage Rainmeter
; MsgBox, clicked
; Sleep, 50
ExitApp

Shortcut_Regular:
; 2 = Save location
; 3 = Target
; 4 = Param
; 5 = Icon
FileCreateShortcut, %3%, %2%, , %4%, Launch JaxCore, %5%
ExitApp

Shortcut_NoParam:
; 2 = Save location
; 3 = Target
FileCreateShortcut, %3%, %2%
ExitApp