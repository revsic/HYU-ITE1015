#include "draw_shape.h"
#include <iostream>

int main() {
    int row, col;
    std::cin >> row >> col;
    Canvas::SetCanvas(row, col);

    while (true) {
        Shape* shape = nullptr;
        
        std::string given;
        std::cin >> given;

        int pos_x, pos_y;
        std::cin >> pos_x >> pos_y;
        
        if (given == "rect") {
            int pos_x, pos_y, height, width;
            std::cin >> height >> width;
            shape = new Rectangle(width, height);
        }
        else if (given == "square") {
            int size;
            std::cin >> size;
            shape = new Square(size);
        }
        else if (given == "diamond") {
            int dist;
            std::cin >> dist;
            shape = new Diamond(dist);
        }
        else if (given == "quit"){
            break;
        }
        else {
            continue;
        }

        char brush;
        std::cin >> brush;

        std::cout << "Area: " << shape->GetArea() << '\n'
                  << "Perimeter: " << shape->GetPerimeter() << '\n'
                  << shape->Draw(pos_x, pos_y).Make(brush) 
                  << std::endl;
        delete shape;
    }
    return 0;
}