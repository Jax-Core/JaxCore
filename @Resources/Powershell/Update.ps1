$Folder = '../../../@CoreUpdateTemp'
if (Test-Path -Path $Folder) {
    "Path exists!"
} else {
    New-Item -Path "../../.." -Name "@CoreUpdateTemp" -ItemType "directory"
}
Copy-Item -Path "../Actions/AHK.exe" -Destination "../../../@CoreUpdateTemp"
Copy-Item -Path "../Actions/InstallData.ini" -Destination "../../../@CoreUpdateTemp"
Copy-Item -Path "../Actions/Installer.ahk" -Destination "../../../@CoreUpdateTemp"