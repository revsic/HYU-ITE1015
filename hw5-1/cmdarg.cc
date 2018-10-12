#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int total = 0;
    std::string concat;

    for (int i = 1; i < argc; ++i) {
        int parse = std::atoi(argv[i]);
        
        if (parse == 0) {
            concat += argv[i];
        }
        else {
            total += parse;
        }
    }

    std::cout 
        << concat << std::endl
        << total << std::endl;

    return 0;
}
