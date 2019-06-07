/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 06 - 2D Vector
 *   SECTION        : CS 003A
 *   Due Date       : 3/09/19
 *   ________________________________________________
 *   Goals
 *   By the end of this lab I should:
 *   be more familiar with 2d vectors

***********************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "BBoard.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

//void add_user(istream &infile, const string &name, const string &pass){
//    ifstream infile("t1.txt");
//    string s;
//    istream(' ');
//    while( getline(infile,s, ' ') )
//    {
//        cout << "Read from file: " << s << endl;
//        if(s=="end"){
//            break;
//        }
//    }
//}



int main(int argc, char *argv[]) {
    cout << "You have++ entered " << argc
         << " arguments:" << "\n";
    string testingString;
    for (int i = 1; i < argc; ++i) {
        testingString = argv[i];
        cout << argv[i] << "\n";
    }
    cout<<"Debug: "<<testingString<<endl;
    return 0;
}









