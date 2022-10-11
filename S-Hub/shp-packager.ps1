using namespace System.Collections.Generic; using namespace System.Text
<#

>>==SCRIPT PARAMETERS==<<
$o_name             - Name of package
$o_noDiscord        - don't package BetterDiscord?
$o_noSpotify        - don't package Spicetify theme?
$o_noFirefox        - don't package Firefox profile?
$o_noWinVS          - don't package Windows visual style?
$o_noRainmeter      - don't package Rainmeter skins?
$o_noCore           - don't package JaxCore modules?
$o_saveLocation     - location to save generated folder structure [==Default set when running==]
$o_saveLocationSHP  - location to export the package [==Default set when running==]
$o_keepGenerated    - keep generated folder structure?
$o_noCopy           - copy files to structure?
$o_noCompile        - compile SHP package? (debug only)

#>

param(
    [Parameter(Mandatory=$true)][Alias("n")][ValidateNotNullOrEmpty()][string]$o_name,
    [Alias("D")][switch]$o_noDiscord,
    [Alias("S")][switch]$o_noSpotify,
    [Alias("F")][switch]$o_noFirefox,
    [Alias("W")][switch]$o_noWinVS,
    [Alias("R")][switch]$o_noRainmeter,
    [Alias("C")][switch]$o_noCore,
    [Alias("locsave")][string]$o_saveLocation,
    [Alias("locexport")][string]$o_saveLocationSHP,
    [Alias("keep")][switch]$o_keepGenerated,
    [Alias("nocopy")][switch]$o_noCopy,
    [Alias("nocompile")][switch]$o_noCompile
) 

$ErrorActionPreference = 'SilentlyContinue'

Add-Type -TypeDefinition '
    using System;
    using System.Runtime.InteropServices;
    using System.Text;

    public class WindowTools
    {
        public delegate bool EnumWindowsProc(IntPtr hWnd, int lParam);

        [DllImport("user32.dll")]
        public static extern bool EnumWindows(EnumWindowsProc enumFunc, int lParam);

        [DllImport("user32.dll")]
        public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        [DllImport("user32.dll")]
        public static extern IntPtr GetShellWindow();

        [DllImport("user32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool GetWindowRect(IntPtr hWnd, out RECT lpRect);

        [DllImport("user32.dll")]
        public static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);

        [DllImport("user32.dll")]
        public static extern int GetWindowTextLength(IntPtr hWnd);

        [DllImport("user32.dll")]
        public static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint lpdwProcessId);

        [DllImport("user32.dll")]
        public static extern bool IsWindowVisible(IntPtr hWnd);

        [DllImport("user32.dll")]
        public static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, int uFlags);

        [DllImport("user32.dll")]
        public static extern bool CloseWindow(IntPtr hWnd);

        [DllImport("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, uint Msg, uint wParam, uint lParam);
    }

    public struct RECT
    {
        public int Left;        // x position of upper-left corner
        public int Top;         // y position of upper-left corner
        public int Right;       // x position of lower-right corner
        public int Bottom;      // y position of lower-right corner
    }
'

class OpenWindow {
    [string] $Title
    [IntPtr] $Handle
    [UInt32] $ProcessID
}

# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

# -------------------------------- Window size ------------------------------- #

function Get-OpenWindow {
    [CmdletBinding()]
    param (
        [String]$Name = '*'
    )

    $handles = [List[IntPtr]]::new()
    $shellWindowhWnd = [WindowTools]::GetShellWindow()

    $null = [WindowTools]::EnumWindows(
        {
            param (
                [IntPtr] $handle,
                [int]    $lParam
            )

            if ($handle -eq $shellWindowhWnd) {
                return $true
            }

            if (-not [WindowTools]::IsWindowVisible($handle)) {
                return $true
            }

            $handles.Add($handle)

            return $true
        },
        0
    )

    foreach ($handle in $handles) {
        $titleLength = [WindowTools]::GetWindowTextLength($handle)
        if ($titleLength -gt 0) {
            $titleBuilder = [StringBuilder]::new($titleLength)
            $null = [WindowTools]::GetWindowText(
                $handle,
                $titleBuilder,
                $titleLength + 1
            )
            $title = $titleBuilder.ToString()

            if ($title -like $Name) {
                $processID = 0
                $null = [WindowTools]::GetWindowThreadProcessId(
                    $handle,
                    [ref]$ProcessID
                )

                [OpenWindow]@{
                    Title     = $title
                    Handle    = $handle
                    ProcessId = $ProcessID
                }
            }
        }
    }
}

function Get-WindowPosition {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory, ValueFromPipeline, ParameterSetName = 'FromInputObject')]
        [OpenWindow]$InputObject
    )

    process {
        $rect = [RECT]::new()

        $null = [WindowTools]::GetWindowRect(
            $InputObject.Handle,
            [ref]$rect
        )

        [PSCustomObject]@{
            Title     = $InputObject.Title
            Handle    = $InputObject.Handle
            ProcessID = $InputObject.ProcessID
            Left      = $rect.Left
            Top       = $rect.Top
            Right     = $rect.Right
            Bottom    = $rect.Bottom
        }
    }
}

