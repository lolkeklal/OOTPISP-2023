#include "task02.h"
#include "ui_task02.h"
#include <QGridLayout>

task02::task02(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task02)
{
    ui->setupUi(this);

    inputArrayLabel = new QLabel("input array:");
    outputArrayLabel = new QLabel("output array:");
    inputArray = new QLabel("");
    outputArray = new QLabel("");

    table = new QTableWidget();

    generateArray = new QPushButton("generate array");
    processArray = new QPushButton("process array");
    generateTableButton = new QPushButton("generate table");
    processTableButton = new QPushButton("process table");



    connect(generateArray, &QPushButton::clicked, this, &task02::generate);
    connect(processArray, &QPushButton::clicked, this, &task02::process);
    connect(generateTableButton, &QPushButton::clicked, this, &task02::generateTable);
    connect(processTableButton, &QPushButton::clicked, this, &task02::processTable);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(inputArrayLabel, 0, 0);
    layout->addWidget(outputArrayLabel, 1, 0);
    layout->addWidget(inputArray, 0, 1);
    layout->addWidget(outputArray, 1, 1);
    layout->addWidget(generateArray, 0, 2);
    layout->addWidget(processArray, 1, 2);
    layout->addWidget(table, 2, 0, 3, 3);
    layout->addWidget(generateTableButton, 5, 0);
    layout->addWidget(processTableButton, 5, 2);


    ui->centralwidget->setLayout(layout);
}

task02::~task02()
{
    delete ui;
}

void task02::generate() {
    v.clear();
    inputArray->clear();
    size = rand() % 10+1;
    for (int i = 0; i < size; i++) {
        v.push_back(rand() % 50);
        if (i != size - 1) {
            inputArray->setText(inputArray->text() + QString::number(v[i]) + ", ");
        }
        else {
            inputArray->setText(inputArray->text() + QString::number(v[i]));
        }
    }
}

void task02::process() {
    outputArray->clear();
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (v[i] % 2 == 0) {
            if (counter != size - 1) {
                outputArray->setText(outputArray->text() + QString::number(v[i]) + ", ");
            }
            else {
                outputArray->setText(outputArray->text() + QString::number(v[i]));
            }
            counter++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (v[i] % 2 == 1) {
            if (counter != size - 1) {
                outputArray->setText(outputArray->text() + QString::number(v[i]) + ", ");
            }
            else {
                outputArray->setText(outputArray->text() + QString::number(v[i]));
            }
            counter++;
        }
    }
}

void task02::generateTable() {
    tableElements.clear();
    tableCols = rand() % 10 + 1;
    tableRows = rand() % 10 + 1;
    table->setColumnCount(tableCols);
    table->setRowCount(tableRows);
    for (int i = 0; i < tableRows; i++) {
        QVector<int> tempVector;
        tableElements.push_back(tempVector);
        for (int j = 0; j < tableCols; j++) {
            tableElements[i].push_back(rand() % 50);
            QTableWidgetItem* Item = new QTableWidgetItem(QString::number(tableElements[i][j]));
            this->table->setItem(i, j, Item);
        }
    }
}

void task02::processTable() {
    for (int i = 0; i < tableRows; i++) {
        int minIndex = findMinElement(tableElements[i], tableElements[i].size());
        int maxIndex = findMaxElement(tableElements[i], tableElements[i].size());
        QColor color(255, 0, 0);
        table->item(i, minIndex)->setBackground(color);
        table->item(i, minIndex)->setText(QString::number(tableElements[i][maxIndex]));
        color.setRgb(0, 255, 0);
        table->item(i, maxIndex)->setBackground(color);
        table->item(i, maxIndex)->setText(QString::number(tableElements[i][minIndex]));
    }
}

int task02::findMinElement(QVector<int>& arr, int size) {
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


int task02::findMaxElement(QVector<int>& arr, int size) {
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
