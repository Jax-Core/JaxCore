$ErrorActionPreference = 'SilentlyContinue'

$root = $RmAPI.VariableStr("SKINSPATH") + "#CoreInstallerCache"
function InitInstall { 
    $url = $RmAPI.VariableStr('DownloadLink')
    $name = $RmAPI.VariableStr('DownloadName')
    $RmAPI.Bang("[!DeactivateConfig `"#JaxCore\Accessories\GenericInteractionBox`"][!CommandMeasure Func `"interactionBox('Install', '$name', '$url')`"]")
}
# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

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

function debug {
    param(
        [Parameter()]
        [string]
        $message
    )

    $RmAPI.Bang("[!Log `"`"`"CoreInstaller: " + $message + "`"`"`" Debug]")
}

function post-prog {
    param(
        [Parameter()]
        [string]
        $message
    )
    $RmAPI.Bang("[!SetVariable InstallText `"`"`"" + $message + "`"`"`"][!UpdateMeterGroup Progress][!Redraw]")
    
}

function Get-Webfile ($url, $dest) {
    debug "Downloading $url`n"
    $uri = New-Object "System.Uri" "$url"
    $request = [System.Net.HttpWebRequest]::Create($uri)
    $request.set_Timeout(5000)
    $response = $request.GetResponse()
    $length = $response.get_ContentLength()
    $responseStream = $response.GetResponseStream()
    $destStream = New-Object -TypeName System.IO.FileStream -ArgumentList $dest, Create
    $buffer = New-Object byte[] 100KB
    $count = $responseStream.Read($buffer, 0, $buffer.length)
    $downloadedBytes = $count

    while ($count -gt 0) {
        $RmAPI.Bang("[!CommandMeasure s.CircleBarHelper `"DrawCircleBar($([System.Math]::Round(($downloadedBytes / $length) * 100,0)))`"][!SetOption ProgressBar.String Text `"$([System.Math]::Round(($downloadedBytes / $length) * 100,0))%`"][!UpdateMeterGroup Progress][!Redraw]")
        $destStream.Write($buffer, 0, $count)
        $count = $responseStream.Read($buffer, 0, $buffer.length)
        $downloadedBytes += $count
    }

    debug "`nDownload of `"$dest`" finished."
    $destStream.Flush()
    $destStream.Close()
    $destStream.Dispose()
    $responseStream.Dispose()
}

function New-Cache {

    [System.IO.Directory]::CreateDirectory("$root") | Out-Null
    Get-ChildItem "$root" | ForEach-Object {
        Remove-Item $_.FullName -Force -Recurse
    }
}

# ---------------------------------------------------------------------------- #
#                                    Actions                                   #
# ---------------------------------------------------------------------------- #
function Install {
    $url = $RmAPI.VariableStr('sec.arg2')
    $name = $RmAPI.VariableStr('sec.arg1')
    $outPath = "$root/$name.rmskin"
    # -------------------------------- Clear cache ------------------------------- #
    New-Cache
    # ---------------------------- Stop ahk processes ---------------------------- #
    $process = Get-Process 'Rainmeter'
    $ppid = $process.Id
    Get-CimInstance Win32_Process | Where-Object { $_.ParentProcessId -eq $ppid } | ForEach-Object { Stop-Process $_.ProcessId }
    # ------------------------------- Download file ------------------------------ #
    Get-Webfile $url $outPath
    StartInstall-Process $name
}

function StartInstall-Process($name) {
    # ------------------------------- Extract file ------------------------------- #
    post-prog "Expanding archive"
    Get-ChildItem $root -File | ForEach-Object {
        $i_name = $($_.Name -replace '\.rmskin', '')
        Rename-Item "$root\$($_.Name)" -NewName "$i_name.zip"
        debug "$root\$i_name.zip -> $root\Unpacked\$i_name\"
        Expand-Archive -Path "$root\$i_name.zip" -DestinationPath "$root\Unpacked\$i_name\" -Force -Verbose
    }
    post-prog "Installing..."
    
    # ---------------------------- Start installation ---------------------------- #
    debug "Starting installation"
    $rmprocess_object = Get-Process Rainmeter
    $rmprocess_id = $rmprocess_object.id
    # ------------------------------ Carry over data ----------------------------- #
    New-Item -Path "$root\Unpacked\InstallerProcessData.ini" -ItemType "file" -Value @"
[Data]
RainmeterPluginsBit=x
RainmeterPath=y
RainmeterExePath=z
InstallIsBatch=Bool
"@
    $Ini = Get-IniContent "$root\Unpacked\InstallerProcessData.ini"

    Add-Type -MemberDefinition @'
[DllImport("kernel32.dll", SetLastError = true, CallingConvention = CallingConvention.Winapi)]
[return: MarshalAs(UnmanagedType.Bool)]
public static extern bool IsWow64Process(
    [In] System.IntPtr hProcess,
    [Out, MarshalAs(UnmanagedType.Bool)] out bool wow64Process);
'@ -Name NativeMethods -Namespace Kernel32

    $Ini["Data"]["RainmeterPluginsBit"] = "32bit"
    Get-Process -Id $rmprocess_id | Foreach {
        $is32Bit=[int]0 
        if ($_.Handle -ne $null) {
            if ([Kernel32.NativeMethods]::IsWow64Process($_.Handle, [ref]$is32Bit)) { 
                $Ini["Data"]["RainmeterPluginsBit"] = "$(if ($is32Bit) {'32bit'} else {'64bit'})"
            } else {
                $Ini["Data"]["RainmeterPluginsBit"] = "32bit"
            }    
        }
    }
    If ($name -ne $null ) {
        If ($name -match "^JaxCore") {$RmAPI.Bang("[!WriteKeyValue `"$($RmAPI.VariableStr('CURRENTCONFIG'))`" Active 0 `"$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini`"]")}
        $Ini["Data"]["InstallIsBatch"] = "0"
    } else {
        $Ini["Data"]["InstallIsBatch"] = "1"
    }

    $Ini["Data"]["RainmeterPath"] = "$($RmAPI.VariableStr('SETTINGSPATH'))"
    $Ini["Data"]["RainmeterExePath"] = "$($RmAPI.VariableStr('PROGRAMPATH'))"
    Set-IniContent $Ini "$root\Unpacked\InstallerProcessData.ini"

    Copy-Item -Path "$($RmAPI.VariableStr('@'))Powershell\InstallerProcess.ps1" -Destination "$root\InstallerProcess.ps1"
    # Set-ExecutionPolicy Unrestricted -Scope CurrentUser
    cmd /c start powershell -ExecutionPolicy Bypass -command "Get-Process Rainmeter | Stop-Process; `$root='$root\Unpacked';`$Script='$($root -replace ' ','` ')\InstallerProcess.ps1';`$Script | Invoke-Expression"
}

function FinishInstall {
    New-Cache
    $RmAPI.Bang('[!DeactivateConfig]')
}

function BatchInstall-AddToList($name) {
    If ($global:batchinstall_list -eq $null) {
        [System.Collections.ArrayList]$global:batchinstall_list = @()
    }
    $global:batchinstall_list.Add("$name")
    debug $global:batchinstall_list
}

function BatchInstall-RemoveFromList($name) {
    $global:batchinstall_list.Remove("$name")
    debug $global:batchinstall_list
}

function CheckAvailableUpdates {
    $skinList = $RmAPI.VariableStr('SkinList')
    $skinspath = $RmAPI.VariableStr('Skinspath')
    $SkinArray = $SkinList -split '\s\|\s'
    [System.Collections.ArrayList]$global:batchinstall_list = @()
    
    for ($i=0; $i -lt $SkinArray.Count; $i++) {
        If (Test-Path -Path "$($skinspath)$($SkinArray[$i])\") {
            try {
                $response = Invoke-WebRequest "https://raw.githubusercontent.com/Jax-Core/$($SkinArray[$i])/main/%40Resources/Version.inc" -UseBasicParsing
                $responseBytes = $response.RawContentStream.ToArray()
                if ([System.Text.Encoding]::Unicode.GetString($responseBytes) -match 'Version=(.+)') {
                    $latest_v = $matches[1]
                }
            } catch {
                debug "$($SkinArray[$i]) repository does not exist or is hidden"
                $latest_v = '0.0'
            } finally {
                Get-Content "$($skinspath)$($SkinArray[$i])\@Resources\Version.inc" -Raw | Select-String -Pattern '\d\.\d+' -AllMatches | Foreach-Object {$local_v = $_.Matches.Value}
                debug "$($SkinArray[$i]) ✔️ - 🔼 |$latest_v| 🔽 |$local_v|"
                if ($latest_v -gt $local_V) {
                    $global:batchinstall_list.Add("$($SkinArray[$i])")
                    $RmAPI.Bang("[!SetOption ProgressBar.String Text $($global:batchinstall_list.Count)][!SetOption ProgressBar.Title.String Text `"Required updates found`"][!UpdateMeterGroup Progress][!Redraw]")
                }
            }
        }
    }
    debug "$($global:batchinstall_list.Count) - $global:batchinstall_list"
    If ($global:batchinstall_list.Count -eq 0) {
        $RmAPI.Bang('[!SetOption Button2.String Text Back][!SetOption Button2.Shape LeftMouseUpAction """[!CommandMeasure ActionTimer "Execute 2"][!WriteKeyValue Variables Sec.Page 1 "#ROOTCONFIGPATH#Main\Home.ini"][!ActivateConfig "#JaxCore\Main" "Home.ini"]"""][!SetOption ProgressBar.String Text 0][!SetOption ProgressBar.Title.String Text "Required updates found"][!UpdateMeterGroup Progress][!UpdateMeterGroup Button][!Redraw]')
    } else {
        $RmAPI.Bang('[!SetOption Button2.String Text "Install all"][!SetOption Button2.Shape LeftMouseUpAction """[!WriteKeyValue "#CURRENTCONFIG#" Active 0 "#SETTINGSPATH#Rainmeter.ini"][!CommandMeasure CoreInstallHandler "BatchInstallStart"]"""][!UpdateMeterGroup Button][!Redraw]')
    }
}

function BatchInstallStart {
    If ($global:batchinstall_list -eq $null) { Return } else {
        debug "Selected $($global:batchinstall_list.Count) items."
        $RmAPI.Bang('[!SetOption List.Container Fill "Fill Color 0,0,0,25"][!DisableMouseActionGroup "*" "List"][!HideMeterGroup Button][!ShowMeterGroup Hidden][!UpdateMeter *][!Redraw]')
        # -------------------------------- Clear cache ------------------------------- #
        New-Cache
        # ---------------------------- Stop ahk processes ---------------------------- #
        $process = Get-Process 'Rainmeter'
        $ppid = $process.Id
        Get-CimInstance Win32_Process | Where-Object { $_.ParentProcessId -eq $ppid } | ForEach-Object { Stop-Process $_.ProcessId }
        # --------------------------------- Download --------------------------------- #
        for ($i = 0; $i -lt $global:batchinstall_list.Count; $i++) {
            $i_name = $($global:batchinstall_list[$i])
            # -------------------------- Get latest skin version ------------------------- #
            $response = Invoke-WebRequest "https://raw.githubusercontent.com/Jax-Core/$i_name/main/%40Resources/Version.inc" -UseBasicParsing
            $responseBytes = $response.RawContentStream.ToArray()
            if ([System.Text.Encoding]::Unicode.GetString($responseBytes) -match 'Version=(.+)') {
                $i_latest = $matches[1]
            }
            debug "#$($i+1) $i_name v$i_latest, starting download"
            $RmAPI.Bang("[!SetOption ProgressBar.Title.String Text `"$i_name v$i_latest`"][!UpdateMeter ProgressBar.Title.String][!Redraw]")
            $url = "https://github.com/Jax-Core/$i_name/releases/download/v$i_latest/$($i_name)_v$i_latest.rmskin"
            $outPath = "$root/$i_name.rmskin"
            Get-Webfile $url $outPath
            Start-Sleep -Milliseconds 200
        }
        StartInstall-Process
    }
}

function CheckForDLC {
    If ([String]::IsNullOrWhiteSpace((Get-content "$($RmAPI.VariableStr('SKINSPATH'))..\CoreData\@DLCs\InstalledDLCs.inc"))) {
        $RmAPI.Bang('[!ActivateConfig "#JaxCore\Main" "Settings.Ini"][!DeactivateConfig]')
    } else {
        $Ini = Get-IniContent -filePath "$($RmAPI.VariableStr('SKINSPATH'))..\CoreData\@DLCs\InstalledDLCs.inc"
        $InstalledSkin = $RmAPI.VariableStr('SKIN.NAME')
        for ($i = 0; $i -lt $Ini['Variables'].Keys.Count; $i++) { 
            debug $Ini['Variables'].Keys[$i]
            if ($Ini['Variables'].Keys[$i] -match $InstalledSkin) {
                debug "Found $InstalledSkin"
                $RmAPI.Bang('[!WriteKeyValue Variables Sec.Page "2" "'+$($RmAPI.VariableStr('ROOTCONFIGPATH'))+'Main\Home.ini"][!WriteKeyValue Variables Page.SubPage "1" "'+$($RmAPI.VariableStr('ROOTCONFIGPATH'))+'CoreShell\Home\Page2.inc"][!WriteKeyValue Variables Page.Complete_Reinstallation "1" "'+$($RmAPI.VariableStr('ROOTCONFIGPATH'))+'CoreShell\Home\Page2.inc"][!ActivateConfig "#JaxCore\Main" "Home.Ini"][!DeactivateConfig]')
                Return
            } else {
                debug "Not Found"
            }
        }
        $RmAPI.Bang('[!ActivateConfig "#JaxCore\Main" "Settings.Ini"][!DeactivateConfig]')
        # [!ActivateConfig "'+$RmAPI.VariableStr('Skin.Name')+'\Main"]
    }
    $RmAPI.Bang('[!ActivateConfig "#JaxCore\Main" "Settings.Ini"][!DeactivateConfig]')
}

function GenCoreData {
    $SkinsPath = $RmAPI.VariableStr('SKINSPATH')
    $SkinName = $RmAPI.VariableStr('Skin.Name')
    $SkinVer = $RmAPI.VariableStr('Version')
    If (Test-Path -Path "$SkinsPath..\CoreData") {
        $RmAPI.Log("Found coredata in programs")

        If (Test-Path -Path "$SkinsPath$SkinName\@Resources\@Structure") {
            $RmAPI.Log("Available CoreData structure for $SkinName")
            If (-not (Test-Path -Path "$SkinsPath..\CoreData\$SkinName\$SkinVer.txt")) {
                $RmAPI.Log("Generating: Can't find $SkinVer.txt file in CoreData of $SkinName")
                Robocopy "$SkinsPath$SkinName\@Resources\@Structure" "$SkinsPath..\CoreData\$SkinName" /E /XC /XN /XO
                New-Item -Path "$SkinsPath..\CoreData\$SkinName" -Name "$SkinVer.txt" -ItemType "file"
            }
            else {
                $RmAPI.Log("CoreData for $SkinName is already generated")
            }
        }
        else {
            $RmAPI.Log("$SkinName doesn't require creation of CoreData")
        }
    }
    else {
        $RmAPI.Log("Failed to find coredata in programs, generating")
        New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
        $RmAPI.Bang('[!Refresh]')
    }
}

function DuplicateSkin {
    param (
        [string]$DuplicateName = 'CloneSkinName'
    )
    $SkinsPath = $RmAPI.VariableStr('SKINSPATH')
    $Resources = $RmAPI.VariableStr('@')
    $SkinName = $RmAPI.VariableStr('Sec.arg1')

    If (Test-Path -Path "$SkinsPath$DuplicateName") {
        $RmAPI.Log("Folder already exits")
    }
    else {
        $RmAPI.Log("Duplicating to $DuplicateName")
        Copy-Item -Path "$SkinsPath$SkinName\" -Destination "$SkinsPath$DuplicateName\" -Recurse
        New-Item -Path "$SkinsPath$DuplicateName\@Resources\" -Name "IsClone.txt" -ItemType "file"
    }
    $RmAPI.Bang("[!WriteKeyValue Rainmeter OnRefreshAction `"`"`"[!WriteKeyValue Rainmeter OnRefreshAction `"#*Sec.DefaultStartActions*#`"][!DeactivateConfig]`"`"`"][!WriteKeyValue Variables Skin.Name $DuplicateName `"$($Resources)SecVar.inc`"][!WriteKeyValue Variables Skin.Set_Page Info `"$($Resources)SecVar.inc`"][!WriteKeyValue `"#JaxCore\Main`" Active 1 `"$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini`"][`"$($Resources)Addons\RestartRainmeter.exe`"]")

}

function Remove-Section($SkinName) {

    $Ini = Get-IniContent -filePath "$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini"
    $pattern = "^$SkinName"
    [string[]]$Ini.Keys | Where-Object { $_ -match $pattern } | ForEach-Object { 
        debug "Detected section [$_] in Rainmeter.ini, removing"
        $Ini.Remove($_)
    }
    Set-IniContent -ini $Ini -filePath "$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini"

}

function Uninstall {
    $SkinsPath = $RmAPI.VariableStr('SKINSPATH')
    $Resources = $RmAPI.VariableStr('@')
    $SkinName = $RmAPI.VariableStr('Sec.arg1')
    If (Test-Path -Path "$SkinsPath..\CoreData\$SkinName") {
        Remove-Item -LiteralPath "$SkinsPath..\CoreData\$SkinName" -Force -Recurse
    }

    Remove-Item -LiteralPath "$SkinsPath$SkinName" -Force -Recurse
    Remove-Item -LiteralPath "$SkinsPath@Backup\$SkinName" -Force -Recurse

    Remove-Section $SkinName
    # -- Rainmeter might not restart if the uninstalled skin is not loaded once! - #

    # Start-Sleep -s 1
    $RmAPI.Bang("[!WriteKeyvalue Variables Sec.variant `"Variants\Uninstalled.inc`"][!WriteKeyValue Variables Skin.Name $SkinName `"$($Resources)SecVar.inc`"][!WriteKeyValue Variables Skin.Set_Page Info `"$($Resources)SecVar.inc`"][`"$($Resources)Addons\RestartRainmeter.exe`"]")
}