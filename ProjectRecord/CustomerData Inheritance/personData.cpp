#include <utility>

//
// Created by JonathanSum on 5/7/2019.
//

#include "personData.h"
#include <iostream>

using namespace std;


/***************************************************
 *
 *   PersonData(string last, string first ):PersonData
 ________________________________________________
 *   This Constructor initial a personal data
 *   with last name and first name
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   A constructor is created
*****************************************************/
PersonData::PersonData(string last,         //IN - last name
                        string first         //IN - first name
        ) {
    lastName = last;        //PROCESSING - setting the last name
    firstName = first;        //PROCESSING - setting the first name
}

/***************************************************
 *
 *   string getName() const:PersonData
 ________________________________________________
 *   This function return the name
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   A string is returned
*****************************************************/
string PersonData::getName() const {
    return (firstName + " " + lastName);
}
/***************************************************
 *
 *   void setName() const:PersonData
 ________________________________________________
 *   This function sets the name
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   A name is changed
*****************************************************/
void PersonData::setName(string f, string l) {
    firstName = move(f);
    lastName = move(l);
}
/***************************************************
 *
 *    string getAddress() const:PersonData
 ________________________________________________
 *   This function get the address
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An address is returned
*****************************************************/
string PersonData::getAddress() const {

    return (address+" "+city+", "+state+" "+to_string(zip));
}

/***************************************************
 *
 *   void setAddress(string a, string c, string s, unsigned z): Class PersonData
 ________________________________________________
 *   This function sets the address
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An address is changed
*****************************************************/
void PersonData::setAddress(string a, string c, string s, unsigned z) {
    address = move(a);
    city = move(c);
    state = move(s);
    zip = z;
}
/***************************************************
 *
 *   Method PersonData(string last, string first, string a, string c, string s,
                       unsigned z, long p): Class PersonData
 ________________________________________________
 *   This Constructor initial a personal data
 *   with last name and first name
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   A constructor is created
*****************************************************/
PersonData::PersonData(string last, string first, string a, string c, string s,
                       unsigned z, long p) {
    lastName = std::move(last);
    firstName = std::move(first);
    address = std::move(a);
    city = std::move(c);
    state = std::move(s);
    zip = z;
    phone = p;

}
/***************************************************
 *
 *   setPhone(unsigned p): Class PersonData
 ________________________________________________
 *   This function sets the Phone
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An Phone is changed
*****************************************************/
void PersonData::setPhone(unsigned p) {
    phone = p;
}

/***************************************************
 *
 *   long getPhone() const: Class PersonData
 ________________________________________________
 *   This function sets the Phone
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   An Phone is returned
*****************************************************/
long PersonData::getPhone() const {

    return phone;
}

/***************************************************
 *
 *   void set_contact_info(string a,string c, string s, unsigned z, long p) : Class PersonData
 ________________________________________________
 *   This function sets the contact_info
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   contact_info is changed
*****************************************************/
void PersonData::set_contact_info(string a,string c, string s, unsigned z, long p) {
    address = a;
    city = c;
    state = s;
    zip = z;
    phone = p;
}
/***************************************************
 *
 *   PersonData():PersonData
 ________________________________________________
 *   it ini the name
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   A constutor is changed
*****************************************************/
PersonData::PersonData(): lastName(""),firstName("") {

}
