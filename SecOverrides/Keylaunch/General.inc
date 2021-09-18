[Variables]
@includeAct=#SKINSPATH##Skin.Name#\@Resources\Act.inc
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Act.inc
Sec.ForceWriteVariables=0

[HotkeysTitle]
Meter=String
Text=List of actions (#Total#)
; / tip: right click to select folders instaed of files
InlinePattern=/.*
inlinesetting=Size | (8*[Set.S])
InlinePattern2=/.*
inlinesetting2=Color | #Set.Subtext_Color#
MeterStyle=Set.String:S | Set.OptionCat:S

[Script:M]
Measure=Script
ScriptFile=#@#Lua\GenKeylaunchKey.lua

[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
OnUpdateAction=[!Delay 100][!CommandMeasure CheckForDataFolder "Check-Data"]
ScriptFile=#@#Powershell\CheckData.ps1

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Sec.Edit:S]
Fill=Fill Color 0,255,50,100
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,255,50,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 0,255,50,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Act=[!CommandMeasure Script:M "Edit(0, 0, '#CURRENTSECTION#')"]

[Sec.Delete:S]
Fill=Fill Color 255,0,0,100
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,0,0,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,0,0,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#Set.W#-#Set.L#-#Set.P#*2-190*[Set.S])
Shape=Rectangle (160*[Set.S]),0,(30*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Act=[!CommandMeasure Script:M "Remove(0, '#CURRENTSECTION#')"]

; ---------------------------------------------------------------------------- ;
;                                   Includes                                   ;
; ---------------------------------------------------------------------------- ;



@includeInclude=#SKINSPATH#..\CoreData\Keylaunch\Include.inc

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini
