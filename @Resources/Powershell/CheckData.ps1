$SkinsPath = $RmAPI.VariableStr('SKINSPATH')

If (Test-Path -Path "$SkinsPath..\CoreData") {
        $RmAPI.Log("Found coredata in programs")
    } else {
        $RmAPI.Log("Failed to find coredata in programs, generating")
        New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
        New-Item -Path "$SkinsPath..\CoreData" -Name "Keylaunch" -ItemType "directory"
        New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Keylaunch.ahk" -ItemType "file"
        New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Include.inc" -ItemType "file"
        $RmAPI.Bang("!Refresh")
    }