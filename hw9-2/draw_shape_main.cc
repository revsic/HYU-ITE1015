#include "draw_shape.h"
#include <iostream>
#include <vector>

int main() {
    size_t row, col;
    std::cin >> row >> col;

    Canvas canvas(row, col);
    std::cout << canvas.Print();

    std::vector<Shape*> shapes;
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "add") {
            std::string shape;
            std::cin >> shape;

            size_t x, y;
            char brush;

            if (shape == "rect") {
                size_t width, height;
                std::cin >> x >> y >> width >> height >> brush;
                shapes.emplace_back(new Rectangle(x, y, width, height, brush));
            }
            else if (shape == "tri_up") {
                size_t height;
                std::cin >> x >> y >> height >> brush;
                shapes.emplace_back(new UpTriangle(x, y, height, brush));
            }
            else if (shape == "tri_down") {
                size_t height;
                std::cin >> x >> y >> height >> brush;
                shapes.emplace_back(new DownTriangle(x, y, height, brush));
            }
            else if (shape == "diamond") {
                size_t dist;
                std::cin >> x >> y >> dist >> brush;
                shapes.emplace_back(new Diamond(x, y, dist, brush));
            }
        }
        else if (given == "delete") {
            size_t idx;
            std::cin >> idx;
            
            if (idx < shapes.size()) {
                auto iter = shapes.begin() + idx;
                delete *iter;
                shapes.erase(iter);
            }
        }
        else if (given == "draw") {
            canvas.Clear();
            for (auto const& shape : shapes) {
                shape->Draw(canvas);
            }
            std::cout << canvas.Print();
        }
        else if (given == "dump") {
            for (size_t i = 0; i < shapes.size(); ++i) {
                std::cout << i << ' ' << shapes[i]->ShapeInfo() << std::endl;
            }
        }
        else if (given == "resize") {
            size_t width, height;
            std::cin >> width >> height;
            canvas.Resize(width, height);
        }
        else if (given == "quit") {
            break;
        }
    }

    for (auto& shape : shapes) {
        delete shape;
    }
    return 0;
}