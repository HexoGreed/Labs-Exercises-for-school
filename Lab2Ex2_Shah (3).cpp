#include <iostream>
#include <string>


int main() {
	std::string name;
	int age;
	std::cout << "Lab1 \n\n\n";
	std::cout << "Hello! can you please give me your name\n";
	std::cin >> name;
	std::cout << "\n" << name << " can you please give me your age\n";
	std::cin >> age;

	//This is all cout
	std::cout <<"\n" << name << " You are aproximatley " << age * 365
		<< " Days old. \nIn minutes you are " << age * 525600 << " minutes old. \nIn seconds you are "
		<< age * 31536000
		<< " seconds old";
	//end of cout

	return 0;
}