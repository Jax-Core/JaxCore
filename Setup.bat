@echo off

cmd /c start powershell -ExecutionPolicy Bypass -command "IWR -UseBasicParsing "https://raw.githubusercontent.com/Jax-Core/JaxCore/master/CoreInstaller.ps1" | IEX"

del "%~dp0" /F /Q /S