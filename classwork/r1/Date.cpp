/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 03 - Date Class
 *   SECTION        : CS 003A
 *   Due Date       : 3/17/19
 *   ________________________________________________
 *   Goals: To print out date in correct format

***********************************************/

#include "Date.h"
#include <iostream>

using namespace std;
//   This method will print the date in a Numeric format
void Date::printNumeric() const {
    cout<<month<<"/"<<day<<"/"<<year;
}

//   This method will print the date in a Alpha format
void Date::printAlpha() const {
    cout<<monthName<<" "<<day<<", "<<year;
}
//  This method will convert month name from number to string name
string monthNameReturn(int m){
    string monthName;
    if (m == 1) {
        monthName = "January";
    } else if (m == 2) {
        monthName = "February";
    } else if (m == 3) {
        monthName = "March";
    } else if (m == 4) {
        monthName = "April";
    } else if (m == 5) {
        monthName = "May";
    } else if (m == 6) {
        monthName = "June";
    } else if (m == 7) {
        monthName = "July";
    } else if (m == 8) {
        monthName = "August";
    } else if (m == 9) {
        monthName = "September";
    } else if (m == 10) {
        monthName = "October";
    } else if (m == 11) {
        monthName = "November";
    } else if (m == 12) {
        monthName = "December";
    }
    return monthName;
}
//  This method will convert month name from string to number
int MonthNumReturn(string name){
    string tempString=name;
    int month=0;
    tempString[0] = tolower(tempString[0]);
    if (tempString == "january") {
        month = 1;

    } else if (tempString == "february") {
        month = 2;
    } else if (tempString == "march") {
        month = 3;

    } else if (tempString == "april") {
        month = 4;

    } else if (tempString == "may") {
        month = 5;

    } else if (tempString == "june") {
        month = 6;

    } else if (tempString == "july") {
        month = 7;

    } else if (tempString == "august") {
        month = 8;

    } else if (tempString == "september") {
        month = 9;

    } else if (tempString == "october") {
        month = 10;

    } else if (tempString == "november") {
        month = 11;

    } else if (tempString == "december") {
        month = 12;
    }
    return month;
}


