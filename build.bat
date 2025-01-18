@echo off
setlocal

set "ASSET_PATH=..\AssetFile"
set "DEST_DIR=bin\Release"

cmake --build . --config Release

xcopy "%ASSET_PATH%" "%DEST_DIR%" /E /I /Y
