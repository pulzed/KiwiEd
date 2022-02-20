#!/bin/bash
if [ "$1" = "debug" ]
then
	BUILD_TYPE="debug"
elif [ "$1" = "release" ]
then
	BUILD_TYPE="release"
else
	BUILD_TYPE="debug"
fi

./build.sh $BUILD_TYPE

if [ "$BUILD_TYPE" = "debug" ]
then
	echo "== Running Debug =="
	./build/Debug/bin/KiwiEd
elif [ "$BUILD_TYPE" = "release" ]
then
	echo "== Running Release =="
	./build/Release/bin/KiwiEd
fi
