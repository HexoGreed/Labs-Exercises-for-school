#include "Message copy.h"
#include <iostream>
using namespace std;

// Default constructor
Message::Message() {
    sender = "";
    recipient = "";
    message = "";
    stamp = Time();   //there is no time stamp yet.
}




// Constructor with sender and recipient
Message::Message(string s, string r) {
    sender = s;
    recipient = r;
    message = "";
    stamp = Time();   //set the time of this Message to the current time (now).
}




// Constructor with sender, recipient, message, and timestamp
Message::Message(string s, string r, string m, const Time& t) {
    sender = s;
    recipient = r;
    message = m;
    stamp = t;  // Copy timestamp
}





// Append a message to the current message content
void Message::append(string m) {
    message += m;
}




// Print the message
void Message::print() {
    cout << "From: " << sender << " To: " << recipient << endl;
    cout << "Message: " << message << endl;
    cout << "Sent at: " << stamp.to_string() << endl;
}



string Message::to_string() {
    string theMessage = "From: " + sender + "\n";
    theMessage += "To: " + recipient + "\n";
    theMessage += "Sent at: " + stamp.to_string() + "\n";//noticed time had a .toString
    theMessage += "Message:\n" + message;
    return theMessage;
}





void Message::setTime(const Time& t) {
    stamp = t;  // Copy the provided timestamp to the message
}
