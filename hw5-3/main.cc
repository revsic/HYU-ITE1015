#include "magic_square.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "usage: ./magic_square [NUM]" << std::endl;
        return 0;
    }

    int size = std::atoi(argv[1]);
    if (size < 3 || size % 2 == 0) {
        return 0;
    }

    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    magic_square(matrix, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;

        delete[] matrix[i];
    }
    delete[] matrix;

    // int max = size * size;
    // int line_total = max * (max + 1) / 2 / size;
    // for (int i = 0; i < size; ++i) {
    //     int row_sum = 0;
    //     int col_sum = 0;
    //     for (int j = 0; j < size; ++j) {
    //         row_sum += matrix[i][j];
    //         col_sum += matrix[j][i];
    //     }
    //     if (row_sum != line_total || col_sum != line_total) {
    //         std::cout << "failed" << std::endl;
    //         return 1;
    //     }
    // }

    return 0;
}
