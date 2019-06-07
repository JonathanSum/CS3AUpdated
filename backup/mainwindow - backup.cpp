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

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);


    LinkedList<string> l1;
    l1.push_back("Apple");
    l1.push_back("Orange");
    l1.push_back("Car");
    l1.push_back("House");
    LinkedList<int> l2;
    l2.push_back(34);
    l2.push_back(21);
    l2.push_back(4);
    l2.push_back(15);
    LinkedList<Rational> l3;
    l3.push_back(Rational(2, 3));
    l3.push_back(Rational(5));
    l3.push_back(Rational(4, 5));
    list_of_LinkedList.push_back(l2);
    list_of_LinkedList.push_back(l1);
    list_of_LinkedList.push_back(l3);
    LinkedList<Date> l4;
    l4.push_back( Date());
    l4.push_back(Date(7, 3, 1991));
    l4.push_back(Date("July", 3, 1991));
    LinkedList<Complex> l5;
    l5.push_back( Complex());
    l5.push_back(Complex());
    l5.push_back(Complex(5));
    l5.push_back(Complex(1,2));
    l5.push_back(Complex(-13,21));
    l5.push_back(Complex(-3,-4));
    LinkedList<double> l6;
    l6.push_back( 5.598);
    l6.push_back(644.5);
    l6.push_back(4521.5);
    l6.push_back(5656.245);
    l6.push_back(524.3);
    l6.push_back(3434.144);
    list_of_LinkedList.push_back(l6);
    list_of_LinkedList.push_back(l5);
    list_of_LinkedList.push_back(l4);
    QStringList headers;
    headers << "All List:" << "Info" << "Pointer Info";
    ui->treeWidget->setHeaderLabels(headers);
    ui->treeWidget->setColumnWidth(0,180);
    ui->treeWidget->setColumnWidth(1,180);
    ui->treeWidget->setColumnWidth(2,180);
    //dropToListWidget();


}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::dropToListWidget() {
    listId = 1;
    ui->treeWidget->clear();
    intListIndex = 1;
    doubleListIndex = 1;
    stringListIndex = 1;
    rationalListIndex = 1;
    dateListIndex = 1;
    complextListIndex = 1;
    for (const auto &v : list_of_LinkedList) {
        if(listId==typeList.size()){
            typeList.push_back(0);
        }

        //PROCESSING - if the linked list is int
        //             then push_back the int list to the mother list
        if (holds_alternative<LinkedList<int> >(v)) {
            QString qstr = QString::fromStdString("Int List " + to_string(intListIndex));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                        QStringList() << qstr << "Int List" << "Pointers");
            int leafIndex = 1;


            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId-1)=1;
            listId++;

            const auto &ListInt = get<LinkedList<int>>(v);
            //const LinkedList<int> *ListInt=&get<LinkedList<int>>(v);
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
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Double List" << "Pointers");
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId-1)=2;
            listId++;
            const auto &ListD = get<LinkedList<double>>(v);

            for (auto iterator = ListD.begin(); iterator != ListD.end(); iterator++) {
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::number(*iterator)
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));
                root->addChild(leaf);
                leafIndex++;


            }
            doubleListIndex++;
            //PROCESSING - if the linked list is string
        } else if (holds_alternative<LinkedList<string> >(v)) {
            QString qstr = QString::fromStdString("String List " + to_string(stringListIndex));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "String List" << "Pointers");
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId-1)=3;
            listId++;
            const auto &Lists = get<LinkedList<string>>(v);

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
            //PROCESSING - if the linked list is Rational
        } else if (holds_alternative<LinkedList<Rational> >(v)) {
            QString qstr = QString::fromStdString("Rational List " + to_string(rationalListIndex));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Rational List" << "Pointers");
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId-1)=4;
            listId++;
            const auto &ListR = get<LinkedList<Rational>>(v);

            for (auto iterator = ListR.begin(); iterator != ListR.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Rational tempR =*iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(tempR.stringValue())
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));
                root->addChild(leaf);
                leafIndex++;
            }
            rationalListIndex++;
        }else if (holds_alternative<LinkedList<Date> >(v)) {
            QString qstr = QString::fromStdString("Date List " + to_string(dateListIndex));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Date List" << "Pointers");
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId-1)=5;
            listId++;
            const auto &ListD = get<LinkedList<Date>>(v);

            for (auto iterator = ListD.begin(); iterator != ListD.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Date tempR =*iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(tempR.stringNumeric())
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));
                root->addChild(leaf);
                leafIndex++;
            }
            dateListIndex++;
        }else if (holds_alternative<LinkedList<Complex> >(v)) {

            QString qstr = QString::fromStdString("Complex List " + to_string(complextListIndex));
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget,
                                                        QStringList() << qstr << "Complex List" << "Pointers");
            int leafIndex = 1;

            QVariant int_v(listId);
            root->setData(0, 5, int_v);
            typeList.at(listId-1)=6;
            listId++;
            const auto &ListC = get<LinkedList<Complex>>(v);
