#include "simple_account.h"

#include <iostream>
#include <sstream>

int main() {
    Manager manager;
    auto no_account = [] {
        std::cout << "Account does not exist" << std::endl;
    };

    auto log = [](std::string&& msg, int result) {
        if (result == 0) {
            std::cout << "Success: ";
        }
        else if (result == 1){
            std::cout << "Failure: ";
        }
        std::cout << msg << std::endl;
    };

    while (true) {
        char job = '\0';
        std::cout << "Job?" << std::endl;
        std::cin >> job;

        switch (job) {
        case 'N': {
            int id = manager.GetSize();
            std::stringstream stream;
            stream << "Account for user " << id << " registered";

            log(stream.str(), manager.NewAccount());
            std::cout << manager[id].Log() << std::endl;
            break;
        }
        case 'D': {
            int idx = 0, money = 0;
            std::cin >> idx >> money;

            if (manager.GetSize() == 0) {
                no_account();
                continue;
            }

            std::stringstream stream;
            stream << "Deposit to user " << idx << ' ' << money;

            log(stream.str(), manager.Deposit(idx, money));
            std::cout << manager[idx].Log() << std::endl;
            break;
        }
        case 'W': {
            int idx = 0, money = 0;
            std::cin >> idx >> money;

            if (manager.GetSize() == 0) {
                no_account();
                continue;
            }

            std::stringstream stream;
            stream << "Withdraw from user " << idx << ' ' << money;

            log(stream.str(), manager.Withdraw(idx, money));
            std::cout << manager[idx].Log() << std::endl;
            break;
        }
        case 'T': {
            int src = 0, dst = 0, money = 0;
            std::cin >> src >> dst >> money;

            if (manager.GetSize() == 0) {
                no_account();
                continue;
            }

            std::stringstream stream;
            stream << "Transfer from user " << src << " to user " << dst << ' ' << money;
        
            log(stream.str(), manager.Transfer(src, dst, money));
            if (src > dst) {
                std::swap(src, dst);
            }
            std::cout << manager[src].Log() << std::endl;
            std::cout << manager[dst].Log() << std::endl;
            break;
        }
        case 'Q':
            return 0;
        }
    }

    return 0;
}