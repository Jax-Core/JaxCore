; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
TweenNode1=0

; [MeasureOnLoad]
; Measure=Calc
; Formula=Counter
; IfEqualValue=1
; IfEqualAction=[!EnableMeasureGroup BackgroundMeasures]
; UpdateDivider=-1

; -------------------------------- News and page update check -------------------------------- ;

[NewsParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/CoreWebResources.inc
RegExp=(?s).*NewsID=(\d*).*Page2ID=(\d*).*Page3ID=(\d*)$
Group=BackgroundMeasures
Disabled=(0)
FinishAction=[!CommandMeasure LogicalScript "checkNews()"]

[mNewsID]
Measure=WebParser
URL=[NewsParser]
Group=BackgroundMeasures
Disabled=(0)
StringIndex=1

[mPage2ID]
Measure=WebParser
URL=[NewsParser]
Group=BackgroundMeasures
Disabled=(0)
StringIndex=2

[mPage3ID]
Measure=WebParser
URL=[NewsParser]
Group=BackgroundMeasures
Disabled=(0)
StringIndex=3

[ParseNews]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/Accessories/Popup/Variants/CoreNews.inc
CodePage=1200
RegExp=(?siU).*
Debug=2
Debug2File=#ROOTCONFIGPATH#Accessories\Popup\Variants\CoreNews.inc
DynamicVariables=1
Disabled=1
Group=ParseNews
FinishAction=[!Delay 1000][!commandMeasure Func "startPopup('CoreNews', 'Left')"]

[ParsePage2]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/CoreShell/Home/Page2.inc
CodePage=1200
RegExp=(?siU).*
Debug=2
Debug2File=#ROOTCONFIGPATH#CoreShell/Home/Page2.inc
DynamicVariables=1
Disabled=1

[ParsePage3]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/CoreShell/Home/Page3.inc
CodePage=1200
RegExp=(?siU).*
Debug=2
Debug2File=#ROOTCONFIGPATH#CoreShell/Home/Page3.inc
DynamicVariables=1
Disabled=1

; ------------------------------- Version check ------------------------------ ;

[WebParser]
Measure=WebParser
URL=https://raw.githubusercontent.com/Jax-Core/JaxCore/main/%40Resources/Version.inc
RegExp==(.*)$
Group=BackgroundMeasures
Disabled=(0)
FinishAction=[!CommandMeasure LogicalScript "check()"]
CodePage=1200

[mVer]
Measure=WebParser
URL=[WebParser]
Group=BackgroundMeasures
Disabled=(0)
StringIndex=1
CodePage=1200

[LogicalScript]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Accessories\UpdatePrompt\Logic.lua

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[DefaultStartActions]
ActionList2=Repeat Anim,2,80
Custom1=[!CommandMeasure DefaultStartActions "Execute 2"]
Anim=[!SetVariable TweenNode1 "(#TweenNode1#+0.0125)"][!UpdateMeterGroup Anim][!UpdateMeasure #CURRENTSECTION#][!Redraw]
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Loading.Image]
Meter=Image
X=([BC:W]/2-128/2*[SEt.S])
Y=([BC:H]/2-128/2*[SEt.S])
W=(128*[Set.S])
H=(128*[Set.S])
DynamicVariables=1
Container=BC
Group=Anim
TransformationMatrix=(Cos(Rad(#TweenNode1#*360)));(-Sin(Rad(#TweenNode1#*360)));(Sin(Rad(#TweenNode1#*360)));(Cos(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad(#TweenNode1#*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad(#TweenNode1#*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad(#TweenNode1#*360)))
ImageName=#@#Images\CoreAssets\LogoIcon.png