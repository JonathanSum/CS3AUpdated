/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 7 - Linked List Recursion
 *   SECTION        : CS 003A
 *   Due Date       : 5/01/19
 *   ________________________________________________
 *   Goals
 *    Add some additional recursive functions to your
 *    IntList class as well as make sure the Big 3 are defined.
***********************************************/
#ifndef INC_3A_1_INTLIST_H
#define INC_3A_1_INTLIST_H
#include <iostream>
#include "IntListIterator.h"

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

class IntListIterator;
class IntList {
private:
    IntNode *head= nullptr;          //IN - head node
    IntNode *tail;          //IN - tail node
public:

    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    IntList() : head(nullptr), tail(nullptr) {}
    IntList(const IntList &list);
    ~IntList();
    /**********************
        * * ACCESSORS **
    **********************/
    void display() const;

    /**********************
         * * MUTATORS **
    **********************/
    void push_front(int value);
    void pop_front();
    void push_back( int value );
    void select_sort();
    void insert_sorted( int value );
    void remove_duplicates();
    IntListIterator begin();
    IntListIterator end();
    int front() const;
    int back() const;
    int length(IntListIterator head) const;
    int sum(IntListIterator head) const;
    void reverseDisplay(IntListIterator head) const;
    IntList & operator=( const IntList &list );


};



/*********************************************************************
   * IntList Class
   * This class represents a IntList object.
   * It manages 2 attributest,
   * tail of the IntNode node
   * head of the IntNode node
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  IntList();
 *  Constructor;    Initialize class attributes and setting head
 *  and tail to null pointer
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~IntList();
 *  Destructor;   deallocate all element in the linked list.
 *  After freeing all the element from the memory,
 *  set the head and tail to null pointer
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/

/*********************************************************************
 * void display() const;
 * Accessors: Display the
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 * void push_front(int value);
 * Mutator: Add a node with a integer value to the front the linked
 * list.
 *--------------------------------------------------------------------
 * Parameter: value // IN - the value of the new node that is
 * is going to be added to the front of the linked list.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void pop_front();
 * Mutator: remove the first node in the linked list
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void push_back(int value);
 * Mutator: Add a node with a integer value to the end the linked
 * list.
 *--------------------------------------------------------------------
 * Parameter: value // IN - the value of the new node that is
 * is going to be added to the front of the linked list.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void select_sort();
 * Mutator: sort the linked list
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * insert_sorted( int value );
 * insert a node to the sorted list at index where the element
 * is smaller or same of the node.
 *--------------------------------------------------------------------
 * Parameter: value // IN - the value to be inserted
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * remove_duplicates();
 * Remove Duplicates Node
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * IntListIterator begin();
 * return the first element in IntListIterator
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: IntListIterator
*********************************************************************/

/*********************************************************************
 * IntListIterator end();
 * return the last element in IntListIterator
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: IntListIterator
*********************************************************************/

/*********************************************************************
 * int front() const;
 * return the first element in integer
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/

/*********************************************************************
 * int back() const;
 * return the last element in integer
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/

/*********************************************************************
 * int length(IntListIterator head) const;
 * return total length of the list
 *--------------------------------------------------------------------
 * Parameter: (IntListIterator head     //IN - head of the list
 *             )
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/

/*********************************************************************
 * int sum(IntListIterator head) const;
 * return total sum of the list
 *--------------------------------------------------------------------
 * Parameter: (IntListIterator head     //IN - head of the list
 *             )
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/

/*********************************************************************
 * void reverseDisplay(IntListIterator head) const;
 * print the whole list in reverse
 *--------------------------------------------------------------------
 * Parameter: (IntListIterator head     //IN - head of the list
 *             )
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/

/*********************************************************************
 * IntList & operator=( const IntList &list );
 * Assignment operator
 *--------------------------------------------------------------------
 * Parameter: (const IntList &list     //IN - object of other list
 *             )
 *--------------------------------------------------------------------
 * Return: IntList object
*********************************************************************/

#endif //INC_3A_1_INTLIST_H
