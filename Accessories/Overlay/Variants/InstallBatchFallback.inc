[Rainmeter]
Update=-1

[Variables]
@includeVars=#@#Vars.inc
@includeSkinVars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 200 | Position
Position=[!SetWindowPosition 50% 50% 50% 50%]

[p.FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=Blur
Corner=#Set.BlurCorner#
DynamicVariables=1
Border=All

; ---------------------------------------------------------------------------- ;
;                                  mEterStyle                                  ;
; ---------------------------------------------------------------------------- ;

[Sec.String:S]
Container=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Overlay]
Meter=String
W=(600*#Sec.S#)
H=(800*#Sec.S#)
SolidColor=0,0,0,150
Leftmouseupaction=[!DeactivateConfig]
MouseActionCursor=0

[Title]
Meter=String
X=((600*#Sec.S#)/2)
Y=((800*#Sec.S#)/2)
W=(600*#Sec.S#)
StringAlign=CenterCenter
Text=Installer not working? Click me
FontSize=20
Leftmouseupaction=["https://wiki.jaxcore.app/getting-started/faqs/jaxcore-faqs#in-app-installer"]
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
MEterStyle=Sec.String:S
