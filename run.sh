#!/bin/bash

# show commands being run
set -xe

# Set up the build directory
meson setup build/linux-x86_64

# build the project
ninja -C build/linux-x86_64

# run the project
./build/linux-x86_64/tahm 