#include "mainwindow.h"//210674
#include "./ui_mainwindow.h"//210674

MainWindow::MainWindow(QWidget *parent)//210674
    : QMainWindow(parent)//210674
    , ui(new Ui::MainWindow)//210674
{//210674
    ui->setupUi(this);//210674
}//210674//210674
//210674
MainWindow::~MainWindow() //210674
{//210674
    delete ui;//210674
}//210674

