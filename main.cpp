/***********************************************
*   Author         : Jonathan Sum
*   Assignment     : Assignment :Final Project
*   SECTION        : CS 003A
*   Due Date       : 6/10/19
*   ________________________________________________
*   Goals
*    Write a GUI
***********************************************/



#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"




int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();


}







