/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 06 - IntList
 *   SECTION        : CS 003A
 *   Due Date       : 4/11/19
 *   ________________________________________________
 *   Goals
 *   Write a linked list and write a sorting algorithm
 *   to sort the linked list.
***********************************************/

#include "IntList.h"
#include <iostream>

using namespace std;

/***************************************************
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
    auto current = head;                        //PROCESSING - starting
                                                // from the first node
    while (current != nullptr) {
        if (current->next != nullptr) {
            cout << current->data << " ";
        } else {
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
        return;
    }
    if (head != nullptr && tail == nullptr) {
        tail = head;
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
    IntNode *current = head;        //IN - set the current to the head
    IntNode *next;                  //IN - set create the next node

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

}

/*****************************************************
 *
 *   Method push_back(int value): Class IntList
 ________________________________________________
 *   This method add a node in the beginning of
 *   the linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   The size is linked list's original the size
 *   POST-CONDITIONS
 *   The size increases by one
*****************************************************/
void IntList::push_back(int value) {


    auto *newNode = new IntNode(value);         //IN - Create a new node

    //PROCESSING - add the new node into the end of the list
    if (head == nullptr) {
        head = newNode;
        return;
    }

    //PROCESSING - add the new node into the end of the list if the tail is empty
    if (tail == nullptr && head!= nullptr){
        head->next=newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }

}
/*****************************************************
 *
 *   Method select_sort(): Class IntList
 ________________________________________________
 *   This method sort the list by swapping
 *   each node's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   unsorted list
 *   POST-CONDITIONS
 *   sorted list
*****************************************************/
void IntList::select_sort() {

    IntNode *current = head;             // PROCESSING current node is the current node
                                         // while looping the list.

    // PROCESSING - loop while the whole linked list
    while (current != nullptr) {
        IntNode *min = current;
        IntNode *r = current->next;

        while (r != nullptr) {
            if (min->data > r->data)
                min = r;
            r = r->next;
        }
        int x = current->data;
        current->data = min->data;
        min->data = x;
        current = current->next;
    }

}

/*****************************************************
 *
 *   Method insert_sorted(int value)
 ________________________________________________
 *   adding a node in to the list before an element
 *   is same or smaller than it.
 ________________________________________________
 *   PRE-CONDITIONS
 *   sorted list
 *   POST-CONDITIONS
 *   sorted list and the size is increased by one
*****************************************************/
void IntList::insert_sorted(int value) {


    IntNode *current = head,          // PROCESSING current node is the current node
                                      // while looping the list.
            *previous = nullptr;     // PROCESSING It is the previous node
                                      // of the current node
                                      // while looping the list.


    // PROCESSING - loop while the whole linked list
    while (current != nullptr && value > current->data) {
        previous = current;
        current = current->next;
    }

    //PROCESSING - if the number is not less than any numbers in the list,
    //             then push back it.
    if (current == nullptr) {
        push_back(value);
        return;
    } else if (current == head) {
        push_front(value);
        return;
    } else {
        auto *temp = new IntNode(value);
        previous->next = temp;
        temp->next = current;
    }

}

/*****************************************************
 *
 *   Method remove_duplicates(int value)
 ________________________________________________
 *   remove duplicates any nodes in the list
 ________________________________________________
 *   PRE-CONDITIONS
 *   a list has a duplicate node.
 *   POST-CONDITIONS
 *   a list does not have a duplicate node.
*****************************************************/
void IntList::remove_duplicates() {

    IntNode *current = head,          // PROCESSING current node is the current node
                                      // while looping the list.

            *previous = nullptr;     // PROCESSING It is the previous node
                                      // of the current node
                                      // while looping the list.

    // PROCESSING - loop while the whole linked list before the list element
    while (current->next != nullptr) {
        IntNode *min = current;
        IntNode *r = current->next;

        // PROCESSING - loop while the whole linked list starting from the first's
        //              element's next element.
        while (r != nullptr) {
            if (current->data != r->data) {
                current->next = r;
                break;
            }
            r = r->next;
        }
        current = current->next;

    }
}

