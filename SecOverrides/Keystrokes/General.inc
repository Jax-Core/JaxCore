[HotkeysTitle]
Meter=String
Text=Hotkeys
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=HotKey
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Terminate service
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

[Updatre]
Meter=String
Text=Update
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option21]
Meter=String
Text=RGB update rate
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!ActivateConfig "#JaxCore\Main\Hotkey"][!Move (#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#/2-500/2) (#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#/2-500/2) "#JaxCore\Main\Hotkey"]
[Value01]
Meter=String
Text=#Key#
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


[Rm.AniUpdate]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=#Rm.AniUpdate#
MeterStyle=Set.String:S | Set.Value:S


@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini