#include "class_function.h"
#include <iostream>

void A::test1() const {
    std::cout << "A::test1" << std::endl;
}

void B::test2() const {
    std::cout << "B::test2" << std::endl;
}

void C::test1() const {
    std::cout << "C::test1" << std::endl;
}

void C::test2() const {
    std::cout << "C::test2" << std::endl;
}

void BB::test1() const {
    std::cout << "BB::test1" << std::endl;
}