//
// Created by zerotwo on 3/20/19.
//
#include <iostream>

#ifndef INC_3A_COMPLEX_H
#define INC_3A_COMPLEX_H
using namespace std;

class Complex {
private:
    float realPart;
    float imaginaryPart;


public:
    Complex() {
        realPart = 0;
        imaginaryPart = 0;
    }

    Complex(float r) {
        realPart = r;
        imaginaryPart=0;
    }

    Complex(float r, float i) {
        realPart=r;
        imaginaryPart=i;
    }


    Complex operator+(Complex const &obj) const;

    Complex operator*(Complex const &obj) const;

    Complex operator-(Complex const &obj) const;

    bool operator==(Complex const &obj) const;

    friend ostream &operator<<(ostream &os, const Complex &obj);

    friend istream &operator>>(istream &is, Complex &obj);

};


#endif //INC_3A_COMPLEX_H
