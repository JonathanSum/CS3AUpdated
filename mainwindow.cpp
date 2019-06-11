#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QtWidgets/QComboBox>
#include "linkedList.h"
#include <iostream>
#include <string>
#include <QApplication>
#include <QtWidgets/QMessageBox>
#include <QValidator>
#include "Rational.h"
#include"qpainter.h"
#include <QDebug>

using namespace std;

/*****************************************************
 *
 *   Constructor MainWindow(QWidget *parent) ): Class MainWindow
 ________________________________________________
 *   This Constructor creates the baisc empty UI
 ________________________________________________
 *   PRE-CONDITIONS
 *   UI is still exist
 *   POST-CONDITIONS
 *   Empty UI created
*****************************************************/
MainWindow::MainWindow(QWidget *parent) :

//PROCESSING - Setting up the GUI
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("CS3A Jonathan Sum Assignment 10: GUI Linked List Display");
    variant<int, float> v, w;


    //PROCESSING & IN - Adding some lists during compiling time
    LinkedList<string> l1;
    l1.push_back("phenex");
    l1.push_back("Pasadena City College");
    l1.push_back("providence");
    l1.push_back("unicorn");
    l1.push_back("zero two");
    l1.push_back("CS8");
    l1.push_back("zero two");
    l1.push_back("Pasadena City College");
    l1.push_back("zero two");
    l1.push_back("akatsuki");
    l1.push_back("providence");

    LinkedList<int> l2;
    l2.push_back(999);
    l2.push_back(999);
    l2.push_back(34);
    l2.push_back(21);
    l2.push_back(888);
    l2.push_back(88);
    l2.push_back(15);
    l2.push_back(777);
    l2.push_back(777);
    l2.push_back(666);
    LinkedList<Rational> l3;
    l3.push_back(Rational(2, 3));
    l3.push_back(Rational(5));
    l3.push_back(Rational(5, 999));
    l3.push_back(Rational(4, 1));
    l3.push_back(Rational(4, 5));
    l3.push_back(Rational(99, 2));
    l3.push_back(Rational(2, 99));
    l3.push_back(Rational(5, 999));
    l3.push_back(Rational(4, 1));
    l3.push_back(Rational(4, 1));
    l3.push_back(Rational(99, 2));
    l3.push_back(Rational(2, 99));

    LinkedList<Date> l4;
    l4.push_back(Date(2, 3, 2050));
    l4.push_back(Date(7, 3, 1991));
    l4.push_back(Date("July", 3, 2074));
    l4.push_back(Date("July", 25, 1952));
    l4.push_back(Date("July", 25, 1952));
    l4.push_back(Date());
    l4.push_back(Date(7, 3, 1991));
    l4.push_back(Date());
    l4.push_back(Date("July", 3, 2074));
    l4.push_back(Date("July", 25, 1952));
    l4.push_back(Date("July", 25, 1952));
    l4.push_back(Date(2, 3, 2050));
    LinkedList<Complex> l5;
    l5.push_back(Complex(-13, 21));
    l5.push_back(Complex(-3, -4));
    l5.push_back(Complex());
    l5.push_back(Complex(52, 1));
    l5.push_back(Complex(5));
    l5.push_back(Complex(1, 2));
    l5.push_back(Complex(-13, 21));
    l5.push_back(Complex(-3, -4));
    l5.push_back(Complex());
    l5.push_back(Complex(52, 1));
    l5.push_back(Complex(5));
    LinkedList<double> l6;
    l6.push_back(524.3);
    l6.push_back(3434.144);
    l6.push_back(4521.5);
    l6.push_back(5656.245);
    l6.push_back(524.3);
    l6.push_back(3434.144);
    l6.push_back(5.598);
    l6.push_back(644.5);
    l6.push_back(524.3);
    l6.push_back(3434.144);
    l6.push_back(5.598);
    l6.push_back(644.5);
    list_of_LinkedList.push_back(l2);
    list_of_LinkedList.push_back(l1);
    list_of_LinkedList.push_back(l3);
    list_of_LinkedList.push_back(l6);
    list_of_LinkedList.push_back(l5);
    list_of_LinkedList.push_back(l4);

    //PROCESSING - Setting up the GUI of the header of the tree list
    QStringList headers;
    headers << "All List:" << "Info" << "Pointer Info";
    ui->treeWidget->setHeaderLabels(headers);
    ui->treeWidget->setColumnWidth(0, 180);
    ui->treeWidget->setColumnWidth(1, 180);
    ui->treeWidget->setColumnWidth(2, 180);


}
/*****************************************************
 *
 *   Destructor ~IntList(): Class MainWindow
 ________________________________________________
 *   This Destructor free all element in UI
 ________________________________________________
 *   PRE-CONDITIONS
 *   UI is still exist
 *   POST-CONDITIONS
 *   UI's elements are delete in the memory
*****************************************************/
MainWindow::~MainWindow() {
    delete ui;

}

