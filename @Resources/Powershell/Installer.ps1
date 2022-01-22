# function Install { 
#     $url=$RmAPI.VariableStr('DownloadLink')
#     $name=$RmAPI.VariableStr('DownloadName')
#     $outPath="C:/Windows/Temp/$name.rmskin"

#     $wc=New-Object System.Net.WebClient
#     $wc.DownloadFile($url, $outPath)
#     Start-Process -Filepath $outPath

#     If($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
#         $wshell=New-Object -ComObject wscript.shell
#         $wshell.AppActivate('Rainmeter Skin Installer')
#         Start-Sleep -s 1
#         $wshell.SendKeys('~')
#     }

#     # script inspired by ModkaVart.
# }

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

    # script inspired by ModkaVart.
    # v2 script by death
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
                    Robocopy "$SkinsPath$SkinName\@Resources\@Structure\" "$SkinsPath..\CoreData\$SkinName\" /E /XC /XN /XO
                    New-Item -Path "$SkinsPath..\CoreData\$SkinName\" -Name "$SkinVer.txt" -ItemType "file"
                } else {
                    $RmAPI.Log("CoreData for $SkinName is already generated")
                }
            } else {
                $RmAPI.Log("$SkinName doesn't require creation of CoreData")
            }
        } else {
            $RmAPI.Log("Failed to find coredata in programs, generating")
            New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
        }
}