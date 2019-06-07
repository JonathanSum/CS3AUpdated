/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 16 - 2D Vector
 *   SECTION        : CS 003A
 *   Due Date       : 5/19/19
 *   ________________________________________________
 *   Goals
 *   Have a good understanding on how to template a class

***********************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
//#include "Date.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include "matrix.h"
using namespace std;



int main() {
cout<<"Demonstrating with string matrix:\n"
      "\n"
      "Matrix set to first array\n";
    Matrix<string> stringM1;
    Matrix<string> stringM2;
    Matrix<string> stringM3;
    string arr1D[6] = { "Congra", "y", "ar", "alm", "don", "La"  };
    stringM1.setMatrix(arr1D);
    stringM1.printMatrix();
    cout<<endl;
    string arr1D2[6] = { "tulations", "ou", "e", "ost", "e    the", "b!"  };
    stringM2.setMatrix(arr1D2);
    cout<<"Matrix incremented by second array"<<endl;
    stringM3 = stringM1+stringM2;
    cout<<stringM3<<endl;
    cout<<"Demonstrating with int matrix:\n"
          "\n"
          "Matrix set to first array\n";
    Matrix <int>intM1;
    int array1DInt[6] = {1,2,3,4,5,6};
    intM1.setMatrix(array1DInt);
    intM1.printMatrix();
    Matrix <int>intM2;

    int array2DInt2[2][3] = {{6,5,4},{3,2,1}};
    intM2.setMatrix(array2DInt2);
    cout<<endl<<"Matrix incremented by second array"<<endl;
    Matrix<int>intM3 = intM1+intM2;
    cout<<intM3<<endl;

    cout<<"Demonstrating with float matrix:\n"
          "\n"
          "Matrix set to first array"<<endl;
    Matrix <double>doubleM1;
    Matrix <double>doubleM2;
    double array1Ddouble[6] = {1.6,   2.5,   3.4,
            4.3,   5.2,   6.1 };
    doubleM1.setMatrix(array1Ddouble);
    doubleM1.printMatrix();
    cout<<endl<<"Matrix incremented by second array"<<endl;
    double array2Ddouble2[2][3] = {{6.1,5.2,4.3},{3.4,2.5,1.6}};
    doubleM2.setMatrix(array2Ddouble2);
    Matrix<double>doubleM3 = doubleM1+doubleM2;
    cout<<doubleM3;




    return 0;
}