/*****************************************************
 *
 *   dropToListWidget: Class MainWindow
 ________________________________________________
 *   This method drops all the child lists into the mother list
 ________________________________________________
 *   PRE-CONDITIONS
 *   None
 *   POST-CONDITIONS
 *   droped all the child lists into the mother list
*****************************************************/
void MainWindow::dropToListWidget() {

    listId = 1;             //IN -it is the type of the list
    ui->treeWidget->clear();        //PROCESSING - clean the tree list
    intListIndex = 1;           //It is the number of the int
    doubleListIndex = 1;           //It is the number of the double
    stringListIndex = 1;         //It is the number of the string
    rationalListIndex = 1;        //It is the number of the rational
    dateListIndex = 1;        //It is the number of the date
    complextListIndex = 1;        //It is the number of the complex

    for (const auto &v : list_of_LinkedList) {

        //PROCESSING - base case to prevent the vector size is more than the index
        if (listId == typeList.size()) {
            typeList.push_back(0);
        }

        //PROCESSING - if the linked list is int
        //             then push_back the int list to the mother list
        if (holds_alternative<LinkedList<int> >(v)) {

            //IN - assigning the title of the list
            QString qstr = QString::fromStdString("Int List " + to_string(intListIndex));



            auto &ListInt = get<LinkedList<int>>(v);

            //OUT - the name of the pointer in qstring
            QString ptrStr = QString("Pointers and current address: 0x%1").arg((quintptr) &ListInt,
                                                                               QT_POINTER_SIZE * 1, 16, QChar('0'));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Int List" << ptrStr);
            int leafIndex = 1;   //OUT - setting a leaf index


            QVariant int_v(listId);

            //IN - assigning the index of the list into the tree list and get index later
            root->setData(0, 5, int_v);
            typeList.at(listId - 1) = 1;
            listId++;

            //PROCESSING Assigning the node of the list
            for (auto iterator = ListInt.begin(); iterator != ListInt.end(); iterator++) {

                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::number(*iterator)
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));
                root->addChild(leaf);
                leafIndex++;


            }


            intListIndex++;


            //PROCESSING - if the linked list is double
        } else if (holds_alternative<LinkedList<double> >(v)) {
            QString qstr = QString::fromStdString("Double List " + to_string(doubleListIndex));

            auto &ListD = get<LinkedList<double>>(v);
            QString ptrStr = QString("Pointers and current address: 0x%1").arg((quintptr) &ListD,
                                                                               QT_POINTER_SIZE * 1, 16, QChar('0'));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Double List" << ptrStr);
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId - 1) = 2;
            listId++;

            //PROCESSING Assigning the node of the list
            for (auto iterator = ListD.begin(); iterator != ListD.end(); iterator++) {
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::number(*iterator)
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));

                root->addChild(leaf);
                leafIndex++;


            }
            doubleListIndex++;

            //PROCESSING - if the linked list is string, assign them
        } else if (holds_alternative<LinkedList<string> >(v)) {
            QString qstr = QString::fromStdString("String List " + to_string(stringListIndex));

            auto &Lists = get<LinkedList<string>>(v);
            QString ptrStr = QString("Pointers and current address: 0x%1").arg((quintptr) &Lists,
                                                                               QT_POINTER_SIZE * 1, 16, QChar('0'));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "String List" << ptrStr);
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId - 1) = 3;
            listId++;


            //PROCESSING Assigning the node of the list
            for (auto iterator = Lists.begin(); iterator != Lists.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();
                string s = *iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(s)
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));

                root->addChild(leaf);
                leafIndex++;
            }
            stringListIndex++;


            //PROCESSING - if the linked list is Rational, assign them
        } else if (holds_alternative<LinkedList<Rational> >(v)) {
            QString qstr = QString::fromStdString("Rational List " + to_string(rationalListIndex));

            const auto &ListR = get<LinkedList<Rational>>(v);
            QString ptrStr = QString("Pointers and current address: 0x%1").arg((quintptr) &ListR,
                                                                               QT_POINTER_SIZE * 1, 16, QChar('0'));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Rational List" << ptrStr);
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId - 1) = 4;
            listId++;

            //PROCESSING Assigning the node of the list
            for (auto iterator = ListR.begin(); iterator != ListR.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Rational tempR = *iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(
                        tempR.stringValue())
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));

                root->addChild(leaf);
                leafIndex++;
            }
            rationalListIndex++;

            //PROCESSING - if the linked list is Date, assign them
        } else if (holds_alternative<LinkedList<Date> >(v)) {
            QString qstr = QString::fromStdString("Date List " + to_string(dateListIndex));

            const auto &ListD = get<LinkedList<Date>>(v);
            QString ptrStr = QString("Pointers and current address: 0x%1").arg((quintptr) &ListD,
                                                                               QT_POINTER_SIZE * 1, 16, QChar('0'));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Date List" << ptrStr);
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId - 1) = 5;
            listId++;

            //PROCESSING Assigning the node of the list
            for (auto iterator = ListD.begin(); iterator != ListD.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Date tempR = *iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(
                        tempR.stringNumeric())
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));

                root->addChild(leaf);
                leafIndex++;
            }
            dateListIndex++;

            //PROCESSING - if the linked list is Complex, assign them
        } else if (holds_alternative<LinkedList<Complex> >(v)) {

            QString qstr = QString::fromStdString("Complex List " + to_string(complextListIndex));
            const auto &ListC = get<LinkedList<Complex>>(v);
            QString ptrStr = QString("Pointers and current address: 0x%1").arg((quintptr) &ListC,
                                                                               QT_POINTER_SIZE * 1, 16, QChar('0'));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Complex List" << ptrStr);
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId - 1) = 6;
            listId++;

            //PROCESSING Assigning the node of the list
            for (auto iterator = ListC.begin(); iterator != ListC.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Complex tempR = *iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(
                        tempR.stringValue())
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));

                root->addChild(leaf);
                leafIndex++;
            }
            complextListIndex++;
        }

    }
}


