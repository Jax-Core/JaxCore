[1]
Meter=Image
Y=73
MeterStyle=HighlightStyle

[Index1]
Meter=String
MeterStyle=SelectStyle
Hidden=0

[Index1Icon]
Meter=Image
MeasureName=mIndex1Icon
y=80
MeterStyle=IconStyle

[Index1Info]
Meter=String
MeasureName=mIndex1Name
MeterStyle=TextStyle | InfoStyle
w=300
clipstring=2

[2]
Meter=Image
MeterStyle=HighlightStyle

[Index2]
Meter=String
MeterStyle=SelectStyle
Hidden=(Clamp(2-([mFolderCount]+[mFileCount]+[#mPathBool]), 0,6))

[Index2Icon]
Meter=Image
MeasureName=mIndex2Icon
MeterStyle=IconStyle

[Index2Info]
Meter=String
MeasureName=mIndex2Name
MeterStyle=TextStyle | InfoStyle
w=300
clipstring=2

[3]
Meter=Image
MeterStyle=HighlightStyle

[Index3]
Meter=String
MeterStyle=SelectStyle
Hidden=(Clamp(3-([mFolderCount]+[mFileCount]+[#mPathBool]), 0,6))

[Index3Icon]
Meter=Image
MeasureName=mIndex3Icon
MeterStyle=IconStyle

[Index3Info]
Meter=String
MeasureName=mIndex3Name
MeterStyle=TextStyle | InfoStyle
w=300
clipstring=2

[4]
Meter=Image
MeterStyle=HighlightStyle

[Index4]
Meter=String
MeterStyle=SelectStyle
Hidden=(Clamp(4-([mFolderCount]+[mFileCount]+[#mPathBool]), 0,6))

[Index4Icon]
Meter=Image
MeasureName=mIndex4Icon
MeterStyle=IconStyle

[Index4Info]
Meter=String
MeasureName=mIndex4Name
MeterStyle=TextStyle | InfoStyle
w=300
clipstring=2

[5]
Meter=Image
MeterStyle=HighlightStyle

[Index5]
Meter=String
MeterStyle=SelectStyle
Hidden=(Clamp(5-([mFolderCount]+[mFileCount]+[#mPathBool]), 0,6))

[Index5Icon]
Meter=Image
MeasureName=mIndex5Icon
MeterStyle=IconStyle

[Index5Info]
Meter=String
MeasureName=mIndex5Name
MeterStyle=TextStyle | InfoStyle
w=300
clipstring=2

[6]
Meter=Image
MeterStyle=HighlightStyle

[Index6]
Meter=String
MeterStyle=SelectStyle
Hidden=(Clamp(6-([mFolderCount]+[mFileCount]+[#mPathBool]), 0,6))

[Index6Icon]
Meter=Image
MeasureName=mIndex6Icon
MeterStyle=IconStyle

[Index6Info]
Meter=String
MeasureName=mIndex6Name
MeterStyle=TextStyle | InfoStyle
w=300
clipstring=2