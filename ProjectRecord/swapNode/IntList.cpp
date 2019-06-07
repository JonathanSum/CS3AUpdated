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

void IntList::push_back(int value) {
//    cout<<"Debug tail: "<<tail->data<<endl;
//    cout<<"Debug list: \n";
//    this->display();
//    cout<<endl;
    auto *newNode = new IntNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

//    IntNode *current = head;
//    while (current->next != nullptr) {
//        current = current->next;
//    }
//    current->next = newNode;

    tail->next = newNode;
    tail = newNode;
}

void IntList::select_sort() {
//This function sorts the list into ascending order
//using the selection sort algorithm.
    IntNode *current = head,
            *previous = nullptr,
            *previousMin = nullptr,
            *previousOfPre = nullptr;
    IntNode *minNode;

    auto *currentNext = head->next;

    while ((current->next)->next != nullptr) {
        currentNext = current->next;

        previousOfPre = current;
        minNode = current;
        previousMin = previous;
        while (currentNext != nullptr) {

            if (currentNext->data < minNode->data) {

                minNode = currentNext;
                previousMin = previousOfPre;    //setting previousMin to be the node pointing to the minNode
            }
            previousOfPre = currentNext;
            currentNext = currentNext->next;
        }
        if (minNode->data != current->data) {
            //PROCESSING - if previous is not null, which current isn't head, set the previous->next
            //             pointing to the minNode. Otherwise, head will be the minNode

            //swapping the minNode to current
            if (previous != nullptr) {
                previous->next = minNode;
            } else {
                head = minNode;
            }
            //swapping the current to minNode
            if(previousMin!= nullptr)
                previousMin->next = current;
            tail->next = nullptr;
            IntNode *tempMN = minNode->next;

            if (current->next == minNode) {
                minNode->next = current;
                current->next = tempMN;
            } else {
                minNode->next = current->next;
                current->next = tempMN;
            }

            if (previous != nullptr) {
                current = previous->next;
            } else {
                current = head;
            }

            minNode = previousMin->next;

        }
        previous = current;
        current = current->next;

    }


}

void IntList::insert_sorted(int value) {
//This function assumes the values in the list are in sorted (ascending) order
// and inserts the data into the appropriate position in the list
// (so that the values will still be in ascending order after insertion).
// DO NOT call select_sort within this function.

    auto *newNode = new IntNode(value);

    IntNode *current = head,
            *previous = nullptr;
    while (current != nullptr && value < current->data) {
        previous = current;
        current = current->next;
    }

    if(current== nullptr){
        push_back(value);
        return;
    }
//    else if(current==){}

}

void IntList::remove_duplicates() {

}

