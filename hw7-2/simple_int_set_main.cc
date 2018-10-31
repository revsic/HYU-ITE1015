#include "simple_int_set.h"
#include <iostream>
#include <map>
#include <sstream>


void log_set(const std::set<int>& int_set) {
    std::cout << "{ ";
    for (int i : int_set) {
        std::cout << i << ' ';
    }
    std::cout << '}' << std::endl;
}

std::set<int> input_set(std::istream& input_stream) {
    std::string given;
    input_stream >> given;
    
    std::set<int> int_set;
    while (true) {
        int num = 0;
        input_stream >> num;

        if (input_stream.fail()) {
            break;
        }
        int_set.emplace(num);
    }

    input_stream.clear();
    input_stream >> given;

    return int_set;
}

using SetOper = std::set<int>(*)(const std::set<int>&, const std::set<int>&);

int main() {
    const std::map<char, SetOper> opers = {
        { '+', SetUnion },
        { '*', SetIntersection },
        { '-', SetDifference },
    };

    while (true) {
        std::string given;
        std::getline(std::cin, given);

        if (given == "0") {
            break;
        }

        std::stringstream sstream(given);
        std::set<int> set1 = input_set(sstream);

        char oper = '\0';
        sstream >> oper;
        std::set<int> set2 = input_set(sstream);
      
        auto iter = opers.find(oper);
        if (iter != opers.end()) {
            std::set<int> result = std::get<1>(*iter)(set1, set2);
            log_set(result);
        }
    }

    return 0;
}
