[Variables]
Skin.Name=ModularVisualizer
Sec.W=(175*#Sec.S#)
[v1.04]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.04/#Skin.Name#_v1.04.rmskin"][!SetVariable DownloadName "#Skin.Name#1.04"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure CoreInstallHandler "InitInstall"]
[Div:1.04]
Meter=Shape
MeterStyle=Div:S
[v1.03]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.03/#Skin.Name#_v1.03.rmskin"][!SetVariable DownloadName "#Skin.Name#1.03"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure CoreInstallHandler "InitInstall"]
[Div:1.03]
Meter=Shape
MeterStyle=Div:S
[v1.02]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.02/#Skin.Name#_v1.02.rmskin"][!SetVariable DownloadName "#Skin.Name#1.02"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure CoreInstallHandler "InitInstall"]
[Div:1.02]
Meter=Shape
MeterStyle=Div:S
[v1.01]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.01/#Skin.Name#_v1.01.rmskin"][!SetVariable DownloadName "#Skin.Name#1.01"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure CoreInstallHandler "InitInstall"]
[Div:1.01]
Meter=Shape
MeterStyle=Div:S
[v1.0]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.0/#Skin.Name#_v1.0.rmskin"][!SetVariable DownloadName "#Skin.Name#1.0"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure CoreInstallHandler "InitInstall"]
[Div:1.0]
Meter=Shape
MeterStyle=Div:S
[CoreInstallHandler]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
