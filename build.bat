@echo off
cls
set TYPE=%1
if "%TYPE%" equ "CMD" (
	echo "Building CMD Version"
	make -j -f cmdmake.makefile
	if %errorlevel% neq 0 (
		echo "Unsuccessful compile"
	)
	if %errorlevel% equ 0 (
		CMDDriver.exe
	)
)
if "%TYPE%" equ "GUI" (
	echo "Building GUI Version"
	make -j -f guimake.makefile
	if %errorlevel% neq 0 (
		echo "Unsuccessful compile"
	)
	if %errorlevel% equ 0 (
		GUIDriver.exe
	)
)
