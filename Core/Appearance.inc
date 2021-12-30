; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[Behavior]
Meter=String
Text=Presets and style
MeterStyle=Set.String:S | Set.OptionCat:S
[Option01]
Meter=String
Text=Core appearance preset
MeterStyle=Set.String:S | Set.OptionName:S
[Div:1]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Core font
MeterStyle=Set.String:S | Set.OptionName:S


[Anim]
Meter=String
Text=Customize colors
MeterStyle=Set.String:S | Set.OptionCat:S

[Option10]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1383]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Secondary Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1384]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Tertiary Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1385]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Accent Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1386]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Secondary Accent Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1387]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Text Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1388]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Secondary Text Color
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-[ContentContainer:Y]-(30/2-12/2)*[Set.S])
Act=[!commandMeasure Func "startDrop('Style', '#CURRENTSECTION#', 'JaxCore')"]
[Value01]
Meter=String
Text=#Set.Style#
MeterStyle=Set.String:S | Set.Value:S
[Set.Font]
Meter=Shape
MeterStyle=Set.FontBox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#set.Font#
MeterStyle=Set.String:S | Set.Value:S


[Set.Pri_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Set.Sec_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Set.Ter_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Set.Accent_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Set.Accent_Color_2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Set.Text_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Set.SubText_Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])

; ---------------------------------------------------------------------------- ;
;                                Core overrides                                ;
; ---------------------------------------------------------------------------- ;

[Auto_Refresh:M]
Measure=


[Help:Category]
Y=(#Set.H#-100*[Set.S])

[DivCat:1293s18]
Meter=
[ActiveChecker]
Measure=
[BottomButton]
Meter=
[BottomText]
Meter=