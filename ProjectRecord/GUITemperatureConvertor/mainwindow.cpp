#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    temperature =0;
    ui->label_2->setText(QString::number(temperature));
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {

    double storeT= ui->lineEdit->text().toDouble();
    cout<<"storeT on_pushButton_clicked: "<<storeT<<endl;
    belowAbsZero(storeT);
    cout<<"click: t"<<temperature<<endl;
    fromCToF();
    QString t = QString::number(temperature);
    cout<<"t: "<<temperature<<endl;
    ui->label_2->setText(t+(  (ui->radioButton->isChecked())?"ºC":"ºF" ));
}

void MainWindow::fromCToF() {



    if (ui->radioButton->isChecked()) {
        cout<<"debugging: 1"<<endl;
        cout<<"debugging: "<<temperature<<endl;
        temperature = ((temperature - 32)*5)/9;
    } else if (ui->radioButton_2->isChecked()) {
        cout<<"debugging: 2"<<endl;
        cout<<"debugging: "<<temperature<<endl;
        temperature = ((temperature  * (9 ))/ 5)+32;
    }
    cout<<"debugging end: "<<temperature<<endl;
}
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    double storeT= ui->lineEdit->text().toDouble();
    belowAbsZero(storeT);

    fromCToF();
    QString t = QString::number(temperature);
    ui->label_2->setText(t+(  (ui->radioButton->isChecked())?"ºC":"ºF" ));
}

void MainWindow::belowAbsZero(double t) {

    if(t <-273&&(ui->radioButton_2->isChecked())){
        temperature = -273;}
    else if(t <-459.4&&(ui->radioButton->isChecked())) {
        temperature = -459.4;
    }else{
        temperature = t;
    }
    cout<<"debug below t: "<<t<<endl;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    (ui->radioButton->isChecked())?(ui->horizontalSlider->setRange(-459,459)):
    (ui->horizontalSlider->setRange(-273,273));


    QString t = QString::number(position);

    ui->lineEdit->setText(t+(  (ui->radioButton->isChecked())?"ºF":"ºC" ));
    temperature=t.toDouble();
    fromCToF();
    ui->label_2->setText(QString::number(temperature));



}

void MainWindow::on_radioButton_clicked()
{
    (ui->radioButton->isChecked())?(ui->horizontalSlider->setRange(-459,459)):
    (ui->horizontalSlider->setRange(-273,273));


}
