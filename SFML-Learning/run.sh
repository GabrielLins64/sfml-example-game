#!/bin/bash

# # With sfml-dev installed:
# g++ -c -Iinclude "src/$1.cpp" -o "build/$1.o" && \
# g++ -o "bin/$1" "build/$1.o" -lsfml-graphics -lsfml-window -lsfml-system && \
# ./"bin/$1"

# # Using project included SFML lib (Only 1 source file):
# SFML_PATH="lib/SFML-2.5.1"
# g++ -c -Iinclude -I"${SFML_PATH}/include" "src/$1.cpp" -o "build/$1.o" && \
# g++ "build/$1.o" -o "bin/$1" -L"${SFML_PATH}/lib" -lsfml-graphics -lsfml-window -lsfml-system && \
# export LD_LIBRARY_PATH="${SFML_PATH}/lib" && ./bin/$1

# Compile all source files to object files in "build", and link those into a binary in "bin"
rm build/*
SFML_PATH="lib/SFML-2.5.1"
g++ -c -Iinclude -I"${SFML_PATH}/include" src/*.cpp && \
mv *.o build/
g++ build/*.o -o "bin/$1" -L"${SFML_PATH}/lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && \
export LD_LIBRARY_PATH="${SFML_PATH}/lib" && ./bin/$1
