#include "class_function.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<A*> vec;
    while (true) {
        std::string input;
        std::cin >> input;

        if (input == "B") {
            vec.emplace_back(new B);
        }
        else if (input == "C") {
            vec.emplace_back(new C);
        }
        else if (input == "BB") {
            vec.emplace_back(new BB);
        }
        else if (input == "0") {
            break;
        }
    }

    for (A* elem : vec) {
        elem->test1();
        elem->test2();

        delete elem;
    }

    return 0;
}