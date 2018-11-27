#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

class MyVector {
public:
    MyVector();
    MyVector(size_t size);

    ~MyVector();

    MyVector(MyVector const& vec);
    MyVector(MyVector&& vec);

    MyVector& operator=(MyVector const& vec);
    MyVector& operator=(MyVector&& vec);

    MyVector operator+(MyVector const& other) const;
    MyVector operator-(MyVector const& other) const;
    MyVector operator+(double other) const;
    MyVector operator-(double other) const;

    friend std::ostream& operator<<(std::ostream& out, MyVector const& vec);
    friend std::istream& operator>>(std::istream& in, MyVector& vec);

private:
    size_t size;
    double* ptr;
};

#endif