#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <radixconverter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_convertButton_clicked();

private:
    RadixConverter *converter;
    Ui::MainWindow *ui;
    QString num = "2,3,4,5,6,7,8,9,10,11,12,13,14,15,16";
    QStringList notations = num.split(",");
};

#endif // MAINWINDOW_H
