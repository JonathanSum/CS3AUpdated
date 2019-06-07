//
// Created by JonathanSum on 3/9/2019.
//

#include "Rational.h"
#include <iostream>

using namespace std;
//add: (a/b) + (c/d) = (a*d + b*c) / (b*d)
//subtract: (a/b) - (c/d) = (a*d - b*c) / (b*d)
//multiply: (a/b) * (c/d) = (a*c) / (b*d)
//divide: (a/b) / (c/d) = (a*d) / (c*b)
const Rational Rational::add(const Rational &R2) const {
    //add: (a/b) + (c/d) = (a*d + b*c) / (b*d)
    int n = numer * R2.denom + denom * R2.numer;
    int d = denom * R2.denom;
    return Rational(n, d);
}

const Rational Rational::subtract(const Rational &R2            //IN -- input Rational object

) const {
    //subtract: (a/b) - (c/d) = (a*d - b*c) / (b*d)
    int n = numer * R2.denom - denom * R2.numer;
    int d = denom * R2.denom;
    return Rational(n, d);
}

const Rational Rational::multiply(const Rational &R2            //IN -- input Rational object
) const {
    //multiply: (a/b) * (c/d) = (a*c) / (b*d)
    int n = numer * R2.numer;
    int d = denom * R2.denom;
    return Rational(n, d);
}

const Rational Rational::divide(const Rational &R2            //IN -- input Rational object
) const {
    //divide: (a/b) / (c/d) = (a*d) / (c*b)
    int n = numer * R2.denom;
    int d = R2.numer * denom;
    return Rational(n, d);
}

void Rational::display() const {
//    print out numerator / denominator
    cout << numer << "/" << denom ;

}
string Rational::stringValue() const {
    return (to_string(numer)+"/"+to_string(denom));
}

bool Rational::operator<( const Rational &d) const {
    double tempN = numer;
    double thisDouble =tempN/denom;
    double tempNC =  d.numer;
    double compairDouble = tempNC/d.denom;
    return (thisDouble<compairDouble);
}

bool Rational::operator>( const Rational &d)  const{
    double tempN = numer;
    double thisDouble =tempN/denom;
    double tempNC =  d.numer;
    double compairDouble = tempNC/d.denom;
    return (thisDouble>compairDouble);
}

bool Rational::operator==(const Rational &r) const {

    return (numer==r.numer)&&(denom==r.denom);
}

bool Rational::operator!=(const Rational &r) const {
    return !(*this == r);
}
