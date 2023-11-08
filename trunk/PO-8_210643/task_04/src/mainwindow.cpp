#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTableWidget>
#include <QTime>
#include <cstdlib>
#include <QModelIndex>
using namespace std;
    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    ui->tableView->horizontalHeader()->setDefaultSectionSize(40);
    ui->tableView->verticalHeader()->setDefaultSectionSize(30);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    generateTable210643();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_clicked
(const QModelIndex &index)
{
    int rowValue = index.row(), columnValue = index.column();
    QAbstractItemModel *itemModel = ui->tableView->model();
    int value = model->data(index).toInt();

    ui->textLabel5->setText(QString("(%1, %2)").arg(rowValue+1).arg(columnValue+1));
    ui->textLabel6->setText(QString("%1").arg(rowValue*10+columnValue+1));
    ui->textLabel7->setText(QString("%1").arg(value * value));
    ui->textLabel8->setText(QString("%1").arg(value * value * value));
}

void MainWindow::generateTable210643(){
    QTableWidget *tableWidget = new QTableWidget(10, 10);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int randNum = rand() % 100;
            QTableWidgetItem *tableItem = new QTableWidgetItem(QString::number(randNum));
            tableWidget->setItem(i, j, tableItem);
        }
    }
    ui->tableView->setModel(tableWidget->model());

    ui->textLabel5->clear();
    ui->textLabel6->clear();
    ui->textLabel7->clear();
    ui->textLabel8->clear();
}

void MainWindow::on_pushButton_clicked210643()
{
    generateTable210643();
}
