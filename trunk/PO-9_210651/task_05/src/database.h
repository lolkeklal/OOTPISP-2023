#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class DataBase; }
QT_END_NAMESPACE

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    DataBase(QWidget *parent = nullptr);
    ~DataBase();


private slots:
    void SearchPhoneNumber();
    void SearchFullName();
    void createTable();
    void showData();

private:
    Ui::DataBase *ui;
    QSqlDatabase SQLdb;
    QSqlQuery *SQLquery;
    QSqlQueryModel *SQLmodel;

};
#endif // DATABASE_H

