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

#include "linkedList.h"
#include "listEmpty.h"
#include <iostream>



using namespace std;

/***************************************************
 *
 *   Method display: Class LinkedList
 ________________________________________________
 *   This method displace the whole linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   Same
*****************************************************/
template<class E>
void LinkedList<E>::display() const {
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
 *   Method push_front: Class LinkedList
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
template<class E>
void LinkedList<E>::push_front(const E& value) {

    //PROCESSING - adding the new node and creating the node
    //              with the input value
    auto * newNode = new Node<E>(value);


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
 *   Destructor ~LinkedList(): Class LinkedList
 ________________________________________________
 *   This Destructor free all element in LinkedList
 ________________________________________________
 *   PRE-CONDITIONS
 *   The elements in class are not free in memory.
 *   before removing the node.
 *   POST-CONDITIONS
 *   The elemenst in class are  free in memory
*****************************************************/
template<class E>
LinkedList<E>::~LinkedList() {

    //PROCESSING - loop thru the linked list
    //              free all the element in the linked
    //              list.
    Node<E> *current = head;        //IN - set the current to the head
    Node<E> *next;                  //IN - set create the next node

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
 *   Method push_back(int value): Class LinkedList
 ________________________________________________
 *   This method add a node in the beginning of
 *   the linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   The size is linked list's original the size
 *   POST-CONDITIONS
 *   The size increases by one
*****************************************************/
template<class E>
void LinkedList<E>::push_back(const E& value){


    auto *newNode = new Node<E>(value);         //IN - Create a new node

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
 *   Method select_sort(): Class LinkedList
 ________________________________________________
 *   This method sort the list by swapping
 *   each node's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   unsorted list
 *   POST-CONDITIONS
 *   sorted list
*****************************************************/
template<class E>
void LinkedList<E>::select_sort() {

    Node<E> *current = head;             // PROCESSING current node is the current node
                                         // while looping the list.

    // PROCESSING - loop while the whole linked list
    while (current != nullptr) {
        Node<E> *min = current;
        Node<E> *r = current->next;

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
 *   Method insert_sorted(int value): Class LinkedList
 ________________________________________________
 *   adding a node in to the list before an element
 *   is same or smaller than it.
 ________________________________________________
 *   PRE-CONDITIONS
 *   sorted list
 *   POST-CONDITIONS
 *   sorted list and the size is increased by one
*****************************************************/
template<class E>
void LinkedList<E>::insert_sorted(const E& value  ) {


    Node<E> *current = head,          // PROCESSING current node is the current node
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
        auto *temp = new Node<E>(value);
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
template<class E>
void LinkedList<E>::remove_duplicates() {

    Node<E> *current = head,          // PROCESSING current node is the current node
                                      // while looping the list.

            *previous = nullptr;     // PROCESSING It is the previous node
                                      // of the current node
                                      // while looping the list.

    // PROCESSING - loop while the whole linked list before the list element
    while (current->next != nullptr) {
        Node<E> *min = current;
        Node<E> *r = current->next;

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

/*****************************************************
 *
 *   Method begin(): Class LinkedList
 ________________________________________________
 *   return a LinkedListIterator object
 *   that is the first element in the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   A first element in linked list is returned.
*****************************************************/
template<class E>
Iterator<E> LinkedList<E>::begin() {

    //OUT - return a LinkedListIterator object
    // with a first element of the linked list's data as attribute
    return Iterator<E>(head);
}
template<class E>
Iterator<E> LinkedList<E>::end() {

    //OUT - return a LinkedListIterator object
    // with a tail data as attribute
    return nullptr;
}

/*****************************************************
 *
 *   Method begin(): Class LinkedList
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


/*****************************************************
 *
 *   Method back() const: Class LinkedList
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


/*****************************************************
 *
 *   Method length(LinkedListIterator head) const: Class LinkedList
 ________________________________________________
 *   return the length of the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   the length of the linked list is returned.
*****************************************************/
template<class E>
int LinkedList<E>::length(Iterator<E> head) const {

    //PROCESSING - base case if the element is the last one,
    //then return 0

    if(head == nullptr){
        return 0;
    }

    //PROCESSING - put the head into the argument for recursive
    head++;
    return 1+length(head);

}

/*****************************************************
 *
 *   Method sum(LinkedListIterator head) const: Class LinkedList
 ________________________________________________
 *   return a number that is the sum
 *   of each element of the whole
 *   linked list's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   the sum of the linked list is returned.
*****************************************************/
template<class E>
int LinkedList<E>::sum(Iterator<E> head) const {

    //PROCESSING - base case if the element is the last one,
    //then return 0
    if(head == nullptr){
        return 0;
    }


    int data = *head;       //OUT - the amount in integer of each element

    //PROCESSING - put the head into the argument for recursive
    head++;
    return data+sum(head);
}


/*****************************************************
 *
 *   Method operator=(const LinkedList &list): Class LinkedList
 ________________________________________________
 *  It is a assignment operator for assigning one
 *  object to another existed
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *  An object is assigned to another object
*****************************************************/
template<class E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList &source) {


    //if the new object is as same as the current one, return the current one
    if(this==&source){
        return *this;
    }

    //PROCESSING - initial the head and tail
    head = nullptr;
    tail = nullptr;

    //PROCESSING - set the current to the head
    auto oldCurrent = source.head;

    //PROCESSING - push back all the element from the old linked list
    //to the new linked list
    while(oldCurrent!= nullptr){

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

    return *this;
}




/*****************************************************
 *
 *   LinkedList(const LinkedList &list): Class LinkedList
 ________________________________________________
 *  It is a assignment operator for assigning one
 *  object to another existed(copy constructor)
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *  An object is assigned to another object
*****************************************************/
template<typename E>
LinkedList<E>::LinkedList(const LinkedList &source) {
    //if the new object is as same as the current one, return the current one
    if(source.head== nullptr){
        return;
    }

    //PROCESSING - initial the head and tail
    head = nullptr;
    tail = nullptr;

    //PROCESSING - set the current to the head
    auto oldCurrent = source.head;

    //PROCESSING - push back all the element from the old linked list
    while(oldCurrent!= nullptr){

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

}




/*****************************************************
 *
 *   Method pop_front(): Class LinkedList
 ________________________________________________
 *   This method remove the first node in linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   The size is linked list is the size
 *   before removing the node.
 *   POST-CONDITIONS
 *   The size decreases by one because one
 *   node is removed to the front of the linked list.
*****************************************************
template<class E>
void LinkedList<E>::pop_front() {

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
***/





