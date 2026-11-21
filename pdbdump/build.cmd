@echo off
rem Build pdbdump.exe with the VS2022 x64 compiler. Output goes to out\ (ignored).
setlocal
set "VSROOT=C:\Program Files\Microsoft Visual Studio\2022\Community"
set "DIA=%VSROOT%\DIA SDK"
call "%VSROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul || exit /b 1
cd /d "%~dp0"
if not exist out mkdir out
cl /nologo /O2 /EHsc /W3 /MT /I "%DIA%\include" /Foout\ /Feout\pdbdump.exe pdbdump.cpp ^
   /link "%DIA%\lib\amd64\diaguids.lib" ole32.lib oleaut32.lib advapi32.lib dbghelp.lib || exit /b 1
echo built %~dp0out\pdbdump.exe
