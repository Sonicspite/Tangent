#!/bin/sh
I="/usr/local/bin/tgnt_version.txt"
R="https://api.github.com/repos/Sonicspite/Tangent/contents/update"

echo "--- Tangent Update Manager ---"

# 1. Gets current version from the system file
if [ -f "$I" ]; then
    # Clean up invisible characters that might break the check
    V=$(cat "$I" | tr -d '\r\n ' | xargs)
    echo "Current System: v$V"
else
    V="0.0.0"
    echo "No version detected."
fi

# 2. Ask user for the update branch
echo "Check for (1) Stable or (2) Test?"
printf "> "
read choice

if [ "$choice" = "2" ]; then
    B="test"
else
    B="stable"
fi

# 3. Get the latest version folder name from GitHub API
echo "Checking GitHub..."
L=$(curl -s "$R/$B" | grep '"name":' | sed -E 's/.*"name": "([^"]+)".*/\1/' | sort -V | tail -n 1 | tr -d '\r\n ')

if [ -z "$L" ]; then
    echo "Error: GitHub unreachable."
    exit 1
fi

# 4. Compare local version to GitHub version
if [ "$L" != "$V" ]; then
    echo "New update available: v$L"
    printf "Install? (y/n): "
    read confirm
    if [ "$confirm" = "y" ] || [ "$confirm" = "Y" ]; then
        echo "Downloading..."
        
        # Create a clean workspace in /tmp
        mkdir -p /tmp/tgnt_up && cd /tmp/tgnt_up || exit 1
        
        # Download the main repository archive
        curl -L "https://github.com/Sonicspite/Tangent/archive/refs/heads/main.tar.gz" -o r.tar.gz
        
        # Extract everything (maintaining folder structure)
        tar -xzf r.tar.gz

        # FINDER LOGIC: This finds the install.sh file inside the specific branch folder
        # It handles spaces, extra 'v' characters, and weird folder names automatically.
        INSTALLER_PATH=$(find . -path "*/update/$B/*/install.sh" | head -n 1)

        if [ -n "$INSTALLER_PATH" ]; then
            # Move into the folder where the installer is located
            cd "$(dirname "$INSTALLER_PATH")"
            
            # Run the actual installation
            sudo sh install.sh
            echo "--------------------------------"
            echo "Success! You are now on v$L."
        else
            echo "Error: Could not find the installer for $B version $L."
            echo "Checking extracted files..."
            ls -R
        fi
        
        # Cleanup temp directory
        cd /
        rm -rf /tmp/tgnt_up
    fi
else
    echo "Already up to date (v$V)."
fi