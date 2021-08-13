[Color]
Meter=String
Text=Options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Scaling factor
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s0sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Distance factor
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19203s8s1sds]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Detection area from node origin
MeterStyle=Set.String:S | Set.OptionName:S

[Header2]
Meter=String
X=([ContentContainer:W]/2)
Y=([ContentContainer:H]/2)
ClipString=2
W=([ContentContainer:W]/2)
DynamicVariables=1
StringAlign=Center
Text=Although you can customize settings for Combilaunch in the core, it does not provide 100% compatiblitiy. For combilaunch, Core only serves as an update changer, hence using the classic settings menu for combilaunch customization is highly recommended.  To open the classic settings menu, right click combilaunch and click Config.
FontSize=(10*[Set.S])
FontCOlor=150,150,150
MeterStyle=Set.String:S
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Size]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Size#
MeterStyle=Set.String:S | Set.Value:S
[Gap]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Gap#
MeterStyle=Set.String:S | Set.Value:S
[DotBox]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#DotBox#
MeterStyle=Set.String:S | Set.Value:S