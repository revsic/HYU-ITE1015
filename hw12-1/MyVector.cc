#include "MyVector.h"
#include <iostream>

int main(){
	MyVector<int> myvec1;
	myvec1.push_back(0);
	std::cout << myvec1.size() << std::endl;//1
	std::cout << myvec1.max_size() << std::endl;//1
	
	
	int arr[] = {1, 2, 3, 4, 5};
	MyVector < int > myvec2(arr, 5);
	std::cout << myvec2.size() << std::endl;//5
	std::cout << myvec2.max_size() << std::endl;//5
	myvec2.push_back(5);
	std::cout << myvec2.size() << std::endl;//6
	std::cout << myvec2.max_size() << std::endl;//10
	
	for(int n = 0; n < myvec2.size(); n++)
		std::cout << myvec2[n] << " ";//1,2,3,4,5,5
	std::cout << std::endl;
	
	myvec2.back() = 6;
	for(int n = 0; n < myvec2.size(); n++)
		std::cout << myvec2.at(n) << " ";//1,2,3,4,5,6
	std::cout << std::endl;
	
	MyVector < int > myvec3 = myvec1 + myvec2;
	for(int n = 0; n < myvec3.size(); n++)
		std::cout << myvec3.at(n) << " ";//0,1,2,3,4,5,6
	std::cout << std::endl;

	return 1;
}