//============================================================================
// Name        : Lab5_Notes.cpp
// Author      : Ivan Temesvari
// Date        : 9/9/2020
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void process(string name){
	int count = 1;
	int frontNum = 1;

	int spaceLocation = name.find(' ');
	for(int i = 0; i < name.size(); i++){

		if(i == spaceLocation){

			std::cout << "\n";
			frontNum = 2;

		}
		else {

			cout << frontNum << setw(count + 1) << char(toupper(name[i])) << std::endl;
			frontNum+=2;
			count++;
		}
	}
}

int main() {

	cout << "Enter your name as \"First Last\"" << endl;
	string userName;
	getline(cin, userName, '\n');

	cout << "Your name: " << userName << endl;
	process(userName);
	int myNameLength = userName.size();

	cout << "The length of myName including the space is: " << myNameLength << endl;
	cout << "The first character in myName: " << userName[0] << endl;
	cout << "The last character in myName: " << userName[myNameLength-1] << endl;

	
	return 0;
}

