//
// Created by gn-00 on 5/14/2019.
//

#ifndef ZEROTWO_STUDENT_H
#define ZEROTWO_STUDENT_H

#include <iostream>
#include <vector>
#include "date.h"

using namespace std;

class Student {
public:
    //student’s name, student’s Id, phone number, age, gender, class standing, and GPA.
    /**************************************
    **      CONSTRUCTOR AND DESTRUCTOR    **
    ***************************************/
    Student();

    Student(string name, unsigned the_id, string the_phone, int the_age,
            char the_gender, string the_standing, double the_gpa);

    virtual ~Student();

    /**********************
       * * ACCESSORS **
    **********************/
    virtual void print() const;

    /**********************
         * * MUTATORS **
    **********************/
    void setName(string n);

    void setId(unsigned the_id);

    void setPhone(string p);

    void setAge(int year);

    void setStanding(string level);

    void setGPA(double gradePoint);

    void setGender(char g);

    virtual void setTotalScore(unsigned score) {};

    virtual void setJavaKnowledge(bool yes) {};

    virtual void setGraduationDate(const Date &the_date) {};
protected:
    string studentName;     //IN - student's name
    unsigned id;     //IN - student's id
    string phone;     //IN - student's phone
    int age;     //IN - student's age
    char gender;     //IN - student's gender
    string classStanding;     //IN - student's class standing
    double gpa;     //IN - student's gpa
};
/*********************************************************************
   * Student  Class
   * This class represents a Student  object.
   * It manages 7 attributes,
   * string studentName;     //IN - student's name
   * unsigned id;     //IN - student's id
   * string phone;     //IN - student's phone
   * int age;     //IN - student's age
   * char gender;     //IN - student's gender
   * string classStanding;     //IN - student's class standing
   * double gpa;     //IN - student's gpa
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  Student();
 *  Constructor;    Initialize class attributes and setting them to the
 *  default value
 *  Parameter: none
 *  Return: Student object
*********************************************************************/
/*********************************************************************
 *  Student(string name, unsigned the_id, string the_phone,
 *  int the_age, char the_gender,
 *  string the_standing, double the_gpa);
 *  Constructor;    Initialize class attributes and by setting
 *  all attributes by the arguments are passed in.
 *  default value
 *  Parameter: none
 *  Return: Student object
*********************************************************************/
/*********************************************************************
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~Student();
 *  Destructor;   print on the screen that default destructor is
 *  called
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/

/*********************************************************************
 * virtual void print () const;
 * Accessors: it prints all the value of the class
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 * void setName(string n);
 * Mutator: setting the student name attribute by the argument n
 *--------------------------------------------------------------------
 * Parameter: string n      //IN - student name
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setId(unsigned the_id);
 * Mutator: setting the student id attribute by the argument the_id
 *--------------------------------------------------------------------
 * Parameter: unsigned the_id       //IN - student id
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setPhone(string p);
 * Mutator: setting the phone number by the argument p
 *--------------------------------------------------------------------
 * Parameter: string p     //IN - student's phone number
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setAge(int year);
 * Mutator: setting the age by the argument year
 *--------------------------------------------------------------------
 * Parameter: int year   //IN - student's age
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setStanding(string level);
 * Mutator: setting the class standing by the argument level
 *--------------------------------------------------------------------
 * Parameter: string level     //IN - student's class standing
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setGPA(double gradePoint);
 * Mutator: setting the gpa by the argument gradePoint
 *--------------------------------------------------------------------
 * Parameter: double gradePoint     //IN - student's gpa
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setGender(char g);
 * Mutator: setting the gender by the argument g
 *--------------------------------------------------------------------
 * Parameter: char g     //IN - student's gender
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * virtual void setTotalScore(unsigned score);
 * Mutator: setting the TotalScor
 *--------------------------------------------------------------------
 * Parameter: unsigned score     //IN - TotalScor
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * virtual void setJavaKnowledge(bool yes);
 * Mutator: setting the JavaKnowledge
 *--------------------------------------------------------------------
 * Parameter: bool yes    //IN - JavaKnowledge
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * virtual void setGraduationDate(const Date &the_date);
 * Mutator: setting the Graduation date
 *--------------------------------------------------------------------
 * Parameter: const Date &the_date    //IN - Graduation date
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/


#endif //ZEROTWO_STUDENT_H
