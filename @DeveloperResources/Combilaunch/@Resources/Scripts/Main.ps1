function Update {

}

function Add {
    $numberOfIndices=$RmAPI.Variable('NumberOfIndices')

    CreateFields -indexCount $numberOfIndices

    CraftVariables -process add -addCount $numberOfIndices

    $RmAPI.Bang('!Refresh')
}
function Delete {
    $numberOfIndices=$RmAPI.Variable('NumberOfIndices')
    $deleteIndex=$RmAPI.Variable('DeleteIndex')

    CreateFields -indexCount $numberOfIndices

    CraftVariables -process remove -addCount $numberOfIndices -deleteIndex $deleteIndex

    $RmAPI.Bang('!Refresh')
}
function ProcessDrop {
    $numberOfIndices=$RmAPI.Variable('NumberOfIndices')

    CreateFields -indexCount $numberOfIndices

    CraftVariables -process drop -addCount $numberOfIndices

    $RmAPI.Bang("!WriteKeyValue Variables NumberOfIndices $numberOfIndices $($RmAPI.VariableStr('@') + 'Checks.inc')")

    $RmAPI.Bang('!Refresh')
}
function CreateFields {
    param(
        [Parameter(Mandatory=$true)]
        $indexCount
    )
#config lists
    $nameContents=@"


"@
    $combinationContents=@"


"@
    $actionContents=@"


"@
    $fileContents=@"


"@
    $deleteContents=@"


"@
    $checkNameContents=@"

[Name]
"@
    $checkLaunchContents=@"

[Launch]
"@

    $RmAPI.Log('Creating configs...')

    for ($i=2; $i -lt $indexCount+1; $i++) {
        $nameContents+=@"

[N$i]
Meter=String
MeterStyle=RegularText | N
Text=#Name$i#
LeftMouseUpAction=[!SetVariable Index $i][!CommandMeasure Input "ExecuteBatch 1"]

"@
        $combinationContents+=@"

[C$i]
Meter=String
MeterStyle=RegularText | C
Text=#Pattern$i#
LeftMouseUpAction=[!SetVariable Index $i][!WriteKeyValue Variables Index $i "SetCombination.ini"][!ActivateConfig "Combilaunch\@Settings" "SetCombination.ini"]

"@
        $actionContents+=@"

[A$i]
Meter=String
MeterStyle=RegularText | A
Text=#MatchAction$i#
LeftMouseUpAction=[!SetVariable Index $i][!CommandMeasure Input2 "ExecuteBatch 1"]
RightMouseUpAction=[!ToggleMeasure ExtendScroll][!ToggleMouseActionGroup "LeftMouseUpAction" ActionTab][!UpdateMeasureGroup Mouse][!UpdateMeterGroup ExtendedMenu][!SetVariable Index $i][!ToggleMeterGroup ExtendedMenu]

"@
        $fileContents+=@"

[F$i]
Meter=String
MeterStyle=IconText | F
LeftMouseUpAction=[!SetVariable Index $i][!UpdateMeasure MeasureChoose][!CommandMeasure MeasureChoose "ChooseFile 1"]

"@
        $deleteContents+=@"

[X$i]
Meter=String
MeterStyle=IconText | X
LeftMouseUpAction=[!SetVariable NumberOfIndices "([#NumberOfIndices]-1)"][!SetVariable DeleteIndex $i][!Delay 5][!WriteKeyValue Variables NumberOfIndices [#NumberOfIndices] "#@#Checks.inc"][!CommandMeasure CombiScript "Delete"]

"@
        $checkNameContents+=@"

IfMatch$i=^#Pattern$i#$
IfMatchAction$i=[!SetOption S Text "#Name$i#"]
"@
        $checkLaunchContents+=@"

IfMatch$i=^#Pattern$i#$
IfMatchAction$i=#MatchAction$i##ConfirmAction#
"@
    }

    $RmAPI.Log('Writing configs...')
    $nameContents | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Include\N.inc') -Encoding utf8
    $combinationContents | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Include\C.inc') -Encoding utf8
    $actionContents | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Include\A.inc') -Encoding utf8
    $fileContents | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Include\F.inc') -Encoding utf8
    $deleteContents | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Include\X.inc') -Encoding utf8
    $($checkNameContents + $checkLaunchContents) | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Variables\ChecksExtension.inc') -Encoding utf8
    $RmAPI.Log('Completed!')
}

function CraftVariables {
    param(
        [Parameter(Mandatory)]
        [ValidateSet('add', 'remove', 'drop')]
        $process,
        [Parameter(Mandatory=$true)]    
        $addCount,
        [Parameter()]
        $deleteIndex
    )
#variables
    
    $nameVariables=@"
    
[Variables]
"@
    $patternVariables=@"
    
[Variables]
"@
    $matchActionVariables=@"
    
[Variables]
"@
    $previuosNamesHash=@('')
    $previuosPatternsHash=@('')
    $previuosMatchActionsHash=@('')

    $RmAPI.Log('Getting old variables...')
    switch ($process) {
        add {
            for ($i=1; $i -lt $addCount; $i++) {
                $previuosNamesHash+=$RmAPI.VariableStr("Name$i")
                $previuosPatternsHash+=$RmAPI.VariableStr("Pattern$i")
                $previuosMatchActionsHash+=$RmAPI.VariableStr("MatchAction$i")
            }
        }
        remove {
            for ($i=1; $i -lt $addCount+2; $i++) {
                if ($i -ne $deleteIndex) {
                    $previuosNamesHash+=$RmAPI.VariableStr("Name$i")
                    $previuosPatternsHash+=$RmAPI.VariableStr("Pattern$i")
                    $previuosMatchActionsHash+=$RmAPI.VariableStr("MatchAction$i")
                }else{
                    $RmAPI.Log("Delete index $deleteIndex not added")
                }
            }    
        }
        drop {
            for ($i=1; $i -lt $addCount; $i++) {
                $previuosNamesHash+=if($RmAPI.VariableStr("Name$i")){$RmAPI.VariableStr("Name$i")}else{''}
                $previuosPatternsHash+=if($RmAPI.VariableStr("Pattern$i")){$RmAPI.VariableStr("Pattern$i")}else{''}
                $previuosMatchActionsHash+=if($RmAPI.VariableStr("MatchAction$i")){$RmAPI.VariableStr("MatchAction$i")}else{''}
            }
            $previuosNamesHash+=$RmAPI.VariableStr('DropFile')
            $previuosMatchActionsHash+=$('["'+$RmAPI.VariableStr('DropLocation')+'"]')
        }
    }

    $RmAPI.Log('Creating new variables...')

    for ($i=1; $i -lt $addCount+1; $i++) {

        $nameVariables+=@"

Name$i=$(if($previuosNamesHash[$i]){$previuosNamesHash[$i]}else{""})
"@
        $patternVariables+=@"

Pattern$i=$(if($previuosPatternsHash[$i]){$previuosPatternsHash[$i]}else{""})
"@
        $matchActionVariables+=@"

MatchAction$i=$(if($previuosMatchActionsHash[$i]){$previuosMatchActionsHash[$i]}else{""})
"@

    }
    $RmAPI.Log('Done!')
    $nameVariables | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Variables\Names.inc') -Encoding utf8
    $patternVariables | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Variables\Patterns.inc') -Encoding utf8
    $matchActionVariables | Out-File -FilePath $($RmAPI.VariableStr('@') + 'Variables\MatchActions.inc') -Encoding utf8
    switch ($process) {
        {$_ -in "add","drop"} {
            $RmAPI.Bang("!WriteKeyValue Variables ScrollAutoBool `"0`"")
        }
    }
}
function AddPattern {
    $currentIndex=$RmAPI.Variable('Index')

    $indexCount=$RmAPI.Variable('NumberOfIndices')

    $inducedPattern=$RmAPI.Variable('InducedPattern')

    $patternArray=@("$($RmAPI.Variable('Pattern1'))")

    for ($i=2; $i -lt $indexCount+1; $i++) {
        if($i -ne $currentIndex) {
            $patternArray+=$RmAPI.VariableStr("Pattern$i")
        }else{
            $RmAPI.Log('Skipped current pattern!')
        }
    }

    if ($patternArray -notcontains $inducedPattern) {
        $RmAPI.Bang("!WriteKeyValue Variables Pattern$currentIndex `"$inducedPattern`" `"$($RmAPI.VariableStr('@')+'Variables\Patterns.inc')`"")
        $RmAPI.Bang('!ActivateConfig "Combilaunch\@Settings" "Actions.ini"')
    }else{
        $RmAPI.Bang('[!SetOption S Text "Pattern exists!"][!SetOption S FontColor FF0000][!UpdateMeter S][!Redraw]')
        Start-Sleep -Milliseconds 500
        $RmAPI.Bang('!Refresh')
    }
}