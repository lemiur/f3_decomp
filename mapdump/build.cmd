@echo off
rem Build mapdump.exe with the VS2022 x64 compiler. Output goes to out\ (ignored).
setlocal
set "VSROOT=C:\Program Files\Microsoft Visual Studio\2022\Community"
call "%VSROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul || exit /b 1
cd /d "%~dp0"
if not exist out mkdir out
cl /nologo /O2 /W3 /MT /I ..\pdbdump /Foout\ /Feout\mapdump.exe mapdump.c /link dbghelp.lib || exit /b 1
echo built %~dp0out\mapdump.exe
