//
// Created by gn-00 on 5/14/2019.
//

#ifndef ZEROTWO_CS003ASTUDENT_H
#define ZEROTWO_CS003ASTUDENT_H

#include "student.h"
#include <iostream>
#include <vector>
#include "date.h"

using namespace std;

class CS003AStudent : public Student {
public:


    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    CS003AStudent();

    CS003AStudent(string the_name, unsigned the_id, string the_phone, int the_age,
                  char the_gender, string the_standing, double the_gpa, unsigned the_score,
                  bool the_java, Date the_graduation_date);
    ~CS003AStudent() override;

    /**********************
       * * ACCESSORS **
    **********************/

    string getJava() const;

    void getGDate() const;
    void print() const override;

    /**********************
         * * MUTATORS **
    **********************/
    void setTotalScore(unsigned score) override;

    void setJavaKnowledge(bool yes) override;

    void setGraduationDate(const Date &the_date) override;



protected:
    unsigned totalScore;     //OUT - Total score on the student’s assignments
    bool javaKnowledge;    //CALC - Knowledge of Java
    Date graduationDate;    // OUT - Projected graduation date

};
/*********************************************************************
   * CS003AStudent  Class
   * This class represents a CS003AStudent  object.
   * It manages 3 attributes,
   * unsigned totalScore;     //OUT - Total score on the student’s assignments
   * bool javaKnowledge;    //CALC - Knowledge of Java
   * Date graduationDate;    // OUT - Projected graduation date
*********************************************************************/
/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
/*********************************************************************
*   CS003AStudent();
 *  Constructor;    Initialize class attributes and setting them to the
 *  default value
 *  Parameter: none
 *  Return: Student object
*********************************************************************/
/*********************************************************************
*   CS003AStudent(string the_name, unsigned the_id, string the_phone, int the_age,
    char the_gender, string the_standing, double the_gpa, unsigned the_score,
    bool the_java, Date the_graduation_date);
 *  Constructor;    Initialize class attributes and setting them to the
 *  value by the arguments passing in
 *  Parameter: none
 *  Return: CS003AStudent object
*********************************************************************/
/*********************************************************************
                         **      DESTRUCTOR   **
*********************************************************************/
/*********************************************************************
*   ~CS003AStudent();
 *  Destructor;   printing on the screen that destructor is called
 *  Parameter: none
 *  Return: CS003AStudent object
*********************************************************************/


/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/
/*********************************************************************
*   string getJava() const;
 *  Accessors;   get Java boolean of the class attributes(javaKnowledge)
 *  Parameter: none
 *  Return: javaKnowledge boolean
*********************************************************************/
/*********************************************************************
*   void getGDate() const;
 *  Accessors; printing the graduationDate object
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
*   void print() const override;
 *  Accessors; printing the cs003AStudent object
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
*   void setTotalScore(unsigned score) override;
 *  Mutator; setting the total scroe
 *  Parameter: unsigned scor    //IN - total score
 *  Return: none
*********************************************************************/
/*********************************************************************
*   void setJavaKnowledge(bool yes) override;
 *  Mutator; setting the JavaKnowledge
 *  Parameter: bool yes    //IN - the booleanJavaKnowledge boolean to be change
 *  Return: none
*********************************************************************/
/*********************************************************************
*  void setGraduationDate(const Date &the_date) override;
 *  Mutator; changing the GraduationDate object
 *  Parameter: const Date &the_date
 *  Return: none
*********************************************************************/

#endif //ZEROTWO_CS003ASTUDENT_H
