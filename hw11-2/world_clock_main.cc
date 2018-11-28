#include "world_clock.h"

int main() {
    WorldClock clock;
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "set") {
            std::cin >> clock;

            if (clock.GetInputValidation()) {
                std::cout << clock << std::endl;
            }
        }
        else if (given == "tick") {
            int sec;
            std::cin >> sec;

            clock.Tick(sec);
            std::cout << clock << std::endl;
        }
        else if (given == "quit") {
            break;
        }
    }
}