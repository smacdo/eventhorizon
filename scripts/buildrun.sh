#!/bin/sh
### Assumes you are in project root directory
currentdir=`pwd`

# If build directory doesn't exist, init it
if [ ! -d "build" ]; then
    mkdir build
    cd build
    
    cmake ../
    if [ $? -ne 0 ]; then
        echo "Failed to init build dir with cmake"
        exit $?
    fi

    cd ..
fi

# If the directory *still* doesn't exist, we're screwed
if [ ! -d "build" ]; then
    echo "Failed to create build dir"
    exit 1
fi

# Build the game
cd build && make

if [ $? -ne 0 ]; then
    echo "*******************************************************"
    echo "Failed to build event horizon - there were build errors"
    echo "*******************************************************"
    cd $currentdir
    exit 1
fi

cd $currentdir

# Run the game
cd game && ./eventhorizon

if [ $? -ne 0 ]; then
    echo "****************************************************"
    echo "Failed to run event horizon - It exited with errors!"
    echo "****************************************************"
    cd $currentdir
    exit 1
fi

cd $currentdir
