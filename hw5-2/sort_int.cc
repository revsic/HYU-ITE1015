#include "sort.h"

#include <iostream>

int main() {
    int size;
    std::cin >> size;

    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    sort_int(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
