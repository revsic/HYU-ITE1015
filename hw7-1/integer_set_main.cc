#include "integer_set.h"
#include <iostream>

int main() {
    IntegerSet int_set;
    
    auto log = [&] {
        for (int i : int_set.GetAll()) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    };

    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "add") {
            int num = 0;
            std::cin >> num;
        
            int_set.AddNumber(num);
            log();
        }
        else if (given == "del") {
            int num = 0;
            std::cin >> num;
            
            int_set.DeleteNumber(num);
            log();
        }
        else if (given == "get") {
            int pos = 0;
            std::cin >> pos;
            std::cout << int_set.GetItem(pos) << std::endl;
        }
        else {
            break;
        }
    }

    return 0;
}
