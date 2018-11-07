#ifndef DRAW_SHAPE_H
#define DRAW_SHAPE_H

#include <string>

class Canvas {
public:
    Canvas();
    ~Canvas();
    
    bool fill(size_t row, size_t col);
    std::string Draw(char brush) const;

    static void SetCanvas(size_t width, size_t height);

private:
    bool* m_pool;
    bool** m_canv;
    static size_t m_width, m_height;
};

class Shape {
public:
    virtual ~Shape() {};
    virtual double GetArea() const = 0;
    virtual int GetPerimeter() const = 0;
    virtual Canvas Draw(size_t pos_x, size_t pos_y) const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int width, int height);

    double GetArea() const override;
    int GetPerimeter() const override;
    Canvas Draw(size_t pos_x, size_t pos_y) const override;

private:
    int m_width, m_height;
};

class Square : public Shape {
public:
    Square(int size);

    double GetArea() const override;
    int GetPerimeter() const override;
    Canvas Draw(size_t pos_x, size_t pos_y) const override;

private:
    int m_size;
};

class Diamond : public Shape {
public:
    Diamond(int dist);

    double GetArea() const override;
    int GetPerimeter() const override;
    Canvas Draw(size_t pos_x, size_t pos_y) const override;

private:
    int m_dist;
};

#endif