//
// Created by JonathanSum on 4/4/2019.
//
#include <iostream>

#ifndef INC_3A_HEADER_H
#define INC_3A_HEADER_H
using namespace std;

struct studentNode {
    string name;
    int age;
    string major;
    double gpa;
    studentNode *next;

    studentNode() : next(nullptr), age(0), gpa(0) {};
};

struct studentList {
    studentNode *first;

    void readFile(const string &input_file);

    void printList();
    void push_back(studentNode *node);
    void push_front(studentNode *node);
    void remove(string studentName);
    void search(string studentName);
    void avgGPA();

    studentList() : first(nullptr) {}

};


#endif //INC_3A_HEADER_H
