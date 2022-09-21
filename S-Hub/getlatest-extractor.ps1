param(
    [Parameter(Mandatory=$true)][Alias("path")][ValidateNotNullOrEmpty()][string]$s_Path
)

If (Test-Path "$ENV:TEMP\shp-extractor.ps1") {Remove-Item "$ENV:TEMP\shp-extractor.ps1" -Force > $null}
iwr -useb "https://raw.githubusercontent.com/Jax-Core/JaxCore/main/S-Hub/shp-extractor.ps1" -outfile "$ENV:TEMP\shp-extractor.ps1"
& "$ENV:TEMP\shp-extractor.ps1" "$s_Path"