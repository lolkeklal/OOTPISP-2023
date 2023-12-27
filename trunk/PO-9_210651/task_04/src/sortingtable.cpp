#include "sortingtable.h"

SortingTable::SortingTable(QWidget *parent)
    : QWidget(parent), comparisons(0) {
    table = new QTableWidget(3, 10, this);
    fillTableRandomly();

    generateButton = new QPushButton("Generate Numbers", this);
    connect(generateButton, &QPushButton::clicked, this, &SortingTable::generateRandomNumbers);

    bubbleSortButton = new QPushButton("Bubble Sort", this);
    connect(bubbleSortButton, &QPushButton::clicked, [this]() { bubbleSort(table->currentColumn()); });

    insertionSortButton = new QPushButton("Insertion Sort", this);
    connect(insertionSortButton, &QPushButton::clicked, [this]() { insertionSort(table->currentColumn()); });

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(table);
    layout->addWidget(generateButton);
    layout->addWidget(bubbleSortButton);
    layout->addWidget(insertionSortButton);
}

void SortingTable::fillTableRandomly() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 10; ++col) {
            int randomNum = QRandomGenerator::global()->bounded(100);
            table->setItem(row, col, new QTableWidgetItem(QString::number(randomNum)));
        }
    }
}

void SortingTable::generateRandomNumbers() {
    fillTableRandomly();
}

void SortingTable::bubbleSort(int column) {
    int rowCount = table->rowCount();
    comparisons = 0;
    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            QTableWidgetItem *curItem = table->item(j, column);
            QTableWidgetItem *nextItem = table->item(j + 1, column);

            int curNum = curItem->text().toInt();
            int nextNum = nextItem->text().toInt();
            comparisons++;
            if (curNum > nextNum) {//swaping elements
                table->setItem(j, column, new QTableWidgetItem(QString::number(nextNum)));
                table->setItem(j + 1, column, new QTableWidgetItem(QString::number(curNum)));
            }
        }
    }
    qDebug() << "Bubble Sort Comparisons: " << comparisons;
}

void SortingTable::insertionSort(int column) {
        int rowCount = table->rowCount();
    comparisons = 0;
        for (int i = 1; i < rowCount; ++i) {
            int key = table->item(i, column)->text().toInt();
            int j = i - 1;

            while (j >= 0 && table->item(j, column)->text().toInt() > key) {
                QTableWidgetItem *curItem = table->item(j, column);
                QTableWidgetItem *nextItem = table->item(j + 1, column);

                int currentNum = curItem->text().toInt();
                table->setItem(j + 1, column, new QTableWidgetItem(QString::number(currentNum)));
                --j;
            }

            table->setItem(j + 1, column, new QTableWidgetItem(QString::number(key)));
            comparisons++;
        }
        qDebug() << "Insertion Sort Comparisons: " << comparisons;
    }


