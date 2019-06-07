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


#ifndef INC_3A_1_INTVECTOR_H
#define INC_3A_1_INTVECTOR_H

#include <iostream>
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
**      CONSTRUCTOR  AND DESTRUCTOR  **
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

    /**********************
         * * MUTATORS **
    **********************/
    void insert( unsigned index, int value );
    void erase( unsigned index );
    void push_back( int value );
    void pop_back();
    void clear();
    void resize( unsigned size );
    void resize( unsigned size, int value );
    void reserve( unsigned n );
    void assign( unsigned n, int value );
    int & at( unsigned index );
    int & front( );
    int & back( );
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
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~IntVector();
 *  destructor;   deallocate all remaining
 *  It delets memory dynamically allocated, which it deletes the
 *  data array with delete operator:
 *  Parameter: none
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

/*********************************************************************
 * const int & front( ) const;
 * Accessors: return the first element in the vector object array.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: Constant integer
*********************************************************************/

/*********************************************************************
 * const int & back( ) const;
 * Accessors: return the last element in the vector object array.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: Constant integer
*********************************************************************/

/*********************************************************************
                            * * PRIVATE HELPER FUNCTIONS **
*********************************************************************/

/*********************************************************************
 * void expand();
 *  Private Helper Functions: This function will double the capacity of
 *  the vector. This function should reallocate memory for the dynamically
 *  allocated array and update the value of capacity.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void expand( unsigned amount );
 *  Private Helper Functions: This function will expand the capacity of the vector by amount passed
 *  in. This function should reallocate memory for the dynamically
 *  allocated array and update the value of capacity.
 *--------------------------------------------------------------------
 * Parameter: unsigned amount   //IN - amount of element that the
 * user wants to expand.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
                            * * MUTATORS **
*********************************************************************/

/*********************************************************************
 * void insert( unsigned index, int value );
 * Mutators: This function inserts data at location index. All values currently
 *  at position index and greater are shifted to the right by 1
 *  (to the element right after its current position).
 *--------------------------------------------------------------------
 * Parameter: unsigned index,   //IN - index for insert
 *            int value     //IN - value to be inset
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void erase( unsigned index );
 *  Mutators: This function removes the value at position index and shifts all
 *  of the values at positions greater than index to the left by one
 *  (to the element right before its current position).
 *--------------------------------------------------------------------
 * Parameter: unsigned index,   //IN - index for erase
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void push_back( int value );
 * Mutators:  This function inserts a value at the back end of the array.
 *--------------------------------------------------------------------
 * Parameter: int value,   //IN - value for insert
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void clear();
 * Mutators: This function reduces the size of the vector to 0.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void resize( unsigned size );
 *  Mutators: This function inserts a value at the back end of the array.
 *  If size is smaller than the current size(sz), this function just
 *  reduces the value of sz to size.
 *  If size is greater than the current size(sz), then
 *  the appropriate number of elements are inserted at the end of
 *  the vector, giving all of the new elements a value of 0.
 *--------------------------------------------------------------------
 * Parameter: unsigned size    //IN - size of the vector
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void resize( unsigned size, int value);
 *  Mutators: This function inserts a value at the back end of the array.
 *  If size is smaller than the current size(sz), this function just
 *  reduces the value of sz to size.
 *  If size is greater than the current size(sz), then
 *  the appropriate number of elements are inserted at the end of
 *  the vector, giving all of the new elements a value of
 *  the 2nd parameter (value).
 *--------------------------------------------------------------------
 * Parameter: unsigned size,    //IN - size of the vector
 *            int value         //IN - value to be added for the extra
 *                              value of the update size is greate than the
 *                              original size.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void reserve( unsigned n )
;
 * Mutators: This function requests that the capacity
 * (the size of the dynamically allocated array) be set to n at minimum.

 *--------------------------------------------------------------------
 * Parameter:  unsigned n,   //IN - capacity that is the minimum
 *                          // capacity of the vector.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void reserve( unsigned n );
 * Mutators: This function requests that the capacity
 * (the size of the dynamically allocated array) be set to n at minimum.

 *--------------------------------------------------------------------
 * Parameter:  unsigned n,   //IN - capacity that is the minimum
 *                          // capacity of the vector.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * void assign( unsigned n, int value );
 * Mutators: This function drops the current values and update the
 * vector array to new value
 *--------------------------------------------------------------------
 * Parameter: unsigned n,       //IN - size of new vector array
 *            int value         //IN - value to be assigned for the
 *                              //     vector array
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * int & at( unsigned index );
 * Mutators: This function will return the value stored in the element
 * at the passed in index position.
 * program will exit if an index greater than or equal
 * to the size is passed in.
 *--------------------------------------------------------------------
 * Parameter: unsigned n,       //IN - size of new vector array
 *            int value         //IN - value to be assigned for the
 *                              //     vector array
 *--------------------------------------------------------------------
 * Return: Integer
*********************************************************************/

/*********************************************************************
 * int & front( );
 * Mutators: This function will return the first element in the vector array
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: Integer
*********************************************************************/

/*********************************************************************
 * int & front( );
 * Mutators: This function will return the last element in the vector array
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: Integer
*********************************************************************/

#endif //INC_3A_1_INTVECTOR_H
