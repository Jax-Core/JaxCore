# ----------------------------- Terminal outputs ----------------------------- #
# Helper functions edited from spicetify cli ps1 installer (https://github.com/spicetify/spicetify-cli/blob/master/install.ps1)
function Write-Part ([string] $Text) {
  Write-Host $Text -NoNewline
}

function Write-Emphasized ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Cyan"
}

function Write-Error ([string] $Text) {
  Write-Host $Text -ForegroundColor "Red"
}

function Write-Done {
  Write-Host " > " -NoNewline
  Write-Host "OK" -ForegroundColor "Green"
}

function Write-Info ([string] $Text) {
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

# --------------------------------- Download --------------------------------- #
function DownloadFile($url, $targetFile)

{
   $uri = New-Object "System.Uri" "$url"
   $request = [System.Net.HttpWebRequest]::Create($uri)
   $request.set_Timeout(15000) #15 second timeout
   $response = $request.GetResponse()
   $totalLength = [System.Math]::Floor($response.get_ContentLength()/1024)
   $responseStream = $response.GetResponseStream()
   $targetStream = New-Object -TypeName System.IO.FileStream -ArgumentList $targetFile, Create
   $buffer = new-object byte[] 1000KB
   $count = $responseStream.Read($buffer,0,$buffer.length)
   $downloadedBytes = $count
   while ($count -gt 0)
   {
       $targetStream.Write($buffer, 0, $count)
       $count = $responseStream.Read($buffer,0,$buffer.length)
       $downloadedBytes = $downloadedBytes + $count
       Write-Progress -activity "Downloading file '$($url.split('/') | Select -Last 1)'" -status "Downloaded ($([System.Math]::Floor($downloadedBytes/1024))K of $($totalLength)K): " -PercentComplete ((([System.Math]::Floor($downloadedBytes/1024)) / $totalLength)  * 100)
   }
   Write-Progress -activity "Finished downloading file '$($url.split('/') | Select -Last 1)'"
   $targetStream.Flush()
   $targetStream.Close()
   $targetStream.Dispose()
   $responseStream.Dispose()
}

# ---------------------------------- Install --------------------------------- #

function Install-Skin() {
    $api_url = 'https://api.github.com/repos/Jax-Core/' + $skinName + '/releases'
    $api_object = Invoke-WebRequest -Uri $api_url -UseBasicParsing | ConvertFrom-Json
    $dl_url = $api_object.assets.browser_download_url[0]
    $outpath = "$env:temp\$($skinName)_$($api_object.tag_name[0]).rmskin"
    Write-Part "Downloading    "; Write-Emphasized $dl_url; Write-Part " -> "; Write-Emphasized $outpath
    downloadFile "$dl_url" "$outpath"
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
    Wait-Process "SkinInstaller"
    If ($skinName -contains "JaxCore") {
      $skinFolder = "#JaxCore"
    } else {
      $skinFolder = $skinName
    }
    If (Test-Path -Path "$([Environment]::GetFolderPath("MyDocuments"))\Rainmeter\Skins\$skinFolder") {
      Write-Emphasized "$skinName is installed successfully. "; Write-Part "Follow the instructions in the pop-up window."
    } else {
      Write-Error "Failed to install $skinName! "; Write-Part "Please contact support or try again."
      Break
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
  Write-Part "Downloading    "; Write-Emphasized $dl_url; Write-Part " -> "; Write-Emphasized $outpath
  # Invoke-WebRequest $dl_url -OutFile $outpath
  downloadFile "$dl_url" "$outpath"
  Write-Done
  # ------------------------------------ Run ----------------------------------- #
  Write-Part "Running installer   "; Write-Emphasized $outpath
  Start-Process -FilePath $outpath -ArgumentList "/S /AUTOSTARTUP=1 /RESTART=0" -Wait
  Write-Done
  # ---------------------------- Check if installed ---------------------------- #
  Write-Part "Checking "; Write-Emphasized "$Env:Programfiles\Rainmeter\Rainmeter.exe"; Write-Part " for Rainmeter.exe"
  If (Test-Path -Path "$Env:Programfiles\Rainmeter\Rainmeter.exe") {
    Write-Done
  } else {
    Write-Error "Failed to install Rainmeter! "; Write-Part "Make sure you have selected `"Yes`" when installation dialog pops up"
    Break
  }
  # --------------------------------- Generate --------------------------------- #
  Write-Part "Generating "; Write-Emphasized "Rainmeter.ini "; Write-Part "for the first time..."
  New-Item -Path "$env:APPDATA\Rainmeter" -Name "Rainmeter.ini" -ItemType "file" -Force -Value @"
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
    Install-Skin
}