/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     :  Assignment 03 - Student Records
 *   SECTION        : CS 003A
 *   Due Date       : 3/5/19
 *   ________________________________________________
 *   write a program that reads and stores student data from an input file,
 *   computes and stores each student's test average,
 *   then prints a report to an output file, along with class averages.
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
/**********************
   * * Documents struct**
   * This struct represents a
   * Documents struct. It manages one attributest,
   * words
**********************/
//This is a struct for recording the file
struct Documents {
    string words;           //In -- input words from file to Document struct
};
/**********************
   * * Student struct**
   * This struct represents a
   * Documents struct. It manages one attributest,
   * words
**********************/
//This is the student struct for storing info.
struct Student {
    string lastName;        //In --         last name
    string firstName;       //In --         first name
    string course;          //In --         course name
    int test1Grade;         //In --         test grade1
    int test2Grade;         //In --         test grade 2
    float finaExamGrade;   //In --          final grade

};

//This function is to convert float grade to letter grade
string getGrade(float grade);

int main() {



//INPUT -- get the input file name

    cout << "Please enter the name of the input file." << endl;
    string inputFileName;
    cout<<"Filename: ";
    getline( cin, inputFileName );
    cout << endl;
//INPUT -- get the  output file name
    cout << endl;
    cout << "Please enter the name of the output file." << endl;
    string outputFileName;
    cout<<"Filename: ";
    getline( cin, outputFileName );
    cout << endl;




    int classSize = 0;      //CALC -- class size
    int a = 0;              //CALC -- how many lines in the file
    string line;             //INPUT -- each line in the fine in string
    int z = 0;               //CALC -- it is for skipping hte first line



    ifstream file1(inputFileName.c_str()) ;             //Open the file first to get the first line
    string c ;
    while( file1 >> c ){
        classSize = atoi(c.c_str());                           //OUTPUT set the class size from the first line
        break;
    }


    file1.close() ;                                     //close the file



    ifstream file;
    file.open(inputFileName.c_str());                   //Open the file again

    Documents text[classSize];                          //PROCESSING init the document struct in the size of class size.

    while (getline(file, line)) {
        if (z > 0) {                                    // since the z is not equal to zero in the first line, this will skip the first line

            text[a].words = line;                       // after the else statement below chaning the z to be greater than zero, set each line into the test struct

            a++;
        } else {


            z++;

        }

    }
    Student studentList[classSize];                 //PROCESSING init the Student struct in the size of class size.

    //
    //PROCESSING input all the info to the studentList struct
    for (int i = 0; i < classSize; i++) {

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









    file.close();               //PROCESSING close the file

    ofstream myfile;                //PROCESSING open the file for writing
    myfile.open(outputFileName.c_str());
    if (myfile.is_open()) {
        myfile << "Student Grade Summary\n"
                  "---------------------\n\n";


        float tempClassAvg = 0;                 //CALC  --  create a temp class avg for writing the file
        int tempStudents = 0;                    //CALC --  create a temp class Students index for writing the file




        //PROCESSING open the file for writing for English
        myfile << "\nENGLISH CLASS\n\n";
        myfile << left << setw(37) << "Student Name" << left << setw(13) << "Test Avg" << "Grade" << endl;
        myfile << "----------------------------------------------------------------\n";
        for (int i = 0; i < classSize; i++) {

            if (studentList[i].course == "English") {

                tempStudents++;
                auto grade = static_cast<float>(((studentList[i].test1Grade) * 0.3 + (studentList[i].test2Grade) * 0.3 + (studentList[i].finaExamGrade) * 0.4));

                tempClassAvg += grade;
                string strGrade = getGrade(grade);

                string name = studentList[i].firstName + ", " + studentList[i].lastName;

                myfile << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint << grade << right
                       << setw(6) << strGrade;
                myfile << endl;


            }

        }
        tempClassAvg = tempClassAvg / tempStudents;
        string strClassTestAvgE = getGrade(tempClassAvg);
        myfile << endl<< left << setw(40) << "Class Average" << left << setw(8) << setprecision(4) << showpoint << tempClassAvg
               << right << setw(6)
               << strClassTestAvgE << endl;
        myfile << "----------------------------------------------------------------\n";
        tempClassAvg = 0, tempStudents = 0;

        //PROCESSING open the file for writing for History
        myfile << "HISTORY CLASS\n\n";
        myfile << left << setw(37) << "Student Name" << left << setw(13) << "Test Avg" << "Grade" << endl;
        myfile << "----------------------------------------------------------------\n";
        for (int i = 0; i < classSize; i++) {

            if (studentList[i].course == "History") {

                tempStudents++;
                auto grade = static_cast<float>(((studentList[i].test1Grade) * 0.3 + (studentList[i].test2Grade) * 0.3 + (studentList[i].finaExamGrade) * 0.4));

                tempClassAvg += grade;
                string strGrade = getGrade(grade);
                string name = studentList[i].firstName + ", " + studentList[i].lastName;

                myfile << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint << grade << right
                       << setw(6) << strGrade;
                myfile << endl;


            }

        }
        tempClassAvg = tempClassAvg / tempStudents;
        string strClassTestAvgH = getGrade(tempClassAvg);
        myfile <<endl<< left << setw(40) << "Class Average" << left << setw(8) << setprecision(4) << showpoint << tempClassAvg
               << right << setw(6)
               << strClassTestAvgH << endl;

        myfile << "----------------------------------------------------------------\n";
        tempClassAvg = 0, tempStudents = 0;
        myfile << "MATH CLASS\n\n";
        myfile << left << setw(37) << "Student Name" << left << setw(13) << "Test Avg" << "Grade" << endl;
        myfile << "----------------------------------------------------------------\n";

        //PROCESSING open the file for writing for Math
        for (int i = 0; i < classSize; i++) {

            if (studentList[i].course == "Math") {

                tempStudents++;
                auto grade = static_cast<float>(((studentList[i].test1Grade) * 0.3 + (studentList[i].test2Grade) * 0.3 + (studentList[i].finaExamGrade) * 0.4));

                tempClassAvg += grade;
                string strGrade = getGrade(grade);
                string name = studentList[i].firstName + ", " + studentList[i].lastName;

                myfile << left << setw(40) << name << left << setw(8) << setprecision(4) << showpoint << grade << right
                       << setw(6) << strGrade;
                myfile << endl;



            }

        }
        tempClassAvg = tempClassAvg / tempStudents;
        string strClassTestAvgM = getGrade(tempClassAvg);
        myfile <<endl<< left << setw(40) << "Class Average" << left << setw(8) << setprecision(4) << showpoint << tempClassAvg
               << right << setw(6)
               << strClassTestAvgM << endl;
        myfile << "----------------------------------------------------------------\n";
        myfile.close();
    } else {
        cout << "Unable to open file";

    }


    cout << "Processing Complete\n\n";                  //OUTPUT program ended

    // OUTPUT read the output file
    string lineOfFile;
    ifstream outPutFile (outputFileName.c_str());
    if (outPutFile.is_open())
    {
        while ( getline (outPutFile,lineOfFile) )
        {
            cout << lineOfFile << '\n';
        }
        outPutFile.close();
    }

    else cout << "Unable to open output file";

    return 0;
}


//This function input a grade in float and output a letter grade
string getGrade(
        float grade         //IN -- input the grade
) {

    // returning the letter grade in string based on the grade point
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
    if (grade <= 59.99) {
        return "F";
    }
}
