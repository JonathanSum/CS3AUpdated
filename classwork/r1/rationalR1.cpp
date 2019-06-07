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
};

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
    cout<<endl;
    cout << "Testing one argument constructor with 5 as the argument.\n";
//    5/1\n
    Rational r2(5);
    r2.display();
    cout<<endl;
    cout << "Testing two argument constructor with (2,3) as the argument.\n";
//    2/3\

    Rational r3(2, 3);
    r3.display();
    cout<<endl;
    cout << "Testing add function by adding 5 and 2/3.\n";
//    17/3\

    r2.add(r3).display();
    cout<<endl;
    cout << "Testing subtract function by subtracting 5 and 2/3.\n";
//    13/3\n
    r2.subtract(r3).display();
    cout<<endl;
    cout << "Testing multiply function by multiplying 5 and 2/3.\n";
//    10/3\n
    r2.multiply(r3).display();
    cout<<endl;
    cout << "Testing divide function by dividing 5 and 2/3.\n";
//    15/2\n
    r2.divide(r3).display();
    return 0;
}
