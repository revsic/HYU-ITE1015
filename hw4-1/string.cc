#include <iostream>
#include <string>

int main() {
    std::string str1, str2;
    
    std::cin >> str1 >> str2;
    std::cout << str1 + str2 << std::endl;
    std::cout << str1[0] << std::endl;
    std::cout << str2.back() << std::endl;
}
