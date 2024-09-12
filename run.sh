#!/bin/bash

# show commands being run
set -xe

# Set up the build directory
meson setup builddir

# build the project
ninja -C builddir

# run the project
./builddir/tahm 
