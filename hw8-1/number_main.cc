#include "number.h"
#include <iostream>

void print_num(Number const& number) {
    std::cout << "GetNumber(): " << number.GetNumber() << std::endl;
}

void print_square(Square const& square) {
    print_num(square);
    std::cout << "GetSquare(): " << square.GetSquare() << std::endl;
}

void print_cube(Cube const& cube) {
    print_num(cube);
    print_square(cube);
    std::cout << "GetCube(): " << cube.GetCube() << std::endl;
}

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
