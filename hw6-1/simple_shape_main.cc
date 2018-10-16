#include "simple_shape.h"

#include <iostream>

int main() {
    while (true) {
        char shape_info = '\0';
        std::cout << "shape?" << std::endl;
        std::cin >> shape_info;

        Shape* shape = nullptr;
        switch (shape_info) {
        case 'C':
            shape = Circle::InputCircle();
            break;
        case 'R':
            shape = Rectangle::InputRectangle();
            break;
        case 'Q':
            return 0;
        default:
            continue;
        }

        std::cout << "area: " << shape->Area()
                  << ", perimeter: " << shape->Round()
                  << std::endl;
        delete shape;
    }

    return 0;
}
