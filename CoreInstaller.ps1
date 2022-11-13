# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

# Write-Host

function Write-Task ([string] $Text) {
  Write-Host $Text -NoNewline
}

function Write-Done {
  Write-Host " > " -NoNewline
  Write-Host "OK" -ForegroundColor "Green"
}

function Write-Emphasized ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Cyan"
}

function Write-Info ([string] $Text) {
  Write-Host $Text -ForegroundColor "Yellow"
}

function Write-Fail ([string] $Text) {
  Write-Host $Text -ForegroundColor "Red"
}

function Write-Divider ([string] $Text) {
    Write-Host "[$Text]>+============================================+<[$Text]" -BackgroundColor "DarkGray"
}

function debug ([string] $Text) {
  Write-Verbose "$Text"
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

# ------------------------------------ Ini ----------------------------------- #

function Get-IniContent ($filePath) {
    $ini = [ordered]@{}
    if (![System.IO.File]::Exists($filePath)) {
        throw "$filePath invalid"
    }
    $section = ';ItIsNotAFuckingSection;'
    $ini.Add($section, [ordered]@{})

    foreach ($line in [System.IO.File]::ReadLines($filePath)) {
        if ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            $secDup = 1
            while ($ini.Keys -contains $section) {
                $section = $section + '||ps' + $secDup
            }
            $ini.Add($section, [ordered]@{})
        }
        elseif ($line -match "^\s*;.*$") {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $matches[1]
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            $ini[$section][$key] = $value
        }
        else {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $line
        }
    }

    return $ini
}

function Get-RemoteIniContent ($link) {
    $ini = [ordered]@{}

    $result = Invoke-WebRequest -useb $link
    $section = ';ItIsNotAFuckingSection;'
    $ini.Add($section, [ordered]@{})

    foreach ($line in $($result.Content -split "`n")) {
        if ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            $secDup = 1
            while ($ini.Keys -contains $section) {
                $section = $section + '||ps' + $secDup
            }
            $ini.Add($section, [ordered]@{})
        }
        elseif ($line -match "^\s*;.*$") {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $matches[1]
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            $ini[$section][$key] = $value
        }
        else {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $line
        }
    }

    return $ini
}

function Set-IniContent($ini, $filePath) {
    $str = @()
    foreach ($section in $ini.GetEnumerator()) {
        if ($section -ne ';ItIsNotAFuckingSection;') {
            $str += "[" + ($section.Key -replace '\|\|ps\d+$', '') + "]"
        }
        foreach ($keyvaluepair in $section.Value.GetEnumerator()) {
            if ($keyvaluepair.Key -match "^;NotSection\d+$") {
                $str += $keyvaluepair.Value
            }
            else {
                $str += $keyvaluepair.Key + "=" + $keyvaluepair.Value
            }
        }
    }
    $finalStr = $str -join [System.Environment]::NewLine
    $finalStr | Out-File -filePath $filePath -Force -Encoding unicode
}

function Wait-ForProcess
{
    param
    (
        $Name = 'notepad',
        [Switch]
        $IgnoreAlreadyRunningProcesses
    )
    if ($IgnoreAlreadyRunningProcesses)
    {        $NumberOfProcesses = (Get-Process -Name $Name -ErrorAction SilentlyContinue).Count    }
    else
    {        $NumberOfProcesses = 0    }
    Write-Host "Waiting for $Name" -NoNewline
    while ( (Get-Process -Name $Name -ErrorAction SilentlyContinue).Count -eq $NumberOfProcesses )
    {
        Write-Host '.' -NoNewline
        Start-Sleep -Milliseconds 400
    }
    Write-Done
}

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

function Get-Folder($initialDirectory="") {
    [System.Reflection.Assembly]::LoadWithPartialName("System.windows.forms")|Out-Null

    $foldername = New-Object System.Windows.Forms.FolderBrowserDialog
    $foldername.Description = "Select a folder"
    $foldername.rootfolder = "MyComputer"
    $foldername.SelectedPath = $initialDirectory

    if($foldername.ShowDialog() -eq "OK")
    {
        $folder += $foldername.SelectedPath
    }
    return $folder
}

# ---------------------------------------------------------------------------- #
#                             Installation modules                             #
# ---------------------------------------------------------------------------- #

function Set-DPICompatability {
    REG ADD "HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers" /V "$RMEXEloc" /T REG_SZ /D ~HIGHDPIAWARE /F
}

