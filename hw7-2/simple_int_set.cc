#include "simple_int_set.h"
#include <algorithm>
#include <iterator>

std::set<int> SetIntersection(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> intersect;
    for (int elem : set0) {
        auto iter = std::find(set1.begin(), set1.end(), elem);
        if (iter != set1.end()) {
            intersect.emplace(elem);
        }
    }
    return intersect;
}

std::set<int> SetUnion(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> union_;
    for (int elem : set0) {
        union_.emplace(elem);
    }
    for (int elem : set1) {
        union_.emplace(elem);
    }
    return union_;
}

std::set<int> SetDifference(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> difference(set0);
    for (int elem : set1) {
        auto iter = std::find(difference.begin(), difference.end(), elem);
        if (iter != difference.end()) {
            difference.erase(iter);
        }
    }
    
    return difference;
}

bool InputSet(std::istream& input_stream, std::set<int>& s) {
    std::set<int> backup(s);

    std::string given;
    input_stream >> given;

    if (given != "{") {
        return false;
    }

    while (true) {
        int num = 0;
        input_stream >> num;

        if (input_stream.fail()) {
            break;
        }
        s.emplace(num);
    }

    input_stream.clear();
    input_stream >> given;

    if (given != "}") {
        s = std::move(backup);
        return false;
    }

    return true;
}
