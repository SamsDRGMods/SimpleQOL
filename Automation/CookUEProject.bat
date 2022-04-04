@echo off
setlocal EnableDelayedExpansion

::Set active directory to the dir the bat is in
pushd %~dp0

call VerifyVars.bat noPause

::Find variables in config.ini
for /f "tokens=1,2 delims==" %%g in (Config.ini) do (
	::Variables modname and ProjectFile need to be treated differently, all other variables in Config.ini are paths
	if %%g==ModName (
		set ModName=%%h
	) else if %%g==ProjectFile (
		::Resolve to path w/ drive letter
		set ProjectFolder=%%~dph
		::Resolve to file name w/ extension
		set ProjectFile=%%~nxh
	) else (
		::Resolve qualified path name
		set %%g=%%~fh
	)
)

echo cooking UE project

"%UnrealEngineLocation%\Engine\Binaries\Win64\UE4Editor-Cmd.exe" "%ProjectFolder%%ProjectFile%" -run=cook -targetplatform=WindowsNoEditor

if %errorlevel% gtr 0 (
	echo Error reported! Stopping bats
	echo 
	pause
	exit
)

echo cooking complete

::There's probably a better way to pass an argument to disable pausing, but Oh well
if not "%1"=="noPause" (
	pause
)
