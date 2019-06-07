#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_clicked();
    void fromCToF();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_horizontalSlider_sliderMoved(int position);
    void on_radioButton_clicked();
private:
    void belowAbsZero(double t);
    double temperature;
};

#endif // MAINWINDOW_H
