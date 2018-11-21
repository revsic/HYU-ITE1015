#ifndef PRINT_SHAPE_H
#define PRINT_SHAPE_H

#include <string>

class Shape {
public:
    virtual ~Shape();
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getTypeString() const = 0;
};

class Circle : public Shape {
public:
    Circle(double rad);

    double getArea() const override;
    double getPerimeter() const override;
    std::string getTypeString() const override;

private:
    double m_rad;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);

    double getArea() const override;
    double getPerimeter() const override;
    std::string getTypeString() const override;

private:
    double m_width;
    double m_height;
};

#endif