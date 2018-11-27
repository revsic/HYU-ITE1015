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



int main() {
    MyVector a, b;
    while (true) {
        std::string given;
        std::cin >> given;

        if (given == "new") {
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
        else if (given == "quit") {
            break;
        }

        char oper;
        std::string other;
        std::cin >> oper >> other;

        if (given == "a") {
            try {
                int i = std::stoi(other);
                a = operate<MyVector, int>(a, i, oper);
                    std::cout << a << std::endl;
            } catch (...) {
                if (other == "a") {
                    a = operate<MyVector, MyVector>(a, a, oper);
                    std::cout << a << std::endl;
                }
                else if (other == "b") {
                    a = operate<MyVector, MyVector>(a, b, oper);
                    std::cout << a << std::endl;
                }
            }
        }
        else if (given == "b") {
            try {
                int i = std::stoi(other);
                b = operate<MyVector, int>(b, i, oper);
                    std::cout << b << std::endl;
            } catch(...) {
                if (other == "a") {
                    b = operate<MyVector, MyVector>(b, a, oper);
                    std::cout << b << std::endl;
                }
                else if (other == "b") {
                    b = operate<MyVector, MyVector>(b, b, oper);
                    std::cout << b << std::endl;
                }
            }
        }
    }

    return 0;
}