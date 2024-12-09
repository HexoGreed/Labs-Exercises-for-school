#include <iostream>
#include "Mailbox copy.h"
#include "ccc_time copy.h"  // Include the Time class
using namespace std;

int main() {
    // Create a mailbox
    Mailbox myMail;

    // Create first message with sender, recipient, message content, and default time (current time)
    Message message1("Jimmy", "Bobby", "Hello, JImmy Bobby Brown see ya later!",Time());
    myMail.add_message(message1);

    // Create second message with sender, recipient, message content, and specific timestamp
    Time message2TimeUpdate(12, 9, 24);  // Set a specific timestamp for this message
    Message message2("Goku", "Vegeta", "Hey, its me, Goku!", message2TimeUpdate);
    myMail.add_message(message2);




    myMail.get_message(0).print();
    myMail.print();
    myMail.remove_message(0);


    myMail.print();

    return 0;
}
