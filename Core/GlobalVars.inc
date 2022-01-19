; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
[Variables]
@includegVar1=#@#gVars\Time.inc
@includegVar2=#@#gVars\Weather.inc
@includegVar3=#@#gVars\WeatherAPIKey.inc

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Time]
Meter=String
Text=Time & weather
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option01]
Meter=String
Text=Time format
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Weather temperature unit
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:24125158]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Weather location
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:58]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Weather language
MeterStyle=Set.String:S | Set.OptionName:S

[Advanced]
Meter=String
Text=Advanced
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Weather.com API key
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[gVar.2412:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('gVar.2412', 'H')]=0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables gVar.2412 "I" "#@#gVars\Time.inc"]
1Act=[!WriteKeyValue Variables gVar.2412 "H" "#@#gVars\Time.inc"]
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[gVar.2412:0]
Meter=String
Text=12-Hour
FontColor=[&Func:returnBool('gVar.2412', 'H', '#Set.Text_Color#', '#Set.Pri_color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[gVar.2412:1]
Meter=String
Text=24-hour
FontColor=[&Func:returnBool('gVar.2412', 'H', '#Set.Pri_color#', '#Set.Text_Color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[gVar.WeatherUnits:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('gVar.WeatherUnits', 'Imperial')]=0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables gVar.WeatherUnits "Metric" "#@#gVars\Weather.inc"]
1Act=[!WriteKeyValue Variables gVar.WeatherUnits "Imperial" "#@#gVars\Weather.inc"]
MeterStyle=Set.Pick:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[gVar.WeatherUnits:0]
Meter=String
Text=Metric
FontColor=[&Func:returnBool('gVar.WeatherUnits', 'Imperial', '#Set.Text_Color#', '#Set.Pri_color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[gVar.WeatherUnits:1]
Meter=String
Text=Imperial
FontColor=[&Func:returnBool('gVar.WeatherUnits', 'Imperial', '#Set.Pri_color#', '#Set.Text_Color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[gVar.WeatherLocation]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
SaveLocation="#@#gVars\Weather.inc"
[Value03]
Meter=String
Text=#gVar.WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[gVar.language]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
SaveLocation="#@#gVars\Weather.inc"
[Value04]
Meter=String
Text=#gVar.language#
MeterStyle=Set.String:S | Set.Value:S

[gVar.WeatherAPIKey]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
SaveLocation="#@#gVars\WeatherAPIKey.inc"
[Value11]
Meter=String
Text=#gVar.WeatherAPIKey#
MeterStyle=Set.String:S | Set.Value:S

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