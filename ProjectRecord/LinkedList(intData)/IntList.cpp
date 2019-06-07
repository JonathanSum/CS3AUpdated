/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 11 - IntList Intro
 *   SECTION        : CS 003A
 *   Due Date       : 4/11/19
 *   ________________________________________________
 *   Goals
 *   Write a linked list
***********************************************/

#include "IntList.h"
#include <iostream>

using namespace std;





/*****************************************************
 *
 *   Method display: Class IntList
 ________________________________________________
 *   This method displace the whole linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   Same
*****************************************************/

void IntList::display() const {
    //PROCESSING - loop thru the linked list
    // to displace each element
    if (head == nullptr) {
        return;
    }
    auto current = head;        //PROCESSING - starting
                                // from the first node
    while (current != nullptr) {
        if(current->next!= nullptr){
            cout << current->data << " ";
        }else{
            cout << current->data;
        }
        current = current->next;
    }
}

/*****************************************************
 *
 *   Method push_front: Class IntList
 ________________________________________________
 *   This method add the first node in linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   The size is linked list is the size
 *   before adding the node.
 *   POST-CONDITIONS
 *   The size increases by one because one
 *   node is added to the front of the linked list.
*****************************************************/
void IntList::push_front(int value) {

    //PROCESSING - adding the new node and creating the node
    //              with the input value
    auto *newNode = new IntNode(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

/*****************************************************
 *
 *   Method pop_front(): Class IntList
 ________________________________________________
 *   This method remove the first node in linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   The size is linked list is the size
 *   before removing the node.
 *   POST-CONDITIONS
 *   The size decreases by one because one
 *   node is removed to the front of the linked list.
*****************************************************/
void IntList::pop_front() {

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
}
/*****************************************************
 *
 *   Destructor ~IntList(): Class IntList
 ________________________________________________
 *   This Destructor free all element in IntList
 ________________________________________________
 *   PRE-CONDITIONS
 *   The elements in class are not free in memory.
 *   before removing the node.
 *   POST-CONDITIONS
 *   The elemenst in class are  free in memory
*****************************************************/

IntList::~IntList() {

    //PROCESSING - loop thru the linked list
    //              free all the element in the linked
    //              list.
    IntNode* current = head;        //IN - set the current to the head
    IntNode* next;                  //IN - set create the next node

    //PROCESSING - loop thru the linked list and stop when the element is
    //null pointer.
    while (current != nullptr) {

        //PROCESSING - store the next node before deleting the current
        next = current->next;

        //PROCESSING - deleting the current node
        delete current;

        //PROCESSING - set the current from the updated next node
        current = next;
    }
};