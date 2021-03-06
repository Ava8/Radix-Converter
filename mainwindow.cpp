#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegExp rx_s("^[A-F0-9_]*$");
    QValidator *val_name = new QRegExpValidator(rx_s, this);
    ui->inputEdit->setValidator(val_name);

    ui->sourceNotation->addItems(notations);
    ui->destinationNotation->addItems(notations);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertButton_clicked()
{
    int sourceNotation = ui->sourceNotation->currentText().toInt();
    int destinationNotation = ui->destinationNotation->currentText().toInt();
    QString num = ui->inputEdit->text();

    converter = new RadixConverter;

    if (sourceNotation == destinationNotation) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if(num[i] >= sourceNotation) {
                ui->resaultLabel->setText("wrong input");
            } else {
                ui->resaultLabel->setText(num);
            }
        }

    } else {
        ui->resaultLabel->setText(converter->toBase(sourceNotation,destinationNotation,num));
    }

}
