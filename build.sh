#!/bin/bash
g++ -Iinclude src/*.cpp -o game -lfltk -lfltk_images -lSDL2 -lSDL2_mixer 
./game