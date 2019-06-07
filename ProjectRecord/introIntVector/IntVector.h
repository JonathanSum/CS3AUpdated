/***********************************************
*   Author         : Jonathan Sum
*   Assignment     : Assignment 5: IntVector
*   SECTION        : CS 003A
*   Due Date       : 4/02/19
*   ________________________________________________
*   Goals
*   By the end of this assignment you should:
*   have a good head start on the IntVector assignment
*   have fully tested the constructors and accessor functions
*   be confident these functions work correctly
***********************************************/
#include <iostream>

#ifndef INC_3A_1_INTVECTOR_H
#define INC_3A_1_INTVECTOR_H

#include <cstddef>

using namespace std;

class IntVector {
private:
    void expand( unsigned amount );
    void expand();
    unsigned sz;        //IN - size of the vector
    unsigned cap;       //IN - captize of the vector
    int *data;          //IN - the address of the array
public:


    /************************
**      CONSTRUCTOR  AND DECONSTRUCTOR  **
************************/
    IntVector() {
        sz = 0;
        cap = 0;
    };

    IntVector(unsigned size) {
        data = nullptr;

        sz = size;
        cap = size;
        data = new int[cap];
        for (int i = 0; i < sz; i++) {
            data[i]=0;
        }
    };

    IntVector(unsigned size, int value) {
        data = nullptr;

        sz = size;
        cap = size;

        data = new int[cap];
        for (int i = 0; i < sz; i++) {
            data[i]=value;
        }
    };

    /**********************
        * * ACCESSORS **
    **********************/
    unsigned size() const;

    unsigned capacity() const;

    bool empty() const;

    const int &at(unsigned index) const;
    const int & front( ) const;
    const int & back( ) const;
    void insert( unsigned index, int value );
    void erase( unsigned index );
    void push_back( int value );
    void pop_back();
    void resize( unsigned size );
    void resize( unsigned size, int value );
    void reserve( unsigned n );
    ~IntVector();


};

/*********************************************************************
   * IntVector Class
   * This class represents a IntVector object.
   * It manages 2 attributest,
   * size of the vector object array
   * and capacity of the vector object array
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  IntVector();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/

/*********************************************************************
 *  IntVector(unsigned size);
 *  Constructor;   Sets both the size and capacity of the IntVector
 *  to the value of the parameter passed in and dynamically
 *  allocates an array of that size as well.
 *  Parameter: unsigned size,   //IN - size of the vector object array
 *  Return: none
*********************************************************************/

/*********************************************************************
 *  IntVector(unsigned size, int value);
 *  Constructor;   Sets both the size and capacity of the IntVector
 *  to the value of the parameter passed in and dynamically allocates
 *  an array of that size as well.
 *  It initialize all elements of the array
 *  to the value of the 2nd parameter.
 *  Parameter: unsigned size        //size of the vector object array
 *             int value            //value for initialize
 *  Return: none
*********************************************************************/

/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/

/*********************************************************************
 * unsigned size() const;
 * Accessors: Return the size of the vector object array
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: Positive integer - size of the vector object array
*********************************************************************/
/*********************************************************************
 * unsigned capacity() const;
 * Accessors: Return the capacity of the vector object array
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: Positive integer
*********************************************************************/
/*********************************************************************
 * bool empty() const;
 * Accessors: Check the vector object array is empty or not.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: boolean
*********************************************************************/
/*********************************************************************
 * const int &at(unsigned index) const;
 * Accessors: return the element in the vector object array.
 *--------------------------------------------------------------------
 * Parameter: unsigned index    // index of the vector object array
 *--------------------------------------------------------------------
 * Return: Constant integer
*********************************************************************/

#endif //INC_3A_1_INTVECTOR_H
