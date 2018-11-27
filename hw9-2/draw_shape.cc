#include "draw_shape.h"
#include <cmath>
#include <iomanip>
#include <sstream>

Canvas::Canvas(size_t row, size_t col) : 
    m_row(row), m_col(col), m_block(m_row * m_col), m_pixels(m_row)
{
    for (size_t i = 0; i < m_row; ++i) {
        m_pixels[i] = &m_block[i * m_col];
    }
    Clear();
}

void Canvas::Resize(size_t w, size_t h) {
    m_row = h;
    m_col = w;

    m_block = Box<char>(m_row * m_col);
    m_pixels = Box<char*>(m_row);

    for (size_t i = 0; i < m_row; ++i) {
        m_pixels[i] = &m_block[i * m_col];
    }
    Clear();
}

bool Canvas::DrawPixel(size_t y, size_t x, char brush) {
    if (y < m_row && x < m_col) {
        m_pixels[y][x] = brush;
        return true;
    }
    return false;
}

std::string Canvas::Print() const {
    std::ostringstream oss;
    oss << ' ';
    for (size_t i = 0; i < m_col; ++i) {
        oss << (i % 10);
    }
    oss << '\n';

    for (size_t i = 0; i < m_row; ++i) {
        oss << (i % 10);

        for (size_t j = 0; j < m_col; ++j) {
            char p = m_pixels[i][j] ? m_pixels[i][j] : '.';
            oss << p;
        }
        oss << '\n';
    }
    return oss.str();
}

void Canvas::Clear() {
    char* ptr = m_block;
    for (size_t i = 0; i < m_row * m_col; ++i) {
        *ptr++ = 0;
    }
}

Shape::Shape(size_t x, size_t y, char brush) : m_x(x), m_y(y), m_brush(brush) {
    // Do Nothing
}

size_t Shape::GetX() const {
    return m_x;
}

size_t Shape::GetY() const {
    return m_y;
}

char Shape::GetBrush() const {
    return m_brush;
}

Rectangle::Rectangle(size_t x, size_t y, size_t width, size_t height, char brush) :
    Shape(x, y, brush), m_width(width), m_height(height)
{
    // Do Nothing
}

std::string Rectangle::ShapeInfo() const {
    std::ostringstream oss;
    oss << "rect " << GetX() << ' ' 
                   << GetY() << ' ' 
                   << m_width << ' ' 
                   << m_height << ' ' 
                   << GetBrush();
    return oss.str();
}

void Rectangle::Draw(Canvas& canvas) const {
    size_t x = GetX();
    size_t y = GetY();
    char brush = GetBrush();

    for (size_t i = y; i < y + m_height; ++i) {
        for (size_t j = x; j < x + m_width; ++j) {
            canvas.DrawPixel(i, j, brush);
        }
    }
}

UpTriangle::UpTriangle(size_t x, size_t y, size_t height, char brush) :
    Shape(x, y, brush), m_height(height)
{
    // Do Nothing
}

std::string UpTriangle::ShapeInfo() const {
    std::ostringstream oss;
    oss << "tri_up " << GetX() << ' ' 
                     << GetY() << ' ' 
                     << m_height << ' ' 
                     << GetBrush();
    return oss.str();
}

void UpTriangle::Draw(Canvas& canvas) const {
    size_t x = GetX();
    size_t y = GetY();
    char brush = GetBrush();

    for (size_t i = 0; i < m_height; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            canvas.DrawPixel(y + i, x - j, brush);
            canvas.DrawPixel(y + i, x + j, brush);
        }
    }
}

DownTriangle::DownTriangle(size_t x, size_t y, size_t height, char brush) :
    Shape(x, y, brush), m_height(height)
{
    // Do Nothing
}

std::string DownTriangle::ShapeInfo() const {
    std::ostringstream oss;
    oss << "tri_down " << GetX() << ' ' 
                       << GetY() << ' ' 
                       << m_height << ' ' 
                       << GetBrush();
    return oss.str();
}

void DownTriangle::Draw(Canvas& canvas) const {
    size_t x = GetX();
    size_t y = GetY();
    char brush = GetBrush();

    for (size_t i = 0; i < m_height; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            canvas.DrawPixel(y - i, x - j, brush);
            canvas.DrawPixel(y - i, x + j, brush);
        }
    }
}

Diamond::Diamond(size_t x, size_t y, size_t dist, char brush) :
    Shape(x, y, brush), m_dist(dist)
{
    // Do Nothing
}

std::string Diamond::ShapeInfo() const {
    std::ostringstream oss;
    oss << "diamond " << GetX() << ' ' 
                      << GetY() << ' ' 
                      << m_dist << ' ' 
                      << GetBrush();
    return oss.str();
}

void Diamond::Draw(Canvas& canvas) const {
    size_t x = GetX();
    size_t y = GetY();
    char brush = GetBrush();

    for (size_t i = 0; i < m_dist; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            canvas.DrawPixel(y + i, x - j, brush);
            canvas.DrawPixel(y + i, x + j, brush);
        }
    }

    size_t base = y + 2 * m_dist;
    for (size_t i = 0; i <= m_dist; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            canvas.DrawPixel(base - i, x - j, brush);
            canvas.DrawPixel(base - i, x + j, brush);
        }
    }
}
