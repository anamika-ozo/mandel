#!/bin/bash

cd "${0%/*}"
export LD_LIBRARY_PATH="$(pwd)/lib"
/usr/local/bin/mandel
