@echo off
REM Makefile.bat - Windows batch equivalent of the Linux Makefile

REM Compilers
set CC=gcc.exe
set CXX=g++.exe

REM Flags
set CFLAGS=-std=c23 -Wall -Wextra -Wpedantic -g
set CXXFLAGS=-std=c++23 -Wall -Wextra -Wpedantic -g

REM Source files
set C_SRCS=C\main.c C\hash_fn.c
set C_OBJS=C\main.o C\hash_fn.o
set C_BIN=C\hash_function.exe

set CXX_SRCS=CXX\main.cpp CXX\hash_fn.cpp
set CXX_OBJS=CXX\main.o CXX\hash_fn.o
set CXX_BIN=CXX\hash_function_cpp.exe

if "%1"=="" goto all
if "%1"=="all" goto all
if "%1"=="c" goto c
if "%1"=="cxx" goto cxx
if "%1"=="clean" goto clean
goto usage

:all
call :c
call :cxx
goto end

:c
echo Building C version...
%CC% %CFLAGS% -c C\main.c -o C\main.o
%CC% %CFLAGS% -c C\hash_fn.c -o C\hash_fn.o
%CC% %CFLAGS% -o %C_BIN% %C_OBJS%
goto end

:cxx
echo Building C++ version...
%CXX% %CXXFLAGS% -c CXX\main.cpp -o CXX\main.o
%CXX% %CXXFLAGS% -c CXX\hash_fn.cpp -o CXX\hash_fn.o
%CXX% %CXXFLAGS% -o %CXX_BIN% %CXX_OBJS%
goto end

:clean
echo Cleaning...
if exist C\*.o del C\*.o
if exist CXX\*.o del CXX\*.o
if exist %C_BIN% del %C_BIN%
if exist %CXX_BIN% del %CXX_BIN%
goto end

:usage
echo Usage: Makefile.bat [all^|c^|cxx^|clean]
echo   all   - Build both C and C++ versions (default)
echo   c     - Build C version only
echo   cxx   - Build C++ version only
echo   clean - Remove all generated files

:end
