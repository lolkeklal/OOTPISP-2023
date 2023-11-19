#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
//210663 mainwindow.cpp
    : QMainWindow(parent) //210663 mainwindow.cpp
    , ui(new Ui::MainWindow) //210663 mainwindow.cpp
{
    ui->setupUi(this); //210663 mainwindow.cpp
}

MainWindow::~MainWindow() //210663 mainwindow.cpp
{
    delete ui; //210663 mainwindow.cpp
}

