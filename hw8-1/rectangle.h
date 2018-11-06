#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle {
public:
    Rectangle(int width, int height);
    virtual ~Rectangle() = default;

    int GetArea() const;
    int GetPerimeter() const;

    void PrintInfo(std::string&& id) const;
    virtual void Print() const = 0;

private:
    int m_width, m_height;
};

class Square : public Rectangle {
public:
    Square(int width);
    void Print() const override;
};

class NonSquare : public Rectangle {
public:
    NonSquare(int width, int height);
    void Print() const override;
};

#endif

