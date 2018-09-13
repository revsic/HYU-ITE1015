#include <iostream>

void rotateLeft(int* pa, int* pb, int* pc) {
    int tmp = *pa;
    *pa = *pb;
    *pb = *pc;
    *pc = tmp;
}

void rotateRight(int* pa, int* pb, int* pc) {
    int tmp = *pc;
    *pc = *pb;
    *pb = *pa;
    *pa = tmp;
}

int main() {
    int a = 10, b = 20, c = 30;
    std::cout << a << ':' << b << ':' << c << std::endl;

    while (true) {
        int input = -1;
        scanf("%d", &input);

        if (input == 1) {
            rotateLeft(&a, &b, &c);
        }
        else if (input == 2) {
            rotateRight(&a, &b, &c);
        }
        else {
            break;
        }

        std::cout << a << ':' << b << ':' << c << std::endl;
    }
}
