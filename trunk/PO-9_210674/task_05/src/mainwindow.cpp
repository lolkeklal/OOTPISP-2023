#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
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
    ui->text->clear();
    // Подключаем базу данных
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/dashubaa/univer/3kurs/oop/lab5DB.db");
    db.open();

    // Осуществляем запрос
    QSqlQuery query;
    query.exec("SELECT artistic FROM cd");
    int count = 0;
    // Выводим значения из запроса
    ui->text->insertPlainText("Artistics:\n");
    while (query.next()) {
        QString artistic = query.value(0).toString();
        if (!artistic.isEmpty()){
        count++;
        ui->text->insertPlainText(artistic + "\n");
        }
    }
    ui->text->insertPlainText("Count:\n");
    ui->text->insertPlainText(QString::number(count));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->text->clear();
    // Подключаем базу данных
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/dashubaa/univer/3kurs/oop/lab5DB.db");
    db.open();

    // Осуществляем запрос
    QSqlQuery query;
    query.exec("SELECT title FROM cd");
    int count = 0;
    // Выводим значения из запроса
    ui->text->insertPlainText("Titles:\n");
    while (query.next()) {
        QString title = query.value(0).toString();
        if (!title.isEmpty()){
        count++;
        ui->text->insertPlainText(title + "\n");
        }
    }
    ui->text->insertPlainText("Count:\n");
    ui->text->insertPlainText(QString::number(count));
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->text->clear();
    // Подключаем базу данных
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/dashubaa/univer/3kurs/oop/lab5DB.db");
    db.open();

    // Осуществляем запрос
    QSqlQuery query;
    query.exec("SELECT year FROM cd");
    int count = 0;
    // Выводим значения из запроса
    ui->text->insertPlainText("Years:\n");
    while (query.next()) {
        QString year = query.value(0).toString();
        if (!year.isEmpty()){
        count++;
        ui->text->insertPlainText(year + "\n");
            }
    }
    ui->text->insertPlainText("Count:\n");
    // Выводим количество записей
    ui->text->insertPlainText(QString::number(count));
}

