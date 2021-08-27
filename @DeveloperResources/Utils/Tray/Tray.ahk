#SingleInstance Ignore
#NoTrayIcon
ProcessSetPriority("Realtime")
DetectHiddenWindows 1
SetControlDelay -1
SetWinDelay 0
ControlClick "Button2", "ahk_class Shell_TrayWnd",,,, "NA"

CoordMode "Mouse", "Screen"
MouseGetPos MouseX, MouseY

if WinWait("ahk_class NotifyIconOverflowWindow",, 3) {
	Sleep 100
	WinActivate("ahk_class NotifyIconOverflowWindow")
	While WinActive("ahk_class NotifyIconOverflowWindow")
	{
		WinGetPos x,y, WidthOfTray, HeightOfTray, "ahk_class NotifyIconOverflowWindow"
		TrueX := MouseX - WidthOfTray / 2
		TrueY := MouseY - HeightOfTray / 2
		WinMove TrueX, TrueY,,, "ahk_class NotifyIconOverflowWindow"
	}
	;WinHide("ahk_class NotifyIconOverflowWindow")
	Return
}
else
	Return
ExitApp
