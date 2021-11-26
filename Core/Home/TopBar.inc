[Top.String:S]
Y=r
StringAlign=Right
Container=
FontSize=(16*[Set.S])

[BarClip]
Meter=Shape
Shape=Rectangle 0,0, #Set.W#, (110*[Set.S]), #Set.R# | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Pri_Color#
MouseActionCursor=0
DynamicVariables=1

; ------------------------------------- e ------------------------------------ ;

[Class.Text1]
Meter=String
MeterStyle=Set.String:S
Text=JaxOriginals
X=(#Set.P#)
Y=(#Set.P#)
Container=
FontSize=(16*[Set.S])

[Class.Side5]
Meter=String
MeterStyle=Set.String:S | Top.String:S
Text=Settings
X=(#Set.W#-#Set.P#)
LeftMouseUpAction=[!WriteKeyValue "Variables" "Sec.Page" "5"][!Refresh]

[Class.Side4]
Meter=String
MeterStyle=Set.String:S | Top.String:S
X=(-31*[Set.S]-[Class.Side5:W])r
Text=Desktop
LeftMouseUpAction=[!WriteKeyValue "Variables" "Sec.Page" "4"][!Refresh]

[Class.Side3]
Meter=String
MeterStyle=Set.String:S | Top.String:S
X=(-31*[Set.S]-[Class.Side4:W])r
Text=Modules
LeftMouseUpAction=[!WriteKeyValue "Variables" "Sec.Page" "3"][!Refresh]

; [Class.Side2]
; Meter=String
; MeterStyle=Set.String:S | Top.String:S
; X=(-31*[Set.S]-[Class.Side3:W])r
; Text=News
; LeftMouseUpAction=[!WriteKeyValue "Variables" "Sec.Page" "2"][!Refresh]

[Class.Side1]
Meter=String
MeterStyle=Set.String:S | Top.String:S
X=(-31*[Set.S]-[Class.Side3:W])r
Text=Home
LeftMouseUpAction=[!WriteKeyValue "Variables" "Sec.Page" "1"][!Refresh]