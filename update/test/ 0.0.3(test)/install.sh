#!/bin/sh

DEST="/usr/local/bin"

echo "--- Tangent Installer ---"

# Compiles
echo "Building binary..."
if [ -f "./source/main.c" ]; then
    gcc ./source/main.c -o tgnt -lm
else
    echo "Error: ./source/main.c not found."
    exit 1
fi

# Moves to path
sudo cp -f ./tgnt "$DEST/tgnt"

# Moves everything except the source code
echo "Deploying non-code files from source/ to $DEST..."

for file in ./source/*; do
    # Check if the file ends in .c or .h
    case "$file" in
        *.c|*.h) 
            # Skip these files
            ;;
        *)
            if [ -f "$file" ]; then
                sudo cp -f "$file" "$DEST/"
            fi
            ;;
    esac
done

sudo cp -f ./tgnt_update.sh "$DEST/tgnt_update.sh"
sudo cp -f ./tgnt_uninstall.sh "$DEST/tgnt_uninstall.sh"

# Makes shell files into executables
sudo chmod +x "$DEST/tgnt"
sudo chmod +x "$DEST/tgnt_update.sh"
sudo chmod +x "$DEST/tgnt_uninstall.sh"

echo "Installation successful, use 'tgnt' to open Tangent."