// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QToolTip>
#include <QCursor>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLabel>


class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void generateRandomArray();
    void bubbleSort();
    void insertionSort();
    void showToolTip(int row, int column);
    void sortColumn(int column);

private:
    QTableWidget *tableWidget;
    QLabel *bubbleSortLabel; // Добавление метки для отображения сравнений сортировки пузырьком
    QLabel *insertionSortLabel; // Добавление метки для отображения сравнений сортировки вставками
    int selectedColumn;
    int bubbleSortComparisons;
    int insertionSortComparisons;
};

#endif // MAINWINDOW_H
