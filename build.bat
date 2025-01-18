@echo off
setlocal enabledelayedexpansion

set BUILD_DIR=build
set BUILD_TYPE=Release
set "ASSET_PATH=AssetFile"
set "DEST_DIR=build\bin\Release"

if not exist "%BUILD_DIR%" (
    echo Creating build directory: %BUILD_DIR%
    mkdir "%BUILD_DIR%"
)

cd "%BUILD_DIR%"

echo Configuring the project...
cmake .. -DCMAKE_BUILD_TYPE=%BUILD_TYPE%

echo Building the project...
cmake --build . --config %BUILD_TYPE%

cd ..

echo Copying assets to the destination directory: %DEST_DIR%
xcopy "%ASSET_PATH%" "%DEST_DIR%\AssetFile" /E /I /Y

echo Build complete!
