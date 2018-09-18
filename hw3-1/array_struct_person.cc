#include <iostream>

typedef struct {
    char name[11];
    int age;
} Person;

int main() {
    Person people[3] = { 0, };
    for (int i = 0; i < 3; ++i) {
        std::cin >> people[i].name >> people[i].age;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout
            << "Name: " << (people + i)->name
            << ", Age: " << (people + i)->age
            << std::endl; 
    }
}
