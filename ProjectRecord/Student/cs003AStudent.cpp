#include <utility>

#include <utility>

//
// Created by gn-00 on 5/14/2019.
//

#include "cs003AStudent.h"

/*****************************************************
 *
 *   setJavaKnowledge(bool yes): Class cs003AStudent
 ________________________________________________
 *   setting the student javaKnowledge
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   javaKnowledge attribute is changed
*****************************************************/
void CS003AStudent::setJavaKnowledge(bool yes) {
    javaKnowledge = yes;
}
/*****************************************************
 *
 *   setTotalScore(unsigned score): Class cs003AStudent
 ________________________________________________
 *   setting the student totalScore
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   totalScore attribute is changed
*****************************************************/
void CS003AStudent::setTotalScore(unsigned score) {
    totalScore = score;
}
/*****************************************************
 *
 *   setGraduationDate(const Date &the_date): Class cs003AStudent
 ________________________________________________
 *   setting the student graduationDate
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   graduationDate attribute is changed
*****************************************************/
void CS003AStudent::setGraduationDate(const Date &the_date) {
    graduationDate = the_date;
}


/*****************************************************
 *
 *   print() const: Class cs003AStudent
 ________________________________________________
 *   printing the cs003A student's all information
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *    cs003A student's all information is printed
*****************************************************/
void CS003AStudent::print() const {

    cout<<studentName<<" "<<id<<" "<<phone<<" "<<age<<" "<<gender<<" "<<classStanding<<" "
    <<gpa<<" "<<totalScore<<" "<<getJava()<<" ";
    getGDate();
    cout<<endl;

}
/*****************************************************
 *
 *   getJava(): Class cs003AStudent
 ________________________________________________
 *   returning Yes or No based on the javaKnowledge
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   returned a string that is yes or no
*****************************************************/
string CS003AStudent::getJava() const {
    if(javaKnowledge){
        return "yes";
    }else{
        return "no";
    }
}
/*****************************************************
 *
 *   getGDate() cons: Class cs003AStudent
 ________________________________________________
 *   printing the graduationDate in Numeric
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   graduationDate is printed in Numeric.
*****************************************************/
void CS003AStudent::getGDate() const {
    graduationDate.printNumeric();
}
/*****************************************************
 *
 *   ~CS003AStudent(): Class cs003AStudent
 ________________________________________________
 *   calling the destructor
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   destructor is called
*****************************************************/
CS003AStudent::~CS003AStudent() {
    cout<<"Called CS133Student destructor"<<endl;
}
/*****************************************************
 *
 *   CS003AStudent(): Class cs003AStudent
 ________________________________________________
 *   initialize a CS003AStudent object
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   CS003AStudent object is created
*****************************************************/
CS003AStudent::CS003AStudent() {
    studentName = "Name";
    id = 0;
    phone = "00-000-0000";
    age =0;
    gender = 'X';
    classStanding = "classStanding";
    gpa = 0;
    totalScore=0;
    javaKnowledge=false;
    graduationDate = Date();
}
/*****************************************************
 *
 *   CS003AStudent(): Class cs003AStudent
 ________________________________________________
 *   initialize a CS003AStudent object
 *   by all the arguments passingin
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   CS003AStudent object is created
*****************************************************/
CS003AStudent::CS003AStudent(string the_name, unsigned the_id, string the_phone,
        int the_age, char the_gender,string the_standing,double the_gpa, unsigned the_score,
                             bool the_java, Date the_graduation_date): Student(std::move(the_name),
                                     the_id, std::move(the_phone),
                                     the_age, the_gender, std::move(the_standing), the_gpa) {
            totalScore = the_score;
            javaKnowledge = the_java;
            graduationDate = std::move(the_graduation_date);
}
