#include <iostream>

int main() {
    double arr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double *parr = arr;

    for (int i = 0; i < 5; ++i) {
        parr[i] *= 2;
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << *parr << std::endl;
	++parr;		
    }

   return 0;
}
