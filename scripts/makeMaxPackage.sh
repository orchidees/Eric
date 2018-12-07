#!/bin/bash

echo "[orchidea - creating Max package in ~/Documents/Max 7/Packages]"

echo "preparing directories..."
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/externals/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/patchers/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/help/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/init/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/interfaces/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/docs/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/docs/refpages/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/docs/tutorials/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/docs/refpages/orchidea_ref/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/extras/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/docs/
mkdir -p ~/Documents/Max\ 7/Packages/orchidea/media/

echo "copying icon, package info and license"
cp ../scripts/COPYING.* ~/Documents/Max\ 7/Packages/orchidea/
cp package-info.json ~/Documents/Max\ 7/Packages/orchidea/

echo "copying extras..."
cp -R ../max/extras/*.maxpat ~/Documents/Max\ 7/Packages/orchidea/extras/

echo "copying externals..."
cp -R ../max/externals/*.mxo ~/Documents/Max\ 7/Packages/orchidea/externals/

echo "copying patchers..."
cp ../max/patchers/*.maxpat ~/Documents/Max\ 7/Packages/orchidea/patchers/

echo "copying help files..."
cp ../max/help/*.maxhelp ~/Documents/Max\ 7/Packages/orchidea/help/

echo "copying docs files..."
cp ../max/docs/refpages/orchidea_ref/* ~/Documents/Max\ 7/Packages/orchidea/docs/refpages/orchidea_ref/

echo "copying tutorials files..."
cp ../max/docs/tutorials/* ~/Documents/Max\ 7/Packages/orchidea/docs/tutorials/

echo "copying init files..."
cp ../max/init/* ~/Documents/Max\ 7/Packages/orchidea/init/

echo "copying interface files..."
cp ../max/interfaces/* ~/Documents/Max\ 7/Packages/orchidea/interfaces/

echo "copying targets..."
cp ../max/media/* ~/Documents/Max\ 7/Packages/orchidea/media/

echo "done!"

