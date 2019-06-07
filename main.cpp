/***********************************************
*   Author         : Jonathan Sum
*   Assignment     : Assignment 5: IntVector
*   SECTION        : CS 003A
*   Due Date       : 4/02/19
*   ________________________________________________
*   Goals
*    Use Qt to create a GUI version of the templated
 *    LinkedList you made for assignment 9.
***********************************************/



#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"




int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();


//    LinkedList< variant< LinkedList<int>, LinkedList<double>, LinkedList<string>,
//            LinkedList<Rational>, LinkedList<Date>, LinkedList<Complex> > > list_of_LinkedList;
//    LinkedList<string> l1;
//    l1.push_back("Zoo");
//    l1.push_back("IPhone");
//    l1.push_back("C++");
//    l1.push_back("Java");
//    l1.push_back("Apple");
//    l1.push_back("Orange");
//    l1.push_back("Car");
//    l1.push_back("House");
//    LinkedList<int> l2;
//    l2.push_back(34);
//    l2.push_back(21);
//    l2.push_back(4);
//    l2.push_back(15);
//    LinkedList<Rational> l3;
//    l3.push_back(Rational(2, 3));
//    l3.push_back(Rational(5));
//    l3.push_back(Rational(4, 5));
//    l3.push_back(Rational(5,999));
//    list_of_LinkedList.push_back(l2);
//    list_of_LinkedList.push_back(l1);
//    list_of_LinkedList.push_back(l3);
//    LinkedList<Date> l4;
//    l4.push_back(Date());
//    l4.push_back(Date(7, 3, 1991));
//    l4.push_back(Date("July", 3, 1991));
//    LinkedList<Complex> l5;
//    l5.push_back(Complex());
//    l5.push_back(Complex());
//    l5.push_back(Complex(5));
//    l5.push_back(Complex(1, 2));
//    l5.push_back(Complex(-13, 21));
//    l5.push_back(Complex(-3, -4));
//    LinkedList<double> l6;
//    l6.push_back(5.598);
//    l6.push_back(644.5);
//    l6.push_back(4521.5);
//    l6.push_back(5656.245);
//    l6.push_back(524.3);
//    l6.push_back(3434.144);
//    l6.push_back(3434.144);
//    list_of_LinkedList.push_back(l6);
//    list_of_LinkedList.push_back(l5);
//    list_of_LinkedList.push_back(l4);
//
//
//    //l3.select_sort();
//    l2.select_sort();
//    l2.insert_sorted(25);
//    for(auto &i: l2){
//        cout<<i<<endl;
//    }
//    auto r1 = Rational(5,999);
//    double t1 = 5.0/999;
//    cout<<t1<<endl;
//    cout<<(r1<(Rational(3,2)))<<endl;
//    cout<<((Rational(4,5))<(r1))<<endl;
//    Complex c1 = Complex(1, 2);
//    Complex c2 = Complex(-13, 21);
//    cout<<(c1>c2)<<endl;
//    cout<<(c1<c2)<<endl;
    return 0;
}







