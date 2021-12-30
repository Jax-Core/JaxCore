[Variables]
Skin.Name=ModularClocks
Sec.W=(175*#Sec.S#)
[v2.11]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v2.11/#Skin.Name#_v2.11.rmskin"][!SetVariable DownloadName "#Skin.Name#2.11"][!CommandMeasure Installer "Install"]
[Div:2.11]
Meter=Shape
MeterStyle=Div:S
[v2.1]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v2.1/#Skin.Name#_v2.1.rmskin"][!SetVariable DownloadName "#Skin.Name#2.1"][!CommandMeasure Installer "Install"]
[Div:2.1]
Meter=Shape
MeterStyle=Div:S
[v2.0]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v2.0/#Skin.Name#_v2.0.rmskin"][!SetVariable DownloadName "#Skin.Name#2.0"][!CommandMeasure Installer "Install"]
[Div:2.0]
Meter=Shape
MeterStyle=Div:S
[v1.6]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.6/#Skin.Name#_v1.6.rmskin"][!SetVariable DownloadName "#Skin.Name#1.6"][!CommandMeasure Installer "Install"]
[Div:1.6]
Meter=Shape
MeterStyle=Div:S
[v1.5]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.5/#Skin.Name#_v1.5.rmskin"][!SetVariable DownloadName "#Skin.Name#1.5"][!CommandMeasure Installer "Install"]
[Div:1.5]
Meter=Shape
MeterStyle=Div:S
[v1.4]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.4/#Skin.Name#_v1.4.rmskin"][!SetVariable DownloadName "#Skin.Name#1.4"][!CommandMeasure Installer "Install"]
[Div:1.4]
Meter=Shape
MeterStyle=Div:S
[v1.3]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.3/#Skin.Name#_v1.3.rmskin"][!SetVariable DownloadName "#Skin.Name#1.3"][!CommandMeasure Installer "Install"]
[Div:1.3]
Meter=Shape
MeterStyle=Div:S
[v1.2]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.2/#Skin.Name#_v1.2.rmskin"][!SetVariable DownloadName "#Skin.Name#1.2"][!CommandMeasure Installer "Install"]
[Div:1.2]
Meter=Shape
MeterStyle=Div:S
[v1.1]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.1/#Skin.Name#_v1.1.rmskin"][!SetVariable DownloadName "#Skin.Name#1.1"][!CommandMeasure Installer "Install"]
[Div:1.1]
Meter=Shape
MeterStyle=Div:S
[v1.0]
Meter=String
MeterStyle=String:S
LeftMouseUpAction=[!SetVariable DownloadLink "https://github.com/Jax-Core/#Skin.Name#/releases/download/v1.0/#Skin.Name#_v1.0.rmskin"][!SetVariable DownloadName "#Skin.Name#1.0"][!CommandMeasure Installer "Install"]
[Div:1.0]
Meter=Shape
MeterStyle=Div:S
[Installer]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Installer.ps1
