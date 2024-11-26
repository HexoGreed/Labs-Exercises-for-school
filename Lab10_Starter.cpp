/*
 * Lab10_Starter.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: Ivan
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "invalidDay.h"
#include "invalidMonth.h"
#include "invalidYear.h"
using namespace std;
string convertDate(string dateOfBirth, vector<int>& years){
	string convertedDate = "";
	string monthString, dayString, yearString;


	string date = "12-1-1999";



	int first_dash = dateOfBirth.find('-');
	int second_dash = dateOfBirth.find('-', first_dash + 1);

	if (first_dash == string::npos || second_dash == string::npos) {
		return "Invalid date format. Please use MM-DD-YYYY.";
	}

	string month = dateOfBirth.substr(0, first_dash);
	string day = dateOfBirth.substr(first_dash + 1, second_dash - (first_dash + 1));
	string year = dateOfBirth.substr(second_dash + 1);

	

	try {
		// Check for valid year
		int yearValue = stoi(year);
		if (yearValue < 0 || yearValue > 2024) {
			throw invalidYear();
		}

		// Check for valid month input
		int monthValue = stoi(month);
		if (monthValue < 1 || monthValue > 12) {
			throw invalidMonth();
		}

		// Check for valid day input
		int dayValue = stoi(day);
		if (dayValue < 1 || dayValue > 31) {
			throw invalidDay();
		}


		//pushing year into vector
		years.push_back(yearValue);

		// Find the appropriate month as a word
		const string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		if (monthValue < 1 || monthValue > 12) {
			throw invalidMonth();
		}
		monthString = months[monthValue - 1]; //month becomes 0 in the array

		


		// Find the appropriate suffix for the day
		string daySuffix;
		if (dayValue == 1 || dayValue == 21 || dayValue == 31) {
			daySuffix = "st";
		}
		else if (dayValue == 2 || dayValue == 22) {
			daySuffix = "nd";
		}
		else if (dayValue == 3 || dayValue == 23) {
			daySuffix = "rd";
		}
		else {
			daySuffix = "th";
		}


		convertedDate += monthString + " " + dayString + daySuffix + ", " + yearString;





	}
	catch(invalidDay& iD){
		return iD.what();
	}
	catch(invalidMonth& iM){
		return iM.what();
	}
	catch(invalidYear& iY){
		return iY.what();
	}

	return convertedDate;

}

int main() {
	vector<int> years;
	string dob;
	//Loop 10 times here.
	int validEntries = 0;
	cout << "Please enter your date of birth in the form (month-day-year), e.g. 8-27-2020" << endl;
	while (validEntries < 10) {
		cin >> dob;
		//cout << "Your birth date is: " << convertDate(dob, years) << endl;

		string output = convertDate(dob, years);

		if (output.substr(0, 7) == "Invalid") {
			cout << "User entered an invalid birth data. Input not stored. " << endl;
		}
		else {
			cout << output << endl;
			validEntries++;
		}
		//End the loop here.
	}
	//Use the std sort function which gives ascending order by default.
	std::sort(years.begin(), years.end());

	//Display the sorted vector of years.
	for(unsigned int i = 0; i < years.size(); i++){
		cout << years[i] << " ";
	}
	//range based loop to itterate through the vector years
	cout << "\nsorted Years: \n" << endl;
	for (int year : years) {
		cout << year << " ";
	}
	return 0;
}


