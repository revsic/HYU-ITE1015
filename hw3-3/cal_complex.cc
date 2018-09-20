#include <iostream>

typedef struct {
    double real;
    double img;
} Complex;

void printComplex(const Complex& comp) {
    std::cout << comp.real << " + " << comp.img << 'i' << std::endl;
}

void printAddComp(const Complex& comp1, const Complex& comp2) {
    Complex add = { 0, };
    add.real = comp1.real + comp2.real;
    add.img = comp1.img + comp2.img;

    printComplex(add);
}

void printMulComp(const Complex& comp1, const Complex& comp2) {
    Complex mul = { 0, };
    mul.real = comp1.real * comp2.real - comp1.img * comp2.img;
    mul.img = comp1.real * comp2.img + comp1.img * comp2.real;
    
    printComplex(mul);
}

int main() {
    Complex comp[2] = { 0, };
    for (int i = 0; i < 2; ++i) {
        std::cin >> comp[i].real >> comp[i].img;
    }

    for (int i = 0; i < 2; ++i) {
        std::cout << "Complex " << i + 1 << std::endl;
        printComplex(comp[i]);
    }

    std::cout << "Sum" << std::endl;
    printAddComp(comp[0], comp[1]);

    std::cout << "Mul" << std::endl;
    printMulComp(comp[0], comp[1]);
}