/*****************************************************
 *
 *   on_pushButton_clicked: Class MainWindow
 ________________________________________________
 *   This methos if or the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_clicked() {

    //IN - display button

    displayClicked = true;
    dropToListWidget();
    listClicked = false;
}
/*****************************************************
 *
 *   on_pushButton_clicked: Class MainWindow
 ________________________________________________
 *   This methos if or the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_6_clicked() {


    //IN - the create list radio selection
    listClicked = false;
    if (ui->radioButton->isChecked()) {
        LinkedList<int> l2;
        list_of_LinkedList.push_back(l2);
    } else if (ui->radioButton_2->isChecked()) {
        LinkedList<double> l1;
        list_of_LinkedList.push_back(l1);
    } else if (ui->radioButton_3->isChecked()) {
        LinkedList<string> l2;
        list_of_LinkedList.push_back(l2);
    } else if (ui->radioButton_4->isChecked()) {
        LinkedList<Rational> l1;
        list_of_LinkedList.push_back(l1);
    } else if (ui->radioButton_5->isChecked()) {
        LinkedList<Date> l1;
        list_of_LinkedList.push_back(l1);
    } else if (ui->radioButton_6->isChecked()) {
        LinkedList<Complex> l1;
        list_of_LinkedList.push_back(l1);
    }
    dropToListWidget();
}

/*****************************************************
 *
 *   on_pushButton_clicked: Class MainWindow
 ________________________________________________
 *   This methos if or the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_2_clicked() {



    //IN - push_back button
    if (!listClicked) {
        noListClickedMessage();
        return;

    } else if (listClicked) {
        if (displayClicked && listClicked) {
            QVariant message = ui->treeWidget->currentItem()->data(0, 5);
            if ((message.toInt() - 1) != -1) {
                int type_index = typeList.at((message.toInt() - 1));
                switch (type_index) {
                    case 1:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(ui->lineEdit->text().toInt(), 0, 0,
                                          0, 0, "",
                                          1, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 1);
                        break;
                    case 2:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          ui->lineEdit->text().toDouble(), 0, "",
                                          2, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 1);
                        break;
                    case 3:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          0, 0, ui->lineEdit->text().toStdString(),
                                          3, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 1);
                        break;
                    case 4:
                        if (ui->lineEdit_4->text().toStdString().empty() &&
                            ui->lineEdit_5->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(ui->lineEdit_4->text().toInt(),
                                          ui->lineEdit_5->text().toInt(), 0,
                                          0,
                                          0, "",
                                          4, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 1);
                        break;
                    case 5:
                        push_back_by_type(ui->dateEdit->date().month(),
                                          ui->dateEdit->date().day(),
                                          ui->dateEdit->date().year(),
                                          0,
                                          0, "",
                                          5, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 1);
                        break;
                    case 6:
                        if (ui->lineEdit_2->text().toStdString().empty()
                            || ui->lineEdit_3->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          ui->lineEdit_2->text().toDouble(),
                                          ui->lineEdit_3->text().toDouble(), "",
                                          6, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 1);
                        break;
                }
            }
        }
    }

}


/*****************************************************
 *
 *   on_treeWidget_itemClicked(QTreeWidgetItem *item, int column) : Class MainWindow
 ________________________________________________
 *   This methos manages if the list is clicked
 ________________________________________________
 *   PRE-CONDITIONS
 *   list was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column) {



    //PROCESSING - if the tree list is cliecked, clear the lineEdit6
    ui->lineEdit_6->clear();

    int bigLength = sizeOfList();       //IN - assigning the total list length.

    //PROCESSING this hides the node in the list
    if (ui->checkBox->isChecked()) {
        ui->treeWidget->currentItem()->setHidden(true);
    }


    //PROCESSING - they are all the input box in the GUI
    listClicked = true;
    if (bigLength == 0) {

        ui->lineEdit_6->setReadOnly(true);
    } else {
        ui->lineEdit_6->setReadOnly(false);
        ui->lineEdit_6->setValidator(new QIntValidator(1, 15,
                                                       this));
    }

    QVariant message = ui->treeWidget->currentItem()->data(0, 5);
    ui->label->setText(QString("Selected List: %1").arg(message.toString()));
    if ((message.toInt() - 1) != -1) {

        int type_index = typeList.at((message.toInt() - 1));

        switch (type_index) {
            case 1:
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
                ui->lineEdit->setReadOnly(false);
                ui->lineEdit_2->setReadOnly(true);
                ui->lineEdit_3->setReadOnly(true);
                ui->lineEdit_4->setReadOnly(true);
                ui->lineEdit_5->setReadOnly(true);
                ui->lineEdit->clear();
                ui->lineEdit->setValidator(new QIntValidator(
                        ui->lineEdit));
                ui->dateEdit->setReadOnly(true);
                break;
            case 2:
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
                ui->lineEdit->setReadOnly(false);
                ui->lineEdit_2->setReadOnly(true);
                ui->lineEdit_3->setReadOnly(true);
                ui->lineEdit_4->setReadOnly(true);
                ui->lineEdit_5->setReadOnly(true);
                ui->lineEdit->clear();
                ui->lineEdit->setValidator(new QDoubleValidator(-10000.0, 1000.0, 5, ui->lineEdit));
                ui->dateEdit->setReadOnly(true);
                break;
            case 3:
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
                ui->lineEdit->setReadOnly(false);
                ui->lineEdit_2->setReadOnly(true);
                ui->lineEdit_3->setReadOnly(true);
                ui->lineEdit_4->setReadOnly(true);
                ui->lineEdit_5->setReadOnly(true);
                ui->lineEdit->clear();
                ui->lineEdit->setValidator(0);
                ui->dateEdit->setReadOnly(true);
                break;
            case 4:
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit->setReadOnly(true);
                ui->lineEdit_2->setReadOnly(true);
                ui->lineEdit_3->setReadOnly(true);
                ui->lineEdit_4->setReadOnly(false);
                ui->lineEdit_5->setReadOnly(false);
                ui->dateEdit->setReadOnly(true);
                ui->lineEdit_4->setValidator(new QIntValidator(-200, 200,
                                                               ui->lineEdit));

                ui->lineEdit_5->setValidator(
                        new QRegularExpressionValidator(QRegularExpression("[1-9]\\d{0,5}"), this));
                break;
            case 5:
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
                ui->lineEdit->setReadOnly(true);
                ui->lineEdit_2->setReadOnly(true);
                ui->lineEdit_3->setReadOnly(true);
                ui->lineEdit_4->setReadOnly(true);
                ui->lineEdit_5->setReadOnly(true);
                ui->dateEdit->setReadOnly(false);
                break;
            case 6:
                ui->lineEdit->clear();
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
                ui->lineEdit->setReadOnly(true);
                ui->lineEdit_2->setReadOnly(false);
                ui->lineEdit_3->setReadOnly(false);
                ui->lineEdit_4->setReadOnly(true);
                ui->lineEdit_5->setReadOnly(true);
                ui->lineEdit_2->setValidator(new QDoubleValidator(-10000.0, 1000.0, 5, ui->lineEdit));
                ui->lineEdit_3->setValidator(new QDoubleValidator(-10000.0, 1000.0, 5, ui->lineEdit));
                break;
        }
    } else {
        listClicked = false;
    }
}

/*****************************************************
 *
 *   noListClickedMessage()const
 ________________________________________________
 *   This methos tells the user that the usser did not click the list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   told the user that the usser did not click the list
*****************************************************/
void MainWindow::noListClickedMessage()const {

    //OUT - if the list did not clicked, tell the user about it.
    QMessageBox msgBox;
    msgBox.setText(
            "Error: Please Select a List Before Clicking a Push Back.\n Click the Display key and Select a list");
    msgBox.exec();
}

