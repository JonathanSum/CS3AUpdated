#include <iostream>
#include "linkedList.h"

/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 9: Linked List - Templates and Exceptions
 *   SECTION        : CS 003A
 *   Due Date       : 5/26/19
 *   ________________________________________________
 *   Goals
 *     generalize your IntList class using templates and exception.
***********************************************/




using namespace std;



int main()
{
    cout<<"Testing push_back function"<<endl;
    LinkedList<int> list1;
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);
    list1.push_back(8);
    cout<<"Testing push_front function"<<endl;
    list1.push_front(4);
    list1.push_front(3);
    list1.push_front(9);
    list1.push_front(12);
    list1.push_front(9);
    list1.push_front(5);
    cout<<"Testing select_sort function"<<endl;
    list1.select_sort();
    cout<<"Testing display() function"<<endl;
    list1.display();
    cout<<endl;\
    cout<<"Testing remove_duplicates() function"<<endl;
    list1.remove_duplicates();
    list1.display();
    cout<<endl;
    list1.display();
    cout<<endl;
    cout<<"Testing length() function"<<endl;
    cout<<list1.length(list1.begin());
    cout<<endl;
    cout<<"Testing sum() function"<<endl;
    cout<<list1.sum(list1.begin());
    cout<<endl;
    LinkedList<char> list2;
    cout<<"Testing function push_back: a r d d i m m y "<<endl;
    list2.push_back('a');
    list2.push_back('r');
    list2.push_back('d');
    list2.push_back('d');
    list2.push_back('l');
    list2.push_back('m');
    list2.push_back('m');
    list2.push_back('y');
    cout<<"Testing function push_front: z a a a r d d i m m y "<<endl;
    list2.push_front('a');
    list2.push_front('z');
    list2.push_front('z');
    list2.display();
    cout<<endl;
    cout<<"Testing select_sort "<<endl;
    list2.select_sort();
    list2.display();
    cout<<endl;
    list2.insert_sorted('x');
    list2.display();
    cout<<endl;
    list2.insert_sorted('x');
    list2.display();
    cout<<endl;
    cout<<"Testing function remove_duplicates "<<endl;
    list2.remove_duplicates();
    list2.display();
    cout<<endl;
    list2.pop_front();
    cout<<"Testing iterator and pop_front"<<endl;
    for ( auto iterator = list2.begin(); iterator != list2.end(); iterator++){
        cout<<*iterator<<" ";
    }
    cout<<endl;
    cout<<"Testing back() function"<<endl;
    cout<<list2.back();
    cout<<endl;
    cout<<"Testing front() function"<<endl;
    cout<<list2.front()<<endl;
    cout<<endl;
    cout<<"Testing length() function"<<endl;
    cout<<list2.length(list2.begin());
    cout<<endl;
    cout<<"Testing sum() function"<<endl;
    cout<<list2.sum(list2.begin());
    cout<<endl;
    cout<<"Testing is empty function"<<endl;
    cout<<list2.isEmpty();
    cout<<endl;
    cout<<"Testing is clear function"<<endl;
    list2.clear();
    cout<<endl;
    for ( auto iterator = list2.begin(); iterator != list2.end(); iterator++){
        cout<<*iterator<<" ";
    }
    LinkedList<string> list3;
    list3.push_back("Zero");
    list3.push_back("Two");
    list3.push_back("is");
    list3.push_back("the");
    list3.push_back("best.");
    list3.display();
    cout<<endl;
    cout<<"testing Assignment operator "<<endl;
    LinkedList<string> list4;
    list4 = list3;
    list4.display();
    cout<<endl;
    cout<<"testing copy constructor "<<endl;
    LinkedList<string> list5 = list3;
    list5.display();
    cout<<endl;
    cout<<"testing length for string linked list"<<endl;
    cout<<list5.length(list5.begin())<<endl;
    cout<<"testing the exception for front(), back() and pop front"<<endl;
    LinkedList<string>  list6;
    cout<<"returning the front for string empty list"<<endl;
    list6.front();
    cout<<"returning the back for string empty list"<<endl;
    list6.back();
    cout<<"removing the front for string empty list"<<endl;
    list6.pop_front();
    cout<<endl;
    LinkedList<int>  list7;
    cout<<"returning the front for int empty list"<<endl;
    list6.front();
    cout<<"returning the back for int empty list"<<endl;
    list6.back();
    cout<<"removing the front for int empty list"<<endl;
    list6.pop_front();
    cout<<endl;
    return 0;
}