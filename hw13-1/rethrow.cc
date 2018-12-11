#include <iostream>

struct A {
    static int global;
    int id;

    A() : id(global++) {
        std::cout << "Constructed "  << id << std::endl;
    }

    ~A() {
        std::cout << "Destructed " << id << std::endl;
    }

    A(A const&) : id(global++) {
        std::cout << "Copy Ctor " << id << std::endl;
    }
};
int A::global = 0;

int main() {
    try {
        try {
            A a;
            throw a;
        } catch (A& a) {
            #if 1
            std::cout << "rethrow" << std::endl;
            throw;
            #else 
            std::cout << "throw twice" << std::endl;
            throw a;
            #endif
        }
    } catch (A& a) {
        std::cout << "Exception handled" << std::endl;
    }
}