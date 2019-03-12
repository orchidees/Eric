#!/bin/bash

echo "[orchidea - deployment script for command line tools]"
echo ""
if [ $# -ne 1 ]; then 
    echo "syntax is: deployBin.sh ver_number"
    exit -1
fi

if [ -f ../deployments/orchidea-$1.bin.tar.gz ]; then
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

mkdir -p $1.bin
cp build/src/liborchidea* $1.bin
cp build/tools/orchestrate/orchestrate $1.bin
cp build/tools/dbgen/dbgen $1.bin
cp build/tools/dbquery/dbquery $1.bin
cp build/tools/features/features $1.bin
cp build/tools/c_driver/c_driver $1.bin
cp build/tools/cpp_driver/cpp_driver $1.bin
cp scripts/static_orchestration.txt $1.bin
cp scripts/dynamic_orchestration.txt $1.bin
cp scripts/COPYRIGHT $1.bin
cp scripts/changes.txt $1.bin
cp targets/A_minor.wav $1.bin
cp targets/Beethoven_chord2.wav $1.bin
cp targets/Brahms_4.wav $1.bin
cp targets/WinchesterBell.wav $1.bin
cp targets/YanBn-mul-PG-ST12.wav $1.bin
cp targets/archeos-bell.wav $1.bin
cp targets/bass_clarinet.wav $1.bin
cp targets/boat_docking.wav $1.bin
cp targets/car-horn.wav $1.bin 
cp targets/girl-scream.wav $1.bin 
cp targets/wind-harp.wav $1.bin

echo "archiving deployment..."
tar cvzf orchidea-$1.bin.tar.gz $1.bin
mv orchidea-$1.bin.tar.gz deployments
rm -rf $1.bin

echo "build deployed for version " $1


