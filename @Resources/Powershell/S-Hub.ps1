# ---------------------------------------------------------------------------- #
#                                    Actions                                   #
# ---------------------------------------------------------------------------- #

Function Initiate {
    $SKINSPATH = $RmAPI.VariableStr('SKINSPATH').TrimEnd('\')
    $PROGRAMPATH = $RmAPI.VariableStr('SETTINGSPATH').TrimEnd('\')
    Start-Process powershell.exe -Verb RunAs -ArgumentList ("-ExecutionPolicy Bypass -noprofile -file `"$SKINSPATH\#JaxCore\S-Hub\shp-registerer.ps1`" -corepath `"$SKINSPATH`" -rmpath `"$PROGRAMPATH`" -elevated")
}