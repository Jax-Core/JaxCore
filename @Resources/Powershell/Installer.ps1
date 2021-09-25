function Install { 
    $url=$RmAPI.VariableStr('DownloadLink')
    $name=$RmAPI.VariableStr('DownloadName')
    $outPath="C:/Windows/Temp/$name.rmskin"

    $wc=New-Object System.Net.WebClient
    $wc.DownloadFile($url, $outPath)
    Start-Process -Filepath $outPath

    If($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell=New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1
        $wshell.SendKeys('~')
    }

    # script inspired by ModkaVart.
}