function Download-Rainmeter($params) {
    # ----------------------------------- Fetch ---------------------------------- #
    Write-Info "Rainmeter is not installed, installing Rainmeter"
    $githubRMReleaseAPIObject = Invoke-WebRequest -Uri 'https://api.github.com/repos/rainmeter/rainmeter/releases' -UseBasicParsing | ConvertFrom-Json
    $githubRMDownloadURL = $githubRMReleaseAPIObject.assets.browser_download_url[0]
    $githubRMDownloadOutpath = "$env:temp\RainmeterInstaller.exe"
    # --------------------------------- Download --------------------------------- #
    Write-Task "Downloading    "; Write-Emphasized $githubRMDownloadURL
    Invoke-WebRequest "$githubRMDownloadURL" -outfile "$githubRMDownloadOutpath" -UseBasicParsing
    Write-Done
    # ------------------------------------ Run ----------------------------------- #
    Write-Task "Running installer..."
    Start-Process -FilePath (Get-Item -LiteralPath "$env:temp\RainmeterInstaller.exe").FullName -ArgumentList "$params" -Wait
    Write-Done
    # ---------------------------- Check if installed ---------------------------- #
    Write-Task "Checking "; Write-Emphasized "$RMEXEloc"; Write-Task " for Rainmeter.exe"
    If (Test-Path -Path "$RMEXEloc") {
        Write-Done
        Set-DPICompatability
    } else {
        throw "`nFailed to install Rainmeter! (Did not complete UAC)"
    }
    # --------------------------------- Generate --------------------------------- #
    Write-Task "Generating "; Write-Emphasized "Rainmeter.ini "; Write-Task "for the first time..."
    New-Item -Path "$s_RMSettingsFolder" -Name "Rainmeter.ini" -ItemType "file" -Force -Value @"
[Rainmeter]
Logging=0
SkinPath=$s_RMSkinFolder
HardwareAcceleration=1

[illustro\Clock]
Active=0
[illustro\Disk]
Active=0
[illustro\System]
Active=0

"@
    Write-Done
    If (Test-Path "$env:APPDATA\JaxCore\InstalledComponents\") {
        Get-ChildItem -Path "$env:APPDATA\JaxCore\" -Recurse | Remove-Item -Recurse
    }
}

# ---------------------------------------------------------------------------- #
#                             Start of installation                            #
# ---------------------------------------------------------------------------- #

# ----------------------------------- Info ----------------------------------- #
# $o - Option for installer
# $s - Installer options set by developer
# $o_InstallModule - Module to install
## $o_Version - Version to get (Number ONLY)
# $o_FromCore - If installation is invoked via JaxCore
# $o_FromSHUB - If installation is invoked via S-Hub
# $o_Force - Overwrite existing files
# $o_ExtInstall - Run .rmskin
# $o_PromptBestOption - Prompt for changing to best options
## $o_Location - Where to install Core, or where the Rainmeter folder is 
## $o_NoPostActions - Whether to do additional things after installation
# ------------------------------ Default values ------------------------------ #
if (!($o_InstallModule)) {$o_InstallModule = "JaxCore"}
if (!($o_FromCore)) {$o_FromCore = $false}
if (!($o_FromSHUB)) {$o_FromSHUB = $false}
if (!($o_Force)) {$o_Force = $false}
if (!($o_ExtInstall)) {$o_ExtInstall = $false}
if (!($o_PromptBestOption)) {
    if ($o_FromCore -or $o_Force -or $o_NoPostActions) {
        $o_PromptBestOption = $false
    } else {
        $o_PromptBestOption = $true
    }
}
# ---------------------------- Installer variables --------------------------- #
$s_InstallIsBatch = [bool]($o_InstallModule.Count -gt '1')
$s_rootDrive = (Get-WmiObject Win32_OperatingSystem).SystemDrive
$s_rootFolderName = "JaxCoreCache"
$s_root = "$($s_rootDrive)\$s_rootFolderName"
$s_unpacked = "$s_root\Unpacked"
# Declare global scope installer variables

$s_RMSettingsFolder = ""
$s_RMINIFile = ""
$s_RMSkinFolder = ""
$RMEXEloc = ""
# ----------------------------------- Start ---------------------------------- #

# Enable TLS 1.2 since it is required for connections to GitHub.
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
        
$ProgressPreference = 'SilentlyContinue'

Write-Info "COREINSTALLER REF: Stable v6"

