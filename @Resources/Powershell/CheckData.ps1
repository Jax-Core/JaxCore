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

function Check-Data {
    If (Test-Path -Path "$SkinsPath..\CoreData") {
            $RmAPI.Log("Found coredata in programs")
            If (Test-Path -Path "$SkinsPath..\CoreData\Keylaunch") {
            } else {
                Create-Keylaunch
            }
            If (Test-Path -Path "$SkinsPath..\CoreData\Updater") {
            } else {
                Create-Updater
            }
        } else {
            $RmAPI.Log("Failed to find coredata in programs, generating")
            New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
            Create-Keylaunch
            Create-Updater
            $RmAPI.Bang("!Refresh")
        }
}