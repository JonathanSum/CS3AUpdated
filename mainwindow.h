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
    /**********************
         * * MUTATORS **
    **********************/
    void on_pushButton_clicked() ;
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

protected:
    void paintEvent(QPaintEvent *);

private:
    //OUT - the UI
    Ui::MainWindow *ui;

    //IN - A big mother list to contains int, double, string, Rational, Date, Complex
    LinkedList<
    variant<
    LinkedList<int>, LinkedList<double>, LinkedList<string>,
    LinkedList<Rational>, LinkedList<Date>, LinkedList<Complex> > > list_of_LinkedList;

    int intListIndex;       //IN -  total number of the int index
    int doubleListIndex;       //IN -  total number of the double index
    int stringListIndex;       //IN -  total number of the string index
    int rationalListIndex;       //IN -  total number of the int index
    int dateListIndex;       //IN -  total number of the date index
    int complextListIndex;       //IN -  total number of the complex index
    int listId;       //IN -  type list in id
    IntVector typeList = IntVector(50);     //IN - An int list vector stores list type in int
    bool displayClicked=false;     //IN - boolean shows the display button was clicked or not
    bool listClicked=false;     //IN - boolean shows the list was clicked or not


    /**********************
        * * ACCESSORS **
    **********************/
    int sizeOfList()const;
    void noListClickedMessage() const;
    void emptyStringMessage()const;
    /**********************
         * * MUTATORS **
    **********************/
    void dropToListWidget();
    void push_back_by_type(int the_integer1,    //IN - the first intergeral to be use based on operation
            int the_integer2,    //IN - the second intergeral to be use based on operation
            int the_integer3,    //IN - the third intergeral to be use based on operation
            double the_double1,    //IN - the first double to be use based on operation
            double the_double2,    //IN - the second double to be use based on operation
            const string &the_string,    //IN - the first string to be use based on operation
            int the_type_index,    //IN - the type of the list
            int selectedIndex,    //IN - the list index in mother list
            int selectedNode,    //IN - the node index in child list
            unsigned operation);    //IN - the operation in number


};
/*********************************************************************
   * MainWindow Class
   * This class represents a IntList object.
   * It manages 10 attributest,
   * vint intListIndex;       //IN -  total number of the int index
   * int doubleListIndex;       //IN -  total number of the double index
   * int stringListIndex;       //IN -  total number of the string index
   * int rationalListIndex;       //IN -  total number of the int index
   * int dateListIndex;       //IN -  total number of the date index
   * int complextListIndex;       //IN -  total number of the complex index
   * int listId;       //IN -  type list in id
   * IntVector typeList = IntVector(50);     //IN - An int list vector stores list type in int
   * bool displayClicked=false;     //IN - boolean shows the display button was clicked or not
   * bool listClicked=false;     //IN - boolean shows the list was clicked or not

*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  explicit MainWindow(QWidget *parent = nullptr);
 *  Constructor;    Initialize class attributes
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~MainWindow();
 *  Destructor;   deallocate all element
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 * dropToListWidget();
 * Mutator: putting all the data to the mother list
 * list.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_clicked() ;
 * Mutator: display button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_2_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_3_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_4_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_5_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_6_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_6_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_7_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_8_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_9_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_10_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void on_pushButton_11_clicked() ;
 * Mutator: pushButton button
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void push_back_by_type
 * Mutator: editing the child list
 *--------------------------------------------------------------------
 * Parameter: int the_integer1,    //IN - the first intergeral to be use based on operation
            int the_integer2,    //IN - the second intergeral to be use based on operation
            int the_integer3,    //IN - the third intergeral to be use based on operation
            double the_double1,    //IN - the first double to be use based on operation
            double the_double2,    //IN - the second double to be use based on operation
            const string &the_string,    //IN - the first string to be use based on operation
            int the_type_index,    //IN - the type of the list
            int selectedIndex,    //IN - the list index in mother list
            int selectedNode,    //IN - the node index in child list
            unsigned operation);    //IN - the operation in number
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/
/*********************************************************************
 * noListClickedMessage();
 * Accessor: tells the user that the user did not select list
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * emptyStringMessage();
 * Accessor: tells the user that the user did not input for push back or more
 * list.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
#endif // MAINWINDOW_H
