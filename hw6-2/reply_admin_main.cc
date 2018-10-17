#include "reply_admin.h"

#include <iostream>
#include <regex>
#include <string>

int main() {
    ReplyAdmin admin;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        if (input == "#quit") {
            break;
        }
        else if (input.find("#remove") != std::string::npos) {
            std::smatch match;
            std::regex multi_remove("#remove\\s*([0-9]+)-([0-9]+)");
            if (std::regex_search(input, match, multi_remove) && match.size() >= 3) {
                int start = std::stoi(match.str(1));
                int end = std::stoi(match.str(2));

                if (admin.removeChat(start, end)) {
                    admin.log();
                }
                continue;
            }

            std::regex remove("#remove\\s*([0-9]+)");
            if (std::regex_search(input, match, remove) && match.size() >= 2) {
                int index = std::stoi(match.str(1));
                
                if (admin.removeChat(index)) {
                    admin.log();
                }
            }
        }
        else {
            if (admin.addChat(input)) {
                admin.log();
            }
        }
    }

    return 0;
}
