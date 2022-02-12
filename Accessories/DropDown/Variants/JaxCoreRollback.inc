[Variables]
Skin.Name=YourMixer
Sec.W=(175*#Sec.S#)
[v1.31]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.31/#Skin.Name#_v1.31.rmskin"][!SetVariable DownloadName "#Skin.Name#1.31"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure Installer "Install"]
[Div:1.31]
Meter=Shape
MeterStyle=Div:S
[v1.21]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.21/#Skin.Name#_v1.21.rmskin"][!SetVariable DownloadName "#Skin.Name#1.21"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure Installer "Install"]
[Div:1.21]
Meter=Shape
MeterStyle=Div:S
[v1.2]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.2/#Skin.Name#_v1.2.rmskin"][!SetVariable DownloadName "#Skin.Name#1.2"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure Installer "Install"]
[Div:1.2]
Meter=Shape
MeterStyle=Div:S
[v1.1]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.1/#Skin.Name#_v1.1.rmskin"][!SetVariable DownloadName "#Skin.Name#1.1"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure Installer "Install"]
[Div:1.1]
Meter=Shape
MeterStyle=Div:S
[v1.0]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.0/#Skin.Name#_v1.0.rmskin"][!SetVariable DownloadName "#Skin.Name#1.0"][!SetVariable DownloadConfig "#Skin.Name#"][!CommandMeasure Installer "Install"]
[Div:1.0]
Meter=Shape
MeterStyle=Div:S
[Installer]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
