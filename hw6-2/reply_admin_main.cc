#include "reply_admin.h"

#include <iostream>
#include <regex>
#include <string>

bool remove(ReplyAdmin& admin, const std::string& input) {
    std::smatch match;
    std::regex multi_remove("#remove\\s*([0-9]+)-([0-9]+)");
    if (std::regex_search(input, match, multi_remove) && match.size() >= 3) {
        int start = std::stoi(match.str(1));
        int end = std::stoi(match.str(2));

        return admin.removeChat(start, end);
    }
    
    std::regex neg_multi("#remove\\s*-([0-9]+)-([0-9]+)");
    if (std::regex_search(input, match, neg_multi) && match.size() >= 3) {
        int start = -std::stoi(match.str(1));
        int end = std::stoi(match.str(2));

        return admin.removeChat(start, end);
    }

    std::regex remove("#remove\\s*([0-9]+)");
    if (std::regex_search(input, match, remove) && match.size() >= 2) {
        int index = std::stoi(match.str(1));
        return admin.removeChat(index);
    }
    return false;
}

int main() {
    ReplyAdmin admin;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        if (input == "#quit") {
            break;
        }
        else if (input.find("#remove") != std::string::npos) {
            if(remove(admin, input)) {
                admin.log();
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
