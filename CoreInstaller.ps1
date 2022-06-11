# ----------------------------- Terminal outputs ----------------------------- #
# Helper functions edited from spicetify cli ps1 installer (https://github.com/spicetify/spicetify-cli/blob/master/install.ps1)
function Write-Part ([string] $Text) {
  Write-Host $Text -NoNewline
}

function Write-Emphasized ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Cyan"
}

function Write-Error ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Red"
}

function Write-Done {
  Write-Host " > " -NoNewline
  Write-Host "OK" -ForegroundColor "Green"
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

function Install-Skin() {
    $api_url = 'https://api.github.com/repos/Jax-Core/' + $skinName + '/releases'
    $api_object = Invoke-WebRequest -Uri $api_url -UseBasicParsing | ConvertFrom-Json
    $dl_url = $api_object.assets.browser_download_url[0]
    $outpath = "$env:temp\$($skinName)_$($api_object.tag_name[0]).rmskin"
    Write-Part "DOWNLOADING    "; Write-Emphasized $dl_url; Write-Part " -> "; Write-Emphasized $outpath
    Invoke-WebRequest $dl_url -OutFile $outpath
    Write-Done
    Write-Part "Running installer   "; Write-Emphasized $outpath
    Start-Process -FilePath $outpath
    If ($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell = New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1.5
        $wshell.SendKeys('{ENTER}')
    }
    Write-Done
    If (Test-Path -Path "$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk") {
      Write-Emphasized "$skinName is installed successfully. "; Write-Part "Follow the instructions in the pop-up window."
    } else {
      Write-Error "Failed to install $skinName"; Write-Part "Please contact support or try again."
    }
}

# ----------------------------------- Logic ---------------------------------- #

param (
  [string] $skinName
)

if ($installSkin) {
    $skinName = $installSkin
} else {
    $skinName = "JaxCore"
}

Write-Part "Checking if Rainmeter is installed"

if (Check_Program_Installed("Rainmeter")) {
  Write-Done
  Install-Skin
} else {
  # ----------------------------------- Fetch ---------------------------------- #
  Write-Info "Rainmeter is not installed, installing Rainmeter"
  $api_url = 'https://api.github.com/repos/rainmeter/rainmeter/releases'
  $api_object = Invoke-WebRequest -Uri $api_url -UseBasicParsing | ConvertFrom-Json
  $dl_url = $api_object.assets.browser_download_url[0]
  $outpath = "$env:temp\RainmeterInstaller.exe"
  # --------------------------------- Download --------------------------------- #
  Write-Part "DOWNLOADING    "; Write-Emphasized $dl_url; Write-Part " -> "; Write-Emphasized $outpath
  Invoke-WebRequest $dl_url -OutFile $outpath
  Write-Done
  # ------------------------------------ Run ----------------------------------- #
  Write-Part "Running installer   "; Write-Emphasized $outpath
  Start-Process -FilePath $outpath -ArgumentList "/S /AUTOSTARTUP=1 /RESTART=0" -Wait
  Write-Done
  # --------------------------------- Generate --------------------------------- #
  Write-Part "Generating "; Write-Emphasized "Rainmeter.ini "; Write-Part "for the first time..."
  New-Item -Path "$env:APPDATA\Rainmeter" -Name "Rainmeter.ini" -ItemType "file" -Value @" -Force
[Rainmeter]
Logging=0
SkinPath=$([Environment]::GetFolderPath("MyDocuments"))\Rainmeter\Skins\
HardwareAcceleration=0

[illustro\Clock]
Active=0
[illustro\Disk]
Active=0
[illustro\System]
Active=0

"@
    Write-Done
    # ---------------------------------- Install --------------------------------- #
    # Install-Skin
}