#include "mainwindow.h"//210647
#include "./ui_mainwindow.h"//210647

MainWindow::MainWindow(QWidget *parent)//210647
    : QMainWindow(parent)//210647
    , ui(new Ui::MainWindow)//210647
{//210647
    ui->setupUi(this);//210647
}//210647//210647
//210647
MainWindow::~MainWindow() //210647
{//210647
    delete ui;//210647
}//210647

