#!/bin/sh

# Checks for sudo
[ "$(id -u)" -ne 0 ] && echo "Use sudo" && exit 1

# Ask for confirmation
printf "Uninstall Tangent? (y/n): "
read c
[ "$c" != "y" ] && [ "$c" != "Y" ] && exit 

# Remove every file Tangent put in the path
echo "Wiping files..."
rm -f /usr/local/bin/tgnt* /usr/local/bin/tangent_engine.h

echo "Tangent uninstalled successfully."