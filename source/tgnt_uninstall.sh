#!/bin/sh

DEST="/usr/local/bin"

echo "--- Tangent Uninstaller ---"

# Checks for sudo
if [ "$(id -u)" -ne 0 ]; then
    echo "Error: Please run with sudo."
    echo "Example: sudo tgnt uninstall"
    exit 1
fi

# Ask for confirmation
printf "Are you sure you want to uninstall Tangent? (y/n): "
read confirm

if [ "$confirm" != "y" ] && [ "$confirm" != "Y" ]; then
    echo "Uninstall cancelled."
    exit 0
fi

# Remove every file Tangent put in the path
echo "Wiping tgnt files from $DEST..."

rm -f "$DEST/tgnt"                # The program
rm -f "$DEST/tgnt_update.sh"      # The updater
rm -f "$DEST/tgnt_version.txt"    # The version info
rm -f "$DEST/tangent_engine.h"    # The header file (if it exists)

# Deletes itself
if [ -f "$DEST/tgnt_uninstall.sh" ]; then
    echo "Removing uninstaller..."
    rm -f "$DEST/tgnt_uninstall.sh"
fi

echo "Uninstall complete."