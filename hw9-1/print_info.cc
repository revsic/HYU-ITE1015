#include "print_info.h"

std::string A::getTypeInfo() const {
    return { "This is an instance of class A" };
}

std::string B::getTypeInfo() const {
    return { "This is an instance of class B" };
}

std::string C::getTypeInfo() const {
    return { "This is an instance of class C" };
}