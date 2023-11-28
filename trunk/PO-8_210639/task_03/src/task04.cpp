#include "task04.h"
#include "ui_task04.h"
#include <QGridLayout>

task04::task04(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task04)
{
    ui->setupUi(this);

    stackTable = new QTableWidget();
    queueTable = new QTableWidget();

    stackTable->setColumnCount(1);
    stackTable->setRowCount(stackSize);

    queueTable->setColumnCount(1);
    queueTable->setRowCount(queueSize);

    generateStackButton = new QPushButton("generate stack");
    generateQueueButton = new QPushButton("generate queue");
    processStackButton = new QPushButton("process stack");
    processQueueButton = new QPushButton("process queue");

    connect(generateStackButton, &QPushButton::clicked, this, &task04::generateStack);
    connect(processStackButton, &QPushButton::clicked, this, &task04::processStack);
    connect(generateQueueButton, &QPushButton::clicked, this, &task04::generateQueue);
    connect(processQueueButton, &QPushButton::clicked, this, &task04::processQueue);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(stackTable, 0, 0);
    layout->addWidget(queueTable, 0, 1);
    layout->addWidget(generateStackButton, 1, 0);
    layout->addWidget(processStackButton, 2, 0);
    layout->addWidget(generateQueueButton, 1, 1);
    layout->addWidget(processQueueButton, 2, 1);

    ui->centralwidget->setLayout(layout);
}

task04::~task04()
{
    delete ui;
}

void task04::generateQueue()
{
    for (int i = 0; i < queueSize; i++) {
        q.push_back(rand() % 51);
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(q.last()));
        this->queueTable->setItem(i, 0, Item);
    }
}

void task04::processStack()
{
    QVector<int> v;
    for (int i = stackSize; i != 0; i--) {
        v.push_back(s.pop());
    }
    int minIndex = findMinElement(v, stackSize);
    int maxIndex = findMaxElement(v, stackSize);
    std::swap(v[minIndex], v[maxIndex]);
    for (int i = 0; i < stackSize; i++) {
        s.push(v[i]);
        stackTable->item(i, 0)->setText(QString::number(v[i]));
    }
}

void task04::processQueue()
{
    int sum = 0;
    int counter = 0;
    QVector<int> v;
    for (int i = 0; i < queueSize; i++) {
        v.push_back(q.dequeue());
        if (v[i] % 2 == 0) {
            sum += v[i];
            counter++;
        }
    }

    sum /= counter;

    for (int i = 0; i < queueSize; i++) {
        if (v[i] % 2 == 0) {
            v[i] = sum;
        }
        q.push_back(v[i]);
        queueTable->item(i, 0)->setText(QString::number(v[i]));
    }
}

void task04::generateStack() {
    for (int i = stackSize-1; i!=-1; i--) {
        s.push(rand() % 10 + 1);
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(s.top()));
        this->stackTable->setItem(i, 0, Item);
    }
}

int task04::findMinElement(QVector<int>& arr, int size) {
    int resultElement = arr[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (resultElement > arr[i]) {
            resultElement = arr[i];
            index = i;
        }
    }
    return index;
}

int task04::findMaxElement(QVector<int>& arr, int size) {
    int resultElement = arr[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (resultElement < arr[i]) {
            resultElement = arr[i];
            index = i;
        }
    }
    return index;
}
