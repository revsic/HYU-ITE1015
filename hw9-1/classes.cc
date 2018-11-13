#include "classes.h"
#include <iostream>

void A::test() const {
    std::cout << "A::test()" << std::endl;
}

void B::test() const {
    std::cout << "B::test()" << std::endl;
}

void C::test() const {
    std::cout << "C::test()" << std::endl;
}