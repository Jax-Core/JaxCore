[ArrowLeft]
Meter=Shape
X=#Sec.P#
Y=(#Sec.H#/2)
W=#Sec.P#
H=#Sec.P#
Shape=Path This | StrokeWidth 2 | StrokeColor 255,255,255,120 | Scale -1,1
This=0,-10 | LineTo 10,0 | LineTo 0,10
SolidColor=0,0,0,1
LeftMouseupAction=[!WriteKeyValue Variables Page ([#Page]-1)][!CommandMeasure mTween "Reverse(1)"][!CommandMeasure mTween "Reverse(2)"][!Delay 1000][!Refresh]

[ArrowRight]
Meter=Shape
X=(#Sec.W#-#Sec.P#)
Y=(#Sec.H#/2)
W=#Sec.P#
H=#Sec.P#
Shape=Path This | StrokeWidth 2 | StrokeColor 255,255,255,120 | Scale 1,1
This=0,-10 | LineTo 10,0 | LineTo 0,10
SolidColor=0,0,0,1
LeftMouseupAction=[!WriteKeyValue Variables Page ([#Page]+1)][!CommandMeasure mTween "Reverse(1)"][!CommandMeasure mTween "Reverse(2)"][!Delay 1000][!Refresh]

;CONTENT+=============================================================================
;CONTENT+=============================================================================

[mL]
Measure=String
OnUpdateAction=[!Delay 100][!CommandMeasure mTween "Start(0)"][!Delay 1000][!CommandMeasure mTween "Start(1)"][!Delay 1000][!CommandMeasure mTween "Start(2)"]


[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 100 | 1000
Tween1=Single | Variable | TweenNode2 | 0 | 100 | 1000
Tween2=Single | Variable | TweenNode3 | 0 | 100 | 1000
; Tween3=Single | Variable | TweenNode4 | 0 | 100 | 1000
Optional0=Easing InOutQuart
Optional1=Easing InOutExpo
Optional2=Easing InOutExpo
; Optional3=Easing InOutExpo
UpdateDivider=1

[Title]
Meter=String
MeterStyle=Sec.String:S
Text=What's New
FontFace=Roboto Thin
StringAlign=CenterTop
X=(#Sec.W#/2)
Y=#Sec.P#
Group=Tweenable
DynamicVariables=1
FontColor=150,150,150,255

[BackgroundShapes]
Meter=Shape
X=(#Sec.W#/2-260/2)
Y=(#sec.H#/2-260/2)
Shape=Rectangle 0,0,260,260 | Rotate 45 | Extend Style | Scale (#TweenNode2#/100),(#TweenNode2#/100)
Style=StrokeWidth 0  | FIll Color 19,19,19
Group=Tweenable
DynamicVariables=1

[Icon]
Meter=Image
X=(260/2-100/2)r
Y=((#TweenNode2#/100)*15)r
ImageAlpha=(#TweenNode2#/100*255)
Group=Tweenable
DynamicVariables=1
ImageName=#@#Icons\New\Update.png

[Text]
Meter=String
MeterStyle=Sec.String:S
X=(100/2)r
Y=R
FontFace=Roboto Medium
StringAlign=CenterTop
Text=Updates checker
FontColor=255,255,255,(#TweenNode2#/100*255)
Group=Tweenable
DynamicVariables=1
[Description]
Meter=String
MeterStyle=Sec.String:S
X=r
Y=(#TweenNode3#/100*(-10)+10)R
W=230
ClipString=2
FontFace=Roboto Light
FontSize=10
StringAlign=CenterTop
Text=Automatically checks and notifies you when there is an update. You can turn this off in the core settings
FontColor=245,245,245,(#TweenNode3#/100*230)
Group=Tweenable
DynamicVariables=1