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


    return (realPart == obj.realPart && imaginaryPart == obj.imaginaryPart);
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

        if ((index > 0 && x == '+') || (index > 0 && x == '-')) {
            real = tempString.substr(0, index - 1);
            obj.realPart=stoi ( real );
            obj.realPart = stoi (real);
            img = tempString.substr(index, tempString.size()-(index+1));
            obj.imaginaryPart=stoi(img);
            break;
        }
    }

    return is;
}

string Complex::stringValue() const {
    if (imaginaryPart < 0) {
        return ( to_string(realPart) + to_string(imaginaryPart) + 'i');
    } else {
        return ( to_string(realPart) +"+"+ to_string(imaginaryPart) + 'i');
    }
}

bool Complex::operator>(const Complex &d)const {


/*****
    square error to determine the size
    double thisDistance =sqrt((realPart*realPart)+(imaginaryPart*imaginaryPart));
    double dDistance =sqrt((d.realPart*d.realPart)+(d.imaginaryPart*d.imaginaryPart));
    ****/
    double dx = realPart - d.realPart;
    double dy = imaginaryPart - d.imaginaryPart;
    return ((dx+dy)>0);
}

bool Complex::operator<(const Complex &d)const {
    return (*this>d);
}

bool Complex::operator!=(const Complex &r) const {
    return !(*this == r);
}
