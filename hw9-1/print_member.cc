#include "print_member.h"
#include <iostream>

A::A(int n) : memberA(new int(n)) {
    std::cout << "new memberA" << std::endl;
}

A::~A() {
    if (memberA != nullptr) {
        delete memberA;
    }
    std::cout << "delete memberA" << std::endl;
}

void A::print() const {
    std::cout << "*memberA " << *memberA << std::endl;
}

B::B(double n) : A(1), memberB(new double(n)) {
    std::cout << "new memberB" << std::endl;
}

B::~B() {
    if (memberB != nullptr) {
        delete memberB;
    }
    std::cout << "delete memberB" << std::endl;
}

void B::print() const {
    A::print();
    std::cout << "*memberB " << *memberB << std::endl;
}

C::C(std::string&& str) : B(1.1), memberC(new std::string(std::move(str))) {
    std::cout << "new memberC" << std::endl;
}

C::~C() {
    if (memberC != nullptr) {
        delete memberC;
    }
    std::cout << "delete memberC" << std::endl;
}

void C::print() const {
    B::print();
    std::cout << "*memberC " << *memberC << std::endl;
}