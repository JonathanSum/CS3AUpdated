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
#include "bboard.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;




int main(int argc, char *argv[]) {
    BBoard started = BBoard();
    BBoard x = BBoard();
//    string str="users.txt";
//    x.setup(str);
    string fileName = argv[1];
//    cout<<"Debug file name: "<<fileName<<endl;
    started.setup(fileName);


    return 0;
}
