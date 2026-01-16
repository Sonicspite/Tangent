#!/bin/sh

DEST="/usr/local/bin"

echo "--- Tangent Installer ---"

# Compiles
echo "Compiling..."
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

# Creates save and log files
sudo touch "$DEST/tgnt_save.txt" "$DEST/tgnt_logs.txt"

#Grants premissions
sudo touch /usr/local/bin/tgnt_save.txt
sudo chmod a+rw "$DEST/tgnt_save.txt" "$DEST/tgnt_logs.txt"

# Makes shell files into executables
sudo chmod +x "$DEST/tgnt"
sudo chmod +x "$DEST/tgnt_update.sh"
sudo chmod +x "$DEST/tgnt_uninstall.sh"

echo "Installation successful, use 'tgnt' to open Tangent."