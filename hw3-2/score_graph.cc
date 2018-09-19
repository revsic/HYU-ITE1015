#include <iostream>

typedef struct {
    char name[7];
    int score;
} Person;

void printScoreStars(Person* persons, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << persons[i].name << ' ';
        for (int j = 0; j < persons[i].score / 5; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main() {
    Person people[3] = { 0, };
    for (int i = 0; i < 3; ++i) {
        std::cin >> people[i].name >> people[i].score;
    }
    printScoreStars(people, 3);
}
