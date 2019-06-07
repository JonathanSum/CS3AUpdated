#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "doublyLinkedList.h"
/***********************************************
*   Author         : Jonathan Sum
*   Assignment     : Lab 15
*   SECTION        : CS 003A
*   Due Date       : 5/02/19
*   ________________________________________________
*   Goals
*   Begin implementation of a doubly-linked list.
***********************************************/
using namespace std;

#include "IntListIterator.h"
#include "doublyLinkedList.h"
#include "doublyLinkedList.cpp"
#include "IntListIterator.cpp"


int main(){
    DoublyLinkedList L1, L2;

    cout << "Testing display function on empty List\n";
    L1.display();
    
    cout << "\nTesting display function on one item List\n";
    L1.push_front(100);
    L1.display();
    cout << endl;
    
    cout << "\nTesting display function on two item List\n";
    L1.push_front(200);
    L1.display();
    cout << endl;
    
    cout << "\nTesting push_front function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.push_front(i);
    }
    
    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;
    cout<<"Testing IntListIterator class with L1"<<endl;
    for(IntListIterator it = L1.begin(); it != L1.end(); it++ ){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Testing Length function"<<endl;
    cout<<"length of the length is 12 and result is :"<<L1.length(L1.begin());
    cout<<endl;
    cout<<endl;

    cout<<endl;
    cout<<"testing front() function of L1: "<<endl;
    cout<<L1.front();
    cout<<endl;
    cout<<"testing back() function of L1: "<<endl;
    cout<<L1.back();
    cout<<endl;
    cout<<"testing assignment operator: "<<endl;
    L2 = L1;
    L2.display();
    cout<<endl;
    cout<<"testing copy constructor : "<<endl;
    DoublyLinkedList L4 = L2;
    L4.display();
    cout<<endl;
    cout<<"end"<<endl;







    //The following is from the old assignment

    cout << "Testing display function on empty List\n";
    L1.display();

    cout << "\nTesting display function on one item List\n";
    L1.push_front(100);
    L1.display();
    cout << endl;

    cout << "\nTesting display function on two item List\n";
    L1.push_front(200);
    L1.display();
    cout << endl;

    cout << "\nTesting push_front function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.push_front(i);
    }

    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;

    cout << "\nTesting the pop_front function\n";
    for (int i = 0; i < 5; i++){
        L1.pop_front();
    }

    cout << "Testing display function after calling pop_front 5 times\n";
    L1.display();
    cout << endl;

    cout << "\nTesting push_back function (by calling it 5 times)\n";
    for (int i = 0; i < 5; i++){
        L1.push_back(i);
    }
    L1.display();
    cout << endl;

    cout << "\nTesting the pop_back function\n";
    for (int i = 0; i < 5; i++){
        L1.pop_back();
    }
    cout << "Testing display function after calling pop_back 5 times\n";
    L1.display();
    cout << endl;

    cout << "\nTesting push_back function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.push_back(rand()%10);
    }

    L1.display();
    cout << endl;

    cout << "\nTesting sort() function\n";
    L1.sort();
    L1.display();
    cout << endl;

    cout << "\nTesting insert_sorted function (by calling it 10 times)\n";
    for (int i = 0; i < 10; i++){
        L1.insert_sorted(rand()%10);
        cout << endl;
        L1.display();
    }

    cout << "\nTesting remove by removing the 200, 2, 0, 200 function\n";
    cout<<"Creative Test Cases: removing the head and tail too\n";
    L1.remove(200);
    L1.remove(2);
    L1.remove(0);
    L1.remove(200);
    L1.display();
    cout << endl;

    cout << "\nTesting push_back() and push_front() function\n";
    for (int i = 0; i < 10; i++){
        L2.push_front(i);
        L2.push_back(i);
    }

    cout << endl;
    L2.display();
    cout << endl;
    cout<<"end of end";
    return 0;
}
