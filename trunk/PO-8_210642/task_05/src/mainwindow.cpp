#include "mainwindow.h"
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(600, 300);
    setupDatabase();
    setupUI();
    insertTestData();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupDatabase()
{
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("internet_database.sqlite");

    if (!sdb.open())
    {
        qDebug() << "Fail to open DB!";
    }
    else
    {
        qDebug() << "DB is open!";
        query = new QSqlQuery(sdb);

        // Create day table if not exists
        query->exec("CREATE TABLE IF NOT EXISTS `day` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `day` INTEGER NOT NULL, `month` INTEGER NOT NULL, `year` INTEGER NOT NULL)");

        // Create net table if not exists
        query->exec("CREATE TABLE IF NOT EXISTS `net` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `host` TEXT NOT NULL, `hour` INTEGER NOT NULL, `time` INTEGER NOT NULL, `volume` FLOAT NOT NULL)");
    }
}

void MainWindow::setupUI()
{
    table = new QTableView(this);
    layout = new QGridLayout(this);
    layout->addWidget(table, 0, 0, 8, 2);

    connectionsByHourButton = new QPushButton("Подключения по часам");
    infoVolumeByPeriodButton = new QPushButton("Объем информации за период");
    visitedSitesButton = new QPushButton("Посещенные сайты");
    resetDatabaseButton = new QPushButton("Сброс БД");

    hourTextBox = new QTextEdit(this);
    hourTextBox->setMaximumWidth(250);
    hourTextBox->setMaximumHeight(30);

    startDateTextBox = new QTextEdit(this);
    startDateTextBox->setMaximumWidth(250);
    startDateTextBox->setMaximumHeight(30);

    endDateTextBox = new QTextEdit(this);
    endDateTextBox->setMaximumWidth(250);
    endDateTextBox->setMaximumHeight(30);

    connect(connectionsByHourButton, &QPushButton::clicked, this, &MainWindow::connectionsByHour);
    connect(infoVolumeByPeriodButton, &QPushButton::clicked, this, &MainWindow::infoVolumeByPeriod);
    connect(visitedSitesButton, &QPushButton::clicked, this, &MainWindow::visitedSites);
    connect(resetDatabaseButton, &QPushButton::clicked, this, &MainWindow::resetDatabase);

    layout->addWidget(connectionsByHourButton, 0, 2);
    layout->addWidget(infoVolumeByPeriodButton, 1, 2);
    layout->addWidget(visitedSitesButton, 2, 2);
    layout->addWidget(resetDatabaseButton, 3, 2);

    QLabel *hourLabel = new QLabel("Введите час:", this);
    layout->addWidget(hourLabel, 4, 2, Qt::AlignLeft | Qt::AlignVCenter);
    layout->addWidget(hourTextBox, 5, 2);

    QLabel *startDateLabel = new QLabel("Дата начала (ГГГГММДД):", this);
    layout->addWidget(startDateLabel, 6, 2, Qt::AlignLeft | Qt::AlignVCenter);
    layout->addWidget(startDateTextBox, 7, 2);

    QLabel *endDateLabel = new QLabel("Дата окончания (ГГГГММДД):", this);
    layout->addWidget(endDateLabel, 8, 2, Qt::AlignLeft | Qt::AlignVCenter);
    layout->addWidget(endDateTextBox, 9, 2);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
}

void MainWindow::connectionsByHour()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM net WHERE hour = ?");
    query.addBindValue(hourTextBox->toPlainText().toInt());
    query.exec();

    model->setQuery(query);
    table->setModel(model);
}

void MainWindow::infoVolumeByPeriod()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;

    QDate startDate = QDate::fromString(startDateTextBox->toPlainText(), "yyyyMMdd");
    QDate endDate = QDate::fromString(endDateTextBox->toPlainText(), "yyyyMMdd");

    query.prepare("SELECT SUM(volume) FROM net WHERE time >= ? AND time <= ?");
    query.addBindValue(startDate.toString("yyyyMMdd").toInt());
    query.addBindValue(endDate.toString("yyyyMMdd").toInt());
    query.exec();

    model->setQuery(query);
    table->setModel(model);

    qDebug() << "Start Date:" << startDate.toString("yyyyMMdd") << "End Date:" << endDate.toString("yyyyMMdd");
    qDebug() << "SQL Query:" << query.lastQuery();
}

void MainWindow::visitedSites()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT host, hour, time, volume FROM net");
    query.exec();

    model->setQuery(query);
    table->setModel(model);
}

void MainWindow::resetDatabase()
{
    sdb.close();

    QFile dbFile("internet_database.sqlite");
    if (dbFile.exists())
    {
        dbFile.remove();
    }

    setupDatabase();

    insertTestData();
}

void MainWindow::insertTestData()
{
    query->exec("INSERT INTO day (day, month, year) VALUES (1, 12, 2023)");
    query->exec("INSERT INTO day (day, month, year) VALUES (5, 12, 2023)");
    query->exec("INSERT INTO day (day, month, year) VALUES (10, 12, 2023)");
    query->exec("INSERT INTO day (day, month, year) VALUES (15, 12, 2023)");
    query->exec("INSERT INTO day (day, month, year) VALUES (20, 12, 2023)");
    query->exec("INSERT INTO day (day, month, year) VALUES (25, 12, 2023)");
    query->exec("INSERT INTO day (day, month, year) VALUES (2, 1, 2024)");
    query->exec("INSERT INTO day (day, month, year) VALUES (8, 1, 2024)");
    query->exec("INSERT INTO day (day, month, year) VALUES (14, 1, 2024)");
    query->exec("INSERT INTO day (day, month, year) VALUES (28, 1, 2024)");

    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site1.com', 1, 100, 10.5)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site2.com', 2, 150, 20.0)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site3.com', 1, 200, 15.5)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site4.com', 2, 300, 30.0)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site5.com', 1, 400, 25.5)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site6.com', 2, 500, 40.0)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site7.com', 3, 600, 35.0)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site8.com', 4, 700, 45.5)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site9.com', 3, 800, 50.0)");
    query->exec("INSERT INTO net (host, hour, time, volume) VALUES ('site10.com', 4, 900, 60.0)");
}
