/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 04 - Rational class
 *   SECTION        : CS 003A
 *   Due Date       : 3/09/19
 *   ________________________________________________
 *   A solution that is often used when precision is of greatest importance and
 *   all of the numbers involved are going to be "rational" (that is, expressible as
 *   a 'ratio' of two integers - i.e. a fraction) is to use a custom data type - i.e. a
 *   class - that implements fractions, or "rational numbers". This is what you
 *   will do in this lab assignment.
***********************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Date.h"
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;
//default constructor: creates the date January 1st, 2000.

void printString(string *s){
    cout<<*s<<endl;
}

int main() {
//    string temp = "I am temp";
//    string *tempPtr = &temp;
//    printString(tempPtr);
    Date x = Date("February", 34, 2050);
    x.printNumeric();
    cout << endl;
    x.printAlpha();

    return 0;
}
