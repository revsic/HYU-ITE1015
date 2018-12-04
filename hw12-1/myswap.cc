#include <iostream>

template <typename T>
void myswap(T& a, T& b) {
    std::swap(a, b);
}

int main() {
    int a = 3, b = 1;	
	myswap(a, b);
	std::cout << "a= " << a << " b= " << b << std::endl;//1, 3
	
	float c = 3.1f, d = 1.5f;	
	myswap(c, d);
	std::cout << "c= " << c << " d= " << d << std::endl;//1.5, 3.1
	
	return 1;
}