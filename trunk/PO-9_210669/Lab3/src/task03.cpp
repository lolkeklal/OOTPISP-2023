#include "task03.h"
#include "ui_task03.h"
#include <QGridLayout>

task03::task03(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task03)
{
    ui->setupUi(this);

    higherThan = new QLabel("higher than: ");

    firstListTable = new QTableWidget();
    secondListTable = new QTableWidget();
    linkedListTable = new QTableWidget();

    generateListsButton = new QPushButton("generate lists");
    processListsButton = new QPushButton("process lists");
    generateLinkedListButton = new QPushButton("generate linked list");
    processLinkedListButton = new QPushButton("process linked list");

    connect(generateListsButton, &QPushButton::clicked, this, &task03::generateLists);
    connect(processListsButton, &QPushButton::clicked, this, &task03::processLists);
    connect(generateLinkedListButton, &QPushButton::clicked, this, &task03::generateLinkedList);
    connect(processLinkedListButton, &QPushButton::clicked, this, &task03::processLinkedList);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(firstListTable, 0, 0);
    layout->addWidget(secondListTable, 0, 1);
    layout->addWidget(generateListsButton, 1, 0);
    layout->addWidget(processListsButton, 1, 1);
    layout->addWidget(linkedListTable, 2, 0, 4, 1);
    layout->addWidget(generateLinkedListButton, 3, 1);
    layout->addWidget(processLinkedListButton, 4, 1);
    layout->addWidget(higherThan, 5, 1);

    ui->centralwidget->setLayout(layout);
}

task03::~task03()
{
    delete ui;
}

void task03::generateLists() {
    firstList.clear();
    secondList.clear();
    firstListSize = rand() % 10 + 1;
    secondListSize = rand() % 10 + 1;
    firstListTable->setColumnCount(1);
    firstListTable->setRowCount(firstListSize);
    secondListTable->setColumnCount(1);
    secondListTable->setRowCount(secondListSize);
    for (int i = 0; i < firstListSize; i++) {
        int temp = rand() % 20 - 10;
        firstList<<temp;
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(firstList[i]));
        this->firstListTable->setItem(i, 0, Item);
    }
    for (int i = 0; i < secondListSize; i++) {
        int temp = rand() % 20 - 10;
        secondList<<temp;
        QList<int>::iterator it = secondList.end();
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(secondList[i]));
        this->secondListTable->setItem(i, 0, Item);
    }
}

void task03::processLists() {
    int minElement = *std::min_element(secondList.begin(), secondList.end());
    for (int i = 0; i < firstListSize; i++) {
        if (firstList[i] > 0) {
            firstList[i] = minElement;
            firstListTable->item(i, 0)->setText(QString::number(firstList[i]));
        }
    }
}

void task03::generateLinkedList() {
    linkedList.clear();
    linkedListSize = rand() % 10 + 1;
    linkedListTable->setColumnCount(1);
    linkedListTable->setRowCount(linkedListSize);
    for (int i = 0; i < linkedListSize; i++) {
        linkedList.push_back(rand() % 10);
        std::list<int>::iterator it = linkedList.end();
        --it;
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(*it));
        this->linkedListTable->setItem(i, 0, Item);
    }
}

void task03::processLinkedList() {
    int lowerValue = rand() % 10;
    higherThan->setText("higher than: " + QString::number(lowerValue));
    std::list<int>::iterator it = linkedList.begin();
    while (it != linkedList.end()) {
        if (*it > lowerValue) {
            it = linkedList.erase(it);
            linkedListSize--;
        }
        else {
            it++;
        }
    }

    linkedListTable->setRowCount(linkedListSize);
    for (int i = 0; i < linkedListSize; i++) {
        std::list<int>::iterator it = linkedList.begin();
        int j = 0;
        while (j != i) {
            ++it;
            j++;
        }
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(*it));
        this->linkedListTable->setItem(i, 0, Item);
    }
}