if (!($o_Location)) {
    # ---------------------------------------------------------------------------- #
    #                             Standard installation                            #
    # ---------------------------------------------------------------------------- #
    # ---------------------------- Installer variables --------------------------- #
    $s_RMSettingsFolder = "$env:APPDATA\Rainmeter\"
    $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
    $s_RMSkinFolder = "$env:APPDATA\JaxCore\InstalledComponents\"
    # --------------------------- Check if RM installed -------------------------- #

    $RMEXEloc = "$($s_RMSettingsFolder)Rainmeter.exe"

    if (Test-Path -LiteralPath "$RMEXEloc") {
        # ------------------------------- RM installed ------------------------------- #
        debug "Rainmeter is already installed on your device."
        $wasRMInstalled = $true
        # If (Test-Path "$RMEXE32bitloc") {$RMEXEloc = "$RMEXE32bitloc"}
        If (Test-Path $s_RMINIFile) {
            $Ini = Get-IniContent $s_RMINIFile
            $s_RMSkinFolder = $Ini["Rainmeter"]["SkinPath"]
            $hwa = $Ini["Rainmeter"]["HardwareAcceleration"]
            if (($hwa -eq $null) -and ($o_PromptBestOption -eq $true)) {
                Write-Info "JaxCore recommends that the HardwareAcceleration option for Rainmeter to be turned on. "
                $confirmation = Read-Host "Turn on? (y/n)"
                if ($confirmation -match '^y$') {
                    $Ini["Rainmeter"]["HardwareAcceleration"] = "1"
                    Set-IniContent $Ini $s_RMINIFile
                }
            }
        } else {
            Write-Fail "Seems like you have Rainmeter installed but haven't ran it once on this account. Please do so and try again."
            Read-Host
            Exit
        }
    } else {
        $wasRMInstalled = $false
        
        if ($o_InstallModule -match '/') {
            $s_LargeModuleName = $o_InstallModule.Split('/')[1]
        } else {
            $s_LargeModuleName = 'JaxCore'
        }
        Write-Host "$s_LargeModuleName is not installed on your device:`n1 - Quick install (Recommended)`n2 - Install as Rainmeter application`n3 - Install at a custom location`n"
        $confirmation = Read-Host "Please select your desired installation by entering 1-3"
        if ($confirmation -match '1') {
            # # ------------------------------- Quick install ------------------------------ #
            # $s_RMSettingsFolder = "$env:APPDATA\Rainmeter\"
            # $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
            # $s_RMSkinFolder = "$env:APPDATA\JaxCore\InstalledComponents\"
            # $RMEXEloc = "$s_RMSettingsFolder\Rainmeter.exe"

            # Download-Rainmeter "/S /RESTART=0 /PORTABLE=1 /D=$s_RMSettingsFolder"
            $RMEXEloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"

            Download-Rainmeter "/S /AUTOSTARTUP=1 /RESTART=0"
            # Quick install will do a portable install once I can get JaxCore.lnk to start Rainmeter if not already running
        } elseif ($confirmation -match '2') {
            # ----------------------- Install Rainmeter application ---------------------- #
            $RMEXEloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"

            Download-Rainmeter "/S /AUTOSTARTUP=1 /RESTART=0"
        } elseif ($confirmation -match '3') {
            # --------------------- Install custom location prompted --------------------- #
            $o_Location = Get-Folder

            $s_RMSettingsFolder = "$o_Location\Rainmeter\"
            $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
            $s_RMSkinFolder = "$o_Location\JaxCore\InstalledComponents\"
            $RMEXEloc = "$s_RMSettingsFolder\Rainmeter.exe"
            
            Download-Rainmeter "/S /RESTART=0 /PORTABLE=1 /D=$s_RMSettingsFolder"
        } else {
            Write-Fail "Action cancelled. Installation terminated."
            Return
        }
    }
} else {
    # ---------------------------------------------------------------------------- #
    #                             Portable installation                            #
    # ---------------------------------------------------------------------------- #
    # ---------------------------- Installer variables --------------------------- #
    $s_RMSettingsFolder = "$o_Location\Rainmeter\"
    $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
    $s_RMSkinFolder = "$o_Location\JaxCore\InstalledComponents\"
    $RMEXEloc = "$s_RMSettingsFolder\Rainmeter.exe"
    # ------- Check if Rainmeter is already installed at provided location ------- #
    If (Test-Path "$o_Location\Rainmeter\Rainmeter.exe") {
        debug "Rainmeter is already installed under $o_Location\Rainmeter";
        $wasRMInstalled = $true
        If (Test-Path $s_RMINIFile) {
            $Ini = Get-IniContent $s_RMINIFile
            $s_RMSkinFolder = $Ini["Rainmeter"]["SkinPath"]
            If ($s_RMSkinFolder -eq $null) {
                $s_RMSkinFolder = "$($s_RMSettingsFolder)Skins\"
                $Ini["Rainmeter"]["SkinPath"] = $s_RMSkinFolder
                Set-IniContent $Ini $s_RMINIFile
            }
            $hwa = $Ini["Rainmeter"]["HardwareAcceleration"]
            if (($hwa -eq $null) -and ($o_PromptBestOption -eq $true)) {
                Write-Info "JaxCore recommends that the HardwareAcceleration option for Rainmeter to be turned on. "
                $confirmation = Read-Host "Turn on? (y/n)"
                if ($confirmation -match '^y$') {
                    $Ini["Rainmeter"]["HardwareAcceleration"] = "1"
                    Set-IniContent $Ini $s_RMINIFile
                }
            }
        }
    } else {
        Write-Host "Are you sure you want to install JaxCore at " -NoNewLine; Write-Emphasized $o_Location
        $confirmation = Read-Host "? (y/n)"
        if ($confirmation -match '^y$') {
            $wasRMInstalled = $false
            Download-Rainmeter "/S /RESTART=0 /PORTABLE=1 /D=$s_RMSettingsFolder"
        } else {
            Write-Fail "Action cancelled. Installation terminated."
            Return
        }
    }
}

