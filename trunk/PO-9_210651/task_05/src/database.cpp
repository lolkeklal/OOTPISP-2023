#include "database.h"
#include "./ui_database.h"

DataBase::DataBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DataBase)
{
    ui->setupUi(this);

    SQLmodel = new QSqlQueryModel(this);
    SQLdb = QSqlDatabase::addDatabase("QSQLITE");
    SQLdb.setDatabaseName("address_book.sqlite");

    connect(ui->SearchPhone, &QPushButton::clicked, this, &DataBase::SearchPhoneNumber);
    connect(ui->SearchFIO, &QPushButton::clicked, this, &DataBase::SearchFullName);

    createTable();
    showData();

}

DataBase::~DataBase()
{
    delete ui;
}

void DataBase::SearchFullName() {
    if (!SQLdb.open()) {
        qDebug() << "Fail";
    } else {
        qDebug() << "Database opened";
        QSqlQuery query;
        query.prepare("SELECT family, name, otch FROM fio f JOIN telephone tel ON f.id = tel.id WHERE tel.telef = ?");
        query.addBindValue(ui->PhoneText->text());
        query.exec();
        QSqlQueryModel *resultModel = new QSqlQueryModel(this);
        resultModel->setQuery(std::move(query));
        ui->table->setModel(resultModel);
    }
}

void DataBase::SearchPhoneNumber() {
    if (!SQLdb.open()) {
        qDebug() << "Fail";
    } else {
        qDebug() << "Database opened";
        QSqlQuery SQLquery;
        SQLquery.prepare("SELECT telef FROM telephone tel JOIN fio f ON tel.id = f.id WHERE f.family = :family AND f.name = :name");
        SQLquery.bindValue(":name", ui->NameText->text());
        SQLquery.bindValue(":family", ui->SurnameText->text());
        SQLquery.exec();
        QSqlQueryModel *resultModel = new QSqlQueryModel(this);
        resultModel->setQuery(std::move(SQLquery));
        ui->table->setModel(resultModel);
    }
}

void DataBase::showData() {
    std::unique_ptr<QSqlQueryModel> queryModel = std::make_unique<QSqlQueryModel>(this);
    QSqlQuery query(SQLdb);

    query.prepare("SELECT fio.id, fio.family, fio.name, fio.otch, address.gorod, address.street, address.dom, telephone.telef \
                   FROM fio \
                   LEFT JOIN address ON fio.id = address.id \
                   LEFT JOIN telephone ON fio.id = telephone.id");

    if (query.exec()) {
        queryModel->setQuery(std::move(query));
        ui->table->setModel(queryModel.release());
    }
}

void DataBase::createTable() {
    if (!SQLdb.open()) {
        qDebug() << "Fail";
    } else {
        qDebug() << "Database opened";
        SQLquery = new QSqlQuery(SQLdb);
        SQLquery->exec("CREATE TABLE IF NOT EXISTS fio (id INTEGER PRIMARY KEY AUTOINCREMENT, family TEXT NOT NULL, name TEXT NOT NULL, otch TEXT NOT NULL)");
        SQLquery->exec("CREATE TABLE IF NOT EXISTS address (id INTEGER PRIMARY KEY AUTOINCREMENT, gorod TEXT NOT NULL, street TEXT NOT NULL, dom TEXT NOT NULL)");
        SQLquery->exec("CREATE TABLE IF NOT EXISTS telephone (id INTEGER PRIMARY KEY AUTOINCREMENT, telef TEXT NOT NULL)");

        QSqlQuery checkQuery(SQLdb);
        checkQuery.exec("SELECT COUNT(*) FROM fio");
        checkQuery.next();
        int rowCount = checkQuery.value(0).toInt();
        if(rowCount==0){
            SQLquery->exec("INSERT INTO fio (family, name, otch) VALUES ('Olegov', 'Oleg', 'Olegovich')");
            int lastFioId1 = SQLquery->lastInsertId().toInt();
            SQLquery->exec("INSERT INTO address (id, gorod, street, dom) VALUES (" + QString::number(lastFioId1) + ", 'City Hall', 'Street1', 'House 1')");
            SQLquery->exec("INSERT INTO telephone (id, telef) VALUES (" + QString::number(lastFioId1) + ", '9876543210')");

            SQLquery->exec("INSERT INTO fio (family, name, otch) VALUES ('Andreev', 'Andrew', 'Andreevich')");
            int lastFioId2 = SQLquery->lastInsertId().toInt();
            SQLquery->exec("INSERT INTO address (id, gorod, street, dom) VALUES (" + QString::number(lastFioId2) + ", 'City2', 'Street2', 'House 2')");
            SQLquery->exec("INSERT INTO telephone (id, telef) VALUES (" + QString::number(lastFioId2) + ", '1231231231')");
        }
        showData();
    }
}
