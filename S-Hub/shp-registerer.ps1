param(
    [Parameter(Mandatory=$true)][Alias("corepath")][ValidateNotNullOrEmpty()][string]$o_RMSkinFolder,
    [Parameter(Mandatory=$true)][Alias("rmpath")][ValidateNotNullOrEmpty()][string]$o_RMSettingsFolder,
    [switch]$Elevated
) 
# ------------------------------- Run as admin ------------------------------- #
function Test-Admin {
    $currentUser = New-Object Security.Principal.WindowsPrincipal $([Security.Principal.WindowsIdentity]::GetCurrent())
    $currentUser.IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
}

if ((Test-Admin) -eq $false)  {
    if ($elevated) {
        # tried to elevate, did not work, aborting
    } else {
        Start-Process powershell.exe -Verb RunAs -ArgumentList ("-noprofile -file `"{0}`" -corepath `"$o_RMSkinFolder`" -rmpath `"$o_RMSettingsFolder`" -elevated" -f ($myinvocation.MyCommand.Definition))
    }
    exit
}
# --------------------------------- Variables -------------------------------- #
$root = "hkcr:\HKEY_CLASSES_ROOT\"
$name = "shubpackage"
# --------------------------- Make PSDrive if none --------------------------- #
If (!(Test-Path HKCR:)) {New-PSDrive -Name HKCR -PSProvider Registry -Root HKEY_CLASSES_ROOT -Scope Global}
$set = $false
If (!(Test-Path "$root\$name")) {
    'Registry structure not created, generating...'
    New-Item -Path "$root" -Name '.shp'
    New-Item -Path "$root" -Name $name
    New-Item -Path "$root\$name" -Name 'DefaultIcon'
    New-Item -Path "$root\$name" -Name 'Shell'
    New-Item -Path "$root\$name\Shell" -Name 'Open'
    New-Item -Path "$root\$name\Shell\Open" -Name 'Command'
    $set = $true
} else {
    'Registry structure already created.'
    $confirmation = Read-Host "Do you want re-set properties? (y/n)"
    if ($confirmation -match '^y$') {
        $set = $true
    }
}
If ($set) {
    'Setting properties...'
    Set-ItemProperty -Path "$root\.shp" -Name '(Default)' -Value $name
    Set-ItemProperty -Path "$root\$name" -Name '(Default)' -Value "S-Hub Package"
    Set-ItemProperty -Path "$root\$name\DefaultIcon" -Name '(Default)' -Value "$o_RMSkinFolder\#JaxCore\@Resources\Images\SHP.ico"
    Set-ItemProperty -Path "$root\$name\Shell" -Name '(Default)' -Value 'open'
    Set-ItemProperty -Path "$root\$name\Shell\Open\Command" -Name '(Default)' -Value "powershell.exe -ExecutionPolicy Bypass -File `"$($o_RMSkinFolder)\#JaxCore\S-Hub\shp-extractor.ps1`" `"%1`""
    'Restarting explorer...'
    taskkill /f /im explorer.exe
    start-process explorer.exe
}

# ----------------------------------- Close ---------------------------------- #
'Generating SHP Path File'
If (Test-Path 'C:\RMInstallation.txt') {Remove-Item 'C:\RMInstallation.txt' -Force > $null}
New-Item -Path 'C:\RMInstallation.txt' -Type "File" -Value "$o_RMSettingsFolder" -Force > $null
Get-Item 'C:\RMInstallation.txt' -Force | foreach { $_.Attributes = $_.Attributes -bor "Hidden" }
Exit