/*****************************************************
 *
 *   emptyStringMessage()const
 ________________________________________________
 *   This methos tells the user that the usser did not input to the linedit
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   told the user that the usser did not input to the linedit
*****************************************************/
void MainWindow::emptyStringMessage()const {

    //OUT - tell the users it can not push back an empty element
    QMessageBox msgBox;
    msgBox.setText("Error: Can not Push Back a Empty Element.");
    msgBox.exec();
}

/*****************************************************
 *
 *   push_back_by_type(int the_integer1, int the_integer2, int the_integer3,
                       double the_double1, double the_double2, const string &the_string,
                       int the_type_index, int selectedIndex, int selectedNode, unsigned operation)
 ________________________________________________
 *   This methos edits the mother list and child list based on the operation number 1-9
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   edited the mother list and child list based on the operation number 1-9
*****************************************************/
void MainWindow::push_back_by_type(int the_integer1, int the_integer2, int the_integer3,
                                   double the_double1, double the_double2, const string &the_string,
                                   int the_type_index, int selectedIndex, int selectedNode, unsigned operation) {

    selectedIndex = selectedIndex - 1;
    int atIndex = 0;

    // IN - loop through the mother list and do with them based on the opereation 1 - 9
    for (auto &v : list_of_LinkedList) {
        if (atIndex == selectedIndex) {
            switch (the_type_index) {
                case 1:
                    if (holds_alternative<LinkedList<int> >(v)) {
                        if (operation == 1) {

                            get_if<LinkedList<int>>(&v)->push_back(the_integer1);

                        } else if (operation == 2) {

                            get_if<LinkedList<int>>(&v)->push_front(the_integer1);

                        } else if (operation == 3) {

                            get_if<LinkedList<int>>(&v)->pop_front();

                        } else if (operation == 4) {

                            get_if<LinkedList<int>>(&v)->select_sort();
                            get_if<LinkedList<int>>(&v)->insert_sorted(the_integer1);

                        } else if (operation == 5) {

                            LinkedList<int> copied = get<LinkedList<int>>(v);
                            list_of_LinkedList.push_back(copied);

                        } else if (operation == 6) {

                            get_if<LinkedList<int>>(&v)->select_sort();

                        } else if (operation == 7) {

                            get_if<LinkedList<int>>(&v)->select_sort();
                            get_if<LinkedList<int>>(&v)->remove_duplicates();

                        } else if (operation == 8) {

                            get_if<LinkedList<int>>(&v)->clear();
                            list_of_LinkedList.deleteItem(selectedIndex);

                        } else if (operation == 9) {

                            get_if<LinkedList<int>>(&v)
                                    ->insertByPosition(selectedNode, the_integer1);
                            on_pushButton_clicked();

                        }
                        break;
                        case 2:
                            if (holds_alternative<LinkedList<double> >(v)) {
                                if (operation == 1) {

                                    get_if<LinkedList<double>>(&v)->push_back(the_double1);

                                } else if (operation == 2) {

                                    get_if<LinkedList<double>>(&v)->push_front(the_double1);

                                } else if (operation == 3) {

                                    get_if<LinkedList<double>>(&v)->pop_front();

                                } else if (operation == 4) {

                                    get_if<LinkedList<double>>(&v)->select_sort();
                                    get_if<LinkedList<double>>(&v)->insert_sorted(the_double1);

                                } else if (operation == 5) {

                                    LinkedList<double> copied = get<LinkedList<double>>(v);
                                    list_of_LinkedList.push_back(copied);

                                } else if (operation == 6) {

                                    get_if<LinkedList<double>>(&v)->select_sort();

                                } else if (operation == 7) {

                                    get_if<LinkedList<double>>(&v)->select_sort();
                                    get_if<LinkedList<double>>(&v)->remove_duplicates();

                                } else if (operation == 8) {

                                    get_if<LinkedList<double>>(&v)->clear();
                                    list_of_LinkedList.deleteItem(selectedIndex);

                                } else if (operation == 9) {

                                    get_if<LinkedList<double>>(&v)
                                            ->insertByPosition(selectedNode, the_double1);
                                    on_pushButton_clicked();

                                }
                            }
                        break;
                        case 3:
                            if (holds_alternative<LinkedList<string> >(v)) {
                                if (operation == 1) {

                                    get_if<LinkedList<string>>(&v)->push_back(the_string);

                                } else if (operation == 2) {

                                    get_if<LinkedList<string>>(&v)->push_front(the_string);

                                } else if (operation == 3) {

                                    get_if<LinkedList<string>>(&v)->pop_front();

                                } else if (operation == 4) {

                                    get_if<LinkedList<string>>(&v)->select_sort();
                                    get_if<LinkedList<string>>(&v)->insert_sorted(the_string);

                                } else if (operation == 5) {

                                    LinkedList<string> copied = get<LinkedList<string>>(v);
                                    list_of_LinkedList.push_back(copied);

                                } else if (operation == 6) {

                                    get_if<LinkedList<string>>(&v)->select_sort();
                                } else if (operation == 7) {

                                    get_if<LinkedList<string>>(&v)->select_sort();
                                    get_if<LinkedList<string>>(&v)->remove_duplicates();

                                } else if (operation == 8) {

                                    get_if<LinkedList<string>>(&v)->clear();
                                    list_of_LinkedList.deleteItem(selectedIndex);

                                } else if (operation == 9) {

                                    get_if<LinkedList<string>>(&v)->insertByPosition(selectedNode, the_string);
                                    on_pushButton_clicked();

                                }
                            }
                        break;
                        case 4:
                            if (holds_alternative<LinkedList<Rational> >(v)) {
                                if (operation == 1) {

                                    get_if<LinkedList<Rational>>(&v)->push_back(Rational(the_integer1, the_integer2));

                                } else if (operation == 2) {

                                    get_if<LinkedList<Rational>>(&v)->push_front(Rational(the_integer1, the_integer2));

                                } else if (operation == 3) {

                                    get_if<LinkedList<Rational>>(&v)->pop_front();

                                } else if (operation == 4) {

                                    get_if<LinkedList<string>>(&v)->select_sort();
                                    get_if<LinkedList<Rational>>(&v)->insert_sorted(
                                            Rational(the_integer1, the_integer2));

                                } else if (operation == 5) {

                                    LinkedList<Rational> copied = get<LinkedList<Rational>>(v);
                                    list_of_LinkedList.push_back(copied);

                                } else if (operation == 6) {

                                    get_if<LinkedList<Rational>>(&v)->select_sort();

                                } else if (operation == 7) {

                                    get_if<LinkedList<Rational>>(&v)->select_sort();
                                    get_if<LinkedList<Rational>>(&v)->remove_duplicates();

                                } else if (operation == 8) {

                                    get_if<LinkedList<Rational>>(&v)->clear();
                                    list_of_LinkedList.deleteItem(selectedIndex);

                                } else if (operation == 9) {

                                    get_if<LinkedList<Rational>>(&v)
                                            ->insertByPosition(selectedNode, Rational(the_integer1, the_integer2));
                                    on_pushButton_clicked();

                                }
                            }
                        break;
                        case 5:
                            if (holds_alternative<LinkedList<Date> >(v)) {
                                if (operation == 1) {

                                    get_if<LinkedList<Date>>(&v)->push_back(
                                            Date(the_integer1, the_integer2, the_integer3));

                                } else if (operation == 2) {

                                    get_if<LinkedList<Date>>(&v)->push_front(
                                            Date(the_integer1, the_integer2, the_integer3));

                                } else if (operation == 3) {

                                    get_if<LinkedList<Date>>(&v)->pop_front();

                                } else if (operation == 4) {

                                    get_if<LinkedList<string>>(&v)->select_sort();
                                    get_if<LinkedList<Date>>(&v)->insert_sorted(
                                            Date(the_integer1, the_integer2, the_integer3));

                                } else if (operation == 5) {

                                    LinkedList<Date> copied = get<LinkedList<Date>>(v);
                                    list_of_LinkedList.push_back(copied);

                                } else if (operation == 6) {

                                    get_if<LinkedList<Date>>(&v)->select_sort();

                                } else if (operation == 7) {

                                    get_if<LinkedList<Date>>(&v)->select_sort();
                                    get_if<LinkedList<Date>>(&v)->remove_duplicates();

                                } else if (operation == 8) {

                                    get_if<LinkedList<Date>>(&v)->clear();
                                    list_of_LinkedList.deleteItem(selectedIndex);

                                } else if (operation == 9) {
                                    get_if<LinkedList<Date>>(&v)
                                            ->insertByPosition(selectedNode,
                                                               Date(the_integer1, the_integer2, the_integer3));
                                    on_pushButton_clicked();

                                }
                            }

                        break;
                        case 6:
                            if (holds_alternative<LinkedList<Complex> >(v)) {
                                if (operation == 1) {

                                    get_if<LinkedList<Complex>>(&v)->push_back(Complex(the_double1, the_double2));

                                } else if (operation == 2) {

                                    get_if<LinkedList<Complex>>(&v)->push_front(Complex(the_double1, the_double2));

                                } else if (operation == 3) {

                                    get_if<LinkedList<Complex>>(&v)->pop_front();

                                } else if (operation == 4) {

                                    get_if<LinkedList<string>>(&v)->select_sort();
                                    get_if<LinkedList<Complex>>(&v)->insert_sorted(Complex(the_double1, the_double2));

                                } else if (operation == 5) {

                                    LinkedList<Complex> copied = get<LinkedList<Complex>>(v);
                                    list_of_LinkedList.push_back(copied);

                                } else if (operation == 6) {

                                    get_if<LinkedList<Complex>>(&v)->select_sort();

                                } else if (operation == 7) {

                                    get_if<LinkedList<Complex>>(&v)->select_sort();
                                    get_if<LinkedList<Complex>>(&v)->remove_duplicates();

                                } else if (operation == 8) {

                                    get_if<LinkedList<Complex>>(&v)->clear();
                                    list_of_LinkedList.deleteItem(selectedIndex);

                                } else if (operation == 9) {

                                    get_if<LinkedList<Complex>>(&v)
                                            ->insertByPosition(selectedNode, (Complex(the_double1, the_double2)));
                                    on_pushButton_clicked();
                                }
                            }
                        break;
                    }
            }
            update();
            listClicked = false;
            dropToListWidget();

        }

        atIndex++;
    }
}


