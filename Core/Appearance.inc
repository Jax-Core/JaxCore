[Variables]
[Header01]
Meter=String
Text=Presets
MeterStyle=Set.String:S | Set.OptionCat:S
[Option02]
Meter=String
Text=Core appearance preset

MeterStyle=Set.String:S | Set.OptionName:S
[Header03]
Meter=String
Text=Dimensions and styling
MeterStyle=Set.String:S | Set.OptionCat:S
[Option04]
Meter=String
Text=Padding size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider05]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Element corner rounding size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider06]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Window corner rounding size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider07]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text=Window border size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider08]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
Text=Text font

MeterStyle=Set.String:S | Set.OptionName:S
[Header09]
Meter=String
Text=Fill and coloring
MeterStyle=Set.String:S | Set.OptionCat:S
[Option10]
Meter=String
Text=Blur type

MeterStyle=Set.String:S | Set.OptionName:S
[Divider11]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Blur rounding size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider12]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Window background opacity

MeterStyle=Set.String:S | Set.OptionName:S
[Divider13]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Primary color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider14]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Secondary color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider15]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Tertiary color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider16]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Primary accent color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider17]
Meter=Shape
MeterStyle=Set.Div:S
[Option17]
Meter=String
Text=Secondary accent color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider18]
Meter=Shape
MeterStyle=Set.Div:S
[Option18]
Meter=String
Text=Primary text color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider19]
Meter=Shape
MeterStyle=Set.Div:S
[Option19]
Meter=String
Text=Secondary text color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider20]
Meter=Shape
MeterStyle=Set.Div:S
[Option20]
Meter=String
Text=Positive indicator color

MeterStyle=Set.String:S | Set.OptionName:S
[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!commandMeasure Func "startDrop('Style', '#CURRENTSECTION#', 'JaxCore')"]

[Icon02]
Meter=String
Text=[\xe5d4]
FontFace=Material Icons Round
FontSize=(14*[Set.S])

MeterStyle=Set.String:S | Set.Value:S
[Value02]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=#Set.Style#

MeterStyle=Set.String:S | Set.Value:S
[Set.P.Handle]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#Set.P.Handle#

MeterStyle=Set.String:S | Set.Value:S
[Set.R]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#Set.R#

MeterStyle=Set.String:S | Set.Value:S
[Set.WinR]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#Set.WinR#

MeterStyle=Set.String:S | Set.Value:S
[Set.WinB]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#Set.WinB#

MeterStyle=Set.String:S | Set.Value:S
[Set.Font]
Meter=Shape
MeterStyle=Set.Textbox:S



Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value08]
Meter=String
Text=#Set.Font#

MeterStyle=Set.String:S | Set.Value:S
[Set.Blur:]
Meter=Shape
0Act=[!WriteKeyValue Variables Set.Blur "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Set.Blur "Acrylic" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Set.Blur "Blur" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Set.Blur', 'Acrylic')]+[&Func:returnBool('Set.Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Blur:0]
Meter=String
Text=None
FontColor=[&Func:returnBool('Set.Blur', 'None', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S

[Set.Blur:1]
Meter=String
Text=Acrylic
FontColor=[&Func:returnBool('Set.Blur', 'Acrylic', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S

[Set.Blur:2]
Meter=String
Text=Standard
FontColor=[&Func:returnBool('Set.Blur', 'Blur', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Hidden=

[Set.BlurCorner:]
Meter=Shape
0Act=[!WriteKeyValue Variables Set.BlurCorner "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Set.BlurCorner "RoundSmall" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Set.BlurCorner "Round" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Set.BlurCorner', 'RoundSmall')]+[&Func:returnBool('Set.BlurCorner', 'Round')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.BlurCorner:0]
Meter=String
Text=None
FontColor=[&Func:returnBool('Set.BlurCorner', 'None', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S

[Set.BlurCorner:1]
Meter=String
Text=Small
FontColor=[&Func:returnBool('Set.BlurCorner', 'RoundSmall', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S

[Set.BlurCorner:2]
Meter=String
Text=Standard
FontColor=[&Func:returnBool('Set.BlurCorner', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Hidden=

[Set.Alpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|255


Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#Set.Alpha#

MeterStyle=Set.String:S | Set.Value:S
[Set.Pri_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Sec_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Ter_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Accent_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Accent_Color_2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Text_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option18:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.SubText_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option19:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Set.Positive_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option20:Y]-#Set.P#+(-30/2+8)*[Set.S])




;[Presets]
;Type=Header
;
;[Core appearance preset]
;Type=Button
;String=#Set.Style#
;Icon=e5d4
;Act=[!commandMeasure Func "startDrop('Style', '#CURRENTSECTION#', 'JaxCore')"]
;
;[Dimensions and styling]
;Type=Header
;
;[Padding size]
;Type=String
;Limit=Num|0|100
;Variable=Set.P.Handle
;[Element corner rounding size]
;Type=String
;Limit=Num|0|100
;Variable=Set.R
;[Window corner rounding size]
;Type=String
;Limit=Num|0|100
;Variable=Set.WinR
;[Window border size]
;Type=String
;Limit=Num|0|100
;Variable=Set.WinB
;[Text font]
;Type=String
;Variable=Set.Font
;
;[Fill and coloring]
;Type=Header
;
;[Blur type]
;Type=Switch
;Variable=Set.Blur
;Limit=3
;String=None|Acrylic|Standard
;StringSet=None|Acrylic|Blur
;[Blur rounding size]
;Type=Switch
;Variable=Set.BlurCorner
;Limit=3
;String=None|Small|Standard
;StringSet=None|RoundSmall|Round
;[Window background opacity]
;Type=String
;Variable=Set.Alpha
;Limit=Int|0|255
;[Primary color]
;Type=Color
;Variable=Set.Pri_Color
;[Secondary color]
;Type=Color
;Variable=Set.Sec_Color
;[Tertiary color]
;Type=Color
;Variable=Set.Ter_Color
;[Primary accent color]
;Type=Color
;Variable=Set.Accent_Color
;[Secondary accent color]
;Type=Color
;Variable=Set.Accent_Color_2
;[Primary text color]
;Type=Color
;Variable=Set.Text_Color
;[Secondary text color]
;Type=Color
;Variable=Set.SubText_Color
;[Positive indicator color]
;Type=Color
;Variable=Set.Positive_Color