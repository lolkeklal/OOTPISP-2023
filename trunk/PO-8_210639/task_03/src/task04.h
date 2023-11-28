#ifndef TASK04_H
#define TASK04_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QStack>
#include <QQueue>

namespace Ui {
class task04;
}

class task04 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task04(QWidget *parent = nullptr);
    ~task04();

    QTableWidget* stackTable;
    QTableWidget* queueTable;

    QPushButton* generateStackButton;
    QPushButton* generateQueueButton;
    QPushButton* processStackButton;
    QPushButton* processQueueButton;

private:
    Ui::task04 *ui;
    int stackSize = 5;
    int queueSize = 8;
    QStack<int> s;
    QQueue<int> q;
    int findMinElement(QVector<int>& arr, int size);
    int findMaxElement(QVector<int>& arr, int size);
private slots:
    void generateStack();
    void generateQueue();
    void processStack();
    void processQueue();
};

#endif // TASK04_H
