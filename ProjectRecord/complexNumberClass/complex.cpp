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

Complex Complex::operator+(Complex const &obj) const {
    Complex result;
    result.realPart = realPart + obj.realPart;
    result.imaginaryPart = imaginaryPart + obj.imaginaryPart;
    return result;
}

Complex Complex::operator*(Complex const &obj) const {
    //    (a+b*i)*(c+d*i) = (a*c-b*d)+(a*d+b*c)*i
    Complex result;
    result.realPart = (realPart * obj.realPart - imaginaryPart * obj.imaginaryPart);
    result.imaginaryPart = (realPart * obj.imaginaryPart + imaginaryPart * obj.realPart);
    return result;
}

bool Complex::operator==(Complex const &obj) const {
    return realPart == obj.realPart && imaginaryPart == obj.imaginaryPart;
}

Complex Complex::operator-(Complex const &obj) const {
    Complex result;
    result.realPart = realPart - obj.realPart;
    result.imaginaryPart = imaginaryPart - obj.imaginaryPart;
    return result;
}

ostream &operator<<(ostream &os, const Complex &obj) {
    if (obj.imaginaryPart < 0) {
        os << obj.realPart << obj.imaginaryPart << 'i';
    } else {
        os << obj.realPart << '+' << obj.imaginaryPart << 'i';
    }

    return os;
}

istream &operator>>(istream &is, Complex &obj) {
    string tempString;
    is >> tempString;
    bool realNumber;
    bool imag;
    int starting=0;
    int index = 0;
    string real;
    string img;

    for (char x : tempString) {
        if (x == 'i') {
            imag = true;
        }
        index++;
//        if(tempString[tempString.size()-1]=='i'){
//
//        }


        if (index > 0 && x == '+' || index > 0 && x == '-') {
            real = tempString.substr(0, index - 1);
            obj.realPart=atoi( real.c_str() );

            img = tempString.substr(index, tempString.size()-(index+1));
            obj.imaginaryPart=atoi(img.c_str());
            break;
        }
    }

    return is;
}

