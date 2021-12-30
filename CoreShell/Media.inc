[Variables]
BarHandler=5

[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S]+#Scroll#)
DynamicVariables=1
Text=Media 
FontSize=(25*[Set.S])
FontWeight=600
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
MeterStyle=Set.String:S
Container=ContentContainer

[MediaLua]
Measure=Script
ScriptFile=#@#Lua\MediaPlayers.lua

; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

[MediaBox:S]
X=(#Set.P#/2+20*[Set.S])R
Y=(-20*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]/2-#Set.P#/2),(150*[Set.S]),(#Set.R#) | StrokeWidth 0 | Extend This
This=Fill LinearGradient 1232412414
1232412414=45 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'Opacity')] ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.1')],[&Func:LocalVar('#CURRENTSECTION#', 'Opacity')] ; 1.0
Opacity=90
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# 1232412414 "45 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.2')],[&Func:LocalVar('#CURRENTSECTION#', 'Opacity')] ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.3')],[&Func:LocalVar('#CURRENTSECTION#', 'Opacity')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# 1232412414 "45 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.0')],[&Func:LocalVar('#CURRENTSECTION#', 'Opacity')] ; 0.0 | [&Func:LocalVar('#CURRENTSECTION#', 'Grad.1')],[&Func:LocalVar('#CURRENTSECTION#', 'Opacity')] ; 1.0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
[MediaBox1:S]
Opacity=255
[MediaText:S]
X=(20*[Set.S])r
Y=(20*[Set.S])r
FontSize=(25*[Set.S])
FontFace=#Set.Font# 
FontWeight=(650)
Container=ContentContainer
[MediaImage:S]
X=([#CURRENTSECTION#Shape:W]-140*[Set.S])r
Y=r
W=(100*[Set.S])
H=(100*[Set.S])
DynamicVariables=1
Imagename=#@#Icons\Music\#CURRENTSECTION#.png
PreserveAspectRatio=1
Container=ContentContainer


; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Divider192038]
Meter=Shape
MeterStyle=Set.Div:S

[SpotifyShape]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=MediaBox:S
Grad.0=29, 185, 84
Grad.1=10, 171, 68
Grad.2=29, 185, 84
Grad.3=30, 215, 96
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[SpotifyText]
Meter=String
Text=Spotify
MEterStyle=Set.String:S | MEdiaText:S
[Spotify]
Meter=Image
MeterStyle=MediaImage:S

[WebShape]
Meter=Shape
MeterStyle=MediaBox:S
Grad.0=0, 130, 119
Grad.1=0, 154, 223
Grad.2=0, 130, 170
Grad.3=0, 154, 250
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[WebText]
Meter=String
Text=Web
MEterStyle=Set.String:S | MEdiaText:S
[Web]
Meter=Image
MeterStyle=MediaImage:S

[MusicBeeShape]
Meter=Shape
X=(20*[Set.S])
Y=([SpotifyShape:YH]-[ContentContainer:Y]+#set.P#/2)
MeterStyle=MediaBox:S
Grad.0=45,45,45
Grad.1=255, 192, 0
Grad.2=70,70,70
Grad.3=255, 209, 0
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[MusicBeeText]
Meter=String
Text=MusicBee
MEterStyle=Set.String:S | MEdiaText:S
[MusicBee]
Meter=Image
MeterStyle=MediaImage:S

[AIMPShape]
Meter=Shape
MeterStyle=MediaBox:S
Grad.0=189, 123, 38
Grad.1=253, 222, 27
Grad.2=226, 148, 47
Grad.3=253, 222, 27
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[AIMPText]
Meter=String
Text=AIMP
MEterStyle=Set.String:S | MEdiaText:S
[AIMP]
Meter=Image
MeterStyle=MediaImage:S

[FoobarShape]
Meter=Shape
X=(20*[Set.S])
Y=([MusicBeeShape:YH]-[ContentContainer:Y]+#set.P#/2)
MeterStyle=MediaBox:S
Grad.0=150,150,150
Grad.1=55, 55, 55
Grad.2=150,150,150
Grad.3=77,77,77
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[FoobarText]
Meter=String
Text=Foobar
MEterStyle=Set.String:S | MEdiaText:S
[Foobar]
Meter=Image
MeterStyle=MediaImage:S

[iTunesShape]
Meter=Shape
MeterStyle=MediaBox:S
Grad.0=255, 94, 82
Grad.1=6, 198, 255
Grad.2=255, 94, 82
Grad.3=189, 122, 199
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[iTunesText]
Meter=String
Text=iTunes
MEterStyle=Set.String:S | MEdiaText:S
[iTunes]
Meter=Image
MeterStyle=MediaImage:S

[WinAMPShape]
Meter=Shape
X=(20*[Set.S])
Y=([FoobarShape:YH]-[ContentContainer:Y]+#set.P#/2)
MeterStyle=MediaBox:S
Grad.0=255, 84, 0
Grad.1=178, 16, 14
Grad.2=255, 84, 0
Grad.3=254, 22, 20
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[WinAMPText]
Meter=String
Text=WinAMP
MEterStyle=Set.String:S | MEdiaText:S
[WinAMP]
Meter=Image
MeterStyle=MediaImage:S

[WMPShape]
Meter=Shape
MeterStyle=MediaBox:S
Grad.0=139, 170, 195
Grad.1=102, 104, 116
Grad.2=139, 170, 195
Grad.3=148, 151, 167
Leftmouseupaction=[!CommandMeasure MediaLua "startInfo('#CURRENTSECTION#')"]
[WMPText]
Meter=String
Text=WMP
MEterStyle=Set.String:S | MEdiaText:S
[WMP]
Meter=Image
MeterStyle=MediaImage:S