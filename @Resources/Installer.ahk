#SingleInstance, Force
SendMode Input
SetWorkingDir, %A_ScriptDir%

File = %A_scriptDir%\Installer.ahk
MoveUpDirTree(File)

IniRead, OutputVar, SecVar.inc, Variables, "Skin.Name"
MsgBox, %OutputVar%


;---------------------------------------------------------------------------
MoveUpDirTree(File) {
;---------------------------------------------------------------------------
    ; This function will move a file one notch up in the directory tree
    ; No error checking included if File exists
    ;-----------------------------------------------------------------------
    FileMove, %File%, %File%\..\..
}
