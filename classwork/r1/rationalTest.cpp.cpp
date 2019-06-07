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

using namespace std;

class Rational {
public:
    int numer;
    int denom;
public:
    Rational() {
        numer = 0;
        denom = 1;
    }

    Rational(int n) {
        numer = n;
        denom = 1;
    }

    Rational(int n, int d){
        numer = n;
        denom = d;
    }

    const Rational add(const Rational &) const;

    const Rational subtract(const Rational &) const;

    const Rational multiply(const Rational &) const;

    const Rational divide(const Rational &) const;

    void display() const;
};
//add: (a/b) + (c/d) = (a*d + b*c) / (b*d)
//subtract: (a/b) - (c/d) = (a*d - b*c) / (b*d)
//multiply: (a/b) * (c/d) = (a*c) / (b*d)
//divide: (a/b) / (c/d) = (a*d) / (c*b)
const Rational Rational::add(const Rational &R2) const {
    //add: (a/b) + (c/d) = (a*d + b*c) / (b*d)
   int n =numer*R2.denom+denom*R2.numer;
   int d = denom*R2.denom;
    return Rational(n,d);
}

const Rational Rational::subtract(const Rational &R2) const {
    //subtract: (a/b) - (c/d) = (a*d - b*c) / (b*d)
    int n =numer*R2.denom-denom*R2.numer;
    int d = denom*R2.denom;
    return Rational(n,d);
}

const Rational Rational::multiply(const Rational &R2) const {
    //multiply: (a/b) * (c/d) = (a*c) / (b*d)
    int n =numer*R2.numer;
    int d = denom*R2.denom;
    return Rational(n,d);
}

const Rational Rational::divide(const Rational &R2) const {
    //divide: (a/b) / (c/d) = (a*d) / (c*b)
    int n =numer*R2.denom;
    int d = R2.numer*denom;
    return Rational(n,d);
}

void Rational::display() const {
//    print out numerator / denominator
    cout << numer << "/" << denom << endl;
}

//add: (a/b) + (c/d) = (a*d + b*c) / (b*d)
//subtract: (a/b) - (c/d) = (a*d - b*c) / (b*d)
//multiply: (a/b) * (c/d) = (a*c) / (b*d)
//divide: (a/b) / (c/d) = (a*d) / (c*b)


int main() {
//    Rational r, r1;


    cout << "Testing default constructor.\n";
    Rational r1;
    r1.display();
//    0/1\n
 return 0;
}
