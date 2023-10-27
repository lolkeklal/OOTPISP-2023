#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include "addwork.h"
#include "addworker.h"
#include "statistics.h"

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
    void on_addWorkerButton_clicked();

    void on_addWorkButton_clicked();

    void on_deleteWorkButton_clicked();

    void on_editWorkButton_clicked();

    void on_editWorkerButton_clicked();

    void on_deleteWorkerButton_clicked();

    void on_showWorkerStatisticsButton_clicked();

    void on_showWorkStatisticsButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *fioModel;
    QSqlTableModel *vidModel;

    AddWork* addWork;
    AddWorker* addWorker;
    Statistics* statistics;
};
#endif // MAINWINDOW_H
