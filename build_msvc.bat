@echo off
rem launch this from msvs-enabled console

set CFLAGS=/std:c17 /O2 /FC /Zi /W4 /WX /wd4458 /wd4996 /nologo
rem set INCLUDES=/I SDL2\include
rem set LIBS=SDL2\lib\x64\SDL2.lib SDL2\lib\x64\SDL2main.lib Shell32.lib

cl.exe %CFLAGS ./src/main.c ./src/eight_utils.c ./src/headers/eight_utils
