#include <iostream>

int main() {
    char input[11] = { 0, };
    std::cin >> input;

    int idx = -1;
    while(input[++idx]) input[idx] ^= 0x20;
    std::cout << input << std::endl;

    return 0;
}
