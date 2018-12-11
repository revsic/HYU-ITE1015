#include <iostream>

//#define CTOR_EXCEPTION
#define DTOR_EXCEPTION

struct ctor_exception {};
struct dtor_exception {};

struct A {
    static int global;
    int id;

    A() : id(global++) {
        std::cout << "ctor " << id << std::endl;

        #ifdef CTOR_EXCEPTION
        throw ctor_exception();
        #endif
    }

    ~A() {
        --global;
        std::cout << "dtor " << id << std::endl;

        #ifdef DTOR_EXCEPTION
        throw dtor_exception();
        #endif
    }

    A(A const&) : id(global++) {
        std::cout << "copy ctor " << id << std::endl;

        #ifdef CTOR_EXCEPTION
        throw ctor_exception();
        #endif
    }
};
int A::global = 0;

int main() {
    try {
        A a;
        throw 0;
    } catch (int) {
        std::cout << "thrown" << std::endl;
    } catch (ctor_exception&) {
        std::cout << "ctor exception occured" << std::endl;
    } catch (dtor_exception&) {
        std::cout << "dtor exception occured" << std::endl;
    }

    return 0;
}