$SkinsPath = $RmAPI.VariableStr('SKINSPATH')

function Update {
    Check-Data
}

function Create-IdleStyle {
    New-Item -Path "$SkinsPath..\CoreData" -Name "IdleStyle" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\IdleStyle" -Name "Include.inc" -ItemType "file"
    $RmAPI.Log("Created: IdleStyle")
    
}

function Create-Keylaunch {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Keylaunch" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Keylaunch.ahk" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "Include.inc" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch" -Name "IconCache" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Keylaunch\IconCache" -Name "folder.png" -ItemType "file"
    $RmAPI.Log("Created: Keylaunch")
}
function Create-Updater {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Updater" -ItemType "directory"
    Copy-Item -Path "$SkinsPath\#JaxCore\@Resources\Actions\*" -Destination "$SkinsPath..\CoreData\Updater" -PassThru
    $RmAPI.Log("Created: Updater")
}

# function Create-ValliStart {
#     New-Item -Path "$SkinsPath..\CoreData" -Name "ValliStart" -ItemType "directory"
#     New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "SingleRow.inc" -ItemType "file"
#     Set-Content "$SkinsPath..\CoreData\ValliStart\SingleRow.inc" @" 
# [SingleBox1]
# Meter=Shape
# MeterStyle=BoxStyle
# [SingleBox1Icon]
# Meter=Image
# MeterStyle=IconStyle
# [SingleBox2]
# Meter=Shape
# MeterStyle=BoxStyle
# [SingleBox2Icon]
# Meter=Image
# MeterStyle=IconStyle
# [SingleBox3]
# Meter=Shape
# MeterStyle=BoxStyle
# [SingleBox3Icon]
# Meter=Image
# MeterStyle=IconStyle
# [SingleBox4]
# Meter=Shape
# MeterStyle=BoxStyle
# [SingleBox4Icon]
# Meter=Image
# MeterStyle=IconStyle
# [SingleBox5]
# Meter=Shape
# MeterStyle=BoxStyle
# [SingleBox5Icon]
# Meter=Image
# MeterStyle=IconStyle
# "@
#     New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "DoubleRow.inc" -ItemType "file"
#     Set-Content "$SkinsPath..\CoreData\ValliStart\DoubleRow.inc" @" 
# [DoubleBox1]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox1Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox2]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox2Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox3]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox3Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox4]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox4Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox5]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox5Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox6]
# Meter=Shape
# MeterStyle=BoxStyle | BoxNewRowStyle
# [DoubleBox6Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox7]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox7Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox8]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox8Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox9]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox9Icon]
# Meter=Image
# MeterStyle=IconStyle
# [DoubleBox10]
# Meter=Shape
# MeterStyle=BoxStyle
# [DoubleBox10Icon]
# Meter=Image
# MeterStyle=IconStyle
# "@
#     New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "Win11Row.inc" -ItemType "file"
#     Set-Content "$SkinsPath..\CoreData\ValliStart\Win11Row.inc" @" 
# [Win11Box1]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box1Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box1Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box2]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box2Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box2Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box3]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box3Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box3Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box4]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box4Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box4Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box5]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box5Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box5Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box6]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box6Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box6Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box7]
# Meter=Shape
# MeterStyle=Win11BoxStyle | Win11BoxNewRowStyle
# [Win11Box7Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box7Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box8]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box8Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box8Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box9]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box9Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box9Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box10]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box10Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box10Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box11]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box11Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box11Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# [Win11Box12]
# Meter=Shape
# MeterStyle=Win11BoxStyle
# [Win11Box12Icon]
# Meter=Image
# MeterStyle=Win11IconStyle
# [Win11Box12Text]
# Meter=String
# MeterStyle=RegularText | Win11TextStyle
# "@
#     New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "IconCache" -ItemType "directory"
#     New-Item -Path "$SkinsPath..\CoreData\ValliStart\IconCache" -Name "folder.png" -ItemType "file"

#     $RmAPI.Log("Created: ValliStart")
# }

function Create-ValliStart {
    New-Item -Path "$SkinsPath..\CoreData" -Name "ValliStart" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "Include.inc" -ItemType "file"
    Set-Content "$SkinsPath..\CoreData\ValliStart\Include.inc" @" 
[Box1]
Meter=Shape
X=(#scale#*25)
Y=(#scale#*100)
MeterStyle=BoxStyle
[Box1Icon]
Meter=Image
MeterStyle=IconStyle
[Box2]
Meter=Shape
MeterStyle=BoxStyle
[Box2Icon]
Meter=Image
MeterStyle=IconStyle
[Box3]
Meter=Shape
MeterStyle=BoxStyle
[Box3Icon]
Meter=Image
MeterStyle=IconStyle
[Box4]
Meter=Shape
MeterStyle=BoxStyle
[Box4Icon]
Meter=Image
MeterStyle=IconStyle
[Box5]
Meter=Shape
MeterStyle=BoxStyle
[Box5Icon]
Meter=Image
MeterStyle=IconStyle
"@
    New-Item -Path "$SkinsPath..\CoreData\ValliStart" -Name "IconCache" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\ValliStart\IconCache" -Name "folder.png" -ItemType "file"

    $RmAPI.Log("Created: ValliStart")
}

function Create-Combilaunch {
    New-Item -Path "$SkinsPath..\CoreData" -Name "Combilaunch" -ItemType "directory"
    New-Item -Path "$SkinsPath..\CoreData\Combilaunch" -Name "Include.inc" -ItemType "file"
    New-Item -Path "$SkinsPath..\CoreData\Combilaunch" -Name "Actions.inc" -ItemType "file"
    $RmAPI.Log("Created: Combilaunch")
}

function Create-VarInc {
    $source      = $RmAPI.VariableStr('SKINSPATH')
    $destination = Split-Path -Path $source -Parent
    New-Item -Path "$SkinsPath..\CoreData" -Name "Vars.inc" -ItemType "file" -Value "[Variables]`nRAINMETERPATH=$destination"
}

function Check-Data {
    If (Test-Path -Path "$SkinsPath..\CoreData") {
            $RmAPI.Log("Found coredata in programs")
        } else {
            $RmAPI.Log("Failed to find coredata in programs, generating")
            New-Item -Path "$SkinsPath..\" -Name "CoreData" -ItemType "directory"
            $RmAPI.Bang("!Refresh")
        }
    If (Test-Path -Path "$SkinsPath..\CoreData\Keylaunch\IconCache") {
    } else {
        Create-Keylaunch
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\IdleStyle") {
    } else {
        Create-IdleStyle
    }
    # If (Test-Path -Path "$SkinsPath..\CoreData\ValliStart\SingleRow.inc") {
    If (Test-Path -Path "$SkinsPath..\CoreData\ValliStart\Include.inc") {
    } else {
        Create-ValliStart
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\Combilaunch") {
    } else {
        Create-Combilaunch
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\Updater") {
    } else {
        Create-Updater
    }
    If (Test-Path -Path "$SkinsPath..\CoreData\Vars.inc") {
    } else {
        Create-VarInc
    }
}