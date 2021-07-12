#SingleInstance, Force
SendMode Input
SetWorkingDir, %A_ScriptDir%

IniRead, SaveLocation, InstallData.ini, Data, SaveLocation
IniRead, DownloadLink, InstallData.ini, Data, DownloadLink

SplashTextOn , 400, 100, Rainmeter, "Downloading skin..."
UrlDownloadToFile, %DownloadLink%, %SaveLocation%\INSTALL.rmskin
SplashTextOff
Run, INSTALL.rmskin
WinWait, Rainmeter Skin Installer
Sleep, 100
Send, {Enter}

ExitApp