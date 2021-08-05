
[WallpaperPath]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop
RegValue=Wallpaper
UpdateDivider=-1
[WallpaperRegex]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop
RegValue=Wallpaper
Substitute="\":"\\",".":"\."
OnUpdateAction=[!UpdateMeasure WallpaperCheck:M]
UpdateDivider=-1
[WallpaperCheck:M]
Measure=String
String=#cache.wallpaper#
ifMatch = ^[WallpaperRegex]$
ifMatchAction = [!Log "WallpaperChecked:match"]
ifnotmatchaction=[!Delay 200][!Log "Wallpaper changed: [WallpaperPath]"][!Setvariable Cache.Wallpaper "[WallpaperPath]"][!WriteKeyValue Variables Cache.Wallpaper "[WallpaperPath]" "#@#Vars.inc"][!UpdateMeasure MM][!CommandMeasure MM "Reload Image"][!Delay 100][!CommandMeasure mWH "Dimensions"]
DynamicVariables=1
UpdateDivider=-1


[MM]
Measure=Plugin
Plugin=MagickMeter
DynamicVariables=1
Image=File #Cache.Wallpaper# | RenderSize (#Img.W#/4),(#Img.H#/4) | Blur 70,10
ExportTo=#@#Export\Blur.png
UpdateDivider=-1
Disabled=1
Group=NUOL

[mWH]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
UpdateDivider=-1
ScriptFile=#SKINSPATH##JaxCore\@Resources\Powershell\ImgWH.ps1

[ExportWH]
Measure=Calc
DynamicVariables=1
UpdateDivider=-1
OnUpdateAction=[!WriteKeyvalue Variables Img.W #IMGW# "#@#Vars.inc"][!WriteKeyvalue Variables Img.H #IMGH# "#@#Vars.inc"][!Delay 1000][!Refresh]
Disabled=1
Group=NUOL