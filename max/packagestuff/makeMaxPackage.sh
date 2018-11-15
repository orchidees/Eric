#!/bin/bash

echo "[orchidea - creating Max package in ~/Documents/Max 7/Packages]"

echo "preparing directories..."
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/externals/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/patchers/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/help/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/extras/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/docs/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/media/

echo "copying icon, package info and license"
cp icon.png ~/Documents/Max\ 7/Packages/orchidea/
cp LICENSE ~/Documents/Max\ 7/Packages/orchidea/
cp package-info.json ~/Documents/Max\ 7/Packages/orchidea/

echo "copying externals..."
cp -R ../externals/*.mxo ~/Documents/Max\ 7/Packages/orchidea/externals/

echo "copying patchers..."
cp ../patchers/*.maxpat ~/Documents/Max\ 7/Packages/orchidea/patchers/

echo "copying help files..."
cp ../help/*.maxhelp ~/Documents/Max\ 7/Packages/orchidea/help/

echo "copying targets..."
cp ../../targets/A_minor.wav ~/Documents/Max\ 7/Packages/orchidea/media/
cp ../../targets/archeos-bell.wav ~/Documents/Max\ 7/Packages/orchidea/media/
cp ../../targets/WinchesterBell.wav ~/Documents/Max\ 7/Packages/orchidea/media/

echo "done!"

