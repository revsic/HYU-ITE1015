#include "print_info.h"
#include <iostream>
#include <vector>

void printObjectTypeInfo1(A* object) {
    std::cout << object->getTypeInfo() << std::endl;
}

void printObjectTypeInfo2(A& object) {
    std::cout << object.getTypeInfo() << std::endl;
}

int main() {
    std::vector<A*> vec = { new A(), new B(), new C() };
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        printObjectTypeInfo1(*iter);
        printObjectTypeInfo2(**iter);

        delete *iter;
    }
    return 0;
}