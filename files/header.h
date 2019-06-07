//
// Created by JonathanSum on 4/4/2019.
//
#include <iostream>

#ifndef INC_3A_HEADER_H
#define INC_3A_HEADER_H
using namespace std;

/**********************
   * * IntNode struct**
   * This struct represents a
   * IntNode struct. It manages two attributes,
   * int data;
   * IntNode *next;
**********************/
struct IntNode {
    int data;       //IN - value in the node
    IntNode *next;  // OUT - the address of the next node

    /**************************************
            **      CONSTRUCTOR    **
    ***************************************/
    IntNode(int data) : data(data), next(0) {}
};
/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  IntNode(int data);
 *  Constructor;    Initialize class attributes and setting node with
 *  the value and next node address to be null pointer
 *  Parameter: int data  //IN - value to be stored in the node
 *  Return: none
*********************************************************************/



#endif //INC_3A_HEADER_H
