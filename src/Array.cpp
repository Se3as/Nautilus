#include "Array.h"

Array::~Array() {
    delete[] arr;
}

bool Array::binary_search(int data, int& iterations, int& index) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        iterations++;

        if (arr[mid] == data) {
            index = mid;
            return true;
        }
        if (arr[mid] < data) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    index = left;
    return false;
}

bool Array::insert(int data, int& iterations) {
    if (size == capacity) {
        resize();
    }
    int index;
    binary_search(data, iterations, index);

    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
        iterations++;
    }
    
    arr[index] = data;
    size++;
    //iterations++;

return true;
}

bool Array::remove(int data, int& iterations, int& up_points) {
    int index;
    if (!binary_search(data, iterations, index)) {
        return false;
    }

    for (int i = index; i < size - 1; i++) {
        iterations++;
        if (up_points >= iterations) {
            arr[i] = arr[i + 1];
        }
    }
    size--;
    return true;
}
void Array::resize() {
    capacity *= 2;
    int* newArr = new int[capacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}