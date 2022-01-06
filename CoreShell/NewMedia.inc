[Variables]
BarHandler=5.5

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



; --------------------------------- Section2 --------------------------------- ;

[Section1]
Meter=Shape
X=(30*[Set.S])
Y=(30*[Set.S])R
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(100*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Container=ContentContainer
DynamicVariables=1

[Section1.Icon]
Meter=String
Text=[\xec4f]
X=(#Set.P#)r
Y=(100/2*[Set.S])r
FontSize=(20*[set.s])
MeterStyle=Set.String:S | Set.Icon:S | Section1.Icon:#MediaType#
[Section1.Icon:Modern]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section1.Icon:Auto]
FontColor=#Set.Accent_Color_2#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color_2#

[Section1.Text]
Meter=String
X=(5*[Set.S])R
Y=r
W=([ContentContainer:W]-#Set.P#*4-300*[Set.S])
ClipString=2
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Set.String:S | Section1.Text:#MediaType#
[Section1.Text:Modern]
Text=Method: #MediaType##CRLF#Gets media status from all media players.
[Section1.Text:Auto]
Text=Method: #MediaType##CRLF#Switches between nowplaying and webnowplaying plugins.

[MediaType:]
Meter=Shape
Y=(-30/2*[Set.S])r
X=([ContentContainer:W]-#Set.P#-300*[Set.S])
Shape2=Rectangle ([&Func:returnBool('MediaType', 'Modern')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables MediaType "Auto" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables MediaType "Modern" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[MediaType:0]
Meter=String
Text=Auto
FontColor=[&Func:returnBool('MediaType', 'Modern', '#Set.Text_Color#', '#Set.Pri_Color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[MediaType:1]
Meter=String
Text=Modern
FontColor=[&Func:returnBool('MediaType', 'Modern', '#Set.Pri_color#', '#Set.Text_Color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

; --------------------------------- Section2 --------------------------------- ;

[Section2]
Meter=Shape
X=(30*[Set.S])
Y=(60*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(100*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Container=ContentContainer
DynamicVariables=1

[Section2.Icon]
Meter=String
Text=[\xe7b3]
X=(#Set.P#)r
Y=(100/2*[Set.S])r
FontSize=(20*[set.s])
MeterStyle=Set.String:S | Set.Icon:S | Section2.Icon:#FetchImage#
[Section2.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section2.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section2.Text]
Meter=String
X=(5*[Set.S])R
Y=r
W=([ContentContainer:W]-#Set.P#*4-60*[Set.S])
ClipString=2
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Set.String:S | Section2.Text:#FetchImage#
[Section2.Text:0]
Text=Skip media art#CRLF#The skin will not fetch and display now playing album art
[Section2.Text:1]
Text=Download media art#CRLF#The skin will fetch and display now playing album art

[FetchImage]
Meter=Shape
MeterStyle=Set.Bool:S
Y=(-20/2*[Set.S])r
X=([ContentContainer:W]-#Set.P#-60*[Set.S])

; --------------------------------- Section3 --------------------------------- ;

[Section3]
Meter=Shape
X=(30*[Set.S])
Y=(70*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(150*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#,150
Container=ContentContainer
DynamicVariables=1

[Section3.Text]
Meter=String
X=(#Set.P#)r
Y=(150/2*[Set.S])r
FontSize=(12*[set.s])
MeterStyle=Set.String:S | Section3.Text:#Mediatype#
Container=ContentContainer
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
InlinePattern2=https://.*$
InlinePattern3=https://.*$
InlinePattern4=https://.*$
InlineSetting2=Color | 059FD8
InlineSetting3=Size | (10*[Set.S])
[Section3.Text:Auto]
Text=For Spotify:#CRLF#You'll need Spicetify, follow this guide to install:#CRLF#https://github.com/Jax-Core/ModularPlayers#how-to-install-spicetify-cli
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting4 "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting4 ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=["https://github.com/Jax-Core/ModularPlayers#how-to-install-spicetify-cli"]
[Section3.Text:Modern]
Text=About this method:#CRLF#EXPERIMENTAL: As this is a newly developed method, it is not expected to fully work.#CRLF#Made entirely possible by i2002's MediaPlayer.dll plugin. Check it out here:#CRLF#https://github.com/i2002/RainmeterMediaPlayer
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting4 "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting4 ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=["https://github.com/Jax-Core/ModularPlayers#how-to-install-spicetify-cli"]

; --------------------------------- Section4 --------------------------------- ;

[Section4]
Meter=Shape
X=(30*[Set.S])
Y=(85*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(150*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#,150
Container=ContentContainer
DynamicVariables=1
Hidden=[&Func:returnBool('Mediatype', 'Modern')]

[Section4.Text]
Meter=String
X=(#Set.P#)r
Y=(150/2*[Set.S])r
FontSize=(12*[set.s])
MeterStyle=Set.String:S | Section4.Text:#Mediatype#
Container=ContentContainer
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
InlinePattern2=https://.*$
InlinePattern3=https://.*$
InlinePattern4=https://.*$
InlineSetting2=Color | 059FD8
InlineSetting3=Size | (10*[Set.S])
Hidden=[&Func:returnBool('Mediatype', 'Modern')]
[Section4.Text:Auto]
Text=For Web:#CRLF#Requires the WebNowPlaying extension to be installed on your browser:#CRLF#https://chrome.google.com/webstore/detail/webnowplaying-companion/jfakgfcdgpghbbefmdfjkbdlibjgnbli
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting4 "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting4 ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=["https://chrome.google.com/webstore/detail/webnowplaying-companion/jfakgfcdgpghbbefmdfjkbdlibjgnbli"]
