#include <iostream>

int main() {
    int array[3][2] = { 0, };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> array[i][j];
        }
    }

    int sum[2] = { 0, };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            sum[j] += array[i][j];
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "sum of the first column : " << sum[0] << std::endl;
    std::cout << "sum of the second column : " << sum[1] << std::endl;
}
