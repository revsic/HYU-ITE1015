#ifndef DRAW_SHAPE_H
#define DRAW_SHAPE_H

#include <string>

template <typename T>
struct Box {
    T* ptr;
    size_t size;

    Box(size_t size) : ptr(new T[size]), size(size) {
        // Do Nothing
    }

    ~Box() {
        reset();
    }

    Box(const Box&) = delete;
    Box(Box&& box) : ptr(box.ptr), size(box.size) {
        box.ptr = nullptr;
    }

    Box& operator=(const Box&) = delete;
    Box& operator=(Box&& box) {
        reset();
        ptr = box.ptr;
        size = box.size;
        box.ptr = nullptr;

        return *this;
    }

    void reset() {
        if (ptr != nullptr) {
            delete[] ptr;
        }
    }

    operator T*() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

    const T& operator*() const {
        return *ptr;
    }

    T& operator[](size_t idx) {
        return ptr[idx];
    }

    const T& operator[](size_t idx) const {
        return ptr[idx];
    }
};

class Canvas {
public:
    Canvas(size_t row, size_t col);

    void Resize(size_t w, size_t h);
    bool DrawPixel(size_t y, size_t x, char brush);
    std::string Print() const;
    void Clear();

private:
    size_t m_row;
    size_t m_col;

    Box<char> m_block;
    Box<char*> m_pixels;
};

class Shape {
public:
    Shape(size_t x, size_t y, char brush);
    virtual ~Shape() = default;
    virtual std::string ShapeInfo() const = 0;
    virtual void Draw(Canvas& canvas) const = 0;

    size_t GetX() const;
    size_t GetY() const;
    char GetBrush() const;

private:
    size_t m_x, m_y;
    char m_brush;
};

class Rectangle : public Shape {
public:
    Rectangle(size_t x, size_t y, size_t width, size_t height, char brush);

    std::string ShapeInfo() const override;
    void Draw(Canvas& canvas) const override;

private:
    size_t m_width, m_height;
};

class UpTriangle : public Shape {
public:
    UpTriangle(size_t x, size_t y, size_t height, char brush);

    std::string ShapeInfo() const override;
    void Draw(Canvas& canvas) const override;

private:
    size_t m_height;
};

class DownTriangle : public Shape {
public:
    DownTriangle(size_t x, size_t y, size_t height, char brush);

    std::string ShapeInfo() const override;
    void Draw(Canvas& canvas) const override;

private:
    size_t m_height;
};

class Diamond : public Shape {
public:
    Diamond(size_t x, size_t y, size_t dist, char brush);

    std::string ShapeInfo() const override;
    void Draw(Canvas& canvas) const override;

private:
    size_t m_dist;
};



#endif