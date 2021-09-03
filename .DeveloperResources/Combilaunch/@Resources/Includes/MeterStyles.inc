[TextStyle]
Group=Popup
FontColor=#colorText#
FontFace=#Font#
AntiAlias=1
FontSize=9
stringstyle=bold
Container=TextMask

[TextHighlight]
Group=Popup
FontColor=#colorText#
FontFace=#Font#
stringstyle=bold
Container=TextMask

[IconStyle]
Group=Popup
X=15
Y=5r
w=40
h=40
AntiAlias=1
Container=TextMask


[HighlightStyle]
Group=Popup
SolidColor=0,0,0,1
X=13
Y=(73 + 60*([#CurrentSection]-1))
W=324
H=50
Hidden=(Clamp([#CURRENTSECTION]-([mFolderCount]+[mFileCount]+[#mPathBool]), 0,6))
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "808080"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseDoubleClickAction=[!CommandMeasure mIndex#CURRENTSECTION#Name "FollowPath"][!UpdateMeasure mPath][!UpdateMeasureGroup Children][!UpdateMeter *][!Redraw]
Container=TextMask

[InfoStyle]
X=8R
Y=10r
Text="%1"
AutoScale=1

[SelectStyle]
Group=Popup
SolidColor=0,255,0,190
FontFace=Segoe MDL2 Assets
Text=[\xF78C]
AntiAlias=1
FontColor=FFFFFE
X=337
Y=r
W=40
Padding=13,15,0,0
FontSize=15
H=35
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "0,255,0,240"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "0,255,0,190"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables "Name#Index#" [m[#CURRENTSECTION]Name] "#@#Variables\Names.inc"][!WriteKeyValue Variables "MatchAction#Index#" """["[mPath][m[#CURRENTSECTION]Name]"]""" "#@#Variables\MatchActions.inc"][!Refresh "Combilaunch\@Settings" "Actions.ini"][!DeactivateConfig]
Container=TextMask