#ifndef INVALIDMONTH_H_
#define INVALIDMONTH_H_

#include <string>
using namespace std;
class invalidMonth {
public:
	 invalidMonth() {
		 message = "invalid month, please enter a day between 1 and 12 ";
	 }

	 string what() {
		 return message;
	 }


private:
	string message;
};


#endif // !INVALIDMONTH_H_
