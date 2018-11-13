#include <stdio.h>
#include <iostream>
#include <limits>

typedef struct {
    double x;
    double y;
} Point;

double dist(const Point& point) {
    return point.x * point.x + point.y * point.y;
}

typedef struct {
    char name[7];
    Point points[3];
} Person;

int main() {
    Person people[3] = { 0, };
    int offset[3] = { 0, };

    for (int i = 0; i < 3; ++i) {
        std::cin >> people[i].name;
        double max = std::numeric_limits<double>::min();
        
        for (int j = 0; j < 3; ++j) {
            Point& point = people[i].points[j];
            std::cin >> point.x >> point.y;
            
            double now = dist(point);
            if (max < now) {
                max = now;
                offset[i] = j;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        const Person& person = people[i];
        const Point& point = person.points[offset[i]];
        printf("%s (%lf, %lf)\n", person.name, point.x, point.y);
    }

    return 0;
}
