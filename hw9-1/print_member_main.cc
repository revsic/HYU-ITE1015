#include "print_member.h"
#include <iostream>
#include <vector>

int main() {
    int n;
    double real;
    std::string str;

    std::cin >> n >> real >> str;
    std::vector<A*> vec = { new A(n), new B(real), new C(std::move(str)) };

    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        (*iter)->print();
    }

    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        delete *iter;
    }

    return 0;
}