/*****************************************************
 *
 *   on_pushButton_3_clicked() Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_3_clicked() {

    //IN - push front button and edditing
    if (!listClicked) {
        noListClickedMessage();
    } else {
        if (displayClicked && listClicked) {
            QVariant message = ui->treeWidget->currentItem()->data(0, 5);
            if ((message.toInt() - 1) != -1) {
                int type_index = typeList.at((message.toInt() - 1));
                switch (type_index) {
                    case 1:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(ui->lineEdit->text().toInt(), 0, 0,
                                          0, 0, "",
                                          1, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 2);
                        break;
                    case 2:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          ui->lineEdit->text().toDouble(), 0, "",
                                          2, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 2);
                        break;
                    case 3:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          0, 0, ui->lineEdit->text().toStdString(),
                                          3, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 2);
                        break;
                    case 4:
                        if (ui->lineEdit_4->text().toStdString().empty() &&
                            ui->lineEdit_5->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(ui->lineEdit_4->text().toInt(),
                                          ui->lineEdit_5->text().toInt(), 0,
                                          0,
                                          0, "",
                                          4, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 2);
                        break;
                    case 5:
                        push_back_by_type(ui->dateEdit->date().month(),
                                          ui->dateEdit->date().day(),
                                          ui->dateEdit->date().year(),
                                          0,
                                          0, "",
                                          5, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 2);
                        break;
                    case 6:
                        if (ui->lineEdit_2->text().toStdString().empty()
                            || ui->lineEdit_3->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          ui->lineEdit_2->text().toDouble(),
                                          ui->lineEdit_3->text().toDouble(), "",
                                          6, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 2);
                        break;
                }
            }
        }
    }

}

/*****************************************************
 *
 *   on_pushButton_4_clicked(): Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_4_clicked() {

    //IN - Pop_Front Button and pop list
    if (!listClicked) {
        noListClickedMessage();
    }
    if (displayClicked && listClicked) {
        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
        if ((message.toInt() - 1) != -1) {
            int type_index = typeList.at((message.toInt() - 1));
            switch (type_index) {
                case 1:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 3);
                    break;
                case 2:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 3);
                    break;
                case 3:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 3);
                    break;
                case 4:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 3);
                    break;
                case 5:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 3);
                    break;
                case 6:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 3);
                    break;
            }
        }
    }
}

/*****************************************************
 *
 *   on_pushButton_8_clicked(): Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_8_clicked() {

    //IN - selected sort button and selected sort them based on its type
    if (!listClicked) {
        noListClickedMessage();
    }
    if (displayClicked && listClicked) {
        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
        if ((message.toInt() - 1) != -1) {
            int type_index = typeList.at((message.toInt() - 1));
            switch (type_index) {
                case 1:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 6);
                    break;
                case 2:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 6);
                    break;
                case 3:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 6);
                    break;
                case 4:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 6);
                    break;
                case 5:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 6);
                    break;
                case 6:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 6);
                    break;
            }
        }
    }
}

/*****************************************************
 *
 *   on_pushButton_7_clicked(): Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_7_clicked() {

    //IN - Copy Button and send the opereation number 5
    if (!listClicked) {
        noListClickedMessage();
    }
    if (displayClicked && listClicked) {
        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
        if ((message.toInt() - 1) != -1) {
            int type_index = typeList.at((message.toInt() - 1));
            switch (type_index) {
                case 1:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 5);
                    break;
                case 2:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 5);
                    break;
                case 3:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 5);
                    break;
                case 4:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 5);
                    break;
                case 5:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 5);
                    break;
                case 6:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 5);
                    break;
            }
        }
    }
}

/*****************************************************
 *
 *   on_pushButton_10_clicked() : Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_10_clicked() {

    //IN - remove duplicates button and send the opereation number 7
    if (!listClicked) {
        noListClickedMessage();
    }
    if (displayClicked && listClicked) {
        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
        if ((message.toInt() - 1) != -1) {
            int type_index = typeList.at((message.toInt() - 1));
            switch (type_index) {
                case 1:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 7);
                    break;
                case 2:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 7);
                    break;
                case 3:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 7);
                    break;
                case 4:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 7);
                    break;
                case 5:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 7);
                    break;
                case 6:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 7);
                    break;
            }
        }
    }
}

/*****************************************************
 *
 *   on_pushButton_clicked: Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_5_clicked() {

    //IN - Insert_Sorted Button button and send the opereation number 4
    if (!listClicked) {
        noListClickedMessage();
    } else {
        if (displayClicked && listClicked) {
            QVariant message = ui->treeWidget->currentItem()->data(0, 5);
            if ((message.toInt() - 1) != -1) {
                int type_index = typeList.at((message.toInt() - 1));
                switch (type_index) {
                    case 1:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(ui->lineEdit->text().toInt(), 0, 0,
                                          0, 0, "",
                                          1, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 4);
                        break;
                    case 2:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          ui->lineEdit->text().toDouble(), 0, "",
                                          2, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 4);
                        break;
                    case 3:
                        if (ui->lineEdit->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          0, 0, ui->lineEdit->text().toStdString(),
                                          3, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 4);
                        break;
                    case 4:
                        if (ui->lineEdit_4->text().toStdString().empty() &&
                            ui->lineEdit_5->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(ui->lineEdit_4->text().toInt(),
                                          ui->lineEdit_5->text().toInt(), 0,
                                          0,
                                          0, "",
                                          4, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 4);
                        break;
                    case 5:
                        push_back_by_type(ui->dateEdit->date().month(),
                                          ui->dateEdit->date().day(),
                                          ui->dateEdit->date().year(),
                                          0,
                                          0, "",
                                          5, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 4);
                        break;
                    case 6:
                        if (ui->lineEdit_2->text().toStdString().empty()
                            || ui->lineEdit_3->text().toStdString().empty()) {
                            emptyStringMessage();
                            break;
                        }
                        push_back_by_type(0, 0, 0,
                                          ui->lineEdit_2->text().toDouble(),
                                          ui->lineEdit_3->text().toDouble(), "",
                                          6, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 4);
                        break;
                }
            }
        }
    }

}

/*****************************************************
 *
 *   on_pushButton_9_clicked: Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_9_clicked() {


    //IN - Delete Button Button button and send the opereation number 8
    if (list_of_LinkedList.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText(
                "Error: All lists are deleted");
        msgBox.exec();
        return;
    }
    if (!listClicked) {
        QMessageBox msgBox;
        msgBox.setText(
                "Error: Please Select a List Before deleting.");
        msgBox.exec();
    }
    if (displayClicked && listClicked) {
        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
        if ((message.toInt() - 1) != -1) {
            int type_index = typeList.at((message.toInt() - 1));
            switch (type_index) {
                case 1:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 8);
                    break;
                case 2:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 8);
                    break;
                case 3:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 8);
                    break;
                case 4:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 8);
                    break;
                case 5:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 8);
                    break;
                case 6:
                    push_back_by_type(0, 0, 0,
                                      0,
                                      0, "",
                                      type_index, ui->treeWidget->currentItem()->data(0, 5).toInt(), 0, 8);
                    break;
            }
        }
    }
}

/*****************************************************
 *
 *   on_pushButton_clicked: Class MainWindow
 ________________________________________________
 *   This methos manages the push back button
 ________________________________________________
 *   PRE-CONDITIONS
 *   Button was clicked
 *   POST-CONDITIONS
 *   apply the program in the function in below
*****************************************************/
void MainWindow::on_pushButton_11_clicked() {


    //IN - Insert Node Button and operation is 9 to send them to the function handle that
    if (!listClicked) {
        noListClickedMessage();
    } else if (displayClicked && listClicked) {

        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
        if ((message.toInt() - 1) != -1) {
            int selectedIndex = (ui->lineEdit_6->text().toInt()) - 1;
            int type_index = typeList.at((message.toInt() - 1));
            switch (type_index) {
                case 1:
                    if (ui->lineEdit->text().toStdString().empty()) {
                        emptyStringMessage();
                        break;
                    }
                    push_back_by_type(ui->lineEdit->text().toInt(), 0, 0,
                                      0, 0, "",
                                      1, ui->treeWidget->currentItem()->data(0, 5).toInt(), selectedIndex, 9);
                    break;
                case 2:
                    if (ui->lineEdit->text().toStdString().empty()) {
                        emptyStringMessage();
                        break;
                    }
                    push_back_by_type(0, 0, 0,
                                      ui->lineEdit->text().toDouble(), 0, "",
                                      2, ui->treeWidget->currentItem()->data(0, 5).toInt(), selectedIndex, 9);
                    break;
                case 3:
                    if (ui->lineEdit->text().toStdString().empty()) {
                        emptyStringMessage();
                        break;
                    }
                    push_back_by_type(0, 0, 0,
                                      0, 0, ui->lineEdit->text().toStdString(),
                                      3, ui->treeWidget->currentItem()->data(0, 5).toInt(), selectedIndex, 9);
                    break;
                case 4:
                    if (ui->lineEdit_4->text().toStdString().empty() &&
                        ui->lineEdit_5->text().toStdString().empty()) {
                        emptyStringMessage();
                        break;
                    }
                    push_back_by_type(ui->lineEdit_4->text().toInt(),
                                      ui->lineEdit_5->text().toInt(), 0,
                                      0,
                                      0, "",
                                      4, ui->treeWidget->currentItem()->data(0, 5).toInt(), selectedIndex, 9);
                    break;
                case 5:
                    push_back_by_type(ui->dateEdit->date().month(),
                                      ui->dateEdit->date().day(),
                                      ui->dateEdit->date().year(),
                                      0,
                                      0, "",
                                      5, ui->treeWidget->currentItem()->data(0, 5).toInt(), selectedIndex, 9);
                    break;
                case 6:
                    if (ui->lineEdit_2->text().toStdString().empty()
                        || ui->lineEdit_3->text().toStdString().empty()) {
                        emptyStringMessage();
                        break;
                    }
                    push_back_by_type(0, 0, 0,
                                      ui->lineEdit_2->text().toDouble(),
                                      ui->lineEdit_3->text().toDouble(), "",
                                      6, ui->treeWidget->currentItem()->data(0, 5).toInt(), selectedIndex, 9);
                    break;
            }
        }
    }
}
/*****************************************************
 *
 *   sizeOfList() const: Class MainWindow
 ________________________________________________
 *   This method return the size of the child list
 ________________________________________________
 *   PRE-CONDITIONS
 *   none
 *   POST-CONDITIONS
 *   returned the size of the child list
*****************************************************/
int MainWindow::sizeOfList() const {
    int index = (ui->treeWidget->currentItem()->data(0, 5).toInt()) - 1;


    int currentIndex = 0;

    //PROCESSING - loop through the list and return their size
    if (index >= 0 && displayClicked) {

        int type_index = typeList.at(index);
        for (const auto &v : list_of_LinkedList) {
            if (index == currentIndex) {
                switch (type_index) {
                    case 1:
                        if (holds_alternative<LinkedList<int> >(v)) {
                            auto &ListD = get<LinkedList<int>>(v);
                            return ListD.length(ListD.begin());
                        }
                        break;
                    case 2:
                        if (holds_alternative<LinkedList<double> >(v)) {
                            auto &ListD = get<LinkedList<double>>(v);
                            return ListD.length(ListD.begin());
                        }
                        break;
                    case 3:
                        if (holds_alternative<LinkedList<string> >(v)) {
                            auto &ListD = get<LinkedList<string>>(v);
                            return ListD.length(ListD.begin());
                        }
                        break;
                    case 4:
                        if (holds_alternative<LinkedList<Rational> >(v)) {
                            auto &ListD = get<LinkedList<Rational>>(v);
                            return ListD.length(ListD.begin());
                        }
                        break;
                    case 5:
                        if (holds_alternative<LinkedList<Date> >(v)) {
                            auto &ListD = get<LinkedList<Date>>(v);
                            return ListD.length(ListD.begin());
                        }
                        break;
                    case 6:
                        if (holds_alternative<LinkedList<Complex> >(v)) {
                            auto &ListD = get<LinkedList<Complex>>(v);
                            return ListD.length(ListD.begin());
                        }
                        break;
                }
            }
            currentIndex++;
        }
    }
    return 0;
}


