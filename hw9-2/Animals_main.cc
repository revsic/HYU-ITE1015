#include "Animals.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Animal*> vec;

    while (true) {
        char opt;
        std::cin >> opt;

        if (opt == '0') {
            break;
        }
        else if (opt == 'z') {
            std::string name;
            int age, num_stripes;

            std::cin >> name >> age >> num_stripes;
            vec.emplace_back(new Zebra(std::move(name), age, num_stripes));
        }
        else if (opt == 'c') {
            std::string name, toy;
            int age;

            std::cin >> name >> age >> toy;
            vec.emplace_back(new Cat(std::move(name), age, std::move(toy)));
        }
    }

    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        (*iter)->printInfo();
        delete *iter;
    }
    return 0;
}