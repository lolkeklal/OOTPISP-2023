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
#include <QString>

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

    QSqlTableModel* sellersModel;
    QSqlTableModel* productModel;

    QTableView* table;

    QPushButton* selectSellersButton;
    QPushButton* selectProductButton;
    QPushButton* findSellerByProductIdButton;
    QPushButton* countTotalSumForEachSellerButton;

    QTextEdit* productIdTextBox;

private slots:
    void selectSellers();
    void selectProducts();
    void findSellerByProductId();
    void countTotalSumForEachSeller();
private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
