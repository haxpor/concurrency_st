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

REM build .dll
REM No generation of .pdb file, but debugging info will be generated in .obj file
cl.exe /EHsc /Z7 /DEBUG:NONE /I. /O2 /LD /DCOMPILING_LIB /Fo:%outputDir%/lib.obj lib.cpp /link /DLL /OUT:%outputDir%/lib.dll /IMPLIB:%outputDir%/lib.lib
REM build main.cpp
REM link with lib.lib (import library for lib.dll)
REM and also generate assembly output (included source and assembly code)
cl.exe /EHsc /Z7 /DEBUG:NONE /I. /O2 /FAcs /Fa%outputDir%/main.asm main.cpp /Fo:%outputDir%/main.obj /Fe:%outputDir%/main.exe %outputDir%\lib.lib 

if %ERRORLEVEL% GEQ 1 (
    EXIT /B %ERRORLEVEL%
)

EXIT /B %ERRORLEVEL%

REM Delete all artifact files from build
:DoClean
del /Q %outputDir%\*
EXIT /B 0
