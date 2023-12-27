#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    selectSellersButton = new QPushButton("Продавцы");
    selectProductButton = new QPushButton("Продукты");
    findSellerByProductIdButton = new QPushButton("Найти продавца по id продукта");
    countTotalSumForEachSellerButton = new QPushButton("Расчитать сумму каждого продавца");

    productIdTextBox = new QTextEdit(this);
    productIdTextBox->setMaximumWidth(250);
    productIdTextBox->setMaximumHeight(26);

    connect(selectSellersButton, &QPushButton::clicked, this, &MainWindow::selectSellers);
    connect(selectProductButton, &QPushButton::clicked, this, &MainWindow::selectProducts);
    connect(findSellerByProductIdButton, &QPushButton::clicked, this, &MainWindow::findSellerByProductId);
    connect(countTotalSumForEachSellerButton, &QPushButton::clicked, this, &MainWindow::countTotalSumForEachSeller);

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("shop.sqlite");
    table = new QTableView(this);
    layout = new QGridLayout(this);
    layout->addWidget(table, 0, 0, 8, 2);
    layout->addWidget(selectSellersButton, 0, 2);
    layout->addWidget(selectProductButton, 1, 2);
    layout->addWidget(findSellerByProductIdButton, 2, 2);
    layout->addWidget(productIdTextBox, 3, 2);
    layout->addWidget(countTotalSumForEachSellerButton, 4, 2);
    ui->centralwidget->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectSellers() {
    if (!sdb.open()) {
        qDebug() << "Fail to open DB!";
    }
    else {
        qDebug() << "DB is open!";
        sellersModel = new QSqlTableModel(this, sdb);
        sellersModel->setTable("sellers");
        sellersModel->select();
        if (sellersModel->columnCount() == 0) {
            query = new QSqlQuery(sdb);
            query->exec("CREATE TABLE `sellers` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `surname` TEXT NOT NULL, `name` TEXT NOT NULL, `middlename` TEXT NOT NULL)");
        }
        if (sellersModel->rowCount() == 0) {
            query = new QSqlQuery(sdb);
            query->prepare("INSERT INTO sellers (surname, name, middlename) VALUES (?, ?, ?)");
            query->addBindValue("Petrov");
            query->addBindValue("Petr");
            query->addBindValue("Petrovich");
            query->exec();
            query->prepare("INSERT INTO sellers (surname, name, middlename) VALUES (?, ?, ?)");
            query->addBindValue("Ivanov");
            query->addBindValue("Ivan");
            query->addBindValue("Ivanovich");
            query->exec();
            query->prepare("INSERT INTO sellers (surname, name, middlename) VALUES (?, ?, ?)");
            query->addBindValue("Artemov");
            query->addBindValue("Artem");
            query->addBindValue("Artemovich");
            query->exec();
            sellersModel->select();
        }
        table->setModel(sellersModel);
        qDebug() << "Установите продавцов";
    }
}

void MainWindow::selectProducts() {
    if (!sdb.open()) {
        qDebug() << "Fail to open DB!";
    }
    else {
        qDebug() << "DB is open!";
        productModel = new QSqlTableModel(this, sdb);
        productModel->setTable("product");
        productModel->select();
        if (productModel->columnCount() == 0) {
            query = new QSqlQuery(sdb);
            query->exec("CREATE TABLE `product` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `sellerid` INTEGER NOT NULL, `count` INTEGER NOT NULL, `cost` FLOAT NOT NULL, `sum` FLOAT NOT NULL)");
        }
        if (productModel->rowCount() == 0) {
            qDebug() << "Insert values";
            query = new QSqlQuery(sdb);
            query->prepare("INSERT INTO product (sellerid, count, cost, sum) VALUES (?, ?, ?, ?)");
            query->addBindValue(1);
            query->addBindValue(5);
            query->addBindValue(20);
            query->addBindValue(5*20);
            query->exec();
            query->prepare("INSERT INTO product (sellerid, count, cost, sum) VALUES (?, ?, ?, ?)");
            query->addBindValue(1);
            query->addBindValue(7);
            query->addBindValue(16);
            query->addBindValue(7 * 16);
            query->exec();
            query->prepare("INSERT INTO product (sellerid, count, cost, sum) VALUES (?, ?, ?, ?)");
            query->addBindValue(2);
            query->addBindValue(9);
            query->addBindValue(10);
            query->addBindValue(9 * 10);
            query->exec();
            query->prepare("INSERT INTO product (sellerid, count, cost, sum) VALUES (?, ?, ?, ?)");
            query->addBindValue(2);
            query->addBindValue(14);
            query->addBindValue(8);
            query->addBindValue(14 * 8);
            query->exec();
            query->prepare("INSERT INTO product (sellerid, count, cost, sum) VALUES (?, ?, ?, ?)");
            query->addBindValue(3);
            query->addBindValue(3);
            query->addBindValue(34);
            query->addBindValue(3 * 34);
            query->exec();
            productModel->select();
        }
        table->setModel(productModel);
        qDebug() << "Установите модель продукта";
    }
}

void MainWindow::findSellerByProductId() {
    if (!sdb.open()) {
        qDebug() << "Fail to open DB!";
    }
    else {
        qDebug() << "DB is open!";
        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery query;
        query.prepare("SELECT surname, name, middlename FROM sellers s JOIN product p ON sellerid = s.id WHERE p.id = ?");
        query.addBindValue(productIdTextBox->toPlainText().toInt());
        query.exec();
        model->setQuery(query);
        table->setModel(model);
    }
}

void MainWindow::countTotalSumForEachSeller() {
    if (!sdb.open()) {
        qDebug() << "Fail to open DB!";
    }
    else {
        qDebug() << "DB is open!";
        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery query;
        query.prepare("SELECT surname, name, middlename, SUM(sum) as totalsum FROM sellers s JOIN product p ON s.id = p.sellerid GROUP BY s.id, surname, name, middlename");
        query.exec();
        model->setQuery(query);
        table->setModel(model);
    }
}
