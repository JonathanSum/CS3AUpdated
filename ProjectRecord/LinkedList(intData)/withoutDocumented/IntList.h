//
// Created by zerotwo on 4/8/19.
//

#ifndef INC_3A_1_INTLIST_H
#define INC_3A_1_INTLIST_H
#include <iostream>
using namespace std;
struct IntNode {
    int data;
    IntNode *next;

    IntNode(int data) : data(data), next(0) {}
};


class IntList {
private:
    IntNode *head;
    IntNode *tail;
public:
    IntList() : head(nullptr), tail(nullptr) {}

    ~IntList() {
        if (head != nullptr) {
            auto current = head;
            while (current != nullptr) {
                delete current;
                current = current->next;
            }
        }
        head = nullptr;
        tail = nullptr;
    };

    void display() const;

    void push_front(int value);

    void pop_front();

};


#endif //INC_3A_1_INTLIST_H
