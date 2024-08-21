#include <iostream>
#include<cmath>
int main() {
	
	/*
	This file contains both the lab1 & exercise 1;
	*/


	int sum = 0;
	std::cout << "Lab1" << std::endl;
	for (int i = 0; i <=10; i++) {
		sum+=i;
		std::cout << sum << "\n";
	}

	int multiply = 10;
	int64_t sumof10s = 1;
	
	std::cout << "\n\n\n\n\n";
	std::cout << "Exercise_1" << std::endl;

	for (int i = 0; i <= 5; i++) {
		sumof10s *= pow(10, i);
		std::cout << sumof10s << std::endl;

	}


	return 0;
}