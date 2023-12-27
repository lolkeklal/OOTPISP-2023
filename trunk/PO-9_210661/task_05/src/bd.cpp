#include "bd.h"
#include "./ui_bd.h"

BD::BD(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BD)
{
    ui->setupUi(this);

    connectToDatabase();

    ui->outputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->outputTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    connect(ui->displayAllButton, &QPushButton::clicked, this, &BD::displayAllOrders);
    connect(ui->displayUncompletedButton, &QPushButton::clicked, this, &BD::displayUncompletedOrders);
    connect(ui->findButton, &QPushButton::clicked, [this]() {
        int orderId = ui->orderIdLineEdit->text().toInt();
        findThemeAndText(orderId);
    });

    initializeDatabase();
}

BD::~BD()
{
    disconnectFromDatabase();
    delete ui;
}

void BD::connectToDatabase()
{
    QSqlDatabase::removeDatabase("QSQLITE");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");

    if (!db.open()) {
        qDebug() << "Failed to connect to database! Error:" << db.lastError().text();
    }
}


void BD::disconnectFromDatabase()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

void BD::initializeDatabase()
{
    connectToDatabase();
    QSqlQuery query;

    if (!db.isOpen()) {
        qDebug() << "Failed to connect to database!";
        return;
    }

    query.exec("DROP TABLE IF EXISTS zakaz");
    query.exec("DROP TABLE IF EXISTS tema");

    // Создание таблицы zakaz
    if (query.exec("CREATE TABLE IF NOT EXISTS zakaz (id INTEGER PRIMARY KEY, day INTEGER, month INTEGER, year INTEGER, vip BOOLEAN, theme_id INTEGER, FOREIGN KEY(theme_id) REFERENCES tema(id))")) {
        qDebug() << "Table zakaz created successfully.";
    } else {
        qDebug() << "Failed to create table zakaz! Error:" << query.lastError().text();
    }

    if (query.exec("CREATE TABLE IF NOT EXISTS tema (id INTEGER PRIMARY KEY, tema TEXT, text TEXT)")) {
        qDebug() << "Table tema created successfully.";
    } else {
        qDebug() << "Failed to create table tema! Error:" << query.lastError().text();
    }

    QSqlQuery checkQuery;
    checkQuery.exec("SELECT COUNT(*) FROM zakaz");
    checkQuery.next();
    int zakazCount = checkQuery.value(0).toInt();

    if (zakazCount == 0) {
        QString insertZakazQuery = "INSERT INTO zakaz (day, month, year, vip, theme_id) VALUES ";
        for (int i = 0; i < QRandomGenerator::global()->bounded(10, 31); ++i) {
            insertZakazQuery += QString("(%1, %2, %3, %4, %5), ")
                                    .arg(QRandomGenerator::global()->bounded(1, 32))
                                    .arg(QRandomGenerator::global()->bounded(1, 13))
                                    .arg(QRandomGenerator::global()->bounded(2022, 2024))
                                    .arg(QRandomGenerator::global()->bounded(2))
                                    .arg(QRandomGenerator::global()->bounded(1, 11));
        }

        insertZakazQuery.chop(2);

        if (query.exec(insertZakazQuery)) {
            qDebug() << "Test data inserted into zakaz successfully.";
        } else {
            qDebug() << "Failed to insert test data into zakaz! Error:" << query.lastError().text();
        }
    }

    QSqlQuery checkThemeQuery;
    checkThemeQuery.exec("SELECT COUNT(*) FROM tema");
    checkThemeQuery.next();
    int temaCount = checkThemeQuery.value(0).toInt();

    if (temaCount == 0) {
        // Вставка тестовых данных в таблицу tema
        QString insertThemeQuery = "INSERT INTO tema (tema, text) VALUES ";
        for (int i = 0; i < QRandomGenerator::global()->bounded(3, 11); ++i) {
            insertThemeQuery += QString("('Theme %1', 'Text for theme %1'), ").arg(i + 1);
        }

        insertThemeQuery.chop(2);

        if (query.exec(insertThemeQuery)) {
            qDebug() << "Test data inserted into tema successfully.";
        } else {
            qDebug() << "Failed to insert test data into tema! Error:" << query.lastError().text();
        }
    }
}


void BD::displayAllOrders()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM zakaz")) {
        ui->outputTable->clearContents();
        ui->outputTable->setRowCount(0);

        int rowCount = 0;
        ui->outputTable->setColumnCount(6);
        ui->outputTable->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Day" << "Month" << "Year" << "VIP" << "Theme ID");

        while (query.next()) {
            int orderId = query.value(0).toInt();
            int day = query.value(1).toInt();
            int month = query.value(2).toInt();
            int year = query.value(3).toInt();
            bool vip = query.value(4).toBool();
            int themeId = query.value(5).toInt();

            ui->outputTable->insertRow(rowCount);
            ui->outputTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(orderId)));
            ui->outputTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(day)));
            ui->outputTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(month)));
            ui->outputTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(year)));
            ui->outputTable->setItem(rowCount, 4, new QTableWidgetItem(vip ? "Yes" : "No"));
            ui->outputTable->setItem(rowCount, 5, new QTableWidgetItem(QString::number(themeId)));

            rowCount++;
        }
    } else {
        qDebug() << "Failed to execute query! Error:" << query.lastError().text();
    }
    ui->outputTable->scrollToBottom();
}

void BD::displayUncompletedOrders()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM zakaz WHERE vip = 0")) {
        ui->outputTable->clearContents();
        ui->outputTable->setRowCount(0);

        int rowCount = 0;
        ui->outputTable->setColumnCount(6);
        ui->outputTable->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Day" << "Month" << "Year" << "VIP" << "Theme ID");

        while (query.next()) {
            int orderId = query.value(0).toInt();
            int day = query.value(1).toInt();
            int month = query.value(2).toInt();
            int year = query.value(3).toInt();
            bool vip = query.value(4).toBool();
            int themeId = query.value(5).toInt();

            ui->outputTable->insertRow(rowCount);
            ui->outputTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(orderId)));
            ui->outputTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(day)));
            ui->outputTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(month)));
            ui->outputTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(year)));
            ui->outputTable->setItem(rowCount, 4, new QTableWidgetItem(vip ? "Yes" : "No"));
            ui->outputTable->setItem(rowCount, 5, new QTableWidgetItem(QString::number(themeId)));

            rowCount++;
        }
    } else {
        qDebug() << "Failed to execute query! Error:" << query.lastError().text();
    }
    ui->outputTable->scrollToBottom();
}

void BD::findThemeAndText(int orderId)
{
    QSqlQuery query;
    query.prepare("SELECT id, tema, text FROM tema WHERE id = ?");
    query.addBindValue(orderId);

    if (query.exec()) {
        ui->outputTable->clearContents();
        ui->outputTable->setRowCount(0);

        int rowCount = 0;
        ui->outputTable->setColumnCount(3);
        ui->outputTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Theme" << "Text");

        if (query.next()) {
            int id = query.value(0).toInt();
            QString theme = query.value(1).toString();
            QString text = query.value(2).toString();

            ui->outputTable->insertRow(rowCount);
            ui->outputTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(id)));
            ui->outputTable->setItem(rowCount, 1, new QTableWidgetItem(theme));
            ui->outputTable->setItem(rowCount, 2, new QTableWidgetItem(text));
        } else {
            ui->outputTable->insertRow(rowCount);
            ui->outputTable->setItem(rowCount, 0, new QTableWidgetItem("Order not found!"));
        }
    } else {
        qDebug() << "Failed to execute query! Error:" << query.lastError().text();
    }
    ui->outputTable->scrollToBottom();
}