//            (get<LinkedList<Complex>>(v)).
//            cout<<"Testing old address: "<<
//            cout<<"Testing old address: "<<(get<LinkedList<Complex>>(v)).<<endl;
//            cout<<"Testing old address: "<<)
            for (auto iterator = ListC.begin(); iterator != ListC.end(); iterator++) {
                auto ptr1 = iterator.stringAddress();

                Complex tempR =*iterator;
                QString lQstr = QString::fromStdString("Node " + to_string(leafIndex));
                QTreeWidgetItem *leaf = new QTreeWidgetItem(root, QStringList() << lQstr << QString::fromStdString(tempR.stringValue())
                                                                                << QString::fromStdString(
                                                                                        iterator.stringAddress()));
                root->addChild(leaf);
                leafIndex++;
            }
            complextListIndex++;
        }

    }
}

//display button
void MainWindow::on_pushButton_clicked() {
    displayClicked = true;
    dropToListWidget();
    listClicked=false;
}

void MainWindow::on_pushButton_6_clicked() {
    listClicked=false;
    if (ui->radioButton->isChecked()) {
//        auto *tempIntList = new LinkedList<string>;
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

//push_back button
void MainWindow::on_pushButton_2_clicked() {

    if( !listClicked){
        noListClickedMessage();
    }
    cout<<"running"<<endl;
    if(displayClicked&&listClicked) {
        QVariant message = ui->treeWidget->currentItem()->data(0, 5);
//        cout << message.toString().toStdString() << endl;
//        ui->label->setText(QString("Selected Index: %1").arg(message.toString()));
//        cout << "message: " << (message.toInt() - 1) << endl;
//        cout << "message2: " << ui->treeWidget->currentItem()->columnCount() << endl;
        if ((message.toInt() - 1) != -1) {
//        cout << "type index: " << typeList.at((message.toInt() - 1)) << endl;
            int type_index = typeList.at((message.toInt() - 1));

            switch (type_index) {
                case 1:
                    cout<<"Integer"<<endl;
                    if(ui->lineEdit->text().toStdString().empty()){
                       emptyStringMessage();
                    }
                    push_back_by_type( ui->lineEdit->text().toInt(),  0,0,
                     0,  0,  "",
                     1,  ui->treeWidget->currentItem()->data(0, 5).toInt());
                    break;
                case 2:
                    if(ui->lineEdit->text().toStdString().empty()){
                        emptyStringMessage();
                    }
                    push_back_by_type( 0,  0,0,
                                       ui->lineEdit->text().toDouble(),  0,  "",
                                       2,  ui->treeWidget->currentItem()->data(0, 5).toInt());
                    break;
                case 3:
                    cout<<"String"<<endl;
                    if(ui->lineEdit->text().toStdString().empty()){
                        emptyStringMessage();
                    }
                    push_back_by_type( 0,  0, 0,
                                       0,  0, ui->lineEdit->text().toStdString(),
                                       3,  ui->treeWidget->currentItem()->data(0, 5).toInt());
                    break;
                case 4:
                    push_back_by_type( 0,  0, 0,
                                       ui->lineEdit_4->text().toDouble(),
                                       ui->lineEdit_5->text().toDouble(), "",
                                       4,  ui->treeWidget->currentItem()->data(0, 5).toInt());
                    break;
                case 5:
                    cout<<"Year: "<<ui->dateEdit->date().year()<<endl;
                    cout<<"Month: "<<ui->dateEdit->date().month()<<endl;
                    cout<<"Day: "<<ui->dateEdit->date().day()<<endl;
                    push_back_by_type(  ui->dateEdit->date().month(),
                                        ui->dateEdit->date().day(),
                                        ui->dateEdit->date().year(),
                                       0,
                                       0, "",
                                       5,  ui->treeWidget->currentItem()->data(0, 5).toInt());
                    break;
                case 6:
                    if(ui->lineEdit_2->text().toStdString().empty()
                       ||ui->lineEdit_3->text().toStdString().empty()){
                        emptyStringMessage();
                    }
                    push_back_by_type( 0,  0, 0,
                                       ui->lineEdit_4->text().toDouble(),
                                       ui->lineEdit_5->text().toDouble(), "",
                                       6,  ui->treeWidget->currentItem()->data(0, 5).toInt());
                    break;
            }
        }
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column) {

//    cout<<"col: "<<ui->treeWidget->currentColumn()<<endl;
//    QModelIndex index = ui->treeWidget->currentIndex();
//    cout<<"row: "<< index.row()<<endl;

//     auto *lineEdit1 = new QLineEdit(this);
//    lineEdit1->setFocus();
//    lineEdit1->setText(tr("內容"));
//    QString content = lineEdit1->text();
//    lineEdit1->setGeometry(760,70,80,30);
    listClicked=true;
    QVariant message = ui->treeWidget->currentItem()->data(0, 5);
//    cout << message.toString().toStdString() << endl;
    ui->label->setText(QString("Selected Index: %1").arg(message.toString()));
//    cout << "message: " << (message.toInt() - 1) << endl;
//        cout << "message2: " <<ui->treeWidget->currentItem()->columnCount() << endl;
        if((message.toInt() - 1)!=-1){
//        cout << "type index: " << typeList.at((message.toInt() - 1)) << endl;
            int type_index = typeList.at((message.toInt() - 1));

        switch(type_index){
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
                ui->lineEdit->setValidator( new QDoubleValidator(-500.0, 500.0 , 2, ui->lineEdit));
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
                ui->lineEdit_5->setValidator(new QIntValidator(-200, 200,
                        ui->lineEdit));
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
                ui->lineEdit_2->setValidator( new QDoubleValidator(-500.0, 500.0 , 2, ui->lineEdit));
                ui->lineEdit_3->setValidator( new QDoubleValidator(-500.0, 500.0 , 2, ui->lineEdit));
                break;
        }
    }
}

void MainWindow::noListClickedMessage() {
    QMessageBox msgBox;
    msgBox.setText("Error: Please Select a List Before Clicking a Push Back.\n Click the Display key and Select a list");
    msgBox.exec();
}

void MainWindow::emptyStringMessage() {
    QMessageBox msgBox;
    msgBox.setText("Error: Can not Push Back a Empty Element.");
    msgBox.exec();
}



void MainWindow::push_back_by_type(int the_integer1, int the_integer2, int the_integerl3,
                                   double the_double1, double the_double2, const string& the_string,
                                   int the_type_index, int selectedIndex){
    selectedIndex=selectedIndex-1;
    int atIndex =0;

    for (const auto &v : list_of_LinkedList) {
        if(atIndex==selectedIndex){
            cout<<"Yes"<<endl;
            cout<<"selectedIndex: "<<selectedIndex<<endl;
        }
        atIndex++;
    }

    switch(the_type_index) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
    }
}
