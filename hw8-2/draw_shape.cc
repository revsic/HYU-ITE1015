#include "draw_shape.h"
#include <cmath>
#include <iomanip>
#include <sstream>

size_t Canvas::m_width = 0;
size_t Canvas::m_height = 0;

Canvas::Canvas() {
    if (m_width == 0 || m_height == 0) {
        throw std::invalid_argument("width and height must bigger than 0");
    }

    m_pool = new bool[m_width * m_height];
    for (size_t i = 0; i < m_width * m_height; ++i) {
        m_pool[i] = false;
    }

    m_canv = new bool*[m_height];
    for (size_t i = 0; i < m_height; ++i) {
        m_canv[i] = &m_pool[i * m_width];
    }
}

Canvas::~Canvas() {
    if (m_pool != nullptr) {
        delete[] m_pool;
    }
    if (m_canv != nullptr) {
        delete[] m_canv;
    }
}

bool Canvas::fill(size_t row, size_t col) {
    if (row < m_height && col < m_width) {
        m_canv[row][col] = true;
        return true;
    }
    return false;
}

std::string Canvas::Draw(char brush) const {
    std::ostringstream oss;

    int plc_width = std::log10(m_width - 1) + 1;
    int plc_height = std::log10(m_height - 1) + 1;

    oss << std::setw(plc_height) << ' ';
    for (size_t i = 0; i < m_width; ++i) {
        oss << std::setw(plc_width) << i;
    }
    oss << '\n';

    for (size_t i = 0; i < m_height; ++i) {
        oss << std::setw(plc_height) << i;

        for (size_t j = 0; j < m_width; ++j) {
            char p = m_canv[i][j] ? brush : '.';
            oss << std::setw(plc_width) << p;
        }
        oss << '\n';
    }
    return oss.str();
}

void Canvas::SetCanvas(size_t width, size_t height) {
    m_width = width;
    m_height = height;
}

Rectangle::Rectangle(int width, int height) : m_width(width), m_height(height) {
    // Do Nothing
}

double Rectangle::GetArea() const {
    return m_width * m_height;
}

int Rectangle::GetPerimeter() const {
    return 2 * (m_width + m_height);
}

Canvas Rectangle::Draw(size_t pos_x, size_t pos_y) const {
    Canvas canvas;
    for (size_t i = pos_y; i < pos_y + m_height; ++i) {
        for (size_t j = pos_x; j < pos_x + m_width; ++j) {
            if (!canvas.fill(i , j)) {
                break;
            }
        }
    }
    return canvas;
}

Square::Square(int size) : m_size(size) {
    // Do Nothing
}

double Square::GetArea() const {
    return m_size * m_size;
}

int Square::GetPerimeter() const {
    return 4 * m_size;
}

Canvas Square::Draw(size_t pos_x, size_t pos_y) const {
    Canvas canvas;
    for (size_t i = pos_y; i < pos_y + m_size; ++i) {
        for (size_t j = pos_x; j < pos_x + m_size; ++j) {
            if (!canvas.fill(i , j)) {
                break;
            }
        }
    }
    return canvas;
}

Diamond::Diamond(int dist) : m_dist(dist) {
    // Do Nothing
}

double Diamond::GetArea() const {
    auto square = [](int a) { return a * a; };
    return square(m_dist * 2 + 1) / 2;
}

int Diamond::GetPerimeter() const {
    return m_dist * 8;
}

Canvas Diamond::Draw(size_t pos_x, size_t pos_y) const {
    Canvas canvas;

    for (size_t i = 0; i < m_dist; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            canvas.fill(pos_y + i, pos_x + j);
            canvas.fill(pos_y + i, pos_x - j);
        }
    }

    size_t base = 2 * m_dist + pos_y;
    for (int i = m_dist; i >= 0; --i) {
        for (size_t j = 0; j <= i; ++j) {
            canvas.fill(base - i, pos_x + j);
            canvas.fill(base - i, pos_x - j);
        }
    }
    
    return canvas;
}