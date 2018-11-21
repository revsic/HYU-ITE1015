#include "clock_time.h"
#include <iostream>
#include <vector>

using ull = unsigned long long;

int main() {
    std::vector<Clock*> vec = {
        new SundialClock(0, 0, 0),
        new CuckooClock(0, 0, 0),
        new GrandFatherClock(0, 0, 0),
        new WristClock(0, 0, 0),
        new AtomicClock(0, 0, 0)
    };

    ull seconds;
    std::cin >> seconds;

    std::cout << "Reported clock times after resetting:" << std::endl;
    for (auto elem : vec) {
        elem->reset();
        elem->displayTime();
    }

    std::cout << "\nRunning the clocks..." << std::endl;
    for (size_t i = 0; i < seconds; ++i) {
        for (auto elem : vec) {
            elem->tick();
        }
    }

    std::cout << "\nReported clock times after running:" << std::endl;
    for (auto elem : vec) {
        elem->displayTime();
        delete elem;
    }

    return 0;
}
