param (
  [string] $skinName
)

# --------------- if $installSkin variable is defined, use that -------------- #
if ($installSkin) {
    $skinName = $installSkin
} else {
    $skinName = "JaxCore"
}

# ----------------------------- Terminal outputs ----------------------------- #

function Write-Part ([string] $Text) {
  Write-Host $Text -NoNewline
}

function Write-Emphasized ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Cyan"
}

function Write-Success ([string] $Text) {
  Write-Host " > " -NoNewline
  Write-Host $Text -ForegroundColor "Green"
}

function Write-Info ([string] $Text) {
  Write-Host " > " -NoNewline
  Write-Host $Text -ForegroundColor "Yellow"
}

# -------------------------- Check program installed ------------------------- #

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

# ---------------------------------- Install --------------------------------- #

function Install_Skin() {
    $api_url = 'https://api.github.com/repos/Jax-Core/' + $skinName + '/releases'
    $api_object = Invoke-WebRequest -Uri $api_url -UseBasicParsing | ConvertFrom-Json
    $dl_url = $api_object.assets.browser_download_url[0]
    $outpath = "$env:temp\$($skinName)_$($api_object.tag_name[0]).rmskin"
    Invoke-WebRequest $dl_url -OutFile $outpath
    Write-Part "DOWNLOADING    "; Write-Emphasized $dl_url; Write-path "    to    "; Write-Emphasized $outpath
    Start-Process -FilePath $outpath
    If ($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell = New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1.5
        $wshell.SendKeys('{ENTER}')
    }
    # Exit
}

# ----------------------------------- Logic ---------------------------------- #

if (Check_Program_Installed("Rainmeter")) {
    Write-Success Rainmeter is installed, installing $skinName
    Install_Skin
} else {
    Write-Info Rainmeter is not installed, installing Rainmeter via winget
    winget install Rainmeter
    Start-Sleep 1s
    Write-Success Installed Rainmeter. Installing $skinName
    Install_Skin
}