# ---------------------------------------------------------------------------- #
#                      Getting info from Rainmeter process                     #
# ---------------------------------------------------------------------------- #
If (!$bit) {
    If (!(Get-Process 'Rainmeter' -ErrorAction SilentlyContinue)) {
        & "$RMEXEloc"
        Wait-ForProcess 'Rainmeter'
    }
    $rmprocess_object = Get-Process Rainmeter
    $rmprocess_id = $rmprocess_object.id
    # ------------------------------------ Bit ----------------------------------- #
    Write-Task "Getting Rainmeter bitness..."
    $bit = '32bit'
    Get-Process -Id $rmprocess_id | Foreach {
        $modules = $_.modules
        foreach($module in $modules) {
            $file = [System.IO.Path]::GetFileName($module.FileName).ToLower()
            if($file -eq "wow64.dll") {
                $bit = "32bit"
                Break
            } else {
                $bit = "64bit"
            }
        }
    }
    Write-Done
    # -------------------------- Stop running instances -------------------------- #
    If (!(Test-Path $s_RMSkinFolder)) {New-Item -Path $s_RMSkinFolder -Type "Directory" > $null}
    [System.IO.Directory]::SetCurrentDirectory($s_RMSkinFolder)

    If (Get-Process 'Rainmeter' -ErrorAction SilentlyContinue) {
        Write-Task "Ending Rainmeter & potential AHKv1 process"
        Stop-Process -Name 'Rainmeter'
        If (Get-Process 'AHKv1' -ErrorAction SilentlyContinue) {
            Stop-Process -Name 'AHKv1'
        }
        Write-Done
    }
}

# ---------------------------------------------------------------------------- #
#                                   Download                                   #
# ---------------------------------------------------------------------------- #
New-Item -Path $s_root -Type "Directory" -Force > $null
Get-Item $s_root -Force | foreach { $_.Attributes = $_.Attributes -bor "Hidden" }
Get-ChildItem "$s_root" | ForEach-Object {
    Remove-Item $_.FullName -Force -Recurse
}
# ------------------------------ Download files ------------------------------ #
Write-Task "Getting ModuleDetails from JaxCore repository"
$moduleDetails = Get-RemoteIniContent 'https://raw.githubusercontent.com/Jax-Core/JaxCore/main/S-Hub/ModuleDetails.ini'
Write-Done
foreach ($m in $o_InstallModule) {
    debug "Processing module $m"

    if ($m -match '/') {
        $org = $m.Split('/')[0]
        $m = $m.Split('/')[1]
    } else {
        $org = 'Jax-Core'
    }
    debug "Organization: $org"

    if (-not $o_Version) {
        $release_api_url = "https://api.github.com/repos/$org/$m/releases/latest"
    } else {
        $release_api_url = "https://api.github.com/repos/$org/$m/releases/tags/v$o_Version"
    }

    # 22H2 media player patch

    if (($moduleDetails[$m].Values -contains 'WindowsNowPlaying') -and ($22h2_downloaded -ne $true) -and ($([System.Environment]::OSVersion.Version.Build) -gt 22533)) {
        $22h2_downloaded = $true

        $outpath = "$s_root\zzzzzz.rmskin"
        Write-Task "Downloading 22H2 media player patch from    "; Write-Emphasized "https://github.com/Jax-Core/22H2-MediaPatch/releases/download/v1/zzzzzz.rmskin"
        Invoke-WebRequest "https://github.com/Jax-Core/22H2-MediaPatch/releases/download/v1/zzzzzz.rmskin" -outfile "$outpath" -UseBasicParsing
        Write-Done
    }

    # End End End End

    Write-Task "Downloading    "; Write-Emphasized $release_api_url; Write-Task " to get download URL"
    $api_object = Invoke-WebRequest -Uri $release_api_url -UseBasicParsing | ConvertFrom-Json
    Write-Done
    $dl_url = $api_object.assets.browser_download_url
    
    $outpath = "$s_root\$($m)_$($api_object.tag_name).rmskin"
    Write-Task "Downloading    "; Write-Emphasized $dl_url
    Invoke-WebRequest "$dl_url" -outfile "$outpath" -UseBasicParsing
    Write-Done
}

