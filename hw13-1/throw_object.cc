#include <iostream>

int data_size = 5;
class A {
public:
    A() : data(new int[data_size]) {
        for (int i = 0; i < data_size; ++i) {
            data[i] = i;
        }
        std::cout << "constructed\n";
    }

    ~A() {
        for (int i = 0; i < data_size; ++i) {
            data[i] = 0;
        }
        delete[] data;

        data = nullptr;
        std::cout << "destroyed\n";
    }

    A(A const& other) : data(new int[data_size]) {
        for (int i = 0; i < data_size; ++i) {
            data[i] = other.data[i];
        }
    }

    friend std::ostream& operator<<(std::ostream& os, A const& a);

private:
    int* data;
};

std::ostream& operator<<(std::ostream& os, A const& a) {
    for (int i = 0; i < data_size; ++i) {
        os << a.data[i] << ' ';
    }
    return os;
}

int main() {
    try {
        A a;
        std::cout << a << std::endl;
        throw a;
    } catch (A& a) {
        std::cout << "err. handled\n";
        std::cout << a << std::endl;
    }

    return 1;
}