#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    int num = 0;
    std::cin >> num;

    Person* people = new Person[num];

    for (int i = 0; i < num; ++i) {
        std::cin >> people[i].name;
        std::cin >> people[i].age;
    }

    for (int i = 0; i < num; ++i) {
        std::cout << "Name: " << people[i].name 
                  << ", Age: " << people[i].age 
                  << std::endl;
    }

    delete[] people;
}
