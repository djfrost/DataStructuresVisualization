@echo off
cls
set TYPE=%1
if "%TYPE%" == "CMD" (
	echo "Building CMD Version"
	make -j -f cmdmake.makefile
	if %errorlevel% neq 0 (
		echo "Unsuccessful compile"
	)
	if %errorlevel% equ 0 (
		CMDDriver.exe
	)
)
set NEWPATH=%PATH%;%CD%\SDL2\bin
set PATH=%NEWPATH%;
if "%TYPE%" == "GUI" (
	echo "Building GUI Version"
	make -j -f guimake.makefile
	if %errorlevel% neq 0 (
		echo "Unsuccessful compile"
	)
	if %errorlevel% equ 0 (
		GUIDriver.exe
	)
)