/*****************************************************
 *
 *   paintEvent(QPaintEvent *): Class MainWindow
 ________________________________________________
 *   This method paints the list on the GUI
 ________________________________________________
 *   PRE-CONDITIONS
 *   None
 *   POST-CONDITIONS
 *   painted the list on the GUI
*****************************************************/
void MainWindow::paintEvent(QPaintEvent *) {




    int x = 30;         //PROCESSING - starting location 30 in x-axis
    int y = 570;         //PROCESSING - starting location 30 in y-axis
    int l = 40,         //PROCESSING - length of the rectangle
            h = 15;         //PROCESSING - height of the rectangle
    int paddingTop =50;

    for (const auto &v : list_of_LinkedList) {



        //PROCESSING - if the linked list is int,, paint the arrow for it
        if (holds_alternative<LinkedList<int> >(v)) {

            auto &ListInt = get<LinkedList<int>>(v);


            int leafIndex = 1;

            x = 30;
            for (auto iterator = ListInt.begin(); iterator != ListInt.end(); iterator++) {


                QPainter painter(this);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawEllipse(x - 20, y, l + 35, h + 5);
                painter.setPen(Qt::green);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawRect(x + 70 - 10, y, l, h);
                painter.setBrush(Qt::blue);
                QPointF points[4] = {QPointF(x + l + 70 - 10, y + (h * 2)), QPointF(x + l + 10 + 70 - 10, y + (h / 2)),
                                     QPointF((x + l + 70 - 10), y - h), QPointF(x + l + 70 - 10, y + h)};
                painter.drawConvexPolygon(points, 4);
                string sNum = to_string(*iterator);
                QString qstr = QString::fromStdString(sNum);


                painter.setFont(QFont("Arial", 8));
                painter.drawText(x - 10, y + 15, qstr);
                x += 150;


            }
            y += paddingTop;

            //PROCESSING - if the linked list is double, paint the arrow for it
        } else if (holds_alternative<LinkedList<double> >(v)) {

            auto &ListD = get<LinkedList<double>>(v);

            int leafIndex = 1;


            x = 30;
            for (auto iterator = ListD.begin(); iterator != ListD.end(); iterator++) {


                QPainter painter(this);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawEllipse(x - 20, y, l + 35, h + 5);
                painter.setPen(Qt::green);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawRect(x + 70 - 10, y, l, h);
                painter.setBrush(Qt::blue);
                QPointF points[4] = {QPointF(x + l + 70 - 10, y + (h * 2)), QPointF(x + l + 10 + 70 - 10, y + (h / 2)),
                                     QPointF((x + l + 70 - 10), y - h), QPointF(x + l + 70 - 10, y + h)};
                painter.drawConvexPolygon(points, 4);
                string sNum = to_string(*iterator);
                QString qstr = QString::fromStdString(sNum);



                painter.setFont(QFont("Arial", 8));
                painter.drawText(x - 10, y + 15, qstr);
                x += 150;


                leafIndex++;


            }
            y += paddingTop;
            //PROCESSING - if the linked list is string, paint the arrow for it
        } else if (holds_alternative<LinkedList<string> >(v)) {

            auto &Lists = get<LinkedList<string>>(v);

            x = 30;

            for (auto iterator = Lists.begin(); iterator != Lists.end(); iterator++) {


                QPainter painter(this);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawEllipse(x - 20, y, l + 35, h + 5);
                painter.setPen(Qt::green);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawRect(x + 70 - 10, y, l, h);
                painter.setBrush(Qt::blue);
                QPointF points[4] = {QPointF(x + l + 70 - 10, y + (h * 2)), QPointF(x + l + 10 + 70 - 10, y + (h / 2)),
                                     QPointF((x + l + 70 - 10), y - h), QPointF(x + l + 70 - 10, y + h)};
                painter.drawConvexPolygon(points, 4);
                QString qstr = QString::fromStdString(*iterator);



                painter.setFont(QFont("Arial", 8));
                painter.drawText(x - 10, y + 15, qstr);
                x += 150;


            }
            y += paddingTop;

            //PROCESSING - if the linked list is Rational, paint the arrow for it
        } else if (holds_alternative<LinkedList<Rational> >(v)) {

            const auto &ListR = get<LinkedList<Rational>>(v);

            int leafIndex = 1;
            x = 30;
            for (auto iterator = ListR.begin(); iterator != ListR.end(); iterator++) {


                Rational tempR = *iterator;


                QPainter painter(this);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawEllipse(x - 20, y, l + 35, h + 5);
                painter.setPen(Qt::green);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawRect(x + 70 - 10, y, l, h);
                painter.setBrush(Qt::blue);
                QPointF points[4] = {QPointF(x + l + 70 - 10, y + (h * 2)), QPointF(x + l + 10 + 70 - 10, y + (h / 2)),
                                     QPointF((x + l + 70 - 10), y - h), QPointF(x + l + 70 - 10, y + h)};
                painter.drawConvexPolygon(points, 4);
                QString qstr = QString::fromStdString(tempR.stringValue());


                painter.setFont(QFont("Arial", 8));
                painter.drawText(x - 10, y + 15, qstr);
                x += 150;

                leafIndex++;
            }
            y += paddingTop;

            //PROCESSING - if the linked list is Date, paint the arrow for it
        } else if (holds_alternative<LinkedList<Date> >(v)) {

            const auto &ListD = get<LinkedList<Date>>(v);

            int leafIndex = 1;

            x = 30;


            for (auto iterator = ListD.begin(); iterator != ListD.end(); iterator++) {

                Date tempR = *iterator;


                QPainter painter(this);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawEllipse(x - 20, y, l + 35, h + 5);
                painter.setPen(Qt::green);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawRect(x + 70 - 10, y, l, h);
                painter.setBrush(Qt::blue);
                QPointF points[4] = {QPointF(x + l + 70 - 10, y + (h * 2)), QPointF(x + l + 10 + 70 - 10, y + (h / 2)),
                                     QPointF((x + l + 70 - 10), y - h), QPointF(x + l + 70 - 10, y + h)};
                painter.drawConvexPolygon(points, 4);

                QString qstr = QString::fromStdString(tempR.stringNumeric());


                painter.setFont(QFont("Arial", 8));
                painter.drawText(x - 10, y + 15, qstr);
                x += 150;


                leafIndex++;

            }
            y += paddingTop;

            //PROCESSING - if the linked list is Complex, paint the arrow for it
        } else if (holds_alternative<LinkedList<Complex> >(v)) {
            x = 30;
            const auto &ListC = get<LinkedList<Complex>>(v);

            int leafIndex = 1;


            for (auto iterator = ListC.begin(); iterator != ListC.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Complex tempR = *iterator;
                QPainter painter(this);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawEllipse(x - 20, y, l + 35, h + 5);
                painter.setPen(Qt::green);
                painter.setPen(QPen(Qt::blue, 2));
                painter.drawRect(x + 70 - 10, y, l, h);
                painter.setBrush(Qt::blue);
                QPointF points[4] = {QPointF(x + l + 70 - 10, y + (h * 2)), QPointF(x + l + 10 + 70 - 10, y + (h / 2)),
                                     QPointF((x + l + 70 - 10), y - h), QPointF(x + l + 70 - 10, y + h)};
                painter.drawConvexPolygon(points, 4);
                QString qstr = QString::fromStdString(tempR.stringValue());


                painter.setFont(QFont("Arial", 8));
                painter.drawText(x - 10, y + 15, qstr);
                x += 150;

                leafIndex++;
            }
            y += paddingTop;
        }

    }
}