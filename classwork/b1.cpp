/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 04  Bin project
 *   SECTION        : CS 003A
 *   Due Date       : 3/5/19
 *   ________________________________________________
 *   Write a program that simulates inventory bins in a warehouse. Each bin holds a number of the
 *   same type of parts. The program should use a structure that keeps the following data:
 *   Description of the part kept in the bin
 *   Number of parts in the bin
 *   The program should have an array of 30 bins, initialized with the following data:
***********************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




struct Student {
    string lastName;
    string firstName;
    string course;
    int test1Grade;
    int test2Grade;
    float finaExamGrade;

};


int main() {



//    string fileName;
//    cout<<"Enter the name of the file: ";
//    cin>>fileName;

//    file.open("fileName");

    string lastName;
    string firstName;
    string course;
    int test1Grade;
    int test2Grade;
    float finaExamGrade;




//    int capacity = *(&bin + 1) - bin;
    ifstream size("t1.txt");
    string line1;

//The first line is an int, which is the class size.
//Thus we open the file and close it first in order to get the class size.
    int classSize = 0;
    if (size.is_open()) {
        while (getline(size, line1)) {
            classSize = stoi(line1);
            break;
        }
        size.close();
    } else cout << "Unable to open file" << endl;
    Student studentList[classSize];

    ifstream file;
    file.open("t1.txt");
//    cout<<&studentList<<endl;
    string line;
    int n = 0;  //It is for skipping the first line of the file.
    int eachLine = 0;
    int m = 0;
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    int m4 = 0; //test 1 grade
    int m5 = 0; //test 2 grade
    int m6 = 0; //final exam grade
//    while (getline(file, line)) {
//
//        stringstream lineStream(line);
//        string value;
//
//        while (getline(lineStream, value, ',')) {
//            if (n != 0) {
//                if (eachLine < 6) {
//                    cout << " " << eachLine << " Value(" << value << ")";
//                    if (m1 == 0) {
//                        value = studentList[m].firstName;
//                        m1++;
//                    } else if (m2 == 0) {
//                        value = studentList[m].lastName;
//                        m2++;
//                    } else if (m3 == 0) {
//                        if (value == "M") {
//                            studentList[m].course = "Math";
//                        } else if (value == "H") {
//                            studentList[m].course = "History";
//                        } else if (value == "E") {
//                            studentList[m].course = "English";
//                        }
//                        m3++;
//                    }else if(m4==0){
//                        value= studentList[m].test1Grade;
//                        m4++;
//                    }else if(m5==0){
//                        value= studentList[m].test2Grade;
//                        m5++;
//                    }else if(m6==0){
//                        value= studentList[m].finaExamGrade;
//                        m6++;
//                    }
//
//
//                    eachLine++;
//                    if (eachLine == 6) {
//                        eachLine = 0;  //after running six items each line, set this var back to zero.
//                    }
//
//
//                } else {
//                    cout << endl;
//                }
//
//            } else {
//                n++; //It is for skipping the first line of the file.
//            }
//
//
//        }
//        cout << "This line ended" << endl;
//        m++;
//        m1=0;
//        m2=m1;
//        m3=m1;
//        m4=m1;
//        m5=m1;
//        m6=m1;
//    }
    while (getline(file, line)) {

    }

    cout<<"Hi"<<endl;
//    for(int i=0; i<8;i++){
//        cout<<studentList[i].firstName<<" "<<studentList[i].lastName<<" "<<studentList[i].course<<" "<< studentList[i].test1Grade<<" "<<studentList[i].test2Grade<<" "<<studentList[i].finaExamGrade<<endl;
//    }

    cout << "I am n" << classSize << endl;



//    int capacity = *(&studentList + 1) - studentList;
//    cout << "I am capacity" << capacity << endl;
    cout << "Length of array = " << (sizeof(studentList) / sizeof(studentList[0])) << endl;
    file.close();
    return 0;
}

