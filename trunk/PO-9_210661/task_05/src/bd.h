#ifndef BD_H
#define BD_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class BD; }
QT_END_NAMESPACE

class BD : public QMainWindow
{
    Q_OBJECT

public:
    BD(QWidget *parent = nullptr);
    ~BD();

private slots:
    void displayAllOrders();
    void displayUncompletedOrders();
    void findThemeAndText(int orderId);

private:
    Ui::BD *ui;
    QSqlDatabase db;

    void connectToDatabase();
    void disconnectFromDatabase();
    void initializeDatabase();
};

#endif // BD_H
