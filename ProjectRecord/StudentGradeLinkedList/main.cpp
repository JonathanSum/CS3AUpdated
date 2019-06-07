/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 06 - 2D Vector
 *   SECTION        : CS 003A
 *   Due Date       : 3/09/19
 *   ________________________________________________
 *   Goals
 *   Write a struct called StudentNode
 *   that will be used in a linked list.

***********************************************/

#include <iostream>
#include "header.h"
#include <fstream>
using namespace std;



int main() {
    auto *linkedList = new studentList();
    linkedList->readFile("inFile.txt");
    linkedList->printList();
    linkedList->search("Anna White");
    linkedList->remove("Paul Johnson");
    linkedList->avgGPA();
    return 0;
}