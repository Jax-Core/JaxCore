[Rainmeter]
Update=1000

[Variables]
Sec.W=(600*#Sec.S#)
Sec.H=(800*#Sec.S#)
AniDir=Left

NowPlayingMedia=AIMP
PlayerType=NP
[moveX]
Formula=20
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=0
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[GetMediaAuto]
Measure=Script
ScriptFile=#@#Lua\GetMediaAuto.lua
OnUpdateAction=[!Delay 100][!CommandMeasure GetMediaAuto "checkMediaAuto()"]

; ; ---------------------------------------------------------------------------- ;
; ;                                      Gru                                     ;
; ; ---------------------------------------------------------------------------- ;

[stateAIMP]
Measure=NowPlaying
PlayerName=AIMP
PlayerType=State
OnChangeAction=[!CommandMeasure GetMediaAuto "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateCAD]
Measure=NowPlaying
PlayerName=CAD
PlayerType=State
OnChangeAction=[!CommandMeasure GetMediaAuto "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWMP]
Measure=NowPlaying
PlayerName=WMP
PlayerType=State
OnChangeAction=[!CommandMeasure GetMediaAuto "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateiTunes]
Measure=NowPlaying
PlayerName=iTunes
PlayerType=State
OnChangeAction=[!CommandMeasure GetMediaAuto "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWinamp]
Measure=NowPlaying
PlayerName=Winamp
PlayerType=State
OnChangeAction=[!CommandMeasure GetMediaAuto "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWebNowPlaying]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
OnChangeAction=[!CommandMeasure GetMediaAuto "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

; ; ---------------------------------------------------------------------------- ;
; ;                                    Minions                                   ;
; ; ---------------------------------------------------------------------------- ;

; ; ------------------------------------ NP ------------------------------------ ;

[npPlayer]
Measure=String
String=#NowPlayingMedia#
UpdateDivider=-1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCover]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npArtist]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Artist
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npTrack]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npProgress]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCurrentPosition]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Position
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npLength]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Duration
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npRepeat]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Repeat
UpdateDivider=1
Group=Music | NP
Disabled=1

[npShuffle]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Shuffle
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npHeart]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Rating
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

; ------------------------------------ WNP ----------------------------------- ;

[wnpPlayer]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Player
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
; OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpRepeat]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Repeat
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpShuffle]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Shuffle
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
UpdateDivider=1
Group=Music | WNP
Disabled=1

; ----------------------------------- Other ---------------------------------- ;

[IDLE_TIME]
Measure=SysInfo
SysInfoType=IDLE_TIME
UpdateDivider=1

; ---------------------------------------------------------------------------- ;
;                                  MeterStyle                                  ;
; ---------------------------------------------------------------------------- ;

