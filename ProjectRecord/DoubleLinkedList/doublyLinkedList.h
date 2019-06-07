//
// Created by JonathanSum on 5/2/2019.
//
/***********************************************
*   Author         : Jonathan Sum
*   Assignment     : Lab 15
*   SECTION        : CS 003A
*   Due Date       : 5/02/19
*   ________________________________________________
*   Goals
*   Begin implementation of a doubly-linked list.
***********************************************/
#ifndef INC_3A_DoublyLinkedList_H
#define INC_3A_DoublyLinkedList_H
#include <iostream>
#include "IntListIterator.h"

using namespace std;
/**********************
   * * IntNode struct**
   * This struct represents a
   * IntNode struct. It manages three attributes,
   * int data;
   * IntNode *next;
   * IntNode *prev;
**********************/
struct IntNode {
    int data;       //IN - value in the node
    IntNode *prev;  // OUT - the address of the previous node
    IntNode *next;  // OUT - the address of the next node

    /**************************************
            **      CONSTRUCTOR    **
    ***************************************/
    IntNode( int data ) : data(data), next(0), prev(0) {}
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
class DoublyLinkedList {
private:
    IntNode *head= nullptr;          //IN - head node
    IntNode *tail;          //IN - tail node
public:

    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    DoublyLinkedList(const DoublyLinkedList &D);
    ~DoublyLinkedList();
    /**********************
       * * ACCESSORS **
    **********************/
    void display(bool forward = true) const;
    /**********************
         * * MUTATORS **
    **********************/
    void push_front(int value);
    void pop_front();
    void push_back( int value );
    void pop_back();
    void sort();
    void insert_sorted( int value );
    bool remove(int value);
    IntListIterator  begin();
    IntListIterator  end();
    int front() const;
    int back() const;
    int length(IntListIterator head) const;
    DoublyLinkedList & operator=( const DoublyLinkedList &D );


};



/*********************************************************************
   * DoublyLinkedList Class
   * This class represents a DoublyLinkedList object.
   * It manages 2 attributest,
   * tail of the IntNode node
   * head of the IntNode node
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  DoublyLinkedList();
 *  Constructor;    Initialize class attributes and setting head
 *  and tail to null pointer
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~DoublyLinkedList();
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
 *  void display(bool forward = true) const;
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
 * void pop_back();
 * Mutator: remove the last node in the linked list
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
 * void sort();
 * Mutator: sort the linked list
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * insert( int value );
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
 * DoublyLinkedList & operator=( const DoublyLinkedList &D );
 * Assignment operator
 *--------------------------------------------------------------------
 * Parameter: (const DoublyLinkedList &D     //IN - object of other list
 *             )
 *--------------------------------------------------------------------
 * Return: DoublyLinkedList object
*********************************************************************/
/*********************************************************************
 * DoublyLinkedList(const DoublyLinkedList &D);;
 * copy constructor
 *--------------------------------------------------------------------
 * Parameter: (const DoublyLinkedList &D     //IN - object of other list
 *             )
 *--------------------------------------------------------------------
 * Return: DoublyLinkedList object
*********************************************************************/

#endif //INC_3A_DoublyLinkedList_H
