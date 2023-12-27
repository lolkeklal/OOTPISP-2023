#ifndef SORTINGTABLE_H
#define SORTINGTABLE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QHeaderView>

class SortingTable : public QWidget {
    Q_OBJECT

public:
    SortingTable(QWidget *parent = nullptr);

private slots:
    void generateRandomNumbers();
    void bubbleSort(int column);
    void insertionSort(int column);

private:
    QTableWidget *table;
    QPushButton *generateButton;
    QPushButton *bubbleSortButton;
    QPushButton *insertionSortButton;
    int comparisons;

    void fillTableRandomly();
};

#endif // SORTINGTABLE_H




