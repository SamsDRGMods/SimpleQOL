@echo off

echo Administrative permissions required. Detecting permissions...
net session >nul 2>&1
if %errorLevel% == 0 (
	echo Success: Administrative permissions confirmed.
) else (
	echo Failure: Current permissions inadequate.
	pause
	exit
)

rem change the current directory to the bat location
pushd %~dp0

echo making symbolic link
cd ..
rmdir "%cd%\FSD\Content\DRGLib"
del "%cd%\FSD\Content\DRGLib"
mklink /d "%cd%\FSD\Content\DRGLib" "%cd%\DRGLibDevkitFiles\FSD\Content\DRGLib"

pause
