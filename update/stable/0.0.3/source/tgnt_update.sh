#!/bin/sh
I="/usr/local/bin/tgnt_version.txt"
R="https://api.github.com/repos/Sonicspite/Tangent/contents/update"

echo "--- Tangent Update Manager ---"

# Gets current version
if [ -f "$I" ]; then
    # tr -d cleans invisible characters that break the version check
    V=$(cat "$I" | tr -d '\r\n ' | xargs)
    echo "Current System: v$V"
else
    V="0.0.0"
    echo "No version detected."
fi

# Asks for branch
echo "Check for (1) Stable or (2) Test?"
read -p "> " choice

if [ "$choice" = "2" ]; then
    B="test"
else
    B="stable"
fi

# Gets latest version name from GitHub
echo "Checking GitHub..."
L=$(curl -s "$R/$B" | grep '"name":' | sed -E 's/.*"name": "([^"]+)".*/\1/' | sort -V | tail -n 1 | tr -d '\r\n ')

# Error if GitHub is down
if [ -z "$L" ]; then
    echo "Error: GitHub unreachable."
    exit 1
fi

# Compares local version to GitHub version
if [ "$L" != "$V" ]; then
    echo "New update: v$L"
    read -p "Install? (y/n): " confirm
    if [ "$confirm" = "y" ] || [ "$confirm" = "Y" ]; then
        echo "Downloading..."
        
        # Create temp workspace
        mkdir -p /tmp/tgnt_up && cd /tmp/tgnt_up
        
        # Download the repo
        curl -L "https://github.com/Sonicspite/Tangent/archive/refs/heads/main.tar.gz" -o r.tar.gz
        tar -xzf r.tar.gz --strip-components=1

        # Navigate to the specific version folder
        T="update/$B/$L"
        if [ -d "$T" ]; then
            cd "$T"
            # Runs the installer
            sudo sh install.sh
            echo "Done! You are on v$L."
        else
            echo "Error: Folder not found."
        fi
        
        # Cleans temp files
        rm -rf /tmp/tgnt_up
    fi
else
    echo "Already up to date (v$V)."
fi