$SkinsPath = $RmAPI.VariableStr('SKINSPATH')

function Update {}

function Create-IdleStyle {
    New-Item -Path "$SkinsPath..\CoreData" -Name "IdleStyle" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\IdleStyle" -Name "Include.inc" -ItemType "file"
    $RmAPI.Log("Created: IdleStyle")
    
}

function Create-Keylaunch {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Keylaunch" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Keylaunch.ahk" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Include.inc" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "IconCache" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch\IconCache" -Name "folder.png" -ItemType "file"
    $RmAPI.Log("Created: Keylaunch")
}
function Create-Updater {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Updater" -ItemType "directory"
    Copy-Item -Path "$SkinsPath\#JaxCore\@Resources\Actions\*" -Destination "$SkinsPath..\CoreData\Updater" -PassThru
    $RmAPI.Log("Created: Updater")
}

function Create-ValliStart {
    New-Item -Path "$SkinsPath..\CoreData" -Name "ValliStart" -ItemType "directory"
    $RainmeterFolder = Split-Path -Path $SkinsPath -Parent

    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut("$SkinsPath..\CoreData\ValliStart\Config.lnk")
    $Shortcut.TargetPath = "$RainmeterFolder\CoreData\ValliStart"
    $shortcut.IconLocation = $ResourceFolder+"Images\Add.ico"
    $Shortcut.Save()

    
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut("$SkinsPath..\CoreData\ValliStart\JaxCore.lnk")
    $Shortcut.TargetPath = $RainmeterExe+"Rainmeter.exe"
    $Shortcut.Arguments = '!ActivateConfig #JaxCore\Main Home.ini'
    $shortcut.IconLocation = $ResourceFolder+"Images\Logo.ico"
    $Shortcut.Save()

    $RmAPI.Log("Created: ValliStart")
}

function Create-Combilaunch {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Combilaunch" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Combilaunch" -Name "Include.inc" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Combilaunch" -Name "Actions.inc" -ItemType "file"
    $RmAPI.Log("Created: Combilaunch")
}

function Create-VarInc {
    $source      = $RmAPI.VariableStr('SKINSPATH')
    $destination = Split-Path -Path $source -Parent
    New-Item -Path "$SkinsPath..\CoreData" -Name "Vars.inc" -ItemType "file" -Value "[Variables]`nRAINMETERPATH=$destination"
}

function Check-Data {
    If (Test-Path -Path "$SkinsPath..\CoreData") {
            $RmAPI.Log("Found coredata in programs")
        } else {
            $RmAPI.Log("Failed to find coredata in programs, generating")
            New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
            $RmAPI.Bang("!Refresh")
        }
    If (Test-Path -Path "$SkinsPath..\CoreData\Keylaunch\IconCache") {
    } else {
        Create-Keylaunch
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\IdleStyle") {
    } else {
        Create-IdleStyle
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\ValliStart") {
    } else {
        Create-ValliStart
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\Combilaunch") {
    } else {
        Create-Combilaunch
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\Updater") {
    } else {
        Create-Updater
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\Vars.inc") {
    } else {
        Create-VarInc
    }
}