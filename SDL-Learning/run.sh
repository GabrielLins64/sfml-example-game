#!/bin/bash

# Static including SDL, linking it and running the application:
rm build/*
SDL_PATH="lib/SDL2-2.0.14"
SDL_IMAGE_PATH="lib/SDL2_image-2.0.5"
DLIB_SDL_IMAGE_PATH="/usr/local/lib/libSDL2_image.a"
g++ -std=c++17 -c -Iinclude -I "${SDL_PATH}/include" -I"${SDL_IMAGE_PATH}" src/*.cpp && \
mv *.o build
# g++ build/*.o -o "bin/$1" -L"${SDL_PATH}/build" "-lSDL2" && \
# export LD_LIBRARY_PATH="${SDL_PATH}/build" && ./bin/$1
g++ -std=c++17 -o "bin/$1" build/*.o "${SDL_PATH}/build/libSDL2.so" "${DLIB_SDL_IMAGE_PATH}" && \
./bin/$1
