#include <iostream>

void getSumDiff(int a, int b, int* pSum, int* pDiff) {
    *pSum = a + b;
    *pDiff = a - b;
}

int main() {
    int a = 0, b = 0;
    int sum = 0, diff = 0;

    std::cin >> a >> b;
    getSumDiff(a, b, &sum, &diff);

    std::cout << sum << ' ' << diff << std::endl;
    return 0;
}
