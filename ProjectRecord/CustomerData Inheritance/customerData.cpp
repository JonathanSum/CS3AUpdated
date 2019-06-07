#include <utility>

//
// Created by JonathanSum on 5/7/2019.
//

#include <iostream>
#include "customerData.h"
using namespace std;
/***************************************************
 *
 *  CustomerData(): Class CustomerData
 ________________________________________________
 *   it init the mailing list and id number
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An object is returned
*****************************************************/
CustomerData::CustomerData() : mailingList(false), customerNumber(0) {
}

/***************************************************
 *
 *  setId: Class CustomerData
 ________________________________________________
 *   it sets the id
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An id is changed
*****************************************************/
void CustomerData::setId(int id) {
    customerNumber = id;
}
/***************************************************
 *
 *  willMail() const: Class CustomerData
 ________________________________________________
 *   it return the mailingList boolean
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An boolean is returned
*****************************************************/
bool CustomerData::willMail() const {
    return mailingList;
}
/***************************************************
 *
 *  CustomerData(int the_customer_number, bool the_mailing_list):
              customerNumber(the_customer_number): Class CustomerData
 ________________________________________________
 *   it return an object
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An object is returned
*****************************************************/
CustomerData::CustomerData(int the_customer_number, bool the_mailing_list):
              customerNumber(the_customer_number),
              mailingList(the_mailing_list) {
}
/***************************************************
 *
 *  getId() const Class CustomerData
 ________________________________________________
 *   it return the id
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   id is returned
*****************************************************/
int CustomerData::getId() const {
    return customerNumber;
}
/***************************************************
 *
 *  setMail: Class CustomerData
 ________________________________________________
 *   it sets the mailingList boolean
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An boolean is returned
*****************************************************/
void CustomerData::setMail(bool mail) {
    mailingList = mail;
}
