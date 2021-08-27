$DesktopPath = [Environment]::GetFolderPath("Desktop")
$Startpath = $env:APPDATA

function Check {
    If (Test-Path -Path "$Startpath\Microsoft\Windows\Start Menu\Programs\#CoreHome.lnk") {
        $RmAPI.Bang('[!SetOption WhatsNew: MeterStyle "BottomBox:S | TrueStyleProg"]')
        $RmAPI.Bang('[!UpdateMeter WhatsNew:]')
        $RmAPI.Bang('[!Redraw]')
        $RmAPI.Log("Found: CoreHome in programs")
    } else {
        $RmAPI.Log("Failed to find corehome in programs")
    }
    If (Test-Path -Path "$DesktopPath\#CoreHome.lnk") {
        $RmAPI.Bang('[!SetOption Jax: MeterStyle "BottomBox:S | TrueStyleDesk"]')
        $RmAPI.Bang('[!UpdateMeter Jax:]')
        $RmAPI.Bang('[!Redraw]')
        $RmAPI.Log("Found: CoreHome on desktop")
    } else {
        $RmAPI.Log("Failed to find corehome on desktop")
    }

}

function Desktop {
    Copy-Item -Path "../../Accessories/Shortcut/#CoreHome.lnk" -Destination "$DesktopPath"
}

function StartFolder {
    Copy-Item -Path "../../Accessories/Shortcut/#CoreHome.lnk" -Destination "$Startpath\Microsoft\Windows\Start Menu\Programs"
}

function RemoveDeskop {
    Remove-Item "$DesktopPath\#CoreHome.lnk" -Recurse
}

function RemoveStartFolder {
    Remove-Item "$Startpath\Microsoft\Windows\Start Menu\Programs\#CoreHome.lnk" -Recurse
}
