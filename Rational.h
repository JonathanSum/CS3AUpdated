//
// Created by JonathanSum on 3/9/2019.
//

#ifndef INC_3A_RATIONAL_H
#define INC_3A_RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
private:
    int numer;      //IN --  numerator
    int denom;      //IN -- denominator
public:
    Rational() {        //default constructor
        numer = 0;
        denom = 1;
    }

    Rational(int n) {       // constructor for only one numerator
        numer = n;
        denom = 1;
    }

    Rational(int n, int d) {       // constructor for denominator and numerator
        numer = n;
        denom = d;
    }

    const Rational add(const Rational &) const;         //member function for adding

    const Rational subtract(const Rational &) const;         //member function for subtracting

    const Rational multiply(const Rational &) const;         //member function for multiply

    const Rational divide(const Rational &) const;         //member function for divide

    void display() const;         //member function for displace
    string stringValue() const;

    // overloaded < operator
    bool operator <( const Rational &d) const;
    bool operator ==( const Rational &r) const;
    bool operator !=( const Rational &r) const;
    // overloaded > operator
    bool operator >( const Rational &d) const;
};


#endif //INC_3A_RATIONAL_H
