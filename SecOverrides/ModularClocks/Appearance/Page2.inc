; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[ContentContainer]
MouseScrollUpAction=
MouseScrollDownAction=

[Shape:S]
X=(220*[Set.S])r
Y=r
Shape=Rectangle 0,0,200,200,#Set.R# | strokeWidth 0 | Scale [Set.S],[Set.S] | Extend This
This=Fill Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Subtext_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Dynamicvariables=1
Container=ContentContainer
[Image:S]
MEasureName=Image[#CURRENTSECTION]
; ImageName=#ROOTCONFIGPATH#\.DeveloperResources\WebResources\Clocks\Page1\Image1.png
X=0r
Y=0r
W=(200*[Set.S])
H=(200*[Set.S])
Container=ContentContainer
Dynamicvariables=1
Group=ParsedDisplay

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Shape1]
Meter=Shape
X=(30*[Set.S])
y=(30*[Set.S])R
MeterStyle=Shape:S
[0001]
Meter=Image
MeterStyle=Image:S

[Shape2]
Meter=Shape
MeterStyle=Shape:S
[0002]
Meter=Image
MeterStyle=Image:S

[Shape3]
Meter=Shape
MeterStyle=Shape:S
[0003]
Meter=Image
MeterStyle=Image:S

[Shape4]
Meter=Shape
X=(30*[Set.S])
y=(220*[Set.S])r
MeterStyle=Shape:S
[0004]
Meter=Image
MeterStyle=Image:S

[Shape5]
Meter=Shape
MeterStyle=Shape:S
[0005]
Meter=Image
MeterStyle=Image:S

[Shape6]
Meter=Shape
MeterStyle=Shape:S
[0006]
Meter=Image
MeterStyle=Image:S

[Shape7]
Meter=Shape
X=(30*[Set.S])
y=(220*[Set.S])r
MeterStyle=Shape:S
[0007]
Meter=Image
MeterStyle=Image:S

[Shape8]
Meter=Shape
MeterStyle=Shape:S

[Shape9]
Meter=Shape
MeterStyle=Shape:S

[Shape10]
Meter=Shape
X=(30*[Set.S])
y=(220*[Set.S])r
MeterStyle=Shape:S

[Shape11]
Meter=Shape
MeterStyle=Shape:S

[Shape12]
Meter=Shape
MeterStyle=Shape:S

[ConnectivityErrorShape]
Meter=Shape
X=[Shape1:X]
Y=[Shape1:Y]
Shape=Rectangle 0,0,(200*3+20*2),(200*4+20*3),#set.R# | strokeWidth 0 | Scale [Set.S],[Set.S] | Extend This
This=Fill Color #Set.Ter_Color#
Dynamicvariables=1
Hidden=1
Group=Connecterror

[ErrorString]
Meter=String
FontSize=(30*[Set.S])
Text=Connectivity.Error#CRLF#Make sure you're connected to the internet. If the problem presists, please seek help on the Discord server.
FontFace=Poppins SemiBold
X=((200*3+20*2)*[Set.S]/2)r
Y=((200*4+20*3)*[Set.S]/2)r
W=((200*3+20*2)*[Set.S])
ClipString=2
InlinePattern=#CRLF#.*
InlineSetting=Size | (15*[Set.S])
MeterStyle=Set.String:S
StringAlign=CenterCenter
Hidden=1
Group=Connecterror


; ---------------------------------------------------------------------------- ;
;                                    Parser                                    ;
; ---------------------------------------------------------------------------- ;
@includeWeb=WebParse\Measures.inc