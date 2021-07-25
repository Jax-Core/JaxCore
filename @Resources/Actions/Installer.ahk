#SingleInstance, Force
SendMode Input
SetWorkingDir, %A_ScriptDir%

IniRead, SaveLocation, InstallData.ini, Data, SaveLocation
IniRead, DownloadLink, InstallData.ini, Data, DownloadLink

SplashTextOn , 400, 100, Rainmeter, "Downloading skin..."
UrlDownloadToFile, %DownloadLink%, INSTALL.rmskin
SplashTextOff
Run, INSTALL.rmskin
Run, %comspec% /c del "%A_ScriptFullPath%\..",,Hide ;works on both compiled and non compiled
ExitApp
ExitApp