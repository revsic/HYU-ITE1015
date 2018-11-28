#include "calendar.h"
#include <iostream>

int main() {
    Date date;
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "set") {
            try {
                std::cin >> date;
                std::cout << date << std::endl;
            } catch(InvalidDateException& exception) {
                std::cout << "Invalid date: " << exception.input_date << std::endl;
            }
        }
        else if (given == "next_day") {
            date.NextDay();
            std::cout << date << std::endl;
        }
        else if (given == "next") {
            int offset;
            std::cin >> offset;

            date.NextDay(offset);
            std::cout << date << std::endl;
        }
        else if (given == "quit") {
            break;
        }
    }

    return 0;
}