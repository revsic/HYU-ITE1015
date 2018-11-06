#include "rectangle.h"
#include <iostream>

int main() {
    while (true) {
        std::string given;
        std::cin >> given;

        Rectangle* rect = nullptr;
        if (given == "nonsquare") {
            int width, height;
            std::cin >> width >> height;
            rect = new NonSquare(width, height);
        }
        else if (given == "square") {
            int width;
            std::cin >> width;
            rect = new Square(width);
        }
        else if (given == "quit") {
            break;
        }

        rect->Print();
        delete rect;
    }
    return 0;
}
