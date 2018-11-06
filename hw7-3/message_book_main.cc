#include "message_book.h"
#include <iostream>

int main() {
    MessageBook msg_book;

    while (true) {
        std::string input;
        std::cin >> input;

        if (input == "add") {
            int number = 0;
            std::cin >> number;
            std::getline(std::cin, input);
            
            if (input != "" && input[0] == ' ') {
                input.erase(input.begin());
            }
            msg_book.AddMessage(number, input);
        }
        else if (input == "delete") {
            int number = 0;
            std::cin >> number;
            msg_book.DeleteMessage(number);
        }
        else if (input == "print") {
            int number = 0;
            std::cin >> number;
            std::cout << msg_book.GetMessage(number) << std::endl;
        }
        else if (input == "list") {
            for (int num : msg_book.GetNumbers()) {
                std::cout << num << ": " << msg_book.GetMessage(num) << std::endl;
            }
        }
        else if (input == "quit") {
            break;
        }
    }
    return 0;
}
