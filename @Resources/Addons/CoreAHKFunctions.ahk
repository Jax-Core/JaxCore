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