# ---------------------------------------------------------------------------- #
#                                 Installation                                 #
# ---------------------------------------------------------------------------- #
If (($o_ExtInstall -eq $true) -and ($s_InstallIsBatch -eq $false)) {
    # ---------------------------------------------------------------------------- #
    #                          RMSKIN legacy installation                          #
    # ---------------------------------------------------------------------------- #
    # ---------------------------------- RMSKIN ---------------------------------- #
    Write-Task "Running .rmskin to install (specified)"
    If (Test-Path -Path "$s_root\*") {
        Get-ChildItem $s_root -File | ForEach-Object {
            Invoke-Item $_.FullName
        }
    } else {
        throw 'Unable to find downloaded file. Try running installer as adminstrator, or if you are installing a module within JaxCore, run Rainmeter as administrator and try again. Make sure you have no programs running that would potentially delete the downloaded file'
    }
    Write-Done
    Write-Task "Interacting with installer UI"
    If ($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell = New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1.5
        $wshell.SendKeys('{ENTER}')
    }
    Write-Done
    Write-Task "Waiting for SkinInstaller to quit"
    Wait-Process "SkinInstaller"
    Write-Done
    Wait-ForProcess 'Rainmeter'
} else {
    # ---------------------------------------------------------------------------- #
    #                       Standard extraction installation                       #
    # ---------------------------------------------------------------------------- #
    # ------------------------------- Extract file ------------------------------- #
    If (Test-Path -Path "$s_root\*") {
        Get-ChildItem $s_root -File | ForEach-Object {
            $i_name = $($_.Name -replace '\.rmskin', '')
            Rename-Item -LiteralPath (Get-Item -LiteralPath "$s_root\$($_.Name)").FullName -NewName "$i_name.zip"
            Write-Task "Exapnding downloaded archive    "; Write-Emphasized "$i_name"; Write-Task " -> "; Write-Emphasized "$s_root\Unpacked\$i_name\"
            Expand-Archive -LiteralPath (Get-Item -LiteralPath "$s_root\$i_name.zip").FullName -DestinationPath "$s_unpacked\$i_name\" -Force
            Write-Done
        }
    } else {
        throw 'Unable to find downloaded file. Try running installer as adminstrator, or if you are installing a module within JaxCore, run Rainmeter as administrator and try again. Make sure you have no programs running that would potentially delete the downloaded file'
    }
    # ---------------------------- Start installation ---------------------------- #
    Write-Info "Starting installation..."
    debug "-----------------"
    debug "RainmeterPluginsBit: $bit"
    debug "RainmeterPath: $s_RMSettingsFolder"
    debug "RainmeterExePath: $RMEXEloc"
    debug "SkinsPath: $s_RMSkinFolder"
    debug "InstallIsBatch: $s_InstallIsBatch"
    debug "-----------------"

    $isInstallingCore = $false
    [System.Collections.ArrayList]$list_of_installations = @()

    Get-ChildItem "$s_unpacked\" -Directory | Sort-Object | ForEach-Object {
        $i_root = "$s_unpacked\$($_.Name)"
        
        If (!(Test-Path "$i_root\RMSKIN.ini")) {
            Write-Fail "ERROR: Unable to find RMSKIN.ini in extracted package. Please report this issue to the developer."
            debug "Press ENTER to close this prompt"
            Read-Host
            Exit
        }

        # ------------------------------ Read RMSKIN.ini ----------------------------- #
        $Ini = Get-IniContent "$i_root\RMSKIN.ini"
        if (Test-Path "$i_root\Skins\") {
            $skin_name = (Get-ChildItem -Path "$i_root\Skins\" | Select-Object -First 1).Name
            $skin_auth = $Ini["rmskin"]["Author"]
            $skin_ver = $Ini["rmskin"]["Version"]
            $skin_varf = $Ini["rmskin"]["VariableFiles"]

            $skin_load = $Ini["rmskin"]["Load"]
            $skin_load_path = Split-Path $skin_load
            if ($skin_name -contains '#JaxCore') {$isInstallingCore = $true} 
            $list_of_installations.Add("$skin_name") > $null

            debug "$skin_name $skin_ver - by $skin_auth"
            debug "Variable files: $skin_varf"
            debug "Load: $skin_load_path ($isInstallingCore)"
            debug "-----------------"
            # ------------------------------ Variable files ------------------------------ #
            If (Test-Path "$s_RMSkinFolder\$skin_name") {
                $new_install = $false
                debug "This is an update"
                $confirmation = 'y'
                If ($o_Force) {$confirmation = 'n'}
                If ($o_PromptBestOption) {
                    $confirmation = Read-Host "Do you want to save variables for this installation? (y/n)"
                }
                if ($confirmation -match '^y$') {
                    debug "> Saving variable files"
                    $skin_varf = $skin_varf -split '\s\|\s'
                    If (Test-Path "$i_root\Unpacked\$i_name\") { Remove-Item -Path "$i_root\SavedVarFiles" -Force -Recurse > $null }
                    New-Item -Path "$i_root\SavedVarFiles" -Type "Directory" > $null
                    foreach ($varf in $skin_varf) {
                        if (Test-Path -Path "$s_RMSkinFolder\$varf") {
                            $i_savedir = "$i_root\SavedVarFiles\$(Split-Path $varf)"
                            $i_savelocation = "$i_root\SavedVarFiles\$varf"
                            debug "Saving #$i $($varf) -> $i_savelocation"
                            If (!(Test-Path "$i_savedir")) { New-Item -Path "$i_savedir" -Type "Directory" > $null }
                            Copy-Item -Path "$s_RMSkinFolder\$varf" -Destination "$i_savelocation" -Force > $null
                        }
                    }
                } else {
                    debug "> Not saving variable files"
                }
            } else {
                $new_install = $true
                debug "This is a new installation"
            }
            # ---------------------------------- Process --------------------------------- #
            debug "> Moving skin files"
            Get-ChildItem -Path "$i_root\Skins\" | ForEach-Object {
                If ($new_install) {
                    New-Item -Path "$s_RMSkinFolder\$($_.Name)\" -Type "Directory" -Force > $null
                } else {
                    Get-ChildItem -Path "$s_RMSkinFolder\$($_.Name)\" -Recurse | Remove-Item -Recurse
                }
                Move-Item -Path "$i_root\Skins\$($_.Name)\*" -Destination "$s_RMSkinFolder\$($_.Name)\" -Force
            }
            # ------------------------------ Variable files ------------------------------ #
            If ((-not $new_install) -and ($confirmation -match '^y$')) {
                debug "> Writing saved variables files back to skin"
                foreach ($varf in $skin_varf) {
                    $i_savelocation = "$i_root\SavedVarFiles\$varf"
                    $i_targetlocation = "$s_RMSkinFolder\$varf"
                    If (Test-Path "$i_savelocation") {
                        debug "Writing keys and values from saved variables to local"
                        $Ini = Get-IniContent $i_savelocation;$oldvars = $Ini
                        $Ini = Get-IniContent $i_targetlocation;$newvars = $Ini
                        $oldvars.Keys | Foreach-Object {
                            $i_section = $_
                            $oldvars[$i_section].Keys | ForEach-Object {
                                $i_value = $_
                                # debug "[$i_section] $i_value"
                                If ([bool]$newvars[$i_section][$i_value]) {
                                    $newvars[$i_section][$i_value] = $oldvars[$i_section][$i_value]
                                    # debug "$($newvars[$i_section][$i_value]) replaced by $($oldvars[$i_section][$i_value])"
                                }
                            }
                        }
                        Set-IniContent $newvars $i_targetlocation
                    }
                }
            } elseif (($skin_name -notcontains '#JaxCore') -and !$o_FromSHUB -and $o_NoPostActions) {
                debug "> Automatically changing scale variables (new installation)"
                $vc = Get-WmiObject -class "Win32_VideoController"
                $saw = $vc.CurrentHorizontalResolution
                $sah = $vc.CurrentVerticalResolution
        #        ((#SCREENAREAWIDTH#/1920) < (#SCREENAREAHEIGHT#/1080) ? (#SCREENAREAWIDTH#/1920) : (#SCREENAREAHEIGHT#/1080))
                $scale = 1
                Write-Task "Getting scale"
                If (($saw/1920) -lt ($sah/1080)) {
                    $scale = $saw / 1920
                } else {
                    $scale = $sah / 1080
                }
                Write-Done
                $scale = [math]::Round($scale,2)
                debug "Scale is $scale"
                if ($scale -eq 1) {
                    debug "Scale unchanged."
                } elseif ($scale -eq 0) {
                    Write-Fail "Seems like the installer is unable to identify the correct screen sizes. Skipping scaling writing."
                } else {
                    Write-Task "Applying scaling to config files"
                    $varsfile = "$s_RMSkinFolder\$skin_name\@Resources\Vars.inc"
                    If (Test-Path $varsfile) {
                        debug "Vars.inc found."
                        $Ini = Get-IniContent $varsfile
                        If ([bool]$Ini["Variables"]["Scale"]) {
                            $Ini["Variables"]["Scale"] = $scale
                            Set-IniContent $Ini $varsfile
                        }
                    }
                    $othervarfiles = "$s_RMSkinFolder\$skin_name\Main\Vars\"
                    If (Test-Path "$othervarfiles") {
                        debug "Found other variable files"
                        Get-ChildItem "$othervarfiles" -File | ForEach-Object {
                            $i_file = "$othervarfiles\$($_.Name)"
                            $Ini = Get-IniContent $i_file
                            If ([bool]$Ini["Variables"]["Scale"]) {
                                debug "Found scale variable in $i_file"
                                $Ini["Variables"]["Scale"] = $scale
                                Set-IniContent $Ini $i_file
                            }
                        }
                    }
                    Write-Done
                }
            }
            # ------------------------------ Hotkey variable ----------------------------- #
            If ($($ModuleDetails[$skin_name].VarFiles -split '\s\|\s') -contains "$skin_name\@Resources\Actions\Hotkeys.ini") {
                If (!((join-path "$Env:APPDATA\Rainmeter\" "") -eq ($RMEXEloc))) {
                    Write-Task "Setting Rainmeter path for AutoHotkey to use in modules."
                    $i_file = "$s_RMSkinFolder\$skin_name\@Resources\Actions\Hotkeys.ini"
                    $Ini = Get-IniContent $i_file
                    $Ini["Variables"]["RMPATH"] = $RMEXEloc
                    Set-IniContent $Ini $i_file
                    Write-Done
                }
            }
        } else {
            debug "> Skipping skin installation (none)"
        }
        # ---------------------------------- Plugins --------------------------------- #
        If (Test-Path "$i_root\Plugins\") {
            debug "> Moving / replacing plugins"
            $i_targetlocation = "$($s_RMSettingsFolder)\Plugins\"
            If (!(Test-Path "$i_targetlocation\")) { New-Item -Path "$i_targetlocation" -Type "Directory" -Force }
            Get-ChildItem "$i_root\Plugins\$bit" | ForEach-Object {
                $i_plugin = $_.Name
                $i_pluginlocation = "$i_root\Plugins\$bit\$i_plugin"
                debug "Moving `"$i_plugin`" -> `"$i_pluginlocation`""
                If (Test-Path "$i_targetlocation\$i_plugin") { Remove-Item "$i_targetlocation\$i_plugin" -Force }
                Copy-Item -Path "$i_pluginlocation" -Destination "$i_targetlocation" -Force > $null
            }
        } else {
            debug "> Skipping plugin installation (none)"
        }
        Write-Info "Finished installation of $skin_name! :D "
    }
    If (!($o_FromSHUB) -or $o_NoPostActions) {
        Start-Process "$RMEXEloc"
        Wait-ForProcess 'Rainmeter'
    }
}

Start-Sleep -Milliseconds 500
If (!$wasRMInstalled) {
    Stop-Process -Name 'Rainmeter'
    Remove-Item -Path "$($s_RMSettingsFolder)Rainmeter.ini"
    New-Item -Path "$s_RMSettingsFolder" -Name "Rainmeter.ini" -ItemType "file" -Force -Value @"
[Rainmeter]
Logging=0
SkinPath=$s_RMSkinFolder
HardwareAcceleration=1

[illustro\Clock]
Active=0
[illustro\Disk]
Active=0
[illustro\System]
Active=0

[$skin_load_path]
Active=1

"@
    Start-Process "$RMEXEloc"
    Wait-ForProcess 'Rainmeter'
    Start-Sleep -Milliseconds 500
} elseif ($isInstallingCore -or $o_NoPostActions) {
    if ($o_ExtInstall -eq $false) {
        & "$RMEXEloc" [!ActivateConfig $skin_load_path]
    }
} else {
    If ($o_ExtInstall) {
        & "$RMEXEloc" [!DeactivateConfig $skin_load_path]
    }
    $dlcINCFile = "$s_RMSkinFolder\..\CoreData\@DLCs\InstalledDLCs.inc"
    $isPostWebviewCore = Test-Path "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Configurator.inc"

    If (!($o_FromSHUB)) {
        If (!(Test-Path $dlcINCFile)) {
            debug "No DLCs installed."
        } else {
            If ([String]::IsNullOrWhiteSpace((Get-content $dlcINCFile))) {
                debug "No DLCs installed."
            } else {
                # --------------------- Check if skin has a DLC installed -------------------- #
                $Ini = Get-IniContent -filePath $dlcINCFile

                for ($i = 0;$i -lt $list_of_installations.Count;$i++) {
                    $i_name = $list_of_installations[$i]
                    debug "> Matching $i_name with installed DLCs"

                    for ($j = 0; $j -lt $Ini['Variables'].Keys.Count; $j++) { 
                        if ($Ini['Variables'].Keys[$j] -match $i_name) {
                            debug "Found $i_name in installed DLCs"
                            # Preserve legacy DLC reinstall action
                            if ($isPostWebviewCore) {
                                & "$RMEXEloc" [!WriteKeyValue Variables Sec.Page "1" "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Supporter.inc"][!WriteKeyValue Variables Page.Complete_Reinstallation "1" "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Supporter.inc"][!WriteKeyValue Variables Page.Reinstallation_isSingle "$([Bool]($list_of_installations.Count -eq 1))" "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Supporter.inc"][!ActivateConfig "#JaxCore\Main" "Supporter.Ini"]
                            } else {
                                & "$RMEXEloc" [!WriteKeyValue Variables Sec.Page "1" "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Supporter.inc"][!WriteKeyValue Variables Page.Complete_Reinstallation "1" "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Supporter.inc"][!WriteKeyValue Variables Page.Reinstallation_isSingle "$([Bool]($list_of_installations.Count -eq 1))" "$s_RMSkinFolder\#JaxCore\@Resources\CacheVars\Supporter.inc"][!ActivateConfig "#JaxCore\Main" "Supporter.Ini"]
                            }
                            Return
                        }
                    }
                }
                debug "No matching DLCs found"
            }
        }
        If ($s_InstallIsBatch) {
            # Preserve legacy jaxcore post acton
            If ($isPostWebviewCore) {
                & "$RMEXEloc" [!ActivateConfig "#JaxCore\Main" "Home.Ini"]
            } else {
                & "$RMEXEloc" [!WriteKeyValue Variables Sec.Page "1" "$s_RMSkinFolder\#JaxCore\Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.Ini"]
            }
        } else {
            # Preserve legacy secvar path
            If ($isPostWebviewCore) {
                $cachevars_configurator = 'CacheVars\Configurator.inc'
                $coreini_toload = 'Settings.ini'
            } else {
                $cachevars_configurator = 'SecVar.inc'
                $coreini_toload = 'Settings.ini'
            }
            & "$RMEXEloc" [!WriteKeyvalue Variables Skin.Name "$skin_name" "$s_RMSkinFolder\#JaxCore\@Resources\$cachevars_configurator"][!WriteKeyvalue Variables Skin.Set_Page Info "$s_RMSkinFolder\#JaxCore\@Resources\$cachevars_configurator"][!ActivateConfig "#JaxCore\Main" "$coreini_toload"]
        }
    }
}
Write-Task "Clearing cache"
Get-ChildItem -Path "$s_root\" -Recurse | Remove-Item -Recurse
Remove-Item -Path "$s_root" -Force
Write-Done
If (!($o_FromSHUB)) {Exit}