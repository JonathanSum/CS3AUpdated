/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 8 - Inheritance
 *   SECTION        : CS 003A
 *   Due Date       : 5/19/19
 *   ________________________________________________
 *   Goals
 *   Have a good understanding on Inheritance

***********************************************/
    #include <string>
    #include <iostream>
    #include <vector>
    #include "cs003AStudent.h"
    #include "student.h"
    using namespace std;




class tornadoException {
public:
    tornadoException() {
        line= "Tornado: Take cover immediately!";
    }
    tornadoException(int mile){
        m = mile;
        line = "Tornado: "+to_string(m)+" miles away; and approaching!";
    }
    string what();
private:
    int m;
    string line;
};
string tornadoException::what() {
    return line;
}

int main() {
    try {
        tornadoException t1;
        throw t1;
    } catch(tornadoException &eObj) {
        cout << eObj.what() << endl;
    }
    try {
        tornadoException t1(10);
        throw t1;
    } catch(tornadoException &eObj) {
        cout << eObj.what() << endl;
    }
}


