Add-Type -AssemblyName System.Drawing
function Dimensions {
    $imageFile=$RmAPI.VariableStr("Cache.Wallpaper")
    $image = New-Object System.Drawing.Bitmap $imageFile
    $imageWidth = $image.Width
    $imageHeight = $image.Height
    $RmAPI.Bang("[!SetVariable IMGW `"$imageWidth`"]")
    $RmAPI.Bang("[!SetVariable IMGH `"$imageHeight`"]")
    $RmAPI.Bang("[!UpdateMeasure ExportWH]")
}