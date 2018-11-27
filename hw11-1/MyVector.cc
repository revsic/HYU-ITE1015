#include "MyVector.h"

MyVector::MyVector() : size(0), ptr(nullptr) {
    // Do Nothing
}

MyVector::MyVector(size_t size) : size(size), ptr(new double[size]) {
    // Do Nothing
}

MyVector::~MyVector() {
    if (ptr != nullptr) {
        delete[] ptr;
    }
}

MyVector::MyVector(MyVector const& vec) : MyVector(vec.size)
{
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = vec.ptr[i];
    }
}

MyVector::MyVector(MyVector&& vec) : 
    size(vec.size), ptr(vec.ptr)
{
    vec.ptr = nullptr;
}

MyVector& MyVector::operator=(MyVector const& vec) {
    if (ptr != nullptr) {
        delete[] ptr;
    }

    size = vec.size;
    ptr = new double[size];

    for (size_t i = 0; i < size; ++i) {
        ptr[i] = vec.ptr[i];
    }

    return *this;
}

MyVector& MyVector::operator=(MyVector&& vec) {
    if (ptr != nullptr) {
        delete[] ptr;
    }

    size = vec.size;
    ptr = vec.ptr;
    vec.ptr = nullptr;

    return *this;
}

MyVector MyVector::operator+(MyVector const& other) const {
    size_t new_size = std::min(size, other.size);
    MyVector vec(new_size);
    for (size_t i = 0; i < new_size; ++i) {
        vec.ptr[i] = ptr[i] + other.ptr[i];
    }
    
    return vec;
}

MyVector MyVector::operator-(MyVector const& other) const {
    size_t new_size = std::min(size, other.size);
    MyVector vec(new_size);
    for (size_t i = 0; i < new_size; ++i) {
        vec.ptr[i] = ptr[i] - other.ptr[i];
    }
    return vec;
}

MyVector MyVector::operator+(double other) const {
    MyVector vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec.ptr[i] = ptr[i] + other;
    }
    return vec;
}

MyVector MyVector::operator-(double other) const {
    MyVector vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec.ptr[i] = ptr[i] - other;
    }
    return vec;
}

std::ostream& operator<<(std::ostream& out, MyVector const& other) {
    for (size_t i = 0; i < other.size; ++i) {
        out << other.ptr[i] << ' ';
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyVector& other) {
    for (size_t i = 0; i < other.size; ++i) {
        in >> other.ptr[i];
    }
    return in;
}
