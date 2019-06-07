#include <utility>


#include "student.h"

/*****************************************************
 *
 *   setName(string n): Class Student
 ________________________________________________
 *  setting the student name
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   studentName is changed
*****************************************************/
void Student::setName(string n) {
    studentName = std::move(n);

}
/*****************************************************
 *
 *   setId(unsigned the_id): Class Student
 ________________________________________________
 *  setting the student id
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   id is changed
*****************************************************/
void Student::setId(unsigned the_id) {
    id = the_id;
}
/*****************************************************
 *
 *   setPhone(string p): Class Student
 ________________________________________________
 *  setting the student id
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   id is changed
*****************************************************/
void Student::setPhone(string p) {
    phone = std::move(p);
}
/*****************************************************
 *
 *   setAge(int year): Class Student
 ________________________________________________
 *  setting the student age
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   age is changed
*****************************************************/
void Student::setAge(int year) {
    age = year;
}
/*****************************************************
 *
 *   setStanding(string level): Class Student
 ________________________________________________
 *  setting the student age
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   classStanding is changed
*****************************************************/
void Student::setStanding(string level) {
    classStanding = std::move(level);
}
/*****************************************************
 *
 *   setGPA(double gradePoint): Class Student
 ________________________________________________
 *  setting the student gpa
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   gpa is changed
*****************************************************/
void Student::setGPA(double gradePoint) {
    gpa = gradePoint;
}

/*****************************************************
 *
 *  print() const: Class Student
 ________________________________________________
 *  printing student's information
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   student's information is printed
*****************************************************/
void Student::print() const {
    cout << studentName << " " << id << " " << phone << " " << age << " " << gender << " " << classStanding << " "
         << gpa << endl;
}
/*****************************************************
 *
 *  ~Student(): Class Student
 ________________________________________________
 *   destructors for student class
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   an information that student class is destoried
 *   is printed
*****************************************************/
Student::~Student() {
    cout << "Called Student destructor" << endl;
}
/*****************************************************
 *
 *  Student(): Class Student
 ________________________________________________
 *   constructors for student class
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   a  student class object is returned
*****************************************************/
Student::Student() {
    studentName = "Name";
    id = 0;
    phone = "00-000-0000";
    age = 0;
    gender = 'X';
    classStanding = "classStanding";
    gpa = 0;
}
/*****************************************************
 *
 *  setGender(char g): Class Student
 ________________________________________________
 *  setting the gender
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   gender attribute is changed
*****************************************************/
void Student::setGender(char g) {
    gender = g;
}
/*****************************************************
 *
 *  Student(string name, unsigned the_id, string the_phone,
        int the_age, char the_gender,
                 string the_standing, double the_gpa)
 ________________________________________________
 *   constructor for student class
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   a  student class object is returned
*****************************************************/
Student::Student(string name, unsigned the_id, string the_phone,
        int the_age, char the_gender,
                 string the_standing, double the_gpa) {
    studentName = std::move(name);
    id = the_id;
    phone = std::move(the_phone);
    age = the_age;
    gender = the_gender;
    classStanding = std::move(the_standing);
    gpa = the_gpa;
}

