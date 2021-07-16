[mL]
Measure=String
OnUpdateAction=[!CommandMeasure mTween "Start(0)"][!Delay 500][!CommandMeasure mTween "Start(1)"][!Delay 1500][!HideMeter MeterRotate][!SetOption MeterRotate Group ""][!ShowMeter Logo][!SetOption Logo Group "Tweenable"][!UpdateMeter Logo]


[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 100 | 2000
Tween1=Single | Variable | TweenNode2 | 0 | 100 | 1000
Tween2=Single | Variable | TweenNode3 | 0 | 100 | 1000
Optional0=Easing InOutQuart
Optional1=Easing InOutQuart
Optional2=Easing OutQuart
UpdateDivider=1

[MeasureRotate]
Measure=Calc
Formula=(#TweenNode1#/100*360 % 360)
MaxValue=360
DynamicVariables=1
Group=Tweenable

[MeterRotate]
Meter=Rotator
MeasureName=MeasureRotate
ImageName=#@#Images\Logo256.png
OffsetX=(256 / 2)
OffsetY=(256 / 2)
X=(#Sec.W#/2-256/2)
Y=(#Sec.H#/2-256/2-#TweenNode2#/100*80)
W=(256)
H=(256)
DynamicVariables=1
ImageAlpha=(#TweenNode1#/100*255)
Group=Tweenable

[SectingsText]
Meter=String
MeterStyle=Sec.String:S
Text=JaxCore#CRLF#Core ver #Core.Ver##CRLF#Click the logo to continue
X=(#Sec.W#/2)
Y=(#Sec.H#/2+256/2-#TweenNode2#/100*80+60)
StringAlign=CenterTop
FontSize=30
FontWeight=500
InlinePattern=^.*(#CRLF#.*)#CRLF#.*$
InlineSetting=Size | 15
InlinePattern2=^.*(#CRLF#.*)#CRLF#.*$
InlineSetting2=Color | 255,255,255,(#TweenNode1#/100*150)
InlinePattern3=^.*(#CRLF#.*#CRLF#.*)$
InlineSetting3=Weight | 400
InlinePattern4=^(.*)#CRLF#.*#CRLF#.*$
InlineSetting4=GradientColor | 180 | 204, 31, 20, (#TweenNode1#/100*255) ; 0.0 | 255, 230, 55, (#TweenNode1#/100*255) ; 1.0
InlinePattern5=^.*#CRLF#.*(#CRLF#.*)$
InlineSetting5=Size | 10
InlinePattern6=^.*#CRLF#.*(#CRLF#.*)$
InlineSetting6=Color | 255,255,255,(#TweenNode1#/100*50)
DynamicVariables=1
Group=Tweenable

[Logo]
Meter=Image
ImageName=#@#Images\LogoBig.png
X=(#Sec.W#/2-(256+256*#TweenNode3#/50)/2)
Y=(#Sec.H#/2-(256+256*#TweenNode3#/50)/2-80)
W=(256+256*#TweenNode3#/50)
H=(256+256*#TweenNode3#/50)
DynamicVariables=1
Hidden=1
ImageAlpha=((100 - #TweenNode3#)/100*255)
Leftmouseupaction=[!CommandMeasure mTween "Reverse(0)"][!CommandMeasure mTween "Start(2)"][!Delay 1500][!WriteKeyValue Variables Page 2][!Refresh]