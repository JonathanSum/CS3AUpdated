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
#include "linkedList.h"
using namespace std;

template<class E>
class varNode;

template<class E>
class Iterator {
private:
    varNode<E> *current;
public:
    Iterator() : current(nullptr) {};
    Iterator(varNode<E> *ptr) : current(ptr) {};
    E operator*();
    Iterator<E> operator++();
    Iterator<E> operator++(int);
    bool operator==(const Iterator &right) const;
    bool operator!=(const Iterator &right) const;
};
E Iterator<E>::operator*() {
    if (current != nullptr) {
        return current->data;
    };
}
Iterator<E> Iterator<E>::operator++() {
    if (current) {
        current = current->next;
    }
    return *this;
}
Iterator<E> Iterator<E>::operator++(int) {
    Iterator<E> it = *this;
    ++*this;
    return it;
}
bool Iterator<E>::operator==(const Iterator &right) const {

    return current == right.current;
}
bool Iterator<E>::operator!=(const Iterator &right) const {

    return current != right.current;
}


template<typename E>
struct varNode {
    E data;
    varNode *next;
    varNode(E data) : data(data), next(0) {}
};



template<class E>
class LinkedList {
private:
    varNode<E> *head;
    varNode<E> *tail;
public:
    LinkedList() : head(nullptr) {}
    LinkedList(const LinkedList<E> &source);
    LinkedList &operator=(LinkedList const &source);
    ~LinkedList();   //destructor
    void push_back(const E &value);
    Iterator<E> begin();
    Iterator<E> end();
};
void LinkedList<E>::push_back(const E &value) {
    varNode<E> *newNode = new varNode<E>(value);
    varNode<E> *current = head;
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
LinkedList<E>::~LinkedList() {
    varNode<E> *tmp = nullptr;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}
Iterator<E> LinkedList<E>::begin() {
    //OUT - return the head node in type of Iterator class
    return Iterator<E>(head);
}
Iterator<E> LinkedList<E>::end() {
    return Iterator<E>(nullptr);
}



#endif //INC_3A_1_INTLIST_H
