[Variables]
@includeSkin=#@#SecVar.inc
;Retrives the skin name
@includeSkinVars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
@includeSkinVer=#SKINSPATH##Skin.Name#\@Resources\Version.inc
;get current skin data
Skin.Appearance=Combilaunch | Plainext | ModularClocks | MIUIShade | ModularPlayers
Skin.Layout=Combilaunch
; Skin.General=Combilaunch | Plainext | ModularClocks | MIUIShade | ModularPlayers
Skin.Media=MIUIShade | ModularPlayers
Skin.Render=ModularClocks
Skin.FAQ=MIUIShade | ModularClocks | ModularPlayers

[Set.GeneratePages:M]
Measure=Script
ScriptFile=#@#Lua\GenSet.lua
[Set.Refresh:M]
Measure=Script
ScriptFile=#@#Lua\Refresh.lua
Refreshed=0