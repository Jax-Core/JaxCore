function Wait-ForProcess
{
    param
    (
        $Name = 'notepad',

        [Switch]
        $IgnoreAlreadyRunningProcesses
    )

    if ($IgnoreAlreadyRunningProcesses)
    {
        $NumberOfProcesses = (Get-Process -Name $Name -ErrorAction SilentlyContinue).Count
    }
    else
    {
        $NumberOfProcesses = 0
    }


    Write-Host "Waiting for $Name" -NoNewline
    while ( (Get-Process -Name $Name -ErrorAction SilentlyContinue).Count -eq $NumberOfProcesses )
    {
        Write-Host '.' -NoNewline
        Start-Sleep -Milliseconds 400
    }

    Write-Host ''
}

$scriptpath = $MyInvocation.MyCommand.Path
$scriptdir = Split-Path $scriptpath

$RMPATH = Get-Content "$scriptdir\RainmeterPath.txt"
$RMPROCESS = Get-Process 'Rainmeter' -ErrorAction SilentlyContinue

If ($RMPROCESS) {
    Write-Host "Process exist"
    & $RMPATH [!DeactivateConfig \#JaxCore\Main][!ActivateConfig \#JaxCore\Main Home.ini]
} else {
    Write-Host "Process not exist, starting"
    & "$RMPATH"
    Wait-ForProcess 'Rainmeter'
    Write-Host "Process started"
    Start-Sleep 1
    & $RMPATH [!DeactivateConfig \#JaxCore\Main][!ActivateConfig \#JaxCore\Main Home.ini]
}
Write-Host "Done"