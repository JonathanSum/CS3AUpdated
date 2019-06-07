/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 03 - Date Class
 *   SECTION        : CS 003A
 *   Due Date       : 3/17/19
 *   ________________________________________________
 *   Goals: To print out date in correct format

***********************************************/
#ifndef INC_3A_DATE_H
#define INC_3A_DATE_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string monthNameReturn(int m        //INPUT for month
);
int MonthNumReturn(string name      //INPUT for name of month
);
void monthNumReturn(string &tempString      //INPUT a temp string for storing a string in the loop
        , int &month                        //INPUT month in number
        , int &year                         //INPUT year in number
        , int &day                          //INPUT day in number
        , string monthName)                 //INPUT month in name in string
        ;
/**********************
   * * Date Class**
   * This struct represents a
   *  Date Class. It manages 4 attributest,
   * day, month, name of month, and year
**********************/
class Date {
private:
    /**********************
       * * ACCESSORS **
    **********************/
    unsigned day;           //IN day
    unsigned month;         //IN month
    string monthName;        //IN month in name of string
    unsigned year;          //IN year in number


public:
    /**********************
       * * CONSTRUCTOR **
    **********************/

/**********************
 * Date();
 * Constructor; Initialize class attributes
 *  Parameters: none
 *  return none
**********************/
    Date() {                    //default constructor: creates the date January 1st, 2000.
        day = 1;                    //IN day
        year = 2000;                     //IN Year
        monthName = "January";       //IN Month
        month = 1;
    }


/********************************************
    *      Date(unsigned m,        //IN Month
         unsigned d,        //IN Day
         unsigned y         //IN Year
         )
     * Constructor; Parameterized constructor, this will set the private varibles, month, day, year with from the input values.
     *  Parameters: unsigned m,        //IN Month
                     unsigned d,        //IN Day
                     unsigned y         //IN Year
     *  return none
********************************************/
    Date(unsigned m,
         unsigned d,
         unsigned y
         ) {




        //PROCESSING:  Debug first, if month is greater than 12 or less than 1, day is less than one or greater than 31, year is less than 0, or day is greater than 28 in Feb
        if (m > 12 || m < 1 || d > 31 || d < 1 || y < 0 || (m == 2 && d > 28)) {

            day = d;
            year = y;
            month = m;

            if (m < 1) {
                cout << "Invalid date values: Date corrected to 1/" << day << "/" << y << "." << endl;                  //OUTPUT        correcting the error input of the date class
                month = 1;
                monthName = "January";
                m = 1;

            } else if (m > 31) {
                cout << "Invalid date values: Date corrected to 12/" << day << "/" << y << "." << endl;                 //OUTPUT        correcting the error input of the date class
                month = 12;
                monthName = "December";
                m = 12;
            }
            //debug invalid day
            if (d < 1) {
                cout << "Invalid date values: Date corrected to " << month << "/" << "1" << "/" << y << "." << endl;    //OUTPUT        correcting the error input of the date class
                monthName = monthNameReturn(m);
                day = 1;
            }
            if (d > 31 && m != 2) {
                if (m % 2 == 0) {
                    monthName = monthNameReturn(m);
                    day = 31;
                } else if (m % 2 != 0) {
                    monthName = monthNameReturn(m);
                    day = 31;
                }
                cout << "Invalid date values: Date corrected to " << month << "/" << "31" << "/" << y << "." << endl;       //OUTPUT        correcting the error input of the date class
            } else if (m == 2 && year % 4 == 0) {
                month = 2;
                monthName = "February";
                day = 29;
                cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;        //OUTPUT        correcting the error input of the date class
            } else if (m == 2 && year % 4 != 0) {
                month = 2;
                monthName = "February";
                day = 28;
                cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;        //OUTPUT        correcting the error input of the date class
            }


        } else {                       //OUTPUT:   set the month, day, and year to the private section of the class if they are passed the debug section.

            month = m;
            day = d;
            year = y;
            monthName = monthNameReturn(m);
        }


    }
/********************************************
    *      Date(const string &mn,
            unsigned d,
            unsigned y)
     * Constructor; Parameterized constructor, this will set the private varibles, month, day, year with from the input values.
     *  Parameters: const string &mn,          //IN month name
                    unsigned d,                //day in number
                    unsigned y)                //year in number
     *  return none
********************************************/
    Date(const string &mn,
            unsigned d,
            unsigned y)
        {
        string tempString = mn;
        tempString[0] = tolower(tempString[0]);

        int m =MonthNumReturn(mn);       //OUT  It will return to 0 if the name is not in the month list in English, else it will convert month name in string to number of the month.



//PROCESSING if incorrected date values were input
        if ( d > 31 || d < 1 || y < 0 || (m == 2 && d > 28)) {

            day = d;
            year = y;
            month = m;

            if (m < 1) {
                cout << "Invalid date values: Date corrected to 1/" << day << "/" << y << "." << endl;
                month = 1;
                monthName = "January";
                m = 1;

            } else if (m > 31) {
                cout << "Invalid date values: Date corrected to 12/" << day << "/" << y << "." << endl;
                month = 12;
                monthName = "December";
                m = 12;
            }

            if (d < 1) {
                cout << "Invalid date values: Date corrected to " << month << "/" << "1" << "/" << y << "." << endl;
                monthName = monthNameReturn(m);
                day = 1;
            }
            if (d > 31 && m != 2) {
                if (m % 2 == 0) {
                    monthName = monthNameReturn(m);
                    day = 31;
                } else if (m % 2 != 0) {
                    monthName = monthNameReturn(m);
                    day = 31;
                }
                cout << "Invalid date values: Date corrected to " << month << "/" << "31" << "/" << y << "." << endl;
            } else if (m == 2 && year % 4 == 0) {
                month = 2;
                monthName = "February";
                day = 29;
                cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;
            } else if (m == 2 && year % 4 != 0) {
                month = 2;
                monthName = "February";
                day = 28;
                cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;
            }

        }  else {
            day = d;
            year = y;
        }

        //PROCESSING last check for month name
        if (tempString == "january") {
            month = 1;
            monthName = "January";
        } else if (tempString == "february") {
            month = 2;
            monthName = "February";
        } else if (tempString == "march") {
            month = 3;
            monthName = "March";
        } else if (tempString == "april") {
            month = 4;
            monthName = "April";
        } else if (tempString == "may") {
            month = 5;
            monthName = "May";
        } else if (tempString == "june") {
            month = 6;
            monthName = "June";
        } else if (tempString == "july") {
            month = 7;
            monthName = "July";
        } else if (tempString == "august") {
            month = 8;
            monthName = "August";
        } else if (tempString == "september") {
            month = 9;
            monthName = "September";
        } else if (tempString == "october") {
            month = 10;
            monthName = "October";
        } else if (tempString == "november") {
            month = 11;
            monthName = "November";
        } else if (tempString == "december") {
            month = 12;
            monthName = "December";
        } else {
            cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
            monthName = "January";
            month = 1;
            day = 1;
            year = 2000;
        }
    }
/********************************************
    *      void printNumeric() const;
     * Accessor; This method will print the date in a Numeric format
     *  Parameters: None
     *  return none
********************************************/
    void printNumeric() const;
/********************************************
    *     printAlpha() const
     * Accessor; This method will print the date in a Alpha format
     *  Parameters: None
     *  return none
********************************************/
    void printAlpha() const;
};


#endif //INC_3A_DATE_H
