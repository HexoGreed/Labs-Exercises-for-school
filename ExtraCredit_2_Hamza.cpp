#include <iostream>

int main() {
	int userInput;

	int onesPlace;
	int twosPlace=0;
	int threesplace=0;
	std::cout << "Extra Credit Lab2 EX2 \n\n\n\n\n";
	std::cout << "enter a three digit int \n";
	std::cin >> userInput;
	//this divides the number so i can just get the one
	onesPlace = userInput / 100;

	/*
	this gets the twos by dividing the users input by 10 so in the case of 123 it becomes 12.3then we mod 10. it becomes 2.3 in wich case the .3 is removed bc its an int
	*/
	twosPlace = (userInput / 10)%10;
	//if we mod the users input and it is indeed a three digit # then we just gets the one place because for modulo if the remainder isnt 0 and its smaller than the right side of the mod the left side is returned
	threesplace = userInput%10;


	//std::cout << onesPlace <<   << twosPlace <<  << threesplace;
	//ignore this ^^^^  its just to see if i was getting the numbers right

	std::cout << "\n" << onesPlace << twosPlace << threesplace << "\n";
	std::cout << onesPlace << threesplace <<twosPlace << "\n";
	std::cout << twosPlace <<onesPlace <<threesplace << "\n";
	std::cout << twosPlace <<threesplace <<onesPlace << "\n";
	std::cout << threesplace <<onesPlace <<twosPlace << "\n";
	std::cout << threesplace << twosPlace << onesPlace << std::endl;



	return 0;
}