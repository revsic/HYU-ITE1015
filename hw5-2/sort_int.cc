#include "sort.h"

#include <iostream>

int main() {
    int size;
    std::cin >> size;

    if (size <= 0) {
        return 1;
    }

    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    sort_int(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    delete[] array;
    return 0;
}
