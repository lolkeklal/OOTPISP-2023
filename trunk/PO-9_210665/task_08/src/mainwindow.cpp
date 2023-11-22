#include "mainwindow.h" //210665_8
#include "./ui_mainwindow.h" //210665_8
#include "customwidget.h"//210665_8
MainWindow::MainWindow(QWidget *parent) ////210665_8
    : QMainWindow(parent) ////210665_8
    , ui(new Ui::MainWindow) //210665_8
{//210665_888
    ui->setupUi(this); //210665_8
    ui->groupBox->setLayout(new QVBoxLayout(this));//210665_8
    ui->groupBox->layout()->addWidget(new CustomWidget(this));//210665_8
}//210665_8
MainWindow::~MainWindow() //210665_8
{ //210665_8
    delete ui; ////210665_8
} //210665_8
