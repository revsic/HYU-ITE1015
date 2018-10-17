#include "minimal_fighter.h"

#include <iostream>
#include <sstream>

std::string Log(const MinimalFighter& fighter) {
    if (fighter.status() == FighterStatus::Alive) {
        std::stringstream stream;
        stream << 'H' << fighter.hp() << ", P" << fighter.power();
        return stream.str();
    }
    else {
        return "DEAD";
    }
}

int main() {
    while (true) {
        char action;
        int hp1, hp2;
        int power1, power2;

        std::string input;
        std::getline(std::cin, input);

        std::stringstream stream;
        stream << input;
        stream >> hp1 >> power1 >> action >> hp2 >> power2;

        if (stream.fail()) {
            break;
        }

        MinimalFighter fighter1(hp1, power1);
        MinimalFighter fighter2(hp2, power2);

        switch (action) {
        case 'H':
            fighter1.hit(&fighter2);
            break;
        case 'A':
            fighter1.attack(&fighter2);
            break;
        case 'F':
            fighter1.fight(&fighter2);
            break;
        default:
            return 0;
        }

        std::cout << Log(fighter1) << " / " << Log(fighter2) << std::endl;
    }
}
