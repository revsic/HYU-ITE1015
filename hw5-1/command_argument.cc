#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "usage: ./commnad_argument [string] [int]" << std::endl;
        return 1;
    }

    char* str = argv[1];
    int num = std::atoi(argv[2]);

    for (int i = 0; i < num; ++i) {
        std::cout << str << std::endl;
    }

    return 0;
}
