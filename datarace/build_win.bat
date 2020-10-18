@echo off
setlocal

set outputDir=bin-win

if "%1" == "clean" (
    call :DoClean
    echo "Remove all artifact files from build"
    EXIT /B %ERRORLEVEL%
)

if not exist %outputDir% (
    mkdir %outputDir%
)

REM build main.cpp
REM and also generate assembly output (included source and assembly code)
cl.exe /EHsc /Z7 /I. /FAcs /Fa%outputDir%/main.asm main.cpp /Fo:%outputDir%/main.obj /Fe:%outputDir%/main.exe

if %ERRORLEVEL% GEQ 1 (
    EXIT /B %ERRORLEVEL%
)

EXIT /B %ERRORLEVEL%

REM Delete all artifact files from build
:DoClean
del /Q %outputDir%\*
EXIT /B 0
