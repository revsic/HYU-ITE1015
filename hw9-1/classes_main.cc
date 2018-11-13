#include "classes.h"
#include <vector>

int main() {
    std::vector<A*> vec = { new A(), new B(), new C() };
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        (*iter)->test();
        delete *iter;
    }

    return 0;
}