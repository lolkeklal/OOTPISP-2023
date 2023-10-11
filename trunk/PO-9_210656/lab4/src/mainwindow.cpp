#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTableWidget>
#include <QTime>
#include <cstdlib>
#include <QModelIndex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    ui->tableView->horizontalHeader()->setDefaultSectionSize(40);
    ui->tableView->verticalHeader()->setDefaultSectionSize(30);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    generate();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row(), column = index.column();
    QAbstractItemModel *model = ui->tableView->model();
    int value = model->data(index).toInt();

    ui->label_5->setText(QString("(%1, %2)").arg(row+1).arg(column+1));
    ui->label_6->setText(QString("%1").arg(row*10+column+1));
    ui->label_7->setText(QString("%1").arg(value * value));
    ui->label_8->setText(QString("%1").arg(value * value * value));
}

void MainWindow::generate(){
    QTableWidget *table = new QTableWidget(10, 10);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int randomNumber = rand() % 100;
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(randomNumber));
            table->setItem(i, j, item);
        }
    }
    ui->tableView->setModel(table->model());

    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();
    ui->label_8->clear();
}

void MainWindow::on_pushButton_clicked()
{
    generate();
}

