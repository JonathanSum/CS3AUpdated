/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 7 - Linked List Recursion
 *   SECTION        : CS 003A
 *   Due Date       : 5/01/19
 *   ________________________________________________
 *   Goals
 *    Add some additional recursive functions to your
 *    LinkedList class as well as make sure the Big 3 are defined.
***********************************************/
#ifndef INC_3A_1_INTLIST_H
#define INC_3A_1_INTLIST_H

#include <iostream>
#include "iterator.h"
#include "listEmpty.cpp"

using namespace std;

/**********************
   * * IntNode struct**
   * This struct represents a
   * IntNode struct. It manages two attributes,
   * int data;
   * IntNode *next;
**********************/
template<typename E>
struct Node {
    E data;       //IN - value in the node
    Node *next;  // OUT - the address of the next node

    /**************************************
            **      CONSTRUCTOR    **
    ***************************************/
    Node(E data) : data(data), next(0) {}
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


template<class E>
class Iterator;

template<class E>
class LinkedList {
private:
    Node<E> *head = nullptr;          //IN - head node
    Node<E> *tail;          //IN - tail node
public:

    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(const LinkedList &source);

    ~LinkedList();

    /**********************
        * * ACCESSORS **
    **********************/
    void display() const;

    /**********************
         * * MUTATORS **
    **********************/
    LinkedList<E> &operator=(const LinkedList &source);

    void push_front(const E &value);

    void pop_front() {

        //PROCESSING - removing the first node in the linked
        //             list
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else if (head == nullptr) {
            cout << "the list is empty" << endl;
        } else {
            auto tempNode = head;
            head = head->next;
            delete tempNode;
            tempNode = nullptr;
        }
    };

    void push_back(const E &value);

    const E &front() {


        //OUT - return the first element of the linked list's data
        return head->data;
    };

    const E &back() {

        return tail->data;

    };

    void clear();

    void select_sort();

    void insert_sorted(const E &value);

    void remove_duplicates();

    Iterator<E> begin();

    Iterator<E> end();

    int length(Iterator<E> head) const;

    int sum(Iterator<E> head) const;


};



/*********************************************************************
   * LinkedList Class
   * This class represents a LinkedList object.
   * It manages 2 attributest,
   * tail of the IntNode node
   * head of the IntNode node
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  LinkedList();
 *  Constructor;    Initialize class attributes and setting head
 *  and tail to null pointer
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~LinkedList();
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
 * LinkedListIterator begin();
 * return the first element in LinkedListIterator
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: LinkedListIterator
*********************************************************************/

/*********************************************************************
 * LinkedListIterator end();
 * return the last element in LinkedListIterator
 *--------------------------------------------------------------------
 * Parameter: None
 *--------------------------------------------------------------------
 * Return: LinkedListIterator
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
 * int length(LinkedListIterator head) const;
 * return total length of the list
 *--------------------------------------------------------------------
 * Parameter: (LinkedListIterator head     //IN - head of the list
 *             )
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/

/*********************************************************************
 * int sum(LinkedListIterator head) const;
 * return total sum of the list
 *--------------------------------------------------------------------
 * Parameter: (LinkedListIterator head     //IN - head of the list
 *             )
 *--------------------------------------------------------------------
 * Return: integer
*********************************************************************/



#endif //INC_3A_1_INTLIST_H
