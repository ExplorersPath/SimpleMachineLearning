@echo off

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

mkdir .\build
cd .\build
cl ..\main.c

IF %ERRORLEVEL% NEQ 0 (
    echo Compilation failed. Exiting...
    exit /b %ERRORLEVEL%
)

main.exe