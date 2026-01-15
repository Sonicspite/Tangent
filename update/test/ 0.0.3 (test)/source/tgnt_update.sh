#!/bin/sh

REPO_API="https://api.github.com/repos/Sonicspite/Tangent/contents/update"
INSTALLED_VER="/usr/local/bin/tgnt_version.txt"

echo "--- Tangent Update Manager ---"

# Gets current version
if [ -f "$INSTALLED_VER" ]; then
    CURRENT_VER=$(cat "$INSTALLED_VER" | xargs)
    echo "Current System: tgnt v$CURRENT_VER"
else
    CURRENT_VER="0.0.0"
    echo "No system version detected."
fi

echo "Check for (1) Stable or (2) Test?"
read -p "> " choice

if [ "$choice" = "2" ]; then
    BRANCH_PATH="test"
else
    BRANCH_PATH="stable"
fi

# Gets folder names from GitHub
echo "Checking GitHub for the latest $BRANCH_PATH build..."
# This grabs the folder names exactly as they are (e.g., "0.0.3 (test)")
LATEST_VER=$(curl -s "$REPO_API/$BRANCH_PATH" | grep '"name":' | sed -E 's/.*"name": "([^"]+)".*/\1/' | sort -V | tail -n 1)

if [ -z "$LATEST_VER" ]; then
    echo "Error: Could not reach GitHub or no versions found in $BRANCH_PATH."
    exit 1
fi

if [ "$LATEST_VER" != "$CURRENT_VER" ]; then
    echo "New update available: tgnt v$LATEST_VER"
    read -p "Would you like to install this build? (y/n): " confirm
    
    if [ "$confirm" = "y" ] || [ "$confirm" = "Y" ]; then
        echo "Downloading build: $LATEST_VER..."
        
        # Create temp workspace
        mkdir -p /tmp/tgnt_up && cd /tmp/tgnt_up
        
        # Download the repo
        curl -L "https://github.com/Sonicspite/Tangent/archive/refs/heads/main.tar.gz" -o repo.tar.gz
        tar -xzf repo.tar.gz --strip-components=1

        # Navigate to the specific folder name
        TARGET_DIR="update/$BRANCH_PATH/$LATEST_VER"
        
        if [ -d "$TARGET_DIR" ]; then
            cd "$TARGET_DIR"
            echo "Installing tgnt v$LATEST_VER..."
            
            # Run the installer
            sudo sh install.sh
            
            echo "Update complete! You are now on v$LATEST_VER. Use 'tgnt' to open Tangent."
        else
            echo "Error: Folder '$TARGET_DIR' not found in download."
        fi

        # Cleans
        cd /tmp
        rm -rf /tmp/tgnt_up
    fi
else
    echo "You are already running tgnt v$CURRENT_VER."
fi