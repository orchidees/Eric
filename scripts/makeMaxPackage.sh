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
cp COPYRIGHT ~/Documents/Max\ 7/Packages/orchidea/
cp package-info.json ~/Documents/Max\ 7/Packages/orchidea/

echo "copying externals..."
cp -R ../max/externals/*.mxo ~/Documents/Max\ 7/Packages/orchidea/externals/

echo "copying patchers..."
cp ../max/patchers/*.maxpat ~/Documents/Max\ 7/Packages/orchidea/patchers/

echo "copying help files..."
cp ../max/help/*.maxhelp ~/Documents/Max\ 7/Packages/orchidea/help/

echo "copying targets..."
cp ../max/media/* ~/Documents/Max\ 7/Packages/orchidea/media/

echo "done!"

