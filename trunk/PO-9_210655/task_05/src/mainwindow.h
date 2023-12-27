#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_add_day_clicked();

    void on_pushButton_delete_day_clicked();

    void on_tableView_day_clicked(const QModelIndex &index);

    void on_pushButton_add_net_clicked();

    void on_pushButton_delete_net_clicked();

    void on_tableView_net_clicked(const QModelIndex &index);

    void on_pushButton_hours_clicked();

    void on_pushButton_hours_2_clicked();

    void on_pushButton_sites_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *q1;
    QSqlTableModel *modelDay;
    QSqlTableModel *modelNet;

    int rowDay;
    int rowNet;

};
#endif // MAINWINDOW_H
