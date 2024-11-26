#pragma once
#ifndef INVALIDYEAR_H_
#define INVALIDYEAR_H_
#include <string>
using namespace std;
class invalidYear {
public:
	invalidYear() {
		message = "invalid Year, please enter a valid year";
	}

	string what() {
		return message;
	}


private:
	string message = "";
};

#endif