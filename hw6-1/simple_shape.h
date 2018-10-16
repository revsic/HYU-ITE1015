#ifndef SIMPLE_SHAPE_H
#define SIMPLE_SHAPE_H

class Shape {
public:
    virtual ~Shape() {}
    virtual double Round() const = 0;
    virtual double Area() const = 0;
};

class Circle : public Shape {
public:
    Circle(double x, double y, double radius);
    
    static Circle* InputCircle();

    double Round() const override;
    double Area() const override;

private:
    double m_x;
    double m_y;
    double m_radius;
};

class Rectangle : public Shape {
public:
    // lt : left top, rb: right bottom
    Rectangle(double ltx, double lty, double rbx, double rby);

    static Rectangle* InputRectangle();

    double Round() const override;
    double Area() const override;

private:
    double m_ltx;
    double m_lty;
    double m_rbx;
    double m_rby;
};

#endif
