//
// Created by JonathanSum on 5/26/2019.
//

#ifndef UNTITLED5_LINKEDLIST_H
#define UNTITLED5_LINKEDLIST_H

#include <iostream>
#include <cstring>
#include "listEmpty.h"
#include <typeinfo>
#include <string>
#include <sstream>
#include <variant>
using namespace std;


template<class E>
class Node;

template<class E>
class Iterator {
private:
    Node<E> *current;
public:

    Iterator() : current(nullptr) {};

    Iterator(Node<E> *ptr) : current(ptr) {};

    E operator*();

    Iterator<E> operator++();

    const Iterator<E> operator++(int);

    bool operator==(const Iterator &right) const;

    bool operator!=(const Iterator &right) const;

};



template<class E>
E Iterator<E>::operator*() {
    if (current != nullptr) {
        return current->data;
    };
}


template<class E>
Iterator<E> Iterator<E>::operator++() {
    if (current) {
        current = current->next;
    }
    return *this;
}

template<class E>
const Iterator<E> Iterator<E>::operator++(int) {
    Iterator<E> it = *this;
    ++*this;
    return it;
}

template<class E>
bool Iterator<E>::operator==(const Iterator &right) const {

    return current == right.current;
}

template<class E>
bool Iterator<E>::operator!=(const Iterator &right) const {

    return current != right.current;
}




template<typename E>
struct Node {
    E data;
    Node *next;
    Node(E data) : data(data), next(0) {}
};



template<class E>
class LinkedList {
private:
    Node<E> *head;
    Node<E> *tail;
public:

    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList<E> &source);

    LinkedList &operator=(LinkedList const &source);

    ~LinkedList();   //destructor

    void push_back(const E &value);


    //Iterator<E> begin()const;
    Iterator<E> begin()const;

    //Iterator<E> end()const;
     Iterator<E> end()const;
    void pop_front() noexcept;

    void display() const;


};


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

template<class E>
LinkedList<E>::LinkedList(const LinkedList<E> &source) {

    head = nullptr;
    tail = nullptr;

    auto oldCurrent = source.head;

    while (oldCurrent != nullptr) {

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

}

template<class E>
LinkedList<E> &LinkedList<E>::operator=(LinkedList const &source) {

    if (this == &source) {
        return *this;
    }

    head = nullptr;
    tail = nullptr;

    auto oldCurrent = source.head;

    while (oldCurrent != nullptr) {

        push_back(oldCurrent->data);
        oldCurrent = oldCurrent->next;
    }

    return *this;
}


template<class E>
void LinkedList<E>::display() const {


    Node<E> *current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}


#endif //UNTITLED5_LINKEDLIST_H
