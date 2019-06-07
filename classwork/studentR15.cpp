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
#include <math.h>
#include <fstream>

using namespace std;


struct Documents {
    string words;
};

struct Student {
    string lastName;
    string firstName;
    string course;
    int test1Grade;
    int test2Grade;
    float finaExamGrade;

};
struct English {
    string studentName;
    string firstName;
    string testAverage;
    char Grade;

};

float roundFloat(float var);

string getGrade(float grade);

int main() {





    string lastName;
    string firstName;
    string course;



    cout<<"Please enter the name of the input file."<<endl;
    string inputFileName;
    cout<<"Filename: ";
    getline( cin, inputFileName );
    cout<<endl;
    cout<<endl;

    cout<<"Please enter the name of the output file."<<endl;
    string outputFileName;
    cout<<"Filename: ";
    getline( cin, outputFileName );
    cout<<endl;
    cout<<"Processing Complete\n\n";


    ifstream file;
    file.open(inputFileName.c_str());

    int classSize = 0;
    int z = 0;
    string line;
    int a = 0;
    Documents text[8];
    while (getline(file, line)) {
        if (z > 0) {

            text[a].words = line;

            a++;
        } else {
            classSize =  atoi(line.c_str());

            z++;
        }

    }
    Student studentList[classSize];


    for (int i = 0; i < 8; i++) {

        int n = 1;
        int nextIndex = (int) text[i].words.length();
        int startingIndex = 0;


        string tempLast = text[i].words.substr(nextIndex - 2, nextIndex - 1);


        studentList[i].finaExamGrade = ::atof(tempLast.c_str());


        for (int j = 0; j < nextIndex; j++) {

            if (text[i].words[j] == ',') {
                string tempString = text[i].words;           //create a temp string.
                string temp1 = tempString.substr(startingIndex, (j - startingIndex));
                if (n < classSize) {
                    if (n == 1) {
                        studentList[i].firstName = temp1;
                    }
                    if (n == 2) {
                        studentList[i].lastName = temp1;
                    }
                    if (n == 3) {
                        if (temp1 == "M") {
                            studentList[i].course = "Math";
                        } else if (temp1 == "H") {
                            studentList[i].course = "History";
                        } else if (temp1 == "E") {
                            studentList[i].course = "English";
                        }
                    }
                    if (n == 4) {
                        studentList[i].test1Grade = atoi(temp1.c_str());
                    }
                    if (n == 5) {
                        studentList[i].test2Grade = atoi(temp1.c_str());
                    }
                    n++;

                }


                startingIndex = j + 1;
            }
        }

    }


//    for (int i = 0; i < 8; i++) {
//        cout << "First Name: " << studentList[i].firstName << " Last Name: " << studentList[i].lastName << " course "
//             << studentList[i].course
//             << " test1 " << studentList[i].test1Grade << " test2 " << studentList[i].test2Grade << " final "
//             << studentList[i].finaExamGrade << endl;
//    }
//    Letter Grade of the test average, based on standard 10-point scale (i.e. 90-100 = A, 80-89.99 = B, etc.)
//    cout << "Starting" << endl;
    for (int i = 0; i < classSize; i++) {

        if (studentList[i].course == "English") {
            float grade = ((studentList[i].test1Grade + studentList[i].test2Grade + studentList[i].finaExamGrade) / 3);
            string strGrade = getGrade(grade);
            string name = studentList[i].lastName + ", " + studentList[i].firstName;
//            cout << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint  << grade << setw(6) << strGrade << endl;

        }
    }



    file.close();
    ofstream myfile;
    myfile.open(outputFileName.c_str());
    if (myfile.is_open()) {
        myfile << "Student Grade Summary\n"
                  "---------------------\n\n";

//        myfile << "Student Name                             Test Avg  Grade\n";

        float tempClassAvg = 0;
        int tempStudents = 0;
        //English
        myfile << "ENGLISH CLASS\n\n";
        myfile << left << setw(37) << "Student Name" << left << setw(13) << "Test Avg" << "Grade" << endl;
        myfile << "----------------------------------------------------------------\n";
        for (int i = 0; i < classSize; i++) {

            if (studentList[i].course == "English") {

                tempStudents++;
                float grade = ((studentList[i].test1Grade + studentList[i].test2Grade + studentList[i].finaExamGrade) /
                               3);
                tempClassAvg += grade;
                string strGrade = getGrade(grade);
//                myfile<<"Debug Test Avg: "<<TestAvg<<endl;
                string name = studentList[i].lastName + ", " + studentList[i].firstName;
                myfile << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint<< grade << right << setw(6) << strGrade
                       << endl;
                myfile << endl;



            }

        }
        tempClassAvg = tempClassAvg / tempStudents;
        string strClassTestAvgE = getGrade(tempClassAvg);
        myfile << left << setw(40) << "Class Average" << left << setw(8) << setprecision(4) << showpoint <<tempClassAvg << right << setw(6)
               << strClassTestAvgE << endl;
        myfile << "----------------------------------------------------------------\n\n\n";
        tempClassAvg = 0, tempStudents = 0;

        //History
        myfile << "HISTORY CLASS\n\n";
        myfile << left << setw(37) << "Student Name" << left << setw(13) << "Test Avg" << "Grade" << endl;
        myfile << "----------------------------------------------------------------\n";
        for (int i = 0; i < classSize; i++) {

            if (studentList[i].course == "History") {

                tempStudents++;
                float grade = ((studentList[i].test1Grade + studentList[i].test2Grade + studentList[i].finaExamGrade) /
                               3);
                tempClassAvg += grade;
                string strGrade = getGrade(grade);
                string name = studentList[i].lastName + ", " + studentList[i].firstName;
                myfile << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint <<grade << right << setw(6) << strGrade
                       << endl;
                myfile << endl;



            }

        }
        tempClassAvg = tempClassAvg / tempStudents;
        string strClassTestAvgH = getGrade(tempClassAvg);
        myfile << left << setw(40) << "Class Average" << left << setw(8) << setprecision(4) << showpoint << tempClassAvg << right << setw(6)
               << strClassTestAvgH << endl;
        float a1=73.00;

        myfile << "----------------------------------------------------------------\n\n\n";
        tempClassAvg = 0, tempStudents = 0;
        myfile << "MATH CLASS\n\n";
        myfile << left << setw(37) << "Student Name" << left << setw(13) << "Test Avg" << "Grade" << endl;
        myfile << "----------------------------------------------------------------\n";


        for (int i = 0; i < classSize; i++) {

            if (studentList[i].course == "Math") {

                tempStudents++;
                float grade = ((studentList[i].test1Grade + studentList[i].test2Grade + studentList[i].finaExamGrade) /
                               3);
                tempClassAvg += grade;
                string strGrade = getGrade(grade);
                string name = studentList[i].lastName + ", " + studentList[i].firstName;
                myfile << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint <<grade << right << setw(6) << strGrade
                       << endl;
                myfile << endl;

                if (i == (classSize - 1)) {
                }

            }

        }
        tempClassAvg = tempClassAvg / tempStudents;
        string strClassTestAvgM = getGrade(tempClassAvg);
        myfile << left << setw(40) << "Class Average" << left << setw(8) << setprecision(4) << showpoint << tempClassAvg << right << setw(6)
               << strClassTestAvgM << endl;
        myfile << "----------------------------------------------------------------\n\n\n";
        myfile.close();
    } else {
        cout << "Unable to open file";

    }
    string s("Hello");







    return 0;
}

float roundFloat(float var) {
    float rounded = (int) (var * 100 + .5);
    rounded= (rounded / 100)+0.00;
    return rounded;
}

string getGrade(float grade) {

    if (grade <= 100.00 && grade >= 90.00) {
        return "A";
    }
    if (grade <= 89.99 && grade >= 80.00) {

        return "B";
    }
    if (grade <= 79.99 && grade >= 70) {
        return "C";
    }
    if (grade <= 69.99 && grade >= 60) {
        return "D";
    }
    if (grade <= 59.99 && grade >= 50) {
        return "F";
    }
}
