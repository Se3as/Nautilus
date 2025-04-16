#!/bin/bash

g++ -std=c++17 -o my_program \
    algorithms.cpp array.cpp BTree.cpp LinkedList.cpp \
    RedBlackTree.cpp SplayTree.cpp ship.cpp game.cpp -o game
echo
./game
echo
echo "Press Enter to continue..."
read