#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "widget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->setLayout(new QVBoxLayout(this));
    ui->groupBox->layout()->addWidget(new Widget(this));
}
MainWindow::~MainWindow()
{
    delete ui;
}


