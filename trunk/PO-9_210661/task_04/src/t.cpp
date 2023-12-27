#include "t.h"
#include "ui_t.h"
#include <QDebug>
#include <QRandomGenerator>
#include <iostream>


t::t(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t)
{
    ui->setupUi(this);
    setWindowTitle("Table");

    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(3);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->randomizeButton, &QPushButton::clicked, this, &t::on_generateButton_clicked);
    connect(ui->tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &t::on_columnHeaderClicked);

    on_generateButton_clicked();
}

t::~t()
{
    delete ui;
}

void t::on_generateButton_clicked()
{
    array.clear();
    ui->tableWidget->clear();

    for (int row = 0; row < 3; ++row) {
        QVector<int> rowValues;
        for (int col = 0; col < 10; ++col) {
            int value = QRandomGenerator::global()->bounded(100);
            rowValues.append(value);
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(QString::number(value)));
        }
        array.append(rowValues);
    }
}

void t::on_columnHeaderClicked(int column)
{
    Qt::SortOrder sortOrder = ui->tableWidget->horizontalHeader()->sortIndicatorOrder();
    bubbleSort(sortOrder == Qt::AscendingOrder, column);
    updateTable();
}

void t::bubbleSort(bool ascending, int column)
{
    int rowCount = array.size();

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            if (ascending) {
                if (array[j][column] > array[j + 1][column]) {
                    std::swap(array[j], array[j + 1]);
                }
            } else {
                if (array[j][column] < array[j + 1][column]) {
                    std::swap(array[j], array[j + 1]);
                }
            }
        }
    }
}

void t::updateTable()
{
    for (int row = 0; row < array.size(); ++row) {
        for (int col = 0; col < array[row].size(); ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(QString::number(array[row][col])));
        }
    }
}
