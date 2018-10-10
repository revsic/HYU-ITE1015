#include <iostream>

void swapInt(int& n1, int& n2) {
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void swapString(std::string& s1, std::string& s2) {
    std::string tmp = std::move(s1);
    s1 = std::move(s2);
    s2 = std::move(tmp);
}

int main() {
    int n1, n2;
    std::string str1, str2;

    std::cin >> n1 >> n2;
    std::cin >> str1 >> str2;

    auto print = [&] {
        std::cout 
            << "n1: " << n1 
            << ", n2: " << n2 
            << ", s1: " << str1 
            << ", s2: " << str2 
            << std::endl;
    };

    print();

    swapInt(n1, n2);
    swapString(str1, str2);

    print();

    return 0;
}
