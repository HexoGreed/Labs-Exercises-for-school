#ifndef MAILBOX_H_
#define MAILBOX_H_

#include "Message copy.h"
#include <vector>
#include <iostream>
using namespace std;

class Mailbox {
public:
    Mailbox();   // Default constructor


    void add_message(Message m); // Adds a message to the mailbox
    Message get_message(int i) const; // Gets the message at index i
    void remove_message(int i); // Removes the message at index i
    void print(); // Prints all messages in the mailbox

private:
    int messageCount; // Keeps track of the number of messages in the inbox
    vector<Message> inbox; // Vector to store messages
};

// Default constructor
Mailbox::Mailbox() {
    messageCount = 0;
}

// Adds a message to the mailbox
void Mailbox::add_message(Message m) {
    inbox.push_back(m);
    messageCount++;
}

// Gets the message at index i
Message Mailbox::get_message(int i) const {
    return inbox[i];
}

// Removes the message at index i
void Mailbox::remove_message(int i) {
    if (i >= 0 && i < messageCount) {
        inbox.erase(inbox.begin() + i); // Remove I
        messageCount--;
    }
}

// Prints all the messages in the mailbox
void Mailbox::print() {
    if (messageCount == 0 || messageCount < 0) {
        cout << "Mailbox is empty." << endl;
    }
    else {
        for (int i = 0; i < messageCount; i++) {
            cout << "Message " << (i + 1) << ":" << endl;
            inbox[i].print();
            cout << endl;
        }
    }
}

#endif  MAILBOX_H_ 
