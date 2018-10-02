#include <iostream>
#include <string>

int add(int a, int b) {
    return a + b;
}

std::string add(std::string a, std::string b) {
    return a + '-' + b;
}

int main() {
    int num1, num2;
    std::string str1, str2;

    std::cin >> num1 >> num2;
    std::cin >> str1 >> str2;

    std::cout << add(num1, num2) << std::endl;
    std::cout << add(str1, str2) << std::endl;
}
