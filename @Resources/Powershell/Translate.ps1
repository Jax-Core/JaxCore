$escapePatterns = @(
    '\".+?\"',
    '\[.+?\]',
    '#.+?#',
    'JaxOriginals',
    'JaxCore',
    'Core',
    'Discord',
    'DeviantArt',
    'MusicBee',
    'Spotify',
    'AIMP',
    'WMP',
    'iTunes',
    'Foobar',
    'WinAMP',
    'Spicetify',
    'WebNowPlaying'
)
$escapeFiles = @(
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Popup\Variants\News.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Popup\Variants\CoreNews.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Tour\Pages\Page1.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Tour\Pages\Page2.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Tour\Pages\Page3.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Tour\Pages\Page4.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Tour\Pages\Page5.inc",
    "$($RmAPI.VariableStr('SKINSPATH'))#JaxCore\Accessories\Popup\Variants\News.inc"
)

class TranslateString {
    [string]$string
    [string]$translatedString
    [array]$escapedStrings
    [void]EscapeString($escapeKeys) {
        $i = 0
        $escapeKeys | ForEach-Object {
            while ($this.string -match $_) {
                $this.escapedStrings += $Matches[0]
                $this.string = $this.string -replace [regex]::Escape($Matches[0]), "{$i}"
                $i++
            }
        }
    }
    [void]UnescapeString() {
        for ($i = 0; $i -lt $this.escapedStrings.Count; $i++) {
            $this.string = $this.string -replace "\{$i\}", $this.escapedStrings[$i]
            $this.translatedString = $this.translatedString -replace "\{$i\}", $this.escapedStrings[$i]
        }
        $this.string = $this.string -replace '\{quot\}', '"'
        $this.translatedString = $this.translatedString -replace '\{quot\}', '"'
    }
    [string]$file
    [string]$section
    [string]$key

    TranslateString(
        [string]$str,
        [string]$key,
        [string]$section,
        [string]$file,
        [array]$escapeKeys
    ) {
        $this.string = $str
        $this.key = $key
        $this.section = $section
        $this.file = $file
        $this.EscapeString($escapeKeys)
    }
}

$LanguageHashTable = @{ 
    Afrikaans             = 'af' 
    Albanian              = 'sq' 
    Arabic                = 'ar' 
    Azerbaijani           = 'az' 
    Basque                = 'eu' 
    Bengali               = 'bn' 
    Belarusian            = 'be' 
    Bulgarian             = 'bg' 
    Catalan               = 'ca' 
    'Chinese Simplified'  = 'zh-CN' 
    'Chinese Traditional' = 'zh-TW' 
    Croatian              = 'hr' 
    Czech                 = 'cs' 
    Danish                = 'da' 
    Dutch                 = 'nl' 
    English               = 'en' 
    Esperanto             = 'eo' 
    Estonian              = 'et' 
    Filipino              = 'tl' 
    Finnish               = 'fi' 
    French                = 'fr' 
    Galician              = 'gl' 
    Georgian              = 'ka' 
    German                = 'de' 
    Greek                 = 'el' 
    Gujarati              = 'gu' 
    Haitian               = 'ht' 
    Creole                = 'ht' 
    Hebrew                = 'iw' 
    Hindi                 = 'hi' 
    Hungarian             = 'hu' 
    Icelandic             = 'is' 
    Indonesian            = 'id' 
    Irish                 = 'ga' 
    Italian               = 'it' 
    Japanese              = 'ja' 
    Kannada               = 'kn' 
    Korean                = 'ko' 
    Latin                 = 'la' 
    Latvian               = 'lv' 
    Lithuanian            = 'lt' 
    Macedonian            = 'mk' 
    Malay                 = 'ms' 
    Maltese               = 'mt' 
    Norwegian             = 'no' 
    Persian               = 'fa' 
    Polish                = 'pl' 
    Portuguese            = 'pt' 
    Romanian              = 'ro' 
    Russian               = 'ru' 
    Serbian               = 'sr' 
    Slovak                = 'sk' 
    Slovenian             = 'sl' 
    Spanish               = 'es' 
    Swahili               = 'sw' 
    Swedish               = 'sv' 
    Tamil                 = 'ta' 
    Telugu                = 'te' 
    Thai                  = 'th' 
    Turkish               = 'tr' 
    Ukrainian             = 'uk' 
    Urdu                  = 'ur' 
    Vietnamese            = 'vi' 
    Welsh                 = 'cy' 
    Yiddish               = 'yi' 
}

# $skinsList = $RmAPI.VariableStr('SKINLIST') -split '\s*\|\s*'

