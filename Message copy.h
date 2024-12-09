#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "ccc_time copy.h"  // Include Time class
using namespace std;

class Message {
public:
    // Constructors
    Message();  // Default constructor
    Message(string s, string r);  // Constructor with sender and recipient
    Message(string s, string r, string m, const Time& t);  // Constructor with sender, recipient, message, and timestamp

    // Methods
    void append(string m);  // Append message content
    void print();  // Print message
    string to_string();  // Return message as string
    void setTime(const Time& t);  // Set timestamp

private:
    string sender;    // Sender of the message
    string recipient; // Recipient of the message
    string message;   // Message content
    Time stamp;       // Timestamp of the message
};

#endif  // MESSAGE_H
