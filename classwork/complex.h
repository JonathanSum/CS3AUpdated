//
// Created by zerotwo on 3/20/19.
//
#include <iostream>

#ifndef INC_3A_COMPLEX_H
#define INC_3A_COMPLEX_H
using namespace std;

class Complex {

private:
    float realPart;                 //IN - real number
    float imaginaryPart;            //IN - imaginary number


public:
    /************************
    **      CONSTRUCTOR   **
    ************************/
    Complex() {
        realPart = 0;
        imaginaryPart = 0;
    }

    Complex(float r) {
        realPart = r;
        imaginaryPart = 0;
    }

    Complex(float r, float i) {
        realPart = r;
        imaginaryPart = i;
    }

    /**********************
        * * ACCESSORS **
    **********************/

    Complex operator+(Complex const &obj) const;

    Complex operator*(Complex const &obj) const;

    Complex operator-(Complex const &obj) const;

    bool operator==(Complex const &obj) const;

    /**********************
        * * MUTATORS **
    **********************/

    friend ostream &operator<<(ostream &os, const Complex &obj);

    friend istream &operator>>(istream &is, Complex &obj);

};

/*********************************************************************
   * Complex Class
   * This class represents a user object.
   * It manages 2 attributest,
   * user name, and user password
   * real number and imaginary number
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 * Complex();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/

/*********************************************************************
 *  Complex(float r)
 *  Constructor;   Setting the Complex class attributes, but only the
 *  real number. The imaginary number is set to zero
 *  Parameter: float r,     //IN - real number
 *  Return: none
*********************************************************************/

/*********************************************************************
 *  Complex(float r, float i)
 *  Constructor;   Setting the Complex class attributes
 *  Parameter: float r,     //IN - real number
 *             float i,     //IN - imaginary number
 *  Return: none
*********************************************************************/

/*********************************************************************
                            * * MUTATORS **
*********************************************************************/

/*********************************************************************
 * friend ostream &operator<<(ostream &os, const Complex &obj);
 * Mutators; This method will mutate the << operator to perform
 * different format of << operator for output.
 *--------------------------------------------------------------------
 * Parameter: ostream &os    //  IN  -   os stream
 *            const Complex &obj    // IN - Complex object
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * friend istream &operator>>(istream &is, Complex &obj);
 * Mutators; This method will mutate the >> operator to perform
 * different format of r >> operator for input.
 *--------------------------------------------------------------------
 * Parameter: istream &is    //  IN  -   a input stream
 *            const Complex &obj    // IN - Complex object
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/


/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/


/*********************************************************************
 * Complex operator+(Complex const &obj) const;
 * Mutators; This method will mutate the + operator to perform
 * different format of + operator for adding.
 *--------------------------------------------------------------------
 * Parameter: const Complex &obj    // IN - Complex object
 *--------------------------------------------------------------------
 * Return: Complex object
*********************************************************************/
/*********************************************************************
 * Complex operator*(Complex const &obj) const;
 * Mutators: This method will mutate the * operator to perform
 * different format of * operator for multiplying
 * two complex numbers(object)
 *--------------------------------------------------------------------
 * Parameter: const Complex &obj    // IN - Complex object
 *--------------------------------------------------------------------
 * Return: Complex object
*********************************************************************/
/*********************************************************************
 * Complex operator-(Complex const &obj) const;
 * Mutators: This method will mutate the - operator to perform
 * different format of - operator for subtraction.
 *--------------------------------------------------------------------
 * Parameter: const Complex &obj    // IN - Complex object
 *--------------------------------------------------------------------
 * Return: Complex object
*********************************************************************/

/*********************************************************************
 * bool operator==(Complex const &obj) const;
 * Mutators: This method will mutate the == operator to perform
 * different format of == operator for checking
 * equality of two complex numbers(object).
 *--------------------------------------------------------------------
 * Parameter: const Complex &obj    // IN - Complex object
 *--------------------------------------------------------------------
 * Return: Complex object
*********************************************************************/



#endif //INC_3A_COMPLEX_H