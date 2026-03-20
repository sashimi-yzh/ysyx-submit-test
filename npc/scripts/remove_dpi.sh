#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_directory> <target_directory>"
    exit 1
fi

SOURCE_DIR=$1
TARGET_DIR=$2

mkdir -p "$TARGET_DIR"

find "$SOURCE_DIR" -maxdepth 1 -type f | while read -r FILE_PATH; do
    FILE_NAME=$(basename "$FILE_PATH")
    
    perl -0777 -p -e 's/import "DPI-C" context function void (\w+)\((.*?)\);/function void $1($2);endfunction/sg;' "$FILE_PATH" > "$TARGET_DIR/$FILE_NAME"

    echo "cleaned: $FILE_NAME"
done

echo "DPI-C cleaned and saved to $TARGET_DIR."
