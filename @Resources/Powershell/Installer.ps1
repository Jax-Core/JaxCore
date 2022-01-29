function Install { 
    param (
    [string]$saveDirectory = 'CoreShell\Info.inc'
    )
    $url=$RmAPI.VariableStr('DownloadLink')
    $name=$RmAPI.VariableStr('DownloadName')
    $configroot=$RmAPI.VariableStr('DownloadConfig')
    $SaveLocation="$($RmAPI.VariableStr("ROOTCONFIGPATH"))$saveDirectory"

    $config="$configroot\Main"
    $outPath="C:/Windows/Temp/$name.rmskin"

    if ($config -NotMatch "#JaxCore") {
        if ($RmAPI.Measure('ActiveChecker') -eq -1){
            $RmAPI.Bang("[!WriteKeyValue DefaultStartActions Custom1 `"`"`"[!Delay 1000][!DeactivateConfig `"$configroot\@Start`"][!WriteKeyValue DefaultStartActions Custom1 `"`" $SaveLocation]`"`"`" $SaveLocation]")
        } else {
            $RmAPI.Bang("[!WriteKeyValue DefaultStartActions Custom1 `"`"`"[!Delay 1000][!DeactivateConfig `"$configroot\@Start`"][!ActivateConfig `"$configroot\Main`"][!WriteKeyValue DefaultStartActions Custom1 `"`" $SaveLocation]`"`"`" $SaveLocation]")
            $RmAPI.Bang("[!DeactivateConfig $config]")
        }
    }
    
    $RmAPI.Bang("[!CommandMeasure Func `"interactionBox('UpdatePrompt', '$name')`"]")

    Invoke-WebRequest -Uri $url -OutFile $outPath
    if (-not [System.IO.File]::Exists($outPath)) {
        throw "File not downloaded"
    }
    Start-Process -Filepath $outPath

    If($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell=New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1
        $wshell.SendKeys('~')
    }
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
                } else {
                    $RmAPI.Log("CoreData for $SkinName is already generated")
                }
            } else {
                $RmAPI.Log("$SkinName doesn't require creation of CoreData")
            }
        } else {
            $RmAPI.Log("Failed to find coredata in programs, generating")
            New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
            $RmAPI.Bang('[!Refresh]')
        }
}

# function CheckIfClone {
#     $SkinsPath = $RmAPI.VariableStr('SKINSPATH')
#     $SkinName = $RmAPI.VariableStr('Skin.Name')
#     $BetaSkinList = $RmAPI.VariableStr('BetaSkinList')
#     If (Test-Path -Path "$SkinsPath$SkinName\@Resources\IsClone.txt") {
#         $RmAPI.Log('IsClone')
#         $RmAPI.Bang('[!HideMeterGroup Buttons][!HideMeterGroup HideIsClone][!SetOption SubHeader MeterStyle "Set.String:S | Subheader:5"][!SetOption Description MeterStyle "Set.String:S | Description:IsClone"][!UpdateMeter *][!Redraw]')
#     } elseif ("$SkinName" -Match "$BetaSkinList") {
#         $RmAPI.Bang('[!ShowMeterGroup DiscordButton][!SetOption SubHeader MeterStyle "Set.String:S | Subheader:4"][!UpdateMeter *][!Redraw]')
#     } else {
#         $RmAPI.Bang('[!EnableMeasureGroup CheckForbeta][!UpdateMeasureGroup CheckForBeta]')
#     }
# }

function DuplicateSkin {
    param (
    [string]$DuplicateName = 'CloneSkinName'
    )
    $SkinsPath = $RmAPI.VariableStr('SKINSPATH')
    $Resources = $RmAPI.VariableStr('@')
    $SkinName = $RmAPI.VariableStr('Sec.arg1')

    If (Test-Path -Path "$SkinsPath$DuplicateName") {
        $RmAPI.Log("Folder already exits")
    } else{
        $RmAPI.Log("Duplicating to $DuplicateName")
        Copy-Item -Path "$SkinsPath$SkinName\" -Destination "$SkinsPath$DuplicateName\" -Recurse
        New-Item -Path "$SkinsPath$DuplicateName\@Resources\" -Name "IsClone.txt" -ItemType "file"
    }
    $RmAPI.Bang("[!WriteKeyValue Rainmeter OnRefreshAction `"`"`"[!WriteKeyValue Rainmeter OnRefreshAction `"#*Sec.DefaultStartActions*#`"][!DeactivateConfig]`"`"`"][!WriteKeyValue Variables Skin.Name $DuplicateName `"$($Resources)SecVar.inc`"][!WriteKeyValue Variables Skin.Set_Page Info `"$($Resources)SecVar.inc`"][`"$($Resources)Addons\RestartRainmeter.exe`"]")

}

function Uninstall {
    $SkinsPath = $RmAPI.VariableStr('SKINSPATH')
    $Resources = $RmAPI.VariableStr('@')
    $SkinName = $RmAPI.VariableStr('Sec.arg1')
    if ($RmAPI.Measure('ActiveChecker') -eq 1) {
        $RmAPI.Bang("[!DeactivateConfig `"$SkinName\Main`"]")
    }
    Start-Sleep -s 1
    Remove-Item -LiteralPath "$SkinsPath$SkinName" -Force -Recurse
    Start-Sleep -s 1
    $RmAPI.Bang("[!WriteKeyvalue Variables Sec.variant `"Uninstalled`"][!WriteKeyValue Variables Skin.Name $SkinName `"$($Resources)SecVar.inc`"][!WriteKeyValue Variables Skin.Set_Page Info `"$($Resources)SecVar.inc`"][`"$($Resources)Addons\RestartRainmeter.exe`"]")
}