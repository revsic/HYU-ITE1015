#include "sort.h"

int sort_int(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i; ++j) {
            if (array[j] < array[j - 1]) {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }

    return 0;
}
