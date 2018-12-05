#include "linked_list.h"
#include <iostream>

int main() {
    int array[5] = { 12, 7, 9, 21, 13 };
    List<int> li(array, 5);
    std::cout << li << std::endl;

    li.pop_back();
    std::cout << li << std::endl;

    li.push_back(15);
    std::cout << li << std::endl;

    li.pop_front();
    std::cout << li << std::endl;

    li.push_front(8);
    std::cout << li << std::endl;

    li.insert_at(4, 19);
    std::cout << li << std::endl;

    li.remove_at(1);
    std::cout << li << std::endl;

    return 0;
}