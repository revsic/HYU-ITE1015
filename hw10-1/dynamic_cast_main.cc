#include "dynamic_cast.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<B*> vec;
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "B") {
            vec.emplace_back(new B);
        }
        else if (given == "C") {
            vec.emplace_back(new C);
        }
        else if (given == "D") {
            vec.emplace_back(new D);
        }
        else if (given == "0") {
            break;
        }
    }

    for (auto elem : vec) {
        C* c = dynamic_cast<C*>(elem);
        if (c != nullptr) {
            c->test_C();
            continue;
        }
        
        D* d = dynamic_cast<D*>(elem);
        if (d != nullptr) {
            d->test_D();
        }
    }

    for (auto elem : vec) {
        delete elem;
    }
}