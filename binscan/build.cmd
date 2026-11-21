@echo off
rem Build binscan with the VS2022 x64 compiler. Output: out\binscan.exe (ignored by git).
setlocal
if "%VCVARS%"=="" set "VCVARS=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
if "%VSCMD_VER%"=="" call "%VCVARS%" >nul
cd /d "%~dp0"
if not exist out mkdir out
cl /nologo /O2 /W4 /wd4996 /wd4100 /Fe:out\binscan.exe /Fo:out\ binscan.c
exit /b %ERRORLEVEL%
