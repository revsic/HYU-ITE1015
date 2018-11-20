#include "dynamic_cast.h"
#include <iostream>

B::~B() {
    // Do Nothing
}

void C::test_C() {
    std::cout << "C::test_C()" << std::endl;
}

void D::test_D() {
    std::cout << "D::test_D()" << std::endl;
}