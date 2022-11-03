[Rainmeter]
Update=-1

[Variables]
@includeVars=#@#Vars.inc

[mActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 200

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
W=(#Set.W#+#Set.WinB#)
H=(#Set.H#+#Set.WinB#)
SolidColor=0,0,0,150
Leftmouseupaction=[!DeactivateConfig]
MouseActionCursor=0

[Title]
Meter=String
X=(#Set.W#/2)
Y=(#Set.H#/2)
W=(#Set.W#)
StringAlign=CenterCenter
Text=Installer not working? Click me
FontSize=20
Leftmouseupaction=["https://wiki.jaxcore.app/getting-started/faqs/jaxcore-faqs#in-app-installer"]
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
MEterStyle=Sec.String:S
