#!/bin/sh

# 1. Define where the file should go
# /usr/local/bin is the global standard for manual installs
DEST="/usr/local/bin"

echo "--- Tangent Installer/Updater ---"

# Check if the user is running with sudo
if [ "$(id -u)" -ne 0 ]; then
    echo "Error: Please run this script with sudo."
    echo "Example: sudo sh install.sh"
    exit 1
fi

# Moves the binary
if [ -f "./tngnt" ]; then
    cp -f ./tngnt "$DEST/tngnt"
    chmod +x "$DEST/tngnt"
    echo "Successfully installed/updated Tangent! Run 'tngnt' to open Tangent."
else
    echo "Error: 'tngnt' binary not found in this folder."
    exit 1
fi