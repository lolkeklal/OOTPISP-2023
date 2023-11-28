#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    selectFIOButton = new QPushButton("Fio table");
    selectVidButton = new QPushButton("Vid table");
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
            query->addBindValue("Smith");
            query->addBindValue("John");
            query->addBindValue("Johnson");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Williams");
            query->addBindValue("David");
            query->addBindValue("Davis");
            query->exec();
            query->prepare("INSERT INTO fio (family, name, otch) VALUES (?, ?, ?)");
            query->addBindValue("Miller");
            query->addBindValue("Michael");
            query->addBindValue("Mitchell");
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
            query->addBindValue("WorkType1");
            query->addBindValue(1);
            query->addBindValue(5000.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("WorkType2");
            query->addBindValue(1);
            query->addBindValue(7000.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("WorkType3");
            query->addBindValue(2);
            query->addBindValue(6000.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("WorkType4");
            query->addBindValue(1);
            query->addBindValue(1800.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("WorkType5");
            query->addBindValue(2);
            query->addBindValue(4500.0);
            query->exec();
            query->prepare("INSERT INTO vid (vid, month, summa) VALUES (?, ?, ?)");
            query->addBindValue("WorkType6");
            query->addBindValue(1);
            query->addBindValue(8900.0);
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
