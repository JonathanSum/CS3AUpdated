//
// Created by JonathanSum on 3/9/2019.
//

#ifndef INC_3A_DATE_H
#define INC_3A_DATE_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string monthNameReturn(int m);
class Date {
private:
    unsigned day;
    unsigned month;
    string monthName;
    unsigned year;
public:
    Date() {        //default constructor: creates the date January 1st, 2000.
        day = 1;
        year = 2000;
        monthName = "January";
        month = 1;
    }

//    January, February, March, April, May, June, July, August, September, October, November, December
//cout<<"Invalid date values: Date corrected to 12/31/2010."<<endl;
    Date(unsigned m, unsigned d,
         unsigned y) {         // parameterized constructor: month number, day, year - e.g. (3, 1, 2010) would construct the date March 1st, 2010
        if (m > 12 || m < 1 || d > 31 || d < 1 || y < 0 || (m == 2 && d > 28)) {
            cout << "Debug Secontion started\n";
//            cout << "Debug m: " << m << endl;
//            cout << "Debug: month " << month << endl;
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
            //debug invalid day
            cout << "Debug d: " << d << endl;
            if (d < 1) {
                cout << "Invalid date values: Date corrected to " << month << "/" <<"1" << "/" << y << "." << endl;
                day = 1;
                monthName=monthNameReturn(m);
            }
            if (d > 31 && m != 2) {
                monthName=monthNameReturn(m);
                if (m % 2 == 0) {
                    day = 30;
                } else if (m % 2 != 0) {
                    day = 31;
                }
                cout << "Invalid date values: Date corrected to " << month << "/" <<"31" << "/" << y << "." << endl;
            } else if (m == 2 && year % 4 == 0) {
                month = 2;
                monthName = "February";
                day = 29;
                cout << "Invalid date values: Date corrected to " << month << "/" <<day << "/" << y << "." << endl;
            } else if (m == 2 && year % 4 != 0) {
                month = 2;
                monthName = "February";
                day = 28;
                cout << "Invalid date values: Date corrected to " << month << "/" <<day << "/" << y << "." << endl;
            }

//            cout << "Debug: month " << month << endl;
//            cout << "Debug: month " << day << endl;
        } else {
//            cout << "Debug Section did not started\n";
            month = m;
            day = d;
            year = y;
            monthName=monthNameReturn(m);
        }


    }

    Date(
            const string &mn,
            unsigned d,
            unsigned y) {
        string tempString = mn;
        tempString[0] = tolower(tempString[0]);
//        transform(mn.begin(), mn.end(), mn.begin(), ::toupper);


        monthName = mn;
        if (d < 0 || d > 31 || y < 0) {
            monthName = "January";
            month = 1;
            day = 1;
            year = 2000;
        } else {
            day = d;
            year = y;
        }



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

    void printNumeric() const;

    void printAlpha() const;
};


#endif //INC_3A_DATE_H
