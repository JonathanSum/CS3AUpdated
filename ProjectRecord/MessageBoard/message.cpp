//
// Created by JonathanSum on 3/15/2019.
//

#include "message.h"
/*************************************
 * display()
 *  THis function display the message in format
 *  - return nonthing -> this will output the message.
 **************************************/


void Message::display() const {
    //OUTPUT - display the message
    cout<<subject<<endl;
    cout<<"from "<<author<<": "<<body<<endl;
}
