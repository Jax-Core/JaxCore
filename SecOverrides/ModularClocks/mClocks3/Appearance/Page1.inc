[Variables]
@includeMain=#SKINSPATH##Skin.Name#\@Resources\Data\MainData.inc
@include222=#SKINSPATH##Skin.Name#\@Resources\Data\2Data.inc
@include333=#SKINSPATH##Skin.Name#\@Resources\Data\3Data.inc

[Set.OptionName:S]
X=(30*[Set.S])
Y=(30*[Set.s])R
[Set.OptionName0:S]
FontColor=#Set.Subtext_Color#
[Set.Textbox:S]
X=(#Sec.L#-(120*[Set.S]))
[Set.Fontbox:S]
X=(#Sec.L#-(120*[Set.S]))
[Set.Button:S]
X=(#Sec.L#-(120*[Set.S]))
[Set.Bool:S]
X=(#Sec.L#-(20*[Set.S]))
[Set.Pick:S]
X=(#Sec.L#-(272*[Set.S]))
[Set.Pick3:S]
X=(#Sec.L#-(272*[Set.S]))
[Set.ColorPacity:S]
X=(#Sec.L#-(120*[Set.S]))


[SpecialDiv:S]
X=(30*[Set.S])
y=(30*[Set.S])R
DynamicVariables=1
Container=ContentContainer
Shape=Line 0,(7.5*[Set.S]),#Sec.L#,(7.5*[Set.S]) | Extend Common
Shape2=Line 0,0,0,(15*[Set.S]) | Extend Common
Shape3=Line #Sec.L#,0,#Sec.L#,(15*[Set.S]) | Extend Common
Common=StrokeWidth 2 | Fill Color #Set.Pri_Color#,0 | Stroke Color #Set.Ter_Color#
[Set.SpecialCat:S]
Y=(7.5*[Set.S])r
X=(#Sec.L#/2)r
StringAlign=CenterCenter
FontSize=(8*[Set.S])
SolidColor=#Set.Pri_Color#
Padding=30,5,30,5
FontCOlor=#Set.Subtext_Color#
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Div:Seqweqwe]
Meter=Shape
MeterStyle=SpecialDiv:S
[DivText:qweq]
Meter=String
Text=Global options
MeterStyle=Set.String:S | Set.SpecialCat:S

[Option01]
Meter=String
Text=Master scale
MeterStyle=Set.String:S | Set.OptionName:S
[Option02]
Meter=String
Text=Time format
MeterStyle=Set.String:S | Set.OptionName:S

[Div:Seqweqwasde]
Meter=Shape
MeterStyle=SpecialDiv:S
[DivText:qwezq]
Meter=String
Text=Super options
MeterStyle=Set.String:S | Set.SpecialCat:S

[Option11]
Meter=String
Text=Align
MeterStyle=Set.String:S | Set.OptionName:S
[Option12]
Meter=String
Text=Rows
MeterStyle=Set.String:S | Set.OptionName:S
; [Option13]
; Meter=String
; Text=Filling
; MeterStyle=Set.String:S | Set.OptionName:S
; [Option14]
; Meter=String
; Text=Special images / shapes
; MeterStyle=Set.String:S | Set.OptionName:S
[Option15]
Meter=String
Text=Generic layout
MeterStyle=Set.String:S | Set.OptionName:S
; [Option16]
; Meter=String
; Text=Values
; MeterStyle=Set.String:S | Set.OptionName:S
[Option17]
Meter=String
Text=Subscript item
MeterStyle=Set.String:S | Set.OptionName:S

[Div:Seqweqwzcxzasde]
Meter=Shape
MeterStyle=SpecialDiv:S
[DivText:qwsawaezq]
Meter=String
Text=Personalization options
MeterStyle=Set.String:S | Set.SpecialCat:S

; ------------------------------- Fill settings ------------------------------ ;

; @includeFillOptions=CogsOptions\Fill#Fill#.inc

[TipBox]
MEter=Shape
X=(30*[Set.S])
Y=(#Set.H#-#Set.P#*2-100*[Set.S])
Shape=Rectangle 0,0,#Sec.L#,(100*[SEt.S]),#Set.R# | StrokeWidth 0 | Fill Color #Set.Ter_Color#
DynamicVariables=1
Container=ContentContainer

[TipIcon]
Meter=Image
X=(#set.P#/2)r
Y=(#Set.P#/2)r
W=(100*[Set.S]-#Set.P#)
H=[#CURRENTSECTION#:W]
ImageName=#@#Images\Logo.png
DynamicVariables=1
Container=ContentContainer

[TipText]
Meter=String
Text=Further customization#CRLF#You can further customize the clock by clicking on elements of the clock. This only applies when you are on this panel.
X=(#Set.P#/2)R
Y=([TipIcon:W]/2-2*[Set.S])r
StringAlign=LeftCenter
Container=ContentContainer
FontSize=(8*[Set.S])
ClipString=2
W=(#Sec.L#-#Set.P#*1.5-[TipIcon:W])
Inlinepattern=.*#CRLF#
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 2.0
Inlinepattern2=.*#CRLF#
InlineSetting2=Weight | 600
Inlinepattern3=.*#CRLF#
InlineSetting3=Size | (16*[Set.S])
MeterStyle=SEt.String:S

; ------------------------------ Common settings ----------------------------- ;

; [Option003]
; Meter=String
; Text=Clock font
; MeterStyle=Set.String:S | Set.OptionName:S
; [Option001]
; Meter=String
; Text=Clock seperator
; MeterStyle=Set.String:S | Set.OptionName:S
; [Option002]
; Meter=String
; Text=Subscript seperator
; MeterStyle=Set.String:S | Set.OptionName:S

; ------------------------------- Date settings ------------------------------ ;

; @includeDateOptions=CogsOptions\Date#Date#.inc
; @includeDatePositionOptions=CogsOptions\DatePos#Date#.inc

; ---------------------------------------------------------------------------- ;
;                                     INput                                    ;
; ---------------------------------------------------------------------------- ;

; ----------------------------------- Super ---------------------------------- ;

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[2412:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('2412', 'H')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables 2412 "I" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables 2412 "H" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[2412:0]
Meter=String
Text=12-Hour
FontColor=([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[2412:1]
Meter=String
Text=24-hour
FontColor=([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S


[Align:]
Meter=Shape
0Act=[!WriteKeyValue Variables Align "Left" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Align "Center" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Align "Right" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Align', 'Center')]+[&Func:returnBool('Align', 'Right')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Align:0]
Meter=String
Text=Left
FontColor=([&Func:returnBool('Align', 'Left')] = 1 ? 0 : 255),([&Func:returnBool('Align', 'Left')] = 1 ? 0 : 255),([&Func:returnBool('Align', 'Left')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Align:1]
Meter=String
Text=Center
FontColor=([&Func:returnBool('Align', 'Center')] = 1 ? 0 : 255),([&Func:returnBool('Align', 'Center')] = 1 ? 0 : 255),([&Func:returnBool('Align', 'Center')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Align:2]
Meter=String
Text=Right
FontColor=([&Func:returnBool('Align', 'Right')] = 1 ? 0 : 255),([&Func:returnBool('Align', 'Right')] = 1 ? 0 : 255),([&Func:returnBool('Align', 'Right')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S


[Rows:]
Meter=Shape
0Act=[!WriteKeyValue Variables Rows "Single" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Rows "Double" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Rows "Triple" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Rows', 'Double')]+[&Func:returnBool('Rows', 'Triple')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Rows:0]
Meter=String
Text=Single
FontColor=([&Func:returnBool('Rows', 'Single')] = 1 ? 0 : 255),([&Func:returnBool('Rows', 'Single')] = 1 ? 0 : 255),([&Func:returnBool('Rows', 'Single')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Rows:1]
Meter=String
Text=Double
FontColor=([&Func:returnBool('Rows', 'Double')] = 1 ? 0 : 255),([&Func:returnBool('Rows', 'Double')] = 1 ? 0 : 255),([&Func:returnBool('Rows', 'Double')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Rows:2]
Meter=String
Text=Triple
FontColor=([&Func:returnBool('Rows', 'Triple')] = 1 ? 0 : 255),([&Func:returnBool('Rows', 'Triple')] = 1 ? 0 : 255),([&Func:returnBool('Rows', 'Triple')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S


; [Button13]
; Meter=Shape
; MeterStyle=Set.Button:S
; Act=[!commandMeasure Func "startDrop('Filling', '#CURRENTSECTION#')"]
; Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value13]
; Meter=String
; Text=#Fill#
; MeterStyle=Set.String:S | Set.Value:S

; [Button14]
; Meter=Shape
; MeterStyle=Set.Button:S
; Act=[!commandMeasure Func "startDrop('Image', '#CURRENTSECTION#')"]
; Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value14]
; Meter=String
; Text=#Image#
; MeterStyle=Set.String:S | Set.Value:S


[Layout:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('Layout', 'Double')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables Layout "Single" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Layout "Double" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Layout:0]
Meter=String
Text=Single row
FontColor=([&Func:returnBool('Layout', 'Double')] = 0 ? 0 : 255),([&Func:returnBool('Layout', 'Double')] = 0 ? 0 : 255),([&Func:returnBool('Layout', 'Double')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[Layout:1]
Meter=String
Text=Stacked row
FontColor=([&Func:returnBool('Layout', 'Double')] = 1 ? 0 : 255),([&Func:returnBool('Layout', 'Double')] = 1 ? 0 : 255),([&Func:returnBool('Layout', 'Double')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S


; [Val:]
; Meter=Shape
; Shape2=Rectangle ([&Func:returnBool('Val', 'Text')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
; 0Act=[!WriteKeyValue Variables Val "Time" "#Sec.SaveLocation#"]
; 1Act=[!WriteKeyValue Variables Val "Text" "#Sec.SaveLocation#"]
; MeterStyle=Set.Pick:S
; Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Val:0]
; Meter=String
; Text=Numeric
; FontColor=([&Func:returnBool('Val', 'Text')] = 0 ? 0 : 255),([&Func:returnBool('Val', 'Text')] = 0 ? 0 : 255),([&Func:returnBool('Val', 'Text')] = 0 ? 0 : 255)
; LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
; MeterStyle=Set.String:S | Set.PickOption_0:S
; [Val:1]
; Meter=String
; Text=Textual
; FontColor=([&Func:returnBool('Val', 'Text')] = 1 ? 0 : 255),([&Func:returnBool('Val', 'Text')] = 1 ? 0 : 255),([&Func:returnBool('Val', 'Text')] = 1 ? 0 : 255)
; LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
; MeterStyle=Set.String:S | Set.PickOption_1:S


[Sec:]
Meter=Shape
0Act=[!WriteKeyValue Variables Sec "0" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Sec "1" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Sec "2" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*#Sec#),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Sec:0]
Meter=String
Text=AM / PM
FontColor=(#Sec# = 0 ? 0 : 255),(#Sec# = 0 ? 0 : 255),(#Sec# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Sec:1]
Meter=String
Text=Seconds
FontColor=(#Sec# = 1 ? 0 : 255),(#Sec# = 1 ? 0 : 255),(#Sec# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Sec:2]
Meter=String
Text=Empty
FontColor=(#Sec# = 2 ? 0 : 255),(#Sec# = 2 ? 0 : 255),(#Sec# = 2 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S







; ---------------------------------- Common ---------------------------------- ;

; [Seperator]
; Meter=Shape
; MeterStyle=Set.Textbox:S
; Y=([Option001:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value001]
; Meter=String
; Text=#Seperator#
; MeterStyle=Set.String:S | Set.Value:S

; [Seperator2]
; Meter=Shape
; MeterStyle=Set.Textbox:S
; Y=([Option002:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value002]
; Meter=String
; Text=#Seperator2#
; MeterStyle=Set.String:S | Set.Value:S


; [FontFace]
; Meter=Shape
; MeterStyle=Set.FontBox:S
; Act=[!commandMeasure Func "startSide('Font', '#CURRENTSECTION#')"]
; Y=([Option003:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value003]
; Meter=String
; Text=#FontFace#
; MeterStyle=Set.String:S | Set.Value:S