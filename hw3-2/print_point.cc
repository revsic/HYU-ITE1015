#include <iostream>

typedef struct {
    int xpos;
    int ypos;
} Point;

Point point(int xpos, int ypos) {
    Point point;
    point.xpos = xpos;
    point.ypos = ypos;

    return point;
}

Point getScale2xPoint(const Point* p) {
    return point(p->xpos * 2, p->ypos * 2);
}

void swapPoint(Point& p1, Point& p2) {
    Point tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main() {
    int xpos = 0;
    int ypos = 0;
    std::cin >> xpos >> ypos;
    
    Point p1 = point(xpos, ypos);
    std::cout << "Calling getScale2xPoint()" << std::endl;
    std::cout << "P1 : " << p1.xpos << ' ' << p1.ypos << std::endl;

    Point p2 = getScale2xPoint(&p1);
    std::cout << "P2 : " << p2.xpos << ' ' << p2.ypos << std::endl;
    
    std::cout << "Calling swapPoint()" << std::endl;
    swapPoint(p1, p2);

    std::cout << "P1 : " << p1.xpos << ' ' << p1.ypos << std::endl;
    std::cout << "P2 : " << p2.xpos << ' ' << p2.ypos << std::endl;

    return 0;
}
