$ProgressPreference = 'SilentlyContinue'
If (Test-Path "$ENV:TEMP\shp-packager.ps1") {Remove-Item "$ENV:TEMP\shp-packager.ps1" -Force > $null}
iwr -useb "https://raw.githubusercontent.com/Jax-Core/JaxCore/main/S-Hub/shp-packager.ps1" -outfile "$ENV:TEMP\shp-packager.ps1"
& "$ENV:TEMP\shp-packager.ps1"