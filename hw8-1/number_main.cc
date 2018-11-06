#include "number.h"
#include <iostream>

int main() {
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "quit") {
            break;
        }

        int num = 0;
        std::cin >> num;

        Number* number = nullptr;
        if (given == "number") {
            number = new Number;
        }
        else if (given == "square") {
            number = new Square;
        }
        else if (given == "cube") {
            number = new Cube;
        }

        number->SetNumber(num);
        std::cout << number->GetString();

        delete number;
    }

    return 0;
}
