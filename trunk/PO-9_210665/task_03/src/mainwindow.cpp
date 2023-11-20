#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    f_to_pay=new form() ;
    f_to_pay->show();
}


void MainWindow::on_pushButton_2_clicked()
{
}


void MainWindow::on_pushButton_21_clicked()
{
    f_to_pay21=new form21();
    f_to_pay21->show();
}


void MainWindow::on_pushButton_22_clicked()
{
    f_to_pay22=new form2();
    f_to_pay22->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    f_to_pay3=new form3();
    f_to_pay3->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    f_to_pay4=new form4();
    f_to_pay4->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    f_to_pay5=new form5();
    f_to_pay5->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    f_to_pay6=new form6();
    f_to_pay6->show();
}

