#include "magic_square.h"

int magic_square(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }

    
    int row = 1;
    int col = size / 2 - 1;

    int max = size * size;
    for (int i = 1; i <= max; ++i) {
        int new_row = row - 1;
        int new_col = col + 1;
        
        if (new_row < 0) {
            new_row = size - 1;
        }
        if (new_col >= size) {
            new_col = 0;
        }

        if (matrix[new_row][new_col] != 0) {
            new_row = row + 1;
            new_col = col;
        }

        matrix[new_row][new_col] = i;
        row = new_row;
        col = new_col;
    }
    
    return 0;
}
