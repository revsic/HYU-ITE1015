#include <iostream>

void getSumDiff(int a, int b, int& sum, int& diff) {
    sum = a + b;
    diff = a - b;
}

int main() {
    int a, b;
    int sum = 0, diff = 0;

    std::cin >> a >> b;
    getSumDiff(a, b, sum, diff);

    std::cout 
        << "Sum: " << sum << std::endl
        << "Diff: " << diff << std::endl;

    return 0;
}
