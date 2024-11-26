#ifndef INVALIDDAY_H_
#define INVALIDDAY_H_
#include <string>
using namespace std;
class invalidDay {
public: 
	 invalidDay() {
		 message = "invalid Day, please enter a day between 1 and 31 ";

	 }

	 string what() {
		 return message;
	 }


private:
	string message;
};


#endif