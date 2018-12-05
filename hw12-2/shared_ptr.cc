#include "shared_ptr.h"
#include <iostream>

int main() {
    {
        My_shared_ptr<int> a;
        std::cout << a.getCount() << std::endl;
        {
            My_shared_ptr<int> b(new int(5));
            std::cout << a.getCount() << std::endl;
            std::cout << b.getCount() << std::endl;

            if (a.get_m_obj() == b.get_m_obj()) {
                std::cout << "resource shared" << std::endl;
            }

            a = b;
            std::cout << a.getCount() << std::endl;
            std::cout << b.getCount() << std::endl;

            if (a.get_m_obj() == b.get_m_obj()) {
                std::cout << "resource shared" << std::endl;
            }
        }
        std::cout << a.getCount() << std::endl;
    }
    return 1;
}