//
// Created by JonathanSum on 4/4/2019.
//
#include <iostream>
#include <fstream>
#include "header.h"
#include <iomanip>

void studentList::readFile(const string &input_file) {


    studentNode *tempNode = nullptr;

    int lineNumber = 1;
    string line;
    ifstream myFile(input_file.c_str());
    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            if (lineNumber == 1) {

                tempNode = new studentNode();
                string fullName = line.substr(0, line.size() - 1);
                tempNode->name = fullName;
            }
            if (lineNumber == 2) {
                int year = atoi(line.c_str());
                tempNode->age = year;
            }
            if (lineNumber == 3) {
                string subject = line.substr(0, line.size() - 1);
                tempNode->major = subject;
            }
            if (lineNumber == 4) {
                double gradePoint = atof(line.c_str());
                tempNode->gpa = gradePoint;
            }
            if (lineNumber == 5) {
                lineNumber = 0;
                push_front(tempNode);
                tempNode = nullptr;
            }
            lineNumber++;
        }
        myFile.close();
    } else cout << "Unable to open file";
}

void studentList::printList() {
    if (first == nullptr) {
        cout << "The list is empty" << endl;
    }
    studentNode *current = first;
    cout << "Name           Age    Major          GPA" << endl;
    while (current != nullptr) {
        cout << setw((static_cast<int>(current->name.size())) + (15 - (static_cast<int>(current->name.size())))) << left
             << current->name;
        cout << setw(2 + (7 - 2)) << left << current->age;
        cout << setw(3 + (15 - 3)) << left << current->major;
        cout << setprecision(1) << fixed;
        cout << current->gpa << endl;
        current = current->next;
    }
    cout << endl;
};

void studentList::push_front(studentNode *node) {
    if (first == nullptr) {
        first = node;
        return;
    }
    node->next = first;
    first = node;
}

void studentList::push_back(studentNode *node) {
    if (first == nullptr) {
        first = node;
        return;
    }

    studentNode *current = first;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = node;
};

void studentList::search(string studentName) {
    if (first == nullptr) {
        cout << "The list is empty" << endl;
    }
    studentNode *current = first;

    while (current != nullptr) {
        if (current->name == studentName) {
            cout << "Student Found:" << endl;
            cout << setw((static_cast<int>(current->name.size())) + (15 - (static_cast<int>(current->name.size()))))
                 << left << current->name;
            cout << setw(2 + (7 - 2)) << left << current->age;
            cout << setw(3 + (15 - 3)) << left << current->major;
            cout << setprecision(1) << fixed;
            cout << current->gpa << endl;
            cout << endl;
            return;
        }
        current = current->next;
    }

};


void studentList::remove(string studentName) {

    studentNode *current = first,
            *previous = nullptr;

    while (current->name != studentName && current != nullptr) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {


        cout << "There is no " << studentName << " in the list." << endl;
    } else if (current == first) {

        //OUT - print the student node which is going to be delete
        cout << "Front Node Deleted:\n";

        cout << "Name           Age    Major          GPA" << endl;

        cout << setw((static_cast<int>(current->name.size())) + (15 - (static_cast<int>(current->name.size()))))
             << left << current->name;
        cout << setw(2 + (7 - 2)) << left << current->age;
        cout << setw(3 + (15 - 3)) << left << current->major;
        cout << setprecision(1) << fixed;
        cout << current->gpa << endl;
        cout << endl;

        //PROCESSING - delete the first node in the linked list(student list)


        first = first->next;
        delete current;
        current = nullptr;

        //OUT - print the updated student list
        cout << "\nUpdated Student List:\n";
        printList();
    } else {



        //OUT - print the student node which is going to be delete

        cout << "Front Node Deleted:\n";

        cout << "Name           Age    Major          GPA" << endl;

        cout << setw((static_cast<int>(current->name.size())) + (15 - (static_cast<int>(current->name.size()))))
             << left << current->name;
        cout << setw(2 + (7 - 2)) << left << current->age;
        cout << setw(3 + (15 - 3)) << left << current->major;
        cout << setprecision(1) << fixed;
        cout << current->gpa << endl;
        cout << endl;

        //PROCESSING - delete the targeted node in the linked list(student list)

        previous->next = current->next;
        delete current;
        current = nullptr;

        //OUT - print the updated student list
        cout << "\nUpdated Student List:\n";
        printList();
    }

}

void studentList::avgGPA()  {
    double totalGpa=0;
    int numberOfStudent=0;
    studentNode *current = first;
    while(current!= nullptr){
        totalGpa+=current->gpa;
        numberOfStudent++;
        current=current->next;
    }
    cout << setprecision(1) << fixed;
    cout<<"GPA: "<<(totalGpa/numberOfStudent)<<endl;
};