# -------------------------------- Write-Host -------------------------------- #

function Write-Task ([string] $Text) {
  Write-Host $Text -NoNewLine
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

function Write-Divider {
    Write-Host "============================================" -BackgroundColor "Gray"
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
                    if ($ExcludeFolders -contains $folderName) { $copy; break }
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

# ---------------------------------------------------------------------------- #
#                                     Start                                    #
# ---------------------------------------------------------------------------- #

<#
Standard compiling
.\S-Hub\shp-packager.ps1 -n "Test" -S -F

Test flow
.\S-Hub\shp-packager.ps1 -n "Test" -keep -nocompile
#>

Write-Info "SHPPACKAGER REF: Experimental v1.8"
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
    $s_RMVault = "$s_RMSkinFolder\@Vault\Plugins"
    $Ini = $null
} else {
    Write-Fail "Unable to locate $s_RMINIFile."
    Write-Info "Make sure you've registered the paths with S-Hub packager tool in JaxCore."
    Return
}
# ----------------------------- Default locations ---------------------------- #
if (!$o_saveLocation) {$o_saveLocation = "$s_RMSkinFolder\..\CoreData\S-Hub\Generated"}
if (!$o_saveLocationSHP) {$o_saveLocationSHP = "$s_RMSkinFolder\..\CoreData\S-Hub\Exports"}
# Set running directory
[System.IO.Directory]::SetCurrentDirectory($o_saveLocationSHP)

Write-Info "Getting required information..."
# -------------------------------- Get rm bit -------------------------------- #
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
Add-Type -AssemblyName System.Windows.Forms
$sa_Top = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Top
$sa_Left = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Left
$sa_Bottom = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Bottom
$sa_Right = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Right
$saw = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Width
$sah = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Height
Write-Done
debug "SCREEN TLBR: $sa_Top, $sa_Left, $sa_Bottom, $sa_Right"
if ($saw -eq $null) {
    while ($true) {
        $saw = Read-Host 'Unable to detect monitor width. Please enter the width of the primary monitor in pixels as a whole number'
        if ($saw -gt 0) {
            while ($true) {
                $sah = Read-Host 'Unable to detect monitor height. Please enter height width of the primary monitor in pixels as a whole number'
                if ($sah -gt 0) {
                    Break
                } else {
                    Continue
                }
            }
            Break
        } else {
            Continue
        }
    }
}
$WinVer = [int]((Get-WmiObject -class Win32_OperatingSystem).Caption -replace "[^0-9]" , '')
if ($WinVer -eq $null) {
    $WinVer = [int]((Get-ComputerInfo).WindowsProductName -replace "[^0-9]" , '')
}
# ----------------------------- Get display scale ---------------------------- #
Add-Type @'
  using System;
  using System.Runtime.InteropServices;
  using System.Drawing;

  public class DPI {
    [DllImport("gdi32.dll")]
    static extern int GetDeviceCaps(IntPtr hdc, int nIndex);

    public enum DeviceCap {
      VERTRES = 10,
      DESKTOPVERTRES = 117
    }

    public static float scaling() {
      Graphics g = Graphics.FromHwnd(IntPtr.Zero);
      IntPtr desktop = g.GetHdc();
      int LogicalScreenHeight = GetDeviceCaps(desktop, (int)DeviceCap.VERTRES);
      int PhysicalScreenHeight = GetDeviceCaps(desktop, (int)DeviceCap.DESKTOPVERTRES);

      return (float)PhysicalScreenHeight / (float)LogicalScreenHeight;
    }
  }
'@ -ReferencedAssemblies 'System.Drawing.dll'

$WinScale = [Math]::round([DPI]::scaling(), 2)
# ------------------------------- Start package ------------------------------ #
debug "SetupName: $o_name"
debug "RainmeterPluginsBit: $bit"
debug "RainmeterPath: $s_RMSettingsFolder"
debug "RainmeterExePath: $RMEXEloc"
debug "RainmeterSkinsPath: $s_RMSkinFolder"
debug "SavingDirectory_Generated: $o_saveLocation"
debug "SavingDirectory_SHP: $o_saveLocationSHP"
debug "PrimaryScreenAreaSizes: $saw x $sah"

# ------------------------- Create SHPData structure ------------------------- #
$SHPInfo = @{'SetupName'=$o_name;'ScreenSizeW'=$saw;'ScreenSizeH'=$sah;'CoreModules'='';'DLCs'=@();'WinBuild'=$([System.Environment]::OSVersion.Version.Build);'WinVer'=$WinVer;'WinScale'=$WinScale;'WinVS'=''}
$SHPRainmeter = @{'Skins'=''}
$SHPBetterDiscord = @{'themelist'=@()}
$SHPSpicetify = @{'current_theme'='';'color_scheme'='';'extensions'=''}
$SHPFirefox = @{}
$SHPData = @{'Data'=$SHPInfo;'Rainmeter'=$SHPRainmeter;'BetterDiscord'=$SHPBetterDiscord;'Spicetify'=$SHPSpicetify;'Firefox'=$SHPFirefox;'Tags'=@()}
# -------------------------------- Name to id -------------------------------- #
$s_NameToID = @{
    "YourFlyouts"="0";
    "YourMixer"="1";
    "ValliStart"="2";
    "Rainmeter"="R";
    "Firefox"="F";
    "Spicetify"="S";
    "BetterDiscord"="B";
    "WinVS"="W"
}
# ------------------------------ Wipe directory ------------------------------ #
Write-Task "Wiping generation directory"
if (Test-Path -Path "$o_saveLocation") {Remove-Item "$o_saveLocation" -Recurse -Force > $null}
Write-Done
# ----------------------------- Create directory ----------------------------- #
Write-Task "Creating new directory"
New-Item -Path "$o_saveLocation" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\Rainmeter" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\Rainmeter\Skins" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\Rainmeter\Plugins" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\Wallpaper" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\Spicetify" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\Spicetify\Themes" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\Spicetify\Extensions" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\BetterDiscord" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\Firefox" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\WinVS" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocationSHP" -ItemType "Directory" > $null
Write-Done
# ---------------------------------------------------------------------------- #
#                             Rainmeter and JaxCore                            #
# ---------------------------------------------------------------------------- #
# ------------------------ Get JaxCore module details ------------------------ #
Write-Task "Reading remote ModuleDetails.ini"
$ModuleDetails = Get-RemoteIniContent 'https://raw.githubusercontent.com/Jax-Core/JaxCore/main/S-Hub/ModuleDetails.ini'
# Pre-defined stuff
$tagged_modules = "ValliStart|YourFlyouts|YourMixer|Droptop"
$custom_userimages = @{
    'ModularVisualizer' = 
    @{
        '@Resources\Vars.inc'='ImageUnderlayName';
        '@Resources\LayeringVars.inc'='ImagePath'
    };
    'ValliStart' = 
    @{
        '@Resources\Vars.inc'='ImageUnderlayPath'
    }
}
$jaxcore_modules = $ModuleDetails.Keys | Where-Object {$_ -notmatch "Setup|Version|JaxCore"}
$exclude_plugins = $ModuleDetails.Version.Keys
$s_RMINIFile_filterpattern = "^Rainmeter$","^#JaxCore","^Keylaunch","^QuickNotes","^MIUI-Shade","^Keystrokes","^IdleStyle","@Start$","^;","^TaskbarX","^Polybar" -join '|'
Write-Done
# ---------------------------- Read Rainmeter.ini ---------------------------- #
Write-Task "Getting Rainmeter layout..."
$Ini = Get-IniContent $s_RMINIFile
Write-Done

debug "Found $($Ini.Count) sections in $s_RMINIFile"
# -------------------------- Filter through sections ------------------------- #
Write-Task "Filtering through Rainmeter sections"
[string[]]$Ini.Keys | Where-Object { $Ini[$_].Active -contains "0" -or $_ -match $s_RMINIFile_filterpattern } | ForEach-Object { 
    $Ini.Remove($_)
}
# ----------------------------- Tag modules & WH ----------------------------- #
function isOffscreen($st, $sl, $sb, $sr) {
    debug "TLBR: $st, $sl, $sb, $sr"
    # If rectangle has area 0, no overlap
    if ($sl -eq $sr -or $st -eq $sb) {
        return $true
    }
    # If one rectangle is on left side of other
    if ($sl -gt $sa_Right -or $sa_Left -gt $sr) {
        return $true
    }
    # If one rectangle is above other
    if ($sb -lt $sa_Top -or $sa_Bottom -lt $st) {
        return $true
    }
 
    return $false
}
[string[]]$Ini.Keys | ForEach-Object { 
    $currentSection = $_
    
    if ($_ -notmatch "$tagged_modules") {
        Get-ChildItem -Path "$s_RMSkinFolder\$currentSection" -File | ForEach-Object {
            debug "Getting window property of $s_RMSkinFolder\$currentSection\$($_.Name)"
            $currentSWH = Get-OpenWindow "$s_RMSkinFolder\$currentSection\$($_.Name)" | Get-WindowPosition
            if ($currentSWH -ne $null) {
                if (isOffscreen $currentSWH.Top $currentSWH.Left $currentSWH.Bottom $currentSWH.Right) {
                    debug "$currentSection is off screen"
                    $Ini.Remove($currentSection)
                } else {
                    debug  "$currentSection is on screen"
                }
            }
        }
    } elseif ($currentSection -match "^($tagged_modules)\\Main$") {
        if (!$o_noCore) {
            $currentSection = $currentSection -replace '\\.*$', ''
            debug "Valid SHP Tag: $currentSection"
            $SHPData.Tags += $currentSection
        } else {
            $Ini.Remove($currentSection)
        }
    } elseif ($currentSection -match "^($tagged_modules)?\\.*$") {
        $Ini.Remove($currentSection)
    } else {
        $Ini[$currentSection].WindowW = $currentSWH.Right - $currentSWH.Left
        $Ini[$currentSection].WindowH = $currentSWH.Bottom - $currentSWH.Top
    }
}
Write-Done
# ----------------------- Convert sections to skin name ---------------------- #
$valid_skins = [string[]]$Ini.Keys | ForEach-Object { $_ -replace '\\.*$', '' }
# --------------------------- Work with valid skins -------------------------- #
Write-Task "Copying Rainmeter and JaxCore items"
$i = 0
$ii = 0
$skins = @()
$valid_jaxcore_modules = @()
$valid_skins | select-object -unique | ForEach-Object { 
    if ($jaxcore_modules -contains $_) {
        if (!$o_noCore) {
            $ii++
            $valid_jaxcore_modules += $_
            $skin_varf = $ModuleDetails["$_"].VarFiles -split '\s\|\s' | Where-Object {$_ -notmatch "WelcomeVars|Hotkeys"}

            if (!$o_noCopy) {
                foreach ($varf in $skin_varf) {
                    if (Test-Path -path "$s_RMSkinFolder\$varf") {
                        # ----------------------------------- Copy ----------------------------------- #
                        $i_savedir = "$o_saveLocation\Rainmeter\JaxCore\$(Split-Path $varf)"
                        $i_savelocation = "$o_saveLocation\Rainmeter\JaxCore\$varf"
                        if (!(Test-Path "$i_savedir")) { New-Item -Path "$i_savedir" -Type "Directory" > $null }
                        Copy-Item -Path "$s_RMSkinFolder\$varf" -Destination "$i_savelocation" -Force > $null
                        # --------------------------------- Check DLC -------------------------------- #
                        if ($($ModuleDetails.JaxCoreDLCs.ModuleList -Split "\|") -contains $_) {
                            foreach($dlc in $ModuleDetails.JaxCoreDLCs.DLCList -Split "\|") {
                                $dlcFound = Select-String -Path "$s_RMSkinFolder\$varf" -Pattern "$dlc"
                                if ($dlcFound -ne $null) {
                                    debug "Found $dlc in $_ as an active DLC."
                                    $SHPData.Data.DLCs += $_+'_'+$dlc
                                    Break
                                }
                            }
                        }
                    }
                }
            }

            foreach ($module in $custom_userimages.Keys) {
                if ($_ -eq $module) {
                    foreach ($varf in $custom_userimages[$module].Keys) {
                        $moduleIni = Get-IniContent "$s_RMSkinFolder\$module\$varf"
                        $current_userimage = $moduleIni.Variables.$($custom_userimages[$module][$varf])
                        if (($current_userimage -notmatch "#SKINSPATH#") -and (Test-Path -Path $current_userimage)) {
                            debug "Copying $varf from $module to root of module (user content)"
                            if (!$o_noCopy) {
                                Copy-Item -Path $current_userimage -Destination "$o_saveLocation\Rainmeter\JaxCore\$module\"
                            }
                        }
                    }
                }
            }

            if ($_ -eq 'ModularVisualizer') {
                New-Item -Path "$o_saveLocation\Rainmeter\CoreData\ModularVisualizer" -ItemType Directory > $null
                if (!$o_noCopy) {
                    Get-ChildItem "$s_RMSkinFolder\..\CoreData\ModularVisualizer\" -Directory | ForEach-Object {
                        Copy-Item -Path $_.FullName -Destination "$o_saveLocation\Rainmeter\CoreData\ModularVisualizer\" -Recurse
                    }
                }
            }
        }
    } else {
        if (!$o_noRainmeter -and (Test-Path -Path "$s_RMSkinFolder\$_")) {
            $i++
            $skins += $_
            if (!$o_noCopy) {Copy-Path -Source "$s_RMSkinFolder\$_" -Destination "$o_saveLocation\Rainmeter\Skins\$_\" -ExcludeFolders '.git'}
        }
    }
}
$SHPData.Data.CoreModules = $valid_jaxcore_modules
$SHPData.Rainmeter.Skins = $skins
if ($skins.count -ne 0) {
    $SHPData.Tags += "Rainmeter"
}
debug "$ii valid JaxCore modules configurations saved: $valid_jaxcore_modules"
debug "$i valid Rainmeter skins copied: $skins"
Write-Done
# ------------------------------- Copy plugins ------------------------------- #
Write-Task "Copying Rainmeter plugins"
if (!$o_noRainmeter) {
    $i = 0
    Get-ChildItem -Path $s_RMVault | Where-Object {$_.Name -notmatch ($exclude_plugins -join '|')} | ForEach-Object {
        $i++
        $i_Plugin = $_.Name
        Get-ChildItem -Path $_.FullName | Sort-Object Name -Descending | Select-Object -First 1 | ForEach-Object {
            if (!$o_noCopy) {Copy-Path -Source $_.FullName -Destination "$o_saveLocation\Rainmeter\Plugins\$i_Plugin\"}
        }
    }
    debug "$i valid plugins copied."
}
Write-Done
# ----------------------------- Export Rainmeter.ini ---------------------------- #
if (!$o_noRainmeter -or !$o_noCore) {
    Set-IniContent -ini $Ini -filePath "$o_saveLocation\Rainmeter.ini" -Encoding unicode -Force
}
# ---------------------------------------------------------------------------- #
#                                   Spicetify                                  #
# ---------------------------------------------------------------------------- #
if (!$o_noSpotify) {
    $spicetify_detected = Get-Command spicetify -ErrorAction Silent

    if ($spicetify_detected -ne $null) {
        Write-Task 'Getting spicetify paths'
        $spicetifyconfig_path = spicetify.exe -c
        $spicetify_path = "$spicetifyconfig_path\..\"
        Write-Done
        if (Test-Path -Path "$spicetifyconfig_path") {
            $Ini = Get-IniContent $spicetifyconfig_path
            $spicetify_current_theme = $Ini['Setting']["current_theme"]
            $spicetify_color_scheme = $Ini['Setting']["color_scheme"]
            $spicetify_extensions = $Ini['AdditionalOptions']["extensions"].Split("|")
            # Copy spicetify theme 
            Write-Task "Exporting Theme: $spicetify_current_theme, ColorScheme: $spicetify_color_scheme"
            if (!$o_noCopy) { 
                Copy-Item -Path "$spicetify_path\Themes\$spicetify_current_theme\*" -Destination "$o_saveLocation\AppSkins\Spicetify\Themes" -Exclude @("*.png", "*.jpeg") -Recurse -Force
            }
            $SHPData.Spicetify.current_theme = $spicetify_current_theme
            $SHPData.Spicetify.color_scheme = $spicetify_color_scheme
            Write-Done
            foreach ($extension in $spicetify_extensions) {
                if ($extension -match $spicetify_current_theme) {
                    Write-Task "Found corresponding plugin matching theme name $spicetify_current_theme, copying"
                    $spicetify_themeext = $extension.TrimEnd('.js')+'.js'
                    $SHPData.Spicetify.extensions = $spicetify_themeext
                    if (!$o_noCopy) { Copy-Item -Path "$spicetify_path\Extensions\$spicetify_themeext" -Destination "$o_saveLocation\AppSkins\Spicetify\Extensions" -Force }
                    Write-Done
                    Break
                }
            }
            $SHPData.Tags += 'Spicetify'
        } else {
            Write-Fail "Unable to locate $spicetifyconfig_path"
        }
    } else {
        Write-Fail 'Spicetify is not found on your device. '
    }
}

# ---------------------------------------------------------------------------- #
#                                 BetterDiscord                                #
# ---------------------------------------------------------------------------- #
if (!$o_noDiscord) {
    $bd_path = "$env:APPDATA\BetterDiscord"
    if (Test-Path -Path $bd_path) {
        Write-Task 'Getting BetterDiscord assets...'

        $bd_data_folders = Get-ChildItem -Path "$bd_path\data" -Directory
        if ($bd_data_folders.Count -eq 1) {
            $bd_selected_folder = $bd_data_folders
        } else {
            $bd_selected_folder = $bd_data_folders[0]
        }
        Write-Done
        Write-Task "Extracting themes from discord:data\$($bd_selected_folder)\themes.json"

        $bd_themes = Get-Content -Path "$bd_path\data\$($bd_selected_folder)\themes.json" | ConvertFrom-Json

        $i_found = $False
        $bd_themes | Get-Member | Where-Object -Property MemberType -match "NoteProperty" | Select-Object "Name" | ForEach-Object { 
            $i_bd_themename = "$([string]$_.Name)"
            
            if ($($bd_themes.$i_bd_themename) -match "True") {
                debug "Theme `"$i_bd_themename`" applied, trying to find css file"
                Get-ChildItem -Path "$bd_path\themes\*" -Filter *.theme.css | ForEach-Object {
                    $a = Get-Content $_ -First 2
                    $a = [regex]::match($a,'/\*\*\s\s\*\s@name\s(.*)').Groups[1].Value
                    if ($i_bd_themename -contains $a.trim()) {
                        debug "Found theme in $_"
                        Copy-Item -Path "$_" -Destination "$o_saveLocation\AppSkins\BetterDiscord\" -Force
                        $SHPData.BetterDiscord.themelist += $i_bd_themename
                    }
                }
            $i_found = $True
            }
        }
        if ($i_found) {
            $SHPData.Tags += "BetterDiscord"
            Write-Done
        } else {
            Write-Fail "No active themes detected"
        }
    } else {
        Write-Fail 'BetterDiscord is not found on your device. '
    }
}
# ---------------------------------------------------------------------------- #
#                                    Firefox                                   #
# ---------------------------------------------------------------------------- #
if (!$o_noFirefox) {
    $ff_path = "$env:APPDATA\Mozilla\Firefox\"
    $ffconfig_path = "$($ff_path)profiles.ini"
    if (Test-Path -Path "$ffconfig_path") {
        Write-Task 'Getting Firefox paths'
        $Ini = Get-IniContent $ffconfig_path
        $ff_defaultprofile_path = $Ini[0]["Default"]
        Write-Done
        $ff_userchrome_path = "$($ff_path)$ff_defaultprofile_path\chrome\*"
        if (Test-Path -Path "$ff_userchrome_path") {
            # Copy firefox theme 
            Write-Task "Exporting user css files $ff_userchrome_path"
            if (!$o_noCopy) {Copy-Item -Path "$ff_userchrome_path" -Destination "$o_saveLocation\AppSkins\Firefox\" -Force}
            $SHPData.Tags += "Firefox"
            Write-Done
        } else {
            Write-Fail "Nothing is located at $ff_userchrome_path"
        }
    } else {
        Write-Fail 'Firefox custom css is not found on your device. '
    }
}
# ---------------------------------------------------------------------------- #
#                                  Windows VS                                  #
# ---------------------------------------------------------------------------- #
if (!$o_noWinVS) {
    $currentTheme = (Get-ItemProperty "HKCU:SOFTWARE\Microsoft\Windows\CurrentVersion\Themes").CurrentTheme
    Write-Task "Exporting visual style $(Split-Path $currentTheme -leaf)"
    Copy-Item -Path $currentTheme -Destination "$o_saveLocation\WinVS\"
    Write-Done
    Write-Task "Reading $(Split-Path $currentTheme -Leaf -Resolve)"
    $WinVSdotTheme = Get-IniContent $currentTheme
    $currentThemeVSPath = ($WinVSdotTheme.VisualStyles.Path).Replace('%ResourceDir%\', 'C:\Windows\Resources\').Replace('%SystemRoot%\', 'C:\Windows\')
    $currentThemeVSPathFolder = $currentThemeVSPath | Split-Path
    $currentThemeVSPathFolderName = $currentThemeVSPathFolder | Split-Path -Leaf
    Write-Done
    If ($currentThemeVSPath -ne $null) {
        Write-Task "Copying $currentThemeVSPath"
        New-Item -Path "$o_saveLocation\WinVS\$currentThemeVSPathFolderName\" -ItemType Directory > $Null
        Copy-Item -Path "$currentThemeVSPath" -Destination "$o_saveLocation\WinVS\$currentThemeVSPathFolderName\"
        Write-Done
        If ((Get-ChildItem -Path $currentThemeVSPathFolder -Directory) -ne $null) {
            Write-Task "Copying additional files in msstyles directory"
            Get-ChildItem -Path $currentThemeVSPathFolder -Directory | ForEach-Object {
                debug $_.FullName
                Copy-Item -Path $_.FullName -Destination "$o_saveLocation\WinVS\$currentThemeVSPathFolderName\" -Recurse
            }
            Write-Done
        }
    } else {
        Write-Fail "Unable to locate $(Split-Path $currentTheme -leaf)'s msstyle directory."
    }
    $SHPData.Data.WinVS = $currentTheme
    $SHPData.Tags += "WinVS"
}
# ---------------------------------------------------------------------------- #
#                                   Wallpaper                                  #
# ---------------------------------------------------------------------------- #

Write-Task 'Getting Wallpaper...'
$wallpaper_path = Get-ItemProperty 'HKCU:\Control Panel\Desktop' | Select -exp 'Wallpaper'
Write-Done
Write-Task "Copying wallpaper from $wallpaper_path"
$wallpaper_ext = $wallpaper_path -replace '^.*\.', ''
Copy-Item -Path $wallpaper_path -Destination "$o_saveLocation\Wallpaper\Wallpaper.$wallpaper_ext" -Force
Write-Done

# ---------------------------------- Export ---------------------------------- #
Write-Task "Exporting SHP-data.ini"
$o_name += "{"
$SHPData.Tags | ForEach-Object {
    $o_name += $s_NameToID[$_]
}
$o_name += "}"

$SHPData | ConvertTo-Json -depth 10 | Out-File -FilePath "$o_saveLocation\SHP-data.json" -Encoding unicode -Force
Write-Done
Write-Task "Compiling SHP package"
if (!$o_noCompile) {
    $ProgressPreference = 'SilentlyContinue'
    Compress-Archive -Path "$o_saveLocation\*" -DestinationPath "$o_saveLocationSHP\$o_name.zip" -Force -CompressionLevel "Fastest"
    Rename-Item -Path "$o_saveLocationSHP\$o_name.zip" -NewName "$o_name.shp"
}
if (!$o_keepGenerated) {Remove-Item -Path "$o_saveLocation\*" -Recurse}
Write-Done
# Open folder
if (!$o_noCompile) {Invoke-Item $o_saveLocationSHP}
Write-Host ">>> Export success! (^ ᴗ ^) <<<" -ForegroundColor "Green"