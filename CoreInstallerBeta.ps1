# ----------------------------- Terminal outputs ----------------------------- #
# Helper functions edited from spicetify cli ps1 installer (https://github.com/spicetify/spicetify-cli/blob/master/install.ps1)
function Write-Part ([string] $Text) {
  Write-Host $Text -NoNewline
}

function Write-Emphasized ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Cyan"
}

function Write-Done {
  Write-Host " > " -NoNewline
  Write-Host "OK" -ForegroundColor "Green"
}

function Write-Info ([string] $Text) {
  Write-Host $Text -ForegroundColor "Yellow"
}

function Write-Red ([string] $Text) {
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

# ----------------------------- Wait for process ----------------------------- #

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

# --------------------------- Start of installation -------------------------- #

if ($installSkin) {
  $skinName = $installSkin
} else {
  $skinName = "JaxCore"
}

$designatedskinspath = "$env:APPDATA\Rainmeter\Skins\"
$RMEXEloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"
$RMEXE64bitloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"
$RMEXE32bitloc = "${Env:ProgramFiles(x86)}\Rainmeter\Rainmeter.exe"

Write-Part "COREINSTALLER REF: Beta v12"
Write-Done
Write-Part "Checking if Rainmeter is installed..."


if ((Test-Path "$RMEXE32bitloc") -or (Test-Path "$RMEXE64bitloc")) {
    Write-Done
    $rminstalled = $true
    If (Test-Path "$RMEXE32bitloc") {$RMEXEloc = "$RMEXE32bitloc"}
    REG ADD "HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers" /V "$RMEXEloc" /T REG_SZ /D ~HIGHDPIAWARE /F
    $rmini = "$env:APPDATA\Rainmeter\Rainmeter.ini"
    If (Test-Path $rmini) {
        $Ini = Get-IniContent "$env:APPDATA\Rainmeter\Rainmeter.ini"
        $root = "$($Ini["Rainmeter"]["SkinPath"])#CoreInstallerCache"
        
        $hwa = $Ini["Rainmeter"]["HardwareAcceleration"]
        if ($hwa -eq 0) {
            Write-Info "JaxCore recommends that the HardwareAcceleration option for Rainmeter to be turned on. "
            $confirmation = Read-Host "Turn on? (y/n)"
            if ($confirmation -match '^y$') {
                $Ini["Rainmeter"]["HardwareAcceleration"] = "1"
                Set-IniContent $Ini "$env:APPDATA\Rainmeter\Rainmeter.ini"
            }
        }
    } else {
        Write-Red "Seems like you have Rainmeter installed but haven't ran it once on this account. Please do so and try again."
        Read-Host
        Exit
    }
} else {
    # if (Check_Program_Installed("Rainmeter")) {
    #     $rminstalled = $true
    #     $userRMEXEloc = Read-Host -Prompt "Rainmeter isn't installed at the expected location `"$expectedRMEXEloc`". Please enter the location of Rainmeter.exe below:"
    #     Write-Part "$userRMEXEloc"
    #     Write-Done
    #     Write-Part "Checking if Rainmeter is installed at $userRMEXEloc"
    #     If ($userRMEXEloc -match '^.*Rainmeter\.exe$') {$userRMEXEloc = $userRMEXEloc | Split-Path}
    #     If (Test-Path "$userRMEXEloc\Rainmeter.exe") {
    #         $Ini = Get-IniContent "$userRMEXEloc\Rainmeter.ini"
    #         $root = "$($Ini["Rainmeter"]["SkinPath"])#CoreInstallerCache"
    #         Write-Done
    #     } else {
    #         Write-Done
    #         Write-Red "Could not find $userRMEXEloc. Please double check the path and re-enter."
    #         Read-Host
    #         Exit
    #     }
    # } else {
        $rminstalled = $false
        # ----------------------------------- Fetch ---------------------------------- #
        Write-Info "`nRainmeter is not installed, installing Rainmeter"
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
            If (Test-Path "$RMEXE32bitloc") {$RMEXEloc = "$RMEXE32bitloc"}
            REG ADD "HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers" /V "$RMEXEloc" /T REG_SZ /D ~HIGHDPIAWARE /F
        } else {
            Write-Red "`nFailed to install Rainmeter! "; Write-Part "Make sure you have selected `"Yes`" when installation dialog pops up"
            Return
        }
        # --------------------------------- Generate --------------------------------- #
        Write-Part "Generating "; Write-Emphasized "Rainmeter.ini "; Write-Part "for the first time..."
        New-Item -Path "$env:APPDATA\Rainmeter" -Name "Rainmeter.ini" -ItemType "file" -Force -Value @"
[Rainmeter]
Logging=0
SkinPath=$designatedskinspath
HardwareAcceleration=1

[illustro\Clock]
Active=0
[illustro\Disk]
Active=0
[illustro\System]
Active=0

"@
        Write-Done
        # ---------------------------------- Install --------------------------------- #
        $root = "$designatedskinspath#CoreInstallerCache"
    # }
}


New-Item -Path $root -Type "Directory" -Force | Out-Null

[System.IO.Directory]::CreateDirectory("$root") | Out-Null
Get-Item $root -Force | foreach { $_.Attributes = $_.Attributes -bor "Hidden" }
Get-ChildItem "$root" | ForEach-Object {
    Remove-Item $_.FullName -Force -Recurse
}
# ------------------------------ Download files ------------------------------ #
$api_url = 'https://api.github.com/repos/Jax-Core/' + $skinName + '/releases'
$api_object = Invoke-WebRequest -Uri $api_url -UseBasicParsing | ConvertFrom-Json
$dl_url = $api_object.assets.browser_download_url[0]
$outpath = "$root\$($skinName)_$($api_object.tag_name[0]).rmskin"
Write-Part "Downloading    "; Write-Emphasized $dl_url; Write-Part " -> "; Write-Emphasized $outpath
downloadFile "$dl_url" "$outpath"
Write-Done
# ------------------------------- Extract file ------------------------------- #
Get-ChildItem $root -File | ForEach-Object {
    $i_name = $($_.Name -replace '\.rmskin', '')
    Rename-Item "$root\$($_.Name)" -NewName "$i_name.zip"
    Write-Part "Exapnding downloaded archive    "; Write-Emphasized "$root\$i_name.zip"; Write-Part " -> "; Write-Emphasized "$root\Unpacked\$i_name\"
    Expand-Archive -Path "$root\$i_name.zip" -DestinationPath "$root\Unpacked\$i_name\" -Force
    Write-Done
}

# ---------------------------- Start installation ---------------------------- #
Write-Part "Starting Rainmeter.exe"
& "$RMEXEloc"
Wait-ForProcess 'Rainmeter'
$rmprocess_object = Get-Process Rainmeter
$rmprocess_id = $rmprocess_object.id
Write-Done
# ------------------------------ Carry over data ----------------------------- #
Write-Part "Getting required information"

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

$settingspath = "$env:APPDATA\Rainmeter"
Write-Done
# -------------------------- Stop running instances -------------------------- #
Write-Part "Ending running processes"
$process = Get-Process 'Rainmeter'
$ppid = $process.Id
Get-CimInstance Win32_Process | Where-Object { $_.ParentProcessId -eq $ppid } | ForEach-Object { Stop-Process $_.ProcessId }
Stop-Process -Name 'Rainmeter'
Write-Done
# ---------------------------- Start installation ---------------------------- #
$root = "$root\Unpacked"
Write-Part "Getting archive info"
$skinspath = $root | Split-Path | Split-Path
Write-Done

debug "RainmeterPluginsBit: $bit"
debug "RainmeterPath: $settingspath"
debug "RainmeterExePath: $RMEXEloc"
debug "SkinsPath: $skinspath"
debug "-----------------"

$skin_need_load = $false
Get-ChildItem "$root\" -Directory | ForEach-Object {
    $i_root = "$root\$($_.Name)"

    # ------------------------------ Read RMSKIN.ini ----------------------------- #
    $Ini = Get-IniContent "$i_root\RMSKIN.ini"
    $skin_name = Get-ChildItem -Path "$i_root\Skins\" | Select-Object -First 1
    $skin_name = $skin_name.Name
    $skin_auth = $Ini["rmskin"]["Author"]
    $skin_ver = $Ini["rmskin"]["Version"]
    $skin_varf = $Ini["rmskin"]["VariableFiles"]

    $skin_load = $Ini["rmskin"]["Load"]
    $skin_load_path = Split-Path $skin_load
    If ($skin_name -contains '#JaxCore') {$skin_need_load = $true} 

    debug "$skin_name $skin_ver - by $skin_auth"
    debug "Variable files: $skin_varf"
    debug "Load: $skin_load_path ($skin_need_load)"
    debug "-----------------"
    # ------------------------------ Variable files ------------------------------ #
    If (Test-Path "$skinspath\$skin_name") {
        $new_install = $false
        debug "This is an update"
        $confirmation = Read-Host "Do you want to save variables for this installation? (y/n)"
        if ($confirmation -match '^y$') {
            debug "> Saving variable files"
            $skin_varf = $skin_varf -split '\s\|\s'
            If (Test-Path "$root\Unpacked\$i_name\") { Remove-Item -Path "$i_root\SavedVarFiles" -Force -Recurse | Out-Null }
            New-Item -Path "$i_root\SavedVarFiles" -Type "Directory" | Out-Null
            for ($i=0; $i -lt $skin_varf.Count; $i++) {
                $i_savedir = "$i_root\SavedVarFiles\$(Split-Path $skin_varf[$i])"
                $i_savelocation = "$i_root\SavedVarFiles\$($skin_varf[$i])"
                debug "Saving #$i $($skin_varf[$i]) -> $i_savelocation"
                If (!(Test-Path "$i_savedir")) { New-Item -Path "$i_savedir" -Type "Directory" | Out-Null }
                Copy-Item -Path "$skinspath\$($skin_varf[$i])" -Destination "$i_savelocation" -Force | Out-Null
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
    If ($new_install) {New-Item -Path "$skinspath\$skin_name\" -Type "Directory" -Force | Out-Null} else {Get-ChildItem -Path "$skinspath\$skin_name" -Recurse | Remove-Item -Recurse}
    Move-Item -Path "$i_root\Skins\$skin_name\*" -Destination "$skinspath\$skin_name\" -Force
    If (Test-Path "$i_root\Plugins\") {
        debug "> Moving / replacing plugins"
        $i_targetlocation = "$($settingspath)\Plugins\"
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
        debug "> Moving saved variables files back to skin"
        for ($i=0; $i -lt $skin_varf.Count; $i++) {
            $i_savelocation = "$i_root\SavedVarFiles\$($skin_varf[$i])"
            $i_targetlocation = "$skinspath\$($skin_varf[$i])"
            debug "Moving #$i $i_savelocation -> $i_targetlocation"
            If (!(Test-Path "$i_targetlocation")) { New-Item -Path "$(Split-Path $i_targetlocation)" -Type "Directory" | Out-Null }
            Copy-Item -Path "$i_savelocation" -Destination "$i_targetlocation" -Force | Out-Null
        }
    }
    debug "> Finished installation of $skin_name"
    debug "-----------------"
}

Start-Process "$RMEXEloc"
If ($skin_need_load) {
    Wait-ForProcess 'Rainmeter'
    Start-Sleep -Milliseconds 500
    If (-not $rminstalled) {
        Stop-Process -Name 'Rainmeter'
        $Ini = Get-IniContent "$env:APPDATA\Rainmeter\Rainmeter.ini"
        $Ini["Rainmeter"]["SkinPath"] = "$designatedskinspath"
        Set-IniContent $Ini "$env:APPDATA\Rainmeter\Rainmeter.ini"
        Start-Process "$RMEXEloc"
        Wait-ForProcess 'Rainmeter'
        Start-Sleep -Milliseconds 500
    }
    & "$RMEXEloc" [!ActivateConfig $skin_load_path]
}


If ($skinName -contains "JaxCore") {
    $skinFolder = "#JaxCore"
} else {
    $skinFolder = $skinName
}
If (Test-Path -Path "$skinspath\$skinFolder") {
    Write-Emphasized "`n$skinName is installed successfully. "; Write-Part "Follow the instructions in the pop-up window. Press Enter to close this window"
    Get-ChildItem "$root\*" | Remove-Item -Recurse -Force
    Exit
}
