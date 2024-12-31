ASSET_PATH="../AssetFile"
DEST_DIR="bin/Release"
cmake --build . --config Release
cp -r "$ASSET_PATH" "$DEST_DIR/"
