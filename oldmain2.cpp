#include <iostream>
#include "linkedList.h"
#include <list>
#include <string>
#include <variant>
#include "intVector.cpp"
#include "intVector.h"
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


int main() {
    cout << "Testing push_back function" << endl;
    LinkedList<int> list1;
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);
    list1.push_back(8);
    cout << "Testing push_front function" << endl;
    list1.push_front(4);
    list1.push_front(3);
    list1.push_front(9);
    list1.push_front(12);
    list1.push_front(9);
    list1.push_front(5);
    cout << "Testing select_sort function" << endl;
    list1.select_sort();
    cout << "Testing display() function" << endl;
    list1.display();
    cout << endl;\
    cout << "Testing remove_duplicates() function" << endl;
    list1.remove_duplicates();
    list1.display();
    cout << endl;
    list1.display();
    cout << endl;
    cout << "Testing length() function" << endl;
    cout << list1.length(list1.begin());
    cout << endl;
    cout << "Testing sum() function" << endl;
    cout << list1.sum(list1.begin());
    cout << endl;
    LinkedList<string> list2;
    cout << "Testing function push_back: a r d d i m m y " << endl;
    list2.push_back("a");
    list2.push_back("r");
    list2.push_back("d");
    list2.push_back("d");
    list2.push_back("l");
    list2.push_back("m");
    list2.push_back("m");
    list2.push_back("y");
    cout << "Testing function push_front: z a a a r d d i m m y " << endl;
    list2.push_front("a");
    list2.push_front("z");
    list2.push_front("");
    list2.display();
    LinkedList<int> list3;
    list3.push_front(675);
    list3.push_front(22);
    list3.push_front(532);
    list3.push_front(152);
    list3.push_front(90);
    list3.push_front(768);
    cout << endl;


    cout << "Testing start... " << endl;


    LinkedList<variant< LinkedList<int>,LinkedList<string> >> list_of_lists ;
    list_of_lists.push_back(list3);
    list_of_lists.push_back(list2);
    list_of_lists.push_back(list1);
    variant< LinkedList<string> ,LinkedList<int>>  v;
    std::cout << "v.index = " << v.index() << '\n';
    int lasta;
    string lasts;
    for(const auto&v : list_of_lists){
        if(holds_alternative< LinkedList<int> >(v)){
            cout<<"Testing int ... "<<endl;
            std::cout << "v.index = " << v.index() << '\n';
            const auto &ListInt = get<LinkedList<int>>(v);
            for ( auto iterator = ListInt.begin(); iterator != ListInt.end(); iterator++) {
                cout << *iterator << " ";
                lasta =*iterator;
            }
            cout<<endl;
        }else if(holds_alternative< LinkedList<string> >(v)){
            cout<<"Testing string ... "<<endl;
            std::cout << "v.index = " << v.index() << '\n';
            get<LinkedList<string>>(v).display();
            const auto &Lists = get<LinkedList<string>>(v);
            for ( auto iterator = Lists.begin(); iterator != Lists.end(); iterator++) {
//                cout << *iterator << " ";
                string temp = *iterator;
                cout<<"temp: "<<temp<<endl;
                lasts= *iterator;
            }
//            lasts =*iterator;
            cout<<endl;
        }

    }
    cout<<"endl "<<lasts<<endl;

//
//
//    cout<<endl;
//    cout << "Printing a vector list that has different type of list  start... " << endl;
//    for (const auto& v : list_of_lists) {
//        visit([](auto&& arg) {arg.display();}, v);
//        cout<<endl;
//    }
//    cout<<endl;
//    cout << "Printing the index 2 list of the list of list... " << endl;
//    int index=0;
//    int none = 0;
//    string last;
//    for ( const auto&u : list_of_lists) {
//
//            visit([&last](auto&& arg)mutable {
//
//                arg.display();
//                for( auto j:arg){
//
//                    last=j;
//                    cout<<"debugging j "<<last<<endl;
//                }
//            }, u);
//        if (holds_alternative<list<std::string>>(u)){
//                for( auto i: get<LinkedList<int>>(u)){
//                    cout << "Printing 3 " <<i<< endl;
//
//                }
//            }
//
//
//
//
//        index++;
//    }
//    cout<<"debugging last : "<<last<<endl;
//    cout<<"debugging last none: "<<none<<endl;




    return 0;
}



























