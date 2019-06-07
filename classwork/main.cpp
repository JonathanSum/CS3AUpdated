/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 08 - Complex class
 *   SECTION        : CS 003A
 *   Due Date       : 3/21/19
 *   ________________________________________________
 *   Goals
 *   be more familiar with declaring and using your own ADT (class).
 *   know how to declare and implement an overloaded operator function
***********************************************/
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
#include <fstream>

using namespace std;



//the purpose of this is to understand more on overriding and object.
int main(int argc, char *argv[]) {


    //PROCESSING and OUT - These are the requirement for
    // testing complex program runs or not
    cout<<endl;
    cout<<"Testing default constructor\n";
    cout<<Complex()<<endl;
    cout<<endl;
    cout<<"Testing one parameter constructor with input 5\n";
    cout<<Complex(5)<<endl;
    cout<<endl;
    cout<<"Testing two parameter constructor with input 0, 0\n";
    cout<<Complex(0,0)<<endl;
    cout<<endl;
    cout<<"Testing two parameter constructor with input 1, 2\n";
    cout<<Complex(1,2);
    cout<<endl;
    cout<<endl;
    cout<<"Testing two parameter constructor with input -13, 21\n";
    cout<<Complex(-13,21);
    cout<<endl;
    cout<<endl;
    cout<<"Testing two parameter constructor with input -3, -4\n";
    cout<<Complex(-3,-4);
    cout<<endl;
    cout<<endl;
    cout<<"Testing addition subtraction and multiplication for complex numbers: 10+4i and 5+3i\n";
    cout<<"10+4i + 5+3i = "<<Complex(10,4)+Complex(5,3);
    cout<<endl;
    cout<<"10+4i - 5+3i = "<<Complex(10,4)-Complex(5,3);
    cout<<endl;
    cout<<"10+4i * 5+3i = "<<Complex(10,4)*Complex(5,3);
    cout<<endl;
    cout<<endl;
    cout<<"Testing addition subtraction and multiplication for complex numbers: -10-4i and -5-3i\n";
    cout<<"-10-4i + -5-3i = "<<Complex(-10,-4)+Complex(-5,-3);
    cout<<endl;
    cout<<"-10-4i - -5-3i = "<<Complex(-10,-4)-Complex(-5,-3);
    cout<<endl;
    cout<<"-10-4i * -5-3i = "<<Complex(-10,-4)*Complex(-5,-3);
    cout<<endl;
    cout<<endl;
    cout<<"Testing == operator with -10-4i and -5-3i\n";
    bool b1 = Complex(-10,-4)==Complex(-5,-3);
    cout<<"Should be false: "<<b1;
    cout<<endl;
    cout<<endl;
    cout<<"Testing == operator with 10+4i and 10+4i\n";
    bool b2 = Complex(10,4)==Complex(10,4);
    cout<<"Should be true: "<<b2;
    cout<<endl;
    cout<<endl;
    cout<<"Testing << and >> operators\n";
    cout<<"enter imaginary number of form a+bi or a-bi\n";
    Complex c1;
    cin>>c1;
    cout<<c1;
    cout<<endl;

    return 0;
}