[Row:S]
X=#Sec.P#
Y=(15*#sec.S#+#Sec.P#/2)r
Shape=Rectangle 0,0,(#Sec.W#-2*#Sec.P#),(30*#sec.S#),(#Sec.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
[Name:S]
X=(5*#Sec.S#)r
Y=(15*#Sec.S#)r
StringAlign=LeftCenter
DynamicVariables=1
[Value:S]
X=(#Sec.W#-#Sec.P#-5*#Sec.S#)
Y=r
StringAlign=RightCenter
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HeaderImage]
Meter=Image
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo.png
X=(#Sec.W#/2-(50*#Sec.S#)/2)
Y=(#Sec.P#/2)
W=(50*#Sec.S#)
H=(50*#Sec.S#)
ImageAlpha=50

[HeaderString]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.P#)
StringAlign=Center
Text=Measure value debugger
MeterStyle=Sec.String:S
FontSize=(14*#sec.s#)
FontWeight=650

[Row.0]
Meter=Shape
Y=(#Sec.P#)R
MeterStyle=Row:S
[Name.0]
Meter=String
Text="AIMP.CAD.WMP.iTunes.WinAMP.WNP"
MeterStyle=Sec.String:S | Name:S
[Value.0]
Meter=String
MeasureName=stateAIMP
MeasureName2=stateCAD
MeasureName3=stateWMP
MeasureName4=stateiTunes
MeasureName5=stateWinAMP
MeasureName6=stateWebNowPlaying
Text=%1%2%3%4%5%6
MeterStyle=Sec.String:S | Value:S

[Row.Image]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#-2*#Sec.P#),(150*#sec.S#),(#Sec.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
MeterStyle=Row:S
[Row.Image.Container]
Meter=Shape
X=r
Y=r
MeterStyle=Row.Image
[Image.1]
Meter=Image
ImageName=[#PlayerType#Cover]
DynamicVariables=1
W=[Row.Image.Container:W]
H=[Row.Image.Container:H]
PreserveAspectRatio=2
Container=Row.Image.Container

[Row.1]
Meter=Shape
Y=(#Sec.P#/2)R
MeterStyle=Row:S
[Name.1]
Meter=String
Text="Player"
MeterStyle=Sec.String:S | Name:S
[Value.1]
Meter=String
MeasureName=#PlayerType#Player
MeterStyle=Sec.String:S | Value:S

[Row.2]
Meter=Shape
MeterStyle=Row:S
[Name.2]
Meter=String
Text="Artist"
MeterStyle=Sec.String:S | Name:S
[Value.2]
Meter=String
MeasureName=#PlayerType#Artist
MeterStyle=Sec.String:S | Value:S

[Row.3]
Meter=Shape
MeterStyle=Row:S
[Name.3]
Meter=String
Text="Track"
MeterStyle=Sec.String:S | Name:S
[Value.3]
Meter=String
MeasureName=#PlayerType#Track
MeterStyle=Sec.String:S | Value:S

[Row.4]
Meter=Shape
MeterStyle=Row:S
[Name.4]
Meter=String
Text="Progress"
MeterStyle=Sec.String:S | Name:S
[Value.4]
Meter=String
MeasureName=#PlayerType#Progress
MeterStyle=Sec.String:S | Value:S

[Row.5]
Meter=Shape
MeterStyle=Row:S
[Name.5]
Meter=String
Text="CurrentPosition"
MeterStyle=Sec.String:S | Name:S
[Value.5]
Meter=String
MeasureName=#PlayerType#CurrentPosition
MeterStyle=Sec.String:S | Value:S

[Row.6]
Meter=Shape
MeterStyle=Row:S
[Name.6]
Meter=String
Text="Length"
MeterStyle=Sec.String:S | Name:S
[Value.6]
Meter=String
MeasureName=#PlayerType#Length
MeterStyle=Sec.String:S | Value:S

[Row.7]
Meter=Shape
MeterStyle=Row:S
[Name.7]
Meter=String
Text="Shuffle"
MeterStyle=Sec.String:S | Name:S
[Value.7]
Meter=String
MeasureName=#PlayerType#Shuffle
MeterStyle=Sec.String:S | Value:S

[Row.8]
Meter=Shape
MeterStyle=Row:S
[Name.8]
Meter=String
Text="Heart"
MeterStyle=Sec.String:S | Name:S
[Value.8]
Meter=String
MeasureName=#PlayerType#Heart
MeterStyle=Sec.String:S | Value:S

[Row.9]
Meter=Shape
MeterStyle=Row:S
[Name.9]
Meter=String
Text="Repeat"
MeterStyle=Sec.String:S | Name:S
[Value.9]
Meter=String
MeasureName=#PlayerType#Repeat
MeterStyle=Sec.String:S | Value:S

[Row.10]
Meter=Shape
MeterStyle=Row:S
[Name.10]
Meter=String
Text="IDLE_TIME"
MeterStyle=Sec.String:S | Name:S
[Value.10]
Meter=String
MeasureName=IDLE_TIME
UpdateDivider=1
MeterStyle=Sec.String:S | Value:S