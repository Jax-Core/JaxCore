param(
    [Parameter(Mandatory)]
    [string]
    $coreInstallerPath,
    [Parameter(Mandatory)]
    [string]
    $togglePath,
    [Parameter()]
    [string]
    $Uninstall = 'F'
)

if ($Uninstall -eq 'F') {
    if (-not ((Test-Path $coreInstallerPath) -or ($coreInstallerPath -imatch "\.exe$"))) {
        Write-Error -Message "CoreInstaller path invalid"
        Start-Sleep -Seconds 5
        return
    }
}

# Add HKCR drive
Write-Host "> Adding HKCR drive ..."
Write-Host ""
New-PSDrive -PSProvider registry -Root HKEY_CLASSES_ROOT -Name HKCR | Out-Null

# remove entry if existing
try {
    Write-Host "> Looking for previous entries ..."
    Write-Host ""
    Remove-Item "HKCR:\rm-coreinstaller" -Force -Recurse -ErrorAction Stop | Out-Null
    Write-Host "> Removed previous entry ..."
    Write-Host ""
}
catch {
    Write-Host "> No previous entries found ..."
    Write-Host ""
}

if ($Uninstall -eq 'T') {
    @"
[Variables]
WebInstallation = 0
"@ | Out-File -FilePath $togglePath -Force -Encoding ascii
    Exit-PSSession
}

Write-Host "> Creating new CoreInstaller entry ..."
Write-Host ""
New-Item "HKCR:\rm-coreinstaller" | Out-Null
Write-Host "> Adding URL Protocol ..."
Write-Host ""
New-ItemProperty "HKCR:\rm-coreinstaller" -Name "URL Protocol" -Value "" -Type String | Out-Null
Write-Host "> Adding shell execution options ..."
Write-Host ""
New-Item "HKCR:\rm-coreinstaller\shell" | Out-Null
New-Item "HKCR:\rm-coreinstaller\shell\open" | Out-Null
New-Item "HKCR:\rm-coreinstaller\shell\open\command" | Out-Null
New-ItemProperty "HKCR:\rm-coreinstaller\shell\open\command" -Name "(default)" -Value "`"$coreInstallerPath`" `"%1`"" | Out-Null


@"
[Variables]
WebInstallation = 1
"@ | Out-File -FilePath $togglePath -Force -Encoding ascii

Write-Host Done -ForegroundColor Green

Start-Sleep -Seconds 1

Exit-PSSession