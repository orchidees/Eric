#!/bin/bash

echo "[anarkid - deployment script]"
echo ""
if [ $# -ne 1 ]; then 
    echo "syntax is: deployAll.sh ver_number"
    exit -1
fi

if [ -f ../deployments/anarkid-$1.all.tar.gz ]; then
    read -p "version already deployed; do you want to overwrite (Y/n)? " -n 1 -r
	echo    # (optional) move to a new line
	if [[ $REPLY =~ ^[Nn]$ ]]
	then
	    exit 0
	fi
fi

echo "building library and command line tools..."
cd ..
mkdir -p build
cd build
make

cd ..

mkdir -p deployments

echo "preparing version " $1 "..."

mkdir -p $1.all
cp build/src/anarkid $1.all
cp build/src/makedb $1.all
cp scripts/default_orchestration.txt $1.all
cp scripts/COPYRIGHT $1.all
cp scripts/changes.txt $1.all
cp targets/A_minor.wav $1.all
cp targets/Beethoven_chord2.wav $1.all
cp targets/Brahms_4.wav $1.all
cp targets/WinchesterBell.wav $1.all
cp targets/YanBn-mul-PG-ST12.wav $1.all
cp targets/archeos-bell.wav $1.all
cp targets/bass_clarinet.wav $1.all
cp targets/boat_docking.wav $1.all
cp targets/car-horn.wav $1.all 
cp targets/girl-scream.wav $1.all 
cp targets/wind-harp.wav $1.all

echo "archiving deployment..."
tar cvzf anarkid-$1.all.tar.gz $1.all
mv anarkid-$1.all.tar.gz deployments
rm -rf $1.all

echo "build deployed for version " $1


