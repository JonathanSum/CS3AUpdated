#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QListWidgetItem>
#include "linkedList.h"
#include <variant>
#include <string>
#include <QApplication>
#include <QtWidgets/QTreeWidgetItem>
#include "Rational.h"
#include "Date.h"
#include "complex.h"
#include "intVector.h"
#include "stringVector.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
            /**************************************
            **      DESTRUCTOR & CONSTRUCTOR    **
            ***************************************/
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;

    // A big mother list to contains int, double, string, Rational, Date, Complex
    LinkedList<



    variant<


    LinkedList<int>, LinkedList<double>, LinkedList<string>,
    LinkedList<Rational>, LinkedList<Date>, LinkedList<Complex> > > list_of_LinkedList;

    void dropToListWidget();
    int intListIndex;
    int doubleListIndex;
    int stringListIndex;
    int rationalListIndex;
    int dateListIndex;
    int complextListIndex;
    int listId;
    bool showAll=true;

    IntVector typeList = IntVector(50);
    IntVector showList = IntVector(700);
    bool displayClicked=false;
    bool listClicked=false;

    void noListClickedMessage();
    void emptyStringMessage();
    void push_back_by_type(int the_integer1, int the_integer2, int the_integer3,
                           double the_double1, double the_double2, const string &the_string,
                           int the_type_index, int selectedIndex, int selectedNode, unsigned operation);
    int sizeOfList()const;
    string displayString;
    int displayStringListSize=0;
    StringVector displayList =StringVector(50);
};

#endif // MAINWINDOW_H
