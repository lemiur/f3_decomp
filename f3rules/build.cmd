@echo off
rem Build f3rules.exe with the VS2022 x64 compiler. Output goes to out\ (ignored).
setlocal
set "VSROOT=C:\Program Files\Microsoft Visual Studio\2022\Community"
call "%VSROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1
cd /d "%~dp0"
if not exist out mkdir out
cl /nologo /O2 /W3 /MT /Foout\ /Feout\f3rules.exe main.c check.c index.c lex.c coff.c json.c util.c || exit /b 1
echo built %~dp0out\f3rules.exe
