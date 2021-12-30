param (
    [Parameter(Mandatory=$false)]
    [String]
    $TargetLanguage = "Spanish", # See list of possible languages in $LanguageHashTable below.

    [Parameter(Mandatory=$false)] 
    [String]
    $Text = " " # This can either be the text to translate, or the path to a file containing the text to translate
)
# Create a Hashtable containing the full names of languages as keys and the code for that language as values
$LanguageHashTable = @{ 
Afrikaans='af' 
Albanian='sq' 
Arabic='ar' 
Azerbaijani='az' 
Basque='eu' 
Bengali='bn' 
Belarusian='be' 
Bulgarian='bg' 
Catalan='ca' 
'Chinese Simplified'='zh-CN' 
'Chinese Traditional'='zh-TW' 
Croatian='hr' 
Czech='cs' 
Danish='da' 
Dutch='nl' 
English='en' 
Esperanto='eo' 
Estonian='et' 
Filipino='tl' 
Finnish='fi' 
French='fr' 
Galician='gl' 
Georgian='ka' 
German='de' 
Greek='el' 
Gujarati='gu' 
Haitian ='ht' 
Creole='ht' 
Hebrew='iw' 
Hindi='hi' 
Hungarian='hu' 
Icelandic='is' 
Indonesian='id' 
Irish='ga' 
Italian='it' 
Japanese='ja' 
Kannada='kn' 
Korean='ko' 
Latin='la' 
Latvian='lv' 
Lithuanian='lt' 
Macedonian='mk' 
Malay='ms' 
Maltese='mt' 
Norwegian='no' 
Persian='fa' 
Polish='pl' 
Portuguese='pt' 
Romanian='ro' 
Russian='ru' 
Serbian='sr' 
Slovak='sk' 
Slovenian='sl' 
Spanish='es' 
Swahili='sw' 
Swedish='sv' 
Tamil='ta' 
Telugu='te' 
Thai='th' 
Turkish='tr' 
Ukrainian='uk' 
Urdu='ur' 
Vietnamese='vi' 
Welsh='cy' 
Yiddish='yi' 
}

# Determine the target language
if ($LanguageHashTable.ContainsKey($TargetLanguage)) {
    $TargetLanguageCode = $LanguageHashTable[$TargetLanguage]
}
elseif ($LanguageHashTable.ContainsValue($TargetLanguage)) {
    $TargetLanguageCode = $TargetLanguage
}
else {
    throw "Unknown target language. Use one of the languages from `$LanguageHashTable."
}

if (Test-Path $Text -PathType Leaf) {
    $Text = Get-Content $Text -Raw
}

$Uri = "https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=$($TargetLanguageCode)&dt=t&q=$([System.Uri]::EscapeDataString($Text))"
# Get the response from the web request, then throw a bunch of regex at it to clean it up.
$response = (Invoke-WebRequest -Uri $Uri -Method Get).Content | ConvertFrom-Json

if ($null -eq $response[0]) {
    return
}

$translation = @()

$response[0] | ForEach-Object {
    $translation += $_[0]
}

$translation -join ""