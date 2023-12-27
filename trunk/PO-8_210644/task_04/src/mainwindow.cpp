#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new QTableWidget(this);
    l = new QGridLayout(this);
    generateTableButton = new QPushButton("generate table", this);
    sumButton = new QPushButton("sum", this);
    averageButton = new QPushButton("average", this);
    minButton = new QPushButton("min", this);
    maxButton = new QPushButton("max", this);
    matrixSum = new QLabel("sum:", this);
    matrixAverage = new QLabel("average:", this);
    table->setColumnCount(size);
    table->setRowCount(size);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(generateTableButton, &QPushButton::clicked, this, &MainWindow::generateTable);
    connect(sumButton, &QPushButton::clicked, this, &MainWindow::countSum);
    connect(averageButton, &QPushButton::clicked, this, &MainWindow::countAverage);
    connect(minButton, &QPushButton::clicked, this, &MainWindow::findMin);
    connect(maxButton, &QPushButton::clicked, this, &MainWindow::findMax);
    l->addWidget(table, 0, 0, 1, 5);
    l->addWidget(generateTableButton, 1, 0);
    l->addWidget(sumButton, 1, 1);
    l->addWidget(averageButton, 1, 2);
    l->addWidget(minButton, 1, 3);
    l->addWidget(maxButton, 1, 4);
    l->addWidget(matrixSum, 2, 1);
    l->addWidget(matrixAverage, 2, 2);
    ui->centralwidget->setLayout(l);
}

void MainWindow::generateTable() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int temp = rand() % 100;
            QTableWidgetItem* Item = new QTableWidgetItem(QString::number(temp));
            this->table->setItem(i, j, Item);
        }
    }
    matrixSum->setText("sum:");
    matrixAverage->setText("average:");
}

void MainWindow::countSum() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += table->item(i, j)->text().toInt();
        }
    }
    matrixSum->setText("sum: " + QString::number(sum));
}

void MainWindow::countAverage() {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += table->item(i, j)->text().toInt();
        }
    }
    sum /= size * size;
    matrixAverage->setText("average: " + QString::number(sum));
}

void MainWindow::findMin() {
    int x=0;
    int y=0;
    int min = table->item(x, y)->text().toInt();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (min > table->item(i, j)->text().toInt()) {
                min = table->item(i, j)->text().toInt();
                x = i;
                y = j;
            }
        }
    }
    QColor color(255, 0, 0);
    table->item(x, y)->setBackground(color);
}

void MainWindow::findMax() {
    int x = 0;
    int y = 0;
    int max = table->item(x, y)->text().toInt();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (max < table->item(i, j)->text().toInt()) {
                max = table->item(i, j)->text().toInt();
                x = i;
                y = j;
            }
        }
    }
    QColor color(0, 255, 0);
    table->item(x, y)->setBackground(color);
}

MainWindow::~MainWindow()
{
    delete ui;
}

