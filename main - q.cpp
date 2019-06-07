//#include "mainwindow.h"
//#include <QApplication>
//#include "ui_mainwindow.h"
#include "linkedList.h"
#include <iostream>
#include <list>
#include <string>
#include <variant>
using namespace std;
int main()
{

    LinkedList< variant< LinkedList<int>, LinkedList<string> > > list_of_LinkedList;
    std::list<std::variant<std::list<int>, std::list<std::string>>> list_of_lists;

    LinkedList<string> l1;
    l1.push_back("Start");
    l1.push_back("Sun");
    l1.push_back("Earth");
    l1.push_back("Moon");

    LinkedList<int> l2;
    cout<<&l2<<endl;
    l2.push_back(5);
    l2.push_back(1);
    l2.push_back(5);
    l2.push_back(15);
    list_of_LinkedList.push_back(l1);
    list_of_LinkedList.push_back(l2);
    for (  auto &v : list_of_LinkedList){
        if (std::holds_alternative<  LinkedList<int>   >(v)) {

            auto& Listi=get< LinkedList<int> >(v);
            Listi.push_back(5);
            cout<<"address: "<<&Listi<<endl;
            for ( auto iterator = Listi.begin(); iterator != Listi.end(); iterator++) {

                int temp = *iterator;
                cout<<"temp: "<<temp<<endl;
            }
            std::cout << '\n';
        }
        else if (std::holds_alternative<  LinkedList<string>   >(v)) {

                        auto& Lists=get< LinkedList<string> >(v);
                        cout<<"address: "<<&Lists<<endl;
            for ( auto iterator = Lists.begin(); iterator != Lists.end(); iterator++) {

                string temp = *iterator;
                cout<<"temp: "<<temp<<endl;
            }
            std::cout << '\n';
        }
    }


cout<<"hi"<<endl;






}
