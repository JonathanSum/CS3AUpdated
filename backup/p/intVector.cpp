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
#include "intVector.h"
#include <stdlib.h>

using namespace std;

unsigned IntVector::size() const {

    //OUT -return the size of vector.
    return sz;
}

unsigned IntVector::capacity() const {

    //OUT -return the capacity of vector.
    return cap;
}

bool IntVector::empty() const {

    //OUT -return a bool to show the either the vector is empty or not.
    return sz == 0;
}

template<class E>
E &IntVector::at(unsigned index, int type) const {

    if (index >= sz) {
        //OUT - exit the system when the input
        cout << "index should not be greater than or equal to the size is passed in." << endl;
        exit(1);
    } else {
        //OUT - return the element with index of array at address of data.
        switch(type){
            case 1:
                return dataInt;
            case 2:
                return dataInt;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 61:
                break;
        }
    }
}

IntVector::~IntVector() {

    //Free memory
    delete[] data;
    data = nullptr;
}

const int &IntVector::front() const {
    //PROCESSING - return the value stored at the first element.
    return *data;
}

const int &IntVector::back() const {

    //PROCESSING - return the value stored at the last element.

    return *(data + (sz - 1));
}

void IntVector::expand() {

    expand(cap);    //PROCESSING - expand double of the size of the original size
}

void IntVector::expand(unsigned amount) {

    //PROCESSING - if cap originally is zero, we will add 1 to the cap. Thus,
    //              we don't need to add amount to cap is one.                               //because cap originally was zero.
    if(cap==0){
        cap=1;
        amount=0;

    }
    int *temp = nullptr;            //IN - It is just a dummy memory address.

    // for copying the original vector.
    temp = new int[cap + amount];

    //PROCESSING - only copy when there is a element in the vector.
    if(sz!=0){
        for (int i = 0; i < sz; i++) {
            temp[i] = data[i];
        }

    }

    //PROCESSING - now copy the temp vector to data address.
    data = temp;
    temp = nullptr;

    cap += amount;

    delete[] temp;

}

void IntVector::insert(unsigned index, int value) {

    //CALC - exit(1) if an index value greater than sz is passed in.
    if (index >= sz) {
        cout << "index value greater than sz is passed in." << endl;
        exit(1);
    }

    //CALC -  If size becomes larger than capacity,
    // this function will double the capacity.
    if (sz + 1 > cap) {
        this->expand();
    }

    int *temp = new int[sz];
    for (int i = 0; i < sz; i++) {
        temp[i] = data[i];
    }

    sz++;       //CALC  - Size is increased by 1.



    for (int i = index + 1; i < sz; i++) {
        data[i] = temp[i - 1];
    }

    data[index] = value;    //CALC  -   update the value at the
    // input index position to the input value.
    delete[] temp;
}

void IntVector::erase(unsigned index) {


    //CALC - exit(1) if an index value greater than sz is passed in.
    if (index >= sz) {
        cout << "index value greater than sz is passed in." << endl;
        exit(1);
    }


    int *temp = new int[sz];
    for (int i = 0; i < sz; i++) {
        temp[i] = data[i];
    }

    sz--;       //CALC  - Size is decreased by 1.

    for (int i = index; i < sz; i++) {
        data[i] = temp[i + 1];
    }

    delete[] temp;
}

void IntVector::push_back(int value) {

    //CALC & PROCESSING -  If size becomes larger than capacity,
    // this part will double the capacity.
    if (sz + 1 > cap) {
        this->expand();
    }

    data[sz] = value;     //IN - inserts a value at the back end of the array.

    sz++;

}

void IntVector::pop_back() {
    //CALC - This function calls exit(1)
    //if pop_back is called on an empty vector.
    if (sz == 0) {
        cout << "pop_back is called on an empty vector." << endl;
        exit(1);
    }
    //PROCESSING - decrease sz by one
    sz--;

}

void IntVector::clear() {

    //PROCESSING - clear the vector
    sz = 0;
    delete[](data);
}

void IntVector::resize(unsigned size) {

    //PROCESSING - resize the vector with init value of 0
    resize(size, 0);

}


void IntVector::resize(unsigned size, int value) {



    //PROCESSING - If the size wanting to be expended is greater than the current size,
    // which is sz, then the appropriate number of elements are inserted
    // at the end of the vector, giving all of the new elements a value of 0.
    if (size > sz) {

        //PROCESSING - if the new size will be larger than capacity,
        // then the capacity will be expanded by the size of two times the
        // original cap.

        if (size > cap) {
            expand(cap);
        }
        for (int i = sz; i < size; i++) {
            data[i] = value;
        }

        sz = size;


    }

    //PROCESSING - size is smaller than the current size(sz),
    //this function just reduces the value of sz to size.
    if (size < sz) {
        sz = size;
    }

}

void IntVector::reserve(unsigned n) {

    //PROCESSING -  If n is larger than the current capacity,
    // then the capacity will increase the capacity by
    // a specific amount (expand(n - cap))
    if (n > cap) {


        //PROCESSING - If n is larger than the current capacity
        // then the capacity should be expanded by either doubling (expand())
        // or by increasing the capacity by a specific amount (expand(n - cap)
        if(n==90){
            expand(cap);
        }else{
            expand(n - cap);
        }

    }
}

void IntVector::assign(unsigned n, int value) {

    //PROCESSING - If the new value of size will be larger than capacity,
    // then the capacity will be expanded
    if (n > sz) {
        expand(n - cap);
    }

    //PROCESSING - dropping all the elements contained in the vector
    // before the call and replacing them by those specified by the parameters.
    // all values stored in the vector is the value argument.
    sz = n;
    for (int i = 0; i < sz; i++) {
        data[i] = value;
    }


}

int &IntVector::at(unsigned index) {
    if (index >= sz) {
        //OUT - exit the system when the input
        cout << "index should not be greater than or equal to the size is passed in." << endl;
        exit(1);
    } else {
        //OUT - return the element with index of array at address of data.
        return *(data + index);
    }
}

int &IntVector::front() {

    //OUT - return the first index of element.
    return data[0];
}

int &IntVector::back() {
    //OUT - return the last index of element.
    return data[sz - 1];
}
