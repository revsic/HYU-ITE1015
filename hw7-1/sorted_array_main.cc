#include "sorted_array.h"
#include <iostream>
#include <sstream>

int main() {
    std::string given;
    SortedArray sorted_array;

    while (true) {
        std::cin >> given;
        if (given == "ascend") {
            for (int i : sorted_array.GetSortedAscending()) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
        else if (given == "descend") {
            for (int i : sorted_array.GetSortedDescending()) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
        else if (given == "max") {
            std::cout << sorted_array.GetMax() << std::endl;
        }
        else if (given == "min") {
            std::cout << sorted_array.GetMin() << std::endl;
        }
        else if (given == "quit") {
            break;
        }
        else {
            std::stringstream sstream(given);
            
            int num = 0;
            sstream >> num;
            sorted_array.AddNumber(num);
        }
    }
    return 0;
}
