//
// Created by zerotwo on 4/8/19.
//

#include "IntList.h"
#include <iostream>

using namespace std;

void IntList::display() const {
    if (head == nullptr) {
        return;
    }
    auto current = head;
    while (current != nullptr) {
        if(current->next!= nullptr){
            cout << current->data << " ";
        }else{
            cout << current->data;
        }
        current = current->next;
    }
}

void IntList::push_front(int value) {

    auto *newNode = new IntNode(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void IntList::pop_front() {
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
