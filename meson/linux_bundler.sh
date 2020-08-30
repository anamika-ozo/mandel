#!/bin/bash

export LD_LIBRARY_PATH=${HOME}/devroot/lib
export PATH=${HOME}/devroot/bin:$PATH
export PKG_CONFIG_PATH=${HOME}/devroot/lib/pkgconfig

cd "${0%/*}"
export LD_LIBRARY_PATH="$(pwd)/lib"
/usr/local/bin/mandel
