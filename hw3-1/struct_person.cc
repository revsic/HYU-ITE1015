#include <iostream>

typedef struct {
    char name[11];
    int age;
} Person;

int main() {
    Person person;
    std::cin >> person.name >> person.age;

    std::cout 
        << "name: " << person.name
        << "\nage: " << person.age
        << std::endl;
}
