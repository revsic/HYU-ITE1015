#include <iostream>

class A {
public:
    A(int n) : n_id(n), data(nullptr) {
        if (n_id <= 0) {
            throw std::bad_alloc();
        }

        std::cout << "ID=" << n << ": constructed\n";
        data = new int[n_id];
    }

    ~A() {
        std::cout << "ID=" << n_id << ": destroyed\n";
        if (data != nullptr) {
            delete[] data;
        }
    }

private:
    int n_id;
    int* data;
};

int main() {
    try {
        A a(3);
        A b(2);
        {
            A c(1);
            A d(0);
            A e(-1);
        }
    } catch (std::bad_alloc&) {
        std::cout << "caught in the main" << std::endl;
    }

    return 0;
}