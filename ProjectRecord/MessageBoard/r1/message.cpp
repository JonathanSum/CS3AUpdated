//
// Created by JonathanSum on 3/15/2019.
//

#include "message.h"

void Message::display() const {
    cout<<subject<<endl;
    cout<<"from "<<author<<": "<<body<<endl;
}
