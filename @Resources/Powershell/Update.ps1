$scriptpath = $MyInvocation.MyCommand.Path
$dir = Split-Path $scriptpath
Remove-Item -Path "$dir/../../../@CoreUpdateTemp" -Recurse
New-Item -Path "$dir/../../.." -Name "@CoreUpdateTemp" -ItemType "directory"
Copy-Item -Path "$dir/../Actions/AHKv1.exe" -Destination "$dir/../../../@CoreUpdateTemp"
Copy-Item -Path "$dir/../Actions/InstallData.ini" -Destination "$dir/../../../@CoreUpdateTemp"
Copy-Item -Path "$dir/../Actions/Installer.ahk" -Destination "$dir/../../../@CoreUpdateTemp"