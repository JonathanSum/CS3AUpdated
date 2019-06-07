//
// Created by JonathanSum on 5/26/2019.
//

#ifndef UNTITLED5_LINKEDLIST_H
#define UNTITLED5_LINKEDLIST_H

#include <iostream>
#include <cstring>
#include "listEmpty.h"
#include <typeinfo>
using namespace std;


template<class E>
class Node;

template<class E>
class Iterator {
private:
    Node<E> *current;
public:
    /**************************************
            **      CONSTRUCTOR    **
    ***************************************/
    Iterator() : current(nullptr) {};

    Iterator(Node<E> *ptr) : current(ptr) {};

    /**********************
         * * MUTATORS **
    **********************/
    E operator*();

    Iterator<E> operator++();

    Iterator<E> operator++(int);

/**********************
    * * ACCESSORS **
 **********************/
    bool operator==(const Iterator &right) const;

    bool operator!=(const Iterator &right) const;
};
/*********************************************************************
   * Iterator Class
   * This class represents a Iterator object.
   * It manages 1 attributest,
   * current of the Node of the Node class.
*********************************************************************/



/**********************
** Member Functions **
**********************/


/*****************************************************
 *
 *   Method operator*(): Class Iterator
 ________________________________________________
 *   This method return the data of the node
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   data of the node is returned
*****************************************************/
template<class E>
E Iterator<E>::operator*() {
    if (current != nullptr) {
        return current->data;
    };
}

/*****************************************************
 *
 *   Method operator++(): Class Iterator
 ________________________________________________
 *   This method return the node of the next node
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   next node of the node is returned
*****************************************************/
template<class E>
Iterator<E> Iterator<E>::operator++() {
    if (current) {
        current = current->next;
    }
    return *this;
}
/*****************************************************
 *
 *   Method operator++(): Class Iterator
 ________________________________________________
 *   This method return the node of the next node
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   next node of the node is returned
*****************************************************/
template<class E>
Iterator<E> Iterator<E>::operator++(int) {
    Iterator<E> it = *this;
    ++*this;
    return it;
}
/*****************************************************
 *
 *   Method operator==(const Iterator &right) const: Class Iterator
 ________________________________________________
 *   This method return the node of the next node
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   return a boolean if two nodes are the same
*****************************************************/
template<class E>
bool Iterator<E>::operator==(const Iterator &right) const {

    return current == right.current;
}
/*****************************************************
 *
 *   Method operator!=(const Iterator &right) const : Class Iterator
 ________________________________________________
 *   This method return the node of the next node
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   return a boolean if two nodes are not the same
*****************************************************/
template<class E>
bool Iterator<E>::operator!=(const Iterator &right) const {

    return current != right.current;
}


template<typename E>
struct Node {
    E data;
    Node *next;
    /**************************************
              **  CONSTRUCTOR  **
    ***************************************/
    Node(E data) : data(data), next(0) {}
};
/*********************************************************************
   * Node struct
   * This struct represents a Node object.
   * It manages 2 attributest,
   * data of the node
   * address of the next node
*********************************************************************/


template<class E>
class LinkedList {
private:
    Node<E> *head;
    Node<E> *tail;
public:
    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList<E> &source);

    LinkedList &operator=(LinkedList const &source);

    ~LinkedList();   //destructor
    /**********************
         * * MUTATORS **
    **********************/
    void push_back(const E &value);

    void push_front(const E &value);


    void select_sort();

    void clear();

    void insert_sorted(const E &value);

    void remove_duplicates();

    Iterator<E> begin();

    Iterator<E> end();

    void pop_front() throw(ListEmpty);

    /**********************
        * * ACCESSORS **
     **********************/

    bool isEmpty() const;

    void display() const;

    const E &front() const throw(ListEmpty);;

    const E &back() const throw(ListEmpty);

    int length(Iterator<E> head) const;

    int sum(Iterator<E> head) const;


};



/*********************************************************************
   * LinkedList Class
   * This class represents a LinkedList object.
   * It manages 2 attributest,
   * tail of the LinkedList node
   * head of the LinkedList node
*********************************************************************/







    /**********************
    * * Member Functions **
    **********************/


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
void LinkedList<E>::push_back(const E &value) {
    Node<E> *newNode = new Node<E>(value);
    Node<E> *current = head;
    if (current == nullptr) {
        head = newNode;
    } else {
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        tail = newNode;
    }

}

/*****************************************************
 *
 *   Destructor ~LinkedListt<E>:: Class LinkedList
 ________________________________________________
 *   This Destructor free all element in IntList
 ________________________________________________
 *   PRE-CONDITIONS
 *   The elements in class are not free in memory.
 *   before removing the node.
 *   POST-CONDITIONS
 *   The elemenst in class are  free in memory
*****************************************************/
template<class E>
LinkedList<E>::~LinkedList() {
    Node<E> *tmp = nullptr;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}


