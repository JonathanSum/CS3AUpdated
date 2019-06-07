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

#ifndef INC_3A_CUSTOMERDATA_H
#define INC_3A_CUSTOMERDATA_H

#include "personData.h"

class CustomerData: virtual public PersonData {
    public:
    /*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
        CustomerData();
        CustomerData(int the_customer_number, bool the_mailing_list);
    /**********************
        * * ACCESSORS **
    **********************/
        bool willMail() const;
        int getId() const;
    /**********************
         * * MUTATORS **
    **********************/
        void setMail(bool mail);
         void setId(int id);
    protected:
        int customerNumber;     //IN id number
        bool mailingList;       //IN mailling list will be sent or not


};
/*********************************************************************
   * CustomerData Class
   * This class represents a PersonData object.
   * It manages 2 attributests,
   * id and milling list will be sent or not
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
/*********************************************************************
 *  CustomerData();
 *  Constructor;    Initialize class attributes
 *  on id and milling list will be sent or not
 *  Parameter: none
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
 *  CustomerData(int the_customer_number, bool the_mailing_list);
 *  Constructor;    Initialize class attributes
 *  on id and milling list will be sent or not
 *  Parameter: Id and mailing list
 *  Return: Constructor
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/
/*********************************************************************
 * void display() const;
 * Accessors: return the will sent or not sent boolean
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: boolean
*********************************************************************/
/*********************************************************************
 * int getId() const;
 * Accessors: return the id
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: int
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 * void setMail(bool mail);
 * Mutator: set the mail will sent or not
 *--------------------------------------------------------------------
 * Parameter: value // IN - boolean for sent or not
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setId(int id);
 * Mutator: set the id
 *--------------------------------------------------------------------
 * Parameter: value // IN - id
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

#endif //INC_3A_CUSTOMERDATA_H
