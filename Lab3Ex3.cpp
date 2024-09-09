
#include <iostream>
#include <fstream>


int main() {
	std::ifstream file("years.txt");  //declaring the opening file
	std::ofstream output("output.txt"); //declaring the output file


	while (file.is_open() && output.is_open()) {
		int year; //had to put this in sope of this if bc if i didnt it'd be asking for it


		while (file >> year) {
			//google told me that this reads everything other than strings if we use >>, might be the same way its used for cout
			
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0)) {
				output << year << " , This is a leap year" << "\n";
				std::cout << year << " , This is a leap year" << "\n";
			}
			else {
				output <<year <<", Tihs is not a leap year" << std::endl;
				std::cout << year << " , Tihs is not a leap year" << "\n";

			}
		}
		file.close();
		output.close();
		//closes both fiiiles
	}


	return 0;




	//
}
