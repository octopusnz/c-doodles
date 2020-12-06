@echo off
rem launch this from msvs-enabled console

set CFLAGS=/std:c17 /O2 /FC /Zi /W4 /WX /wd4458 /wd4996 /nologo

cl.exe %CFLAGS /Fe"c_doodles.exe" /src/main.c /src/eight_utils.c /src/headers/eight_utils.h ^
  -SUBSYSTEM:windows
