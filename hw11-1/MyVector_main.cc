#include "MyVector.h"
#include <iostream>

template <typename T, typename U>
T operate(T const& vec1, U const& operand, char oper) {
    T vec;
    switch (oper) {
    case '+':
        vec = vec1 + operand;
        break;
    case '-':
        vec = vec1 - operand;
        break;
    default:
        break;
    }
    return vec;
}

MyVector& select(std::string const& given, MyVector& a, MyVector& b) {
    if (given == "a") {
        return a;
    }
    else if (given == "b") {
        return b;
    }
}

int noexcept_stoi(std::string const& str, bool& flag) {
    int n = -1;
    try {
        n = std::stoi(str);
        flag = true;
    } catch (std::invalid_argument&) {
        flag = false;
    }
    return n;
}

int main() {
    MyVector a, b;
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "quit") {
            break;
        }
        else if (given == "new") {
            int num;
            std::cin >> num;

            a = MyVector(num);
            b = MyVector(num);
            
            std::cout << "enter a" << std::endl;
            std::cin >> a;

            std::cout << "enter b" << std::endl;
            std::cin >> b;

            continue;
        }

        char oper;
        std::string other;
        std::cin >> oper >> other;

        if (given == "a" || given == "b") {
            MyVector& src = select(given, a, b);

            bool success_flag;
            int num = noexcept_stoi(other, success_flag);
            if (success_flag) {
                src = operate<MyVector, int>(src, num, oper);
                std::cout << src << std::endl;
            }
            else if (other == "a" || other == "b") {
                src = operate<MyVector, MyVector>(src, select(other, a, b), oper);
                std::cout << src << std::endl;
            }
        }
    }

    return 0;
}