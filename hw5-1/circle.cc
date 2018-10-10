#include "circle.h"

#define PI 3.141592

double getCirclePerimeter(double radius) {
    return 2 * PI * radius;
}

double getCircleArea(double radius) {
    return PI * radius * radius;
}