function Start-Translation {
    param(
        [Parameter()]
        $skin,
        [Parameter()]
        $TargetLanguage
    )
    $targetLanguageCode = $LanguageHashTable[$TargetLanguage]
    $prevLanguageCode = $LanguageHashTable[$RmAPI.VariableStr('Set.Lang')]
    If ($RmAPI.VariableStr('Set.Lang') -NotMatch 'English') {
        SetLangFile -Skin $skin -LangFile "$($RmAPI.VariableStr('SKINSPATH'))$Skin\@Resources\$Skin-$prevLanguageCode.json" -Revert 1
    }
    elseif (Test-Path -Path "$($RmAPI.VariableStr('SKINSPATH'))$Skin\@Resources\LangExports\$Skin-$targetLanguageCode.json") {
        $RmAPI.Bang('[!SetVariable Log "Exported translation file found!'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
        $RmAPI.Bang('[!SetVariable Log "Applying json...'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
        SetLangFile -Skin $skin -LangFile "$($RmAPI.VariableStr('SKINSPATH'))$Skin\@Resources\LangExports\$skin-$targetLanguageCode.json"
    }
    else {
        $RmAPI.Bang('[!SetVariable Log "Exporting translation...'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
        Export-LangFile -skin $skin -TargetLanguage $targetLanguageCode -directChange 1
    }
}

function Export-LangFile {
    param(
        [Parameter()]
        $skin,
        [Parameter()]
        $TargetLanguage,
        [Parameter()]
        $directChange = 0
    )

    $targetLanguageCode

    if ($LanguageHashTable.ContainsKey($TargetLanguage)) {
        $targetLanguageCode = $LanguageHashTable[$TargetLanguage]
    }
    elseif ($LanguageHashTable.ContainsValue($TargetLanguage)) {
        $targetLanguageCode = $TargetLanguage
    }
    else {
        $RmAPI.Log("Unknown target language. Use one of the languages from `$LanguageHashTable.")
        return
    }

    if (![System.IO.Directory]::Exists("$($RmAPI.VariableStr('SKINSPATH'))$skin")) {
        $RmAPI.Log("Skin folder $($RmAPI.VariableStr('SKINSPATH'))$skin not found!")
        return
    }

    $skindir = "$($RmAPI.VariableStr('SKINSPATH'))$skin"

    $iniTable = @{}

    $translateArray = @()
    $translateStringArr = @()

    foreach ($file in (Get-ChildItem $skindir -Include '*.ini', '*.inc' -Recurse | ?{$escapeFiles -notcontains $_.FullName} ).FullName) {
        $ini = Get-IniContent $file
        
        $hasTranslation = $false

        foreach ($section in $ini.GetEnumerator()) {
            if ($section.Value.Keys -contains 'Text') {
                $hasTranslation = $true
                $translateArray += [TranslateString]::new(
                    $section.Value.Text,
                    'Text',
                    $section.Key,
                    ($file -replace [regex]::Escape($RmAPI.VariableStr('SKINSPATH')), ''),
                    $escapePatterns
                )
                $translateStringArr += $translateArray[$translateArray.Count - 1].string
            }
        }

        if ($hasTranslation) {
            # Write-Host "Found translatables in $file"
            $name = Split-Path $file -leaf
            $RmAPI.Bang('[!SetVariable Log "Found translatables in '+$name+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
            $iniTable[($file -replace [regex]::Escape($RmAPI.VariableStr('SKINSPATH')), '')] =  @()
        }
    }

    if ($translateStringArr.Count -eq 0) {
        $RmAPI.Log('Nothing to translate. Aborting...')
        return
    }

    # Write-Host "Finished collecting strings..."
    $RmAPI.Bang('[!SetVariable Log "Finished collecting strings...'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')

    $translateString = $translateStringArr -join [System.Environment]::NewLine

    # Write-Host "Translating strings..."
    $RmAPI.Bang('[!SetVariable Log "Translating strings...'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
    $translatedString = & "$($RmAPI.VariableStr('@'))Powershell\GoogleTranslate.ps1" -TargetLanguage $targetLanguage -Text "$translateString"

    # Write-Host "Restoring escaped parts..."
    $RmAPI.Bang('[!SetVariable Log "Restoring escaped text...'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
    $i = 0
    foreach ($string in ($translatedString -split [regex]::Escape([System.Environment]::NewLine))) {
        $translateArray[$i].translatedString = $string
        $translateArray[$i].UnescapeString()
        $iniTable[$translateArray[$i].file] += @{
            original = $translateArray[$i].string
            translated = $translateArray[$i].translatedString
            write_info = @{
                key = $translateArray[$i].key
                section = $translateArray[$i].section
            }
        }
        $i++
    }

    # Write-Host "Exporting JSON..."
    $RmAPI.Bang('[!SetVariable Log "Exporting to .JSON file...'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')
    ($iniTable | ConvertTo-Json -Depth 5) | Out-File (New-Item -Path "$($RmAPI.VariableStr('SKINSPATH'))$Skin\@Resources\LangExports\$skin-$targetLanguageCode.json" -Force)

    # Write-Host Done
    $RmAPI.Bang('[!SetVariable Log "Successfully translated to '+$RmAPI.VariableStr('Sec.arg1')+'!'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')

    Start-Sleep -s 2

    if ($directChange) {
        Write-Host Directly applying...
        SetLangFile -Skin $skin -LangFile "$($RmAPI.VariableStr('SKINSPATH'))$Skin\@Resources\LangExports\$skin-$targetLanguageCode.json"
    }
}
function SetLangFile {
    param(
        [Parameter()]
        $Skin,
        [Parameter()]
        $LangFile,
        [Parameter()]
        $Revert = 0
    )

    if (![System.IO.File]::Exists($langFile)) {
        $RmAPI.Log("Language file $langFile invalid!")
        return
    }

    $langJson = Get-Content $LangFile -Raw | ConvertFrom-Json | Get-ObjectMember

    $langJson | ForEach-Object {
        $file = $_

        if (![System.IO.File]::Exists($RmAPI.VariableStr('SKINSPATH') + $file.Key)) {
            $RmAPI.Log("$($file.Key) not found!")
            continue
        }

        $ini = Get-IniContent -filePath ($RmAPI.VariableStr('SKINSPATH') + $file.Key)

        foreach ($string in $file.Value) {
            if (-not $ini[$string.write_info.section]) {
                $RmAPI.Log("No section [$($string.write_info.section)] in $($file.Key). Language file invalid.")
                continue
            }
            if (-not $ini[$string.write_info.section][$string.write_info.key]) {
                $RmAPI.Log("No key $($string.write_info.key) in section [$($string.write_info.section)] in $($file.Key). Language file invalid.")
                continue
            }
            if (($revert -ne 1) -and ($ini[$string.write_info.section][$string.write_info.key] -ne $string.original)) {
                $RmAPI.Log($file.Key)
                $RmAPI.Log("[$($string.write_info.section)]::$($string.write_info.key)")
                $RmAPI.Log("String has changed. Language file invalid.")
                continue
            }
            if ($revert) {
                $ini[$string.write_info.section][$string.write_info.key] = $string.original
            }
            else {
                $ini[$string.write_info.section][$string.write_info.key] = $string.translated
            }
        }

        # Write-Host "-> $($file.Key)"
        $RmAPI.Bang('[!SetVariable Log "-> '+$($file.Key)+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')

        Set-IniContent -filePath ($RmAPI.VariableStr('SKINSPATH') + $file.Key) -ini $ini
    }

    # Write-Host Done
    $LangFilename = Split-Path $LangFile -leaf
    $RmAPI.Bang('[!SetVariable Log "Finished applying '+$LangFilename+'!'+$RmAPI.VariableStr('CRLF')+$RmAPI.VariableStr('Log')+'"][!UpdateMeter Log][!Redraw]')

    $RmAPI.Bang("[!Refresh `"$Skin\Main`"]")
}
# helper to turn PSCustomObject into a list of key/value pairs
function Get-ObjectMember {
    [CmdletBinding()]
    Param(
        [Parameter(Mandatory = $True, ValueFromPipeline = $True)]
        [PSCustomObject]$obj
    )
    $obj | Get-Member -MemberType NoteProperty | ForEach-Object {
        $key = $_.Name
        [PSCustomObject]@{Key = $key; Value = $obj."$key" }
    }
}
function Get-IniContent ($filePath) {
    $ini = [ordered]@{}

    

    $section = ';InitNotSection'

    $ini.Add($section, [ordered]@{})

    foreach ($line in [System.IO.File]::ReadLines($filePath)) {
        $notSectionCount = 0
        if ($line -match "^\s*;.*$") {
            while ($ini[$section].Keys -contains ";NotSection" + $notSectionCount++) {}
            $ini[$section].Add(";NotSection" + --$notSectionCount, $line)
        }
        elseif ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            if ($ini.Keys -notcontains $section) {
                $ini.Add($section, [ordered]@{})
            }
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            if ($ini[$section].Keys -notcontains $key) {
                $ini[$section].Add($key, $value)
            }
            else {
                $ini[$section][$key] = $value
            }
        }
        else {
            while ($ini[$section].Keys -contains ";NotSection" + $notSectionCount++) {}
            $ini[$section].Add(";NotSection" + --$notSectionCount, $line)
        }
    }

    return $ini
}

function Set-IniContent($ini, $filePath) {
    $str = @()

    foreach ($section in $ini.GetEnumerator()) {
        if ($section.Key -match ";InitNotSection") {
            continue
        }
        $str += "[" + $section.Key + "]"
        foreach ($keyvaluepair in $section.Value.GetEnumerator()) {
            if ($keyvaluepair.Key -match "^;NotSection\d+$") {
                $str += $keyvaluepair.Value
            }
            else {
                $str += $keyvaluepair.Key + "=" + $keyvaluepair.Value
            }
        }
    }

    $finalStr = $str -join [System.Environment]::NewLine

    $finalStr | Out-File -filePath $filePath -Force -Encoding unicode
}