[Variables]
BarHandler=5

[Header]
Meter=String
X=(20*[Set.S])
Y=(20*[Set.S])
DynamicVariables=1
Text=Media 
FontSize=(20*[Set.S])
FontWeight=450
MeterStyle=Set.String:S
Container=ContentContainer
Leftmouseupaction=[!Refresh]
InlinePattern=\s(.*)
InlineSetting=Size | 10
InlinePattern2=\s(.*)
InlineSetting2=Color | 150,150,150
Group=Shorthand

[Export]
Measure=String
String=#NPName#
IfMatch=Spotify
ifmatchaction=[!SetOption SpotifyShape MeterStyle "MediaBox:S | MediaBox1:S"][!UpdateMEter *][!Redraw]
IfMatch2=AIMP
ifmatchaction2=[!SetOption AIMPShape MeterStyle "MediaBox:S | MediaBox1:S"][!UpdateMEter *][!Redraw]
IfMatch3=CAD
ifmatchaction3=[!SetOption CADShape MeterStyle "MediaBox:S | MediaBox1:S"][!UpdateMEter *][!Redraw]
IfMatch4=iTunes
ifmatchaction4=[!SetOption Box4 MeterStyle "MediaBox:S | MediaBox1:S"][!UpdateMEter *][!Redraw]
IfMatch5=WinAMP
ifmatchaction5=[!SetOption Box5 MeterStyle "MediaBox:S | MediaBox1:S"][!UpdateMEter *][!Redraw]
IfMatch6=WMP
ifmatchaction6=[!SetOption Box6 MeterStyle "MediaBox:S | MediaBox1:S"][!UpdateMEter *][!Redraw]
ifmatchmode=1

; ---------------------------------------------------------------------------- ;
;                                 Meter styles                                 ;
; ---------------------------------------------------------------------------- ;

[MediaBox:S]
X=(#Set.P#/2+20*[Set.S])R
Y=(-20*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]/2-#Set.P#/2),(150*[Set.S]),(#Set.R#*2) | StrokeWidth 0 | Extend This
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
FontFace=Poppins SemiBold
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
Leftmouseupaction=[!WriteKEyValue Variables PLayer "WNP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "Spotify" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[SpotifyText]
Meter=String
Text=Spotify
MEterStyle=Set.String:S | MEdiaText:S
[Spotify]
Meter=Image
MeterStyle=MediaImage:S

[AIMPShape]
Meter=Shape
MeterStyle=MediaBox:S
Grad.0=189, 123, 38
Grad.1=253, 222, 27
Grad.2=226, 148, 47
Grad.3=253, 222, 27
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "AIMP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[AIMPText]
Meter=String
Text=AIMP
MEterStyle=Set.String:S | MEdiaText:S
[AIMP]
Meter=Image
MeterStyle=MediaImage:S

[CADShape]
Meter=Shape
X=(25*[Set.S])
Y=([SpotifyShape:YH]-[ContentContainer:Y]+#set.P#/2)
MeterStyle=MediaBox:S
Grad.0=150,150,150
Grad.1=55, 55, 55
Grad.2=150,150,150
Grad.3=77,77,77
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "CAD" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[CADText]
Meter=String
Text=CAD
MEterStyle=Set.String:S | MEdiaText:S
[CAD]
Meter=Image
MeterStyle=MediaImage:S

[iTunesShape]
Meter=Shape
MeterStyle=MediaBox:S
Grad.0=255, 94, 82
Grad.1=6, 198, 255
Grad.2=255, 94, 82
Grad.3=189, 122, 199
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "iTunes" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[iTunesText]
Meter=String
Text=iTunes
MEterStyle=Set.String:S | MEdiaText:S
[iTunes]
Meter=Image
MeterStyle=MediaImage:S

[WinAMPShape]
Meter=Shape
X=(25*[Set.S])
Y=([CADShape:YH]-[ContentContainer:Y]+#set.P#/2)
MeterStyle=MediaBox:S
Grad.0=255, 84, 0
Grad.1=178, 16, 14
Grad.2=255, 84, 0
Grad.3=254, 22, 20
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "WinAMP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M][!Refresh]
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
Leftmouseupaction=[!WriteKEyValue Variables PLayer "NP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!WriteKEyValue Variables NPName "WMP" "#SKINSPATH##Skin.Name#\@Resources\Vars.inc"][!UpdateMeasure Auto_Refresh:M][!Refresh]
[WMPText]
Meter=String
Text=WMP
MEterStyle=Set.String:S | MEdiaText:S
[WMP]
Meter=Image
MeterStyle=MediaImage:S