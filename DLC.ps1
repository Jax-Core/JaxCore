function debug {
    param(
        [Parameter()]
        [string]
        $message
    )

    $RmAPI.Bang("[!Log `"`"`"" + $message + "`"`"`" Debug]")
}

function reinstall_all {
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $folderDLCs = "$($skinsPath)..\CoreData\@DLCs\"
    $fileInstalledDLCs = "$($folderDLCs)InstalledDLCs.inc"
    "" | Out-File -FilePath $fileInstalledDLCs -Encoding unicode -Force
    $RmAPI.Bang("[!Delay 200][!WriteKeyvalue Variables Page.Subpage 2 `"$($skinsPath)#JaxCore\CoreShell\Home\Page2.inc`"][!Refresh]")
}

function check-update {
    # $editingModule = $RmAPI.VariableStr('Page.SubpageModule')
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $skinName = $RmAPI.VariableStr('Skin.Name')
    $skinDir = "$($skinsPath)#JaxCore"

    $folderDLCs = "$($skinsPath)..\CoreData\@DLCs\"
    $fileInstalledDLCs = "$($folderDLCs)InstalledDLCs.inc"
    $folderDLCPackages = "$($folderDLCs)Packages\"
    $folderIncludes = "$($folderDLCs)Includes\"
    $fileIncluder = "$($folderIncludes)Includer.inc"
    # ----------------------------- Module includers ----------------------------- #
    # $skinDLCs = @('YourFlyouts','ValliStart')
    $fileIncluder0_YourMixer = "$($skinsPath)YourMixer\Core\Layout\Includer.inc"
    $fileIncluder0_YourFlyouts = "$($skinsPath)YourFlyouts\Core\Layout\Includer.inc"
    $fileIncluder0_ValliStart = "$($skinsPath)ValliStart\Core\Layout\Includer.inc"
    $fileIncluder1_ValliStart = "$($skinsPath)ValliStart\Core\Window\ValliModule\4.inc"

    # -------------------------- Generate DLC structure -------------------------- #
    If (!(Test-Path "$folderDLCs")) {
        New-Item -path $folderDLCs -ItemType "directory"
        New-Item -path $folderIncludes -ItemType "directory"
        New-Item -path $fileIncluder -ItemType "file"
        New-Item -path $fileInstalledDLCs -ItemType "file"
        New-Item -path $folderDLCPackages -ItemType "directory"
    }


    $arr = @(Get-ChildItem $folderDLCPackages -filter *.zip | Foreach-Object -Process { [System.IO.Path]::GetFileNameWithoutExtension($_) })
    if ($arr -match "-") {
        debug "Found"
        $RmAPI.Bang("[!SetOption Error.String Text `"Non-DLCPackage files found. Please remove such files and try again.`"][!SetOption Error.Description.String Text `"Make sure to read the installation guide carefully.`"][!UpdateMeterGroup ErrorString][!ShowMeterGroup ErrorString][$folderDLCPackages]")
        Return
    }
    if ($arr.Length -eq 0) {
        # ------------------------ Write content for DLC list ------------------------ #
        $fileIncluderContent += @"

[InstalledList.Item1.Shape]
Meter=Shape
MeterStyle=List.Item.Shape:S
[InstalledList.Item1.StringIcon]
Meter=String
Text=[\xe854]
MeterStyle=Set.String:S | List.Item.StringIcon:S
[InstalledList.Item1.String]
Meter=String
Text=You don't have any DLCs installed!
MeterStyle=Set.String:S | List.Item.String:S

"@
        # ----------------------- Write content for YourFlyouts ---------------------- #
        $fileIncluder0_YourFlyouts_content += @"

[Item1.Shape]
Meter=Shape
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=You don't have any DLCs installed, discover them on my ko-fi store!
MeterStyle=Set.String:S | Item.String:S
[Item1.Arrow.String]
Meter=String
MeterStyle=Set.String:S | Item.Arrow.String:S
"@
        # ----------------------- Write content for YourMixer ---------------------- #
        $fileIncluder0_YourMixer_content += @"

[Item1.Shape]
Meter=Shape
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=You don't have any DLCs installed, discover them on my ko-fi store!
MeterStyle=Set.String:S | Item.String:S
[Item1.Arrow.String]
Meter=String
MeterStyle=Set.String:S | Item.Arrow.String:S
"@
        # ----------------------- Write content for ValliStart ----------------------- #
        $fileIncluder0_ValliStart_content += ""
        $fileIncluder1_ValliStart_content += @"
        
[Item2.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item2.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Sec.String:S | Item.StringIcon:S
[Item2.String]
Meter=String
Text=You seem to not have any DLCs installed, discover them on my ko-fi store!
MeterStyle=Sec.String:S | Item.String:S
[Item2.Button]
Meter=Shape
MeterStyle=Item.Button.Shape:S
[Item2.Button.StringIcon]
Meter=String
Text=[\xe89e]
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
MeterStyle=Sec.String:S | Item.Button.StringIcon:S
"@

        $fileIncluderContent | Out-File -FilePath $fileIncluder -Force -Encoding unicode 
        If (Test-Path -Path $fileIncluder0_YourMixer) {$fileIncluder0_YourMixer_content | Out-File -FilePath $fileIncluder0_YourMixer -Encoding unicode -Force}
        If (Test-Path -Path $fileIncluder0_YourFlyouts) {$fileIncluder0_YourFlyouts_content | Out-File -FilePath $fileIncluder0_YourFlyouts -Encoding unicode -Force}
        If (Test-Path -Path $fileIncluder0_ValliStart) {$fileIncluder0_ValliStart_content | Out-File -FilePath $fileIncluder0_ValliStart -Encoding unicode -Force}
        If (Test-Path -Path $fileIncluder1_ValliStart) {$fileIncluder1_ValliStart_content | Out-File -FilePath $fileIncluder1_ValliStart -Encoding unicode -Force}
        "" | Out-File -FilePath $fileInstalledDLCs -Encoding unicode -Force
    }


    # --------------------------- for every DLC package -------------------------- #
    for ($i = 1; $i -le $arr.Length; $i++) {
        # ------------ if it is not present in the installed DLCs inc file ----------- #
        if ([string]::IsNullOrEmpty($RmAPI.VariableStr($arr[$i - 1]))) {
            $fileInstalledDLCs_content = "[Variables]"

            for ($i = 1; $i -le $arr.Length; $i++) {
                # -------------------- $iName is the current package name -------------------- #
                $iName = $arr[$i - 1]
                # -------------------- Split iName to module and DLC name -------------------- #
                $iInfo = $iName -split '_'
                # $iInfo[0]: Module
                # $iInfo[1]: DLC
                
                $fileInstalledDLCs_content += @"

$iName=$(-join ((48..57) + (97..122) | Get-Random -Count 32 | % {[char]$_}))
"@
                Expand-Archive -Path "$folderDLCPackages$iName.zip" -DestinationPath "$($skinsPath)$($iInfo[0])\" -Force -Verbose

                $fileIncluderContent += @"

[InstalledList.$iName.Shape]
Meter=Shape
LeftMouseUpAction=[!CommandMeasure Func "corepage('$($iInfo[0])')"]
MeterStyle=List.Item.Shape:S
[InstalledList.$iName.StringIcon]
Meter=String
Text=[\xf091]
MeterStyle=Set.String:S | List.Item.StringIcon:S
[InstalledList.$iName.String]
Meter=String
Text=$($iInfo[1]) for $($iInfo[0])
MeterStyle=Set.String:S | List.Item.String:S

"@
# ---------------------------------------------------------------------------- #
#                    Generated content for separate modules                    #
# ---------------------------------------------------------------------------- #
# --------------------------------- YourMixer -------------------------------- #
                if ($iInfo[0] -Contains "YourMixer") {
                    debug "$iInfo"
                    if ([string]::IsNullOrEmpty($fileIncluder0_YourMixer_content)) {
                        $fileIncluder0_YourMixer_content += @"

[Item1.Shape]
Meter=Shape
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=Discover more DLCs on my ko-fi store!
MeterStyle=Set.String:S | Item.String:S
[Item1.Arrow.String]
Meter=String
MeterStyle=Set.String:S | Item.Arrow.String:S
[Div:Header]
Meter=Shape
X=(20*[Set.S])
MeterStyle=Set.Div:S
"@
                    }
                    $fileIncluder0_YourMixer_content += @"

[$($iInfo[1])]
Meter=Image
MeterStyle=DLC:S
[$($iInfo[1])String]
Meter=String
Text=$($iInfo[1])
MeterStyle=Set.String:S | DLC.String:S

"@
                    if ($i -eq $arr.Length) {
                        $fileIncluder0_YourMixer_content += @"

[Div:Anchor]
Meter=Shape
X=(20*[Set.S])
Y=(20*[Set.S])r
MeterStyle=Set.Div:S
"@

                    }
                }
# ------------------------------------- - ------------------------------------ #
# -------------------------------- YourFlyouts ------------------------------- #
                if ($iInfo[0] -Contains "YourFlyouts") {
                    if ([string]::IsNullOrEmpty($fileIncluder0_YourFlyouts_content)) {
                        $fileIncluder0_YourFlyouts_content += @"

[Item1.Shape]
Meter=Shape
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=Discover more DLCs on my ko-fi store!
MeterStyle=Set.String:S | Item.String:S
[Item1.Arrow.String]
Meter=String
MeterStyle=Set.String:S | Item.Arrow.String:S
[Div:Header]
Meter=Shape
X=(20*[Set.S])
MeterStyle=Set.Div:S
"@
                    }
                    $fileIncluder0_YourFlyouts_content += @"

[$($iInfo[1])]
Meter=Image
MeterStyle=DLC:S
[$($iInfo[1])String]
Meter=String
Text=$($iInfo[1])
MeterStyle=Set.String:S | DLC.String:S

"@
                    if ($i -eq $arr.Length) {
                        $fileIncluder0_YourFlyouts_content += @"

[Div:Anchor]
Meter=Shape
X=(20*[Set.S])
Y=(20*[Set.S])r
MeterStyle=Set.Div:S
"@

                    }
                }
# ------------------------------------- - ------------------------------------ #
# -------------------------------- ValliStart -------------------------------- #
                if ($iInfo[0] -Contains "ValliStart") {
                    $fileIncluder0_ValliStart_content += @"

[$($iInfo[1]).Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[$($iInfo[1]).Image]
Meter=Image
MeterStyle=Module.Image:S
[$($iInfo[1]).String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[$($iInfo[1]).Description.String]
Meter=String
Text=Default layout for the $($iInfo[1]) DLC
MEterStyle=Set.String:S | Module.Description.STring:S

"@
                    $fileIncluder1_ValliStart_content += @"

[$($iInfo[1]).Div]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#)R
Shape=Line 0,0,(#W#-#Sec.P#*2),0 | StrokeWidth 4 | Fill Color #Set.Pri_Color#,0 | Stroke LinearGradient This
This=0 | #Set.Text_Color#,25 ; 0.0 | #Set.Text_Color#,0 ; 0.5 | #Set.Text_Color#,25 ; 1.0
DynamicVariables=1
Container=ContentContainer

[$($iInfo[1]).String]
Meter=String
Text=$($iInfo[1])
FontColor=#Set.Subtext_Color#
X=(#W#/2)
Y=r
DynamicVariables=1
InlineSetting=CharacterSpacing | 2 | 2
StringAlign=CenterCenter
MeterStyle=Sec.String:S


"@
                # ---------------- Generate a block for each ValliStart module --------------- #
                    $moduleNames = @(Get-ChildItem "$($skinsPath)ValliStart\Core\Module" | Where-Object { $_.Name -match "^$($iInfo[1])" } | Foreach-Object -Process {[System.IO.Path]::GetFileNameWithoutExtension($_)})
                    for ($j = 1; $j -le $moduleNames.Length; $j++) {
                        $mo = $j % 3
                        $fileIncluder1_ValliStart_content += @"
                
[$($moduleNames[$j-1]).Shape]
Meter=Shape
"@
                        if ($mo -eq 1) {
                            $fileIncluder1_ValliStart_content += @"

X=(#SEc.P#)
Y=(#Sec.P#*2)r
"@
                        }
                        $fileIncluder1_ValliStart_content += @"

MeterStyle=DLC.Shape:S
[$($moduleNames[$j-1]).Image]
Meter=Image
MeterStyle=DLC.Image:S
[$($moduleNames[$j-1]).String]
Meter=String
MEterStyle=Sec.String:S | DLC.STring:S
"@
                    }

                    $fileIncluder1_ValliStart_content += @"
                
[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R

"@
                }
# ------------------------------------- - ------------------------------------ #
                $fileIncluderContent | Out-File -FilePath $fileIncluder -Force -Encoding unicode
                If (Test-Path -Path $fileIncluder0_YourMixer) {$fileIncluder0_YourMixer_content | Out-File -FilePath $fileIncluder0_YourMixer -Encoding unicode -Force}
                If (Test-Path -Path $fileIncluder0_YourFlyouts) {$fileIncluder0_YourFlyouts_content | Out-File -FilePath $fileIncluder0_YourFlyouts -Encoding unicode -Force}
                If (Test-Path -Path $fileIncluder0_ValliStart) {$fileIncluder0_ValliStart_content | Out-File -FilePath $fileIncluder0_ValliStart -Encoding unicode -Force}
                If (Test-Path -Path $fileIncluder1_ValliStart) {$fileIncluder1_ValliStart_content | Out-File -FilePath $fileIncluder1_ValliStart -Encoding unicode -Force}
            }
            $fileInstalledDLCs_content | Out-File -FilePath $fileInstalledDLCs -Force -Encoding unicode 

            
            break
        }
    }
    if ($RmAPI.VariableStr('Page.Complete_Reinstallation') -contains '1') {
        $RmAPI.Bang("[!WriteKeyvalue Variables Page.Complete_Reinstallation 0 `"$skinDir\CoreShell\Home\Page2.inc`"]")
        If ($RmAPI.VariableStr('Page.Reinstallation_isSingle') -contains 'True') {
            $RmAPI.Bang("[!ActivateConfig `"$($RmAPI.VariableStr('SKin.name'))\Main`"][!ActivateConfig `"#JaxCore\Main`" `"Settings.ini`"]")
        } else {
            $RmAPI.Bang("[!Delay 200][!WriteKeyValue Variables Sec.Page 1 `"$skinspath\#JaxCore\Main\Home.ini`"][!Refresh]")
        }
    } else {$RmAPI.Bang("[!Delay 200][!WriteKeyvalue Variables Page.Subpage 1 `"$skinDir\CoreShell\Home\Page2.inc`"][!Refresh]")}
}

function moveDLC($path) {
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $folderDLCs = "$($skinsPath)..\CoreData\@DLCs\"
    $folderDLCPackages = "$($folderDLCs)Packages\"
    $skinDir = "$($skinsPath)#JaxCore"
    debug $path
    If ($path -notmatch '[a-zA-Z]_[a-zA-Z]') {
        $RmAPI.Bang("[!SetOption Error.String Text `"Not a Valid DLC package!#CRLF#Make sure to read the installation guide carefully or watch the walkthrough video above.`"][!ShowMeterGroup ErrorDialog][!UpdateMeterGroup ErrorDialog][!Redraw]")
        Return
    }
    Move-Item -Path $path -Destination $folderDLCPackages
    $RmAPI.Bang("[!Delay 500][!WriteKeyvalue Variables Page.Subpage 2 `"$skinDir\CoreShell\Home\Page2.inc`"][!Refresh]")
}