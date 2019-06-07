// writing on a text file
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
//    ofstream myfile ("example11.txt");
//    if (myfile.is_open())
//    {
//        myfile << "Student Grade Summary\n"
//                  "---------------------\n\n"
//                  "ENGLISH CLASS\n\n";
//        myfile << "Student Name                             Test Avg  Grade\n";
//        myfile << "----------------------------------------------------------------\n";
//        myfile << "Dipwar, Marvin                              86.50    B";
//        myfile.close();
//    }
//    Student Name                             Test Avg
//                aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//    else cout << "Unable to open file";
    string s("Hello");
    cout << left << setw(10) << s << "there." << endl;


    return 0;
}