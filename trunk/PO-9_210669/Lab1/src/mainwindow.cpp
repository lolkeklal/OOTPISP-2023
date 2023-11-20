#include "mainwindow.h" //210669_1_mainwindowcpp
#include "./ui_mainwindow.h" //210669_1_mainwindowcpp

MainWindow::MainWindow(QWidget *parent) //210669_1_mainwindowcpp
    : QMainWindow(parent) //210669_1_mainwindowcpp
    , ui(new Ui::MainWindow) //210669_1_mainwindowcpp
{
    ui->setupUi(this); //210669_1_mainwindowcpp
}

MainWindow::~MainWindow() //210669_1_mainwindowcpp
{
    delete ui; //210669_1_mainwindowcpp
}


