echo off

@REM Move to the directory where the script is located
cd GameEngine

@REM Run the script
call vendor\bin\premake\premake5.exe vs2019
pause

@REM Move to the directory where the script is located
cd ..

echo on