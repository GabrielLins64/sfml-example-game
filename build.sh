#!/bin/bash

SFML_PATH="$(pwd)/lib/SFML-2.5.1"

# Compile all source files to object files in "build", and link those into a binary in "bin"
mkdir -p build
mkdir -p bin
rm -f build/*.o
g++ -c -Iinclude -I"${SFML_PATH}/include" src/*.cpp && \
mv *.o build/
g++ build/*.o -o "bin/game" -L"${SFML_PATH}/lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && \
export LD_LIBRARY_PATH="${SFML_PATH}/lib"
