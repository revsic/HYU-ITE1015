#include "simple_shape.h"

#include <iostream>

Circle::Circle(double x, double y, double radius) : 
    m_x(x), m_y(y), m_radius(radius) 
{
    // Do Nothing
}

Circle* Circle::InputCircle() {
    int x, y, radius;
    std::cin >> x >> y >> radius;

    return new Circle(x, y, radius);
}

double Circle::Round() const {
    return 2 * 3.14 * m_radius;
}

double Circle::Area() const {
    return 3.14 * m_radius * m_radius;
}

Rectangle::Rectangle(double ltx, double lty, double rbx, double rby) :
    m_ltx(ltx), m_lty(lty), m_rbx(rbx), m_rby(rby)
{
    // Do Nothing
}

Rectangle* Rectangle::InputRectangle() {
    int ltx, lty, rbx, rby;
    std::cin >> ltx >> lty >> rbx >> rby;

    return new Rectangle(ltx, lty, rbx, rby);
}

double Rectangle::Round() const {
    auto abs = [](int n) { return n > 0 ? n : -n; };
    return 2 * (abs(m_ltx - m_rbx) + abs(m_lty - m_rby));
}

double Rectangle::Area() const {
    auto abs = [](int n) { return n > 0 ? n : -n; };
    return abs(m_ltx - m_rbx) * abs(m_lty - m_rby);
}
