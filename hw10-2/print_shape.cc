#include "print_shape.h"

#define PI 3.141592

Shape::~Shape() {
    // Do Nothing
}

Circle::Circle(double rad) : m_rad(rad) {
    // Do Nothing
}

double Circle::getArea() const {
    return PI * m_rad * m_rad;
}

double Circle::getPerimeter() const {
    return 2 * PI * m_rad;
}

std::string Circle::getTypeString() const {
    return "Circle";
}

Rectangle::Rectangle(double width, double height) : 
    m_width(width), m_height(height)
{
    // Do Nothing
}

double Rectangle::getArea() const {
    return m_width * m_height;
}

double Rectangle::getPerimeter() const {
    return 2 * (m_width + m_height);
}

std::string Rectangle::getTypeString() const {
    return "Rectangle";
}