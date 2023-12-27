#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLabel>
#include <QSqlTableModel>
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    
    QLabel* l;
    QSqlDatabase sdb;
    QSqlQuery* query;
    QGridLayout* layout;

    QSqlTableModel* fioModel;
    QSqlTableModel* vidModel;

    QTableView* table;

    QPushButton* selectFIOButton;
    QPushButton* selectVidButton;
    QPushButton* viewSalaryByMonthButton;
    QPushButton* viewWorkTypesByMonthButton;

    QTextEdit* monthTextBox;

private slots:
    void selectFIO();
    void selectVid();
    void viewSalaryByMonth();
    void viewWorkTypesByMonth();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
