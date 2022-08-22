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

function debug ([string] $Text) {
  Write-Host $Text
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
    # $section = ';ItIsNotAFuckingSection;'
    # $ini.Add($section, [ordered]@{})

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
    Write-Host ''
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

# ---------------------------------------------------------------------------- #
#                             Installation modules                             #
# ---------------------------------------------------------------------------- #

function Set-DPICompatability {
    REG ADD "HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers" /V "$RMEXEloc" /T REG_SZ /D ~HIGHDPIAWARE /F
}

function Prompt-UseHWA {
    If (Test-Path $s_RMINIFile) {
        $Ini = Get-IniContent $s_RMINIFile
        $s_RMSkinFolder = $Ini["Rainmeter"]["SkinPath"]
        $hwa = $Ini["Rainmeter"]["HardwareAcceleration"]
        if (($hwa -eq 0) -and ($o_PromptBestOption -eq $true)) {
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
}

function Download-Rainmeter($params) {
    # ----------------------------------- Fetch ---------------------------------- #
    Write-Info "Rainmeter is not installed, installing Rainmeter"
    $githubRMReleaseAPIObject = Invoke-WebRequest -Uri 'https://api.github.com/repos/rainmeter/rainmeter/releases' -UseBasicParsing | ConvertFrom-Json
    $githubRMDownloadURL = $githubRMReleaseAPIObject.assets.browser_download_url[0]
    $githubRMDownloadOutpath = "$env:temp\RainmeterInstaller.exe"
    # --------------------------------- Download --------------------------------- #
    Write-Task "Downloading    "; Write-Emphasized $githubRMDownloadURL; Write-Task " -> "; Write-Emphasized $githubRMDownloadOutpath
    $ProgressPreference = 'SilentlyContinue'
    wget "$githubRMDownloadURL" -outfile "$githubRMDownloadOutpath" -UseBasicParsing
    Write-Done
    # ------------------------------------ Run ----------------------------------- #
    Write-Task "Running installer..."
    Start-Process -FilePath $githubRMDownloadOutpath -ArgumentList "$params" -Wait
    Write-Done
    # ---------------------------- Check if installed ---------------------------- #
    Write-Task "Checking "; Write-Emphasized "$RMEXEloc"; Write-Task " for Rainmeter.exe"
    If (Test-Path -Path "$RMEXEloc") {
        Write-Done
        Set-DPICompatability
    } else {
        Write-Fail "`nFailed to install Rainmeter! "; Write-Task "Make sure you have selected `"Yes`" when installation dialog pops up"
        Return
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
}

# ---------------------------------------------------------------------------- #
#                             Start of installation                            #
# ---------------------------------------------------------------------------- #

# ----------------------------------- Info ----------------------------------- #
# $o - Option for installer
# $s - Installer options set by developer
# $o_InstallModule - Module to install
## $o_Version - Version to get
# $o_FromCore - If installation is invoked via JaxCore
# $o_Force - Overwrite existing files
# $o_PromptBestOption - Prompt for changing to best options
## $o_Location - Where to install Core, or where the Rainmeter folder is 
# ------------------------------ Default values ------------------------------ #
if (!($o_InstallModule)) {$o_InstallModule = "JaxCore"}
if (!($o_FromCore)) {$o_FromCore = $false}
if (!($o_Force)) {$o_Force = $false}
if (!($o_PromptBestOption)) {
    if ($o_FromCore -or $o_Force) {
        $o_PromptBestOption = $false
    } else {
        $o_PromptBestOption = $true
    }
}
# ---------------------------- Installer variables --------------------------- #
$s_InstallIsBatch = [bool]($o_InstallModule.Count -gt '1')
$s_rootFolderName = "JaxCoreCache"
$s_root = "$env:temp\$s_rootFolderName"
$s_unpacked = "$env:temp\$s_rootFolderName\Unpacked"
# Declare global scope installer variables

$s_RMSettingsFolder = ""
$s_RMINIFile = ""
$s_RMSkinFolder = ""
$RMEXEloc = ""
# ----------------------------------- Start ---------------------------------- #
Write-Info "COREINSTALLER REF: Beta v11"

if (!($o_Location)) {
    # ---------------------------------------------------------------------------- #
    #                             Standard installation                            #
    # ---------------------------------------------------------------------------- #
    # ---------------------------- Installer variables --------------------------- #
    $s_RMSettingsFolder = "$env:APPDATA\Rainmeter\"
    $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
    $s_RMSkinFolder = "$env:APPDATA\JaxCore\InstalledComponents\"
    # --------------------------- Check if RM installed -------------------------- #
    Write-Task "Checking if Rainmeter is installed..."

    $RMEXEloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"
    $RMEXE64bitloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"
    $RMEXE32bitloc = "${Env:ProgramFiles(x86)}\Rainmeter\Rainmeter.exe"

    Write-Done
    if ((Test-Path "$RMEXE32bitloc") -or (Test-Path "$RMEXE64bitloc")) {
        # ------------------------------- RM installed ------------------------------- #
        debug "Rainmeter is already installed on your device."
        $wasRMInstalled = $true
        If (Test-Path "$RMEXE32bitloc") {$RMEXEloc = "$RMEXE32bitloc"}
        Prompt-UseHWA
    } else {
        $wasRMInstalled = $false
        Download-Rainmeter "/S /AUTOSTARTUP=1 /RESTART=0"
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
    If (!(Test-Path "$o_Location\Rainmeter\Rainmeter.exe")) {
        Write-Task "Are you sure you want to install JaxCore at "; Write-Emphasized $o_Location
        $confirmation = Read-Host "? (y/n)"
        if ($confirmation -match '^y$') {
            Download-Rainmeter "/S /RESTART=0 /PORTABLE=1 /D=$s_RMSettingsFolder"
        } else {
            Write-Fail "Action cancelled. Installation terminated."
            Return
        }
    }
}

# ---------------------------------------------------------------------------- #
#                               Core installation                              #
# ---------------------------------------------------------------------------- #
New-Item -Path $s_root -Type "Directory" -Force | Out-Null
Get-Item $s_root -Force | foreach { $_.Attributes = $_.Attributes -bor "Hidden" }
Get-ChildItem "$s_root" | ForEach-Object {
    Remove-Item $_.FullName -Force -Recurse
}
# ------------------------------ Download files ------------------------------ #
If ($o_Version) {
    $githubDownloadURL = "https://github.com/Jax-Core/$o_InstallModule/releases/download/v$o_Version/$($o_InstallModule)_v$o_Version.rmskin"
    $githubDownloadOutpath = "$s_root\$($o_InstallModule)_v$o_Version.rmskin"
    Write-Task "Downloading    "; Write-Emphasized $githubDownloadURL; Write-Task " -> "; Write-Emphasized $githubDownloadOutpath
    $ProgressPreference = 'SilentlyContinue'
    wget "$githubDownloadURL" -outfile "$githubDownloadOutpath" -UseBasicParsing
    Write-Done
} else {
    for (($i=0);($i -lt $o_InstallModule.Count);$i++) {
        If ($o_InstallModule.Count -eq 1) {$i_name = $o_InstallModule} else {$i_name = $o_InstallModule[$i]}
        $response = Invoke-WebRequest "https://raw.githubusercontent.com/Jax-Core/$i_name/main/%40Resources/Version.inc" -UseBasicParsing
        $responseBytes = $response.RawContentStream.ToArray()
        if ([System.Text.Encoding]::Unicode.GetString($responseBytes) -match 'Version=(.+)') {
            $latest_v = $matches[1]
        } elseif ([System.Text.Encoding]::Unicode.GetString($responseBytes) -match 'Core\.Ver=(.+)') {
            $latest_v = $matches[1]
        }
        $githubDownloadURL = "https://github.com/Jax-Core/$i_name/releases/download/v$latest_v/$($i_name)_v$latest_v.rmskin"
        $githubDownloadOutpath = "$s_root\$($i_name)_$latest_v.rmskin"
        Write-Task "Downloading    "; Write-Emphasized $githubDownloadURL; Write-Task " -> "; Write-Emphasized $githubDownloadOutpath
        $ProgressPreference = 'SilentlyContinue'
        wget "$githubDownloadURL" -outfile "$githubDownloadOutpath" -UseBasicParsing
        Write-Done
    }
}
# ------------------------------- Extract file ------------------------------- #
Get-ChildItem $s_root -File | ForEach-Object {
    $i_name = $($_.Name -replace '\.rmskin', '')
    Rename-Item "$s_root\$($_.Name)" -NewName "$i_name.zip"
    Write-Task "Exapnding downloaded archive    "; Write-Emphasized "$s_root\$i_name.zip"; Write-Task " -> "; Write-Emphasized "$s_root\Unpacked\$i_name\"
    Expand-Archive -Path "$s_root\$i_name.zip" -DestinationPath "$s_unpacked\$i_name\" -Force
    Write-Done
}
# ---------------------------- Start installation ---------------------------- #
& "$RMEXEloc"
Wait-ForProcess 'Rainmeter'
Write-Done
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
If (Get-Process 'Rainmeter' -ErrorAction SilentlyContinue) {
    # Write-Task "Ending running child processes of Rainmeter"
    # $process = Get-Process 'Rainmeter'
    # $ppid = $process.Id
    # Get-CimInstance Win32_Process | Where-Object { $_.ParentProcessId -eq $ppid } | ForEach-Object { Stop-Process $_.ProcessId }
    # Write-Done
    Write-Task "Ending Rainmeter & potential AHKv1 process"
    Stop-Process -Name 'Rainmeter'
    If (Get-Process 'AHKv1' -ErrorAction SilentlyContinue) {
        Stop-Process -Name 'AHKv1'
    }
    Write-Done
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
If (!(Test-Path $s_RMSkinFolder)) {New-Item -Path $s_RMSkinFolder -Type "Directory" | Out-Null}
[System.IO.Directory]::SetCurrentDirectory($s_RMSkinFolder)

Get-ChildItem "$s_unpacked\" -Directory | ForEach-Object {
    $i_root = "$s_unpacked\$($_.Name)"
    
    If (!(Test-Path "$i_root\RMSKIN.ini")) {
        Write-Fail "ERROR: Unable to find RMSKIN.ini in extracted package. Please report this issue to the developer."
        debug "Press ENTER to close this prompt"
        Read-Host
        Exit
    }

    # ------------------------------ Read RMSKIN.ini ----------------------------- #
    $Ini = Get-IniContent "$i_root\RMSKIN.ini"
    $skin_name = (Get-ChildItem -Path "$i_root\Skins\" | Select-Object -First 1).Name
    $skin_auth = $Ini["rmskin"]["Author"]
    $skin_ver = $Ini["rmskin"]["Version"]
    $skin_varf = $Ini["rmskin"]["VariableFiles"]

    $skin_load = $Ini["rmskin"]["Load"]
    $skin_load_path = Split-Path $skin_load
    If ($skin_name -contains '#JaxCore') {$isInstallingCore = $true} 
    $list_of_installations.Add("$skin_name") | Out-Null

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
            If (Test-Path "$i_root\Unpacked\$i_name\") { Remove-Item -Path "$i_root\SavedVarFiles" -Force -Recurse | Out-Null }
            New-Item -Path "$i_root\SavedVarFiles" -Type "Directory" | Out-Null
            for ($i=0; $i -lt $skin_varf.Count; $i++) {
                $i_savedir = "$i_root\SavedVarFiles\$(Split-Path $skin_varf[$i])"
                $i_savelocation = "$i_root\SavedVarFiles\$($skin_varf[$i])"
                debug "Saving #$i $($skin_varf[$i]) -> $i_savelocation"
                If (!(Test-Path "$i_savedir")) { New-Item -Path "$i_savedir" -Type "Directory" | Out-Null }
                Copy-Item -Path "$s_RMSkinFolder\$($skin_varf[$i])" -Destination "$i_savelocation" -Force | Out-Null
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
    If ($new_install) {
        New-Item -Path "$s_RMSkinFolder\$skin_name\" -Type "Directory" -Force | Out-Null
    } else {
        Get-ChildItem -Path "$s_RMSkinFolder\$skin_name\" -Recurse | Remove-Item -Recurse
    }
    Move-Item -Path "$i_root\Skins\$skin_name\*" -Destination "$s_RMSkinFolder\$skin_name\" -Force
    If (Test-Path "$i_root\Plugins\") {
        debug "> Moving / replacing plugins"
        $i_targetlocation = "$($s_RMSettingsFolder)\Plugins\"
        If (!(Test-Path "$i_targetlocation\")) { New-Item -Path "$i_targetlocation" -Type "Directory" -Force }
        Get-ChildItem "$i_root\Plugins\$bit" | ForEach-Object {
            $i_plugin = $_.Name
            $i_pluginlocation = "$i_root\Plugins\$bit\$i_plugin"
            debug "Moving `"$i_plugin`" -> `"$i_pluginlocation`""
            If (Test-Path "$i_targetlocation\$i_plugin") { Remove-Item "$i_targetlocation\$i_plugin" -Force }
            Copy-Item -Path "$i_pluginlocation" -Destination "$i_targetlocation" -Force
        }
    } else {
        debug "> Skipping plugin installation (none)"
    }
    If ((-not $new_install) -and ($confirmation -match '^y$')) {
        debug "> Writing saved variables files back to skin"
        for ($i=0; $i -lt $skin_varf.Count; $i++) {
            $i_savelocation = "$i_root\SavedVarFiles\$($skin_varf[$i])"
            $i_targetlocation = "$s_RMSkinFolder\$($skin_varf[$i])"
            If (Test-Path "$i_targetlocation") {
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
            } else {
                debug "Moving #$i $i_savelocation -> $i_targetlocation"
                New-Item -Path "$(Split-Path $i_targetlocation)" -Type "Directory" | Out-Null
                Copy-Item -Path "$i_savelocation" -Destination "$i_targetlocation" -Force | Out-Null
            }
        }
    } elseif ($skin_name -notcontains '#JaxCore') {
        debug "> Automatically changing scale variables (new installation)"
        $vc = Get-WmiObject -class "Win32_VideoController"
        $saw = $vc.CurrentHorizontalResolution
        $sah = $vc.CurrentVerticalResolution
#        ((#SCREENAREAWIDTH#/1920) < (#SCREENAREAHEIGHT#/1080) ? (#SCREENAREAWIDTH#/1920) : (#SCREENAREAHEIGHT#/1080))
        $scale = 1
        If (($saw/1920) -lt ($sah/1080)) {
            $scale = $saw / 1920
        } else {
            $scale = $sah / 1080
        }
        debug "Scale is $scale"
        if (!($scale -eq 1)) {
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
        } else {
            debug "Scale unchanged."
        }
    }
    debug "> Finished installation of $skin_name"
    debug "-----------------"
}

Start-Process "$RMEXEloc"
Wait-ForProcess 'Rainmeter'
Start-Sleep -Milliseconds 500
If ($isInstallingCore) {
    If (-not $wasRMInstalled) {
        Stop-Process -Name 'Rainmeter'
        $Ini = Get-IniContent "$($s_RMSettingsFolder)Rainmeter.ini"
        $Ini["Rainmeter"]["SkinPath"] = "$s_RMSkinFolder"
        Set-IniContent $Ini "$($s_RMSettingsFolder)Rainmeter.ini"
        Start-Process "$RMEXEloc"
        Wait-ForProcess 'Rainmeter'
        Start-Sleep -Milliseconds 500
    }
    & "$RMEXEloc" [!ActivateConfig $skin_load_path]
} else {
    $dlcINCFile = "$s_RMSkinFolder\..\CoreData\@DLCs\InstalledDLCs.inc"
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
                        & "$RMEXEloc" [!WriteKeyValue Variables Sec.Page "2" "$s_RMSkinFolder\#JaxCore\Main\Home.ini"][!WriteKeyValue Variables Page.SubPage "1" "$s_RMSkinFolder\#JaxCore\CoreShell\Home\Page2.inc"][!WriteKeyValue Variables Page.Complete_Reinstallation "1" "$s_RMSkinFolder\#JaxCore\CoreShell\Home\Page2.inc"][!WriteKeyValue Variables Page.Reinstallation_isSingle "$([Bool]($list_of_installations.Count -eq 1))" "$s_RMSkinFolder\#JaxCore\CoreShell\Home\Page2.inc"][!ActivateConfig "#JaxCore\Main" "Home.Ini"]
                        Return
                    }
                }
            }
            debug "No matching DLCs found"
        }
    }
    If ($s_InstallIsBatch) {
        & "$RMEXEloc" [!WriteKeyValue Variables Sec.Page "1" "$s_RMSkinFolder\#JaxCore\Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.Ini"]
    } else {
        & "$RMEXEloc" [!WriteKeyvalue Variables Skin.Name "$skin_name" "$s_RMSkinFolder\#JaxCore\@Resources\SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "$s_RMSkinFolder\#JaxCore\@Resources\SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.Ini"]
    }
}

Get-ChildItem -Path "$s_root\" -Recurse | Remove-Item -Recurse
Exit