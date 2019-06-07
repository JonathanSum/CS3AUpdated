#include "mainwindow.h"
#include <QApplication>
#include "linkedList.h"
int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//
//    return a.exec();
    variant<LinkedList<int>, LinkedList<string>> l2;
    LinkedList<int> *l3=&get< LinkedList<int>   >(l2);
    const auto &a1ptr = &l2;


    cout<<"&a1 "<<a1ptr<<endl;
    cout<<"&a2 "<<l3<<endl;
    return 0;
}
