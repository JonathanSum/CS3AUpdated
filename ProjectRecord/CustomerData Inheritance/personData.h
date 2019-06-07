//
// Created by JonathanSum on 5/7/2019.
//
/*********************************************
*   Author         : Jonathan Sum
*   Assignment     : Lab 16 Specifications
*   SECTION        : CS 003A
*   Due Date       : 5/13/19
*   ________________________________________________
*   Goal: write a base class with its child class
***********************************************/

#ifndef INC_3A_PERSONDATA_H
#define INC_3A_PERSONDATA_H

#include <iostream>

using namespace std;



class PersonData {
    public:
    /*********************************************************************
                         **      CONSTRUCTOR   **
    *********************************************************************/
        PersonData();
        PersonData(string last, string first);
        PersonData(string last, string first,string a,string c, string s, unsigned z, long phone);
    /**********************
         * * MUTATORS **
    **********************/
    void setName(string f, string l);
    void set_contact_info(string a,string c, string s, unsigned z, long p);
protected:
        string lastName;        //IN - last name
        string firstName;       //IN - first name
        string address;       //IN - street name
        string city;       //IN - city name
        string state;       //IN - state name
        unsigned zip;       //IN - zip code
        long phone;       //IN - phone number
    /**********************
        * * ACCESSORS **
    **********************/
        string getName() const;
        string getAddress()const;
        long getPhone()const;
    /**********************
         * * MUTATORS **
    **********************/
        void setAddress(string a, string c, string s, unsigned z);
        void setPhone(unsigned p);

};
/*********************************************************************
   * PersonData Class
   * This class represents a PersonData object.
   * It manages 7 attributests,
   * first name and last name
   * address
   * phone number
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
/*********************************************************************
 *  PersonData();
 *  Constructor;    Initialize class attributes
 *  on customer's contact information
 *  Parameter: none
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
 *  PersonData(string last, string first);
 *  Constructor;    Initialize class attributes by initializing the
 *  last name and first name
 *  Parameter: string last   //IN - last name
 *  , string first   //IN - first
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
 * PersonData(string last, string first,string a,string c, string s, unsigned z, long phone);
 *  Constructor;    Initialize class attributes by initializing the
 *  last name,first name and the address
 *  Parameter: string last      //IN - last name
 *  , string first      //IN - first name
 *  ,string a      //IN - street name
 *  ,string c      //IN - city
 *  , string s      //IN - state
 *  , unsigned z     //IN - zip code
 *  , long phone     //IN - phone number
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/
/*********************************************************************
 *  string getName() const;;
 *  Accessors:    function for returning the last name and first name
 *  Parameter: none
 *  Return: full name in string
*********************************************************************/
/*********************************************************************
 *  string getAddress()const;
 *  Accessors:    function for returning full address
 *  Parameter: none
 *  Return: full address in string
*********************************************************************/
/*********************************************************************
 *  long getPhone()const;
 *  Accessors:    function for returning full phone number
 *  Parameter: none
 *  Return: full phone number in long data type
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 *  void setAddress(string a, string c, string s, unsigned z);
 *  Mutators:  changing or setting the address
 *  Parameter: string a,    //IN - street name
 *  string c,    //IN - city
 *  string s,    //IN - state
 *  unsigned z    //IN - zip code
 *  Return: none
*********************************************************************/
/*********************************************************************
 *  void setPhone(unsigned p);
 *  Mutators:  changing or setting the phone number
 *  Parameter: unsigned p,    //IN -phone number
 *  Return: none
*********************************************************************/


#endif //INC_3A_PERSONDATA_H
