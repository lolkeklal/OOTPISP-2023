#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QDate>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlDatabase sdb;
    QSqlQuery *query;
    QGridLayout *layout;

    QSqlTableModel *dayModel;
    QSqlTableModel *netModel;

    QTableView *table;

    QPushButton *connectionsByHourButton;
    QPushButton *infoVolumeByPeriodButton;
    QPushButton *visitedSitesButton;
    QPushButton *resetDatabaseButton;

    QTextEdit *hourTextBox;
    QTextEdit *startDateTextBox;
    QTextEdit *endDateTextBox;

private slots:
    void connectionsByHour();
    void infoVolumeByPeriod();
    void visitedSites();
    void resetDatabase();

private:
    void setupDatabase();
    void setupUI();
    void insertTestData();
};

#endif // MAINWINDOW_H
