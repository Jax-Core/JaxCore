$skinName = 'ModularPlayers'

function Check_Program_Installed( $programName ) {
$x86_check = ((Get-ChildItem "HKLM:Software\Microsoft\Windows\CurrentVersion\Uninstall") |
Where-Object { $_."Name" -like "*$programName*" } ).Length -gt 0;
  
if(Test-Path 'HKLM:Software\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall')  
{
$x64_check = ((Get-ChildItem "HKLM:Software\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall") |
Where-Object { $_."Name" -like "*$programName*" } ).Length -gt 0;
}
return $x86_check -or $x64_check;
}


function Install_Skin() {
    $api_url = 'https://api.github.com/repos/Jax-Core/' + $skinName + '/releases'
    $api_object = Invoke-WebRequest -Uri $api_url -UseBasicParsing | ConvertFrom-Json
    $dl_url = $api_object.assets.browser_download_url[0]
    $outpath = "$env:temp\$($skinName)_$($api_object.tag_name[0]).rmskin"
    Invoke-WebRequest $dl_url -OutFile $outpath
    Start-Process -FilePath $outpath
    If ($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell = New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1.5
        $wshell.SendKeys('{ENTER}')
    }
    Exit
}

if (Check_Program_Installed("Rainmeter")) {
    Install_Skin
} else {
    winget install Rainmeter
    Start-Sleep 1s
    Install_Skin
}