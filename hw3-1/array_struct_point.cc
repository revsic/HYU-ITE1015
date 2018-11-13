#include <stdio.h>
#include <iostream>

typedef struct {
    int xpos;
    int ypos;
} Point;

void scale2x(Point* pp) {
    pp->xpos *= 2;
    pp->ypos *= 2;
}

int main() {
    Point points[3] = { 0, };

    for (int i = 0; i < 3; ++i) {
        std::cin >> points[i].xpos >> points[i].ypos;
        scale2x(&points[i]);
    }

    for (int i = 0; i < 3; ++i) {
        printf("[%d] %d %d\n", i, points[i].xpos, points[i].ypos);
    }
}
