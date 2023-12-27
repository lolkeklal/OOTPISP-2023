#ifndef TASK02_H
#define TASK02_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>

namespace Ui {
class task02;
}

class task02 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task02(QWidget *parent = nullptr);
    ~task02();

    QLabel* inputArrayLabel;
    QLabel* outputArrayLabel;
    QLabel* inputArray;
    QLabel* outputArray;

    QPushButton* generateArray;
    QPushButton* processArray;
    QPushButton* generateTableButton;
    QPushButton* processTableButton;

private:
    Ui::task02 *ui;
    QVector<int> v;
    QVector<QVector<int>> tableElements;
    int size;
    QTableWidget* table;
    int tableCols;
    int tableRows;
    int findMinElement(QVector<int>& arr, int size);
    int findMaxElement(QVector<int>& arr, int size);

private slots:
    void generate();
    void process();
    void generateTable();
    void processTable();
};

#endif // TASK02_H
