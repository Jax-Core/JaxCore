$ErrorActionPreference = 'SilentlyContinue'

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
    $RmAPI.Bang("[!SetVariable Process.Logs `"`"`"`n$message$($RmAPI.VariableStr('Process.Logs'))`"`"`"][!UpdateMeter Logs.String][!Redraw]")

    # $RmAPI.Bang("[!Log `"`"`"S-Hub MGR: " + $message + "`"`"`" Debug]")
}

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

# ---------------------------------------------------------------------------- #
#                                     Input                                    #
# ---------------------------------------------------------------------------- #

function Change-Setting($setting, $value) {
    debug "INFO $setting -> $value"
    $RmAPI.Bang("[!SetVariable Sec.shup_info.$setting `"`"`"$value`"`"`"]")
}

# ---------------------------------------------------------------------------- #
#                                Start-Packager                                #
# ---------------------------------------------------------------------------- #

function Start-Packager {
    # ------------------------------ Import options ------------------------------ #
    $option_use_discord = $RmAPI.VariableStr('Sec.shup_setting.discord')
    $option_use_spotify = $RmAPI.VariableStr('Sec.shup_setting.spotify')
    $option_use_firefox = $RmAPI.VariableStr('Sec.shup_setting.firefox')
    $option_abspos = $RmAPI.VariableStr('Sec.shup_setting.absolute_coordinates')
    $option_name = $RmAPI.VariableStr('Sec.shup_info.name')
    $option_author = $RmAPI.VariableStr('Sec.shup_info.author')
    # ------------------------------- Code options ------------------------------- #
    $export_location = "$($RmAPI.VariableStr('SKINSPATH'))..\CoreData\S-Hub\Generated"
    $export_zip_location = "$($RmAPI.VariableStr('SKINSPATH'))..\CoreData\S-Hub\Exports"
    $shupdata_content = ""
    

    debug "> Starting packager"
    $shupdata_content += @"
[Data]
shup.Name=$option_name
shup.Author=
shup.ScreenSizeW=$($RmAPI.VariableStr('SCREENAREAWIDTH'))
shup.ScreenSizeH=$($RmAPI.VariableStr('SCREENAREAHEIGHT'))
"@
    # ------------------------------ Wipe directory ------------------------------ #
    If (Test-Path -Path "$export_location") {
        Remove-Item "$export_location" -Recurse -Force
    }
    # ----------------------------- Create directory ----------------------------- #
    New-Item -Path "$export_location" -ItemType "Directory"
    New-Item -Path "$export_location\RainmeterSkins" -ItemType "Directory"
    New-Item -Path "$export_location\Wallpaper" -ItemType "Directory"
    New-Item -Path "$export_location\AppSkins" -ItemType "Directory"
    New-Item -Path "$export_location\AppSkins\Spicetify" -ItemType "Directory"
    New-Item -Path "$export_location\AppSkins\BetterDiscord" -ItemType "Directory"
    New-Item -Path "$export_location\AppSkins\Firefox" -ItemType "Directory"
    New-Item -Path "$export_zip_location" -ItemType "Directory"
    # ---------------------------- Read Rainmeter.ini ---------------------------- #
    $rainmeterini = "$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini"
    $skinspath = "$($RmAPI.VariableStr('skinspath'))"
    $Ini = Get-IniContent $rainmeterini

    debug "Found $($Ini.Count) sections in $rainmeterini"
    # -------------------------- Filter through sections ------------------------- #
    $rainmeterini_filterpattern = "^Rainmeter$","^#JaxCore","^#Keylaunch","^DropTop","@Start$" -join '|'
    [string[]]$Ini.Keys | Where-Object { $Ini[$_].Active -contains "0" -or $_ -match $rainmeterini_filterpattern } | ForEach-Object { 
        $Ini.Remove($_)
    }
    # -------------------------------- Tag modules ------------------------------- #
    $tagged_modules = "ValliStart|YourFlyouts|YourMixer|Keylaunch|IdleStyle"
    $shupdata_content += @"

shup.Tags=
"@
    [string[]]$Ini.Keys | Where-Object { $Ini[$_].Active -contains "0" -or $_ -match $tagged_modules } | ForEach-Object { 
        $_ = $_ -replace '\\.*$', ''
        debug "INFO Tag: $_"
        $shupdata_content += @"
$_ | 
"@
    }
#     # ----------------------- Convert sections to skin name ---------------------- #
    $valid_skins = [string[]]$Ini.Keys | ForEach-Object { $_ -replace '\\.*$', '' }
#     # --------------------------- Work with valid skins -------------------------- #
    $i = 0
    $shupdata_content += @"

shup.Skins=
"@
    $valid_skins | select-object -unique | ForEach-Object { 
        $i = $i + 1
        # Add names to data
        $shupdata_content += @"
$_, 
"@
        # Copy skin contents
        Copy-Path -Source "$skinspath$_" -Destination "$export_location\RainmeterSkins\$_\" -ExcludeFolders '.git'
    }
    debug "$i valid skins copied"

    # ----------------------------- Export Rainmeter.ini ---------------------------- #
    Set-IniContent -ini $Ini -filePath "$export_location\Rainmeter.ini" -Encoding unicode -Force
    # --------------------------------- Spicetify -------------------------------- #
    If ($option_use_spotify -eq 1) {
        $spicetify_path = "C:\Users\$env:UserName\.spicetify\"
        $spicetifyconfig_path = "$($spicetify_path)config-xpui.ini"
        If (Test-Path -Path "$spicetifyconfig_path") {
            $Ini = Get-IniContent $spicetifyconfig_path
            $spicetify_current_theme = $Ini['Setting']["current_theme"]
            $spicetify_color_scheme = $Ini['Setting']["color_scheme"]
            # Copy spicetify theme 
            debug "> Found spicetify"
            debug "Exporting Theme: $spicetify_current_theme, ColorScheme: $spicetify_color_scheme"
            Copy-Item -Path "$spicetify_path\Themes\$spicetify_current_theme\*" -Destination "$export_location\AppSkins\Spicetify" -Force
            $shupdata_content += @"


[Spicetify]
current_theme=$spicetify_current_theme
color_scheme=$spicetify_color_scheme
"@
            debug "> Spicetify complete."
        }
    }

    # ------------------------------- BetterDiscord ------------------------------ #
    If ($option_use_discord -eq 1) {
        $bd_path = "$env:APPDATA\BetterDiscord"
        If (Test-Path -Path $bd_path) {
            debug "> Found BetterDiscord"

            $bd_data_folders = Get-ChildItem -Path "$bd_path\data" -Directory
            If ($bd_data_folders.Count -eq 1) {
                $bd_selected_folder = $bd_data_folders
            } else {
                $bd_selected_folder = $bd_data_folders[0]
            }
            debug "Extracting themes from bd:$bd_selected_folder"

            $bd_themes = Get-Content -Path "$bd_path\data\$($bd_selected_folder)\themes.json" | ConvertFrom-Json

            $i_found = $False
            $bd_themes | Get-Member | Where-Object -Property MemberType -match "NoteProperty" | Select-Object "Name" | ForEach-Object { 
                $i_bd_themename = "$([string]$_.Name)"
                
                If (($($bd_themes.$i_bd_themename) -match "True") -and ($i_found -eq $False)) {
                    debug "Theme `"$i_bd_themename`" applied, trying to find css file"
                    Get-ChildItem -Path "$bd_path\themes\*" -Include *.theme.css | ForEach-Object {
                        $a = Get-Content $_ -First 2
                        $a = [regex]::match($a,'/\*\*\s\s\*\s@name\s(.*)').Groups[1].Value
                        If ($i_bd_themename -contains $a) {
                            debug "Found theme in $_"
                            Copy-Item -Path "$_" -Destination "$export_location\AppSkins\BetterDiscord" -Force
                            $shupdata_content += @"


[BetterDiscord]
themename=$i_bd_themename
"@

                        }
                    }
                $i_found = $True
                
                }
            }
        debug "> BetterDiscord complete."
        }
    }
    # ---------------------------------- Firefox --------------------------------- #
    If ($option_use_firefox -eq 1) {
        $ff_path = "$env:APPDATA\Mozilla\Firefox\"
        $ffconfig_path = "$($ff_path)profiles.ini"
        If (Test-Path -Path "$ffconfig_path") {
            debug "> Found Firefox custom css"
            $Ini = Get-IniContent $ffconfig_path
            $ff_defaultprofile_path = $Ini[0]["Default"]
            debug "Found profile: $ff_defaultprofile_path"
            $ff_userchrome_path = "$($ff_path)$ff_defaultprofile_path\chrome\userChrome.css"
            If (Test-Path -Path "$ff_userchrome_path") {
                debug "Found custom css in profile"
                # Copy firefox theme 
                debug "Exporting userChrome $ff_userchrome_path"
                Copy-Item -Path "$ff_userchrome_path" -Destination "$export_location\AppSkins\Firefox" -Force
                $shupdata_content += @"


[Firefox]
found=1
"@
                debug "> Firefox complete."
            }
        }
    }

    # --------------------------------- Wallpaper -------------------------------- #

    $wallpaper_path = $RmAPI.MeasureStr('WallpaperPath')
    debug "INFO Wallpaper path: `"$wallpaper_path`""
    $wallpaper_ext = $wallpaper_path -replace '^.*\.', ''
    Copy-Item -Path $wallpaper_path -Destination "$export_location\Wallpaper\Wallpaper.$wallpaper_ext" -Force

    # ---------------------------------- Export ---------------------------------- #
    debug "Exporting shup-data.ini"
    $shupdata_content | Out-File -FilePath "$export_location\shup-data.ini" -Encoding unicode -Force
    debug "Exporting $export_zip_location\$option_name.zip"
    Compress-Archive -Path "$export_location\*" -DestinationPath "$export_zip_location\$option_name.zip" -Force
    Remove-Item -Path "$export_location\*" -Recurse
    debug "> Successfully created SHUP package `"$option_name`""

    $RmAPI.Bang("[`"$export_zip_location`"]")
}

# ---------------------------------------------------------------------------- #
#                                Import-Package                                #
# ---------------------------------------------------------------------------- #

function Import-Package($path) {
    # ------------------------ Create directory variables ------------------------ #
    $cache_location = "$($RmAPI.VariableStr('SKINSPATH'))..\CoreData\S-Hub\Import_Cache"
    If (Test-Path -Path "$cache_location") {
        Remove-Item "$cache_location" -Recurse -Force
    }
    # ---------------------------- Create cache folder --------------------------- #
    New-Item -Path "$cache_location" -ItemType "Directory"
    # ------------------------------- Unzip pacakge ------------------------------ #
    debug "INFO Selected file: $path"
    debug "Expanding $path to $cache_location"
    Expand-Archive -Path "$path" -DestinationPath "$cache_location" -Force -Verbose
    # ---------------------------- Read shup-data.ini ---------------------------- #
    $Ini = Get-IniContent "$cache_location\shup-data.ini"
    $dataIni = $Ini
    $option_name = $dataIni["Data"]["shup.Name"]
    debug "> SHUP name: `"$option_name`""
    If (Test-Path -Path "$cache_location\RainmeterSkins\*") {
        debug "> Found available Rainmeter skins to install"
        # Move Rainmeter layout
        $rmlayout_path = "$env:APPDATA\Rainmeter\Layouts\"
        New-Item -Path "$rmlayout_path\$option_name" -ItemType "Directory"
        Move-Item -Path "$cache_location\Rainmeter.ini" -Destination "$rmlayout_path\$option_name" -Force
        # Move Rainmeter skins
        debug "Moving Rainmeter skins"
        $rmskins_path = $RmAPI.VariableStr('SKINSPATH')
        Move-Item -Path "$cache_location\RainmeterSkins\*" -Destination "$rmskins_path" -Force
    }
    # --------------------------------- Spicetify -------------------------------- #
    If (Test-Path -Path "$cache_location\AppSkins\Spicetify\*") {
        debug "> Spicetify found in package"
        $spicetify_path = "C:\Users\$env:UserName\.spicetify\"
        $spicetifyconfig_path = "$($spicetify_path)config-xpui.ini"
        If (Test-Path -Path $spicetifyconfig_path) {
            debug "INFO Spicetify is installed locally, starting import"
            Get-Process 'Spotify' | Stop-Process

            debug "Applying settings"
            spicetify.exe config current_theme $dataIni["Spicetify"]["current_theme"]
            spicetify.exe config color_scheme $dataIni["Spicetify"]["color_scheme"]
            
            debug "Copying theme assets to themes folder"
            New-Item -Path "$($spicetify_path)Themes\$($dataIni["Spicetify"]["current_theme"])" -Type "Directory"
            Move-Item -Path "$cache_location\AppSkins\Spicetify\*" -Destination "$($spicetify_path)Themes\$($dataIni["Spicetify"]["current_theme"])"

            debug "Applying spicetify theme"
            ECHO Y | spicetify.exe apply

            debug "> Completed Spicetify import"
        } else {
            debug "!! Spicetify is not installed locally, returning to main process"
        }
    }
    # ------------------------------- BetterDiscord ------------------------------ #
    If (Test-Path -Path "$cache_location\AppSkins\BetterDiscord\*") {
        debug "> BetterDiscord found in package"
        $bd_path = "$env:APPDATA\BetterDiscord"
        If (Test-Path -Path $bd_path) {
            debug "INFO BetterDiscord is installed locally, starting import"
            $bd_data_folders = Get-ChildItem -Path "$bd_path\data" -Directory
            If ($bd_data_folders.Count -eq 1) {
                $bd_selected_folder = $bd_data_folders
            } else {
                $bd_selected_folder = $bd_data_folders[0]
            }
            debug "Found bd:$bd_selected_folder"
            $option_bdtheme = "$($dataIni["BetterDiscord"]["themename"])"

            Get-Process | Where-Object -Property ProcessName -match "^Discord.*" | Stop-Process

            $bd_themes = Get-Content -Path "$bd_path\data\$($bd_selected_folder)\themes.json" | ConvertFrom-Json
            $bd_themes | Add-Member -NotePropertyName "$option_bdtheme" -NotePropertyValue $true -Force
            $bd_themes | ConvertTo-Json -depth 2 | Out-File "$bd_path\data\$($bd_selected_folder)\themes.json" -Force
            
            Move-Item -Path "$cache_location\AppSkins\BetterDiscord\*" -Destination "$bd_path\themes\" -Force

            debug "> Completed BetterDiscord import"
        } else {
            debug "!! BetterDiscord is not installed locally, returning to main process"
        }
    }
    # ---------------------------------- Firefox --------------------------------- #
    If (Test-Path -Path "$cache_location\AppSkins\Firefox\*") {
        debug "> Firefox found in package"
        $ff_path = "$env:APPDATA\Mozilla\Firefox\"
        $ffconfig_path = "$($ff_path)profiles.ini"
        If (Test-Path -Path $ffconfig_path) {
            debug "INFO Firefox is installed locally, starting import"
            $Ini = Get-IniContent $ffconfig_path
            $ff_currentuserprofile = $Ini[0]["Default"]
            $ff_newprofile = "Profiles/JaxCoreSHUP.$option_name"
            for ($i = 1;$i -le 20; $i++) {
                If ($Ini["Profile$i"].Count -eq 0) {
                    debug "Creating new section `"Profile$i`""
                    $Ini["Profile$i"] = @{Name = "$option_name"; IsRelative = 1; Path = "$ff_newprofile"}
                    Break
                }
            }
            $Ini[0]["Default"] = $ff_newprofile
            Set-IniContent $Ini $ffconfig_path

            Get-Process 'Firefox' | Stop-Process

            New-Item -Path "$($ff_path)$ff_newprofile" -Type "Directory"
            debug "Copying current user profile as base, might take a while..."
            Copy-Path -Source "$($ff_path)$ff_currentuserprofile" -Destination "$($ff_path)$ff_newprofile\"
            New-Item -Path "$($ff_path)$ff_newprofile\chrome" -Type "Directory"
            debug "Moving userChrome.css"
            Move-Item -Path "$cache_location\AppSkins\Firefox\userChrome.css" -Destination "$($ff_path)$ff_newprofile\chrome" -Force
            debug "> Completed Firefox import"
        } else {
            debug "!! Firefox is not installed locally, returning to main process"
        }
    }

    # --------------------------------- Wallpaper -------------------------------- #

    debug "> Relocating & setting wallpaper"
    $wallpaper_name = Get-Item "$cache_location\Wallpaper\*" | Select-Object Name
    Move-Item -Path "$cache_location\Wallpaper\$($wallpaper_name.Name)" -Destination "C:\Users\$env:UserName\Pictures" -Force
    $RmAPI.Bang("[!SetWallpaper `"C:\Users\$env:UserName\Pictures\$($wallpaper_name.Name)`"]")

    # ------------------------------------ .. ------------------------------------ #
    Remove-Item -Path "$cache_location\*" -Recurse
    debug "> Completed import"
    $RmAPI.Bang("[!LoadLayout `"$option_name`"]")
}