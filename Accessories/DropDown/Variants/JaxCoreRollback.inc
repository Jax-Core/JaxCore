[Variables]
Skin.Name=ModularVisualizer
Sec.W=(175*#Sec.S#)
[v1.01]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.01/#Skin.Name#_v1.01.rmskin"][!SetVariable DownloadName "#Skin.Name#1.01"][!CommandMeasure CoreInstallHandler "Install"]
[Div:1.01]
Meter=Shape
MeterStyle=Div:S
[v1.0]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.0/#Skin.Name#_v1.0.rmskin"][!SetVariable DownloadName "#Skin.Name#1.0"][!CommandMeasure CoreInstallHandler "Install"]
[Div:1.0]
Meter=Shape
MeterStyle=Div:S
[CoreInstallHandler]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
ExecutionPolicy=Unrestricted