[mPath]
Measure=Plugin
Plugin=FileView
Path=""
Count=6
IfMatch=^$
IfMatchAction=[!SetVariable mPathBool 0]
IfNotMatchAction=[!SetVariable mPathBool 1]

[mFolderCount]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FolderCount
Group=Children


[mFileCount]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileCount
Group=Children


[mFolderSize]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FolderSize
Group=Children

;----------------------------------------------------
; Index 1

[mIndex1Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=1
Group=Children

[mIndex1Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=1
IconPath=#@#Images\fileview1.ico
Group=Children

;----------------------------------------------------
; Index 2

[mIndex2Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=2
Group=Children

[mIndex2Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=2
IconPath=#@#Images\fileview2.ico
Group=Children

;----------------------------------------------------
; Index 3

[mIndex3Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=3
Group=Children

[mIndex3Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=3
IconPath=#@#Images\fileview3.ico
Group=Children

;----------------------------------------------------
; Index 4

[mIndex4Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=4
Group=Children

[mIndex4Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=4
IconPath=#@#Images\fileview4.ico
Group=Children

;----------------------------------------------------
; Index 5

[mIndex5Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=5
Group=Children

[mIndex5Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=5
IconPath=#@#Images\fileview5.ico
Group=Children

[mIndex6Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=6
Group=Children

[mIndex6Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=6
IconPath=#@#Images\fileview6.ico
Group=Children