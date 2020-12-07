@echo off
rem launch this from msvs-enabled console

set CFLAGS=/std:c17 /FC /Wall /WX /nologo

cl.exe %CFLAGS% /Fe"c_doodles.exe" ./src/main.c ./src/eight_utils.c
