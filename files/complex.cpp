//
// Created by zerotwo on 3/20/19.
//

#include "complex.h"


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
    if(obj.imaginaryPart<0){
        os << obj.realPart<< obj.imaginaryPart << 'i';
    }else{
        os << obj.realPart << '+' << obj.imaginaryPart << 'i';
    }

    return os;
}

istream &operator>>(istream &is, Complex &obj) {
    is >> obj.realPart >> obj.imaginaryPart;
    return is;
}


