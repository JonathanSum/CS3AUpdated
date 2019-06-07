//
// Created by zerotwo on 3/28/19.
//

#include <iostream>
#include "intVector.h"
#include <stdlib.h>

using namespace std;

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    return sz == 0;
}

const int &IntVector::at(unsigned index) const {
    if (index >= sz) {
        //OUT - exit the system when the input
        cout << "index should not be greater than or equal to the size is passed in." << endl;
        exit(1);
    } else {
        //OUT - return the element with index of array at address of data.
        return *(data + index);
    }
}

IntVector::~IntVector() {
    delete[] data;
    data = nullptr;
}

const int &IntVector::front() const {
    return *data;
}

const int &IntVector::back() const {
    return *(data + (sz - 1));
}

void IntVector::expand() {
    int *temp = nullptr;
    temp = new int[cap * 2];
    for (int i = 0; i < sz; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    temp = nullptr;
    cap += cap;
}

void IntVector::expand(unsigned amount) {
    int *temp = nullptr;
    temp = new int[cap+amount];
    for (int i = 0; i < sz; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    temp = nullptr;
    cap = amount;
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
    //CALC -  If size becomes larger than capacity,
    // this function will double the capacity.
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
    sz--;

}

void IntVector::resize(unsigned size) {

    resize(size,0);

}


void IntVector::resize(unsigned size, int value) {



    //PROCESSING - size is greater than the current size(sz),
    // then the appropriate number of elements are inserted at the end of the vector,
    // giving all of the new elements a value of 0.
    if (size > sz) {

        //PROCESSING -  the new value of size will be larger than capacity,
        // then the capacity will be expanded by the size of two times the
        // original cap.
        if (size > cap) {
            expand(size - cap);
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
    if(n>cap){
        expand(n-cap);
    }
}

