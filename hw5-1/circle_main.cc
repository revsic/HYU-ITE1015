#include "circle.h"

#include <iostream>

int main() {
    double radius;
    std::cin >> radius;

    std::cout << "Perimeter: " << getCirclePerimeter(radius) << std::endl;
    std::cout << "Area: " << getCircleArea(radius) << std::endl;

    return 0;
}
