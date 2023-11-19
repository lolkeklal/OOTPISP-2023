#include "mainwindow.h" //210664_mainwindow

#include "./ui_mainwindow.h" //210664_mainwindow
#include "customwidget.h"

MainWindow::MainWindow(QWidget *parent) //210664_mainwindow
    : QMainWindow(parent) //210664_mainwindow
    , ui(new Ui::MainWindow) //210664_mainwindow
{
    ui->setupUi(this); //210664_mainwindow

    ui->groupBox->setLayout(new QVBoxLayout(this));
    ui->groupBox->layout()->addWidget(new CustomWidget(this));
}
 //210664_mainwindow
MainWindow::~MainWindow() //210664_mainwindow
{ //210664_mainwindow
    delete ui; //210664_mainwindow
} //210664_mainwindow