/*****************************************************
 *
 *   LinkedList(const LinkedList<E> &source): Class LinkedList
 ________________________________________________
 *  (copy constructor)
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *  An object is assigned to another object
*****************************************************/
template<class E>
LinkedList<E>::LinkedList(const LinkedList<E> &source) {


    //PROCESSING - initial the head and tail
    head = nullptr;
    tail = nullptr;

    //PROCESSING - set the current to the head
    auto oldCurrent = source.head;

    //PROCESSING - push back all the element from the old linked list
    //to the new linked list
    while (oldCurrent != nullptr) {

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

}

/*****************************************************
 *
 *   Method: operator=(LinkedList const &source): Class LinkedList
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
LinkedList<E> &LinkedList<E>::operator=(LinkedList const &source) {
    //if the new object is as same as the current one, return the current one
    if (this == &source) {
        return *this;
    }

    //PROCESSING - initial the head and tail
    head = nullptr;
    tail = nullptr;

    //PROCESSING - set the current to the head
    auto oldCurrent = source.head;

    //PROCESSING - push back all the element from the old linked list
    //to the new linked list
    while (oldCurrent != nullptr) {

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

    return *this;
}

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

    //CALC - storing the head for looping
    Node<E> *current = head;
    //PROCESSING - displaying every node
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

/*****************************************************
 *
 *   Method push_front(const E &value) : Class LinkedList
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
void LinkedList<E>::push_front(const E &value) {

    //PROCESSING - adding the new node and creating the node
    //              with the input value
    auto *newNode = new Node<E>(value);


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
 *   Method front() const throw(ListEmpty: Class LinkedList
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
template<class E>
const E &LinkedList<E>::front() const throw(ListEmpty) {
    try {
        if (isEmpty()) {
            ListEmpty empty;
            throw empty;
        }
        return head->data;
    }
    catch (ListEmpty &eObj) {
        cout << eObj.what() << endl;
    }

}
/*****************************************************
 *
 *   Method: back() const throw(ListEmpty): Class ListEmpty
 ________________________________________________
 *   return the last element in the
 *   linked list's data
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   A last element's data
 *   in the linked list is returned.
*****************************************************/
template<class E>
const E &LinkedList<E>::back() const throw(ListEmpty) {
    try {
        if (isEmpty()) {
            ListEmpty empty;
            throw empty;
        }
        return tail->data;
    }
    catch (ListEmpty &eObj) {
        cout << eObj.what() << endl;
    }
}
/*****************************************************
 *
 *   Method: clear(): Class LinkedList
 ________________________________________________
 *   It delete everything in the list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   whole list is deleted
*****************************************************/
template<class E>
void LinkedList<E>::clear() {

    //CALC- a template node for storing the head.
    Node<E> *tmp = nullptr;

    //PROCESSING - loop through the list and delete everything
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}
/*****************************************************
 *
 *   Method insert_sorted(const E &value) : Class LinkedList
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
void LinkedList<E>::insert_sorted(const E &value) {


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
 *   Method remove_duplicates(int value): Class LinkedList
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
        previous = current;
        current = current->next;

    }

    //PROCESSING - here is the case for delete tail and previous of tail,
    //            if they are the same.
    if (previous != nullptr) {

        if (previous->data == current->data) {

            previous->next = nullptr;
            delete current;
            tail = previous;
        }
    }
}
/*****************************************************
 *
 *   Method sum(IntListIterator head) const: Class LinkedList
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

    if (string(typeid(*head).name()) != "i" && string(typeid(*head).name()) != "d" &&
        string(typeid(*head).name()) != "f") {

        cout << "This is not a linked list of integer, float, or double,\n"
             << "but it is a linked list of " << typeid(E).name() << ", so\n"
             << "there is no sum for the linked list. case: ";
        return 0;
    }

    //PROCESSING - base case if the element is the last one,
    //then return 0
    if (head == nullptr) {
        return 0;
    }


    int data = *head;       //OUT - the amount in integer of each element

    //PROCESSING - put the head into the argument for recursive
    head++;
    return data + sum(head);
}
/*****************************************************
 *
 *   Method length(Iterator<E> head) const: Class LinkedList
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

    if (head == nullptr) {
        return 0;
    }

    //PROCESSING - put the head into the argument for recursive
    head++;
    return 1 + length(head);

}
/*****************************************************
 *
 *   Method begin(): Class LinkedList
 ________________________________________________
 *   return a Iterator object
 *   that is the first element in the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   The first element in linked list is returned.
*****************************************************/
template<class E>
Iterator<E> LinkedList<E>::begin() {
    //OUT - return the head node in type of Iterator class
    return Iterator<E>(head);
}
/*****************************************************
 *
 *   Method begin(): Class LinkedList
 ________________________________________________
 *   return a Iterator object
 *   that is the first element in the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   The last element in linked list is returned.
*****************************************************/
template<class E>
Iterator<E> LinkedList<E>::end() {
    return Iterator<E>(nullptr);
}
/*****************************************************
 *
 *   pop_front() throw(ListEmpty): Class LinkedList
 ________________________________________________
 *   return a Iterator object
 *   that is the first element in the
 *   linked list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   The last element in linked list is returned.
*****************************************************/
template<class E>
void LinkedList<E>::pop_front() throw(ListEmpty) {

    try {
        if (isEmpty()) {
            ListEmpty empty;
            throw empty;
        }

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
    catch (ListEmpty &obj) {
        //PROCESSING print the list is empty
        cout << obj.what() << endl;
    }

}
/*****************************************************
 *
 *   Method: isEmpty(): Class LinkedList
 ________________________________________________
 *   return a boolean whether or not the list
 *   is empty
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   A boolean is returned whether or not the list
 *   is empty
*****************************************************/
template<class E>
bool LinkedList<E>::isEmpty() const {

    //PROCESSING return true if the head is empty
    return (head == nullptr);
}


#endif //UNTITLED5_LINKEDLIST_H
