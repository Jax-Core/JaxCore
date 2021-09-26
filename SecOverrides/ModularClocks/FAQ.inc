[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S]+#Scroll#)
DynamicVariables=1
Text=Frequently Asked Questions /Clocks
FontSize=(20*[Set.S])
FontWeight=450
MeterStyle=Set.String:S
Container=ContentContainer
Leftmouseupaction=[!Refresh]
InlinePattern=(/.*)
InlineSetting=Size | 10
InlinePattern2=(/.*)
InlineSetting2=Color | 150,150,150
;================================================================================================================================================================================

[Q1]
Meter=String
Text=Why do I have to install ImageMagick?
MeterStyle=Set.String:S | Set.OptionCat:S
[A1]
Meter=String
Text=ImageMagick allows the skin to create blur and shadow effects, which can't be done flawlessly just with rainmeter
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10101]
Meter=Shape
MeterStyle=Set.Div:S

[Q2]
Meter=String
Text=Why's the blur lagging when I move the clock?
MeterStyle=Set.String:S | Set.OptionCat:S
[A2]
Meter=String
Text=In order to prevent lag and high resource usage, the blur is set to have a low update rate of 1ups
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10102]
Meter=Shape
MeterStyle=Set.Div:S

[Q3]
Meter=String
Text=What can I do if the skin looks too big / too small on my monitor?
MeterStyle=Set.String:S | Set.OptionCat:S
[A3]
Meter=String
Text=You can customize the scaling in the appearance tab to suit your needs
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10103]
Meter=Shape
MeterStyle=Set.Div:S

[Q4]
Meter=String
Text=Will there be additional styles / render methods added?
MeterStyle=Set.String:S | Set.OptionCat:S
[A4]
Meter=String
Text=Absolutely. You can check for updates in the info tab, so you wouldn't miss any updates
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10104]
Meter=Shape
MeterStyle=Set.Div:S

[Q5]
Meter=String
Text=Why does Chameleon render output weird colors?
MeterStyle=Set.String:S | Set.OptionCat:S
[A5]
Meter=String
Text=The chameleon plugin might not output the best colors if your wallpaper consists of a large variety of colors
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10105]
Meter=Shape
MeterStyle=Set.Div:S

[Q6]
Meter=String
Text=How can I center the clocks / reload the blur?
MeterStyle=Set.String:S | Set.OptionCat:S
[A6]
Meter=String
Text=You can achieve above actions by right clicking the clock
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10106]
Meter=Shape
MeterStyle=Set.Div:S

[Q7]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionCat:S
[A7]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10107]
Meter=Shape
MeterStyle=Set.Div:S

[Q8]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionCat:S
[A8]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10108]
Meter=Shape
MeterStyle=Set.Div:S

[Q9]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionCat:S
[A9]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S
[Divider10109]
Meter=Shape
MeterStyle=Set.Div:S

[Q10]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionCat:S
[A10]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S
[Divider101010]
Meter=Shape
MeterStyle=Set.Div:S
