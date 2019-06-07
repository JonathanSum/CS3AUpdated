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

#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

/***************************************************
 *
 *   Method display: Class DoublyLinkedList
 ________________________________________________
 *   This method displace the whole linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   Same
*****************************************************/



/*****************************************************
 *
 *   Method push_front: Class DoublyLinkedList
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
void DoublyLinkedList::push_front(int value) {

    //PROCESSING - init the new node and creating the node
    //              with the input value
    auto *newNode = new IntNode(value);

    //PROCESSING - adding the new node before the node
    newNode->next = head;
    newNode->prev = nullptr;

    //PROCESSING - if the head node exists before,
    // then its prev exist
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;

    if (head != nullptr && tail == nullptr) {
        tail = head;
    }

}

/*****************************************************
 *
 *   Method pop_front(): Class DoublyLinkedList
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
void DoublyLinkedList::pop_front() {

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

    }
}

/*****************************************************
 *
 *   Destructor ~DoublyLinkedList(): Class DoublyLinkedList
 ________________________________________________
 *   This Destructor free all element in DoublyLinkedList
 ________________________________________________
 *   PRE-CONDITIONS
 *   The elements in class are not free in memory.
 *   before removing the node.
 *   POST-CONDITIONS
 *   The elemenst in class are  free in memory
*****************************************************/
DoublyLinkedList::~DoublyLinkedList() {

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
 *   Method push_back(int value): Class DoublyLinkedList
 ________________________________________________
 *   This method add a node in the beginning of
 *   the linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   The size is linked list's original the size
 *   POST-CONDITIONS
 *   The size increases by one
*****************************************************/
void DoublyLinkedList::push_back(int value) {


    auto *newNode = new IntNode(value);         //IN - Create a new node


    newNode->next = nullptr;    //PROCESSING - setting newNode's next node to be null
    //PROCESSING - add the new node into the end of the list
    if (head == nullptr) {
        head = newNode;
        newNode->prev = nullptr;
        return;
    }

    //PROCESSING - add the new node into the end of the list if the tail is empty
    if (tail == nullptr && head != nullptr) {
        head->next = newNode;
        tail = newNode;
        newNode->prev = head;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

}

/*****************************************************
 *
 *   Method select_sort(): Class DoublyLinkedList
 ________________________________________________
 *   This method sort the list by swapping
 *   each node's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   unsorted list
 *   POST-CONDITIONS
 *   sorted list
*****************************************************/
void DoublyLinkedList::sort() {

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
 *   Method insert_sorted(int value): Class DoublyLinkedList
 ________________________________________________
 *   adding a node in to the list before an element
 *   is same or smaller than it.
 ________________________________________________
 *   PRE-CONDITIONS
 *   sorted list
 *   POST-CONDITIONS
 *   sorted list and the size is increased by one
*****************************************************/
void DoublyLinkedList::insert_sorted(int value) {


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

    } else if (current == head) {
        push_front(value);

    } else {
        //PROCESSING - connect the node in the list
        auto *temp = new IntNode(value);
        previous->next = temp;
        temp->next = current;
        temp->prev = previous;

        if (temp->next != nullptr) {
            temp->next->prev = temp;
        }
    }

}

/*****************************************************
 *
 *   Method w_duplicates(int value)
 ________________________________________________
 *   remove duplicates any nodes in the list
 ________________________________________________
 *   PRE-CONDITIONS
 *   a list has a duplicate node.
 *   POST-CONDITIONS
 *   a list does not have a duplicate node.
*****************************************************/

bool DoublyLinkedList::remove(int value) {

    auto current = head;

    // PROCESSING - loop while the whole linked list before the list element
    while (current->next != nullptr) {
        if (current->data == value) {
            break;
        }
        current = current->next;
    }
    if (current == nullptr) {
        return false;
    }
    if (current == head) {
        pop_front();
    } else if (current == tail) {
        pop_back();
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    return true;
}

/*****************************************************
 *
 *   Method begin(): Class DoublyLinkedList
 ________________________________________________
 *   return a IntListIterator  object
 *   that is the first element in the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   the first element in linked list is returned.
*****************************************************/
IntListIterator DoublyLinkedList::begin() {

    //OUT - return a IntListIterator  object
    // with a first element of the linked list's data as attribute
    return IntListIterator(head);
}

/*****************************************************
 *
 *   Methodend() : Class DoublyLinkedList
 ________________________________________________
 *   return a IntListIterator  object
 *   that is the first element in the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   the last element in linked list is returned.
*****************************************************/
IntListIterator DoublyLinkedList::end() {

    //OUT - return a IntListIterator  object
    // with a tail data as attribute
    return nullptr;
}

/*****************************************************
 *
 *   Method begin(): Class DoublyLinkedList
 ________________________________________________
 *   return the first element in the
 *   linked list's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   A first element's data
 *   in the linked list is returned.
*****************************************************/
int DoublyLinkedList::front() const {

    //OUT - return the first element of the linked list's data
    return head->data;
}

/*****************************************************
 *
 *   Method back() const: Class DoublyLinkedList
 ________________________________________________
 *   return the last element in the
 *   linked list's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   the last element's data
 *   in the linked list is returned.
*****************************************************/
int DoublyLinkedList::back() const {

    //OUT - return the tail element of the linked list's data
    return tail->data;
}

/*****************************************************
 *
 *   Method length(IntListIterator  head) const: Class DoublyLinkedList
 ________________________________________________
 *   return the length of the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   the length of the linked list is returned.
*****************************************************/
int DoublyLinkedList::length(IntListIterator head) const {

    //PROCESSING - base case if the element is the last one,
    //then return 0

    if (head == nullptr) {
        return 0;
    }

    //PROCESSING - put the head into the argument for recursive
    head++;
    return 1 + length(head);

}


/*****************************************************
 *
 *   Method operator=(const DoublyLinkedList &D): Class DoublyLinkedList
 ________________________________________________
 *  It is a assignment operator for assigning one
 *  object to another existed
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *  An object is assigned to another object
*****************************************************/
DoublyLinkedList &DoublyLinkedList::operator=(const DoublyLinkedList &D) {


    //if the new object is as same as the current one, return the current one
    if (this == &D) {
        return *this;
    }

    //PROCESSING - initial the head and tail
    head = nullptr;
    tail = nullptr;

    //PROCESSING - set the current to the head
    auto oldCurrent = D.head;

    //PROCESSING - push back all the element from the old linked list
    //to the new linked list
    while (oldCurrent != nullptr) {

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

    return *this;
}

/*****************************************************
 *
 *   DoublyLinkedList(const DoublyLinkedList &D): Class DoublyLinkedList
 ________________________________________________
 *  It is a assignment operator for assigning one
 *  object to another existed(copy constructor)
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *  An object is assigned to another object
*****************************************************/
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &D) {
    //if the new object is as same as the current one, return the current one
    if (D.head == nullptr) {
        return;
    }

    //PROCESSING - initial the head and tail
    head = nullptr;
    tail = nullptr;

    //PROCESSING - set the current to the head
    auto oldCurrent = D.head;

    //PROCESSING - push back all the element from the old linked list
    while (oldCurrent != nullptr) {

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

}

/*****************************************************
 *
 *   pop_back(): Class DoublyLinkedList
 ________________________________________________
 *  It removes the last element in the list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   an IntNode is removed
*****************************************************/
void DoublyLinkedList::pop_back() {

    //PROCESSING - removing the last node in the linked
    //             list
    if (tail->prev != nullptr) {
        auto tempNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete tempNode;
    } else if (tail == head) {
        pop_front();
    }
}

/*****************************************************
 *
 *  display(bool forward ) const: Class DoublyLinkedList
 ________________________________________________
 *  It displays the whole linked list either forward or backward
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   A linked list is displayed.
*****************************************************/
void DoublyLinkedList::display(bool forward ) const {
    //PROCESSING - loop thru the linked list
    // to displace each element
    if (head == nullptr) {
        return;
    }
    if (forward) {

        auto current = head;                        //PROCESSING - starting
                                                    // from the first node

        //PROCESSING - print out the whole linked list in forward
        while (current != nullptr) {

            if (current->next != nullptr) {
                cout << current->data << " ";
            } else {
                cout << current->data;
            }
            current = current->next;
        }
    }else{
        auto current = tail;                               //PROCESSING - starting
                                                            // from the tail node

        //PROCESSING - print out the whole linked list in backward
        while(current != nullptr){
            if (current->prev != nullptr) {
                cout << current->data << " ";
            } else {
                cout << current->data;
            }
            current = current -> prev;
        }
    }
}






