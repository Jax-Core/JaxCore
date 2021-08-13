
[Set.string:S]
Container=ContentCOntainer

[MeasureLoop]
Measure=Loop
StartValue=0
EndValue=100
Increment=2
LoopCount=0
UpdateDivider=1
IfCondition=MeasureLoop = 100
IfTrueAction=[!SetOption MeasureLoop InvertMeasure 1][!UpdateMeasure MeasureLoop]
IfCondition2=MeasureLoop = 0
IfTrueAction2=[!SetOption MeasureLoop InvertMeasure 0][!UpdateMeasure MeasureLoop]

; [MeasureLoop]
; Measure=Calc
; Formula=100

; ---------------------------------------------------------------------------- ;
;                                   Contenet                                   ;
; ---------------------------------------------------------------------------- ;

[Header]
Meter=String
Text=Feature highlights
X=(#Sec.W#/2)
Y=(#Sec.H#*0.2)
FontSize=(20)
DynamicVariables=1
FontFace=Poppins SemiBold
StringAlign=Center
FontColor=#Set.TextColor#
MeterStyle=Set.String:S
InlinePattern=shortcut
InlineSetting=GradientColor | 180 | CC1C15 ; 0.0 | FF700F ; 1.0

[Shape.1]
Meter=Shape
X=(#Sec.W#/2-(200*2+#Sec.P#)/2)
Y=(#Sec.H#*0.3)
Shape=Rectangle 0,0,(80+120*([MeasureLoop]/100)),(80+20*([MeasureLoop]/100)),5 | StrokeWidth 2 | Stroke Color #Set.SubText_Color# | Fill Color #Set.Ter_Color#
Shape2=Ellipse 0,0,5 | StrokeWidth 1 | Stroke Color 255,255,255 | Fill Color #Set.Accent_Color#
Shape3=Ellipse (80+120*([MeasureLoop]/100)),(80+20*([MeasureLoop]/100)),5 | StrokeWidth 1 | Stroke Color 255,255,255 | Fill Color #Set.Accent_Color#
Shape4=Rectangle 5,5,(70+120*([MeasureLoop]/100)),5,2.5 | StrokeWidth 0 | Fill LinearGradient This
This=180 | CC1C15 ; 0.0 | FF700F ; 1.0
Shape5=Rectangle 5,15,(25+110*([MeasureLoop]/100)),5,2.5 | StrokeWidth 0 | Fill Color #Set.Text_Color#
Shape6=Rectangle 5,25,(25+50*([MeasureLoop]/100)),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#
DynamicVariables=1
UpdateDivider=1
Container=ContentCOntainer

[Text.1]
Meter=String
X=(200/2)r
Y=105r
FontSize=8
StringAlign=CenterTop
MeterStyle=Set.String:S
Text=Scalable menu

[Shape.2]
Meter=Shape
X=(200/2+#Sec.P#)r
Y=-105r
DynamicVariables=1
Container=ContentCOntainer
Shape=Rectangle 0,0,(200),(100),5 | StrokeWidth 2 | Stroke Color #Set.SubText_Color# | Fill Color #Set.Ter_Color#
Shape2=Rectangle 5,5,(40),5,2.5 | StrokeWidth 0 | Fill Color #Set.Text_Color#
Shape3=Rectangle 5,25,(35),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#
Shape4=Rectangle 5,35,(35),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#
Shape5=Rectangle 5,45,(35),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#

[Image.2]
Meter=Image
ImageName=#@#Icons\Settings\GeneralIcon.png
X=(200/2-48/2)r
Y=(100/2-48/2)r
W=48
H=48
DynamicVariables=1
UpdateDivider=1
Container=ContentCOntainer
TransformationMatrix=(Cos(Rad([MeasureLoop]/100*360)));(-Sin(Rad([MeasureLoop]/100*360)));(Sin(Rad([MeasureLoop]/100*360)));(Cos(Rad([MeasureLoop]/100*360)));(([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])-([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Cos(Rad([MeasureLoop]/100*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Sin(Rad([MeasureLoop]/100*360)));(([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])+([#CURRENTSECTION#:W]*0.5+[#CURRENTSECTION#:X])*Sin(Rad([MeasureLoop]/100*360))-([#CURRENTSECTION#:H]*0.5+[#CURRENTSECTION#:Y])*Cos(Rad([MeasureLoop]/100*360)))

[Text.2]
Meter=String
X=(48/2)r
Y=(48/2+100/2+5)r
FontSize=8
StringAlign=CenterTop
MeterStyle=Set.String:S
Text=Unified settings panel


[Shape.3]
Meter=Shape
X=(#Sec.W#/2-200/2)
Y=(#Sec.H#*0.55)
DynamicVariables=1
Container=ContentCOntainer
Shape=Rectangle 0,0,(200),(100),5 | StrokeWidth 2 | Stroke Color #Set.SubText_Color# | Fill Color #Set.Ter_Color#
Shape2=Rectangle 5,5,(25),5,2.5 | StrokeWidth 0 | Fill Color #Set.Text_Color#
Shape3=Rectangle 5,25,(40),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#
Shape4=Rectangle 5,35,(35),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#
Shape5=Rectangle 5,45,(35),5,2.5 | StrokeWidth 0 | Fill Color #Set.SubText_Color#

[Image.3]
Meter=Image
ImageName=#@#Icons\Install.png
X=(200/2-48/2)r
Y=(100/2-10-(30*([MeasureLoop]/100)))r
W=48
H=48
DynamicVariables=1
UpdateDivider=1
Greyscale=1
ImageTint=0,255,50
Container=ContentCOntainer

[Text.3]
Meter=String
X=(48/2)r
Y=380
StringAlign=CenterTop
FontSize=8
DynamicVariables=1
MeterStyle=Set.String:S
Text=Automatically check for updates and quick installation

; ---------------------------------------------------------------------------- ;
;                                    Buttons                                   ;
; ---------------------------------------------------------------------------- ;


[Button]
Meter=Shape
Y=(#Sec.H#*0.85)
MeterStyle=Button:S
[ButtonText]
MEter=String
MeterStyle=Set.String:S | ButtonText:S