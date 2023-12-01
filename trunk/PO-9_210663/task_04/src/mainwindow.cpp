#include "mainwindow.h"
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QToolTip>
#include <QCursor>
#include <QTableWidgetItem>
#include <cstdlib>
#include <ctime>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),bubbleSortComparisons(0), insertionSortComparisons(0) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    tableWidget = new QTableWidget(3, 10, this);
    layout->addWidget(tableWidget);

    QPushButton *generateButton = new QPushButton("Generate Array", this);
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateRandomArray);
    layout->addWidget(generateButton);

    // Создаем метки для отображения счетчиков сравнений
    QLabel *bubbleSortLabel = new QLabel("Bubble Sort Comparisons: 0", this);
    layout->addWidget(bubbleSortLabel);

    QPushButton *bubbleSortButton = new QPushButton("Bubble Sort", this);
    connect(bubbleSortButton, &QPushButton::clicked, this, &MainWindow::bubbleSort);
    layout->addWidget(bubbleSortButton);

    QLabel *insertionSortLabel = new QLabel("Insertion Sort Comparisons: 0", this);
    layout->addWidget(insertionSortLabel);

    QPushButton *insertionSortButton = new QPushButton("Insertion Sort", this);
    connect(insertionSortButton, &QPushButton::clicked, this, &MainWindow::insertionSort);
    layout->addWidget(insertionSortButton);

    tableWidget->setToolTipDuration(500);
    connect(tableWidget, &QTableWidget::cellEntered, this, &MainWindow::showToolTip);
    connect(tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::sortColumn);

    selectedColumn = -1;

    // Привязываем метки к переменным класса для последующего обновления значений
    this->bubbleSortLabel = bubbleSortLabel;
    this->insertionSortLabel = insertionSortLabel;
}
void MainWindow::generateRandomArray() {
    srand(time(nullptr)); // Seed for random number generation
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 10; col++){
            int value = rand() % 100;
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(value));
            tableWidget->setItem(row,col,item);
        }
    }
}
void MainWindow::sortColumn(int column) {
    // Проверяем, выделен ли уже этот столбец
    if (selectedColumn != column) {
        selectedColumn = column;
    } else {
        selectedColumn = -1; // Если столбец уже выделен, сбрасываем выделение
    }
}

void MainWindow::bubbleSort() {
    if (selectedColumn != -1 && selectedColumn < tableWidget->columnCount()) {
        bubbleSortComparisons = 0;
        int col = selectedColumn;
        int rowCount = tableWidget->rowCount();

        for (int i = 0; i < rowCount - 1; ++i) {
            for (int j = 0; j < rowCount - i - 1; ++j) {
                auto currentItem = tableWidget->item(j, col);
                auto nextItem = tableWidget->item(j + 1, col);

                if (currentItem && nextItem) {
                    ++bubbleSortComparisons;

                    if (currentItem->text().toInt() > nextItem->text().toInt()) {
                        QString temp = currentItem->text();
                        currentItem->setText(nextItem->text());
                        nextItem->setText(temp);
                    }
                }
            }
        }
        bubbleSortLabel->setText("Bubble Sort Comparisons: " + QString::number(bubbleSortComparisons));
    }
}





void MainWindow::insertionSort() {
    if (selectedColumn != -1) {
        insertionSortComparisons = 0;
        int col = selectedColumn;

        for (int i = 1; i < tableWidget->rowCount(); ++i) {
            QTableWidgetItem *current = tableWidget->takeItem(i, col);
            int j = i - 1;

            while (j >= 0 && tableWidget->item(j, col)->text().toInt() > current->text().toInt()) {
                ++insertionSortComparisons; // Увеличение счетчика при каждом сравнении
                tableWidget->setItem(j + 1, col, tableWidget->takeItem(j, col));
                --j;
            }

            tableWidget->setItem(j + 1, col, current);
        }
    }
    insertionSortLabel->setText("Insertion Sort Comparisons: " + QString::number(insertionSortComparisons));
}

void MainWindow::showToolTip(int row, int column) {
    QToolTip::showText(QCursor::pos(), tableWidget->item(row, column)->text());
}
