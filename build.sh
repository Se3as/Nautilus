#!/bin/bash
g++ -Iinclude src/*.cpp -o game2 -lfltk -lfltk_images -lSDL2 -lSDL2_mixer 
./game