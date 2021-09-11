# FUNCTION ALL RIGHTS TO DEATHCRAFTER

function ReadIni($filePath)
{
    $ini = @{}
    $content=Get-Content -Path $filePath
    switch -regex ($content)
    {
        “^\[(.+)\]” # Section
        {
            $section = $matches[1]
            $ini[$section] = @{}
            $CommentCount = 0
        }
        “^(;.*)$” # Comment
        {
            $value = $matches[1]
            $CommentCount = $CommentCount + 1
            $name = “Comment” + $CommentCount
            $ini[$section][$name] = $value
        }
        “(.+?)\s*=(.*)” # Key
        {
            $name,$value = $matches[1..2]
            $ini[$section][$name] = $value
        }
    }
    return $ini
}
# # $ini['<sectionName>']['<keyName>']

# Function built to export strings to skin
function FetchVars()
{
    $Settings = $RmAPI.VariableStr('SETTINGSPATH')
    $ini=ReadIni($Settings + 'Rainmeter.ini')
    $Active=$ini['ModularClocks\Main']['Active']
    $X=$ini['ModularClocks\Main']['WindowX']
    $Y=$ini['ModularClocks\Main']['WindowY']
    $Thru=$ini['ModularClocks\Main']['ClickThrough']
    $Drag=$ini['ModularClocks\Main']['Draggable']
    $Snap=$ini['ModularClocks\Main']['SnapEdges']
    $Keep=$ini['ModularClocks\Main']['KeepOnScreen']
    $Zpos=$ini['ModularClocks\Main']['AlwaysOntop']
    $RmAPI.Bang('!CommandMeasure Script:M SaveStatus('+$Active+','+$X+','+$Y+','+$Thru+','+$Drag+','+$Snap+','+$Keep+','+$ZPos+')')
}

# $RmAPI.Bang('!CommandMEasure Script:M Test()')
# $FetchCount = $RmAPI.OptionInt('FetchStringCount')
# $i=1
# for (;$i -le $FetchCount;$i++)
# {
#     $CurrentString = $RmAPI.OptionStr('Fetch'+$i)
#     $OptionArray = $CUrrentString.Split('|')
#     # $RmAPI.Log($OptionArray[0])
#     $RmAPI.Bang('!SetOption '+$OptionArray[1]+' Text "'+$ini['Variables'][$OptionArray[0]]+'"')
#     $RmAPI.Bang('!UpdateMeter "'+$OptionArray[1]+'"')
# }
# $RmAPI.Bang('!Redraw')