#!/bin/sh
I="/usr/local/bin/tgnt_version.txt"
R="https://api.github.com/repos/Sonicspite/Tangent/contents/update"

echo "--- Tangent Update Manager ---"

# Get current version
V="0.0.0"
[ -f "$I" ] && V=$(cat "$I" | tr -d '\r\n ' | xargs)
echo "Current System: v$V"

# Branch Selection
echo "Check for (1) Stable or (2) Test?"
printf "> "
read choice
[ "$choice" = "2" ] && B="test" || B="stable"

# GitHub API Check
echo "Checking GitHub..."
L=$(curl -s "$R/$B" | grep '"name":' | sed -E 's/.*"name": "([^"]+)".*/\1/' | sort -V | tail -n 1 | tr -d '\r\n ')

if [ -z "$L" ]; then
    echo "Error: GitHub unreachable."
    exit 1
fi

# Installation 
echo "New update available: v$L"
printf "Install? (y/n): "
read confirm
if [ "$confirm" = "y" ] || [ "$confirm" = "Y" ]; then
    echo "Downloading..."
    mkdir -p /tmp/tgnt_up && cd /tmp/tgnt_up || exit 1
    
    curl -sL "https://github.com/Sonicspite/Tangent/archive/refs/heads/main.tar.gz" -o r.tar.gz
    tar -xzf r.tar.gz


    INSTALLER_PATH=$(find . -path "*/update/$B/*/install.sh" 2>/dev/null | head -n 1)

    if [ -n "$INSTALLER_PATH" ]; then
        cd "$(dirname "$INSTALLER_PATH")"
        # Run installer quietly
        sudo sh install.sh >/dev/null 2>&1
        echo "--------------------------------"
        echo "Update successful! Current: v$L"
    else
        echo "Error: Could not find installer in update/$B/"
    fi
    
    rm -rf /tmp/tgnt_up
    exit 0
fi

echo "Update cancelled."
exit 0