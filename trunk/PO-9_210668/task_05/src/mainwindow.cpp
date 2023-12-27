#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLabel>
#include <QSqlTableModel>
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    selectFIOButton = new QPushButton("Fio table");
    selectVidButton = new QPushButton("Id table");
    viewSalaryByMonthButton = new QPushButton("View salary by month");
    viewWorkTypesByMonthButton = new QPushButton("View work types by month");

    monthTextBox = new QTextEdit(this);
    monthTextBox->setMaximumWidth(250);
    monthTextBox->setMaximumHeight(30);

    connect(selectFIOButton, &QPushButton::clicked, this, &MainWindow::selectFIO);
    connect(selectVidButton, &QPushButton::clicked, this, &MainWindow::selectVid);
    connect(viewSalaryByMonthButton, &QPushButton::clicked, this, &MainWindow::viewSalaryByMonth);
    connect(viewWorkTypesByMonthButton, &QPushButton::clicked, this, &MainWindow::viewWorkTypesByMonth);

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("database.sqlite");
    table = new QTableView(this);
    layout = new QGridLayout(this);
    layout->addWidget(table, 0, 0, 8, 2);
    layout->addWidget(selectFIOButton, 0, 2);
    layout->addWidget(selectVidButton, 1, 2);
    layout->addWidget(viewSalaryByMonthButton, 2, 2);
    layout->addWidget(monthTextBox, 3, 2);
    layout->addWidget(viewWorkTypesByMonthButton, 4, 2);
    ui->centralwidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFIO()
{
    if (!sdb.open())
    {
        qDebug() << "Fail to open DB!";
    }
    else
    {
        qDebug() << "DB is open!";
        fioModel = new QSqlTableModel(this, sdb);
        fioModel->setTable("fio");
        fioModel->select();
        if (fioModel->columnCount() == 0)
        {
            query = new QSqlQuery(sdb);
            query->exec("CREATE TABLE `fio` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `family` TEXT NOT NULL, `name` TEXT NOT NULL, `otch` TEXT NOT NULL)");
        }
        if (fioModel->rowCount() == 0)
        {
            query = new QSqlQuery(sdb);
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Солышко");
            query->addBindValue("Дмитрий");
            query->addBindValue("Андреевич");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Перреферий");
            query->addBindValue("Петя");
            query->addBindValue("Перевериевич");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Дзмицер");
            query->addBindValue("Слишкомский");
            query->addBindValue("Агригаторович");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Глад");
            query->addBindValue("Феня");
            query->addBindValue("Андреевич");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Даниооии");
            query->addBindValue("Данил");
            query->addBindValue("Алексий");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Дракула");
            query->addBindValue("Дро");
            query->addBindValue("Дрик");
            query->exec();
            fioModel->select();
        }
        table->setModel(fioModel);
        qDebug() << "set model fio!";
    }
}

void MainWindow::selectVid()
{
    if (!sdb.open())
    {
        qDebug() << "Fail to open DB!";
    }
    else
    {
        qDebug() << "DB is open!";
        vidModel = new QSqlTableModel(this, sdb);
        vidModel->setTable("vid");
        vidModel->select();
        if (vidModel->columnCount() == 0)
        {
            query = new QSqlQuery(sdb);
            query->exec("CREATE TABLE `vid` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `vid` TEXT NOT NULL, `month` INTEGER NOT NULL, `summa` FLOAT NOT NULL)");
        }
        if (vidModel->rowCount() == 0)
        {
            qDebug() << "Insert values";
            query = new QSqlQuery(sdb);
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("Ремонтные_работы");
            query->addBindValue(3);
            query->addBindValue(7000.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("Дорожные_работы");
            query->addBindValue(3);
            query->addBindValue(7500.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("Беглые_работы");
            query->addBindValue(3);
            query->addBindValue(6300.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("Бешеные_работы");
            query->addBindValue(1);
            query->addBindValue(118.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("Лекероводочные");
            query->addBindValue(1);
            query->addBindValue(1000.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("Дружные_работы");
            query->addBindValue(1);
            query->addBindValue(890.0);
            query->exec();
            vidModel->select();
        }
        table->setModel(vidModel);
        qDebug() << "set model vid!";
    }
}

void MainWindow::viewSalaryByMonth()
{
    if (!sdb.open())
    {
        qDebug() << "Fail to open DB!";
    }
    else
    {
        qDebug() << "DB is open!";
        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery query;
        query.prepare("SELECT family, name, otch, summa FROM fio f JOIN vid v ON f.id = v.id WHERE v.month = ?");
        query.addBindValue(monthTextBox->toPlainText().toInt());
        query.exec();
        model->setQuery(query);
        table->setModel(model);
    }
}

void MainWindow::viewWorkTypesByMonth()
{
    if (!sdb.open())
    {
        qDebug() << "Fail to open DB!";
    }
    else
    {
        qDebug() << "DB is open!";
        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery query;
        query.prepare("SELECT vid, summa FROM vid WHERE month = ?");
        query.addBindValue(monthTextBox->toPlainText().toInt());
        query.exec();
        model->setQuery(query);
        table->setModel(model);
    }
}
