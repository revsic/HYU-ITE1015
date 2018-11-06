#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(int width, int height) : m_width(width), m_height(height) {
    // Do Nothing
}

int Rectangle::GetArea() const {
    return m_width * m_height;
}

int Rectangle::GetPerimeter() const {
    return 2 * (m_width + m_height);
}

void Rectangle::PrintInfo(std::string&& id) const {
    std::cout << m_width << 'x' << m_height << ' ' <<  id << '\n'
              << "Area: " << GetArea() << '\n'
              << "Perimeter: " << GetPerimeter() << std::endl;
}

Square::Square(int width) : Rectangle(width, width) {
    // Do Nothing
}

void Square::Print() const {
    Rectangle::PrintInfo("Square");
}

NonSquare::NonSquare(int width, int height) : Rectangle(width, height) {
    // Do Nothing
}

void NonSquare::Print() const {
    Rectangle::PrintInfo("NonSquare");
}
