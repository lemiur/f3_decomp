@echo off
rem Build f3link with the VS2022 x64 compiler. Output: out\f3link.exe (ignored by git).
rem Run: out\f3link.exe --evidence E:/f3-campaign/evidence --recipe E:/f3-campaign/f3_decomp/build/units.json --out E:/f3-campaign/evidence/links
setlocal
if "%VCVARS%"=="" set "VCVARS=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
if "%VSCMD_VER%"=="" call "%VCVARS%" >nul
cd /d "%~dp0"
if not exist out mkdir out
cl /nologo /O2 /W4 /wd4996 /wd4100 /wd4244 /wd4267 /Fe:out\f3link.exe /Fo:out\ f3link.c
exit /b %ERRORLEVEL%
