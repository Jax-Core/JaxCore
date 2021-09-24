
[Set.string:S]
Container=ContentCOntainer

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;


[Func]
Measure=Script
ScriptFile=#@#Lua\Func.lua

[Header]
Meter=String
Text=Adding shortcut for easy access
X=(#Sec.W#/2)
Y=(#Sec.H#/2-([Header:H]+[Des:H])/2-#sec.P#)
FontSize=(20)
DynamicVariables=1
FontFace=Poppins SemiBold
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=shortcut
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Des]
Meter=String
Text=Adding a shortcut to either of these 2 locations so that Search would be able to pick up the core activator, allowing you to call Core up by Search.
X=(#Sec.W#/2)
Y=(#Sec.P#)R
W=(#SEc.W#-#Sec.P#*2)
ClipString=2
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=Search
InlineSetting=Color | 0,255,50

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;


[AddButton]
Meter=Shape
X=(#Sec.W#/2-120/2*#Sec.S#+(-120/2-2.5)*#TweenNode2#*#Sec.S#)
Y=(#Sec.H#*0.7)
DynamicVariables=1
Group=Tweenable
Shape=Rectangle 0,0,120,30,5 | StrokeWidth 0 | Fill Color #Set.Accent_Color# | Scale #Sec.S#,#Sec.S#,0,0
Container=ContentCOntainer
Leftmouseupaction=[!CommandMeasure Func "startPopup('shortcut')"]
[addText:S]
Meter=String
Text=Sure!
X=(120/2*#Sec.S#)r
Y=(30/2*#Sec.S#)r
FontFace=Poppins SemiBold
StringAlign=CenterCEnter
MeterStyle=Set.String:S

[Button]
Meter=Shape
X=((120/2+5)*#Sec.S#)r
Shape=Rectangle 0,0,120,30,5 | StrokeWidth 0 | Fill Color #Set.Sec_Color#,(#TweenNode2#*255) | Scale #Sec.S#,#Sec.S#,0,0
MeterStyle=Button:S
[ButtonText]
MEter=String
Text=Maybe later
MeterStyle=Set.String:S | ButtonText:S