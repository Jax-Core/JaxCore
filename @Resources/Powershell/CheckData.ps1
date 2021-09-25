$SkinsPath = $RmAPI.VariableStr('SKINSPATH')

function Update {}

function Create-Keylaunch {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Keylaunch" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Keylaunch.ahk" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Include.inc" -ItemType "file"
    $RmAPI.Log("Created: Keylaunch")
}
function Create-Updater {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Updater" -ItemType "directory"
    Copy-Item -Path "$SkinsPath\#JaxCore\@Resources\Actions\*" -Destination "$SkinsPath..\CoreData\Updater" -PassThru
    $RmAPI.Log("Created: Updater")
}

function Create-ValliStart {
    New-Item -Path "$SkinsPath..\CoreData" -Name "ValliStart" -ItemType "directory"
    # New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "IncludeInCore.inc" -ItemType "file"
    # New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "IncludeInSkin.inc" -ItemType "file"
    $RmAPI.Log("Created: ValliStart")
}

function Create-VarInc {
    $source      = $RmAPI.VariableStr('SKINSPATH')
    $destination = Split-Path -Path $source -Parent
    New-Item -Path "$SkinsPath..\CoreData" -Name "Vars.inc" -ItemType "file" -Value "[Variables]`nRAINMETERPATH=$destination"
}

function Check-Data {
    If (Test-Path -Path "$SkinsPath..\CoreData") {
            $RmAPI.Log("Found coredata in programs")
            If (Test-Path -Path "$SkinsPath..\CoreData\Keylaunch") {
            } else {
                Create-Keylaunch
            }
            If (Test-Path -Path "$SkinsPath..\CoreData\ValliStart") {
            } else {
                Create-ValliStart
            }
            If (Test-Path -Path "$SkinsPath..\CoreData\Updater") {
            } else {
                Create-Updater
            }
            If (Test-Path -Path "$SkinsPath..\CoreData\Vars.inc") {
            } else {
                Create-VarInc
            }
        } else {
            $RmAPI.Log("Failed to find coredata in programs, generating")
            New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
            Create-Keylaunch
            Create-Updater
            $RmAPI.Bang("!Refresh")
        }
}