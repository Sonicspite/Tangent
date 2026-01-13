#!/bin/sh

# Defines file path of installation
DEST="/usr/local/bin/tngnt"

echo "--- Tangent Uninstaller ---"

# Checks for sudo
if [ "$(id -u)" -ne 0 ]; then
    echo "Error: Please run this script with sudo."
    echo "Example: sudo sh uninstall.sh"
    exit 1
fi

# Check if Tangent exists 
if [ -f "$DEST" ]; then
    echo "Removing Tangent from $DEST..."
    rm -f "$DEST"
    
    # Check if the removal was successful
    if [ $? -eq 0 ]; then
        echo "Successfully uninstalled Tangent."
    else
        echo "Error: Failed to remove the binary."
        exit 1
    fi
else
    echo "Tangent is not installed."
fi

if [ -f "./tngnt" ]; then
    echo "Cleaning up local build files..."
    rm -f ./tngnt
fi

echo "Uninstall complete."