@echo off
rem Build f3prune.exe with the VS2022 x64 compiler. Output goes to out\ (ignored). Shares util.c and coff.c with f3rules.
setlocal
set "VSROOT=C:\Program Files\Microsoft Visual Studio\2022\Community"
call "%VSROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1
cd /d "%~dp0"
if not exist out mkdir out
cl /nologo /O2 /W3 /MT /Foout\ /Feout\f3prune.exe main.c lexp.c parse.c ..\f3rules\util.c ..\f3rules\coff.c || exit /b 1
echo built %~dp0out\f3prune.exe
