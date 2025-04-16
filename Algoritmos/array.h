#include "algorithms.h"

class Array {
    public:
        int* arr;
        int capacity;
        int size;
        Array(int c) : capacity(c), size(0) {
            arr = new int[capacity];
        }
        ~Array();
        bool binary_search(int data, int& iterations, int& index);
        bool insert(int data, int& iterations);
        bool remove(int data, int& iterations, int& up_points);
        void resize();
    };