; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Shape:S]
X=(205*[Set.S])r
Y=(-145*[Set.S])r
Shape=Rectangle 0,0,(200),150,#Set.R# | StrokeWidth 0 | Extend This
Shape2=Ellipse 100,25,2.5 | Extend Common
Shape3=Ellipse 125,50,2.5 | Extend Common
Shape4=Ellipse 150,75,2.5 | Extend Common
Shape5=Ellipse 75,50,2.5 | Extend Common
Shape6=Ellipse 100,75,2.5 | Extend Common
Shape7=Ellipse 125,100,2.5 | Extend Common
Shape8=Ellipse 50,75,2.5 | Extend Common
Shape9=Ellipse 75,100,2.5 | Extend Common
Shape10=Ellipse 100,125,2.5 | Extend Common
Shape11=Path That | StrokeWidth 2 | StrokeColor #Set.Text_Color# | OffSet 0,-10
Common=StrokeWidth 0 | Fill Color #Set.Text_Color# | OffSet 0,-10
DynamicVariables=1
Container=ContentContainer
This=Fill Color #Set.Sec_Color#,200
That=[&Lua:exportPath('chain', '#CURRENTSECTION#')]
LeftMouseUpAction=[!CommandMeasure Lua Start('#CURRENTSECTION#')]
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Sec_Color#,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
TransformationMatrix=[Set.S];0;0;[Set.S];((1-[Set.S])*[#CURRENTSECTION#:X]);((1-[Set.S])*[#CURRENTSECTION#:Y])
[String:S]
X=5r
Y=(145*[Set.S])r
StringAlign=LeftBottom
FontSize=(10*[Set.S])
Container=ContentContainer

[Lua]
Measure=Script
ScriptFile=#@#Lua\Combilaunch.lua

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[1Shape]
Meter=Shape
X=(20*[Set.S])
Y=(30*[Set.S])R
MeterStyle=Shape:S
chain=123698745
[1Text]
Meter=String
Text=Combilaunch Github
MeterStyle=Set.String:S | String:S

@includeFromUser=#SKINSPATH##SKin.Name#\@Resources\Global\Core.inc