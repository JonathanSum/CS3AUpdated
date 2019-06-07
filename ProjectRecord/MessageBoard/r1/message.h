//
// Created by JonathanSum on 3/15/2019.
//

#ifndef INC_3A_MESSAGE_H
#define INC_3A_MESSAGE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


//inclusion guards
//includes

class Message {
private:
    string author;
    string subject;
    string body;

public:
    //default constructor
    Message() {
        author = "";
        subject = "";
        body = "";
    };

    //Constructor with parameters
    Message(const string &athr,
            const string &sbjct,
            const string &body) {
        author=athr;
        subject=sbjct;
        this->body=body;
    }


    //displays the message in the given format. See output specs.
    void display() const;
};

//end inc guards



#endif //INC_3A_MESSAGE_H
