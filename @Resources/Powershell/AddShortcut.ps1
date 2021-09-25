$DesktopPath = [Environment]::GetFolderPath("Desktop")
$Startpath = $env:APPDATA

function Check {
    If (Test-Path -Path "$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk") {
        $RmAPI.Bang('[!SetOption WhatsNew: MeterStyle "BottomBox:S | TrueStyleProg"]')
        $RmAPI.Bang('[!UpdateMeter WhatsNew:]')
        $RmAPI.Bang('[!Redraw]')
        $RmAPI.Log("Found: CoreHome in programs")
    } else {
        $RmAPI.Log("Failed to find corehome in programs")
    }
    If (Test-Path -Path "$DesktopPath\JaxCore.lnk") {
        $RmAPI.Bang('[!SetOption Jax: MeterStyle "BottomBox:S | TrueStyleDesk"]')
        $RmAPI.Bang('[!UpdateMeter Jax:]')
        $RmAPI.Bang('[!Redraw]')
        $RmAPI.Log("Found: CoreHome on desktop")
    } else {
        $RmAPI.Log("Failed to find corehome on desktop")
    }

}

function Desktop {
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut("$DesktopPath\JaxCore.lnk")
    $Shortcut.TargetPath = $RainmeterExe+"Rainmeter.exe"
    $Shortcut.Arguments = '!ActivateConfig #JaxCore\Main Home.ini'
    $shortcut.IconLocation = $ResourceFolder+"Images\Logo.ico"
    $Shortcut.Save()
}

function StartFolder {
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut("$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk")
    $Shortcut.TargetPath = $RainmeterExe+"Rainmeter.exe"
    $Shortcut.Arguments = '!ActivateConfig #JaxCore\Main Home.ini'
    $shortcut.IconLocation = $ResourceFolder+"Images\Logo.ico"
    $Shortcut.Save()
}

function RemoveDeskop {
    Remove-Item "$DesktopPath\JaxCore.lnk" -Recurse
}

function RemoveStartFolder {
    Remove-Item "$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk" -Recurse
}
