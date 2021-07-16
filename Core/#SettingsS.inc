[Variables]
@includeSkin=#@#SecVar.inc
;Retrives the skin name
@includeSkinVars=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
@includeSkinVer=#SKINSPATH##Skin.Name#\@Resources\Version.inc
;get current skin data
Skin.Appearance=Combilaunch | Plainext | ModularClocks | MIUIShade | ModularPlayers
Skin.Layout=Combilaunch | MIUIShade
; Skin.General=Combilaunch | Plainext | ModularClocks | MIUIShade | ModularPlayers
Skin.Media=Plainext | MIUIShade | ModularPlayers
Skin.Render=ModularClocks
Skin.FAQ=Plainext | MIUIShade | ModularClocks | ModularPlayers

Skin.Override=MIUIShade.00100

[Set.GeneratePages:M]
Measure=Script
ScriptFile=#@#Lua\GenSet.lua
[Set.Refresh:M]
Measure=Script
ScriptFile=#@#Lua\Refresh.lua
Refreshed=0