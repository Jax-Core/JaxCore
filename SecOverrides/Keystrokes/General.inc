[HotkeysTitle]
Meter=String
Text=Hotkeys
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Toggle visibility
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19s138]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Toggle draggability
MeterStyle=Set.String:S | Set.OptionName:S

[Mouse]
Meter=String
Text=Mouse
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Mouse X maximum acceleration
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19138]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Mouse Y maximum acceleration
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191s38]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Mouse acceleration fetching rate
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S191s3s8]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Show mouse CPS
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value01]
Meter=String
Text=#KeyInString#
MeterStyle=Set.String:S | Set.Value:S
[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Accessories\Hotkey"][!SetVariable Sec.Num 2 "#JaxCore\Accessories\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Accessories\Hotkey"]
[Value02]
Meter=String
Text=#Key2InString#
MeterStyle=Set.String:S | Set.Value:S

[MaxX]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#MaxX#
MeterStyle=Set.String:S | Set.Value:S
[MaxY]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#MaxY#
MeterStyle=Set.String:S | Set.Value:S
[MouseFetchDelay]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#MouseFetchDelay#
MeterStyle=Set.String:S | Set.Value:S
[MouseCPS]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option14:Y]-#Set.P#+(-20/2+8)*[Set.S])


@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini