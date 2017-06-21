@echo off
cls
set TYPE=%1
if "%TYPE%" == "CMD" (
	echo "Building CMD Version"
	::make --directory=./DataStructures/ -f structures.makefile
	make -j -f cmdmake.makefile
	CMDDriver.exe
)
set NEWPATH=%PATH%;%CD%\SDL2\bin
set PATH=%NEWPATH%;
if "%TYPE%" == "GUI" (
	echo "Building GUI Version"
	make -j -f guimake.makefile
	if %errorlevel% neq 0 exit /b %errorlevel%
	GUIDriver.exe
)
