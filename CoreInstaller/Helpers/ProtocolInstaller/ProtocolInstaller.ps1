function Add-CoreProtocol{
    $root = $RmAPI.VariableStr('ROOTCONFIGPATH') + 'CoreInstaller'
    Start-Process powershell -ArgumentList "& `"$root\Helpers\CoreInstaller\CoreInstallerWebSupport.ps1`" `"$root\Helpers\CoreInstaller\CoreInstaller.exe`" `"$($RmAPI.VariableStr('@'))WebSupportEnabled.inc`" '[!SetVariable WebInstallation 1 `"$($RmAPI.VariableStr('CURRENTCONFIG'))`"]'" -Verb RunAs
}
function Remove-Protocol {
    Start-Process powershell -ArgumentList "& `"$root\Helpers\CoreInstaller\CoreInstallerWebSupport.ps1`" `"`" `"$($RmAPI.VariableStr('@'))WebSupportEnabled.inc`" `"`" `"T`"" -Verb RunAs    
}