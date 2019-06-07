//
// Created by JonathanSum on 5/25/2019.
//

#ifndef INC_3A_LISTEMPTY_H
#define INC_3A_LISTEMPTY_H

#include <iostream>

using namespace std;

class ListEmpty {
public:
    ListEmpty() {
        line = "Error: list is empty.";
    };

    string what() {
        return line;
    };
private:
    string line;
};


#endif //INC_3A_LISTEMPTY_H
