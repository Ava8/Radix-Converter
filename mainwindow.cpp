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
        ui->resaultLabel->setText(num);
    } else if (destinationNotation == 10) {
        int r = 0;
        r = converter->toDecimal(sourceNotation,num);
        ui->resaultLabel->setText(QString("%1").arg(r));
    } else {
        ui->resaultLabel->setText(converter->toBase(sourceNotation,destinationNotation,num));
    }

}
