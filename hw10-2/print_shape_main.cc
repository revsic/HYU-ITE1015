#include "print_shape.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Shape*> vec;

    while (true) {
        char given;
        std::cin >> given;

        if (given == 'c') {
            double rad;
            std::cin >> rad;

            vec.emplace_back(new Circle(rad));
        }
        else if (given == 'r') {
            double width, height;
            std::cin >> width >> height;
            
            vec.emplace_back(new Rectangle(width, height));
        }
        else if (given == '0') {
            break;
        }
    }

    for (auto elem : vec) {
        std::cout << elem->getTypeString() << ", " 
                  << elem->getArea() << ", " 
                  << elem->getPerimeter() << '\n';
        delete elem;
    }
    std::cout << std::endl;
}