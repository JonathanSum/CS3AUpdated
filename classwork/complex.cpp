//
// Created by zerotwo on 3/20/19.
//

#include "complex.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "complex.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

/*************************************
 *     Complex Complex::operator+(Complex const &obj) const
 *      This method overrides + operator and return a
 *      complex object
 **************************************/
Complex Complex::operator+(Complex const &obj) const {
    Complex result;     // IN/OUT - dumpy variable

    //PROCESSING perform adding of two complex numbers
    result.realPart = realPart + obj.realPart;
    result.imaginaryPart = imaginaryPart + obj.imaginaryPart;
    return result;
}

/*************************************
 *     Complex Complex::operator+(Complex const &obj) const
 *      This method overrides * operator and return a
 *      complex object
 **************************************/
Complex Complex::operator*(Complex const &obj) const {

    Complex result;     // IN/OUT - dumpy variable

    //PROCESSING - set real number and imaginary number
    //of the object with this formula.
    result.realPart = (realPart * obj.realPart - imaginaryPart * obj.imaginaryPart);
    result.imaginaryPart = (realPart * obj.imaginaryPart + imaginaryPart * obj.realPart);

    return result;
}

/*************************************
 *     Complex Complex::operator==(Complex const &obj) const
 *      This method overrides == operator and return a
 *      complex object
 **************************************/

bool Complex::operator==(Complex const &obj) const {

    //PROCESSING - Calc two complex object are equal or not.
    return realPart == obj.realPart && imaginaryPart == obj.imaginaryPart;

}

/*************************************
 *     Complex Complex::operator-(Complex const &obj) const
 *      This method overrides - operator and return a
 *      complex object
 **************************************/
Complex Complex::operator-(Complex const &obj) const {

    Complex result;    // IN/OUT - dumpy variable

    //PROCESSING perform subtraction of two complex numbers
    result.realPart = realPart - obj.realPart;
    result.imaginaryPart = imaginaryPart - obj.imaginaryPart;
    return result;
}

/*************************************
 *     ostream &operator<<(ostream &os, const Complex &obj)
 *      This method will mutate the << operator to perform
 *      different format of << operator for output.
 **************************************/
ostream &operator<<(ostream &os, const Complex &obj) {

    // PROCESSING/OUT perform different format of << operator for output.
    if (obj.imaginaryPart < 0) {
        os << obj.realPart << obj.imaginaryPart << 'i';
    } else {
        os << obj.realPart << '+' << obj.imaginaryPart << 'i';
    }

    return os;
}

/*************************************
 *     istream &operator>>(istream &is, Complex &obj) const
 *      This method will mutate the >> operator to perform
 *     different format of r >> operator for input.
 **************************************/
istream &operator>>(istream &is, Complex &obj) {
    string tempString;      //IN - dumpy variable for storing a temp string
    is >> tempString;       // IN input stream for tempString

    int index = 0;          // CALC - index of the for loop below
    string real;            // IN/OUT real number
    string img;            // IN/OUT imaginary number

    // PROCESSING - run a for loop to loop through each element of
    // a input string from user
    for (char x : tempString) {



        //CALC & OUT if the element after first index is + or -,
        //set the real number part and img number part
        if (index > 0 && x == '+' || index > 0 && x == '-') {


            real = tempString.substr(0, index);
            obj.realPart = static_cast<float>(atof(real.c_str()));


            img = tempString.substr(index, tempString.size() - (index + 1));
            obj.imaginaryPart = static_cast<float>(atof(img.c_str()));

            break;
        }

        if (index == tempString.size() - 1) {
            if (tempString == "i") {
                obj.realPart = 0;


                obj.imaginaryPart = 1;
            } else if (tempString == "-i") {
                obj.realPart = 0;
                obj.imaginaryPart = -1;
            } else if (tempString[tempString.size() - 1] == 'i') {

                obj.realPart = 0;


                obj.imaginaryPart = static_cast<float>(atof(tempString.c_str()));
            } else if (tempString[tempString.size() - 1] != 'i') {

                obj.realPart = static_cast<float>(atof(tempString.c_str()));


                obj.imaginaryPart = 0;
            }
        }

        index++;        // adding index by one at the end of the loop
    }


    return is;
}

