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

#ifndef INC_3A_PREFERREDCUSTOMER_H
#define INC_3A_PREFERREDCUSTOMER_H

#include "customerData.h"

class PreferredCustomer : public CustomerData  {
    public:
    /*********************************************************************
                         **      CONSTRUCTOR   **
    *********************************************************************/
        PreferredCustomer() : purchasesAmount(0), discountLevel(0) {}
        PreferredCustomer(double purch);
        PreferredCustomer(string last, string first, string a, string c, string s,
                          unsigned z, long phone, int the_customer_number,
                          bool the_mailing_list, double the_purchases_amount);
                /**********************
                 * * MUTATORS **
                **********************/
         void add_TotalBuy(double amount,string product);
            /**********************
                * * ACCESSORS **
            **********************/
         void printData()const;
    protected:
        double purchasesAmount;         //IN - It holds
        // the total of a customer’s purchases to date.
        double discountLevel;           //IN - It sets to the correct discount percentage, according to
        //the store’s preferred customer plan
                /**********************
                    * * MUTATORS **
                **********************/
        double getOffLevel() const;
        double getTotalBuy()const;
                /**********************
                    * * ACCESSORS **
                **********************/
        void setTotalBuy(double t);


};

/*********************************************************************
   * PreferredCustomer Class
   * This class represents a PersonData object.
   * It manages 2 attributests,
   * discount level
   * purchasesAmount
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
/*********************************************************************
 *  PreferredCustomer();
 *  Constructor;    Initialize class attributes
 *  on customer's contact information
 *  Parameter: none
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
 *   PreferredCustomer(double purch);
 *  Constructor;    Initialize class attributes by initializing the
 *  purchasesAmount
 *  Parameter: purch   //IN - purchasesAmount
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
 *  PreferredCustomer(string last, string first, string a, string c, string s,
                          unsigned z, long phone, int the_customer_number,
                          bool the_mailing_list, double the_purchases_amount);
 *  Constructor;    Initialize class attributes by initializing the
 *  all information
 *  Parameter: string last,         //IN  - last name
                string first,         //IN - first name
                string a,         //IN -  street name
                string c,         //IN  - city name
                string s,         //IN  - state name
                unsigned z,         //IN -  zip code
                long phone,         //IN  - phone number
                int the_customer_number,         //IN - ID number
                bool the_mailing_list,         //IN - mail will sent or not
                double the_purchases_amount         //IN - purchases amount
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/
/*********************************************************************
 *  void add_TotalBuy(double amount,string product);
 *  Accessors:    change the total buy amount
 *  Parameter: double amount,   //IN - amount he or she has bought
            string product                    // IN - name of product
 *  Return: none
*********************************************************************/
/*********************************************************************
 *  void printData() const;
 *  Accessors:    print the whole customer information
 *  Parameter: none
 *  Return: none
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
 *  double getOffLevel() const;;
 *  Mutators:  return the discount level
 *  Parameter: none
 *  Return:  discount level
*********************************************************************/
/*********************************************************************
 *  double getTotalBuy()const;
 *  Mutators:  return the total purchase amount
 *  Parameter: none
 *  Return: total purchase amount
*********************************************************************/
#endif //INC_3A_PREFERREDCUSTOMER_H
