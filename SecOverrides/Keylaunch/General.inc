[Variables]
@includeAct=#SKINSPATH##Skin.Name#\@Resources\Act.inc
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Act.inc

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



@includeInclude=#SKINSPATH##Skin.Name#\@Resources\Include.inc

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini