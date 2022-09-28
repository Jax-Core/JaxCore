<#

>>==SCRIPT PARAMETERS==<<
$s_Path                     - path to .shp package

#>

param(
    [Parameter(Mandatory=$true)][Alias("path")][ValidateNotNullOrEmpty()][string]$s_Path,
    [Alias("extracted")][switch]$o_noExtract,
    [Alias("nomove")][switch]$o_noMove
) 

$ErrorActionPreference = 'SilentlyContinue'

# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

# -------------------------------- Write-Host -------------------------------- #

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

function Get-RemoteIniContent ($link) {
    $ini = [ordered]@{}

    $result = iwr -useb $link
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

# ------------------------------- Wait process ------------------------------- #

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

# ----------------------------------- Copy ----------------------------------- #

function Copy-Path {
    [CmdletBinding()]
    param(
        [Parameter(ValueFromPipeline = $true, ValueFromPipelineByPropertyName = $true, Position = 0)]
        [ValidateScript({Test-Path -Path $_ -PathType Container})]
        [string]$Source,

        [Parameter(Position = 1)]
        [string]$Destination,

        [string[]]$ExcludeFolders = $null,
        [switch]$IncludeEmptyFolders
    )
    $Source      = $Source.TrimEnd("\")
    $Destination = $Destination.TrimEnd("\")

    Get-ChildItem -Path $Source -Recurse | ForEach-Object {
        if ($_.PSIsContainer) {
            # it's a folder
            if ($ExcludeFolders.Count) {
                if ($ExcludeFolders -notcontains $_.Name -and $IncludeEmptyFolders) {
                    # create the destination folder, even if it is empty
                    $target = Join-Path -Path $Destination -ChildPath $_.FullName.Substring($Source.Length)
                    if (!(Test-Path $target -PathType Container)) {
                        # Write-Verbose "Create folder $target"
                        New-Item -ItemType Directory -Path $target | Out-Null
                    }
                }
            }
        }
        else {
            # it's a file
            $copy = $true
            if ($ExcludeFolders.Count) {
                # get all subdirectories in the current file path as array
                $subs = $_.DirectoryName.Replace($Source,"").Trim("\").Split("\")
                # check each sub folder name against the $ExcludeFolders array
                foreach ($folderName in $subs) {
                    if ($ExcludeFolders -contains $folderName) { $copy = $false; break }
                }
            }

            if ($copy) {
                # create the destination folder if it does not exist yet
                $target = Join-Path -Path $Destination -ChildPath $_.DirectoryName.Substring($Source.Length)
                if (!(Test-Path $target -PathType Container)) {
                    # Write-Verbose "Create folder $target"
                    New-Item -ItemType Directory -Path $target | Out-Null
                }
                # Write-Verbose "Copy file $($_.FullName) to $target"
                $_ | Copy-Item -Destination $target -Force
            }
        }
    }
}

# ------------------------------ Plugin Version ------------------------------ #

function Get-PluginVersion {
    param(
        $file
    )
    return [System.Version](Get-Item $file).VersionInfo.FileVersion
}

# --------------------------------- Wallpaper -------------------------------- #

function Set-WallPaper($Image) {  
Add-Type -TypeDefinition @" 
using System; 
using System.Runtime.InteropServices;
  
public class Params
{ 
    [DllImport("User32.dll",CharSet=CharSet.Unicode)] 
    public static extern int SystemParametersInfo (Int32 uAction, 
                                                   Int32 uParam, 
                                                   String lpvParam, 
                                                   Int32 fuWinIni);
}
"@ 
  
    $SPI_SETDESKWALLPAPER = 0x0014
    $UpdateIniFile = 0x01
    $SendChangeEvent = 0x02
  
    $fWinIni = $UpdateIniFile -bor $SendChangeEvent
  
    $ret = [Params]::SystemParametersInfo($SPI_SETDESKWALLPAPER, 0, $Image, $fWinIni)
 
}

# ------------------------------ Core variables ------------------------------ #

function Apply-Variables($m) {
    $listInstalledDLCs = "$s_RMSkinFolder\..\CoreData\@DLCs\InstalledDLCs.inc"
    $dlcFound = $null
    foreach ($dlc in $SHPData.Data.DLCs) {
        debug "This setup has DLC $dlc"
        $dlcFound = $false
        $currentDLCModule = $($dlc -split '_')[0]
        $currentDLCName = $($dlc -split '_')[1]
        if ($currentDLCModule -contains $m) {
            if (Test-Path -Path "$listInstalledDLCs") {
                if ($(Get-IniContent $listInstalledDLCs).Variables[$dlc] -ne $null) {
                    debug "$dlc is installed on this device"
                    $dlcFound = $true
                } else {
                    debug "$dlc is not installed on this device"
                    Write-Info "The module $m from $s_name requires the DLC $currentDLCName for it to be installed.`nReapply this .shp package once you've obtained it. Using current settings"
                }
            } else {
                debug "No installed DLCs on this device"
                Write-Info "The module $m from $s_name requires the DLC $currentDLCName for it to be installed.`nReapply this .shp package once you've obtained it. Using current settings"
            }
        }
    } 
    
    if ($dlcFound -eq $null -or $dlcFound -eq $true) {
        debug "Importing variables files back to $m"
        Get-ChildItem -Path "$s_cache_location\Rainmeter\JaxCore\$m" -Recurse -File | ForEach-Object {
            $i_foundLocation = $_.FullName -replace "^$([regex]::Escape("$s_cache_location\Rainmeter\JaxCore\"))"
            $i_savelocation = $_.FullName
            $i_targetlocation = "$s_RMSkinFolder\$i_foundLocation"
            if (Test-Path "$i_targetlocation") {
                # debug $i_savelocation
                # debug $i_targetlocation
                $Ini = Get-IniContent $i_savelocation;$oldvars = $Ini
                $Ini = Get-IniContent $i_targetlocation;$newvars = $Ini
                $oldvars.Keys | Foreach-Object {
                    $i_section = $_
                    $oldvars[$i_section].Keys | ForEach-Object {
                        $i_value = $_
                        if ([bool]$newvars[$i_section][$i_value]) {
                            $newvars[$i_section][$i_value] = $oldvars[$i_section][$i_value]
                        }
                    }
                }
                Set-IniContent $newvars $i_targetlocation
            } else {
                debug "Moving #$i $i_savelocation -> $i_targetlocation"
                New-Item -Path "$(Split-Path $i_targetlocation)" -Type "Directory" -ErrorAction SilentlyContinue
                Copy-Item -Path "$i_savelocation" -Destination "$i_targetlocation" -Force -ErrorAction SilentlyContinue
            }
        }
    }
}
# ------------------------------- Coords interp ------------------------------ #
function coords-interp {
    if (($w/1920) -lt ($h/1080)) { $scale = $w / 1920 } else { $scale = $h / 1080 }
    $margin = $m * $scale

    if (($w/$w0) -lt ($h/$h0)) {
        $sf = $w/$w0
    } else {
        $sf = $h/$h0
    }

    $margin0 = $margin / $sf
    $r0 = [math]::Round($w0 / $h0,3)
    $r = [math]::Round($w / $h,3)

    debug "Interpolation data: sf = $sf, scale = $scale, margin = $margin, margin0 = $margin0, r0 = $r0, r = $r"

    if ($r0 -eq $r) {
        $x = $x0 * $sf
        $y = $y0 * $sf
    } else {
        # $cw = $w / 2
        # $ch = $h / 2
        # $cw0 = $w0 / 2
        # $ch0 = $h0 / 2

        if ($x0 -le $margin0) {
            $x = $x0 * $sf
        # } elseif ($x0 -gt $margin0 -and $x0 + $sw -lt $w0 - $margin0) {
        #     $x = $w / ($w0 - $sw) * $x0
            # $x = $cw - ($cw0 - $x0) * $sf
        } else {
            $x = $w - ($w0 - ($x0 + $sw)) * $sf - $sw
            # $x = $w - ($w0 - $x0) * $sf
        }
        if ($y0 -le $margin0) {
            $y = $y0 * $sf
        # } elseif ($y0 -gt $margin0 -and $y0 + $sh -lt $h0 - $margin0) {
        #     $y = $h / ($h0 - $sh) * $y0
            # $y = $ch - ($ch0 - $y0) * $sf
        } else {
            $y = $h - ($h0 - ($y0 + $sh)) * $sf - $sh
            # $y = $h - ($h0 - $y0) * $sf
        }
    }
    debug "Interpolation result: x = $x, y = $y"
    return $x, $y
}
# ---------------------------------------------------------------------------- #
#                                     Start                                    #
# ---------------------------------------------------------------------------- #

<#
Standard extraction
.\S-Hub\shp-extractor.ps1 "C:\Users\Jax\AppData\Roaming\JaxCore\CoreData\S-Hub\Exports\Test{}.shp"

Test flow
.\S-Hub\shp-extractor.ps1 "C:\Users\Jax\AppData\Roaming\JaxCore\CoreData\S-Hub\Exports\Test{}.shp" -extracted -nomove
#>

Write-Info "SHPEXTRACTOR REF: Experimental v1.7"
# ---------------------------- Installer variables --------------------------- #
$user = [EnvironmentVariableTarget]::User
$path = [Environment]::GetEnvironmentVariable("PATH", $user)
$paths = $path -split ";"

$s_RMSettingsFolder = $paths -match 'Rainmeter'
$s_RMINIFile = "$s_RMSettingsFolder\Rainmeter.ini"
$RMEXEloc = "$s_RMSettingsFolder\Rainmeter.exe"
# Get the set skin path
if (Test-Path $s_RMINIFile) {
    $Ini = Get-IniContent $s_RMINIFile
    $s_RMSkinFolder = $Ini["Rainmeter"]["SkinPath"].TrimEnd('\')
    $Ini = $null
} else {
    Write-Fail "Unable to locate $s_RMINIFile."
    Write-Info "S-Hub packages requires Rainmeter to be installed at the moment."
    Read-Host
    Return
}

Write-Info "Getting required information..."
# -------------------------------- Get rm bit -------------------------------- #
if (!(Get-Process Rainmeter -ErrorAction SilentlyContinue)) {
    Write-Task "Starting Rainmeter"
    rainmeter
    Wait-ForProcess 'Rainmeter'
    Write-Done
}

$rmprocess_object = Get-Process Rainmeter
$rmprocess_id = $rmprocess_object.id
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
# ---------------------------------- Screen ---------------------------------- #
Write-Task "Getting screen sizes"
$vc = Get-WmiObject -class "Win32_VideoController"
$w = $vc.CurrentHorizontalResolution
$h = $vc.CurrentVerticalResolution
Write-Done
# ---------------------------------- Restore --------------------------------- #

if (!$o_noExtract) {
    $confirmation = Read-Host "Do you want to create a system restore point? (y/n)"
    if ($confirmation -match '^y$') {
        Write-Task "Generating system restore point"
        Checkpoint-Computer -Description "JaxCore SHP installation"
        Write-Done
    }
}
Write-Info "Please select the themes and modules that you want to import."
$o_toImport = Read-Host @"
A - Import all
R - Rainmeter skins
C - JaxCore modules
W - Windows visual style
B - BetterDiscord theme
S - Spicetify theme
F - Firefox custom css

Input example: "RCW" (To import Rainmeter, JaxCore and Windows only)
Input example: "A" (To import all available themes)

Selection
"@
if ($o_toImport) {
    $o_toImport = $o_toImport.ToCharArray()
} else {
    Write-Fail "Nothing to import, aborting"
    Read-Host
    Return
}
# ---------------------------- Create cache folder --------------------------- #
$s_cache_location = "$(Split-Path $s_RMSkinFolder)\CoreData\S-Hub\Import_Cache"
if (!$o_noExtract) {
    if (Test-Path -Path "$s_cache_location") {
        Remove-Item "$s_cache_location" -Recurse -Force
    }
    New-Item -Path "$s_cache_location" -ItemType "Directory" > $null
}
# ------------------------------- Unzip pacakge ------------------------------ #
Write-Task "Expanding $s_Path to $s_cache_location"
if (!$o_noExtract -or !(Test-Path "$s_cache_location\SHP-data.json")) {
    Copy-Item -Path "$s_Path" -Destination "$s_cache_location\$($s_Path | Split-Path -Leaf).zip"
    $ProgressPreference = 'SilentlyContinue'
    Expand-Archive -Path "$s_cache_location\$($s_Path | Split-Path -Leaf).zip" -DestinationPath "$s_cache_location" -Force
    Remove-Item "$s_cache_location\$($s_Path | Split-Path -Leaf).zip"
} 
Write-Done
# --------------------------------- SHP data --------------------------------- #
$SHPData = Get-Content -Raw "$s_cache_location\SHP-data.json" | ConvertFrom-Json
$s_name = $SHPData.Data.SetupName -replace '{.*}$'
if ($s_name -eq $null) {
    Write-Fail "Invalid SHP package file."
    Return
}
# ------------------------------ Windows details ----------------------------- #
$WinBuild = $([System.Environment]::OSVersion.Version.Build)
$WinVer = [int]((Get-WmiObject -class Win32_OperatingSystem).Caption -replace "[^0-9]" , '')
# ------------------------------- Start extract ------------------------------ #
Write-Info "Starting extraction..."
debug "SetupDir: $s_Path"
debug "SetupName: $s_name"
debug "RainmeterPluginsBit: $bit"
debug "RainmeterPath: $s_RMSettingsFolder"
debug "RainmeterExePath: $RMEXEloc"
debug "RainmeterSkinsPath: $s_RMSkinFolder"
debug "ScreenAreaSizes: $w x $h"
debug "WinInfo: Windows $WinVer Build $WinBuild"
# ---------------------------------------------------------------------------- #
#                             Rainmeter and JaxCore                            #
# ---------------------------------------------------------------------------- #
if ((($SHPData.Tags -contains 'Rainmeter') -or ($SHPData.Data.CoreModules.Count -gt 0)) -and ('R', 'C', 'A' | ? { $o_toImport -contains $_ })) {

    Write-Info "Rainmeter / JaxCore layout found in package"
    if (!$o_noMove) {
        # ------------------------------ Close Rainmeter ----------------------------- #
        if (Get-Process 'Rainmeter' -ErrorAction SilentlyContinue) {
            Write-Task "Ending Rainmeter & potential AHKv1 process"
            Stop-Process -Name 'Rainmeter'
            if (Get-Process 'AHKv1' -ErrorAction SilentlyContinue) {
                Stop-Process -Name 'AHKv1'
            }
            Write-Done
        }
        # -------------------------------- Get layout -------------------------------- #
        Write-Task "Getting current Rainmeter layout"
        $Ini = Get-IniContent $s_RMINIFile
        $isCoreCheckingUpdate = $Ini["#JaxCore\Accessories\UpdatePrompt"].Active
        Write-Done
        # ------------------------------ Dynamic coords ------------------------------ #
        Write-Task "Intepretating skin coordinates and applying dynamic scale"
        $Ini = Get-IniContent "$s_cache_location\Rainmeter.ini"
        $tagged_modules = "ValliStart|YourFlyouts|YourMixer|IdleStyle"

        # Properties for interpolation
        $w0 = $SHPData.Data.ScreenSizeW
        $h0 = $SHPData.Data.ScreenSizeH
        $m = 250
        # Loop
        [string[]]$Ini.Keys | Where-Object { $_ -notmatch $tagged_modules } | ForEach-Object { 
            $x0 = [int]$Ini[$_].WindowX
            $y0 = [int]$Ini[$_].WindowY
            $sw = [int]$Ini[$_].WindowW
            $sh = [int]$Ini[$_].WindowH

            debug "$($_): $x0, $y0"
            $x, $y = coords-interp

            $Ini[$_].WindowX = $x
            $Ini[$_].WindowY = $y
        }
        Write-Done
        # ------------------------------ JaxCore updater ----------------------------- #
        if ($isCoreCheckingUpdate -eq '1') {
            Write-Task "Setting activeness of presistent skins"
            $Ini["#JaxCore\Accessories\UpdatePrompt"] = @{'Active'='1'}
            Write-Done
        }
        Set-IniContent $Ini "$s_cache_location\Rainmeter.ini"
        # ----------------------------------- Move ----------------------------------- #
        Write-Task "Moving Rainmeter layout"
        New-Item -Path "$s_RMSettingsFolder\Layouts\$s_name" -ItemType "Directory" > $null
        Move-Item -Path "$s_cache_location\Rainmeter.ini" -Destination "$s_RMSettingsFolder\Layouts\$s_name" -Force
        Write-Done
    }
}
# ---------------------------------------------------------------------------- #
#                                   Rainmeter                                  #
# ---------------------------------------------------------------------------- #
if (($SHPData.Tags -contains 'Rainmeter') -and ('R', 'A' | ? { $o_toImport -contains $_ })) {
    Write-Info "Rainmeter found in package"
    if (!$o_noMove) {
        # Move Rainmeter skins
        Get-ChildItem -Path "$s_cache_location\Rainmeter\Skins\" | ForEach-Object {
            $currentSkin = $_.Name
            if (Test-Path "$s_RMSkinFolder\$currentSkin") {
                if ($confirmation -notmatch '^a$') {
                    $confirmation = Read-Host "`nDo you want to replace `"$currentSkin`" in Rainmeter with the one from this package? (y/n/a) [y - yes][n - no][a - yes to all]"
                    if ($confirmation -match '^n$') {
                        return
                    }
                }
                Write-Task "Removing and re-adding `"$currentSkin`""
                Remove-Item -Path "$s_RMSKINFolder\$currentSkin\" -Recurse -Force
                New-Item -Path "$s_RMSKINFolder\$currentSkin" -ItemType "Directory" > $null
                Move-Item -Path "$s_cache_location\Rainmeter\Skins\$currentSkin\*" -Destination "$s_RMSkinFolder\$currentSkin\" -Force
                Write-Done
            } else {
                Write-Task "Moving `"$currentSkin`" to skins folder"
                New-Item -Path "$s_RMSKINFolder\$currentSkin" -ItemType "Directory" > $null
                Move-Item -Path "$s_cache_location\Rainmeter\Skins\$currentSkin\*" -Destination "$s_RMSkinFolder\$currentSkin\" -Force
                Write-Done
            }
        }
        if (Test-Path -Path "$s_cache_location\Rainmeter\Plugins\*") {
            $i_targetlocation = "$($s_RMSettingsFolder)\Plugins\"
            if (!(Test-Path "$i_targetlocation\")) { New-Item -Path "$i_targetlocation" -Type "Directory" -Force }
            Get-ChildItem -Path "$s_cache_location\Rainmeter\Plugins" | ForEach-Object {
                $i_plugin = "$($_.Name).dll"
                $i_pluginlocation = "$($_.FullName)\$bit\$i_plugin"
                if (Test-Path "$i_targetlocation\$i_plugin") {
                    $i_plugin_ver = Get-PluginVersion "$i_pluginlocation"
                    $i_plugin_localVer = Get-PluginVersion "$i_targetlocation\$i_plugin"
                    if ($i_plugin_localVer -lt $i_plugin_ver) {
                        Write-Task "Replacing plugin $i_plugin"
                        Remove-Item "$i_targetlocation\$i_plugin" -Force
                        Copy-Item -Path "$i_pluginlocation" -Destination "$i_targetlocation" -Force
                        Write-Done
                    } else {
                        debug "$i_plugin not replaced: Local $i_plugin_localVer >= Package $i_plugin_ver"
                    }
                } else {
                    Write-Task "Moving plugin $i_plugin"
                    Copy-Item -Path "$i_pluginlocation" -Destination "$i_targetlocation" -Force
                    Write-Done
                }
            }
            Write-Done
        }
    }
}
# ---------------------------------------------------------------------------- #
#                                    JaxCore                                   #
# ---------------------------------------------------------------------------- #
if (($SHPData.Data.CoreModules.Count -gt 0) -and ('C', 'A' | ? { $o_toImport -contains $_ })) {
    Write-Info "JaxCore modules found in package"
    if (!$o_noMove) {
        $o_InstallModule = @()
        $SHPData.Data.CoreModules | ForEach-Object {
            $currentModule = $_
            if (Test-Path "$s_RMSkinFolder\$currentModule") {
                Apply-Variables $currentModule
            } else {
                $hasModuleToDownload = $true
                $o_InstallModule += $currentModule
                debug "Added $_ to the list of modules pending to install"
            }
        }
        if ($hasModuleToDownload) {
            $o_FromSHUB = $true
            $o_Force = $true
            $o_Location = Split-Path $s_RMSettingsFolder
            Write-Divider "JaxCore Installer"
            iwr -useb 'https://raw.githubusercontent.com/Jax-Core/JaxCore/master/CoreInstaller.ps1' | iex
            Write-Divider "Install End"
            foreach($module in $o_InstallModule) {
                Apply-Variables $module
            }
        }
        Write-Done
    }
}
# ---------------------------------------------------------------------------- #
#                                   Spicetify                                  #
# ---------------------------------------------------------------------------- #
if (($SHPData.Tags -contains 'Spicetify') -and ('S', 'A' | ? { $o_toImport -contains $_ })) {
    Write-Info "Spicetify found in package (pre)"
    $spicetify_detected = Get-Command spicetify -ErrorAction Silent

    if ($spicetify_detected -eq $null) {
        Write-Info 'Spicetify not found in local (nil)'
        $confirmation = $null
        $confirmation = Read-Host 'Install Spicetify (https://spicetify.app/) to customize Spotify? (y/n)'
        if ($confirmation -match '^y$') {
            Write-Divider "Spicetify Installer"
            iwr -useb 'https://raw.githubusercontent.com/Jax-Core/JaxCore/main/S-Hub/shp-spicetify.ps1' | iex
            Write-Divider "Install End"

            Write-Divider "Spicetify Init"
            spicetify.exe backup apply
            Write-Divider "Init End"
        }
    }
    if ($spicetify_detected -ne $null -or $confirmation -match '^y$') {
        Write-Info 'Spicetify found in local (set)'
        $spicetify_configpath = spicetify.exe -c
        $spicetify_path = "$spicetify_configpath\..\"

        debug "Applying settings"
        Write-Task "Changing spicetify key values"
        if (!$o_noMove) {
            spicetify.exe config current_theme $SHPData.Spicetify.current_theme > $null
            spicetify.exe config color_scheme $SHPData.Spicetify.color_scheme > $null
        }
        Write-Done
        if ($SHPData.Spicetify.extensions) {
            Write-Task "Changing & moving extensions to spicetify directory"
            if (!$o_noMove) {
                spicetify.exe config extensions $SHPData.Spicetify.extensions > $null
                Move-Item -Path "$s_cache_location\AppSkins\Spicetify\Extensions\*" -Destination "$($spicetify_path)Extensions\$($SHPData.Spicetify.extensions)"
            }
            Write-Done
        }
        
        Write-Task "Copying theme assets to themes folder"
        if (!$o_noMove) {
            New-Item -Path "$spicetify_path\Themes\$($SHPData.Spicetify.current_theme)" -Type "Directory"
            Move-Item -Path "$s_cache_location\AppSkins\Spicetify\Themes\*" -Destination "$($spicetify_path)Themes\$($SHPData.Spicetify.current_theme)" -Recurse
        }
        Write-Done

        Write-Task "Applying spicetify theme"
        if (!$o_noMove) {
            Write-Divider "Spicetify Apply"
            ECHO Y | spicetify.exe apply
            Write-Divider "Apply End"
        }
        Write-Done
    }
}
# ---------------------------------------------------------------------------- #
#                                 BetterDiscord                                #
# ---------------------------------------------------------------------------- #
if (($SHPData.Tags -contains 'BetterDiscord') -and ('B', 'A' | ? { $o_toImport -contains $_ })) {
    Write-Info "BetterDiscord found in package (pre)"
    $bd_path = "$env:APPDATA\BetterDiscord"
    if (Test-Path -Path $bd_path) {
        Write-Info 'BetterDiscord found in local (set)'
        $bd_data_folders = Get-ChildItem -Path "$bd_path\data" -Directory

        if ($bd_data_folders.Count -eq 1) {
            $bd_selected_folder = $bd_data_folders
        } else {
            $bd_selected_folder = $bd_data_folders[0]
        }
        debug "Found bd:$bd_selected_folder"
        $bd_themelist = $SHPData.BetterDiscord.themelist

        if (!$o_noMove) {Get-Process | Where-Object -Property ProcessName -match "^Discord.*" | Stop-Process}

        $bd_themeconfig = "$bd_path\data\$($bd_selected_folder)\themes.json"
        
        if (Test-Path -Path $bd_themeconfig) {
            $bd_themes = Get-Content -Path $bd_themeconfig | ConvertFrom-Json
        } else {
            $bd_themes = @{}
        }
        Write-Task "Generating new theme config"
        if (!$o_noMove) {
            foreach($theme in $bd_themelist) {
                $bd_themes | Add-Member -NotePropertyName "$theme" -NotePropertyValue $true -Force
            }
            Remove-Item -Path $bd_themeconfig -Force
            $bd_themes | ConvertTo-Json -depth 2 | Out-File $bd_themeconfig -Force
            $bd_themeconfig_raw = (Get-Content -Path $bd_themeconfig -Raw) -replace "(?s)`r`n\s*$"
            [system.io.file]::WriteAllText($bd_themeconfig,$bd_themeconfig_raw)
        }
        Write-Done

        Write-Task "Moving theme files to theme directory"
        if (!$o_noMove) {Move-Item -Path "$s_cache_location\AppSkins\BetterDiscord\*" -Destination "$bd_path\themes\" -Force}
        Write-Done
    } else {
        Write-Info 'BetterDiscord not found in local (nil)'
    }
}
# ---------------------------------------------------------------------------- #
#                                    Firefox                                   #
# ---------------------------------------------------------------------------- #
if (($SHPData.Tags -contains 'Firefox') -and ('F', 'A' | ? { $o_toImport -contains $_ })) {
    Write-Info "Firefox found in package (pre)"
    $ff_path = "$env:APPDATA\Mozilla\Firefox"
    $ffconfig_path = "$ff_path\profiles.ini"
    if (Test-Path -Path $ffconfig_path) {
        Write-Info 'Firefox found in local (set)'
        Write-Task "Reading firefox config file"
        $ffconfig = Get-IniContent $ffconfig_path
        $ff_currentuserprofile = $ffconfig[0]["Default"]
        Write-Done
        $ff_prefchanges=@"
user_pref("toolkit.legacyUserProfileCustomizations.stylesheets", true);
user_pref("layers.acceleration.force-enabled", true);
user_pref("gfx.webrender.all", true);
user_pref("svg.context-properties.content.enabled", true);
"@
        Write-Task "Reading $ff_currentuserprofile\prefs.js"
        $prefsPath = "$ff_path\$ff_currentuserprofile\prefs.js"
        $prefsFile = Get-Item -Path ($prefsPath) | Get-Content
        Write-Done

        Write-Task "Applying config settings to prefs.js"
        foreach ($line in $prefsFile){
            if ($line -like 'user_pref("network.proxy.*') {
                $line = $null
            }
        }
        if (!$o_noMove) {
            Set-Content $prefsPath $prefsFile
            Add-Content $prefsPath $ff_prefchanges
        }
        Write-Done

        Write-Task "Moving user css files"
        if (!$o_noMove) {
            New-Item -Path "$ff_path\$ff_currentuserprofile\chrome" -Type "Directory" > $null
            Move-Item -Path "$s_cache_location\AppSkins\Firefox\*" -Destination "$ff_path\$ff_currentuserprofile\chrome\" -Force
        }
        Write-Done
    } else {
        Write-Info 'Firefox not found in local (nil)'
    }
}
# ---------------------------------------------------------------------------- #
#                                  Windows VS                                  #
# ---------------------------------------------------------------------------- #
if (($SHPData.Tags -contains 'WinVS') -and ('W', 'A' | ? { $o_toImport -contains $_ })) {
    Write-Info "Windows visual style found in package"
    $confirmation = 'y'
    if ($SHPData.Data.WinVer -ne $WinVer) {
        $confirmation = 'n'
        $confirmation = Read-Host "The Windows Visual Style from this theme runs on Windows $($SHPData.Data.WinVer), do you want to proceed importing it? (y/n)"
    }
    if ($confirmation -match '^y$') {
        Write-Task "Moving visual style files to C:\Windows\Resources\"
        if (!$o_noMove) {Move-Item -Path "$s_cache_location\WinVS\*" -Destination "C:\Windows\Resources\" -Force}
        Write-Done
        Write-Task "Applying visual theme"
        if (!$o_noMove) {Invoke-Item $SHPData.Data.WinVS}
        Write-Done
    }
}
# ---------------------------------------------------------------------------- #
#                                   Wallpaper                                  #
# ---------------------------------------------------------------------------- #

Write-Info "Applying wallpaper..."
$wallpaper_name = Get-Item "$s_cache_location\Wallpaper\*" | Select-Object Name
Write-Task "Setting wallpaper `"$s_cache_location\Wallpaper\$($wallpaper_name.Name)`""
if (!$o_noMove) {
    # Move-Item -Path "$s_cache_location\Wallpaper\$($wallpaper_name.Name)" -Destination "C:\Users\$ENV:USERNAME\AppData\Roaming\Microsoft\Windows\Themes" -Force
    Set-WallPaper "$s_cache_location\Wallpaper\$($wallpaper_name.Name)"
}
Write-Done

# ------------------------------------ .. ------------------------------------ #
Write-Info "Finalizing"
Write-Task "Clearing cache and applying changes"
if (!$o_noMove) {
    if ((($SHPData.Tags -contains 'Rainmeter') -or ($SHPData.Data.CoreModules.Count -gt 0)) -and ('R', 'C', 'A' | ? { $o_toImport -contains $_ })) {
        Start-Process "$RMEXEloc"
        Wait-ForProcess 'Rainmeter'
        Start-Sleep -Milliseconds 500
        & "$RMEXEloc" [!LoadLayout "$s_name"]
    }

    if (($SHPData.Tags -contains 'BetterDiscord') -and ('B', 'A' | ? { $o_toImport -contains $_ })) {
        If ($bd_selected_folder -contains 'Stable') {
            & "$ENV:LOCALAPPDATA\Discord\Update.exe" --processStart Discord.exe
        } else {
            & "$ENV:LOCALAPPDATA\Discord$bd_selected_folder\Update.exe" --processStart DiscordCanary.exe
        }
    }

    if (($SHPData.Tags -contains 'Firefox') -and ('F', 'A' | ? { $o_toImport -contains $_ })) {
        Start-Process Firefox
    }
}
Write-Done