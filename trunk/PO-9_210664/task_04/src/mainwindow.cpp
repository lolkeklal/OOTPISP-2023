#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tableWidget, &QTableWidget::cellEntered, this, &MainWindow::on_tableWidget_cellEntered);
    ui->randomButton->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_randomButton_clicked()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            int randomNumber = QRandomGenerator::global()->bounded(100);
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(randomNumber));
            ui->tableWidget->setItem(row, col, item);
        }
    }

    ui->resultLabel->clear();
}

void MainWindow::on_maxButton_clicked()
{
    int max = 0;
    int maxRow = -1;
    int maxCol = -1;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            int value = item->text().toInt();

            if (value > max) {
                max = value;
                maxRow = row;
                maxCol = col;
            }
        }
    }

    highlightCell(maxRow, maxCol);
    ui->resultLabel->setText(QString("Max: %1").arg(max));
}

void MainWindow::on_minButton_clicked()
{
    int min = 100;
    int minRow = -1;
    int minCol = -1;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            int value = item->text().toInt();

            if (value < min) {
                min = value;
                minRow = row;
                minCol = col;
            }
        }
    }

    highlightCell(minRow, minCol);
    ui->resultLabel->setText(QString("Min: %1").arg(min));
}

void MainWindow::on_sumButton_clicked()
{
    int sum = 0;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            int value = item->text().toInt();
            sum += value;
        }
    }

    ui->resultLabel->setText(QString("Sum: %1").arg(sum));
}

void MainWindow::on_averageButton_clicked()
{
    int sum = 0;
    int count = ui->tableWidget->rowCount() * ui->tableWidget->columnCount();

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            int value = item->text().toInt();
            sum += value;
        }
    }

    double average = static_cast<double>(sum) / count;
    ui->resultLabel->setText(QString("Average: %1").arg(average));
}

void MainWindow::on_tableWidget_cellEntered(int row, int column)
{
    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    if (item) {
        QToolTip::showText(ui->tableWidget->mapToGlobal(QPoint()), item->text());
    }
}

void MainWindow::highlightCell(int row, int column)
{
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (item) {
                item->setBackground(Qt::white);
                item->setForeground(Qt::black);
            }
        }
    }

    if (row >= 0 && column >= 0) {
        QTableWidgetItem *item = ui->tableWidget->item(row, column);
        if (item) {
            item->setBackground(Qt::blue);
            item->setForeground(Qt::white);
        }
    }
}
